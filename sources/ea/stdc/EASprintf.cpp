/////////////////////////////////////////////////////////////////////////////
// EASprintf.cpp
//
// Copyright (c) 2007 Criterion Software Limited and its licensors. All Rights Reserved.
// Created by Paul Pedriana
///////////////////////////////////////////////////////////////////////////////


#include "EA/StdC/internal/Config.h"
#include <EAStdC/internal/SprintfCore.h>
#include <EAStdC/EAString.h>
#include "EA/StdC/EACType.h"
#include EA_ASSERT_HEADER
#include <math.h>
#include <float.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>


#ifdef _MSC_VER
    #pragma warning(push)
    #pragma warning(disable: 4127)  // conditional expression is constant.
#endif


namespace EA
{
namespace StdC
{


///////////////////////////////////////////////////////////////////////////////
// char8_t 
///////////////////////////////////////////////////////////////////////////////

EASTDC_API int Vcprintf(WriteFunction8 pWriteFunction8, void* EA_RESTRICT pContext, const char8_t* EA_RESTRICT pFormat, va_list arguments)
{
    return SprintfLocal::VprintfCore(pWriteFunction8, pContext, pFormat, arguments);
}

EASTDC_API int Vfprintf(FILE* EA_RESTRICT pFile, const char8_t* EA_RESTRICT pFormat, va_list arguments)
{
    #ifdef EA_PLATFORM_ANDROID
        // On Android there is no implementation of stdout and stderr. It seems to go into the bit bucket.
        // Since for mobile and console platforms we always use stdout/stderr for debug output, we redirect
        // this output to our PlatformLogWriter, which is a debug trace output. Ideally we wouldn't be doing
        // this and would instead let the user handle this. If it becomes a problem then we can consider it.
        if((pFile == stdout) || (pFile == stderr))
        {
            return SprintfLocal::VprintfCore(SprintfLocal::PlatformLogWriter, NULL, pFormat, arguments);
        }
    #endif

    return SprintfLocal::VprintfCore(SprintfLocal::FILEWriter8, pFile, pFormat, arguments);
}

EASTDC_API int Vprintf(const char8_t* EA_RESTRICT pFormat, va_list arguments)
{
    #ifdef EA_PLATFORM_ANDROID
        return SprintfLocal::VprintfCore(SprintfLocal::PlatformLogWriter, NULL, pFormat, arguments);
    #else
        return SprintfLocal::VprintfCore(SprintfLocal::FILEWriter8, stdout, pFormat, arguments);
    #endif
}

EASTDC_API int Vsprintf(char8_t* EA_RESTRICT pDestination, const char8_t* EA_RESTRICT pFormat, va_list arguments)
{
    return Vsnprintf(pDestination, (size_t)-1, pFormat, arguments);
}

EASTDC_API int Vsnprintf(char8_t* EA_RESTRICT pDestination, size_t n, const char8_t* EA_RESTRICT pFormat, va_list arguments)
{
    SprintfLocal::SnprintfContext8 sc(pDestination, 0, pDestination ? n : 0);

    const int nRequiredLength = SprintfLocal::VprintfCore(SprintfLocal::StringWriter8, &sc, pFormat, arguments);

    #if EASPRINTF_SNPRINTF_C99_RETURN
        if(pDestination && (nRequiredLength >= 0))
        {
            if((size_t)nRequiredLength < n) // If there was enough space...
                pDestination[nRequiredLength] = 0;
            else if(n > 0)
                pDestination[n - 1] = 0;
        } // Else an encoding error has occurred and we can do nothing.

        return nRequiredLength;
    #else
        if((size_t)nRequiredLength < n)
        {
            if(pDestination)
                pDestination[nRequiredLength] = 0;
            return n;
        }
        else if((n > 0) && pDestination)
            pDestination[n - 1] = 0;
        return -1;
    #endif
}

EASTDC_API int Vscprintf(const char8_t* EA_RESTRICT pFormat, va_list arguments)
{
    // vscprintf returns the number of chars that are needed for a printf operation.
    return Vsnprintf(NULL, 0, pFormat, arguments);
}

EASTDC_API int Cprintf(WriteFunction8 pWriteFunction, void* EA_RESTRICT pContext, const char8_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);

    int result = SprintfLocal::VprintfCore(pWriteFunction, pContext, pFormat, arguments);

    va_end(arguments);

    return result;
}

EASTDC_API int Fprintf(FILE* EA_RESTRICT pFile, const char8_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);

    #ifdef EA_PLATFORM_ANDROID
        if((pFile == stdout) || (pFile == stderr))
            return SprintfLocal::VprintfCore(SprintfLocal::PlatformLogWriter, NULL, pFormat, arguments);
    #endif

    int result = SprintfLocal::VprintfCore(SprintfLocal::FILEWriter8, pFile, pFormat, arguments);

    va_end(arguments);

    return result;
}

EASTDC_API int Printf(const char8_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);

    #ifdef EA_PLATFORM_ANDROID
        int result = SprintfLocal::VprintfCore(SprintfLocal::PlatformLogWriter, NULL, pFormat, arguments);
    #else
        int result = SprintfLocal::VprintfCore(SprintfLocal::FILEWriter8, stdout, pFormat, arguments);
    #endif

    va_end(arguments);

    return result;
}

EASTDC_API int Sprintf(char8_t* EA_RESTRICT pDestination, const char8_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);

    int result = Vsnprintf(pDestination, (size_t)SprintfLocal::kNoPrecision, pFormat, arguments);

    va_end(arguments);

    return result;
}

EASTDC_API int Snprintf(char8_t* EA_RESTRICT pDestination, size_t n, const char8_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);

    int result = Vsnprintf(pDestination, n, pFormat, arguments);

    va_end(arguments);

    return result;
}



///////////////////////////////////////////////////////////////////////////////
// char16_t 
///////////////////////////////////////////////////////////////////////////////

EASTDC_API int Vcprintf(WriteFunction16 pWriteFunction16, void* EA_RESTRICT pContext, const char16_t* EA_RESTRICT pFormat, va_list arguments)
{
    return SprintfLocal::VprintfCore(pWriteFunction16, pContext, pFormat, arguments);
}

EASTDC_API int Vfprintf(FILE* EA_RESTRICT pFile, const char16_t* EA_RESTRICT pFormat, va_list arguments)
{
    // Disabled because PlatformLogWriter currently supports only 8 bit text.
    //#ifdef EA_PLATFORM_ANDROID
    //    if((pFile == stdout) || (pFile == stderr))
    //        return SprintfLocal::VprintfCore(SprintfLocal::PlatformLogWriter, NULL, pFormat, arguments);
    //#endif

    return SprintfLocal::VprintfCore(SprintfLocal::FILEWriter16, pFile, pFormat, arguments);
}

EASTDC_API int Vprintf(const char16_t* EA_RESTRICT pFormat, va_list arguments)
{
    return SprintfLocal::VprintfCore(SprintfLocal::FILEWriter16, stdout, pFormat, arguments);
}

EASTDC_API int Vsprintf(char16_t* EA_RESTRICT pDestination, const char16_t* EA_RESTRICT pFormat, va_list arguments)
{
    return Vsnprintf(pDestination, (size_t)-1, pFormat, arguments);
}

EASTDC_API int Vsnprintf(char16_t* EA_RESTRICT pDestination, size_t n, const char16_t* EA_RESTRICT pFormat, va_list arguments)
{
    SprintfLocal::SnprintfContext16 sc(pDestination, 0, pDestination ? n : 0);

    const int nRequiredLength = SprintfLocal::VprintfCore(SprintfLocal::StringWriter16, &sc, pFormat, arguments);

    #if EASPRINTF_SNPRINTF_C99_RETURN
        if(pDestination && (nRequiredLength >= 0))
        {
            if((size_t)nRequiredLength < n) // If there was enough space...
                pDestination[nRequiredLength] = 0;
            else if(n > 0)
                pDestination[n - 1] = 0;
        } // Else an encoding error has occurred and we can do nothing.

        return nRequiredLength;
    #else
        if((size_t)nRequiredLength < n)
        {
            if(pDestination)
                pDestination[nRequiredLength] = 0;
            return n;
        }
        else if((n > 0) && pDestination)
            pDestination[n - 1] = 0;
        return -1;
    #endif
}

EASTDC_API int Vscprintf(const char16_t* EA_RESTRICT pFormat, va_list arguments)
{
    // vscprintf returns the number of chars that are needed for a printf operation.
    return Vsnprintf(NULL, 0, pFormat, arguments);
}

EASTDC_API int Cprintf(WriteFunction16 pWriteFunction, void* EA_RESTRICT pContext, const char16_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);

    int result = SprintfLocal::VprintfCore(pWriteFunction, pContext, pFormat, arguments);

    va_end(arguments);

    return result;
}

EASTDC_API int Fprintf(FILE* EA_RESTRICT pFile, const char16_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);

    // Disabled because PlatformLogWriter currently supports only 8 bit text.
    //#ifdef EA_PLATFORM_ANDROID
    //    if((pFile == stdout) || (pFile == stderr))
    //        return SprintfLocal::VprintfCore(SprintfLocal::PlatformLogWriter, NULL, pFormat, arguments);
    //#endif

    int result = SprintfLocal::VprintfCore(SprintfLocal::FILEWriter16, pFile, pFormat, arguments);

    va_end(arguments);

    return result;
}

EASTDC_API int Printf(const char16_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);

    int result = SprintfLocal::VprintfCore(SprintfLocal::FILEWriter16, stdout, pFormat, arguments);

    va_end(arguments);

    return result;
}

EASTDC_API int Sprintf(char16_t* EA_RESTRICT pDestination, const char16_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);

    int result = Vsnprintf(pDestination, (size_t)SprintfLocal::kNoPrecision, pFormat, arguments);

    va_end(arguments);

    return result;
}

EASTDC_API int Snprintf(char16_t* EA_RESTRICT pDestination, size_t n, const char16_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);

    int result = Vsnprintf(pDestination, n, pFormat, arguments);

    va_end(arguments);

    return result;
}



///////////////////////////////////////////////////////////////////////////////
// char32_t 
///////////////////////////////////////////////////////////////////////////////

EASTDC_API int Vcprintf(WriteFunction32 pWriteFunction32, void* EA_RESTRICT pContext, const char32_t* EA_RESTRICT pFormat, va_list arguments)
{
    return SprintfLocal::VprintfCore(pWriteFunction32, pContext, pFormat, arguments);
}

EASTDC_API int Vfprintf(FILE* EA_RESTRICT pFile, const char32_t* EA_RESTRICT pFormat, va_list arguments)
{
    // Disabled because PlatformLogWriter currently supports only 8 bit text.
    //#ifdef EA_PLATFORM_ANDROID
    //    if((pFile == stdout) || (pFile == stderr))
    //        return SprintfLocal::VprintfCore(SprintfLocal::PlatformLogWriter, NULL, pFormat, arguments);
    //#endif

    return SprintfLocal::VprintfCore(SprintfLocal::FILEWriter32, pFile, pFormat, arguments);
}

EASTDC_API int Vprintf(const char32_t* EA_RESTRICT pFormat, va_list arguments)
{
    return SprintfLocal::VprintfCore(SprintfLocal::FILEWriter32, stdout, pFormat, arguments);
}

EASTDC_API int Vsprintf(char32_t* EA_RESTRICT pDestination, const char32_t* EA_RESTRICT pFormat, va_list arguments)
{
    return Vsnprintf(pDestination, (size_t)-1, pFormat, arguments);
}

EASTDC_API int Vsnprintf(char32_t* EA_RESTRICT pDestination, size_t n, const char32_t* EA_RESTRICT pFormat, va_list arguments)
{
    SprintfLocal::SnprintfContext32 sc(pDestination, 0, pDestination ? n : 0);

    const int nRequiredLength = SprintfLocal::VprintfCore(SprintfLocal::StringWriter32, &sc, pFormat, arguments);

    #if EASPRINTF_SNPRINTF_C99_RETURN
        if(pDestination && (nRequiredLength >= 0))
        {
            if((size_t)nRequiredLength < n) // If there was enough space...
                pDestination[nRequiredLength] = 0;
            else if(n > 0)
                pDestination[n - 1] = 0;
        } // Else an encoding error has occurred and we can do nothing.

        return nRequiredLength;
    #else
        if((size_t)nRequiredLength < n)
        {
            if(pDestination)
                pDestination[nRequiredLength] = 0;
            return n;
        }
        else if((n > 0) && pDestination)
            pDestination[n - 1] = 0;
        return -1;
    #endif
}

EASTDC_API int Vscprintf(const char32_t* EA_RESTRICT pFormat, va_list arguments)
{
    // vscprintf returns the number of chars that are needed for a printf operation.
    return Vsnprintf(NULL, 0, pFormat, arguments);
}

EASTDC_API int Cprintf(WriteFunction32 pWriteFunction, void* EA_RESTRICT pContext, const char32_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);

    int result = SprintfLocal::VprintfCore(pWriteFunction, pContext, pFormat, arguments);

    va_end(arguments);

    return result;
}

EASTDC_API int Fprintf(FILE* EA_RESTRICT pFile, const char32_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);

    // Disabled because PlatformLogWriter currently supports only 8 bit text.
    //#ifdef EA_PLATFORM_ANDROID
    //    if((pFile == stdout) || (pFile == stderr))
    //        return SprintfLocal::VprintfCore(SprintfLocal::PlatformLogWriter, NULL, pFormat, arguments);
    //#endif

    int result = SprintfLocal::VprintfCore(SprintfLocal::FILEWriter32, pFile, pFormat, arguments);

    va_end(arguments);

    return result;
}

EASTDC_API int Printf(const char32_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);

    int result = SprintfLocal::VprintfCore(SprintfLocal::FILEWriter32, stdout, pFormat, arguments);

    va_end(arguments);

    return result;
}

EASTDC_API int Sprintf(char32_t* EA_RESTRICT pDestination, const char32_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);

    int result = Vsnprintf(pDestination, (size_t)SprintfLocal::kNoPrecision, pFormat, arguments);

    va_end(arguments);

    return result;
}

EASTDC_API int Snprintf(char32_t* EA_RESTRICT pDestination, size_t n, const char32_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);

    int result = Vsnprintf(pDestination, n, pFormat, arguments);

    va_end(arguments);

    return result;
}






///////////////////////////////////////////////////////////////////////////
// Deprecated functionality
///////////////////////////////////////////////////////////////////////////

struct Bridge8
{
    WriteFunction8Old mpOldWriteFunction;
    void*             mpUserContext;
};

static int WriteFunctionBridge8(const char8_t* EA_RESTRICT pData, size_t nCount, void* EA_RESTRICT pContext8, WriteFunctionState /*wfs*/)
{
    Bridge8* pBridge8 = (Bridge8*)pContext8;
    return pBridge8->mpOldWriteFunction(pData, nCount, pBridge8->mpUserContext);
}

struct Bridge16
{
    WriteFunction16Old mpOldWriteFunction;
    void*              mpUserContext;
};

static int WriteFunctionBridge16(const char16_t* EA_RESTRICT pData, size_t nCount, void* EA_RESTRICT pContext16, WriteFunctionState /*wfs*/)
{
    Bridge16* pBridge16 = (Bridge16*)pContext16;
    return pBridge16->mpOldWriteFunction(pData, nCount, pBridge16->mpUserContext);
}

EASTDC_API int Cprintf(WriteFunction8Old pWriteFunction, void* EA_RESTRICT pContext, const char8_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);
    int result = Vcprintf(pWriteFunction, pContext, pFormat, arguments);
    va_end(arguments);
    return result;
}

EASTDC_API int Cprintf(WriteFunction16Old pWriteFunction, void* EA_RESTRICT pContext, const char16_t* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);
    int result = Vcprintf(pWriteFunction, pContext, pFormat, arguments);
    va_end(arguments);
    return result;
}

EASTDC_API int Vcprintf(WriteFunction8Old pWriteFunction8, void* EA_RESTRICT pContext, const char8_t* EA_RESTRICT pFormat, va_list arguments)
{
    Bridge8 bridge8 = { pWriteFunction8, pContext };
    return SprintfLocal::VprintfCore(WriteFunctionBridge8, &bridge8, pFormat, arguments);
}

EASTDC_API int Vcprintf(WriteFunction16Old pWriteFunction16, void* EA_RESTRICT pContext, const char16_t* EA_RESTRICT pFormat, va_list arguments)
{
    Bridge16 bridge16 = { pWriteFunction16, pContext };
    return SprintfLocal::VprintfCore(WriteFunctionBridge16, &bridge16, pFormat, arguments);
}

#if EASTDC_VSNPRINTF8_ENABLED
    EASTDC_API int Vsnprintf8(char8_t* EA_RESTRICT pDestination, size_t n, const char8_t* EA_RESTRICT pFormat, va_list arguments)
    {
        return Vsnprintf(pDestination, n, pFormat, arguments);
    }

    EASTDC_API int Vsnprintf16(char16_t* EA_RESTRICT pDestination, size_t n, const char16_t* EA_RESTRICT pFormat, va_list arguments)
    {
        return Vsnprintf(pDestination, n, pFormat, arguments);
    }

    EASTDC_API int Vsnprintf32(char32_t* EA_RESTRICT pDestination, size_t n, const char32_t* EA_RESTRICT pFormat, va_list arguments)
    {
        return Vsnprintf(pDestination, n, pFormat, arguments);
    }

    #if defined(EA_WCHAR_UNIQUE) && EA_WCHAR_UNIQUE
        EASTDC_API int VsnprintfW(wchar_t* EA_RESTRICT pDestination, size_t n, const wchar_t* EA_RESTRICT pFormat, va_list arguments)
        {
            return Vsnprintf(pDestination, n, pFormat, arguments);
        }
    #endif

#endif

#if defined(EA_WCHAR_UNIQUE) && EA_WCHAR_UNIQUE
    EASTDC_API int Vcprintf(WriteFunctionW pWriteFunctionW, void* EA_RESTRICT pContext, const wchar_t* EA_RESTRICT pFormat, va_list arguments)
    {
        #if (EA_WCHAR_SIZE == 2)
            return Vcprintf(reinterpret_cast<WriteFunction16>(pWriteFunctionW), pContext, reinterpret_cast<const char16_t *>(pFormat), arguments);
        #else
            return Vcprintf(reinterpret_cast<WriteFunction32>(pWriteFunctionW), pContext, reinterpret_cast<const char32_t *>(pFormat), arguments);
        #endif
    }

    EASTDC_API int Vfprintf(FILE* EA_RESTRICT pFile, const wchar_t* EA_RESTRICT pFormat, va_list arguments)
    {
        #if (EA_WCHAR_SIZE == 2)
            return Vfprintf(pFile, reinterpret_cast<const char16_t *>(pFormat), arguments);
        #else
            return Vfprintf(pFile, reinterpret_cast<const char32_t *>(pFormat), arguments);
        #endif
    }

    EASTDC_API int Vprintf(const wchar_t* EA_RESTRICT pFormat, va_list arguments)
    {
        #if (EA_WCHAR_SIZE == 2)
            return Vprintf(reinterpret_cast<const char16_t *>(pFormat), arguments);
        #else
            return Vprintf(reinterpret_cast<const char32_t *>(pFormat), arguments);
        #endif
    }

    EASTDC_API int Vsprintf(wchar_t* EA_RESTRICT pDestination, const wchar_t* EA_RESTRICT pFormat, va_list arguments)
    {
        #if (EA_WCHAR_SIZE == 2)
            return Vsprintf(reinterpret_cast<char16_t *>(pDestination), reinterpret_cast<const char16_t *>(pFormat), arguments);
        #else
            return Vsprintf(reinterpret_cast<char32_t *>(pDestination), reinterpret_cast<const char32_t *>(pFormat), arguments);
        #endif
    }

    EASTDC_API int Vsnprintf(wchar_t* EA_RESTRICT pDestination, size_t n, const wchar_t* EA_RESTRICT pFormat, va_list arguments)
    {
        #if (EA_WCHAR_SIZE == 2)
            return Vsnprintf(reinterpret_cast<char16_t *>(pDestination), n, reinterpret_cast<const char16_t *>(pFormat), arguments);
        #else
            return Vsnprintf(reinterpret_cast<char32_t *>(pDestination), n, reinterpret_cast<const char32_t *>(pFormat), arguments);
        #endif
    }

    EASTDC_API int Vscprintf(const wchar_t* EA_RESTRICT pFormat, va_list arguments)
    {
        #if (EA_WCHAR_SIZE == 2)
            return Vscprintf(reinterpret_cast<const char16_t *>(pFormat), arguments);
        #else
            return Vscprintf(reinterpret_cast<const char32_t *>(pFormat), arguments);
        #endif
    }

    EASTDC_API int Cprintf(WriteFunctionW pWriteFunction, void* EA_RESTRICT pContext, const wchar_t* EA_RESTRICT pFormat, ...)
    {
        va_list arguments;
        va_start(arguments, pFormat);

        int result = Vcprintf(pWriteFunction, pContext, pFormat, arguments);

        va_end(arguments);

        return result;
    }

    EASTDC_API int Fprintf(FILE* EA_RESTRICT pFile, const wchar_t* EA_RESTRICT pFormat, ...)
    {
        va_list arguments;
        va_start(arguments, pFormat);

        int result = Vfprintf(pFile, pFormat, arguments);

        va_end(arguments);

        return result;
    }

    EASTDC_API int Printf(const wchar_t* EA_RESTRICT pFormat, ...)
    {
        va_list arguments;
        va_start(arguments, pFormat);

        int result = Vprintf(pFormat, arguments);

        va_end(arguments);

        return result;
    }

    EASTDC_API int Sprintf(wchar_t* EA_RESTRICT pDestination, const wchar_t* EA_RESTRICT pFormat, ...)
    {
        va_list arguments;
        va_start(arguments, pFormat);

        int result = Vsprintf(pDestination, pFormat, arguments);

        va_end(arguments);

        return result;
    }

    EASTDC_API int Snprintf(wchar_t* EA_RESTRICT pDestination, size_t n, const wchar_t* EA_RESTRICT pFormat, ...)
    {
        va_list arguments;
        va_start(arguments, pFormat);

        int result = Vsnprintf(pDestination, n, pFormat, arguments);

        va_end(arguments);

        return result;
    }

#endif

} // namespace StdC
} // namespace EA


#ifdef _MSC_VER
    #pragma warning(pop)
#endif







