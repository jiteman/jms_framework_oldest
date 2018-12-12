///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Electronic Arts. All Rights Reserved.
///////////////////////////////////////////////////////////////////////////////


#ifndef PPMALLOC_INTERNAL_CALLSTACK_H
#define PPMALLOC_INTERNAL_CALLSTACK_H

#include "ea/eathreading/internal/config.h"

///////////////////////////////////////////////////////////////////////////////
// PPM_USABLE_CALLSTACK
//
// WinRT-x86 does not provide usable callstacks so we avoid tracing them on this platform.
#if (defined(EA_PLATFORM_WINDOWS) && !EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP) && defined(EA_PROCESSOR_X86)) || defined(EA_PLATFORM_WINDOWS_PHONE) || defined(EA_PLATFORM_AIRPLAY) 
    #define PPM_USABLE_CALLSTACK 0
#else
    #define PPM_USABLE_CALLSTACK 1
#endif

///////////////////////////////////////////////////////////////////////////////
// PPM_USE_EATHREAD_CALLSTACK
// 
// This symbol is defined to 1 if a sufficiently new version of PPMalloc is 
// available and will instead use its callstack facilities instead of the
// ones provided in this library.
#if EATHREAD_VERSION_N > 11702 && PPM_USABLE_CALLSTACK
    #define PPM_USE_EATHREAD_CALLSTACK 1

    #ifdef PPM_DEBUG_CALLSTACK_AVAILABLE
        #undef PPM_DEBUG_CALLSTACK_AVAILABLE
    #endif
    #define PPM_DEBUG_CALLSTACK_AVAILABLE 1
#else
    #define PPM_USE_EATHREAD_CALLSTACK 0
#endif

#endif

