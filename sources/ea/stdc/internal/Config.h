///////////////////////////////////////////////////////////////////////////////
// Config.h
//
// Copyright (c) 2006 Electronic Arts Inc.
// Written and maintained by Paul Pedriana.
///////////////////////////////////////////////////////////////////////////////


#ifndef EASTDC_INTERNAL_CONFIG_H
#define EASTDC_INTERNAL_CONFIG_H


#include "EA/Basic/eabase.h"
#include <stddef.h>


///////////////////////////////////////////////////////////////////////////////
// EASTDC_VERSION
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
//     printf("EASTDC version: %s", EASTDC_VERSION);
//     printf("EASTDC version: %d.%d.%d", EASTDC_VERSION_N / 10000 % 100, EASTDC_VERSION_N / 100 % 100, EASTDC_VERSION_N % 100);
//
///////////////////////////////////////////////////////////////////////////////

#ifndef EASTDC_VERSION
    #define EASTDC_VERSION   "1.08.05"
    #define EASTDC_VERSION_N  10805
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
// EASTDC_DLL
//
// Defined as 0 or 1. The default is dependent on the definition of EA_DLL.
// If EA_DLL is defined, then EASTDC_DLL is 1, else EASTDC_DLL is 0.
// EA_DLL is a define that controls DLL builds within the EAConfig build system. 
// EASTDC_DLL controls whether EASTDC is built and used as a DLL. 
// Normally you wouldn't do such a thing, but there are use cases for such
// a thing, particularly in the case of embedding C++ into C# applications.
//
#ifndef EASTDC_DLL
    #if defined(EA_DLL)
        #define EASTDC_DLL 1
    #else
        #define EASTDC_DLL 0
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EASTDC_API
//
// This is used to label functions as DLL exports under Microsoft platforms.
// If EA_DLL is defined, then the user is building EASTDC as a DLL and EASTDC's
// non-templated functions will be exported. EASTDC template functions are not
// labelled as EASTDC_API (and are thus not exported in a DLL build). This is 
// because it's not possible (or at least unsafe) to implement inline templated 
// functions in a DLL.
//
// Example usage of EASTDC_API:
//    EASTDC_API int someVariable = 10;         // Export someVariable in a DLL build.
//
//    struct EASTDC_API SomeClass{              // Export SomeClass and its member functions in a DLL build.
//        EASTDC_LOCAL void PrivateMethod();    // Not exported.
//    };
//
//    EASTDC_API void SomeFunction();           // Export SomeFunction in a DLL build.
//
// For GCC, see http://gcc.gnu.org/wiki/Visibility
//
#ifndef EASTDC_API // If the build file hasn't already defined this to be dllexport...
    #if EASTDC_DLL 
        #if defined(_MSC_VER)
            #define EASTDC_API      __declspec(dllimport)
            #define EASTDC_LOCAL
        #elif defined(__CYGWIN__)
            #define EASTDC_API      __attribute__((dllimport))
            #define EASTDC_LOCAL
        #elif (defined(__GNUC__) && (__GNUC__ >= 4))
            #define EASTDC_API      __attribute__ ((visibility("default")))
            #define EASTDC_LOCAL    __attribute__ ((visibility("hidden")))
        #else
            #define EASTDC_API
            #define EASTDC_LOCAL
        #endif
    #else
        #define EASTDC_API
        #define EASTDC_LOCAL
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EASTDC_MEMORY_INLINE_ENABLED
//
// Defined as 0 or 1, with 1 being the default.
// This controls whether EAMemory functions are inlined or not in builds.
// The advantage of them being inlined is that they can pass straight through
// to inlinable code. The disadvantage is increased code size and lack of 
// diagnostic functionality that's available when not inlined.
//
#if !defined(EASTDC_MEMORY_INLINE_ENABLED)
    #if defined(EA_PLATFORM_XENON)      // Disabled for XBox 360 because the compiler doesn't optimize inlined memcpy usage and has a very heavy <xtl.h> header file which slows down compilation.
        #define EASTDC_MEMORY_INLINE_ENABLED 0
    #else
        #define EASTDC_MEMORY_INLINE_ENABLED 1
    #endif
#endif



///////////////////////////////////////////////////////////////////////////////
// EASTDC_VSNPRINTF8_ENABLED
//
// *** This option is deprecated. ***
// Defined as 0 or 1. Default is 0.
// If enabled then Vsnprintf8 and Vsnprintf16 are enabled. These are functions
// which simply call Vsnprintf(char8_t..) and Vsnprintf(char16_t). Vsnprintf8
// is the older name for this function and is deprecated. However, some existing
// code uses Vsnprintf8 (most notably the EASTL package).
//
#ifndef EASTDC_VSNPRINTF8_ENABLED
    #define EASTDC_VSNPRINTF8_ENABLED 0
#endif


///////////////////////////////////////////////////////////////////////////////
// EASTDC_MEMCPY16_ENABLED
//
// Defined as 0 or 1. Default is 1.
// The Memcpy(char16_t*, const char16_t*, size_t) function and Memmove 
// equivalent have been deprecated. For the time being we have an option 
// to control their existence. 
//
#ifndef EASTDC_MEMCPY16_ENABLED
    #define EASTDC_MEMCPY16_ENABLED 0
#endif


///////////////////////////////////////////////////////////////////////////////
// EASTDC_MEMCPY16_ENABLED
//
// Defined as 0 or 1. Default is 1.
//
#ifndef EASTDC_MEMCHR16_ENABLED
    #define EASTDC_MEMCHR16_ENABLED 1
#endif


///////////////////////////////////////////////////////////////////////////////
// EASTDC_CHAR32_SUPPORT_ENABLED
//
// Defined as 0 or 1. Default is 1 except on platforms where it would never be used.
// Defines whether functions that use char32_t are supported. If not then there
// are no available declarations or definitions of char32_t functions (e.g. Sprintf(char32_t*,...)
// Note that some char32_t functionality might nevertheless be enabled even if 
// EASTDC_CHAR32_SUPPORT_ENABLED is 0. In these cases it's expected that the 
// C/C++ linker will link away such functions.
//
#ifndef EASTDC_CHAR32_SUPPORT_ENABLED
    #define EASTDC_CHAR32_SUPPORT_ENABLED 1
#endif


///////////////////////////////////////////////////////////////////////////////
// EASprintf configuration parameters
//
#ifndef EASPRINTF_FIELD_MAX                 // Defines the maximum supported length of a field, except string fields, which have no size limit. 
    #if defined(EA_PLATFORM_UNIX)           // This value relates to the size of buffers used in the stack space.
        #define EASPRINTF_FIELD_MAX 4096
    #elif defined(EA_PLATFORM_DESKTOP)
        #define EASPRINTF_FIELD_MAX 3600    // Much higher than this and it could risk problems with stack space.
    #else
        #define EASPRINTF_FIELD_MAX 1024    // The reason it is 1024 and not the 4095 that the C99 Standard specifies is that 4095 can blow up the stack on some platforms (e.g. PS3).
    #endif
#endif

#ifndef EASPRINTF_MS_STYLE_S_FORMAT         // Microsoft uses a non-standard interpretation of the %s field type. 
    #define EASPRINTF_MS_STYLE_S_FORMAT 1   // For wsprintf MSVC interprets %s as a wchar_t string and %S as a char string.
#endif                                      // You can make your code portable by using %hs and %ls to force the type.

#ifndef EASPRINTF_SNPRINTF_C99_RETURN       // The C99 standard specifies that snprintf returns the required strlen 
    #define EASPRINTF_SNPRINTF_C99_RETURN 1 // of the output, which may or may not be less than the supplied buffer size. 
#endif                                      // Some snprintf implementations instead return -1 if the supplied buffer is too small.


/////////////////////////////////////////////////////////////////////////////
// EASTDC_THREADING_SUPPORTED
// 
// Defined as 0 or 1. Default is 1 (enabled).
// Specifies if code that uses multithreading is available. If enabled then
// this package is dependent on the EAThread package.
//
#ifndef EASTDC_THREADING_SUPPORTED
    #if defined(EA_PLATFORM_PS3_SPU) || defined(EA_PLATFORM_AIRPLAY) // Defines platforms that can't create threads.
        #define EASTDC_THREADING_SUPPORTED 0
    #else
        #define EASTDC_THREADING_SUPPORTED 1
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EASTDC_VALGRIND_ENABLED
//
// Defined as 0 or 1. It's value depends on the compile environment.
// Specifies whether the code is being built with Valgrind instrumentation.
//
#if !defined(EASTDC_VALGRIND_ENABLED)
    #define EASTDC_VALGRIND_ENABLED 0
#endif


///////////////////////////////////////////////////////////////////////////////
// operator new
//
// A user-provided operator new of the following types is required.
// Note that this is the same operator new used by EASTL.
//
// Example usage:
//    SomeClass* pObject = new("SomeClass") SomeClass(1, 2, 3);
//    SomeClass* pObject = new("SomeClass", 0, 0, __FILE__, __LINE__) SomeClass(1, 2, 3);
//    SomeClass* pObject = new("SomeClass", EA::Allocator::kFlagNormal, 1 << EA::Allocator::GeneralAllocatorDebug::kDebugDataIdCallStack) SomeClass(1, 2, 3);
//
/// Example usage:
///    SomeClass* pArray = new("SomeClass", EA::Allocator::kFlagPermanent, __FILE__, __LINE__) SomeClass(1, 2, 3)[4];
///    SomeClass* pArray = new("SomeClass", EA::Allocator::kFlagNormal, 1 << EA::Allocator::GeneralAllocatorDebug::kDebugDataIdCallStack, __FILE__, __LINE__) SomeClass(1, 2, 3)[4];
//
void* operator new     (size_t size, const char* name, int flags, unsigned debugFlags, const char* file, int line);
void* operator new[]   (size_t size, const char* name, int flags, unsigned debugFlags, const char* file, int line);
void* operator new     (size_t size, size_t alignment, size_t alignmentOffset, const char* name, int flags, unsigned debugFlags, const char* file, int line);
void* operator new[]   (size_t size, size_t alignment, size_t alignmentOffset, const char* name, int flags, unsigned debugFlags, const char* file, int line);

void  operator delete  (void* p, const char* name, int flags, unsigned debugFlags, const char* file, int line);
void  operator delete[](void* p, const char* name, int flags, unsigned debugFlags, const char* file, int line);
void  operator delete  (void* p, size_t alignment, size_t alignmentOffset, const char* name, int flags, unsigned debugFlags, const char* file, int line);
void  operator delete[](void* p, size_t alignment, size_t alignmentOffset, const char* name, int flags, unsigned debugFlags, const char* file, int line);


///////////////////////////////////////////////////////////////////////////////
// EASTDC_ALLOC_PREFIX
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
//     void* p = pCoreAllocator->Alloc(37, EASTDC_ALLOC_PREFIX, 0);
//
// Example usage:
//     gMessageServer.GetMessageQueue().get_allocator().set_name(EASTDC_ALLOC_PREFIX "MessageSystem/Queue");
//
#ifndef EASTDC_ALLOC_PREFIX
    #define EASTDC_ALLOC_PREFIX "EAStdC/"
#endif


///////////////////////////////////////////////////////////////////////////////
// EASTDC_USE_STANDARD_NEW
//
// Defines whether we use the basic standard operator new or the named
// extended version of operator new, as per the EASTL package.
//
#ifndef EASTDC_USE_STANDARD_NEW
    #if EASTDC_DLL  // A DLL must provide its own implementation of new, so we just use built-in new.
        #define EASTDC_USE_STANDARD_NEW 1
    #else
        #define EASTDC_USE_STANDARD_NEW 0
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EASTDC_NEW
//
// This is merely a wrapper for operator new which can be overridden and 
// which has debug/release forms.
//
// Example usage:
//    SomeClass* pObject = EASTDC_NEW("SomeClass") SomeClass(1, 2, 3);
//
#ifndef EASTDC_NEW
    #if EASTDC_USE_STANDARD_NEW
            #define EASTDC_NEW(name)                            new
            #define EASTDC_NEW_ALIGNED(alignment, offset, name) new
            #define EASTDC_DELETE                               delete
    #else
        #if defined(EA_DEBUG)
            #define EASTDC_NEW(name)                            new(name, 0, 0, __FILE__, __LINE__)
            #define EASTDC_NEW_ALIGNED(alignment, offset, name) new(alignment, offset, name, 0, 0, __FILE__, __LINE__)
            #define EASTDC_DELETE                               delete
        #else
            #define EASTDC_NEW(name)                            new(name, 0, 0, 0, 0)
            #define EASTDC_NEW_ALIGNED(alignment, offset, name) new(alignment, offset, name, 0, 0, 0, 0)
            #define EASTDC_DELETE                               delete
        #endif
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// UTF_USE_EATRACE    Defined as 0 or 1. Default is 1 but may be overridden by your project file.
// UTF_USE_EAASSERT   Defined as 0 or 1. Default is 0.
//
// Defines whether this package uses the EATrace or EAAssert package to do assertions.
// EAAssert is a basic lightweight package for portable asserting.
// EATrace is a larger "industrial strength" package for assert/trace/log.
// If both UTF_USE_EATRACE and UTF_USE_EAASSERT are defined as 1, then UTF_USE_EATRACE
// overrides UTF_USE_EAASSERT.
//
#if defined(UTF_USE_EATRACE) && UTF_USE_EATRACE
    #undef  UTF_USE_EAASSERT
    #define UTF_USE_EAASSERT 0
#elif !defined(UTF_USE_EAASSERT)
    #define UTF_USE_EAASSERT 0
#endif

#undef UTF_USE_EATRACE
#if defined(UTF_USE_EAASSERT) && UTF_USE_EAASSERT
    #define UTF_USE_EATRACE 0
#else
    #define UTF_USE_EATRACE 1
#endif

#if !defined(EA_ASSERT_HEADER)
    #if defined(UTF_USE_EAASSERT) && UTF_USE_EAASSERT
        #define EA_ASSERT_HEADER <EAAssert/eaassert.h>
    #else
        #define EA_ASSERT_HEADER <EATrace/EATrace.h>
    #endif
#endif
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// EASTDC_STOPWATCH_FORCE_CPU_CYCLE_USAGE
//
// Defined as 0 or 1. 
// If 1 then CPU cycle counts are used instead of system timer counts.
// For systems where CPU frequencies are stable, this should be defined.
//
#ifndef EASTDC_STOPWATCH_FORCE_CPU_CYCLE_USAGE
    #if defined(EA_PROCESSOR_X86) || defined(EA_PROCESSOR_X86_64)
        #define EASTDC_STOPWATCH_FORCE_CPU_CYCLE_USAGE 0 // x86 rdtsc is unreliable.
    #else
        #define EASTDC_STOPWATCH_FORCE_CPU_CYCLE_USAGE 1
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EASTDC_STOPWATCH_OVERHEAD_ENABLED
//
// Defined as 0 or 1. Default depends on the platform.
// When defined as 1 the overhead is esimated on startup and applied to 
// timing events.
// On some systems the overhead of reading the current time is small
// enough that we consider it insiginificant, but on some others it is not. 
// We consider significance to mean more than ~100 CPU clock ticks.
//
#ifndef EASTDC_STOPWATCH_OVERHEAD_ENABLED
    #if (defined(EA_PLATFORM_MICROSOFT) && !defined(EA_PLATFORM_XENON)) || defined(EA_PLATFORM_DESKTOP)
        #define EASTDC_STOPWATCH_OVERHEAD_ENABLED 1
    #else
        #define EASTDC_STOPWATCH_OVERHEAD_ENABLED 0
    #endif
#endif


/////////////////////////////////////////////////////////////////////////////
// EASTDC_PS3_LIBRTC_ENABLED
// 
// Defined as 0 or 1. Default is 0 (disabled).
// If enabled then system time functions use the PS3's more recent librtc 
// functionality. In addition to enabling this define, the user needs to 
// call cellSysmoduleLoadModule(CELL_SYSMODULE_RTC) on startup and link
// librtc_stub.a into the application or PRX (i.e. DLL) being built.
//
#ifndef EASTDC_PS3_LIBRTC_ENABLED
    #define EASTDC_PS3_LIBRTC_ENABLED 0
#endif


/////////////////////////////////////////////////////////////////////////////
// EASTDC_PS3_GAMEDATA_ENABLED
// 
// Defined as 0 or 1. Default is 0 (disabled).
// If enabled then usage of the PS3 GameData API is enabled. 
// In addition to enabling this define, the user needs to 
// call cellSysmoduleLoadModule(CELL_SYSMODULE_SYSUTIL_GAME) on startup and link
// libsysutil_stub.a and libsysutil_game_stub.a into the application or PRX (i.e. DLL) being built.
// 
#ifndef EASTDC_PS3_GAMEDATA_ENABLED
    #define EASTDC_PS3_GAMEDATA_ENABLED 0
#endif


///////////////////////////////////////////////////////////////////////////////
// EASTDC_SCANF_WARNINGS_ENABLED
//
// Defined as 0 or 1. Default is 0 (disabled).
// If enabled then scanf execution that is not an error but could be considered
// a warning is reported. An example is a character format conversion that loses
// information.
//
#ifndef EASTDC_SCANF_WARNINGS_ENABLED
    #define EASTDC_SCANF_WARNINGS_ENABLED 0
#endif


///////////////////////////////////////////////////////////////////////////////
// EASTDC_PRINTF_WARNINGS_ENABLED
//
// Defined as 0 or 1. Default is 0 (disabled).
// If enabled then scanf execution that is not an error but could be considered
// a warning is reported. An example is a character format conversion that loses
// information.
//
#ifndef EASTDC_PRINTF_WARNINGS_ENABLED
    #define EASTDC_PRINTF_WARNINGS_ENABLED 0
#endif


///////////////////////////////////////////////////////////////////////////////
// EASTDC_XXXXX_AVAILABLE
// Similar functionality is present in recent versions of EABase via <eahave.h>.
// To do: Migrate to using EABase versions of these.
//
// Defined as 0 or 1. 
// Tells if various headers are available. Some platforms/compile targets don't
// fully support standard C/C++ libraries.
//
#ifndef EASTDC_TIME_H_AVAILABLE             // time.h header and associated functionality.
    #if defined(EA_PLATFORM_PS3_SPU)
        #define EASTDC_TIME_H_AVAILABLE 0
    #else
        #define EASTDC_TIME_H_AVAILABLE 1
    #endif
#endif

#ifndef EASTDC_SYS_TIME_H_AVAILABLE             // sys/time.h header and associated functionality.
    #if defined(EA_PLATFORM_POSIX) || defined(__APPLE__) || defined(EA_PLATFORM_AIRPLAY) || defined(EA_PLATFORM_PS3)
        #define EASTDC_SYS_TIME_H_AVAILABLE 1
    #else
        #define EASTDC_SYS_TIME_H_AVAILABLE 0
    #endif
#endif

#ifndef EASTDC_SYS__TIMEVAL_H_AVAILABLE         // sys/_timeval.h header and associated functionality.
    #if defined(EA_PLATFORM_FREEBSD)
        #define EASTDC_SYS__TIMEVAL_H_AVAILABLE 1
    #else
        #define EASTDC_SYS__TIMEVAL_H_AVAILABLE 0
    #endif
#endif

#ifndef EASTDC_LOCALE_H_AVAILABLE               // locale.h header and associated functionality.
    #if defined(EA_PLATFORM_PS3_SPU) || defined(EA_PLATFORM_PSP2)
        #define EASTDC_LOCALE_H_AVAILABLE 0
    #else
        #define EASTDC_LOCALE_H_AVAILABLE 1
    #endif
#endif

#ifndef EASTDC_SYS_MMAN_H_AVAILABLE             // sys/mman.h header and associated functionality
    #if defined(EA_PLATFORM_POSIX)
        #define EASTDC_SYS_MMAN_H_AVAILABLE 1
    #else
        #define EASTDC_SYS_MMAN_H_AVAILABLE 0
    #endif
#endif

#ifndef EASTDC_SYS_WAIT_H_AVAILABLE             // sys/wait.h header and associated functionality
    #if defined(EA_PLATFORM_UNIX)
        #define EASTDC_SYS_WAIT_H_AVAILABLE 1
    #else
        #define EASTDC_SYS_WAIT_H_AVAILABLE 0
    #endif
#endif

#ifndef EASTDC_FILE_AVAILABLE                   // FILE io, such as fopen, fread.
    #if defined(EA_PLATFORM_PS3_SPU)
        #define EASTDC_FILE_AVAILABLE 0
    #else
        #define EASTDC_FILE_AVAILABLE 1
    #endif
#endif

#ifndef EASTDC_UNIX_TZNAME_AVAILABLE            // The global tzname variable.
    #if defined(EA_PLATFORM_UNIX)
        #define EASTDC_UNIX_TZNAME_AVAILABLE 1
    #else
        #define EASTDC_UNIX_TZNAME_AVAILABLE 0
    #endif
#endif

#ifndef EASTDC_CLOCK_GETTIME_AVAILABLE          // The clock_gettime function, which is an alternative to gettimeofday.
    //#if defined(CLOCK_REALTIME) // Disabled until we can get usage of this better.
    //    #define EASTDC_CLOCK_GETTIME_AVAILABLE 1
    //#else
        #define EASTDC_CLOCK_GETTIME_AVAILABLE 0
    //#endif
#endif




/////////////////////////////////////////////////////////////////////////////
// EABase fallbacks
/////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// EA_CHAR16
// Present in recent versions of EABase.
//
// EA_CHAR16 is defined in EABase 2.0.20 and later. If we are using an earlier
// version of EABase then we replicate what EABase 2.0.20 does.
//
#ifndef EA_CHAR16
    #if !defined(EA_CHAR16_NATIVE)
        #if defined(_MSC_VER) && (_MSC_VER >= 1600) && defined(_HAS_CHAR16_T_LANGUAGE_SUPPORT) && _HAS_CHAR16_T_LANGUAGE_SUPPORT // VS2010+
            #define EA_CHAR16_NATIVE 1
        #elif defined(__GNUC__) && ((__GNUC__ * 100 + __GNUC_MINOR__) >= 404) && (defined(__GXX_EXPERIMENTAL_CXX0X__) || defined(__STDC_VERSION__)) // g++ (C++ compiler) 4.4+ with -std=c++0x or gcc (C compiler) 4.4+ with -std=gnu99
            #define EA_CHAR16_NATIVE 1
        #else
            #define EA_CHAR16_NATIVE 0
        #endif
    #endif

    #if EA_CHAR16_NATIVE && !defined(_MSC_VER) // Microsoft doesn't support char16_t string literals.
        #define EA_CHAR16(s) u ## s
    #elif (EA_WCHAR_SIZE == 2)
        #define EA_CHAR16(s) L ## s
    #endif
#endif


// ------------------------------------------------------------------------
// EA_UNUSED
// Present in recent versions of EABase.
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
#ifndef EA_UNUSED
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


// ------------------------------------------------------------------------
// EA_DISABLE_CLANG_WARNING / EA_RESTORE_CLANG_WARNING
// Present in recent versions of EABase.
//
// Example usage:
//     // Only one warning can be ignored per statement, due to how clang works.
//     EA_DISABLE_CLANG_WARNING(-Wuninitialized)
//     EA_DISABLE_CLANG_WARNING(-Wunused)
//     <code>
//     EA_RESTORE_CLANG_WARNING()
//     EA_RESTORE_CLANG_WARNING()
//
#ifndef EA_DISABLE_CLANG_WARNING
    #if defined(EA_COMPILER_CLANG)
        #define EACLANGWHELP0(x) #x
        #define EACLANGWHELP1(x) EACLANGWHELP0(clang diagnostic ignored x)
        #define EACLANGWHELP2(x) EACLANGWHELP1(#x)

        #define EA_DISABLE_CLANG_WARNING(w)   \
            _Pragma("clang diagnostic push")  \
            _Pragma(EACLANGWHELP2(w))
    #else
        #define EA_DISABLE_CLANG_WARNING(w)
    #endif
#endif

#ifndef EA_RESTORE_CLANG_WARNING
    #if defined(EA_COMPILER_CLANG)
        #define EA_RESTORE_CLANG_WARNING()    \
            _Pragma("clang diagnostic pop")
    #else
        #define EA_RESTORE_CLANG_WARNING()
    #endif
#endif


/////////////////////////////////////////////////////////////////////////////
// EA_HAVE_WCHAR_IMPL
// 
// Provided in case an older version of EABase is being used.
//
#if (EABASE_VERSION_N < 20028)
    #if defined(EA_PLATFORM_DESKTOP) || defined(EA_PLATFORM_PS3) || defined(EA_PLATFORM_XENON) /* To do: which others? */
        #define EA_HAVE_WCHAR_IMPL      /* Specifies if wchar_t string functions are provided, such as wcslen, wprintf, etc. */
    #endif
#endif


/////////////////////////////////////////////////////////////////////////////
// EA_HAVE_WCHAR_IMPL
// 
#if !defined(EA_HAVE_localtime_DECL) && !defined(EA_NO_HAVE_localtime_DECL)
    #if !defined(EA_PLATFORM_NINTENDO) // localtime doesn't work on Nintendo-based platforms, even if it exists.
        #define EA_HAVE_localtime_DECL 1
    #else
        #define EA_NO_HAVE_localtime_DECL 1
    #endif
#endif


///////////////////////////////////////////////////////////////////////////////
// EA_WINAPI_FAMILY_PARTITION / EA_WINAPI_PARTITION
// 
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



#endif // Header include guard



