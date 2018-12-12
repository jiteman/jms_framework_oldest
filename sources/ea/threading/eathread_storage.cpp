/////////////////////////////////////////////////////////////////////////////
// eathread_storage.cpp
//
// Copyright (c) 2003, Electronic Arts Inc. All rights reserved.
//
// Created by Paul Pedriana.
/////////////////////////////////////////////////////////////////////////////


#include <eathread/eathread_storage.h>
#include <eathread/eathread.h>

EA_DISABLE_VC_WARNING(4574)
#include <new>
EA_RESTORE_VC_WARNING()


#if defined(EA_PLATFORM_UNIX) || EA_POSIX_THREADS_AVAILABLE
    #if defined(EA_PLATFORM_UNIX)
        #include <unistd.h>
    #elif defined(EA_PLATFORM_WINDOWS)
        #pragma warning(push, 0)
        #include <Windows.h>
        #pragma warning(pop)
    #endif

    EA::Thread::ThreadLocalStorage::ThreadLocalStorage()
        : mTLSData()
    {
        // To consider: Support the specification of a destructor instead of just passing NULL.
        mTLSData.mResult = pthread_key_create(&mTLSData.mKey, NULL);
        EAT_ASSERT(mTLSData.mResult == 0);
    }


    EA::Thread::ThreadLocalStorage::~ThreadLocalStorage()
    {
        if(mTLSData.mResult == 0)
            pthread_key_delete(mTLSData.mKey);
    }


    void* EA::Thread::ThreadLocalStorage::GetValue()
    {
        return pthread_getspecific(mTLSData.mKey);
    }


    bool EA::Thread::ThreadLocalStorage::SetValue(const void* pData)
    {
        if(pthread_setspecific(mTLSData.mKey, pData) == 0)
            return true;
        return false;
    }



#elif defined(EA_PLATFORM_MICROSOFT) && !defined(EA_PLATFORM_WINDOWS_PHONE) && !(defined(EA_PLATFORM_WINDOWS) && !EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)) 
    #if defined(EA_PLATFORM_XENON)
        #pragma warning(push, 0)
        #pragma warning(disable: 4311 4312)
        #include <XTL.h>
        #pragma warning(pop)
    #else
        #pragma warning(push, 0)
        #include <Windows.h>
        #pragma warning(pop)
    #endif

    EA::Thread::ThreadLocalStorage::ThreadLocalStorage()
        : mTLSData(TlsAlloc())
    {
        EAT_ASSERT(mTLSData != TLS_OUT_OF_INDEXES);
    }


    EA::Thread::ThreadLocalStorage::~ThreadLocalStorage()
    {
        if(mTLSData != TLS_OUT_OF_INDEXES)
            TlsFree(mTLSData);
    }


    void* EA::Thread::ThreadLocalStorage::GetValue()
    {
        return TlsGetValue(mTLSData);
    }


    bool EA::Thread::ThreadLocalStorage::SetValue(const void* pData)
    {
        if(TlsSetValue(mTLSData, (void*)pData))
            return true;
        return false;
    }

#elif defined(EA_PLATFORM_PS3)
    const _Tlskey_t kInvalidKey = -1; // _Tlskey_t values are indexes into a table.

    EA::Thread::ThreadLocalStorage::ThreadLocalStorage()
        : mTLSData(kInvalidKey) 
    {
        const int result = _Tlsalloc(&mTLSData, NULL); // PS3 ignores the second argument, at least as of SDK 250.
        if(result != 0)
            mTLSData = kInvalidKey;
    }


    EA::Thread::ThreadLocalStorage::~ThreadLocalStorage()
    {
        if(mTLSData != kInvalidKey)
            _Tlsfree(mTLSData);
    }


    void* EA::Thread::ThreadLocalStorage::GetValue()
    {
        EAT_ASSERT(mTLSData != kInvalidKey);
        return _Tlsget(mTLSData);
    }


    bool EA::Thread::ThreadLocalStorage::SetValue(const void* pData)
    {
        EAT_ASSERT(mTLSData != kInvalidKey);
        if(_Tlsset(mTLSData, (void*)pData) == 0)
            return true;
        return false;
    }

#elif defined(EA_PLATFORM_CTR)

    EA::Thread::ThreadLocalStorage::ThreadLocalStorage() : mTLSData()
    {
        // We need to set a value (NULL) because when the thread is initialized the thread storage is initialized to 0,
        // but if we create some local storage then release it, then we get some more, it may reuse that area.
        mTLSData.SetValue(NULL);
    }


    EA::Thread::ThreadLocalStorage::~ThreadLocalStorage()
    {
    }


    void* EA::Thread::ThreadLocalStorage::GetValue()
    {
        return reinterpret_cast<void *>(mTLSData.GetValue());
    }


    bool EA::Thread::ThreadLocalStorage::SetValue(const void* pData)
    {
        mTLSData.SetValue(reinterpret_cast<uptr>(pData));

        return true;
    }

#elif (!EA_THREADS_AVAILABLE || defined(EA_PLATFORM_CONSOLE) || defined(EA_PLATFORM_PLAYSTATION2) || defined(EA_PLATFORM_GAMECUBE) || defined(EA_PLATFORM_REVOLUTION) || defined(EA_PLATFORM_PSP)) && !defined(EA_PLATFORM_PSP2)

    #include <string.h>

    #if defined(EA_PLATFORM_PLAYSTATION2) || defined(EA_PLATFORM_PSP)
        #define OSEnableInterrupts() __asm__ __volatile__("ei")    
        #define OSDisableInterrupts() \
        { \
                uint32_t status; \
                do{ \
                    __asm__ __volatile__(".p2align 3"); \
                    __asm__ __volatile__("di"); \
                    __asm__ __volatile__("sync.p"); \
                    __asm__ __volatile__("mfc0 %0, $12" : "=r"(status) : ); \
                }while(status & 0x00010000); \
        }
        
    #elif defined(EA_PLATFORM_REVOLUTION)
        #include <revolution/os.h> // for OSDisableInterrupts() / OSEnableInterrupts(). Could be implemented with a mutex.

    #elif defined(EA_PLATFORM_GAMECUBE)
        #include <dolphin/os.h> // for OSDisableInterrupts() / OSEnableInterrupts(). Could be implemented with a mutex.

    #elif !EA_THREADS_AVAILABLE
        #define OSEnableInterrupts()
        #define OSDisableInterrupts()

    #else
        #error Need to define EnableInterrupts/DisableInterrupts for the given platform.
    #endif


    EAThreadLocalStorageData::ThreadToDataPair* EAThreadLocalStorageData::GetTLSEntry(bool bCreateIfNotFound)
    {
        const int                  kArraySize = (sizeof(mDataArray) / sizeof(mDataArray[0]));
        ThreadToDataPair*          pCurrent, *pEnd;

        EA::Thread::ThreadUniqueId nCurrentThreadID;
        EAThreadGetUniqueId(nCurrentThreadID);

        // The code below is likely to execute very quickly and never transfers 
        // execution outside the function, so we can very briefly disable interrupts
        // for the period needed to do the logic below.
        OSDisableInterrupts();

        // We make the assumption that there are likely to be less than 10 threads most of 
        // the time. Thus, instead of maintaining a sorted array and do a binary search 
        // within that array, we do a linear search. An improvement would be to make the 
        // array be sorted if it goes above some preset size, such as 20.
        for(pCurrent = mDataArray, pEnd = mDataArray + mDataArrayCount; pCurrent < pEnd; ++pCurrent)
        {
            if(pCurrent->mThreadID == nCurrentThreadID)
            {
                OSEnableInterrupts();
                return pCurrent;
            }
        }

        if((pCurrent >= pEnd) && ((mDataArrayCount + 1) < kArraySize) && bCreateIfNotFound) // If we didn't find it above and there is more room and we should create if not found...
        {
            pCurrent = mDataArray + mDataArrayCount++;
            pCurrent->mThreadID = nCurrentThreadID;
        }
        else
            pCurrent = NULL;

        OSEnableInterrupts();

        return pCurrent;
    }


    EA::Thread::ThreadLocalStorage::ThreadLocalStorage()
    {
        memset(mTLSData.mDataArray, 0, sizeof(mTLSData.mDataArray));
        mTLSData.mDataArrayCount = 0;
    }


    EA::Thread::ThreadLocalStorage::~ThreadLocalStorage()
    {
        // Nothing to do.
    }


    void* EA::Thread::ThreadLocalStorage::GetValue()
    {
        EAThreadLocalStorageData::ThreadToDataPair* const pTDP = mTLSData.GetTLSEntry(false);
        if(pTDP)
            return (void*)pTDP->mpData;
        return NULL;
    }


    bool EA::Thread::ThreadLocalStorage::SetValue(const void* pData)
    {
        if(pData == NULL)
        {  // We remove it from the container so that the container can have room for others.
            EAThreadLocalStorageData::ThreadToDataPair* pTDP = mTLSData.GetTLSEntry(false);

            if(pTDP)
            {
                OSDisableInterrupts(); // Briefly disable interrupts for the duration of the logic below.
                const EAThreadLocalStorageData::ThreadToDataPair* const pTDPEnd = mTLSData.mDataArray + mTLSData.mDataArrayCount;
                while(++pTDP <= pTDPEnd)    // What we do here is move all the other values downward. This is an O(n) operation, 
                    pTDP[-1] = pTDP[0];     // but the number of unique threads usinug us is likely to be pretty small.
                mTLSData.mDataArrayCount = (int)(pTDPEnd - mTLSData.mDataArray - 1);
                OSEnableInterrupts();
            }
            return true;
        }

        EAThreadLocalStorageData::ThreadToDataPair* const pTDP = mTLSData.GetTLSEntry(true);
        if(pTDP)
            pTDP->mpData = pData;
        return (pTDP != NULL);
    }

#else

    // Use reference std::map implementation.
    EA_DISABLE_VC_WARNING(4574)
    #include <map>
    EA_RESTORE_VC_WARNING()

    #include <eathread/eathread_futex.h>

    void** EAThreadLocalStorageData::GetTLSEntry(bool bCreateIfNotFound)
    {
        EA::Thread::ThreadUniqueId nThreadID;
        EAThreadGetUniqueId(nThreadID);

        EA::Thread::AutoFutex autoFutex(mFutex);

        if(bCreateIfNotFound) // We expect this to be true most of the time.
        {
            // Create as needed
            if (mThreadToDataMap == NULL)
            {
                mThreadToDataMap = new std::map<EA::Thread::ThreadUniqueId, const void*>;
            }

            return (void**)&((*mThreadToDataMap)[nThreadID]); // Dereferencing a std::map value by index inserts the value if it is not present.
        }

        if (mThreadToDataMap == NULL)
        {
            return NULL;
        }
        
        std::map<EA::Thread::ThreadUniqueId, const void*>::iterator it(mThreadToDataMap->find(nThreadID));
        if(it != mThreadToDataMap->end())
        {
            std::map<EA::Thread::ThreadUniqueId, const void*>::value_type& value = *it;
            return (void**)&value.second;
        }
        return NULL;
    }


    EA::Thread::ThreadLocalStorage::ThreadLocalStorage()
    {
    }


    EA::Thread::ThreadLocalStorage::~ThreadLocalStorage()
    {
        // Nothing to do.
    }


    void* EA::Thread::ThreadLocalStorage::GetValue()
    {
        void** const ppData = mTLSData.GetTLSEntry(false);
        if(ppData)
            return *ppData;
        return NULL;
    }


    bool EA::Thread::ThreadLocalStorage::SetValue(const void* pData)
    {
        if(pData == NULL)
        {
            ThreadUniqueId nThreadID;
            EAThreadGetUniqueId(nThreadID);

            EA::Thread::AutoFutex autoFutex(mTLSData.mFutex);
			
            if (mTLSData.mThreadToDataMap)
            {
                std::map<EA::Thread::ThreadUniqueId, const void*>::iterator it(mTLSData.mThreadToDataMap->find(nThreadID));
                if(it != mTLSData.mThreadToDataMap->end())
                    mTLSData.mThreadToDataMap->erase(it);
            }
            return true;
        }

        void** const ppData = mTLSData.GetTLSEntry(true);
        if(ppData)
            *ppData = (void*)pData;
        return (*ppData != NULL);
    }

#endif


namespace EA
{
    namespace Thread
    {
        extern Allocator* gpAllocator;
    }
}


EA::Thread::ThreadLocalStorage* EA::Thread::ThreadLocalStorageFactory::CreateThreadLocalStorage()
{
    if(gpAllocator)
        return new(gpAllocator->Alloc(sizeof(EA::Thread::ThreadLocalStorage))) EA::Thread::ThreadLocalStorage;
    else
        return new EA::Thread::ThreadLocalStorage;
}

void EA::Thread::ThreadLocalStorageFactory::DestroyThreadLocalStorage(EA::Thread::ThreadLocalStorage* pThreadLocalStorage)
{
    if(gpAllocator)
    {
        pThreadLocalStorage->~ThreadLocalStorage();
        gpAllocator->Free(pThreadLocalStorage);
    }
    else
        delete pThreadLocalStorage;
}

size_t EA::Thread::ThreadLocalStorageFactory::GetThreadLocalStorageSize()
{
    return sizeof(EA::Thread::ThreadLocalStorage);
}

EA::Thread::ThreadLocalStorage* EA::Thread::ThreadLocalStorageFactory::ConstructThreadLocalStorage(void* pMemory)
{
    return new(pMemory) EA::Thread::ThreadLocalStorage;
}

void EA::Thread::ThreadLocalStorageFactory::DestructThreadLocalStorage(EA::Thread::ThreadLocalStorage* pThreadLocalStorage)
{
    pThreadLocalStorage->~ThreadLocalStorage();
}


#undef OSEnableInterrupts   
#undef OSDisableInterrupts




