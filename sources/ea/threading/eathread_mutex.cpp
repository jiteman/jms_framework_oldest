/////////////////////////////////////////////////////////////////////////////
// eathread_mutex.cpp
//
// Copyright (c) 2003, Electronic Arts Inc. All rights reserved.
//
// Created by Paul Pedriana.
/////////////////////////////////////////////////////////////////////////////


#include "ea/eathreading/internal/config.h"

EA_DISABLE_VC_WARNING(4574)
#include <string.h>
#include <new>
EA_RESTORE_VC_WARNING()

#if !EA_THREADS_AVAILABLE
    #include <eathread/eathread_mutex.h>
#elif EA_USE_CPP11_CONCURRENCY
    #include "cpp11/eathread_mutex_cpp11.cpp"
    #if defined(CreateMutex)
        #undef CreateMutex
    #endif
#elif defined(EA_PLATFORM_UNIX) || EA_POSIX_THREADS_AVAILABLE
    #include "unix/eathread_mutex_unix.cpp"
#elif defined(EA_PLATFORM_MICROSOFT)
    #include "pc/eathread_mutex_pc.cpp"
#elif defined(EA_PLATFORM_PLAYSTATION2) || defined(EA_PLATFORM_PS2) || defined(EA_PLATFORM_PSP)
    #include "ps2/eathread_mutex_ps2.cpp"
#elif defined(EA_PLATFORM_PS3)
    #include "ps3/eathread_mutex_ps3.cpp"
#elif defined(EA_PLATFORM_PSP2)
    #include "psp2/eathread_mutex_psp2.cpp"
#elif defined(EA_PLATFORM_GAMECUBE) || defined(EA_PLATFORM_GC) || defined(EA_PLATFORM_REVOLUTION)
    #include "gc/eathread_mutex_gc.cpp"
#elif defined(EA_PLATFORM_CTR)
    #include "ctr/eathread_mutex_ctr.cpp"
#endif


namespace EA
{
    namespace Thread
    {
        extern Allocator* gpAllocator;
    }
}


EA::Thread::Mutex* EA::Thread::MutexFactory::CreateMutex()
{
    if(gpAllocator)
        return new(gpAllocator->Alloc(sizeof(EA::Thread::Mutex))) EA::Thread::Mutex;
    else
        return new EA::Thread::Mutex;
}

void EA::Thread::MutexFactory::DestroyMutex(EA::Thread::Mutex* pMutex)
{
    if(gpAllocator)
    {
        pMutex->~Mutex();
        gpAllocator->Free(pMutex);
    }
    else
        delete pMutex;
}

size_t EA::Thread::MutexFactory::GetMutexSize()
{
    return sizeof(EA::Thread::Mutex);
}

EA::Thread::Mutex* EA::Thread::MutexFactory::ConstructMutex(void* pMemory)
{
    return new(pMemory) EA::Thread::Mutex;
}

void EA::Thread::MutexFactory::DestructMutex(EA::Thread::Mutex* pMutex)
{
    pMutex->~Mutex();
}



///////////////////////////////////////////////////////////////////////////////
// non-threaded implementation
///////////////////////////////////////////////////////////////////////////////

#if defined(EA_THREAD_NONTHREADED_MUTEX) && EA_THREAD_NONTHREADED_MUTEX

    EAMutexData::EAMutexData()
        : mnLockCount(0)
    {
        // Empty
    }


    EA::Thread::MutexParameters::MutexParameters(bool /*bIntraProcess*/, const char* /*pName*/)
      : mbIntraProcess(true)
    {
    }


    EA::Thread::Mutex::Mutex(const MutexParameters* pMutexParameters, bool bDefaultParameters)
    {
        if(!pMutexParameters && bDefaultParameters)
        {
            MutexParameters parameters;
            Init(&parameters);
        }
        else
            Init(pMutexParameters);
    }


    EA::Thread::Mutex::~Mutex()
    {
        EAT_ASSERT(mMutexData.mnLockCount == 0);
        // There is no mutex shutdown on GameCube.
    }


    bool EA::Thread::Mutex::Init(const MutexParameters* /*pMutexParameters*/)
    {
        // Possibly copy pMutexParameters->mName to mMutexData.mName
        return true;
    }


    int EA::Thread::Mutex::Lock(const ThreadTime& /*timeoutAbsolute*/)
    {
        EAT_ASSERT(mMutexData.mnLockCount < 100000);

        return ++mMutexData.mnLockCount;
    }


    int EA::Thread::Mutex::Unlock()
    {
        EAT_ASSERT(mMutexData.mnLockCount > 0);

        return --mMutexData.mnLockCount;
    }


    int EA::Thread::Mutex::GetLockCount() const
    {
        return mMutexData.mnLockCount;
    }


    bool EA::Thread::Mutex::HasLock() const
    {
        return (mMutexData.mnLockCount > 0);
    }

#endif // EA_THREAD_NONTHREADED_MUTEX
