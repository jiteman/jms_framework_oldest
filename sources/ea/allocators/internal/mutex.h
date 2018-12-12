///////////////////////////////////////////////////////////////////////////////
// mutex.h
//
// Copyright (c) 2007, Electronic Arts. All Rights Reserved.
// By Paul Pedriana
///////////////////////////////////////////////////////////////////////////////


#ifndef PPMALLOC_INTERNAL_MUTEX_H
#define PPMALLOC_INTERNAL_MUTEX_H


EA_DISABLE_VC_WARNING(4574 4836)
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <new>
EA_RESTORE_VC_WARNING()


namespace EA
{
    namespace Allocator
    {
        ///////////////////////////////////////////////////////////////////////
        // AtomicUint
        ///////////////////////////////////////////////////////////////////////

        typedef uint64_t AtomicUint;

        ///////////////////////////////////////////////////////////////////////
        // PPMMutex
        ///////////////////////////////////////////////////////////////////////

        #if PPM_THREAD_SAFETY_SUPPORTED
            #if defined(EA_PLATFORM_MICROSOFT) && EA_PLATFORM_PTR_SIZE == 8
                const size_t kMutexBufferSize = 6;
            #elif defined(EA_PLATFORM_WIN32) || defined(EA_PLATFORM_XENON)
                const size_t kMutexBufferSize = 4;
            #elif defined(EA_PLATFORM_UNIX) || defined(__APPLE__) || defined(EA_PLATFORM_PLAYBOOK)
                const size_t kMutexBufferSize = 6 * ((EA_PLATFORM_PTR_SIZE) / 4);
            #elif defined(EA_PLATFORM_PSP2)
                const size_t kMutexBufferSize = 5;
            #else
                const size_t kMutexBufferSize = 4; // To do: Reduce this appropriate for platforms such as PS3 and Unix.
            #endif

            void* PPMMutexCreate(void* pData);     /// Returns an initialized mutex object, created from a sufficiently large block of memory (pData).
            void  PPMMutexDestroy(void* pMutex);   /// Destroys a mutex object.
            int   PPMMutexLock(void* pMutex);      /// Locks a mutex, returning new lock count. This lock must support recursiveness. Note that you can add recursiveness to a non-recursive lock by hand.
            int   PPMMutexUnlock(void* pMutex);    /// Unlocks a locked mutex, returning new lock count.
            int   PPMMutexGetLockCount(const void* pMutex);

            struct PPMAutoMutex
            {
                void* mpMutex;
                PPMAutoMutex(void* pMutex);
               ~PPMAutoMutex();
            };


            inline
            PPMAutoMutex::PPMAutoMutex(void* pMutex)
              : mpMutex(pMutex)
            {
                PPMMutexLock(mpMutex);
            }
    

            inline
            PPMAutoMutex::~PPMAutoMutex()
            {
                PPMMutexUnlock(mpMutex);
            }

        #endif


    } // namespace Allocator

} // namespace EA


#endif // Header include guard




