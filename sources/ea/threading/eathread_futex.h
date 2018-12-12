/////////////////////////////////////////////////////////////////////////////
// eathread_futex.h
//
// Copyright (c) 2006, Electronic Arts Inc. All rights reserved.
// Created by Paul Pedriana, Maxis
//
// Implements a fast, user-space mutex. Also known as a lightweight mutex.
/////////////////////////////////////////////////////////////////////////////


#ifndef EATHREAD_EATHREAD_FUTEX_H
#define EATHREAD_EATHREAD_FUTEX_H


#ifndef EATHREAD_EATHREAD_H
    #include <eathread/eathread.h>
#endif
#ifndef EATHREAD_ATOMIC_H
    #include <eathread/eathread_atomic.h>
#endif
#ifndef EATHREAD_SYNC_H
    #include <eathread/eathread_sync.h>
#endif
#ifndef EATHREAD_MUTEX_H
    #include <eathread/eathread_mutex.h>
#endif
#include <stddef.h>

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
    #pragma once // Some compilers (e.g. VC++) benefit significantly from using this. We've measured 3-4% build speed improvements in apps as a result.
#endif



///////////////////////////////////////////////////////////////////////////////
// EATHREAD_MANUAL_FUTEX_ENABLED
//
// Defined as 0 or 1.
// If enabled then Futex is implemented with atomics and semaphores instead of
// via a direct system-supported lightweight mutex implementation.
//
#ifndef EATHREAD_MANUAL_FUTEX_ENABLED
    #if defined(EA_PLATFORM_MICROSOFT)              // VC++ has CriticalSection, which is a futex.
        #define EATHREAD_MANUAL_FUTEX_ENABLED 0     // Currently 0 because that's best. Can be set to 1.
    #elif defined(EA_PLATFORM_PSP2)                 // PSP2 has light-weight mutexes
        #define EATHREAD_MANUAL_FUTEX_ENABLED 0
    #elif defined(EA_PLATFORM_PS3)                  // PS3 has lwmutex, which is a futex.
        #define EATHREAD_MANUAL_FUTEX_ENABLED 1     // Currently 1 for backward compatibility. Can be set to 0.
    #else
        #define EATHREAD_MANUAL_FUTEX_ENABLED 1     // For most platforms this must always be 1, as there is no alternative.
    #endif
#endif
///////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////
/// Futex data
///
/// This is used internally by class Futex.
/// Note that we don't use an EAThread semaphore, as the direct semaphore
/// we use here is more direct and avoid inefficiencies that result from 
/// the possibility of EAThread semaphores being optimized for being 
/// standalone.
/// 
#if !EA_THREADS_AVAILABLE
    #define EA_THREAD_NONTHREADED_FUTEX 1

    #if EATHREAD_MANUAL_FUTEX_ENABLED
        struct EAFutexSemaphore
        {
            int mnCount;
        };
    #endif

#elif EA_USE_CPP11_CONCURRENCY
    EA_DISABLE_VC_WARNING(4265 4365 4836 4571 4625 4626 4628 4193 4127 4548)
    #include <mutex>
    EA_RESTORE_VC_WARNING()

#elif defined(__APPLE__)
    #if EATHREAD_MANUAL_FUTEX_ENABLED
        #include <eathread/eathread_semaphore.h>
        typedef EA::Thread::Semaphore EAFutexSemaphore;
    #endif

#elif defined(EA_PLATFORM_AIRPLAY)
    #if EATHREAD_MANUAL_FUTEX_ENABLED
        #include <KD/kd.h>
        typedef KDThreadSem* EAFutexSemaphore;
    #endif

#elif defined(EA_PLATFORM_UNIX) || EA_POSIX_THREADS_AVAILABLE
    #if EATHREAD_MANUAL_FUTEX_ENABLED
        #include <semaphore.h>
        typedef sem_t EAFutexSemaphore;
    #endif

#elif defined(EA_PLATFORM_PS3)
    #if EATHREAD_MANUAL_FUTEX_ENABLED
        #include <sdk_version.h>
        #include <sys/synchronization.h>

        typedef sys_semaphore_t EAFutexSemaphore;
    #endif

#elif defined(EA_PLATFORM_PSP2)
    #if EATHREAD_MANUAL_FUTEX_ENABLED
        #include <kernel.h>
        typedef SceUID EAFutexSemaphore;
    #endif

#elif defined(EA_PLATFORM_MICROSOFT)

    #ifdef EA_PLATFORM_XENON
        extern "C" 
        {
            struct _RTL_CRITICAL_SECTION;

            void          __stdcall RtlInitializeCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection);
            void          __stdcall RtlEnterCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection);
            void          __stdcall RtlLeaveCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection);
            unsigned long __stdcall RtlTryEnterCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection);
            unsigned long __stdcall GetCurrentThreadId();
        }
    #else
        extern "C"
        {
            #if defined(EA_COMPILER_GNUC)
                // Mingw declares these slightly differently.
                struct _CRITICAL_SECTION;
                __declspec(dllimport) void          __stdcall InitializeCriticalSection(_CRITICAL_SECTION* pCriticalSection);
                __declspec(dllimport) void          __stdcall DeleteCriticalSection(_CRITICAL_SECTION* pCriticalSection);
                __declspec(dllimport) void          __stdcall EnterCriticalSection(_CRITICAL_SECTION* pCriticalSection);
                __declspec(dllimport) void          __stdcall LeaveCriticalSection(_CRITICAL_SECTION* pCriticalSection);
                __declspec(dllimport) int           __stdcall TryEnterCriticalSection(_CRITICAL_SECTION* pCriticalSection);
            #else
                struct _RTL_CRITICAL_SECTION;
                __declspec(dllimport) void          __stdcall InitializeCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection);
                __declspec(dllimport) void          __stdcall DeleteCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection);
                __declspec(dllimport) void          __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection);
                __declspec(dllimport) void          __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection);
                __declspec(dllimport) int           __stdcall TryEnterCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection);
            #endif

            __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
        }
    #endif

    #if EATHREAD_MANUAL_FUTEX_ENABLED
        typedef void* EAFutexSemaphore; // void* instead of HANDLE to avoid #including windows headers.
    #endif

#elif defined(EA_PLATFORM_PLAYSTATION2) || defined(EA_PLATFORM_PSP)
    #if EATHREAD_MANUAL_FUTEX_ENABLED
        typedef int EAFutexSemaphore;
    #endif

#elif defined(EA_PLATFORM_REVOLUTION)
    #if EATHREAD_MANUAL_FUTEX_ENABLED
        #include <revolution/os.h>
        typedef OSSemaphore EAFutexSemaphore;
    #endif

#elif defined(EA_PLATFORM_GAMECUBE)
    #if EATHREAD_MANUAL_FUTEX_ENABLED
        #include <dolphin/os.h>
        typedef OSSemaphore EAFutexSemaphore;
    #endif

#elif defined(EA_PLATFORM_CTR)
    #if EATHREAD_MANUAL_FUTEX_ENABLED
        #include <nn/os/os_LightSemaphore.h>
        typedef ::nn::os::LightSemaphore EAFutexSemaphore;
    #endif

#else
    #define EA_THREAD_NONTHREADED_FUTEX 1

    #if EATHREAD_MANUAL_FUTEX_ENABLED
        struct EAFutexSemaphore
        {
            int mnCount;
        };
    #endif
#endif
/////////////////////////////////////////////////////////////////////////




namespace EA
{
    namespace Thread
    {
        #if defined(_WIN64)
            static const int FUTEX_PLATFORM_DATA_SIZE = 40; // CRITICAL_SECTION is 40 bytes on Win64.
        #elif defined(_WIN32)
            static const int FUTEX_PLATFORM_DATA_SIZE = 32; // CRITICAL_SECTION is 24 bytes on Win32 and 28 bytes on XBox 360.
        #endif


        /// class Futex
        ///
        /// A Futex is a fast user-space mutex. It works by attempting to use
        /// atomic integer updates for the common case whereby the mutex is
        /// not already locked. If the mutex is already locked then the futex
        /// drops down to waiting on a system-level semaphore. The result is 
        /// that uncontested locking operations can be significantly faster 
        /// than contested locks. Contested locks are slightly slower than in 
        /// the case of a formal mutex, but usually not by much.
        ///
        /// The Futex acts the same as a conventional mutex with respect to  
        /// memory synchronization. Specifically: 
        ///     - A Lock or successful TryLock implies a read barrier (i.e. acquire).
        ///     - A second lock by the same thread implies no barrier.
        ///     - A failed TryLock implies no barrier.
        ///     - A final unlock by a thread implies a write barrier (i.e. release).
        ///     - A non-final unlock by a thread implies no barrier.
        ///
        /// Futex limitations relative to Mutexes:
        ///     - Futexes cannot be inter-process.
        ///     - Futexes cannot be named.
        ///     - Futexes cannot participate in condition variables. A special 
        ///       condition variable could be made that works with them, though.
        ///     - Futex locks don't have timeouts. This could probably be
        ///       added with some work, though users generally shouldn't need timeouts. 
        ///
        class EATHREADLIB_API Futex
        {
        public:
            enum Result
            {
                kResultTimeout = -2
            };

            /// Futex
            ///
            /// Creates a Futex. There are no creation options.
            ///
            Futex();

            /// ~Futex
            ///
            /// Destroys an existing futex. The futex must not be locked by any thread
            /// upon this call, otherwise the resulting behaviour is undefined.
            ///
            ~Futex();

            /// TryLock
            ///
            /// Tries to lock the futex; returns true if possible.
            /// This function always returns immediately. It will return false if 
            /// the futex is locked by another thread, and it will return true 
            /// if the futex is not locked or is already locked by the current thread.
            ///
            bool TryLock();

            /// Lock
            ///
            /// Locks the futex; returns the new lock count.
            /// If the futex is locked by another thread, this call will block until
            /// the futex is unlocked. If the futex is not locked or is locked by the
            /// current thread, this call will return immediately.
            ///
            void Lock();

            /// Lock
            ///
            /// Tries to lock the futex until the given time.
            /// If the futex is locked by another thread, this call will block until
            /// the futex is unlocked or the given time has passed. If the futex is not locked
            /// or is locked by the current thread, this call will return immediately.
            ///
            /// Return value:
            ///     kResultTimeout Timeout
            ///     > 0            The new lock count.
            int Lock(const ThreadTime& timeoutAbsolute);

            /// Unlock
            ///
            /// Unlocks the futex. The futex must already be locked at least once by 
            /// the calling thread. Otherwise the behaviour is not defined.
            ///
            void Unlock();

            /// GetLockCount
            ///
            /// Returns the number of locks on the futex. The return value from this 
            /// function is only reliable if the calling thread already has one lock on 
            /// the futex. Otherwise the returned value may not represent actual value
            /// at any point in time, as other threads lock or unlock the futex soon after the call.
            ///
            int GetLockCount() const;

            /// HasLock
            /// Returns true if the current thread has the futex locked. 
            bool HasLock() const;

        protected:
            #if EATHREAD_MANUAL_FUTEX_ENABLED
                void CreateFSemaphore();
                void DestroyFSemaphore();
                void SignalFSemaphore();
                void WaitFSemaphore();
                bool WaitFSemaphore(const ThreadTime& timeoutAbsolute);
            #endif

        private:
            // Objects of this class are not copyable.
            Futex(const Futex&){}
            Futex& operator=(const Futex&){ return *this; }

        protected:
            #if EATHREAD_MANUAL_FUTEX_ENABLED
                AtomicUWord      mUseCount;         /// Not the same thing as lock count, as waiters increment this value.
                Uint             mRecursionCount;   /// The number of times the lock-owning thread has the mutex.
                ThreadUniqueId   mThreadUniqueId;   /// Unique id for owning thread; not necessarily same as type ThreadId.
                EAFutexSemaphore mSemaphore;        /// OS-level semaphore that waiters wait on when lock attempts failed.
            #else
                #if EA_USE_CPP11_CONCURRENCY
                    std::recursive_timed_mutex mMutex;
                    int mnLockCount;
                    std::thread::id mLockingThread;
                #elif defined(EA_COMPILER_MSVC) && defined(EA_PLATFORM_MICROSOFT) // In the case of Microsoft platforms, we just use CRITICAL_SECTION, as it is essentially a futex.
                    // We use raw structure math because otherwise we'd expose the user to system headers, 
                    // which breaks code and bloats builds. We validate our math in eathread_futex.cpp.
                    #if defined(_WIN64)
                        uint64_t mCRITICAL_SECTION[FUTEX_PLATFORM_DATA_SIZE / sizeof(uint64_t)];
                    #else
                        uint64_t mCRITICAL_SECTION[FUTEX_PLATFORM_DATA_SIZE / sizeof(uint64_t)];
                    #endif
                #elif defined(EA_PLATFORM_PS3)
                    sys_lwmutex_t mlwmutex;
                #elif defined(EA_PLATFORM_CTR)
                    ::nn::os::LightSemaphore mLightSemaphore;
                #elif defined(EA_PLATFORM_PSP2)
                    EA_ALIGN(8) SceKernelLwMutexWork mMutexWorkArea;
                #else
                    #define EAT_FUTEX_USE_MUTEX 1
                    EA::Thread::Mutex mMutex;
                #endif
            #endif
        };



        /// FutexFactory
        /// 
        /// Implements a factory-based creation and destruction mechanism for class Futex.
        /// A primary use of this would be to allow the Futex implementation to reside in
        /// a private library while users of the class interact only with the interface
        /// header and the factory. The factory provides conventional create/destroy 
        /// semantics which use global operator new, but also provides manual construction/
        /// destruction semantics so that the user can provide for memory allocation 
        /// and deallocation.
        ///
        class EATHREADLIB_API FutexFactory
        {
        public:
            static Futex*  CreateFutex();                    // Internally implemented as: return new Futex;
            static void    DestroyFutex(Futex* pFutex);      // Internally implemented as: delete pFutex;

            static size_t  GetFutexSize();                   // Internally implemented as: return sizeof(Futex);
            static Futex*  ConstructFutex(void* pMemory);    // Internally implemented as: return new(pMemory) Futex;
            static void    DestructFutex(Futex* pFutex);     // Internally implemented as: pFutex->~Futex();
        };



        /// class AutoFutex
        /// An AutoFutex locks the Futex in its constructor and 
        /// unlocks the Futex in its destructor (when it goes out of scope).
        class EATHREADLIB_API AutoFutex
        {
        public:
            AutoFutex(Futex& futex);
           ~AutoFutex();

        protected:
            Futex& mFutex;

            // Prevent copying by default, as copying is dangerous.
            AutoFutex(const AutoFutex&);
            const AutoFutex& operator=(const AutoFutex&);
        };


    } // namespace Thread

} // namespace EA






///////////////////////////////////////////////////////////////////////////////
// Inlines
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// EAFutexReadBarrier
//
// For futexes, which are intended to be used only in user-space and without 
// talking to IO devices, DMA memory, or uncached memory, we directly use
// memory barriers.
#if defined(EA_PROCESSOR_POWERPC) && (EA_MEMORY_BARRIERS_REQUIRED == 0) // EA_MEMORY_BARRIERS_REQUIRED is defined in eathread_sync.h
    #define EAFutexReadBarrier()      // In this case we have only a single CPU, though with
    #define EAFutexWriteBarrier()     // hyperthreading. However, the hyperthreads use the same
    #define EAFutexReadWriteBarrier() // memory buffer/cache.
#else
    #define EAFutexReadBarrier      EAReadBarrier
    #define EAFutexWriteBarrier     EAWriteBarrier
    #define EAFutexReadWriteBarrier EAReadWriteBarrier
#endif
///////////////////////////////////////////////////////////////////////////////



namespace EA
{
    namespace Thread
    {
        #if EATHREAD_MANUAL_FUTEX_ENABLED

            inline Futex::Futex()
              : mUseCount(0), 
                mRecursionCount(0),
                mThreadUniqueId(kThreadUniqueIdInvalid),
                mSemaphore()
            {
                CreateFSemaphore();
            }


            inline Futex::~Futex()
            {
                EAT_ASSERT(mUseCount == 0);

                DestroyFSemaphore();
            }


            inline bool Futex::TryLock()
            {
                ThreadUniqueId threadUniqueId;
                EAThreadGetUniqueId(threadUniqueId);

                if(EATHREAD_LIKELY(mUseCount.SetValueConditional(1, 0)))
                {
                    mThreadUniqueId = threadUniqueId;
                    mRecursionCount = 1;
                    EAFutexReadBarrier();
                    return true;
                }

                if(EATHREAD_LIKELY(mThreadUniqueId == threadUniqueId))
                {
                    ++mUseCount;
                    ++mRecursionCount;
                    return true;
                }

                return false;
            }


            inline void Futex::Lock()
            {
                // To consider: Do we want to have the ability spin-wait here?

                // Note: It has been observed that on PS3 the code below is about as
                // fast as the PS3 lwmutex, but the code below would be faster if 
                // it was written in asm, as the PS3 compiler is not generating perfect
                // code. Also, this function is in fact inlined by GCC fairly well,
                // so this code beats the PS3 lwmutex on the grounds that it won't 
                // induce an instruction cache miss, which can be a few hundred CPU cycles.

                ThreadUniqueId threadUniqueId;
                EAThreadGetUniqueId(threadUniqueId);

                if(EATHREAD_LIKELY(++mUseCount == 1)) // If we are newly gaining the lock...
                {
                    mThreadUniqueId = threadUniqueId;
                    EAFutexReadBarrier();
                }
                else if(EATHREAD_UNLIKELY(mThreadUniqueId != threadUniqueId))
                {
                    WaitFSemaphore(); // This will execute a read/write barrier.
                    mThreadUniqueId = threadUniqueId;

                    // EAWriteBarrier();  Question: Do we really need/want to do this? I think not, because the only incorrect values a separate thread would see after this point for mThreadUniqueId are 0 or this thread's id. Things could go wrong only if they see their own id, which would always be impossible. Right? Perhaps I am missing something.
                }

                ++mRecursionCount;
            }


            inline int Futex::Lock(const ThreadTime& timeoutAbsolute)
            {
                // Note: It has been observed that on PS3 the code below is about as
                // fast as the PS3 lwmutex, but the code below would be faster if 
                // it was written in asm, as the PS3 compiler is not generating perfect
                // code. Also, this function is in fact inlined by GCC fairly well,
                // so this code beats the PS3 lwmutex on the grounds that it won't 
                // induce an instruction cache miss, which can be a few hundred CPU cycles.
                if(timeoutAbsolute == kTimeoutNone)
                {
                    Lock();
                    return GetLockCount();
                }
                else if(timeoutAbsolute == kTimeoutImmediate)
                {
                    if(TryLock())
                        return GetLockCount();
                    else
                        return kResultTimeout;
                }
                else
                {
                    ThreadUniqueId threadUniqueId;
                    EAThreadGetUniqueId(threadUniqueId);

                    if(EATHREAD_LIKELY(++mUseCount == 1)) // If we are newly gaining the lock...
                    {
                        mThreadUniqueId = threadUniqueId;
                        EAFutexReadBarrier();
                    }
                    else if(EATHREAD_UNLIKELY(mThreadUniqueId != threadUniqueId))
                    {
                        if(!WaitFSemaphore(timeoutAbsolute))
                            return kResultTimeout;
                        mThreadUniqueId = threadUniqueId;
                    }

                    ++mRecursionCount;
                    return GetLockCount();
                }
            }


            inline void Futex::Unlock()
            {
                #if EAT_ASSERT_ENABLED
                    ThreadUniqueId threadUniqueId;
                    EAThreadGetUniqueId(threadUniqueId);
                    EAT_ASSERT(mThreadUniqueId == threadUniqueId);
                #endif

                if(EATHREAD_LIKELY(--mRecursionCount == 0))
                {
                    // The following assignment is potentially problematic on an SMP  architecture with 
                    // a weak memory model (e.g. multiple processor PowerPC). The problem is that right
                    // before the SignalFSemaphore call below, it's possible that another thread could
                    // acquire the Lock and set mThreadUniqueId to its thread id and thus a thread will
                    // be woken and take the lock for itself. To fix the problem, we would need to 
                    // implement some memory barriers and a spurious wakeup check on the part of the woken thread.
                    mThreadUniqueId = kThreadUniqueIdInvalid;

                    if(EATHREAD_UNLIKELY(--mUseCount > 0))
                        SignalFSemaphore();        // This will execute a read/write barrier.
                    else
                    {
                        EAFutexReadWriteBarrier(); // Question: Do we really need/want to do this? I think so, because we need to make the mThreadUniqueId assigment above visible to other threads.
                    }
                }
                else
                    --mUseCount;
            } 


            inline int Futex::GetLockCount() const
            {
                // No atomic operation or memory barrier required, as this function only
                // has validity if it is being called from the lock-owning thread. However,
                // we don't at this time choose to assert that mThreadUniqueId == GetThreadId().
                return (int)mRecursionCount;
            }

            inline bool Futex::HasLock() const
            {
                ThreadUniqueId threadUniqueId;
                EAThreadGetUniqueId(threadUniqueId);

                return (mThreadUniqueId == threadUniqueId);
            }

        #else // #if EATHREAD_MANUAL_FUTEX_ENABLED

            #if EA_USE_CPP11_CONCURRENCY

                inline Futex::Futex() : mnLockCount(0) {}

                inline Futex::~Futex() { EAT_ASSERT(!GetLockCount()); }

                inline bool Futex::TryLock() 
                { 
                    if (mMutex.try_lock())
                    {
                        EAT_ASSERT(mnLockCount >= 0);
                        EAT_ASSERT(mnLockCount == 0 || mLockingThread == std::this_thread::get_id());
                        ++mnLockCount;
                        mLockingThread = std::this_thread::get_id();
                        return true;
                    }

                    return false;
                }

                inline void Futex::Lock() { mMutex.lock(); mLockingThread = std::this_thread::get_id(); ++mnLockCount; }

                inline int Futex::Lock(const ThreadTime& timeoutAbsolute)
                {
                    if (timeoutAbsolute == kTimeoutNone)
                    {
                        if (!mMutex.try_lock())
                        {
                            return kResultTimeout;
                        }
                    }
                    else
                    {
                        std::chrono::milliseconds timeoutAbsoluteMs(timeoutAbsolute);
                        std::chrono::time_point<std::chrono::system_clock> timeout_time(timeoutAbsoluteMs);
                        if (!mMutex.try_lock_until(timeout_time))
                        {
                            return kResultTimeout;
                        }
                    }

                    EAT_ASSERT(mnLockCount >= 0);
                    EAT_ASSERT(mnLockCount == 0 || mLockingThread == std::this_thread::get_id());
                    mLockingThread = std::this_thread::get_id();
                    return ++mnLockCount; // This is safe to do because we have the lock.
                }

                inline void Futex::Unlock()
                {
                    EAT_ASSERT(HasLock());
                    --mnLockCount;
                    if (mnLockCount == 0)
                        mLockingThread = std::thread::id();
                    mMutex.unlock();
                }

                inline int Futex::GetLockCount() const { return mnLockCount; }

                inline bool Futex::HasLock() const 
                { 
                    if ((mnLockCount > 0) && (std::this_thread::get_id() == mLockingThread))
                        return true;
                    return false;
                }  

            #elif defined(EA_PLATFORM_XENON)

                inline Futex::Futex()
                {
                    RtlInitializeCriticalSection((_RTL_CRITICAL_SECTION*)mCRITICAL_SECTION);
                }

                inline Futex::~Futex()
                {
                    EAT_ASSERT(!GetLockCount());

                    // There is no RtlDeleteCriticalSection on 360; it is #defined to a no-op.
                    // RtlDeleteCriticalSection((_RTL_CRITICAL_SECTION*)mCRITICAL_SECTION);
                }

                inline bool Futex::TryLock()
                {
                    return RtlTryEnterCriticalSection((_RTL_CRITICAL_SECTION*)mCRITICAL_SECTION) != 0;
                }

                inline void Futex::Lock()
                {
                    RtlEnterCriticalSection((_RTL_CRITICAL_SECTION*)mCRITICAL_SECTION);
                }

                inline int Futex::Lock(const ThreadTime& timeoutAbsolute)
                {
                    if(timeoutAbsolute == kTimeoutNone)
                    {
                        Lock();
                        return GetLockCount();
                    }
                    else if(timeoutAbsolute == kTimeoutImmediate)
                    {
                        if(TryLock())
                            return GetLockCount();
                        else
                            return kResultTimeout;
                    }
                    else
                    {
                        while(!TryLock())
                        {
                            if(GetThreadTime() >= timeoutAbsolute)
                                return kResultTimeout;
                            ThreadSleep(1);
                        }
                        return GetLockCount();
                    }
                }

                inline void Futex::Unlock()
                {
                    EAT_ASSERT(HasLock());
                    RtlLeaveCriticalSection((_RTL_CRITICAL_SECTION*)mCRITICAL_SECTION);
                } 

                inline int Futex::GetLockCount() const
                {
                    // Return the RecursionCount member of RTL_CRITICAL_SECTION.

                    // We use raw structure math because otherwise we'd expose the user to system headers, 
                    // which breaks code and bloats builds. We validate our math in eathread_futex.cpp.
                    return *((int*)mCRITICAL_SECTION + 5);
                }

                inline bool Futex::HasLock() const
                {
                    // Check the OwningThread member of RTL_CRITICAL_SECTION.

                    // We use raw structure math because otherwise we'd expose the user to system headers, 
                    // which breaks code and bloats builds. We validate our math in eathread_futex.cpp.
                    #if EAT_ASSERT_ENABLED // Don't read KThread data in release builds.
                        //const uint32_t* const ppKThread = (uint32_t*)mCRITICAL_SECTION.OwningThread;
                        const uint32_t* const ppKThread = (uint32_t*)mCRITICAL_SECTION + 6;
                        return ppKThread && *ppKThread && ((uint32_t*)*ppKThread)[83] == GetCurrentThreadId();
                    #else
                        return (*((uint32_t*)mCRITICAL_SECTION + 5) > 0); // We do what Mutex does, though it is virtually useless.
                    #endif
                }

            #elif defined(EA_COMPILER_MSVC) && defined(EA_PLATFORM_MICROSOFT) // Win32, Win64, etc.

                inline Futex::Futex()
                {
                    InitializeCriticalSection((_RTL_CRITICAL_SECTION*)mCRITICAL_SECTION);
                }

                inline Futex::~Futex()
                {
                    EAT_ASSERT(!GetLockCount());
                    DeleteCriticalSection((_RTL_CRITICAL_SECTION*)mCRITICAL_SECTION);
                }

                inline bool Futex::TryLock()
                {
                    return TryEnterCriticalSection((_RTL_CRITICAL_SECTION*)mCRITICAL_SECTION) != 0;
                }

                inline void Futex::Lock()
                {
                    EnterCriticalSection((_RTL_CRITICAL_SECTION*)mCRITICAL_SECTION);
                }

                inline int Futex::Lock(const ThreadTime& timeoutAbsolute)
                {
                    if(timeoutAbsolute == kTimeoutNone)
                    {
                        Lock();
                        return GetLockCount();
                    }
                    else if(timeoutAbsolute == kTimeoutImmediate)
                    {
                        if(TryLock())
                            return GetLockCount();
                        else
                            return kResultTimeout;
                    }
                    else
                    {
                        while(!TryLock())
                        {
                            if(GetThreadTime() >= timeoutAbsolute)
                                return kResultTimeout;
                            ThreadSleep(1);
                        }
                        return GetLockCount();
                    }
                }

                inline void Futex::Unlock()
                {
                    EAT_ASSERT(HasLock());
                    LeaveCriticalSection((_RTL_CRITICAL_SECTION*)mCRITICAL_SECTION);
                } 

                inline int Futex::GetLockCount() const
                {
                    // Return the RecursionCount member of RTL_CRITICAL_SECTION.

                    // We use raw structure math because otherwise we'd expose the user to system headers, 
                    // which breaks code and bloats builds. We validate our math in eathread_futex.cpp.
                    #if defined(_WIN64)
                        return *((int*)mCRITICAL_SECTION + 3); 
                    #else
                        return *((int*)mCRITICAL_SECTION + 2);
                    #endif
                }

                inline bool Futex::HasLock() const
                {
                    // Check the OwningThread member of RTL_CRITICAL_SECTION.

                    // We use raw structure math because otherwise we'd expose the user to system headers, 
                    // which breaks code and bloats builds. We validate our math in eathread_futex.cpp.
                    #if defined(_WIN64)
                        return (*((uint32_t*)mCRITICAL_SECTION + 4) == (uintptr_t)GetCurrentThreadId());
                    #else
                        return (*((uint32_t*)mCRITICAL_SECTION + 3) == (uintptr_t)GetCurrentThreadId());
                    #endif
                }

            #elif defined(EA_PLATFORM_PS3)

                inline Futex::Futex()
                {
                    sys_lwmutex_attribute_t lwattr;
                    sys_lwmutex_attribute_initialize(lwattr);
                    lwattr.attr_recursive = SYS_SYNC_RECURSIVE;

                    sys_lwmutex_create(&mlwmutex, &lwattr);
                }

                inline Futex::~Futex()
                {
                    EAT_ASSERT(!GetLockCount());
                    sys_lwmutex_destroy(&mlwmutex);;
                }

                inline bool Futex::TryLock()
                {
                    return (sys_lwmutex_trylock(&mlwmutex) == CELL_OK);
                }

                inline void Futex::Lock()
                {
                    sys_lwmutex_lock(&mlwmutex, 0);
                }

                inline int Futex::Lock(const ThreadTime& timeoutAbsolute)
                {
                    if(timeoutAbsolute == kTimeoutNone)
                    {
                        Lock();
                        return GetLockCount();
                    }
                    else if(timeoutAbsolute == kTimeoutImmediate)
                    {
                        if(TryLock())
                            return GetLockCount();
                        else
                            return kResultTimeout;
                    }
                    else
                    {
                        while(!TryLock())
                        {
                            if(GetThreadTime() >= timeoutAbsolute)
                                return kResultTimeout;
                            ThreadSleep(1);
                        }
                        return GetLockCount();
                    }
                }

                inline void Futex::Unlock()
                {
                    EAT_ASSERT(HasLock());
                    sys_lwmutex_unlock(&mlwmutex);
                } 

                inline int Futex::GetLockCount() const
                {
                    return (int)mlwmutex.recursive_count;
                }

                inline bool Futex::HasLock() const
                {
                    sys_ppu_thread_t threadId;
                    sys_ppu_thread_get_id(&threadId);
                    return (mlwmutex.lock_var.info.owner == threadId);
                }

            #elif defined(EAT_FUTEX_USE_MUTEX)

                inline Futex::Futex()
                  { }

                inline Futex::~Futex()
                  { }

                inline bool Futex::TryLock()
                  { return mMutex.Lock(EA::Thread::kTimeoutImmediate) > 0; }

                inline void Futex::Lock()
                  { mMutex.Lock(); }

                inline int Futex::Lock(const ThreadTime& timeoutAbsolute)
                  { return mMutex.Lock(timeoutAbsolute); }

                inline void Futex::Unlock()
                  { mMutex.Unlock(); }

                inline int Futex::GetLockCount() const
                  { return mMutex.GetLockCount(); }

                inline bool Futex::HasLock() const
                  { return mMutex.HasLock(); }

            #endif // _MSC_VER

        #endif // EATHREAD_MANUAL_FUTEX_ENABLED



        inline AutoFutex::AutoFutex(Futex& futex) 
          : mFutex(futex)
        {
            mFutex.Lock();
        }

        inline AutoFutex::~AutoFutex()
        {
            mFutex.Unlock();
        }

    } // namespace Thread

} // namespace EA



#endif // EATHREAD_EATHREAD_FUTEX_H













