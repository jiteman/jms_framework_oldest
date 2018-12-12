/////////////////////////////////////////////////////////////////////////////
// eathread_futex.cpp
//
// Copyright (c) 2006, Electronic Arts Inc. All rights reserved.
// Created by Paul Pedriana.
/////////////////////////////////////////////////////////////////////////////


#include <eathread/eathread_futex.h>
#include <new>

#if defined(EA_THREAD_NONTHREADED_FUTEX) && EA_THREAD_NONTHREADED_FUTEX

    void EA::Thread::Futex::CreateFSemaphore()
    {
        mSemaphore.mnCount = 0;
    }

    void EA::Thread::Futex::DestroyFSemaphore()
    {
        // Do nothing;
    }

    void EA::Thread::Futex::SignalFSemaphore()
    {
        mSemaphore.mnCount++;
    }

    void EA::Thread::Futex::WaitFSemaphore()
    {
        while(mSemaphore.mnCount <= 0)
            EA_THREAD_DO_SPIN();
        mSemaphore.mnCount--;
    }

    bool EA::Thread::Futex::WaitFSemaphore(const ThreadTime&)
    {
        WaitFSemaphore();
        return true;
    }

#elif defined(__APPLE__) && EATHREAD_MANUAL_FUTEX_ENABLED
    #include <semaphore.h>
    #include <stdio.h>
    #include <errno.h>
    #include <string.h>
    #include <libkern/OSAtomic.h>

    void EA::Thread::Futex::CreateFSemaphore()
    {   
        mSemaphore.Init(0);
    }

    void EA::Thread::Futex::DestroyFSemaphore()
    {
        // Do nothing;
    }

    void EA::Thread::Futex::SignalFSemaphore()
    {
        mSemaphore.Post();
    }

    void EA::Thread::Futex::WaitFSemaphore()
    {
        mSemaphore.Wait();
    }

    bool EA::Thread::Futex::WaitFSemaphore(const ThreadTime& timeoutAbsolute)
    {
        return (mSemaphore.Wait(timeoutAbsolute) >= 0);
    }

#elif defined(EA_PLATFORM_AIRPLAY) && EATHREAD_MANUAL_FUTEX_ENABLED
    void EA::Thread::Futex::CreateFSemaphore()
    {   
        mSemaphore = kdThreadSemCreate(0);
        EAT_ASSERT(mSemaphore != NULL);
    }

    void EA::Thread::Futex::DestroyFSemaphore()
    {
        const KDint result = kdThreadSemFree(mSemaphore);
        (void)result;
        EAT_ASSERT(result == 0);
    }

    void EA::Thread::Futex::SignalFSemaphore()
    {
        KDint result = kdThreadSemPost(mSemaphore);
        (void)result;
        EAT_ASSERT(result == 0);
    }

    void EA::Thread::Futex::WaitFSemaphore()
    {
        KDint result = kdThreadSemWait(mSemaphore);
        (void)result;
        EAT_ASSERT(result == 0);
    }

    bool EA::Thread::Futex::WaitFSemaphore(const ThreadTime&)
    {
        WaitFSemaphore();
        return true;
    }

#elif (defined(EA_PLATFORM_UNIX) || EA_POSIX_THREADS_AVAILABLE) && EATHREAD_MANUAL_FUTEX_ENABLED
    #include <semaphore.h>
    #include <errno.h>

    void EA::Thread::Futex::CreateFSemaphore()
    {   
        const int result = sem_init(&mSemaphore, 0, 0);
        (void)result;
        EAT_ASSERT(result != -1);
    }

    void EA::Thread::Futex::DestroyFSemaphore()
    {
        #if defined (__APPLE__)
            sem_close(&mSemaphore);
        #elif defined(EA_PLATFORM_ANDROID)
            sem_destroy(&mSemaphore);   // Android's sem_destroy is broken. http://code.google.com/p/android/issues/detail?id=3106
        #else
            int result = -1;
    
            for(;;)
            {
                result = sem_destroy(&mSemaphore);

                if((result == -1) && (errno == EBUSY)) // If another thread or process is blocked on this semaphore...
                    ThreadSleep(kTimeoutYield);        // Yield. If we don't yield, it's possible we could block other other threads or processes from running, on some systems.
                else
                    break;
            }

            EAT_ASSERT(result != -1);
        #endif
    }

    void EA::Thread::Futex::SignalFSemaphore()
    {
        sem_post(&mSemaphore);
    }

    void EA::Thread::Futex::WaitFSemaphore()
    {
        // We don't have much choice but to retry interrupted waits,
        // as there is no lock failure return value.
        while((sem_wait(&mSemaphore) == -1) && (errno == EINTR))
            continue;
    }

    bool EA::Thread::Futex::WaitFSemaphore(const ThreadTime&)
    {
        WaitFSemaphore();
        return true;
    }

#elif defined(EA_PLATFORM_PS3) && EATHREAD_MANUAL_FUTEX_ENABLED

    void EA::Thread::Futex::CreateFSemaphore()
    {
        sys_semaphore_attribute_t attr;
        sys_semaphore_attribute_initialize(attr);

        const int result = sys_semaphore_create(&mSemaphore, &attr, 0, 100000);

        (void)result;
        EAT_ASSERT(result == CELL_OK);
    }

    void EA::Thread::Futex::DestroyFSemaphore()
    {
        sys_semaphore_destroy(mSemaphore);
    }

    void EA::Thread::Futex::SignalFSemaphore()
    {
        sys_semaphore_post(mSemaphore, 1);
    }

    void EA::Thread::Futex::WaitFSemaphore()
    {
        sys_semaphore_wait(mSemaphore, 0);
    }

    bool EA::Thread::Futex::WaitFSemaphore(const ThreadTime& timeoutAbsolute)
    {
        int64_t timeoutRelativeUS = (int64_t)((timeoutAbsolute - GetThreadTime()) * 1000);
        if(timeoutRelativeUS < 1)
            timeoutRelativeUS = 1;
        return sys_semaphore_wait(mSemaphore, (usecond_t)timeoutRelativeUS) == CELL_OK;
    }

#elif defined(EA_PLATFORM_PSP2) && EATHREAD_MANUAL_FUTEX_ENABLED

    void EA::Thread::Futex::CreateFSemaphore()
    {
		mSemaphore = sceKernelCreateSema("EA::Thread::Futex",	// TODO: fixme
				SCE_KERNEL_SEMA_ATTR_TH_PRIO, // Attributes
				0,
				0x7fffffff,
				NULL);
        EAT_ASSERT(mSemaphore >= 0);
    }

    void EA::Thread::Futex::DestroyFSemaphore()
    {
        int32_t result = sceKernelDeleteSema(mSemaphore);
		(void)result;
		EAT_ASSERT(result >= 0);
    }

    void EA::Thread::Futex::SignalFSemaphore()
    {
		int32_t result = sceKernelSignalSema(mSemaphore, 1);
		(void)result;
		EAT_ASSERT(result >= 0);
    }

    void EA::Thread::Futex::WaitFSemaphore()
    {
		int32_t result = sceKernelWaitSema(mSemaphore, 1, 0);
		(void)result;
		EAT_ASSERT(result >= 0);
    }

    bool EA::Thread::Futex::WaitFSemaphore(const ThreadTime& /* timeoutAbsolute */)
    {
		int32_t result = sceKernelWaitSema(mSemaphore, 1, 0); // To do: support the timeout
		EAT_ASSERT(result >= 0);
        return (result >= 0);
    }

#elif defined(EA_PLATFORM_PSP2)
    
    EA::Thread::Futex::Futex()
    {
        int32_t result = sceKernelCreateLwMutex(
            &mMutexWorkArea,
            "Futex",   // Name
            SCE_KERNEL_LW_MUTEX_ATTR_RECURSIVE,
            0,      // Init count
            NULL);  // Optional parameter (reserved)

        (void)result;
        EAT_ASSERT(result == SCE_OK);
    }

    EA::Thread::Futex::~Futex()
    {
        EAT_ASSERT(!GetLockCount());
        int32_t result = sceKernelDeleteLwMutex(&mMutexWorkArea);
        (void)result;
        EAT_ASSERT(result == 0);
    }

    void EA::Thread::Futex::Lock()
    {
        int32_t result = sceKernelLockLwMutex(&mMutexWorkArea, 1, NULL);
        (void)result;
        EAT_ASSERT(result == 0);
    }

    bool EA::Thread::Futex::TryLock()
    {
        int32_t result = sceKernelTryLockLwMutex(&mMutexWorkArea, 1);
        
        if (result == 0)
            return true;
        else
        {
            EAT_ASSERT(result == SCE_KERNEL_ERROR_LW_MUTEX_FAILED_TO_OWN);
            return false;
        }
    }

    void EA::Thread::Futex::Unlock()
    {
        int32_t result = sceKernelUnlockLwMutex(&mMutexWorkArea, 1);
        (void)result;
        EAT_ASSERT(result == 0);
    }

    int EA::Thread::Futex::GetLockCount() const
    {
        SceKernelLwMutexInfo lwmutexInfo;
        lwmutexInfo.size = sizeof(SceKernelLwMutexInfo);

        int32_t result = sceKernelGetLwMutexInfo(const_cast<SceKernelLwMutexWork*>(&mMutexWorkArea), &lwmutexInfo);
        (void)result;
        EAT_ASSERT(result == 0);

        return lwmutexInfo.currentCount; 
    }  

    bool EA::Thread::Futex::HasLock() const
    {
        SceKernelLwMutexInfo lwmutexInfo;
        lwmutexInfo.size = sizeof(SceKernelLwMutexInfo);

        int32_t result = sceKernelGetLwMutexInfo(const_cast<SceKernelLwMutexWork*>(&mMutexWorkArea), &lwmutexInfo);
        (void)result;
        EAT_ASSERT(result == 0);

        return (lwmutexInfo.currentOwnerId == EA::Thread::GetThreadId());
    }

#elif defined(EA_PLATFORM_MICROSOFT) && !EA_USE_CPP11_CONCURRENCY && !EATHREAD_MANUAL_FUTEX_ENABLED

    #if defined(EA_PLATFORM_XENON)
        #pragma warning(push, 0)
        #include <XTL.h>
        #pragma warning(pop)
    #else
        #pragma warning(push, 0)
        #include <Windows.h>
        #pragma warning(pop)
    #endif

    // Validate what we assume to be invariants.
    EAT_CT_ASSERT(sizeof(CRITICAL_SECTION) <= (EA::Thread::FUTEX_PLATFORM_DATA_SIZE / sizeof(uint64_t) * sizeof(uint64_t)));

    #if defined(EA_PLATFORM_XENON)
        EAT_CT_ASSERT(offsetof(CRITICAL_SECTION, RecursionCount) == (5 * sizeof(int)));
        EAT_CT_ASSERT(offsetof(CRITICAL_SECTION, OwningThread)   == (6 * sizeof(int)));
    #elif defined(EA_PLATFORM_MICROSOFT) && defined(EA_PROCESSOR_X86_64)
        EAT_CT_ASSERT(offsetof(CRITICAL_SECTION, RecursionCount) == (3 * sizeof(int)));
        EAT_CT_ASSERT(offsetof(CRITICAL_SECTION, OwningThread)   == (4 * sizeof(int)));
    #elif defined(EA_PLATFORM_WIN32)
        EAT_CT_ASSERT(offsetof(CRITICAL_SECTION, RecursionCount) == (2 * sizeof(int)));
        EAT_CT_ASSERT(offsetof(CRITICAL_SECTION, OwningThread)   == (3 * sizeof(int)));
    #else
        EAT_FAIL_MSG("Need to verify offsetof.");
    #endif


#elif defined(EA_PLATFORM_MICROSOFT) && EATHREAD_MANUAL_FUTEX_ENABLED

    void EA::Thread::Futex::CreateFSemaphore()
    {
        mSemaphore = CreateSemaphoreA(NULL, 0, INT_MAX / 2, NULL);
        EAT_ASSERT(mSemaphore != 0);
    }

    void EA::Thread::Futex::DestroyFSemaphore()
    {
        if(mSemaphore)
            CloseHandle(mSemaphore);
    }

    void EA::Thread::Futex::SignalFSemaphore()
    {
        ReleaseSemaphore(mSemaphore, 1, NULL);
    }

    void EA::Thread::Futex::WaitFSemaphore()
    {
        WaitForSingleObject(mSemaphore, INFINITE);
    }

    bool EA::Thread::Futex::WaitFSemaphore(const ThreadTime& timeoutAbsolute)
    {
        int64_t timeoutRelativeMS = (int64_t)(timeoutAbsolute - GetThreadTime());
        if(timeoutRelativeMS < 1)
            timeoutRelativeMS = 1;
        return WaitForSingleObject(mSemaphore, (DWORD)timeoutRelativeMS) == WAIT_OBJECT_0;
    }

#elif (defined(EA_PLATFORM_PLAYSTATION2) || defined(EA_PLATFORM_PSP)) && EATHREAD_MANUAL_FUTEX_ENABLED

    #include <eekernel.h>

    void EA::Thread::Futex::CreateFSemaphore()
    {
         SemaParam sp;
         sp.maxCount  = 10000;
         sp.initCount = 0;

         mSemaphore = CreateSema(&sp);
         EAT_ASSERT(mSemaphore >= 0);
    }

    void EA::Thread::Futex::DestroyFSemaphore()
    {
        if(mSemaphore >= 0)
            DeleteSema(mSemaphore);
    }

    void EA::Thread::Futex::SignalFSemaphore()
    {
        SignalSema(mSemaphore);
    }

    void EA::Thread::Futex::WaitFSemaphore()
    {
        WaitSema(mSemaphore);
    }

    bool EA::Thread::Futex::WaitFSemaphore(const ThreadTime&)
    {
        WaitSema(mSemaphore); // Timeouts aren't supported.
        return true;
    }

#elif (defined(EA_PLATFORM_GAMECUBE) || defined(EA_PLATFORM_REVOLUTION)) && EATHREAD_MANUAL_FUTEX_ENABLED

    void EA::Thread::Futex::CreateFSemaphore()
    {
        OSInitSemaphore(&mSemaphore, 0);
    }

    void EA::Thread::Futex::DestroyFSemaphore()
    {
        // The GameCube doesn't have a mechanism for mutex destruction.
    }

    void EA::Thread::Futex::SignalFSemaphore()
    {
        OSSignalSemaphore(&mSemaphore);
    }

    void EA::Thread::Futex::WaitFSemaphore()
    {
        OSWaitSemaphore(&mSemaphore);
    }

    bool EA::Thread::Futex::WaitFSemaphore(const ThreadTime&)
    {
        OSWaitSemaphore(&mSemaphore); // Timeouts aren't supported.
        return true;
    }

#elif defined(EA_PLATFORM_CTR) && EATHREAD_MANUAL_FUTEX_ENABLED

    void EA::Thread::Futex::CreateFSemaphore()
    {
		mSemaphore.Initialize(0, nn::os::LightSemaphore::MAX_MAX_COUNT);
    }

    void EA::Thread::Futex::DestroyFSemaphore()
    {
        mSemaphore.Finalize();
    }

    void EA::Thread::Futex::SignalFSemaphore()
    {
        mSemaphore.Release();
    }

    void EA::Thread::Futex::WaitFSemaphore()
    {
        mSemaphore.Acquire();
    }

    bool EA::Thread::Futex::WaitFSemaphore(const ThreadTime&)
    {
        mSemaphore.Acquire(); // Does this platform support semaphore timeouts?
        return true;
    }

#endif





namespace EA
{
    namespace Thread
    {
        extern Allocator* gpAllocator;
    }
}


EA::Thread::Futex* EA::Thread::FutexFactory::CreateFutex()
{
    if(gpAllocator)
        return new(gpAllocator->Alloc(sizeof(EA::Thread::Futex))) EA::Thread::Futex;
    else
        return new EA::Thread::Futex;
}

void EA::Thread::FutexFactory::DestroyFutex(EA::Thread::Futex* pFutex)
{
    if(gpAllocator)
    {
        pFutex->~Futex();
        gpAllocator->Free(pFutex);
    }
    else
        delete pFutex;
}

size_t EA::Thread::FutexFactory::GetFutexSize()
{
    return sizeof(EA::Thread::Futex);
}

EA::Thread::Futex* EA::Thread::FutexFactory::ConstructFutex(void* pMemory)
{
    return new(pMemory) EA::Thread::Futex;
}

void EA::Thread::FutexFactory::DestructFutex(EA::Thread::Futex* pFutex)
{
    pFutex->~Futex();
}







