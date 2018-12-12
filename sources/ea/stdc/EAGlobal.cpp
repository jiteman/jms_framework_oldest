///////////////////////////////////////////////////////////////////////////////
// EAGlobal.cpp
//
// Copyright (c) 2004, Electronic Arts. All Rights Reserved.
// Maintained by Avery Lee and Paul Pedriana, Maxis
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// OS globals are process-wide globals and are shared between an EXE and
// DLLs. The OS global system works at the operating system level and has
// auto-discovery logic so that no pointers or init calls need to be made
// between modules for them to link their OS global systems together.
//
// Note that the interface to OS globals is a bit convoluted because the
// core system needs to be thread-safe, cross-module, and independent of
// app-level allocators. For objects for which order of initialization is
// clearer, EASingleton is probably a better choice.
///////////////////////////////////////////////////////////////////////////////


#include "EA/StdC/EAGlobal.h"
#include <EAStdC/internal/Thread.inl>
#include <EAStdC/EASprintf.h>
#include <stdlib.h>
#include <new>
#include EA_ASSERT_HEADER

// Until we can test other implementations of Linux, we enable Linux only for regular desktop x86 Linux.
#if (defined(EA_PLATFORM_LINUX) && (defined(EA_PROCESSOR_X86) || defined(EA_PROCESSOR_X86_64))) // || defined(EA_PLATFORM_OSX) // What other unix-like platforms can do this?
    #include <semaphore.h>
    #include <fcntl.h>
    #include <sys/mman.h>
    #include <stdlib.h>
    #include <unistd.h>

    #define EASTDC_EAGLOBAL_UNIX 1
#else
    #define EASTDC_EAGLOBAL_UNIX 0
#endif


#if defined(EA_PLATFORM_MICROSOFT)
    #pragma warning(push, 0)

    #if defined(EA_PLATFORM_XENON)
        #include <xtl.h>
    #else
        #include <Windows.h>
    #endif

    #pragma warning(pop)
#endif



#if defined(EA_PLATFORM_MICROSOFT)
    #pragma warning(push)
    #pragma warning(disable: 4355)          // warning C4355: 'this' : used in base member initializer list

    #ifndef EASTDC_INIT_SEG_DEFINED
        #define EASTDC_INIT_SEG_DEFINED
        // Set initialization order between init_seg(compiler) (.CRT$XCC) and
        // init_seg(lib) (.CRT$XCL). The MSVC linker sorts the .CRT sections
        // alphabetically so we simply need to pick a name that is between
        // XCC and XCL. This works on both Windows and XBox.
        #pragma warning(disable: 4075) // "initializers put in unrecognized initialization area"
        #pragma init_seg(".CRT$XCF")
    #endif
#endif



namespace
{
    struct OSGlobalManager 
    {
        typedef EA::StdC::intrusive_list<EA::StdC::OSGlobalNode> OSGlobalList;

        OSGlobalList      mOSGlobalList;
        uint32_t          mRefCount;     //< Atomic reference count so that the allocator persists as long as the last module that needs it.
        EA::StdC::Mutex   mcsLock;

        OSGlobalManager();
        OSGlobalManager(const OSGlobalManager&);

        OSGlobalManager& operator=(const OSGlobalManager&);

        void Lock() {
            mcsLock.Lock();
        }

        void Unlock() {
            mcsLock.Unlock();
        }

        EA::StdC::OSGlobalNode* Find(uint32_t id);
        void                    Add(EA::StdC::OSGlobalNode* p);
        void                    Remove(EA::StdC::OSGlobalNode* p);
    };

    OSGlobalManager::OSGlobalManager() {
        EA::StdC::AtomicSet(&mRefCount, 0);
    }

    EA::StdC::OSGlobalNode* OSGlobalManager::Find(uint32_t id) {
        OSGlobalList::iterator it(mOSGlobalList.begin()), itEnd(mOSGlobalList.end());

        for(; it!=itEnd; ++it) {
            EA::StdC::OSGlobalNode& node = *it;

            if (node.mOSGlobalID == id)
                return &node;
        }

        return NULL;
    }

    void OSGlobalManager::Add(EA::StdC::OSGlobalNode *p) {
        mOSGlobalList.push_front(*p);
    }

    void OSGlobalManager::Remove(EA::StdC::OSGlobalNode *p) {
        OSGlobalList::iterator it = mOSGlobalList.locate(*p);
        mOSGlobalList.erase(it);
    }

    OSGlobalManager* gpOSGlobalManager = NULL;
    uint32_t         gOSGlobalRefs     = 0;

} // namespace



#if defined(EA_PLATFORM_MICROSOFT)

    namespace {

        #define EA_GLOBAL_UNIQUE_NAME_FORMAT "SingleMgrMutex%08x"

        // For the Microsoft desktop API (e.g. Win32, Win64) we can use Get/SetEnvironmentVariable to 
        // read/write a process-global variable. But other Microsoft APIs (e.g. XBox 360) don't support
        // this and we resort to using a semaphore to store pointer bits.
        #if !EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP) && (EA_PLATFORM_PTR_SIZE == 4)
            HANDLE ghOSGlobalManagerPtrSemaphore;
        #elif !EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)  && (EA_PLATFORM_PTR_SIZE == 8)
            HANDLE ghOSGlobalManagerPtrSemaphoreHi = NULL;
            HANDLE ghOSGlobalManagerPtrSemaphoreLo = NULL;
        #endif

        bool             InitOSGlobalSystem();
        void             ShutdownOSGlobalSystem();
        OSGlobalManager* CreateOSGlobalManager();
        void             DestroyOSGlobalManager(OSGlobalManager* pOSGlobalManager);


        OSGlobalManager* CreateOSGlobalManager()
        {
            // Allocate the OSGlobal manager in the heap. We use the heap so that it can
            // hop between DLLs if the EXE itself doesn't use the manager. Note that this
            // must be the operating system heap and not an app-level heap (i.e. PPMalloc).
            // We store the pointer to the originally allocated memory at p[-1], because we
            // may have moved it during alignment.
            const size_t kAlignment = 16;

            void* p = HeapAlloc(GetProcessHeap(), 0, sizeof(OSGlobalManager) + kAlignment - 1 + sizeof(void *));
            void* pAligned = (void *)(((uintptr_t)p + sizeof(void *) + kAlignment - 1) & ~(kAlignment-1));
            ((void**)pAligned)[-1] = p;

            // Placement-new the global manager into the new memory.
            return new(pAligned) OSGlobalManager;
        }


        void DestroyOSGlobalManager(OSGlobalManager* pOSGlobalManager)
        {
            if(pOSGlobalManager)
            {
                gpOSGlobalManager->~OSGlobalManager();
                HeapFree(GetProcessHeap(), 0, ((void**)gpOSGlobalManager)[-1]);
            }
        }


        bool InitOSGlobalSystem()
        {
            // The following check is not thread-safe. On most platforms this isn't an 
            // issue in practice because this function is called on application startup
            // and other threads won't be active. The primary concern is if the 
            // memory changes that result below are visible to other processors later.
            if (!gpOSGlobalManager)
            {
                // We create a named (process-global) mutex. Other threads or modules within 
                // this process share this same underlying mutex. 
                #if defined(EA_PLATFORM_XENON)
                    HANDLE hMutex = CreateMutexA(NULL, FALSE, "SingleMgrMutex");
                #elif !EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
                    // The kernel object namespace is global on Win32 so we have to choose a unique name.
                    char uniqueName[64];

                    EA::StdC::Sprintf(uniqueName, EA_GLOBAL_UNIQUE_NAME_FORMAT, (unsigned)GetCurrentProcessId());
                    HANDLE hMutex = CreateMutexExA(NULL, uniqueName, CREATE_MUTEX_INITIAL_OWNER, SYNCHRONIZE);
                #else
                    // The kernel object namespace is global on Win32 so we have to choose a unique name.
                    char uniqueName[64];

                    EA::StdC::Sprintf(uniqueName, EA_GLOBAL_UNIQUE_NAME_FORMAT, (unsigned)GetCurrentProcessId());
                    HANDLE hMutex = CreateMutexA(NULL, FALSE, uniqueName);
                #endif

                if (!hMutex)
                    return false;

                if (WAIT_FAILED != WaitForSingleObjectEx(hMutex, INFINITE, FALSE))
                {
                    // If we don't have access to GetEnvironmentVariable and are a 32 bit platform...
                    #if !EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP) && (EA_PLATFORM_PTR_SIZE == 4)
                        // Xenon does not have memory mapping so we can't use the same technique
                        // as for Win32, and lacks GetModuleHandle() so the old "get global proc
                        // from main executable" trick won't work. What we do here is create
                        // a semaphore whose value is the pointer to gpOSGlobalManager. Semaphores
                        // can't hold negative values so we shift the pointer down by 4 bits
                        // before storing it (it has 16 byte alignment so this is OK). Also,
                        // there is no way to read a semaphore without modifying it so a mutex
                        // is needed around the operation.

                        #if defined(EA_PLATFORM_XENON)
                            ghOSGlobalManagerPtrSemaphore = CreateSemaphoreA(NULL, 0, 0x7FFFFFFF, "SingleMgr");
                        #else
                            ghOSGlobalManagerPtrSemaphore = CreateSemaphoreExW(NULL, 0, 0x7FFFFFFF, L"SingleMgr", 0, SYNCHRONIZE | SEMAPHORE_MODIFY_STATE);
                        #endif

                        if (ghOSGlobalManagerPtrSemaphore)
                        {
                            const bool bSemaphoreExists = (GetLastError() == ERROR_ALREADY_EXISTS);

                            if (bSemaphoreExists) // If somebody within our process already created it..
                            {
                                LONG ptrValue;

                                // Read the semaphore value.
                                if (ReleaseSemaphore(ghOSGlobalManagerPtrSemaphore, 1, &ptrValue)) {
                                    // Undo the +1 we added to the semaphore.
                                    WaitForSingleObjectEx(ghOSGlobalManagerPtrSemaphore, INFINITE, FALSE);

                                    // Recover the allocator pointer from the semaphore's original value.
                                    gpOSGlobalManager = (OSGlobalManager *)((uintptr_t)ptrValue << 4);
                                }
                                else
                                    EA_FAIL();
                            } 
                            else
                            {
                                gpOSGlobalManager = CreateOSGlobalManager();

                                // Set the semaphore to the pointer value. It was created with
                                // zero as the initial value so we add the desired value here.
                                ReleaseSemaphore(ghOSGlobalManagerPtrSemaphore, (LONG)((uintptr_t)gpOSGlobalManager >> 4), NULL);
                            }
                        }
                        else
                        {
                            // We have a system failure we have no way of handling.
                            EA_FAIL();
                        }

                    // If we don't have access to GetEnvironmentVariable and are a 64 bit platform...
                    #elif !EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP) && (EA_PLATFORM_PTR_SIZE == 8)

                        // Semaphore counts are limited to 31 bits (LONG_MAX), but we need to store a 64 bit pointer
                        // in those bits. But 64 bit pointers are always 64 bit aligned, so we need only 56 bits
                        // to store a 64 bit pointer. So we store the upper 28 bits in one semaphore and the lower
                        // 28 bits in another semaphore. Take the resulting 56 bits and shift left by 8 to get the 
                        // full 64 bit pointer.
                        // We use CreateSemaphoreExW instead of CreateSemaphoreW because the latter isn't always
                        // present in the non-desktop API.

                        // The kernel object namespace is session-local (not the same as app-local) so we have to choose a unique name.
                        wchar_t uniqueNameHi[64];
                        wchar_t uniqueNameLo[64];
                        DWORD   dwProcessId = GetCurrentProcessId();
                        EA::StdC::Sprintf(uniqueNameHi, L"SingleMgrHi%u", dwProcessId);
                        EA::StdC::Sprintf(uniqueNameLo, L"SingleMgrLo%u", dwProcessId);

                        ghOSGlobalManagerPtrSemaphoreHi = CreateSemaphoreExW(NULL, 0, 0x7FFFFFFF, uniqueNameHi, 0, SYNCHRONIZE | SEMAPHORE_MODIFY_STATE);

                        if(ghOSGlobalManagerPtrSemaphoreHi)
                        {
                            const bool bSemaphoreExists = (GetLastError() == ERROR_ALREADY_EXISTS);
                            LONG ptrValueHi;
                            LONG ptrValueLo;

                            if(bSemaphoreExists) // If somebody within our process already created it..
                            {
                                // Read the semaphore value.
                                if(ReleaseSemaphore(ghOSGlobalManagerPtrSemaphoreHi, 1, &ptrValueHi))
                                {
                                    WaitForSingleObjectEx(ghOSGlobalManagerPtrSemaphoreHi, INFINITE, FALSE);     // Undo the +1 we added with ReleaseSemaphore.

                                    // We still need to create our ghOSGlobalManagerPtrSemaphoreLo, which should also already exist, 
                                    // since some other module in this process has already exected this function.
                                    EA_ASSERT(ghOSGlobalManagerPtrSemaphoreLo == NULL);
                                    ghOSGlobalManagerPtrSemaphoreLo = CreateSemaphoreExW(NULL, 0, 0x7FFFFFFF, uniqueNameLo, 0, SYNCHRONIZE | SEMAPHORE_MODIFY_STATE);
                                    EA_ASSERT(GetLastError() == ERROR_ALREADY_EXISTS);

                                    ReleaseSemaphore(ghOSGlobalManagerPtrSemaphoreLo, 1, &ptrValueLo);
                                    WaitForSingleObjectEx(ghOSGlobalManagerPtrSemaphoreLo, INFINITE, FALSE);     // Undo the +1 we added with ReleaseSemaphore.

                                    // Recover the allocator pointer from the semaphore's original value.
                                    uintptr_t ptr = (((uintptr_t)ptrValueHi) << 28 | ptrValueLo) << 8;
                                    gpOSGlobalManager = (OSGlobalManager*)ptr;
                                }
                                else
                                    EA_FAIL(); // In practice this cannot happen unless the machine is cripped beyond repair.
                            }
                            else // Else our CreateSemaphorExW call was the first one to create ghOSGlobalManagerPtrSemaphoreHi.
                            {
                                gpOSGlobalManager = CreateOSGlobalManager();
                                EA_ASSERT(gpOSGlobalManager);

                                // Set the semaphore to the pointer value. It was created with
                                // zero as the initial value so we add the desired value here.
                                uintptr_t ptr = (uintptr_t)gpOSGlobalManager >> 4;

                                ptrValueHi = static_cast<LONG>(ptr >> 28);
                                ptrValueLo = static_cast<LONG>(ptr & 0x07FFFFFF); // Mask out bits above 28.

                                // We still need to create our ghOSGlobalManagerPtrSemaphoreLo, which should also not already exist.
                                EA_ASSERT(ghOSGlobalManagerPtrSemaphoreLo == NULL);
                                ghOSGlobalManagerPtrSemaphoreLo = CreateSemaphoreExW(NULL, 0, 0x7FFFFFFF, uniqueNameLo, 0, SYNCHRONIZE | SEMAPHORE_MODIFY_STATE);
                                EA_ASSERT(GetLastError() != ERROR_ALREADY_EXISTS);

                                EA_ASSERT((ghOSGlobalManagerPtrSemaphoreHi != NULL) && (ghOSGlobalManagerPtrSemaphoreLo != NULL)); // Should always be true, due to the logic in this function.
                                ReleaseSemaphore(ghOSGlobalManagerPtrSemaphoreHi, ptrValueHi, NULL);
                                ReleaseSemaphore(ghOSGlobalManagerPtrSemaphoreLo, ptrValueLo, NULL);

                                // Now semaphoreHi has the upper 28 significant bits of the gpOSGlobalManager pointer value.
                                // and semaphoreLo has the lower 28 significant bits of the gpOSGlobalManager pointer value.
                            }
                        }
                        else
                        {
                            // We have a system failure we have no way of handling.
                            EA_FAIL();
                        }

                    #else

                        // Under Win32 and Win64, we use system environment variables to store the gpOSGlobalManager value.
                        char stringPtr[32];
                        const DWORD dwResult = GetEnvironmentVariableA(uniqueName, stringPtr, 32);

                        if((dwResult > 0) && stringPtr[0]) // If the variable was found...
                            gpOSGlobalManager = (OSGlobalManager *)(uintptr_t)_strtoui64(stringPtr, NULL, 16); // _strtoui64 is a VC++ extension function.
                        else
                        {
                            // GetLastError() should be ERROR_ENVVAR_NOT_FOUND. But what do we do if it isn't?
                            gpOSGlobalManager = CreateOSGlobalManager();

                            EA::StdC::Sprintf(stringPtr, "%I64x", (uint64_t)(uintptr_t)gpOSGlobalManager);
                            SetEnvironmentVariableA(uniqueName, stringPtr); // There's not much we can do if this call fails.
                        }

                    #endif

                    EA_ASSERT(gpOSGlobalManager && (gpOSGlobalManager->mRefCount < UINT32_MAX));
                    EA::StdC::AtomicIncrement(&gpOSGlobalManager->mRefCount);

                    BOOL result = ReleaseMutex(hMutex);
                    EA_ASSERT(result); EA_UNUSED(result);
                }

                BOOL result = CloseHandle(hMutex);
                EA_ASSERT(result); EA_UNUSED(result);

                if (!gpOSGlobalManager)
                {
                    ShutdownOSGlobalSystem();
                    return false;
                }

                EA_ASSERT(gOSGlobalRefs < UINT32_MAX);
                EA::StdC::AtomicIncrement(&gOSGlobalRefs);  // Increment it once for the init of this system (InitOSGlobalSystem). This increment will be matched by a decrement in ShutdownOSGlobalSystem.
            }

            return true;
        }

        void ShutdownOSGlobalSystem()
        {
            if (EA::StdC::AtomicDecrement(&gOSGlobalRefs) == 0) // If the (atomic) integer decrement results in a refcount of zero...
            {
                if (gpOSGlobalManager)
                {
                    if (EA::StdC::AtomicDecrement(&gpOSGlobalManager->mRefCount) == 0)
                        DestroyOSGlobalManager(gpOSGlobalManager);

                    gpOSGlobalManager = NULL;
                }

                #if !EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP) && (EA_PLATFORM_PTR_SIZE == 4)
                    if (ghOSGlobalManagerPtrSemaphore)
                    {
                        CloseHandle(ghOSGlobalManagerPtrSemaphore);
                        ghOSGlobalManagerPtrSemaphore = NULL;
                    }
                #elif !EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP) && (EA_PLATFORM_PTR_SIZE == 8)
                    if (ghOSGlobalManagerPtrSemaphoreHi)
                    {
                        CloseHandle(ghOSGlobalManagerPtrSemaphoreHi);
                        ghOSGlobalManagerPtrSemaphoreHi = NULL;
                    }

                    if (ghOSGlobalManagerPtrSemaphoreLo)
                    {
                        CloseHandle(ghOSGlobalManagerPtrSemaphoreLo);
                        ghOSGlobalManagerPtrSemaphoreLo = NULL;
                    }
                #else
                    // Clear the gpOSGlobalManager environment variable.
                    // This code needs to be called in a thread-safe way by the user, usually by calling it once on shutdown. 
                    // We have a problem if this function is executing at the same time some other entity in this process 
                    // is currently doing some new use of the OS global system, as that can cause an instance of gpOSGlobalManager
                    // to be created while we are in the process of destroying it.
                    char uniqueName[64];

                    EA::StdC::Sprintf(uniqueName, EA_GLOBAL_UNIQUE_NAME_FORMAT, (unsigned)GetCurrentProcessId());
                    SetEnvironmentVariableA(uniqueName, NULL);
                #endif
            }
        }

    } // namespace

#elif EASTDC_EAGLOBAL_UNIX

    namespace {

        #define EA_GLOBAL_UNIQUE_NAME_FORMAT "/SingleMgrMutex%llu"

        OSGlobalManager* CreateOSGlobalManager();
        bool             InitOSGlobalSystem();
        void             ShutdownOSGlobalSystem();
        

        OSGlobalManager* CreateOSGlobalManager()
        {
            // Allocate the OSGlobal manager in shared memory. 
            #if defined(__APPLE__)
                void* pMemory = mmap(NULL, sizeof(OSGlobalManager), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON,      -1, 0);
            #else
                void* pMemory = mmap(NULL, sizeof(OSGlobalManager), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
            #endif

            if(pMemory) // Some Unix variants (e.g. mobile) can fail this call due to lack of support for it.
            {
                EA_ASSERT(((uintptr_t)pMemory & 15) == 0); // Make sure mmap returns at least 16 byte alignment.
 
                // Placement-new the global manager into the new memory.
                return new(pMemory) OSGlobalManager;
            }

            return NULL;
        }


        void DestroyOSGlobalManager(OSGlobalManager* pOSGlobalManager)
        {
            if(pOSGlobalManager)
            {
                gpOSGlobalManager->~OSGlobalManager();
                munmap(pOSGlobalManager, sizeof(OSGlobalManager));
            }
        }


        bool InitOSGlobalSystem()
        {
            // The following check is not thread-safe. On most platforms this isn't an 
            // issue in practice because this function is called on application startup
            // and other threads won't be active. The primary concern is if the 
            // memory changes that result below are visible to other processors later.

            if(!gpOSGlobalManager)
            {
                // We make a process-unique name based on the process id.
                char  uniqueName[96];
                pid_t processID = getpid();

                EA::StdC::Sprintf(uniqueName, EA_GLOBAL_UNIQUE_NAME_FORMAT, (unsigned long long)processID);
                sem_t* mutex = sem_open(uniqueName, O_CREAT, 0644, 1); // Unix has named semaphores but doesn't really have named mutexes, so we use a semaphore as a mutex.

                if(mutex == SEM_FAILED)
                    return false;

                if(sem_wait(mutex) == 0) // If locking the mutex was successful...
                {
                    // As of this writing, we are using getenv/setenv to write a shared variable pointer. It turns out that this
                    // is not a good idea, because getenv/setenv is not thread-safe. getenv returns a pointer to static memory
                    // which another thread (who isn't using our mutex) might call setenv in a way that changes that memory.
                    // The opinion of the Linux people is that you just shouldn't ever call setenv during application runtime.
                    // A better solution for us is to use shared mapped memory (shm_open(), mmap()): http://www.ibm.com/developerworks/aix/library/au-spunix_sharedmemory/index.html

                    const char* pName = getenv(uniqueName);

                    if(pName && pName[0]) // If the variable was found...
                        gpOSGlobalManager = (OSGlobalManager*)(uintptr_t)strtoull(pName, NULL, 16);
                    else
                    {
                        gpOSGlobalManager = CreateOSGlobalManager();

                        if(gpOSGlobalManager)
                        {
                            char buffer[32];
                            EA::StdC::Sprintf(buffer, "%I64x", (uint64_t)(uintptr_t)gpOSGlobalManager);
                            /*int result =*/ setenv(uniqueName, buffer, 1);
                        }
                    }

                    if(gpOSGlobalManager)
                    {
                        EA_ASSERT(gpOSGlobalManager->mRefCount < UINT32_MAX);
                        EA::StdC::AtomicIncrement(&gpOSGlobalManager->mRefCount);
                    }

                    sem_post(mutex);
                    sem_close(mutex);
                    sem_unlink(uniqueName);
                }

                if(!gpOSGlobalManager)
                {
                    ShutdownOSGlobalSystem();
                    return false;
                }

                EA_ASSERT(gOSGlobalRefs < UINT32_MAX);
                EA::StdC::AtomicIncrement(&gOSGlobalRefs);  // Increment it once for the init of this system (InitOSGlobalSystem). This increment will be matched by a decrement in ShutdownOSGlobalSystem.
            }

            return true;
        }

        void ShutdownOSGlobalSystem()
        {
            if(EA::StdC::AtomicDecrement(&gOSGlobalRefs) == 0) // If the (atomic) integer decrement results in a refcount of zero...
            { 
                if(gpOSGlobalManager)
                {
                    if(EA::StdC::AtomicDecrement(&gpOSGlobalManager->mRefCount) == 0)
                        DestroyOSGlobalManager(gpOSGlobalManager);

                    gpOSGlobalManager = NULL;
                }

                // Clear the gpOSGlobalManager environment variable.
                // This code needs to be called in a thread-safe way by the user, usually by calling it once on shutdown. 
                // We have a problem if this function is executing at the same time some other entity in this process 
                // is currently doing some new use of the OS global system, as that can cause an instance of gpOSGlobalManager
                // to be created while we are in the process of destroying it.
                char  uniqueName[96];
                pid_t processID = getpid();

                EA::StdC::Sprintf(uniqueName, EA_GLOBAL_UNIQUE_NAME_FORMAT, (unsigned long long)processID);
                 /*int result =*/ unsetenv(uniqueName);
            }
        }

    } // namespace

#else // #if defined(EA_PLATFORM_MICROSOFT)

    namespace {

        static uint64_t sOSGlobalMgrMemory[(sizeof(OSGlobalManager) + 1) / sizeof(uint64_t)];
        
        bool InitOSGlobalSystem()
        {
            // Theoretical problem: If you keep calling this function, eventually gOSGlobalRefs will overflow.
            EA_ASSERT(gOSGlobalRefs < UINT32_MAX);
            if(EA::StdC::AtomicIncrement(&gOSGlobalRefs) == 1)
                gpOSGlobalManager = new(sOSGlobalMgrMemory) OSGlobalManager;
            return true;
        }

        void ShutdownOSGlobalSystem()
        {
            if(EA::StdC::AtomicDecrement(&gOSGlobalRefs) == 0) // If the (atomic) integer decrement results in a refcount of zero...
                gpOSGlobalManager = NULL;
        }
    }

#endif // #if defined(EA_PLATFORM_MICROSOFT)




EASTDC_API EA::StdC::OSGlobalNode* EA::StdC::GetOSGlobal(uint32_t id, OSGlobalFactoryPtr pFactory)
{
    // Initialize up the OSGlobal system if we are getting called before
    // static init, i.e. allocator
    if (!InitOSGlobalSystem())
        return NULL;

    gpOSGlobalManager->Lock();

    EA::StdC::OSGlobalNode* p = gpOSGlobalManager->Find(id);

    if (!p && pFactory)
    {
        p = pFactory();
        p->mOSGlobalID = id;
        AtomicSet(&p->mOSGlobalRefCount, 0);
        gpOSGlobalManager->Add(p);
    }

    if (p)
    {
        EA_ASSERT(p->mOSGlobalRefCount < UINT32_MAX);
        AtomicIncrement(&p->mOSGlobalRefCount);

        EA_ASSERT(gOSGlobalRefs < UINT32_MAX);
        AtomicIncrement(&gOSGlobalRefs);
    }

    gpOSGlobalManager->Unlock();

    return p;
}


EASTDC_API bool EA::StdC::SetOSGlobal(uint32_t id, EA::StdC::OSGlobalNode *p)
{
    // Initialize up the OSGlobal system if we are getting called before
    // static init, i.e. allocator
    if (!InitOSGlobalSystem())
        return false;

    gpOSGlobalManager->Lock();

    EA::StdC::OSGlobalNode* const pTemp = gpOSGlobalManager->Find(id);

    if (pTemp == NULL) // If there isn't one already...
    {
        p->mOSGlobalID = id;
        AtomicSet(&p->mOSGlobalRefCount, 0);
        gpOSGlobalManager->Add(p);

        EA_ASSERT(p->mOSGlobalRefCount < UINT32_MAX);
        AtomicIncrement(&p->mOSGlobalRefCount);

        EA_ASSERT(gOSGlobalRefs < UINT32_MAX);
        AtomicIncrement(&gOSGlobalRefs);
    }
    
    gpOSGlobalManager->Unlock();

    return (pTemp == NULL);
}


EASTDC_API bool EA::StdC::ReleaseOSGlobal(EA::StdC::OSGlobalNode *p)
{
    gpOSGlobalManager->Lock();

    const bool shouldDestroyManager  = AtomicDecrement(&gOSGlobalRefs) == 0;
    const bool shouldDestroyOSGlobal = AtomicDecrement(&p->mOSGlobalRefCount) == 0;

    if (shouldDestroyOSGlobal)
        gpOSGlobalManager->Remove(p);

    gpOSGlobalManager->Unlock();

    // Note by Paul Pedriana (10/2009): It seems to me that shouldDestroyManager will never 
    // be true here because InitOSGlobalSystem will have been called at app startup and 
    // its gOSGlobalRefs increment will still be live. So only when that last explicit 
    // call to ShutdownOSGlobalSystem is called will gOSGlobalRefs go to zero.
    if (shouldDestroyManager)
        ShutdownOSGlobalSystem(); // This function decrements gOSGlobalRefs.

    return shouldDestroyOSGlobal;
}


// Force the OSGlobal manager to be available for the life of the app.
// It's OK if this comes up too late for some uses because GetOSGlobal()
// will bring it online earlier in that case.
namespace 
{
    // For PS3, we are finding that if we auto-init it before main() then a 
    // system call to create the manager lwmutex is made. But the PS3 crashes
    // if you make calls to create lwmutex objects before main.
    #if !defined(EA_PLATFORM_PS3)

        struct AutoinitOSGlobalManager
        {
            AutoinitOSGlobalManager()
            {
                bool result = InitOSGlobalSystem();
                EA_ASSERT(result); EA_UNUSED(result);
            }

            ~AutoinitOSGlobalManager()
            {
                ShutdownOSGlobalSystem();
            }
        };

        AutoinitOSGlobalManager gAutoinitOSGlobalManager;

    #endif
}









