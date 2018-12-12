///////////////////////////////////////////////////////////////////////////////
// Config.h
//
// Copyright (c) 2006 Electronic Arts Inc.
// Written and maintained by Paul Pedriana.
///////////////////////////////////////////////////////////////////////////////


#ifndef EATHREAD_INTERNAL_CONFIG_H
#define EATHREAD_INTERNAL_CONFIG_H


#include "EA/Basic/eabase.h"

EA_DISABLE_VC_WARNING(4574)
#include <stddef.h>
EA_RESTORE_VC_WARNING()


///////////////////////////////////////////////////////////////////////////////
// EATHREAD_VERSION
//
// We more or less follow the conventional EA packaging approach to versioning 
// here. A primary distinction here is that minor versions are defined as two
// digit entities (e.g. .03") instead of minimal digit entities ".3"). The logic
// here is that the value is a counter and not a floating point fraction.
// Note that the major version doesn't have leading zeros.
//
// Example version strings:
//      "0.91.00"   // Major version 0, minor version 91, patch version 0. 
//      "1.00.00"   // Major version 1, minor and patch version 0.
//      "3.10.02"   // Major version 3, minor version 10, patch version 02.
//     "12.03.01"   // Major version 12, minor version 03, patch version 
//
// Example usage:
//     printf("EATHREAD_VERSION version: %s", EATHREAD_VERSION);
//     printf("EATHREAD_VERSION version: %d.%d.%d", EATHREAD_VERSION_N / 10000 % 100, EATHREAD_VERSION_N / 100 % 100, EATHREAD_VERSION_N % 100);
//
#ifndef EATHREAD_VERSION
    #define EATHREAD_VERSION   "1.19.01"
    #define EATHREAD_VERSION_N  11901

    // Older style version info
    #define EATHREAD_VERSION_MAJOR (EATHREAD_VERSION_N / 100 / 100 % 100)
    #define EATHREAD_VERSION_MINOR (EATHREAD_VERSION_N       / 100 % 100)
    #define EATHREAD_VERSION_PATCH (EATHREAD_VERSION_N             % 100)
#endif


///////////////////////////////////////////////////////////////////////////////
// EA_WINAPI_FAMILY_PARTITION / EA_WINAPI_PARTITION
// 
// Backwards compatibility for usign older versions of EABase which define EA_WINAPI_FAMILY_PARTITION.
// Provides the EA_WINAPI_FAMILY_PARTITION macro for testing API support under
// Microsoft platforms, plus associated API identifiers for this macro.
//
// Current API identifiers:
//     EA_WINAPI_PARTITION_NONE
//     EA_WINAPI_PARTITION_DESKTOP
//     EA_WINAPI_PARTITION_XENON
//
// Example usage:
//     #if defined(EA_PLATFORM_MICROSOFT)
//         #if EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
//             GetEnvironmentVariableA("PATH", env, sizeof(env));
//         #else
//             // not supported.
//         #endif
//     #endif
//
#if !defined(EA_WINAPI_FAMILY_PARTITION)
    #define EA_WINAPI_FAMILY_PARTITION(partition) (partition)
#endif

#if !defined(EA_WINAPI_PARTITION_NONE) && !defined(EA_WINAPI_PARTITION_DESKTOP) && !defined(EA_WINAPI_PARTITION_XENON)
    #if defined(EA_PLATFORM_MICROSOFT)
        #if defined(EA_PLATFORM_WINDOWS)
            #define EA_WINAPI_PARTITION_DESKTOP 1
        #elif defined(EA_PLATFORM_XENON)
            #define EA_WINAPI_PARTITION_XENON 1
        #else
            // Nothing defined. Future values (e.g. Windows Phone) would go here.
        #endif
    #else
        #define EA_WINAPI_PARTITION_NONE 1
    #endif
#endif

#if !defined(EA_WINAPI_PARTITION_NONE)
    #define EA_WINAPI_PARTITION_NONE 0
#endif

#if !defined(EA_WINAPI_PARTITION_DESKTOP)
    #define EA_WINAPI_PARTITION_DESKTOP 0
#endif

#if !defined(EA_WINAPI_PARTITION_XENON)
    #define EA_WINAPI_PARTITION_XENON 0
#endif



///////////////////////////////////////////////////////////////////////////////
// _GNU_SOURCE
//
// Defined or not defined.
// If this is defined then GlibC extension functionality is enabled during 
// calls to glibc header files.
//
#if !defined(_GNU_SOURCE)
    #define _GNU_SOURCE
#endif


///////////////////////////////////////////////////////////////////////////////
// EATHREAD_TLS_COUNT
//
// Defined as compile-time constant integer > 0.
//
#if !defined(EATHREAD_TLS_COUNT)
    #define EATHREAD_TLS_COUNT 16
#endif


///////////////////////////////////////////////////////////////////////////////
// EA_PLATFORM_MICROSOFT
//
// Defined as 1 or undefined.
// Implements support for the definition of EA_PLATFORM_MICROSOFT for the case
// of using EABase versions prior to the addition of its EA_PLATFORM_MICROSOFT support.
//
#if (EABASE_VERSION_N < 20022) && !defined(EA_PLATFORM_MICROSOFT)
    #if defined(EA_PLATFORM_WINDOWS) || defined(EA_PLATFORM_XENON)
        #define EA_PLATFORM_MICROSOFT 1
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EA_THREADS_AVAILABLE
//
// Defined as 0 or 1
// Defines if threading is supported on the given platform.
// If 0 then the EAThread implementation is not capable of creating threads,
// but other facilities (e.g. mutex) work in a non-thread-aware way.
//
#ifndef EA_THREADS_AVAILABLE
    #if defined(EA_PLATFORM_AIRPLAY)            // Even though Airplay has a pthread interface, it works only for iPhone and even then still doesn't support atomics.
        #define EA_THREADS_AVAILABLE 0          // So by default we flag it as no-threads here, despite EA_POSIX_THREADS_AVAILABLE being enabled for it elsewhere.
    #elif defined(EA_PLATFORM_PLAYSTATION2_IOP) // PS2 IOP processor.
        #define EA_THREADS_AVAILABLE 0
  //#elif defined(EA_PLATFORM_PS3_SPU)          // PS3 SPU processor. We can't currently enable this code, as we have SPU atomic code that would be blocked if this code was enabled.
  //     #define EA_THREADS_AVAILABLE 0
    #else
        #define EA_THREADS_AVAILABLE 1
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EA_USE_CPP11_CONCURRENCY
//
// Defined as 0 or 1
//
#ifndef EA_USE_CPP11_CONCURRENCY
    #if (defined(EA_PLATFORM_WINDOWS) && !EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)) || defined(EA_PLATFORM_WINDOWS_PHONE)
        #define EA_USE_CPP11_CONCURRENCY 1
    #else
        #define EA_USE_CPP11_CONCURRENCY 0
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EA_POSIX_THREADS_AVAILABLE
//
// Defined as 0 or 1
//
#ifdef EA_POSIX_THREADS_AVAILABLE           // This code here is for backwards compatibility.
    #undef  EA_POSIX_THREADS_AVAILABLE      // Older versions of EABase were not defining this to 1,
    #define EA_POSIX_THREADS_AVAILABLE 1    // so we detect that it was defined and define to 1 here.
#endif

#ifndef EA_POSIX_THREADS_AVAILABLE
    #if defined(__unix__) || defined(__linux__) || defined(__APPLE__) || defined(EA_PLATFORM_AIRPLAY) // Airplay supposedly supports pthread on iPhone.
        #define EA_POSIX_THREADS_AVAILABLE 1
    #else
        #define EA_POSIX_THREADS_AVAILABLE 0
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EA_OPENKODE_THREADS_AVAILABLE
//
// Defined as 0 or 1
//
#ifndef EA_OPENKODE_THREADS_AVAILABLE
    #if defined(EA_PLATFORM_AIRPLAY)    // Actually, Airplay's support of OpenKODE threads is incomplete.
        #define EA_OPENKODE_THREADS_AVAILABLE 1
    #else
        #define EA_OPENKODE_THREADS_AVAILABLE 0
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EA_ANALYSIS_ASSUME
//
// If using an earlier version of EABase then we need to define EA_ANALYSIS_ASSUME ourselves.
//
#if !defined(EA_ANALYSIS_ASSUME)
    #if defined(_MSC_VER) && (_MSC_VER >= 1300) && !defined(EA_PLATFORM_AIRPLAY)
        #define EA_ANALYSIS_ASSUME(x) __analysis_assume(x)
    #else
        #define EA_ANALYSIS_ASSUME(x)
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EAT_ASSERT_ENABLED
//
// Defined as 0 or 1, default is 1 if EA_DEBUG or _DEBUG is defined.
// If defined as 1, then assertion failures are reported via EA::Thread::AssertionFailure(). 
// 
#ifndef EAT_ASSERT_ENABLED
    #if defined(EA_DEBUG) || defined(_DEBUG)
        #define EAT_ASSERT_ENABLED 1
    #else
        #define EAT_ASSERT_ENABLED 0
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EA_HAVE_nanosleep_DECL
//
// Implemented in recent versions of EABase.
//
#if !defined(EA_HAVE_nanosleep_DECL) && !defined(EA_NO_HAVE_nanosleep_DECL)
    #if (defined(EA_PLATFORM_UNIX) && !defined(EA_PLATFORM_SONY)) || defined(EA_PLATFORM_PLAYBOOK) || defined(EA_PLATFORM_IPHONE) || defined(EA_PLATFORM_OSX)
        #define EA_HAVE_nanosleep_DECL 1
    #else
        #define EA_NO_HAVE_nanosleep_DECL 1
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EA_HAVE_pthread_getattr_np_DECL
//
// Possibly implemented in recent versions of EABase.
//
#if !defined(EA_HAVE_pthread_getattr_np_DECL) && !defined(EA_NO_HAVE_pthread_getattr_np_DECL)
    #if defined(EA_PLATFORM_LINUX)
        #define EA_HAVE_pthread_getattr_np_DECL 1
    #else
        #define EA_NO_HAVE_pthread_getattr_np_DECL 1
    #endif
#endif


// ------------------------------------------------------------------------
// EA_DISABLE_VC_WARNING / EA_RESTORE_VC_WARNING
// 
// Disable and re-enable warning(s) within code.
// This is simply a wrapper for VC++ #pragma warning(disable: nnnn) for the
// purpose of making code easier to read due to avoiding nested compiler ifdefs
// directly in code.
//
// Example usage:
//     EA_DISABLE_VC_WARNING(4127 3244)
//     <code>
//     EA_RESTORE_VC_WARNING()
//
#ifndef EA_DISABLE_VC_WARNING
    #if defined(_MSC_VER)
        #define EA_DISABLE_VC_WARNING(w)  \
            __pragma(warning(push))       \
            __pragma(warning(disable:w))
    #else
        #define EA_DISABLE_VC_WARNING(w)
    #endif
#endif

#ifndef EA_RESTORE_VC_WARNING
    #if defined(_MSC_VER)
        #define EA_RESTORE_VC_WARNING()   \
            __pragma(warning(pop))
    #else
        #define EA_RESTORE_VC_WARNING()
    #endif
#endif



#if EAT_ASSERT_ENABLED
    #define EAT_STRINGIFY_HELPER(x) #x
    #define EAT_STRINGIFY(x) EAT_STRINGIFY_HELPER(x)
    #define EAT_ASSERT(expression) \
        EA_DISABLE_VC_WARNING(4127) \
        do { \
            EA_ANALYSIS_ASSUME(expression); \
            if (!(expression) ) \
                EA::Thread::AssertionFailure(__FILE__ "(" EAT_STRINGIFY(__LINE__) "): " #expression); \
        } while(0) \
        EA_RESTORE_VC_WARNING()
#else
    #define EAT_ASSERT(expression)
#endif

#if EAT_ASSERT_ENABLED
    #define EAT_ASSERT_MSG(expression, msg) \
        EA_DISABLE_VC_WARNING(4127) \
        do { \
            EA_ANALYSIS_ASSUME(expression); \
            if (!(expression) ) \
                EA::Thread::AssertionFailure(msg); \
        } while(0) \
        EA_RESTORE_VC_WARNING()
#else
    #define EAT_ASSERT_MSG(expression, msg)
#endif

#if EAT_ASSERT_ENABLED
    #define EAT_ASSERT_FORMATTED(expression, pFormat, ...) \
        EA_DISABLE_VC_WARNING(4127) \
        do { \
            EA_ANALYSIS_ASSUME(expression); \
            if (!(expression) ) \
                EA::Thread::AssertionFailureV(pFormat, __VA_ARGS__); \
        } while(0) \
        EA_RESTORE_VC_WARNING()
#else
    #define EAT_ASSERT_FORMATTED(expression, pFormat, ...)
#endif

#if EAT_ASSERT_ENABLED
    #define EAT_FAIL_MSG(msg) (EA::Thread::AssertionFailure(msg))
#else
    #define EAT_FAIL_MSG(msg)
#endif

#define EAT_TOKEN_PASTE(a,b) a ## b
#define EAT_CONCATENATE_HELPER(a,b) EAT_TOKEN_PASTE(a,b)
#define EAT_COMPILETIME_ASSERT(expr) typedef char EAT_CONCATENATE_HELPER(compileTimeAssert,__LINE__) [((expr) != 0) ? 1 : -1]

///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// EAT_CT_ASSERT   
//
// Compile-time assertion for this module.
// C-like declaration:
//    void EAT_CT_ASSERT(bool bExpression);
//
#if !defined(EAT_CT_ASSERT) && (defined(EA_DEBUG) || defined(_DEBUG))
    #ifdef EA_COMPILER_GNUC
        #define EAT_CT_ASSERT(expression) extern int dummy__[bool(expression) ? 1 : -1] __attribute__ ((unused));
    #else
        #define EAT_CT_ASSERT(expression) extern int dummy__[bool(expression) ? 1 : -1];
    #endif
#else
    #define EAT_CT_ASSERT(expression)
#endif


///////////////////////////////////////////////////////////////////////////////
// EATHREAD_TLSALLOC_DTOR_ENABLED
//
// Defined as 0 or 1. Default is 1.
// Defines if the TLSAlloc class destructor frees the TLS thread handle.
// This won't make a difference unless you were using EAThread in a DLL and 
// you were repeatedly loading and unloading DLLs.
// See eathread_pc.cpp for usage of this and more info about the situation.
//
#ifndef EATHREAD_TLSALLOC_DTOR_ENABLED
    #define EATHREAD_TLSALLOC_DTOR_ENABLED 1
#endif
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// EATHREAD_LIKELY / EATHREAD_UNLIKELY
//
// Defined as a macro which gives a hint to the compiler for branch
// prediction. GCC gives you the ability to manually give a hint to 
// the compiler about the result of a comparison, though it's often
// best to compile shipping code with profiling feedback under both
// GCC (-fprofile-arcs) and VC++ (/LTCG:PGO, etc.). However, there 
// are times when you feel very sure that a boolean expression will
// usually evaluate to either true or false and can help the compiler
// by using an explicity directive...
//
// Example usage:
//     if(EATHREAD_LIKELY(a == 0)) // Tell the compiler that a will usually equal 0.
//         { ... }
//
// Example usage:
//     if(EATHREAD_UNLIKELY(a == 0)) // Tell the compiler that a will usually not equal 0.
//         { ... }
//
#ifndef EATHREAD_LIKELY
    #if defined(__GNUC__) && (__GNUC__ >= 3)
          #define EATHREAD_LIKELY(x)   __builtin_expect(!!(x), true)
          #define EATHREAD_UNLIKELY(x) __builtin_expect(!!(x), false) 
     #else
          #define EATHREAD_LIKELY(x)   (x)
          #define EATHREAD_UNLIKELY(x) (x)
     #endif
#endif
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// EATHREAD_NAME_SIZE
//
// Specifies the max size to support for naming threads.
// This value can be changed as desired.
//
#ifndef EATHREAD_NAME_SIZE
    #if defined(EA_PLATFORM_WINDOWS) || defined(EA_PLATFORM_UNIX)
        #define EATHREAD_NAME_SIZE 64
    #else
        #define EATHREAD_NAME_SIZE 32
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EA_XBDM_ENABLED
//
// Defined as 0 or 1, with 1 being the default for debug builds.
// This controls whether xbdm library usage is enabled on XBox 360. This library
// allows for runtime debug functionality. But shipping applications are not
// allowed to use xbdm. 
//
#if !defined(EA_XBDM_ENABLED)
    #if defined(EA_DEBUG)
        #define EA_XBDM_ENABLED 1
    #else
        #define EA_XBDM_ENABLED 0
    #endif
#endif



///////////////////////////////////////////////////////////////////////////////
// EATHREAD_DLL
//
// Defined as 0 or 1. The default is dependent on the definition of EA_DLL.
// If EA_DLL is defined, then EATHREAD_DLL is 1, else EATHREAD_DLL is 0.
// EA_DLL is a define that controls DLL builds within the EAConfig build system. 
// EATHREAD_DLL controls whether EATHREAD_VERSION is built and used as a DLL. 
// Normally you wouldn't do such a thing, but there are use cases for such
// a thing, particularly in the case of embedding C++ into C# applications.
//
#ifndef EATHREAD_DLL
    #if defined(EA_DLL)
        #define EATHREAD_DLL 1
    #else
        #define EATHREAD_DLL 0
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EATHREADLIB_API
//
// This is used to label functions as DLL exports under Microsoft platforms.
// If EA_DLL is defined, then the user is building EAThread as a DLL and EAThread's
// non-templated functions will be exported. EAThread template functions are not
// labelled as EATHREADLIB_API (and are thus not exported in a DLL build). This is 
// because it's not possible (or at least unsafe) to implement inline templated 
// functions in a DLL.
//
// Example usage of EATHREADLIB_API:
//    EATHREADLIB_API int someVariable = 10;         // Export someVariable in a DLL build.
//
//    struct EATHREADLIB_API SomeClass{              // Export SomeClass and its member functions in a DLL build.
//        EATHREADLIB_LOCAL void PrivateMethod();    // Not exported.
//    };
//
//    EATHREADLIB_API void SomeFunction();           // Export SomeFunction in a DLL build.
//
// For GCC, see http://gcc.gnu.org/wiki/Visibility
//
#ifndef EATHREADLIB_API // If the build file hasn't already defined this to be dllexport...
    #if EATHREAD_DLL 
        #if defined(_MSC_VER)
            #define EATHREADLIB_API      __declspec(dllimport)
            #define EATHREADLIB_LOCAL
        #elif defined(__CYGWIN__)
            #define EATHREADLIB_API      __attribute__((dllimport))
            #define EATHREADLIB_LOCAL
        #elif (defined(__GNUC__) && (__GNUC__ >= 4))
            #define EATHREADLIB_API      __attribute__ ((visibility("default")))
            #define EATHREADLIB_LOCAL    __attribute__ ((visibility("hidden")))
        #else
            #define EATHREADLIB_API
            #define EATHREADLIB_LOCAL
        #endif
    #else
        #define EATHREADLIB_API
        #define EATHREADLIB_LOCAL
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EATHREAD_ALLOC_PREFIX
//
// Defined as a string literal. Defaults to this package's name.
// Can be overridden by the user by predefining it or by editing this file.
// This define is used as the default name used by this package for naming
// memory allocations and memory allocators.
//
// All allocations names follow the same naming pattern:
//     <package>/<module>[/<specific usage>]
// 
// Example usage:
//     void* p = pCoreAllocator->Alloc(37, EATHREAD_ALLOC_PREFIX, 0);
//
// Example usage:
//     gMessageServer.GetMessageQueue().get_allocator().set_name(EATHREAD_ALLOC_PREFIX "MessageSystem/Queue");
//
#ifndef EATHREAD_ALLOC_PREFIX
    #define EATHREAD_ALLOC_PREFIX "EAThread/"
#endif


///////////////////////////////////////////////////////////////////////////////
// EA_UNUSED
// 
// Makes compiler warnings about unused variables go away.
//
// Example usage:
//    void Function(int x)
//    {
//        int y;
//        EA_UNUSED(x);
//        EA_UNUSED(y);
//    }
//
#ifndef EA_UNUSED // If not already defined by EABase (as it is in recent versions)...
    // The EDG solution below is pretty weak and needs to be augmented or replaced.
    // It can't handle the C language, is limited to places where template declarations
    // can be used, and requires the type x to be usable as a functions reference argument. 
    #if defined(__cplusplus) && defined(__EDG__) && !defined(__PPU__) && !defined(__SPU__) // All EDG variants except the SN PS3 variant which allows usage of (void)x;
        template <typename T>
        inline void EABaseUnused(T const volatile & x) { (void)x; }
        #define EA_UNUSED(x) EABaseUnused(x)
    #else
        #define EA_UNUSED(x) (void)x
    #endif
#endif



///////////////////////////////////////////////////////////////////////////////
// EATHREAD_USE_STANDARD_NEW
//
// Defines whether we use the basic standard operator new or the named
// extended version of operator new, as per the EASTL package.
//
#ifndef EATHREAD_USE_STANDARD_NEW
    #if EATHREAD_DLL  // A DLL must provide its own implementation of new, so we just use built-in new.
        #define EATHREAD_USE_STANDARD_NEW 1
    #else
        #define EATHREAD_USE_STANDARD_NEW 0
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EATHREAD_NEW
//
// This is merely a wrapper for operator new which can be overridden and 
// which has debug/release forms.
//
// Example usage:
//    SomeClass* pObject = EATHREAD_NEW("SomeClass") SomeClass(1, 2, 3);
//
#ifndef EATHREAD_NEW
    #if EATHREAD_USE_STANDARD_NEW
            #define EATHREAD_NEW(name)                            new
            #define EATHREAD_NEW_ALIGNED(alignment, offset, name) new
            #define EATHREAD_DELETE                               delete
    #else
        #if defined(EA_DEBUG)
            #define EATHREAD_NEW(name)                            new(name, 0, 0, __FILE__, __LINE__)
            #define EATHREAD_NEW_ALIGNED(alignment, offset, name) new(alignment, offset, name, 0, 0, __FILE__, __LINE__)
            #define EATHREAD_DELETE                               delete
        #else
            #define EATHREAD_NEW(name)                            new(name, 0, 0, 0, 0)
            #define EATHREAD_NEW_ALIGNED(alignment, offset, name) new(alignment, offset, name, 0, 0, 0, 0)
            #define EATHREAD_DELETE                               delete
        #endif
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EATHREAD_HAS_EMULATED_AND_NATIVE_ATOMICS
//
// This symbol is defined if a platform has both native and emulated atomics.
// Currently the only platform that requires this is iOS as earlier versions 
// of the operating system (ie: iOS 3) do not provide OS support for 64-bit
// atomics while later versions (ie: iOS 4/5) do.
#ifndef EATHREAD_HAS_EMULATED_AND_NATIVE_ATOMICS
    #if defined(__APPLE__)
        #define EATHREAD_HAS_EMULATED_AND_NATIVE_ATOMICS 1 
    #else
        #define EATHREAD_HAS_EMULATED_AND_NATIVE_ATOMICS 0
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EATHREAD_GLIBC_BACKTRACE_AVAILABLE
//
// You generally need to be using GCC, GLIBC, and Linux for backtrace to be available.
// And even then it's available only some of the time.
//
#if !defined(EATHREAD_GLIBC_BACKTRACE_AVAILABLE)
    #if (defined(__clang__) || defined(__GNUC__)) && (defined(EA_PLATFORM_LINUX) || defined(__APPLE__) || defined(EA_PLATFORM_PALM)) && !defined(__CYGWIN__) && !defined(EA_PLATFORM_ANDROID)
        #define EATHREAD_GLIBC_BACKTRACE_AVAILABLE 1
    #else
        #define EATHREAD_GLIBC_BACKTRACE_AVAILABLE 0
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EATHREAD_GETCALLSTACK_SUPPORTED
//
// Defined as 0 or 1.
// Identifies whether runtime callstack unwinding (i.e. GetCallstack()) is 
// supported for the given platform. In some cases it may be that unwinding 
// support code is present but it hasn't been tested for reliability and may
// have bugs preventing it from working properly. In some cases (e.g. x86) 
// it may be that optimized builds make it difficult to read the callstack 
// reliably, despite that we flag the platform as supported.
//
#if !defined(EATHREAD_GETCALLSTACK_SUPPORTED)
    #if EATHREAD_GLIBC_BACKTRACE_AVAILABLE               // Typically this means Linux on x86.
        #define EATHREAD_GETCALLSTACK_SUPPORTED 1
    #elif defined(EA_PLATFORM_IPHONE)
        #define EATHREAD_GETCALLSTACK_SUPPORTED 0       // Support for these ARM targets is currently in progress.
    #elif defined(EA_PLATFORM_ANDROID)
        #define EATHREAD_GETCALLSTACK_SUPPORTED 1
    #elif defined(EA_PLATFORM_PALM)
        #define EATHREAD_GETCALLSTACK_SUPPORTED 0
    #elif defined(EA_PLATFORM_VITA)
        #define EATHREAD_GETCALLSTACK_SUPPORTED 0
    #elif defined(EA_PLATFORM_AIRPLAY)
        #define EATHREAD_GETCALLSTACK_SUPPORTED 0
    #elif defined(EA_PLATFORM_CTR)
        #define EATHREAD_GETCALLSTACK_SUPPORTED 0
    #elif defined(EA_PLATFORM_PLAYBOOK)
        #define EATHREAD_GETCALLSTACK_SUPPORTED 0
    #elif defined(EA_PLATFORM_IPHONE_SIMULATOR)             // This is an x64 device but support hasn't been verified.
        #define EATHREAD_GETCALLSTACK_SUPPORTED 0
	#elif defined(EA_PLATFORM_WINDOWS_PHONE) && defined(EA_PROCESSOR_ARM)		
		#define EATHREAD_GETCALLSTACK_SUPPORTED 0
    #elif defined(EA_PLATFORM_MICROSOFT)
        #define EATHREAD_GETCALLSTACK_SUPPORTED 1
    #elif defined(EA_PLATFORM_LINUX)
        #define EATHREAD_GETCALLSTACK_SUPPORTED 1
    #elif defined(EA_PLATFORM_OSX)
        #define EATHREAD_GETCALLSTACK_SUPPORTED 1
    #elif defined(EA_PLATFORM_REVOLUTION)
        #define EATHREAD_GETCALLSTACK_SUPPORTED 1
    #elif defined(EA_PLATFORM_PS3)
        #define EATHREAD_GETCALLSTACK_SUPPORTED 1
    #elif defined(EA_PLATFORM_CYGWIN)                       // Support hasn't been verified.
        #define EATHREAD_GETCALLSTACK_SUPPORTED 0
    #elif defined(EA_PLATFORM_MINGW)                        // Support hasn't been verified.
        #define EATHREAD_GETCALLSTACK_SUPPORTED 0
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EATHREAD_DEBUG_DETAIL_ENABLED
//
// Defined as 0 or 1. 
// If true then detailed debug info is displayed. Can be enabled in opt builds.
//
#ifndef EATHREAD_DEBUG_DETAIL_ENABLED
    #define EATHREAD_DEBUG_DETAIL_ENABLED 0
#endif


///////////////////////////////////////////////////////////////////////////////
// EA_PLATFORM_CONSOLE_BSD
//
// Defined or not, the same as EA_PLATFORM_XXX defines.
// Identifies BSD targeted towards console platforms.
//
#if !defined(EA_PLATFORM_CONSOLE_BSD)
    #if defined(EA_PLATFORM_CONSOLE) && defined(__FreeBSD__)
        #define EA_PLATFORM_CONSOLE_BSD 1
    #endif
#endif







#endif // Header include guard


