/////////////////////////////////////////////////////////////////////////////
// eathread_callstack.cpp
//
// Copyright (c), Electronic Arts Inc. All rights reserved.
/////////////////////////////////////////////////////////////////////////////


#include "EA/Basic/eabase.h"


#if defined(EA_PLATFORM_WIN32)
    #include "pc/eathread_callstack_win32.cpp"
#elif defined(EA_PLATFORM_MICROSOFT) && defined(EA_PROCESSOR_X86_64)
    #include "pc/eathread_callstack_win64.cpp"
#elif defined(EA_PLATFORM_XENON)
    #include "pc/eathread_callstack_xenon.cpp"
#elif defined(EA_PLATFORM_PS3)
    #include "ps3/eathread_callstack_ps3.cpp"
#elif defined(EA_PLATFORM_PS3_SPU)
    #include "ps3/eathread_callstack_ps3_spu.cpp"
#elif defined(EA_PLATFORM_REVOLUTION)
    #include "gc/eathread_callstack_gc.cpp"
#elif defined(EA_PLATFORM_APPLE) // OSX, iPhone, iPhone Simulator
    #include "apple/eathread_callstack_apple.cpp"
    #include "unix/eathread_pthread_stack_info.cpp"
#elif defined(EA_PROCESSOR_ARM) && !defined(EA_PLATFORM_WINDOWS_PHONE)
    #include "arm/eathread_callstack_arm.cpp"
    #include "arm/arm_unwind.cpp"
    #include "unix/eathread_pthread_stack_info.cpp"
#elif (defined(EA_PLATFORM_LINUX) || defined(__CYGWIN__)) && (defined(EA_PROCESSOR_X86) || defined(EA_PROCESSOR_X86_64))
    #include "x86/eathread_callstack_x86.cpp"
    #include "unix/eathread_pthread_stack_info.cpp"
#elif defined(__GNUC__) || defined(EA_COMPILER_CLANG)
    #include "unix/eathread_callstack_glibc.cpp"
    #include "unix/eathread_pthread_stack_info.cpp"
#else
    #include "null/eathread_callstack_null.cpp"
#endif
