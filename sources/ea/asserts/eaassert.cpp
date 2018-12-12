// Copyright (c) 2006 Electronic Arts Inc. All rights reserved.

#include "EAAssert/eaassert.h"

#ifndef EA_ASSERT_HAVE_OWN_HEADER

#include <stdio.h>

#if defined(EA_PLATFORM_MICROSOFT) && !defined(EA_PLATFORM_XENON)
    #if !defined(_WIN32_WINNT) || (_WIN32_WINNT < 0x0400)
        #undef  _WIN32_WINNT
        #define _WIN32_WINNT 0x0400
    #endif
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif
    #pragma warning(push,0)
    #include <Windows.h>        // ::IsDebuggerPresent
    #pragma warning(pop)
#elif defined(EA_PLATFORM_AIRPLAY)
    #include <s3eDebug.h>
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
// EA_PLATFORM_MOBILE
//
// Defined as 1 or undefined.
// Implements support for the definition of EA_PLATFORM_MOBILE for the case
// of using EABase versions prior to the addition of its EA_PLATFORM_MOBILE support.
//
#if (EABASE_VERSION_N < 20022) && !defined(EA_PLATFORM_MOBILE)
    #if defined(EA_PLATFORM_IPHONE) || defined(EA_PLATFORM_ANDROID) || defined(EA_PLATFORM_PALM) || \
        defined(EA_PLATFORM_AIRPLAY) || defined(EA_PLATFORM_BADA) || defined(EA_PLATFORM_WINCE)
        #define EA_PLATFORM_MOBILE 1
    #endif
#endif


#if !defined(EA_ASSERT_VSNPRINTF)
    #if defined(EA_PLATFORM_MICROSOFT)
        #define EA_ASSERT_VSNPRINTF _vsnprintf
        #define EA_ASSERT_SNPRINTF   _snprintf
    #else
        #define EA_ASSERT_VSNPRINTF vsnprintf
        #define EA_ASSERT_SNPRINTF   snprintf
    #endif
#endif


namespace EA { 
    namespace Assert { 
    namespace Detail {
    namespace {

        bool DefaultFailureCallback(const char* expr, const char* filename, int line, const char* function, const char* msg, va_list args)
        {
            const int largeEnough = 2048;
            char output[largeEnough + 1] = {};
            char fmtMsg[largeEnough + 1] = {};

            int len = EA_ASSERT_VSNPRINTF(fmtMsg, largeEnough, msg, args);

            // different platforms return different values for the error, but in both
            // cases it'll be out of bounds, so clamp the return value to largeEnough.
            if (len < 0 || len > largeEnough)
                len = largeEnough;

            fmtMsg[len] = '\0';

            len = EA_ASSERT_SNPRINTF(output, largeEnough,
                "%s(%d) : EA_ASSERT failed: '%s' in function: %s\n, message: %s",
                filename, line, expr, function, fmtMsg);
            if (len < 0 || len > largeEnough)
                len = largeEnough;

            output[len] = '\0';

#if defined(EA_PLATFORM_MICROSOFT) && !defined(EA_PLATFORM_XENON) // Xenon (XBox 360) supports printf to write debug output.
            if (IsDebuggerPresent())
            {
                ::OutputDebugStringA(output);
            }
            else
#elif defined(EA_PLATFORM_AIRPLAY)
            if (s3eDebugIsDebuggerPresent())
            {
                s3eDebugOutputString(output);
            }
            else
#elif defined(EA_PLATFORM_CTR)
                NN_LOG(output);
#endif
                puts(output);

                #if defined(EA_PLATFORM_MOBILE)
                    fflush(stdout); // Mobile platforms need this because otherwise you can easily lose output if the device crashes.
                #endif

            return true;
        }
        
        FailureCallback gFailureCallback = &DefaultFailureCallback; 
    }}

    void SetFailureCallback(FailureCallback failureCallback)
    {
        Detail::gFailureCallback = failureCallback;
    }

    FailureCallback GetFailureCallback()
    {
        return Detail::gFailureCallback;
    }

#if !defined(EA_PLATFORM_PS3_SPU)

    bool Detail::VCall(const char *expr, const char *filename, int line, const char *function, const char *msg, ...)
    {
        va_list args;
        va_start(args, msg);
        bool ret = (*GetFailureCallback())(expr, filename, line, function, msg, args);
        va_end(args);
        return ret;
    }

    bool Detail::Call(const char *expr, const char *filename, int line, const char *function)
    {
        return VCall(expr, filename, line, function, "none");
    }

    bool Detail::Call(const char *expr, const char *filename, int line, const char *function, const char* msg)
    {
        return VCall(expr, filename, line, function, msg);

    }
#endif

    }}

#endif
