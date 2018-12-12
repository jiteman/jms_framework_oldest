///////////////////////////////////////////////////////////////////////////////
// Thread.inl
//
// Copyright (c) 2005, Electronic Arts. All Rights Reserved.
// Maintained by Paul Pedriana
///////////////////////////////////////////////////////////////////////////////


// ********************************************************
// To do: Now that EAStdC is dependent on EAThread, we can  
//        remove this thread code and use EAThread instead.
// ********************************************************


#ifndef EASTDC_THREAD_INL
#define EASTDC_THREAD_INL


#include "EA/StdC/EAFixedPoint.h"
#include <EAStdC/internal/Thread.h>
#include EA_ASSERT_HEADER


namespace EA
{
    namespace StdC
    {

        #if defined(EA_PLATFORM_MICROSOFT)
            inline Mutex::Mutex()
            {
                #if defined(EA_PLATFORM_XENON) || !defined(_WIN32_WINNT) || (_WIN32_WINNT < 0x0403)
                    InitializeCriticalSection(&mMutex);
                #elif !EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
                    BOOL result = InitializeCriticalSectionEx(&mMutex, 10, 0);
                    EA_ASSERT(result != 0); EA_UNUSED(result);
                #else
                    BOOL result = InitializeCriticalSectionAndSpinCount(&mMutex, 10);
                    EA_ASSERT(result != 0); EA_UNUSED(result);
                #endif
            }

            inline Mutex::~Mutex()
            {
                DeleteCriticalSection(&mMutex);
            }

            inline void Mutex::Lock()
            {
                EnterCriticalSection(&mMutex);
            }

            inline void Mutex::Unlock()
            {
                LeaveCriticalSection(&mMutex);
            }

        #elif defined(EA_PLATFORM_PS3)
            inline Mutex::Mutex()
            {
                sys_lwmutex_attribute_t lwattr;
                sys_lwmutex_attribute_initialize(lwattr);
                lwattr.attr_recursive = SYS_SYNC_RECURSIVE;

                sys_lwmutex_create(&mMutex, &lwattr);

                #ifdef EA_DEBUG
                    sys_lwmutex_lock(&mMutex, 0);
                    sys_lwmutex_unlock(&mMutex);
                #endif
            }

            inline Mutex::~Mutex()
            {
                sys_lwmutex_destroy(&mMutex);
            }

            inline void Mutex::Lock()
            {
                sys_lwmutex_lock(&mMutex, 0);
            }

            inline void Mutex::Unlock()
            {
                sys_lwmutex_unlock(&mMutex);
            }

        #elif defined(EA_PLATFORM_GAMECUBE) || defined(EA_PLATFORM_REVOLUTION)
            inline Mutex::Mutex()
            {
                OSInitMutex(&mMutex);
            }

            inline Mutex::~Mutex()
            {
                // Nothing to do except possibly assert the mutex is unlocked.
            }

            inline void Mutex::Lock()
            {
                OSLockMutex(&mMutex);
            }

            inline void Mutex::Unlock()
            {
                OSUnlockMutex(&mMutex);
            }

        #elif defined(EA_PLATFORM_POSIX)
            inline Mutex::Mutex()
            {
                pthread_mutexattr_t attr;

                pthread_mutexattr_init(&attr);
                pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_PRIVATE); 
                pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
                pthread_mutex_init(&mMutex, &attr);
                pthread_mutexattr_destroy(&attr);
            }

            inline Mutex::~Mutex()
            {
                pthread_mutex_destroy(&mMutex);
            }

            inline void Mutex::Lock()
            {
                pthread_mutex_lock(&mMutex);
            }

            inline void Mutex::Unlock()
            {
                pthread_mutex_unlock(&mMutex);
            }

        #elif defined(EA_PLATFORM_PLAYSTATION2)
            // The following are slightly faster than calling EI() / DI().
            #define MIPSEnableInterrupts() __asm__ __volatile__("ei")    
            #define MIPSDisableInterrupts() \
            { \
                    uint32_t status; \
                    do{ \
                        __asm__ __volatile__(".p2align 3"); \
                        __asm__ __volatile__("di"); \
                        __asm__ __volatile__("sync.p"); \
                        __asm__ __volatile__("mfc0 %0, $12" : "=r"(status) : ); \
                    }while(status & 0x00010000); \
            }



            inline Mutex::Mutex()
            {
                SemaParam sp; 
                sp.maxCount = 10000; // It's important that maxCount be a large 
                sp.initCount = 0;    // number (>= count of concurrent threads).

                mMutex.mnThreadId  = 0;
                mMutex.mnLockCount = 0;
                mMutex.mnWaitCount = 0;
                mMutex.mSemaphore  = CreateSema(&sp);
            }

            inline Mutex::~Mutex()
            {
                if(mMutex.mSemaphore >= 0)
                    DeleteSema(mMutex.mSemaphore);
            }

            inline void Mutex::Lock()
            {
                const int nThreadId = GetThreadId();

                if(mMutex.mnLockCount && (mMutex.mnThreadId == nThreadId))
                    ++mMutex.mnLockCount;   // This is safe to do outside of MIPSDisableInterrupts(); because we have the lock.
                else
                {
                    MIPSDisableInterrupts();           // Disable interrupts briefly.

                    while(mMutex.mnLockCount)
                    {
                        mMutex.mnWaitCount++;          // Note that we aren't using the semaphore as a mutex, but rather as a signal about the status of the mutex.
                        MIPSEnableInterrupts();        // Unless there are many contentious threads, 95+% of the time we won't get to this line.
                        WaitSema(mMutex.mSemaphore);   // This is a rather slow function, hence the above code to prevent us from very often executing this.
                        MIPSDisableInterrupts();
                    }

                    mMutex.mnThreadId = nThreadId;
                    mMutex.mnLockCount++;
                    MIPSEnableInterrupts();
                }
            }

            inline void Mutex::Unlock()
            {
                MIPSDisableInterrupts();

                const int nReturnValue(--mMutex.mnLockCount);  // This is safe to do because we have the lock.

                if((nReturnValue == 0) && mMutex.mnWaitCount)  // If we are the last lock being unlocked...
                {
                    mMutex.mnWaitCount--;
                    MIPSEnableInterrupts();
                    SignalSema(mMutex.mSemaphore);
                }
                else
                    MIPSEnableInterrupts();
            }

            #undef mpMutex

        #else

            inline Mutex::Mutex()
            {
            }

            inline Mutex::~Mutex()
            {
            }

            inline void Mutex::Lock()
            {
            }

            inline void Mutex::Unlock()
            {
            }

        #endif

    }
}




#endif // Header include guard

