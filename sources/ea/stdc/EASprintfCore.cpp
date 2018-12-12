/////////////////////////////////////////////////////////////////////////////
// SprintfCore.cpp
//
// Copyright (c) 2007 Criterion Software Limited and its licensors. All Rights Reserved.
// Created by Paul Pedriana
///////////////////////////////////////////////////////////////////////////////


#include "EA/StdC/internal/Config.h"
#include <EAStdC/internal/SprintfCore.h>
#include <EAStdC/EAString.h>
#include EA_ASSERT_HEADER
#include <string.h>
#include <float.h>
#include <math.h>
#if (defined EA_PLATFORM_CTR)
    #include <nn/dbg.h>
#endif


#ifdef _MSC_VER
    #pragma warning(push)
    #pragma warning(disable: 4127)  // conditional expression is constant.
#elif defined(__ghs__) // Green Hills compiler
    // We disable warning 1798, which otherwise results in the following warning:
    //     a questionable cast from type "_va_struct *" to type "va_list *" may indicate illegal references.
    // We have the cast in the code below because some compilers implement va_list in 
    // a way that doesn't strictly comply with the C99 Standard. However, the warning 
    // report above indicates that there is an aliasing problem. The cleanest way for us
    // to work around this problem is to revise all our Printf, PrintfOrdered, and Scanf
    // functionality to use a va_list wrapped in a struct. However, that would entail a 
    // cost due to using va_copy to copy to that struct. In the short run we simply disable
    // this warning, but we may want to reconsider the option of using a wrapping struct.
    // See the VaListContainer struct we declared for this purpose.
    #pragma diag_suppress 1798
#endif


#if (defined(__MWERKS__) && defined(__PPC_EABI__)) || (defined(__GNUC__) && (defined(__x86__) || defined(__x86_64__)))
    #define VA_LIST_REFERENCE(arguments) ((va_list*) arguments)
#else
    #define VA_LIST_REFERENCE(arguments) ((va_list*)&arguments)
#endif

#ifdef EA_PLATFORM_ANDROID
    #include <android/log.h>
    #include <pthread.h>
#endif

namespace EA
{
namespace StdC
{
namespace SprintfLocal
{


int StringWriter8(const char8_t* EA_RESTRICT pData, size_t nCount, void* EA_RESTRICT pContext8, WriteFunctionState /*wfs*/)
{
    using namespace SprintfLocal;

    SnprintfContext8* const pSnprintfContext8 = (SnprintfContext8*)pContext8;

    if(nCount && !pSnprintfContext8->mbMaxCountReached) // If there is anything to write and if we haven't already exhausted the limit for this context...
    {
        if(nCount > (pSnprintfContext8->mnMaxCount - pSnprintfContext8->mnCount)) // If nCount results in an exhausting of the limit...
        {
            pSnprintfContext8->mbMaxCountReached = true; // Note that it is possible due to non-breakable multi-byte sequences that mnCount will be < mnMaxCount.

            // We must check for (UTF8) MBCS sequences here. We cannot write a
            // partial multi-byte sequence, but can only write a contiguous sequence.
            const size_t nRoom = pSnprintfContext8->mnMaxCount - pSnprintfContext8->mnCount;
            size_t i = 0;

            while (i < nCount)
            {
                size_t nClusterSize;

                if((uint8_t)pData[i] < 0xc2)
                    nClusterSize = 1;                
                else if((uint8_t)pData[i] < 0xe0)
                    nClusterSize = 2;
                else if((uint8_t)pData[i] < 0xf0)
                    nClusterSize = 3;
                else
                    break; // Unknown size. Fail the cluster.

                if (i + nClusterSize > nRoom)
                    break; // Out of room in our destination buffer.

                i += nClusterSize;
            }

            nCount = i;
        }

        memcpy(pSnprintfContext8->mpDestination + pSnprintfContext8->mnCount, pData, nCount * sizeof(*pData));
        pSnprintfContext8->mnCount += nCount;

        return (int)(unsigned)nCount;
    }

    return 0;
}

int StringWriter16(const char16_t* EA_RESTRICT pData, size_t nCount, void* EA_RESTRICT pContext16, WriteFunctionState /*wfs*/)
{
    using namespace SprintfLocal;

    SnprintfContext16* const pSnprintfContext16 = (SnprintfContext16*)pContext16;

    if(nCount > (pSnprintfContext16->mnMaxCount - pSnprintfContext16->mnCount))  // If nCount results in an exhausting of the limit...
        nCount = pSnprintfContext16->mnMaxCount - pSnprintfContext16->mnCount;

    memcpy(pSnprintfContext16->mpDestination + pSnprintfContext16->mnCount, pData, nCount * sizeof(char16_t));
    pSnprintfContext16->mnCount += nCount;

    return (int)(unsigned)nCount;
}

int StringWriter32(const char32_t* EA_RESTRICT pData, size_t nCount, void* EA_RESTRICT pContext32, WriteFunctionState /*wfs*/)
{
    using namespace SprintfLocal;

    SnprintfContext32* const pSnprintfContext32 = (SnprintfContext32*)pContext32;

    if(nCount > (pSnprintfContext32->mnMaxCount - pSnprintfContext32->mnCount))  // If nCount results in an exhausting of the limit...
        nCount = pSnprintfContext32->mnMaxCount - pSnprintfContext32->mnCount;

    memcpy(pSnprintfContext32->mpDestination + pSnprintfContext32->mnCount, pData, nCount * sizeof(char32_t));
    pSnprintfContext32->mnCount += nCount;

    return (int)(unsigned)nCount;
}




int FILEWriter8(const char8_t* EA_RESTRICT pData, size_t nCount, void* EA_RESTRICT pContext8, WriteFunctionState /*wfs*/)
{
    FILE* const pFile = (FILE*)pContext8;

    #if defined(EA_PLATFORM_CTR)
        if (pFile == stdout)
        {
            NN_LOG("%s", pData);
            return nCount;
        }
    #endif

    const size_t nResult = fwrite(pData, sizeof(char8_t), nCount, pFile); // It's OK if nCount == 0.
    if(nResult == nCount)
        return (int)(unsigned)nResult;
    return -1;
}

int FILEWriter16(const char16_t* EA_RESTRICT pData, size_t nCount, void* EA_RESTRICT pContext16, WriteFunctionState /*wfs*/)
{
    FILE* const pFile = (FILE*)pContext16;
    const size_t nResult = fwrite(pData, sizeof(char16_t), nCount, pFile); // It's OK if nCount == 0.
    if(nResult == nCount)
        return (int)(unsigned)nResult;
    return -1;
}

int FILEWriter32(const char32_t* EA_RESTRICT pData, size_t nCount, void* EA_RESTRICT pContext32, WriteFunctionState /*wfs*/)
{
    FILE* const pFile = (FILE*)pContext32;
    const size_t nResult = fwrite(pData, sizeof(char32_t), nCount, pFile); // It's OK if nCount == 0.
    if(nResult == nCount)
        return (int)(unsigned)nResult;
    return -1;
}



// PlatformLogWriter
//
// The __android_log_write function appends a \n to every call you make to it. This is a problem for 
// us because during a sprintf of a single string we call our Writer multiple times. If we just called
// __android_log_write for every Writer call, a single sprintf would be split across multiple trace lines,
// and \n are also (I think) ignored.
#if defined(EA_PLATFORM_ANDROID)
    struct WriteInfo8
    {
        char8_t mBuffer[512];
        size_t  mPosition;

        WriteInfo8() { mBuffer[0] = 0; mPosition = 0; }
    };

    // The Android C/C++ compiler/linker doesn't support __thread and so we need to use manual pthread
    // thread-local storage facilities to accomplish this.

    struct TLSData
    {
        pthread_key_t mKey;           // This is usually a pointer.
        int           mCreateResult;  // Result of call to pthread_key_create, so we can know if mKey is valid.
        int           mbInitialized;  // 0 if not yet initialized.
    };

    static TLSData gTLS;

    // Currently disabled because this may be called after the heap is destroyed.
    // As a result we intentionally leak a small amount of memory per thread until 
    // we can find a good solution to this problem. The user can solve this by
    // manually deleting the memory before thread exit.
    //static void TLSDestructor(void* pValue)
    //{
    //    WriteInfo8* pWriteInfo = (WriteInfo8*)pValue;
    //    EASTDC_DELETE pWriteInfo;
    //}

    // Unless the user calls EA::StdC::Init() on app startup, the code within this function is 
    // susceptible to a startup race condition if two threads call this for the first time simultaneously.
    static WriteInfo8* TLSGetWriteInfo(bool bAllocateWriteInfoIfNULL)
    {
        if(!gTLS.mbInitialized)
        {
            gTLS.mCreateResult = pthread_key_create(&gTLS.mKey, /*TLSDestructor*/ NULL);
            gTLS.mbInitialized = true; // True even if pthread_key_create failed.
            __sync_synchronize();
        }

        if(gTLS.mCreateResult == 0)
        {
            WriteInfo8* pWriteInfo = (WriteInfo8*)pthread_getspecific(gTLS.mKey);

            if(!pWriteInfo && bAllocateWriteInfoIfNULL)
            {
                pWriteInfo = EASTDC_NEW("EASprintf/never freed") WriteInfo8;
                pthread_setspecific(gTLS.mKey, pWriteInfo);
            }

            return pWriteInfo;
        }

        return NULL;
    }

#endif


int PlatformLogWriter(const char8_t* EA_RESTRICT pData, size_t nCount, void* EA_RESTRICT, WriteFunctionState)
{
    #if defined(EA_PLATFORM_ANDROID)
        const size_t kBufferSize               = sizeof(WriteInfo8::mBuffer) / sizeof(WriteInfo8::mBuffer[0]);
        const size_t kBufferSizeActual         = kBufferSize - 1;           // -1 because we need to save space for a terminating 0 char that __android_log_write wants.
        const size_t kPlatformBufferSize       = 512;                       // This is the size that's the max size the platform's log-writing function can handle.
        const size_t kPlatformBufferSizeActual = kPlatformBufferSize - 1;   // -1 because we need to save space for a terminating 0 char that __android_log_write wants.
        const size_t kMaxCountActual           = (kBufferSizeActual < kPlatformBufferSizeActual) ? kBufferSizeActual : kPlatformBufferSizeActual;

        size_t       countOriginal = nCount;
        WriteInfo8*  pWriteInfo = TLSGetWriteInfo(true);

        if(!pWriteInfo)
        {
            // Emergency fallback code.
            char buffer[kPlatformBufferSize];

            if(nCount > kPlatformBufferSizeActual)
                nCount = kPlatformBufferSizeActual;
            memcpy(buffer, pData, nCount);  // Copy because pData might not be 0-terminated, and Android needs it 0-terminated.
            buffer[nCount] = 0;
            __android_log_write(ANDROID_LOG_INFO, "EAStdC.Printf", buffer);

            return countOriginal;
        }

        // Pick the smaller of the two buffers.

        for(size_t i = 0; i < nCount; i++)
        {
            pWriteInfo->mBuffer[pWriteInfo->mPosition] = pData[i];

            if((pData[i] == '\n') || (pWriteInfo->mPosition == kMaxCountActual)) // If the user is requesting a newline or if we have exhausted the most we can write in a single line...
            {
                if(pWriteInfo->mPosition == kMaxCountActual)
                    pWriteInfo->mPosition++;
                pWriteInfo->mBuffer[pWriteInfo->mPosition] = 0;
                __android_log_write(ANDROID_LOG_INFO, "EAStdC.Printf", pWriteInfo->mBuffer);
                pWriteInfo->mPosition  = 0;
                pWriteInfo->mBuffer[0] = 0;
            }
            else
                pWriteInfo->mPosition++;
        }

        return (int)(unsigned)countOriginal;

    #else
        EA_UNUSED(pData);
        EA_UNUSED(nCount);

        return -1;
    #endif
}



///////////////////////////////////////////////////////////////////////////////
// EASprintfInit
//
void EASprintfInit()
{
    #if defined(EA_PLATFORM_ANDROID)
        TLSGetWriteInfo(false); // Trigger the allocation of the TLS data.
    #endif
}

///////////////////////////////////////////////////////////////////////////////
// EASprintfShutdown
//
void EASprintfShutdown()
{
    #if defined(EA_PLATFORM_ANDROID)
        if(gTLS.mbInitialized && (gTLS.mCreateResult == 0))
            pthread_key_delete(gTLS.mKey);
    #endif
}




///////////////////////////////////////////////////////////////////////////////
// 8 bit version
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ReadFormat8
//
// Reads the current format into FormatData. Return value is pointer to first
// char8_t after the format data.
//
// To know how printf truly needs to work, see the ISO C 1999 standard, section 7.19.6.1.
// See http://www.cplusplus.com/ref/cstdio/printf.html or http://www.opengroup.org/onlinepubs/007908799/xsh/fprintf.html 
// for decent basic online documentation about how printf is supposed to work.
// 
// Argument pFormat is a string pointing to a % format specification of the form:
//        %[flags][width][.precision][modifiers]type
//
///////////////////////////////////////////////////////////////////////////////
//
const char8_t* ReadFormat8(const char8_t* EA_RESTRICT pFormat, SprintfLocal::FormatData* EA_RESTRICT pFormatData, va_list* EA_RESTRICT pArguments)
{
    using namespace SprintfLocal;

    const char8_t* pFormatCurrent       = pFormat;
    Alignment      alignmentNonZeroFill = kAlignmentLeft; // We have a chicken and egg problem in that the zero-fill alignment may or may not be ignored. So we save the value here for what the alignment would be if zero-fill needs to be ignored.
    FormatData     fd;
    char8_t        c;

    // Check for "%%". This is a quick test for early exit.
    if((c = *++pFormatCurrent) == '%')    // If the user specified "%%"...
    {
        fd.mnType = '%';
        *pFormatData = fd;    // pFormatData->mnType = '%'; Consider instead using just this line of code.
        return pFormatCurrent + 1;
    }

    // Check for flags field
    for(; ; (c = *++pFormatCurrent)) // Check for one or more flags ('-', '+', ' ', '#', or '0')
    {
        switch(c)
        {
            case '-': // '-' controls alignment, not the +/- sign before numbers.
                fd.mAlignment = kAlignmentLeft;
                break;

            case '+':
                fd.mSign = kSignMinusPlus;
                break;

            case ' ':    // The C99 language states (7.19.6.1.6): "If the space and + flags both appear, the space flag is ignored."
                if(fd.mSign != kSignMinusPlus)
                   fd.mSign  = kSignSpace;
                break;

            case '#':    // The C99 standard states (7.19.6.1.6): The result is converted to an "alternative form."
                fd.mbAlternativeForm = true; 
                break;

            case '0':    // The C99 standard states (7.19.6.1.6): If the 0 and - flags both appear, the 0 flag is ignored. For d, i, o, u, x, and X conversions, if a precision is specified, the 0 flag is ignored. For other conversions, the behavior is undefined.
                if(fd.mAlignment != kAlignmentLeft)     // Note that '0' is a flag (which can appear in any order) and not part of the number. This is a common misconception.
                {
                    if(fd.mAlignment != kAlignmentZeroFill)    // The C99 standard says that for string fields, 0 fill means space fill.
                        alignmentNonZeroFill = fd.mAlignment;
                    fd.mAlignment  = kAlignmentZeroFill;
                }
                break;

            default:
                goto EndFlagCheck; // C/C++ unfortunately don't provide an efficient mechanism to break from multiple loops other than 'goto'. We could avoid the goto with alternative logic, but that would be less efficient.
        }
    }
    EndFlagCheck:

    // Check for width field. 
    // The C99 standard states (7.19.6.1.5): A field width, or precision, or both, may be 
    // indicated by an asterisk. In this case, an int argument supplies the field width or 
    // precision. The arguments specifying field width, or precision, or both, shall appear 
    // (in that order) before the argument (if any) to be converted. A negative field 
    // width argument is taken as a - flag followed by a positive field width. 
    // A negative precision argument is taken as if the precision were omitted.
    if(c == '*')
    {
        fd.mnWidth = va_arg(*pArguments, int);
        if(fd.mnWidth < 0)
        {
            fd.mAlignment = kAlignmentLeft; // Pretend that a '-' flag was applied, as specified by the standard.
            fd.mnWidth    = -fd.mnWidth;
        }
        c = *++pFormatCurrent;
    }
    else
    {
        // Read the width numerical value. We don't do error checking here as it 
        // would incur a performance penalty that just isn't worth it to us.
        while(((unsigned)(c - '0')) < 10)    // Don't call isdigit() here because that might cause a data cache miss.
        {
            fd.mnWidth = (fd.mnWidth * 10) + (c - '0'); // Consider if there is any way to make this loop more 
            c = *++pFormatCurrent;                      // efficient by reducing multiplies, etc.
        }
    }

    if(fd.mnWidth > kMaxWidth)
    {
        // Note that we leave fd.mnType as zero, indicating an error.
        *pFormatData = fd; // pFormatData->mnType = 0; Consider instead using just this line of code.
        return pFormatCurrent + 1;
    }

    // Check for precision field.
    // An optional precision that gives the minimum number of digits to appear for the 
    // d, i, o, u, x, and X conversions, the number of digits to appear after the decimal-point
    // character for a, A, e, E, f, and F conversions, the maximum number of significant
    // digits for the g and G conversions, or the maximum number of bytes to be written for
    // s conversions. The precision takes the form of a period (.) followed either by an
    // asterisk * (described later) or by an optional decimal integer; if only the period 
    // is specified, the precision is taken as zero. If a precision appears with any other
    // conversion specifier, the behavior is undefined.
    if(c == (char8_t)pFormatData->mDecimalPoint) // If precision is specified...
    {
        if((c = *++pFormatCurrent) == '*') // If the precision is set as a value passed in as an argument...
        {
            fd.mnPrecision = va_arg(*pArguments, int);
            if(fd.mnPrecision < 0)
                fd.mnPrecision = 0;
            c = *++pFormatCurrent;
        }
        else
        {
            fd.mnPrecision = 0;
            while(((unsigned)(c - '0')) < 10) // Don't call isdigit() here because that might cause a data cache miss.
            {
                // Consider doing error checking 
                fd.mnPrecision = (fd.mnPrecision * 10) + (c - '0');
                c = *++pFormatCurrent;
            }
        }
    }

    // Check for length modifier field. C99 standard section 7.19.6.1.7.
    // We support the following modifiers, which include non-standard integer size-specific modifiers.
    //     hh, h, l, ll, I8, I16, I32, I64, I128
    bool bModifierPresent = true; // True until proven false below.

    switch(c)
    {
        case 'h':
            if(pFormatCurrent[1] == 'h') // If the user specified %hh ...
            {
                // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a signed char or unsigned char argument (the argument will have been promoted according to the integer promotions, but its value shall be converted to signed char8_t or unsigned char8_t before printing); or that a following n conversion specifier applies to a pointer to a signed char8_t argument.
                fd.mModifier = kModifierChar;
                c = *++pFormatCurrent;
            }
            else // Else the user specified just %h
            {
                // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a short int or unsigned short int argument (the argument will have been promoted according to the integer promotions, but its value shall be converted to short int or unsigned short int before printing); or that a following n conversion specifier applies to a pointer to a short int argument.
                fd.mModifier = kModifierShort;
            }
            break;

        case 'l': // Check for ell (not one).
            if(pFormatCurrent[1] == 'l') // If the user specified %ll ...
            {
                // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a long long int or unsigned long long int argument; or that a following n conversion specifier applies to a pointer to a long long int argument.
                fd.mModifier = kModifierLongLong;
                c = *++pFormatCurrent;
            }
            else // Else the user specified just %l
            {
                // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a long int or unsigned long int argument; that a following n conversion specifier applies to a pointer to a long int argument; that a following c conversion specifier applies to a wint_t argument; that a following s conversion specifier applies to a pointer to a wchar_t argument; or has no effect on a following a, A, e, E, f, F, g, or G conversion specifier.
                fd.mModifier = kModifierLong;
            }
            break;

        case 'q': 
            // BSD-based OS's use %q to indicate "quad int", which is the same as "long long". We need to support it because iPhone's C99 headers define PRId64 as "qd". 
            fd.mModifier = kModifierLongLong;
            break;

        case 'j':
            // Specifies that a following d, i, o, u, x, or X conversion specifier applies to an intmax_t or uintmax_t argument; or that a following n conversion specifier applies to a pointer to an intmax_t argument.
            fd.mModifier = kModifierMax_t;
            break;

        case 'z':
            // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a size_t or the corresponding signed integer type argument; or that a following n conversion specifier applies to a pointer to a signed integer type corresponding to size_t argument.
            fd.mModifier = kModifierSize_t;
            break;

        case 't':
            // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a ptrdiff_t or the corresponding unsigned integer type argument; or that a following n conversion specifier applies to a pointer to a ptrdiff_t argument.
            fd.mModifier = kModifierPtrdiff_t;
            break;

        case 'L':
            // Specifies that a following a, A, e, E, f, F, g, or G conversion specifier applies to a long double argument.
            fd.mModifier = kModifierLongDouble;
            break;

        case 'I':
            if(pFormatCurrent[1] == '8') // If the user specified %I8 ...
            {
                fd.mModifier = kModifierInt8;
                c = *++pFormatCurrent; // Account for the '8' part of I8. We'll account for the 'I' part below for all formats.
            }
            else if((pFormatCurrent[1] == '1') && (pFormatCurrent[2] == '6'))
            {
                fd.mModifier = kModifierInt16;                    
                c = *(pFormatCurrent += 2);
            }
            else if((pFormatCurrent[1] == '3') && (pFormatCurrent[2] == '2'))
            {
                fd.mModifier = kModifierInt32;                    
                c = *(pFormatCurrent += 2);
            }
            else if((pFormatCurrent[1] == '6') && (pFormatCurrent[2] == '4'))
            {
                fd.mModifier = kModifierInt64;                    
                c = *(pFormatCurrent += 2); // Account for the '64' part of I64. We'll account for the 'I' part below for all formats.
            }
            else if((pFormatCurrent[1] == '1') && (pFormatCurrent[2] == '2') && (pFormatCurrent[3] == '8'))
            {
                fd.mModifier = kModifierInt128;                    
                c = *(pFormatCurrent += 3);
            }
            else // Else the specified modifier was invalid.
            {
                // Note that we leave fd.mnType as zero, indicating an error.
                *pFormatData = fd; // pFormatData->mnType = kFormatError; // Consider instead using just this line of code.
                return pFormatCurrent + 1;
            }
            break;

        default:
            bModifierPresent = false;
    }

    if(bModifierPresent)
        c = *++pFormatCurrent; // Move the pointer past the format (e.g. the 'f' in "%3.1f")

    // Read the conversion type. This must be present.
    fd.mnType = c;

    switch(c)
    {
        case 'b': // unsigned binary. This is a convenient extension that we add.
        case 'd': // signed
        case 'i': // signed
        case 'u': // unsigned
        case 'o': // unsigned
        case 'x': // unsigned
        case 'X': // unsgined
            if(fd.mnPrecision == kNoPrecision)
                fd.mnPrecision = 1;
            else if(fd.mAlignment == kAlignmentZeroFill)
                fd.mAlignment = kAlignmentRight;
            break;

        case 'g':
        case 'G':
            if(fd.mnPrecision == 0) // For %g, if the precision is zero, it is taken as 1.
               fd.mnPrecision = 1;
            // fall through
        case 'e':
        case 'E':
        case 'f':
        case 'F':
        case 'a':  // See the C99 standard, section 7.19.6.1.8, for details on 'a' formatting.
        case 'A':
            if(fd.mnPrecision == kNoPrecision)
               fd.mnPrecision = 6;    // The C99 standard explicitly states that this defaults to 6.
            break;

        case 'p':
            if(sizeof(void*) == 2)
                fd.mModifier = kModifierInt16;
            else if(sizeof(void*) == 4)
                fd.mModifier = kModifierInt32;
            else
                fd.mModifier = kModifierInt64;
            fd.mnPrecision = sizeof(void*) / 4;  // This is 8 for a 32 bit pointer, 16 for a 64 bit pointer.
            fd.mnType = 'x';

            // For the "alternative form" of x (or X) conversion, a nonzero result has 0x (or 0X) prefixed to it.
            // So if the user uses %#p, then the user gets something like 0x12345678, whereas otherwise the 
            // user gets just 12345678.

            break;

        case 'c': // We accept %hc, %c, %lc, %I8c, %I16c, %I32c (regular, regular, wide, char8_t, char16_t, char32_t)
        case 'C': // We accept %hC, %C, %lC, %I8C, %I16C, %I32C (regular, wide,    wide, char8_t, char16_t, char32_t)
        case 's': // We accept %hs, %s, %ls, %I8s, %I16s, %I32s (regular, regular, wide, char8_t, char16_t, char32_t)
        case 'S': // We accept %hS, %S, %lS, %I8s, %I16s, %I32s (regular, wide,    wide, char8_t, char16_t, char32_t)
            // If the user specified zero-fill above, then it is a mistake and we 
            // need to use spaces instead. So we restore the fallback alignment.
            if(fd.mAlignment == kAlignmentZeroFill)
                fd.mAlignment = alignmentNonZeroFill;

            // Microsoft's library goes against the C and C++ standard: %s is 
            // not interpreted to mean char8_t string but instead is interpreted 
            // to be either char8_t or wchar_t depending on what the output
            // text format is. This is non-standard but has the convenience
            // of allowing users to migrate between char8_t and wchar_t usage
            // more easily. So we allow EASPRINTF_MS_STYLE_S_FORMAT to control this.
            if(fd.mModifier == kModifierShort)
               fd.mModifier =  kModifierChar;
            else if(fd.mModifier == kModifierLong)
                fd.mModifier = kModifierWChar;            
            else if(fd.mModifier == kModifierNone) // If the user hasn't already specified, for example %I16.
            {
                #if EASPRINTF_MS_STYLE_S_FORMAT
                    if((c == 's') || (c == 'c'))
                        fd.mModifier = (sizeof(*pFormat) == sizeof(char)) ? kModifierChar : kModifierWChar;
                    else
                        fd.mModifier = (sizeof(*pFormat) == sizeof(char)) ? kModifierWChar : kModifierChar;
                #else
                    if((c == 's') || (c == 'c'))
                        fd.mModifier = kModifierChar;
                    else
                        fd.mModifier = kModifierWChar;
                #endif
            }
            //else if((fd.mModifier < kModifierInt8) || (fd.mModifier > kModifierInt32)) // This expression assumes that Int8, Int16, Int32 are contiguous enum values.
            //{
            //    EA_FAIL_MSG("Printf: Invalid %s modifier");
            //}
            break;

        case 'n':
            // The argument shall be a pointer to signed integer into which is written the 
            // number of characters written to the output stream so far by this call to printf. 
            // No argument is converted, but one is consumed. If the conversion specification 
            // includes any flags, a field width, or a precision, the behavior is undefined.

            // We don't really have anything to do here, as this function is merely reading
            // the format and not acting on it. The caller will act on this appropriately.
            break;
    }

    // If the field width is too long and it's not a string field...
    if((fd.mnPrecision > kMaxPrecision) && (fd.mnPrecision != kNoPrecision) && ((fd.mnType != 's') && (fd.mnType != 'S')))
        fd.mnType = kFormatError;

    // Note that at his point we haven't read the argument corresponding to the formatted value. 
    // We save this for the parent function, as otherwise we'd need some kind of union here to
    // hold all value types.
    *pFormatData = fd;
    return pFormatCurrent + 1;
}



///////////////////////////////////////////////////////////////////////////////
// WriteLong8
//
// Writes the given lValue to the given buffer and returns the start of the 
// data or returns NULL for error. Note that the buffer is passed in as the 
// end of the buffer and not the beginning. This is a common trick used when
// converting integer values to strings, as the conversion algorithm needs
// to work backwards as it is and it's quicker to simply start with the end
// of the buffer and move backwards.
//
char8_t* WriteLong8(const SprintfLocal::FormatData& fd, long lValue, char8_t* EA_RESTRICT pBufferEnd)
{
    using namespace SprintfLocal;

    unsigned long ulValue = (unsigned long)lValue;
    unsigned int  nBase;
    unsigned int  nShift = 0;
    unsigned int  nAnd = 0;
    Sign          sign = kSignNone;
    char8_t*      pCurrent = pBufferEnd;
    int           nDigitCount = 0;
    int           nDigitCountSum = fd.mnPrecision;
    bool          bNegative = false;

    *--pCurrent = 0;

    if((lValue > 0) || (fd.mnPrecision > 0) || fd.mbAlternativeForm)
    {
        // Do initial setup. 
        switch(fd.mnType)
        {
            case 'b': // Binary (this is non-standard, though many would like it to be so)
                nBase  = 2;
                nShift = 0x01;
                nAnd   = 0x01;
                break;

            case 'o': // Octal
                nBase  = 8;
                nShift = 0x03;
                nAnd   = 0x07;
                break;

            case 'd': // Decimal (signed)
            case 'i': // i and d are defined by the standard to be the same.
            default:
                nBase = 10;
                sign  = fd.mSign;
                if(lValue < 0)
                {
                    ulValue   = (unsigned long)-lValue;
                    bNegative = true;
                }
                break;

            case 'u': // Decimal (unsigned)
                nBase = 10;
                break;

            case 'x': // Hexidecimal
            case 'X':
                nBase  = 16;
                nShift = 0x04;
                nAnd   = 0x0f;
                break;
        }

        // Write the individual digits.
        do
        {
            // Optimization: Replace the % and / below with >> and & for cases where
            // we can do this (i.e. nBase = even power of two).
            int nDigit;

            if(nBase == 10)
            {
                nDigit   = (int)(ulValue%nBase);
                ulValue /= nBase;
            }
            else // Else take faster pathway.
            {
                nDigit = (int)(ulValue & nAnd);
                ulValue >>= nShift;
            }

            if(nDigit < 10)
               nDigit = '0' + nDigit;
            else
            {
                nDigit -= 10;
                if(fd.mnType == 'x')
                    nDigit = 'a' + nDigit;
                else
                    nDigit = 'A' + nDigit;
            }

            *--pCurrent = (char8_t)nDigit;
            ++nDigitCount;
        } while(ulValue > 0);

        // For octal mode, the standard specifies that when 'alternative form' is enabled, 
        // the number is prefixed with a zero. This is like how the C language interprets 
        // integers that begin with zero as octal. 
        if((nBase == 8) && fd.mbAlternativeForm && (*pCurrent != (char8_t)'0'))
        {
            *--pCurrent = (char8_t)'0';
            ++nDigitCount;
        }

        // Calculate any leading zeroes required by the 'zero fill' alignment option.
        if(fd.mAlignment == kAlignmentZeroFill) // If we are to precede the number with zeroes...
        {
            if(bNegative || (sign != kSignNone))
                nDigitCountSum = fd.mnWidth - 1; // Take into account the leading sign that we'll need to write.
            else if(fd.mbAlternativeForm && ((nBase == 2) || (nBase == 16)))
                nDigitCountSum = fd.mnWidth - 2; // Take into account the leading "0x" that we'll need to write.
            else
                nDigitCountSum = fd.mnWidth;
        }

        // Write in any leading zeroes as required by the precision specifier(or the zero fill alignment option). 
        while(nDigitCount < nDigitCountSum)
        {
            *--pCurrent = (char8_t)'0';
            ++nDigitCount;
        }

        // Potentially add the sign prefix, which might be either nothing, '-', '+', or ' '.
        if(nBase == 10) // Signs can only apply to decimal types.
        {
            if((fd.mnType == 'd') || (fd.mnType == 'i')) // The standard seems to say that only signed decimal types can have signs.
            {
                if(bNegative)
                    *--pCurrent = (char8_t)'-';
                else if(fd.mSign == kSignMinusPlus)
                    *--pCurrent = (char8_t)'+';
                else if(fd.mSign == kSignSpace)
                    *--pCurrent = (char8_t)' ';
            }
        }
        else if(fd.mbAlternativeForm && ((nBase == 2) || (nBase == 16)))
        {
            // Add the leading 0x, 0X, 0b, or 0B (for our binary extension).
            *--pCurrent = (char8_t)fd.mnType;
            *--pCurrent = (char8_t)'0';
        }
    }

    return pCurrent;
}


///////////////////////////////////////////////////////////////////////////////
// WriteLongLong8
//
// This function is identical to WriteLong except that it works with long long
// instead of long. It is a separate function because on many platforms the
// long long data type is larger than the (efficient) machine word size and is
// thus to be avoided if possible.
//
char8_t* WriteLongLong8(const SprintfLocal::FormatData& fd, long long lValue, char8_t* EA_RESTRICT pBufferEnd)
{
    using namespace SprintfLocal;

    #ifdef EA_PLATFORM_PLAYSTATION2
        // The PS2's long long is 128 bits and no mathematical operations are supported with it.
        // We could solve this by using the int128_t library (see Paul Pedriana), but for now we 
        // just map to long. Note that the PS3 uses a conventional 64 bit long long. 
        return WriteLong8(fd, (long)lValue, pBufferEnd);
    #else
        unsigned long long  ulValue = (unsigned long long)lValue;
        unsigned int        nBase;
        unsigned int        nShift = 0;
        unsigned int        nAnd = 0;
        Sign                sign = kSignNone;
        char8_t*            pCurrent = pBufferEnd;
        int                 nDigitCount = 0;
        int                 nDigitCountSum = fd.mnPrecision;
        bool                bNegative = false;

        *--pCurrent = 0;

        if((lValue > 0) || (fd.mnPrecision > 0) || fd.mbAlternativeForm)
        {
            // Do initial setup. 
            switch(fd.mnType)
            {
                case 'b': // Binary.
                    nBase  = 2;
                    nShift = 1;
                    nAnd   = 0x01;
                    break;

                case 'o':
                    nBase  = 8;
                    nShift = 3;
                    nAnd   = 0x07;
                    break;

                case 'd':
                case 'i':
                default:
                    nBase = 10;
                    sign  = fd.mSign;
                    if(lValue < 0)
                    {
                        ulValue   = (unsigned long long)-lValue;
                        bNegative = true;
                    }
                    break;

                case 'u':
                    nBase = 10;
                    break;

                case 'x':
                case 'X':
                    nBase  = 16;
                    nShift = 4;
                    nAnd   = 0x0f;
                    break;
            }

            // Write the individual digits.
            do
            {
                // Optimization: Replace the % and / below with >> and & for cases where
                // we can do this (i.e. nBase = even power of two).
                int nDigit;

                if(nBase == 10)
                {
                    nDigit   = (int)(ulValue % nBase);
                    ulValue /= nBase;
                }
                else // Else take faster pathway.
                {
                    nDigit  =  (int)(ulValue & nAnd);
                    ulValue >>= nShift;
                }

                if(nDigit < 10)
                   nDigit = '0' + nDigit;
                else
                {
                    nDigit -= 10;
                    if(fd.mnType == 'x')
                        nDigit = 'a' + nDigit;
                    else
                        nDigit = 'A' + nDigit;
                }

                *--pCurrent = (char8_t)nDigit;
                ++nDigitCount;
            } while(ulValue > 0);

            // For octal mode, the standard specifies that when 'alternative form' is enabled, the 
            // number is prefixed with a zero. This is like how the C language interprets integers
            // that begin with zero as octal. 
            if((nBase == 8) && fd.mbAlternativeForm && (*pCurrent != (char8_t)'0'))
            {
                *--pCurrent = (char8_t)'0';
                ++nDigitCount;
            }

            // Calculate any leading zeroes required by the 'zero fill' alignment option.
            if(fd.mAlignment == kAlignmentZeroFill) // If we are to precede the number with zeroes...
            {
                if(bNegative || (sign != kSignNone))
                    nDigitCountSum = fd.mnWidth - 1; // Take into account the leading sign that we'll need to write.
                else if(fd.mbAlternativeForm && ((nBase == 2) || (nBase == 16)))
                    nDigitCountSum = fd.mnWidth - 2; // Take into account the leading "0x" that we'll need to write.
                else
                    nDigitCountSum = fd.mnWidth;
            }

            // Write in any leading zeroes as required by the precision specifier(or the zero fill alignment option). 
            while(nDigitCount < nDigitCountSum)
            {
                *--pCurrent = (char8_t)'0';
                ++nDigitCount;
            }

            // Potentially add the sign prefix, which might be either nothing, '-', '+', or ' '.
            if(nBase == 10) // Signs can only apply to decimal types.
            {
                if((fd.mnType == 'd') || (fd.mnType == 'i')) // The standard seems to say that only signed decimal types can have signs.
                {
                    if(bNegative)
                        *--pCurrent = (char8_t)'-';
                    else if(fd.mSign == kSignMinusPlus)
                        *--pCurrent = (char8_t)'+';
                    else if(fd.mSign == kSignSpace)
                        *--pCurrent = (char8_t)' ';
                }
            }
            else if(fd.mbAlternativeForm && ((nBase == 2) || (nBase == 16)))
            {
                // Add the leading 0x, 0X, 0b, or 0B (for our binary extension).
                *--pCurrent = (char8_t)fd.mnType;
                *--pCurrent = (char8_t)'0';
            }
        }

        return pCurrent;
    #endif
}



///////////////////////////////////////////////////////////////////////////////
// WriteDouble8
//
char8_t* WriteDouble8(const SprintfLocal::FormatData& fd, double dValue, char8_t* EA_RESTRICT pBufferEnd8)
{
    using namespace SprintfLocal;

    // Check for nan or inf strings.
    if(IsNaN(dValue))
    {
        *--pBufferEnd8 = 0;
        if(fd.mnType >= 'a') // If type is f, e, g, a, and not F, E, G, A.
        {
            *--pBufferEnd8 = 'n';
            *--pBufferEnd8 = 'a';
            *--pBufferEnd8 = 'n';
        }
        else
        {
            *--pBufferEnd8 = 'N';
            *--pBufferEnd8 = 'A';
            *--pBufferEnd8 = 'N';
        }
        if(IsNeg(dValue))
            *--pBufferEnd8 = '-';
        return pBufferEnd8;
    }
    else if(IsInf(dValue))
    {
        *--pBufferEnd8 = 0;
        if(fd.mnType >= 'a') // If type is f, e, g, a, and not F, E, G, A.
        {
            *--pBufferEnd8 = 'f';
            *--pBufferEnd8 = 'n';
            *--pBufferEnd8 = 'i';
        }
        else
        {
            *--pBufferEnd8 = 'F';
            *--pBufferEnd8 = 'N';
            *--pBufferEnd8 = 'I';
        }
        if(IsNeg(dValue))
            *--pBufferEnd8 = '-';
        return pBufferEnd8;
    }

    // Regular processing.
    int       nType = fd.mnType;
    int       nPrecision = fd.mnPrecision;
    bool      bStripTrailingZeroes = false;      // If true, then don't write useless trailing zeroes, a with the three at the end of: "1.23000"
    bool      bStripPointlessDecimal = false;    // If true, then don't write a decimal point that has no digits after it, as with: "13."
    char8_t*  pResult8 = NULL;

    *--pBufferEnd8 = 0;

    if(nPrecision <= kConversionBufferSize) // If there is enough space for the data...
    {
        int      nDecimalPoint, nSign, nExponent;
        char8_t  pBufferCvt[kFcvtBufMaxSize]; pBufferCvt[0] = 0;
        int      nBufferLength;
        char8_t* pCurrent8 = pBufferEnd8;

        switch(nType)
        {
            default :
            case 'g':
            case 'G':
            {
                // From section 7.19.6.1.8:
                // A double argument representing a floating-point number is converted in
                // style f or e (or in style F or E in the case of a G conversion specifier), with
                // the precision specifying the number of significant digits. If the precision is
                // zero, it is taken as 1. The style used depends on the value converted; style e
                // (or E) is used only if the exponent resulting from such a conversion is less
                // than -4 or greater than or equal to the precision. Trailing zeros are removed
                // from the fractional portion of the result unless the # flag is specified; a
                // decimal-point character appears only if it is followed by a digit.
                // 
                // A double argument representing an infinity or NaN is converted in the style
                // of an f or F conversion specifier.

                EcvtBuf(dValue, nPrecision + 1, &nDecimalPoint, &nSign, pBufferCvt);
                nExponent = nDecimalPoint - 1; // Exponent can be a positive, zero, or negative value.

                if(!fd.mbAlternativeForm)
                    bStripTrailingZeroes = true;
                bStripPointlessDecimal = true;

                if(!((nExponent < -4) || (nExponent >= nPrecision)))
                {
                    /*if(nExponent >= 0) // If there are any digits to the left of the decimal...
                        nPrecision -= (nExponent + 1);*/
                    goto FType;
                }

                if(nType == 'g')
                    nType = 'e';
                else
                    nType = 'E';
                goto EContinuation;
            }

            case 'e':
            case 'E':
            {
                // From section 7.19.6.1.8:
                // A double argument representing a floating-point number is converted in the
                // style [-]d.ddd edd, where there is one digit (which is nonzero if the
                // argument is nonzero) before the decimal-point character and the number of
                // digits after it is equal to the precision; if the precision is missing, it is 
                // taken as 6; if the precision is zero and the # flag is not specified, no decimal-point
                // character appears. The value is rounded to the appropriate number of digits.
                // The E conversion specifier produces a number with E instead of e
                // introducing the exponent. The exponent always contains at least two digits,
                // and only as many more digits as necessary to represent the exponent. If the
                // value is zero, the exponent is zero.
                // 
                // A double argument representing an infinity or NaN is converted in the style
                // of an f or F conversion specifier.

                EcvtBuf(dValue, nPrecision + 1, &nDecimalPoint, &nSign, pBufferCvt);
                nExponent = nDecimalPoint - 1; // Exponent can be a positive, zero, or negative value.
                if(dValue == 0) // Should we instead compare dValue to a very small value?
                    nExponent = 0; // In this case we are working with the value 0, which is always displayed as 0.???e+00

            EContinuation:
                nBufferLength = (int)Strlen(pBufferCvt);

                // Write the exponent digits, at least two of them.
                int nExponentAbs = abs(nExponent);
                while(nExponentAbs > 0)
                {
                    *--pCurrent8 = (char8_t)('0' + (nExponentAbs % 10));
                    nExponentAbs /= 10;
                }
                if(pCurrent8 >= (pBufferEnd8 - 1)) // The C99 standard states that at least two digits are present in the exponent, even if they are either or both zeroes.
                    *--pCurrent8 = '0';
                if(pCurrent8 >= (pBufferEnd8 - 1))
                    *--pCurrent8 = '0';

                // Write the decimal point sign, always + or -.
                if(nExponent >= 0)
                    *--pCurrent8 = '+';
                else
                    *--pCurrent8 = '-';

                // Write 'e' or 'E'.
                *--pCurrent8 = (char8_t)nType;

                // Write all digits but the first one.
                for(char8_t* pTemp = pBufferCvt + nBufferLength; pTemp > pBufferCvt + 1; )
                {
                    const char8_t c = *--pTemp;

                    if(c != '0') // As we move right to left, as soon as we encounter a non-'0', we are done with trialing zeroes.
                        bStripTrailingZeroes = false;
                    if((c != '0') || !bStripTrailingZeroes)
                        *--pCurrent8 = c;
                }

                // Write the decimal point.
                if((*pCurrent8 != (char8_t)nType) || !bStripPointlessDecimal) // If bStripPointlessDecimal is true, then draw decimal only if there are digits after it.
                {
                    if((nBufferLength > 1) || fd.mbAlternativeForm) // If the 'alternative form' is set, then always show a decimal.
                        *--pCurrent8 = (char8_t)fd.mDecimalPoint;
                }

                // Write the first digit.
                *--pCurrent8 = pBufferCvt[0];
                break;
            } // case e:

            case 'f':
            case 'F':
            FType:
            {
                // From section 7.19.6.1.8:
                // A double argument representing a floating-point number is converted to
                // decimal notation in the style [-]ddd.ddd, where the number of digits after
                // the decimal-point character is equal to the precision specification. 
                // If the precision is missing, it is taken as 6; if the precision is zero 
                // and the # flag is not specified, no decimal-point character appears. 
                // If a decimal-point character appears, at least one digit appears before it. 
                // The value is rounded to the appropriate number of digits.
                //
                // A double argument representing an infinity is converted in one of the 
                // styles [-]inf or [-]infinity  which style is implementation-defined. 
                // A double argument representing a NaN is converted in one of the styles
                // [-]nan or [-]nan(n-char-sequence)  which style, and the meaning of
                // any n-char-sequence, is implementation-defined. The F conversion specifier
                // produces INF, INFINITY, or NAN instead of inf, infinity, or nan,
                // respectively.)

                FcvtBuf(dValue, nPrecision, &nDecimalPoint, &nSign, pBufferCvt);
                nBufferLength = (int)Strlen(pBufferCvt);

                // If the 'alternative form' is set, then always show a decimal.
                if(fd.mbAlternativeForm && (nDecimalPoint >= nBufferLength) && !bStripPointlessDecimal)
                    *--pCurrent8 = (char8_t)fd.mDecimalPoint;

                // Write the values that are after the decimal point.
                const char8_t* const pDecimalPoint  = pBufferCvt + nDecimalPoint - 1;
                const char8_t*       pCurrentSource = pBufferCvt + nBufferLength - 1;

                if((pCurrentSource - pDecimalPoint) > nPrecision) // If dValue is very small, this may be true.
                    pCurrentSource = pDecimalPoint + nPrecision;

                while(pCurrentSource > pDecimalPoint)
                {
                    char8_t c;

                    if((pCurrentSource >= pBufferCvt) && (pCurrentSource <= (pBufferCvt + nBufferLength)))
                        c = *pCurrentSource;
                    else
                        c = '0';

                    if(c != '0') // As we move right to left, as soon as we encounter a non-'0', we are done with trialing zeroes.
                        bStripTrailingZeroes = false;

                    if((c != '0') || !bStripTrailingZeroes)
                        *--pCurrent8 = c;
                    --pCurrentSource;
                }

                // Write the decimal point.
                if(*pCurrent8 || !bStripPointlessDecimal) // If bStripPointlessDecimal is true, then draw decimal only if there is something after it.
                {
                    if(nDecimalPoint < nBufferLength) // The standard specifies to not write the decimal point if the precision is zero. 
                        *--pCurrent8 = (char8_t)fd.mDecimalPoint;
                }

                // Write the values that are before the decimal point.
                if(nDecimalPoint > 0)
                {
                    pCurrentSource = pBufferCvt + nDecimalPoint;

                    while(pCurrentSource > pBufferCvt)
                        *--pCurrent8 = *--pCurrentSource;
                }
                else
                    *--pCurrent8 = '0'; // Write the "0" before the decimal point, as in "0.1234".
                break;
            } // case f:
        } // switch

        // Write a sign character.
        if(nSign)
            *--pCurrent8 = '-';
        else if(fd.mSign == kSignMinusPlus)
            *--pCurrent8 = '+';
        else if(fd.mSign == kSignSpace)
            *--pCurrent8 = ' ';

        // Write leading spaces.
        if(fd.mAlignment == kAlignmentRight)
        {
            // Write in any leading spaces as required by the width specifier (or the zero fill alignment option). 
            int nWidth = (int)(intptr_t)(pBufferEnd8 - pCurrent8);

            while(nWidth < fd.mnWidth)
            {
                *--pCurrent8 = (char8_t)' ';
                ++nWidth;
            }
        }

        pResult8 = pCurrent8;
    }

    return pResult8;
}


///////////////////////////////////////////////////////////////////////////////
// VprintfCore
//
int VprintfCore(WriteFunction8 pWriteFunction8, void* EA_RESTRICT pWriteFunctionContext8, const char8_t* EA_RESTRICT pFormat, va_list arguments)
{
    using namespace SprintfLocal;

    const char8_t*      pFormatCurrent = pFormat;   // Current position within entire format string.
    const char8_t*      pFormatSpec;                // Current format specification (e.g. "%3.2f").
    FormatData          fd;
    int                 nWriteCount;
    int                 nWriteCountSum = 0;
    int                 nWriteCountCurrent;
    char8_t             pBuffer8[kConversionBufferSize + 1]; // The +1 isn't necessary but placates code analysis tools.
    char8_t* const      pBufferEnd8 = pBuffer8 + kConversionBufferSize;
    const char8_t*      pBufferData8 = NULL;       // Where within pBuffer8 the data we are interested in begins.
    long                lValue = 0;                // All known supported platforms have 'long' support in hardware. 'int' is always only 32 bits (even on 64 bit systems).
    unsigned long       ulValue = 0;               // 
    long long           llValue = 0;               // Most compilers support 'long long' at this point. VC++ v6 and earlier are notable exceptions.
    unsigned long long  ullValue = 0;              // 

    pWriteFunction8(NULL, 0, pWriteFunctionContext8, kWFSBegin);

    // We walk through the format string and echo characters to the output until we 
    // come across a % specifier, at which point we process it and then move on as before.
    while(*pFormatCurrent)
    {
        // Find the next format specification (or end of the string).
        pFormatSpec = pFormatCurrent;
        while(*pFormatSpec && (*pFormatSpec != '%'))
            ++pFormatSpec;

        // Write out non-formatted text
        nWriteCount = (int)(pFormatSpec - pFormatCurrent);
        if(nWriteCount)
        {
            if(pWriteFunction8(pFormatCurrent, (size_t)nWriteCount, pWriteFunctionContext8, kWFSIntermediate) == -1)
                goto FunctionError; // This is an error; not the same as running out of space.
            nWriteCountSum += nWriteCount;
            pFormatCurrent  = pFormatSpec;
        }

        if(*pFormatSpec)
        {
            pFormatCurrent = ReadFormat8(pFormatSpec, &fd, VA_LIST_REFERENCE(arguments));

            switch(fd.mnType)
            {
                case 'd':    // These are signed values.
                case 'i':    // The standard specifies that 'd' and 'i' are identical.
                {
                    if(fd.mModifier == kModifierLongLong)
                        llValue = va_arg(arguments, long long); // If the user didn't pass a long long, unexpected behaviour will occur.
                    else if((fd.mModifier == kModifierLong) || (fd.mModifier == kModifierLongDouble)) // It is questionable whether we should allow %Ld here as we do. The standard doesn't define this behaviour.
                        lValue = va_arg(arguments, long);
                    else if(fd.mModifier == kModifierInt64)
                    {
                        if(sizeof(int64_t) == sizeof(long))
                        {
                            // fd.mModifier == kModifierLong; -- Not necessary, as the logic below doesn't need this.
                            lValue = va_arg(arguments, long);
                        }
                        else if(sizeof(int64_t) == sizeof(long long))
                        {
                            fd.mModifier = kModifierLongLong;
                            llValue = va_arg(arguments, long long);
                        }
                    }
                    else if(fd.mModifier == kModifierInt128)
                    {
                        if(sizeof(int64_t) < sizeof(long long)) // If long long is 128 bits... (we don't test sizeof(int128_t) because there may be no such thing. Hopefully there is no int96_t.
                            llValue = va_arg(arguments, long long);
                        else
                        {
                            // We have a problem here. The user wants to print a 128 bit value but 
                            // there is no built-in type to support this. For the time being, we 
                            // simply use only 64 bits of data. If we really need this, we can
                            // add the functionality later. We have the EAStdC int128_t type we can use.
                            // I don't think calling two 64 bit va_args is the same as what a single
                            // 128 bit arg would be. If we are using EAStdC int128_t then we handle the 
                            // value the same as passing a struct by value. And that's compiler/ABI-specific.
                            llValue = va_arg(arguments, long long);
                            llValue = va_arg(arguments, long long);
                        }
                    }
                    else // else we have kModifierChar, kModifierShort, kModifierInt8, kModifierInt16, kModifierInt32.
                    {
                        // COMPILE_TIME_ASSERT(sizeof(int32_t) <= sizeof(int));
                        lValue = va_arg(arguments, int);
                        if((fd.mModifier == kModifierShort) || (fd.mModifier == kModifierInt16))
                            lValue = (long)(signed short)lValue; // We carefully do our casting here in order to preserve intent.
                        else if((fd.mModifier == kModifierChar) || (fd.mModifier == kModifierInt8))
                            lValue = (long)(signed char)lValue;  // We carefully do our casting here in order to preserve intent.
                    }

                    if(fd.mModifier == kModifierLongLong)
                    {
                        pBufferData8 = WriteLongLong8(fd, llValue, pBufferEnd8);
                        if(!pBufferData8)
                            goto FormatError;
                    }
                    else
                    {
                        pBufferData8 = WriteLong8(fd, lValue, pBufferEnd8);
                        if(!pBufferData8)
                            goto FormatError;
                    }

                    nWriteCount = (int)((pBufferEnd8 - pBufferData8) - 1); // -1 because the written string is 0-terminated and we don't want to write the final 0.
                    break;
                }

                case 'b': // 'b' means binary. This is a convenient extension that we provide.
                case 'o': // These are unsigned values.
                case 'u':
                case 'x':
                case 'X':
                {
                    if(fd.mModifier == kModifierLong)
                        ulValue = va_arg(arguments, unsigned long);
                    else if(fd.mModifier == kModifierLongLong)
                        ullValue = va_arg(arguments, unsigned long long);
                    else if(fd.mModifier == kModifierInt64)
                    {
                        if(sizeof(uint64_t) == sizeof(unsigned long))
                        {
                            // fd.mModifier == kModifierLong; -- Not necessary, as the logic below doesn't need this.
                            ulValue = va_arg(arguments, unsigned long);
                        }
                        else if(sizeof(uint64_t) == sizeof(unsigned long long))
                        {
                            fd.mModifier = kModifierLongLong;
                            ullValue = va_arg(arguments, unsigned long long);
                        }
                    }
                    else if(fd.mModifier == kModifierInt128)
                    {
                        if(sizeof(uint64_t) < sizeof(unsigned long long)) // If long long is 128 bits... (we don't test sizeof(int128_t) because there may be no such thing. Hopefully there is no int96_t.
                            ullValue = va_arg(arguments, unsigned long long);
                        else
                        {
                            // We have a problem here. The user wants to print a 128 bit value but 
                            // there is no built-in type to support this. For the time being, we 
                            // simply use only 64 bits of data. If we really need this, we can
                            // add the functionality later. We have the EAStdC int128_t type we can use.
                            // I don't think calling two 64 bit va_args is the same as what a single
                            // 128 bit arg would be. If we are using EAStdC int128_t then we handle the 
                            // value the same as passing a struct by value. And that's compiler/ABI-specific.
                            #ifdef EA_SYSTEM_BIG_ENDIAN
                                     (void)va_arg(arguments, unsigned long long);
                                ullValue = va_arg(arguments, unsigned long long);
                            #else
                                ullValue = va_arg(arguments, unsigned long long);
                                     (void)va_arg(arguments, unsigned long long);
                            #endif
                        }
                    }
                    else // else we have kModifierChar, kModifierShort, kModifierInt8, kModifierInt16, kModifierInt32.
                    {
                        ulValue = va_arg(arguments, unsigned int);
                        if((fd.mModifier == kModifierShort) || (fd.mModifier == kModifierInt16))
                            ulValue = (unsigned long)(unsigned short)ulValue; // We carefully do our casting here in order to preserve intent.
                        else if((fd.mModifier == kModifierChar) || (fd.mModifier == kModifierInt8))
                            ulValue = (unsigned long)(unsigned char)ulValue;  // We carefully do our casting here in order to preserve intent.
                    }

                    // Now do the actual writing of the data.
                    if(fd.mModifier == kModifierLongLong)
                    {
                        pBufferData8 = WriteLongLong8(fd, (long long)ullValue, pBufferEnd8);
                        if(!pBufferData8)
                            goto FormatError;
                    }
                    else
                    {
                        pBufferData8 = WriteLong8(fd, (long)ulValue, pBufferEnd8);
                        if(!pBufferData8)
                            goto FormatError;
                    }

                    nWriteCount = (int)((pBufferEnd8 - pBufferData8) - 1); // -1 because the written string is 0-terminated and we don't want to write the final 0.
                    break;
                }

                case 'e':
                case 'E':
                case 'f':
                case 'F':
                case 'g':
                case 'G':
                case 'a': // See the C99 standard, section 7.19.6.1.8, for details on 'a' formatting.
                case 'A':
                {
                    double dValue;
                    if(fd.mModifier == kModifierLongDouble)
                        dValue = va_arg(arguments, double);
                    else
                        dValue = va_arg(arguments, double); // Since on most systems long double is the same as double, it's really no big deal to just work with long double, much like we do with long int instead of int above.

                    pBufferData8 = WriteDouble8(fd, dValue, pBufferEnd8);
                    if(!pBufferData8)
                        goto FormatError;

                    nWriteCount = (int)((pBufferEnd8 - pBufferData8) - 1); // -1 because the written string is 0-terminated and we don't want to write the final 0.
                    break;
                }

                case 's':
                case 'S':
                {
                    int stringTypeSize;

                    switch (fd.mModifier)
                    {
                        case kModifierInt8:         // If the user specified %I8s or %I8S
                        case kModifierChar:         // If the user specified %hs or %hS or kModifierWChar was chosen implicitly for other reasons.
                            stringTypeSize = 1;
                            break;

                        case kModifierInt16:        // If the user specified %I16s or %I16S
                            stringTypeSize = 2;
                            break;

                        case kModifierInt32:        // If the user specified %I32s or %I32S
                            stringTypeSize = 4;
                            break;

                        case kModifierWChar:        // If the user specified %ls or %lS or kModifierWChar was chosen implicitly for other reasons.
                           stringTypeSize = sizeof(wchar_t);
                           break;

                        default:                    // If the user specified %I64s or %I64S or another invalid size.
                            goto FormatError;
                    }

                    switch (stringTypeSize)
                    {
                        case 1:
                        {
                            pBufferData8 = va_arg(arguments, char8_t*);

                            // I don't see the C99 standard specifying the behaviour for a NULL string pointer, 
                            // but both GCC and MSVC use "(null)" when such a NULL pointer is encountered.
                            if(pBufferData8 == NULL)
                                pBufferData8 = kStringNull8;

                            // For strings, the precision modifier refers to the number of chars to display.
                            if(fd.mnPrecision != kNoPrecision) // If the user specified some precision...
                            {
                                // Find which is shorter, the length or the precision.
                                const char8_t*       pBufferCurrent8 = pBufferData8;
                                const char8_t* const pBufferMax8     = pBufferData8 + fd.mnPrecision;

                                while(*pBufferCurrent8 && (pBufferCurrent8 < pBufferMax8))
                                    ++pBufferCurrent8;
                                nWriteCount = (int)(pBufferCurrent8 - pBufferData8);
                            }
                            else
                            {
                                // Set the write count to be the string length. 
                                // Don't call strlen, as that would jump outside this module.
                                const char8_t* pBufferCurrent8 = pBufferData8;

                                while(*pBufferCurrent8) // Implement a small inline strlen.
                                    ++pBufferCurrent8;
                                nWriteCount = (int)(pBufferCurrent8 - pBufferData8);
                            }

                            break;

                        } // case 1

                        case 2:
                        {
                            const char16_t* pBufferData16 = va_arg(arguments, char16_t*);

                            // I don't see the C99 standard specifying the behaviour for a NULL string pointer, 
                            // but both GCC and MSVC use "(null)" when such a NULL pointer is encountered.
                            if(pBufferData16 == NULL)
                                pBufferData16 = kStringNull16;

                            // For strings, the precision modifier refers to the number of chars to display.
                            if(fd.mnPrecision != kNoPrecision) // If the user specified some precision...
                            {
                                // Find which is shorter, the length or the precision.
                                const char16_t*       pBufferCurrent16 = pBufferData16;
                                const char16_t* const pBufferMax16     = pBufferData16 + fd.mnPrecision;

                                while(*pBufferCurrent16 && (pBufferCurrent16 < pBufferMax16))
                                    ++pBufferCurrent16;
                                nWriteCount = (int)(pBufferCurrent16 - pBufferData16);
                            }
                            else
                            {
                                // Set the write count to be the string length. 
                                // Don't call strlen, as that would jump outside this module.
                                const char16_t* pBufferCurrent16 = pBufferData16;

                                while(*pBufferCurrent16) // Implement a small inline strlen.
                                    ++pBufferCurrent16;
                                nWriteCount = (int)(pBufferCurrent16 - pBufferData16);
                            }

                            // We have a problem here. We are converting a 16 bit string to an 8 bit string.
                            // The 8 bit string must either be UTF8-encoded or there will be a loss of information.
                            // So we make the 8 bit string be UTF8-encoded.
                            if(nWriteCount >= kConversionBufferSize)
                            {
                                EA_ASSERT(nWriteCount < kConversionBufferSize);
                                goto FormatError;
                            }

                            nWriteCount = Strlcpy(pBuffer8, pBufferData16, (size_t)(unsigned)kConversionBufferSize, (size_t)(unsigned)nWriteCount);
     
                            // The following is disabled because currently it is impossible for nWriteCount to be negative. The above Strlcpy never returns a negative value.
                            //if(nWriteCount < 0) // If there was a conversion error...
                            //{
                            //    pBuffer8[0] = 0;
                            //    goto FormatError;
                            //}
                            EA_ASSERT(nWriteCount >= 0);

                            pBufferData8 = pBuffer8;
                            break;

                        } // case 2

                        case 4:
                        {
                            const char32_t* pBufferData32 = va_arg(arguments, char32_t*);

                            // I don't see the C99 standard specifying the behaviour for a NULL string pointer, 
                            // but both GCC and MSVC use "(null)" when such a NULL pointer is encountered.
                            if(pBufferData32 == NULL)
                                pBufferData32 = kStringNull32;

                            // For strings, the precision modifier refers to the number of chars to display.
                            if(fd.mnPrecision != kNoPrecision) // If the user specified some precision...
                            {
                                // Find which is shorter, the length or the precision.
                                const char32_t*       pBufferCurrent32 = pBufferData32;
                                const char32_t* const pBufferMax32     = pBufferData32 + fd.mnPrecision;

                                while(*pBufferCurrent32 && (pBufferCurrent32 < pBufferMax32))
                                    ++pBufferCurrent32;
                                nWriteCount = (int)(pBufferCurrent32 - pBufferData32);
                            }
                            else
                            {
                                // Set the write count to be the string length. 
                                // Don't call strlen, as that would jump outside this module.
                                const char32_t* pBufferCurrent32 = pBufferData32;

                                while(*pBufferCurrent32) // Implement a small inline strlen.
                                    ++pBufferCurrent32;
                                nWriteCount = (int)(pBufferCurrent32 - pBufferData32);
                            }

                            // We have a problem here. We are converting a 32 bit string to an 8 bit string.
                            // The 8 bit string must either be UTF8-encoded or there will be a loss of information.
                            // So we make the 8 bit string be UTF8-encoded.
                            if(nWriteCount >= kConversionBufferSize)
                            {
                                EA_ASSERT(nWriteCount < kConversionBufferSize);
                                goto FormatError;
                            }

                            nWriteCount = Strlcpy(pBuffer8, pBufferData32, (size_t)(unsigned)kConversionBufferSize, (size_t)(unsigned)nWriteCount);

                            // The following is disabled because currently it is impossible for nWriteCount to be negative.
                            //if(nWriteCount < 0) // If there was a conversion error...
                            //{
                            //    pBuffer8[0] = 0;
                            //    goto FormatError;
                            //}
                            EA_ASSERT(nWriteCount >= 0);

                            pBufferData8 = pBuffer8;
                            break;

                        } // case 4

                    } // switch (stringTypeSize)

                    break;
                } // case 's'

                case 'n': // %n %hn %ln %lln %I64n %I32n %I16n, %I8n, %jn, %tn, %zn etc.
                {
                    // In this case, we write the numer of chars written so far to the passed in argument.
                    void* pBufferData = va_arg(arguments, void*);

                    switch(fd.mModifier)
                    {
                        case kModifierInt8:
                        case kModifierChar:
                            *(char8_t*)pBufferData = (char8_t)nWriteCountSum; 
                            break;

                        case kModifierInt16: 
                        case kModifierShort:
                            *(int16_t*)pBufferData = (int16_t)nWriteCountSum;
                            break;

                        case kModifierInt32:
                            *(int32_t*)pBufferData = (int32_t)nWriteCountSum;
                            break;

                        case kModifierInt64:
                            *(int64_t*)pBufferData = (int32_t)nWriteCountSum;
                            break;

                        case kModifierLong:
                            *(long*)pBufferData8 = (long)nWriteCountSum;
                            break;

                        case kModifierLongLong:
                            *(long long*)pBufferData = (long long)nWriteCountSum;
                            break;

                        case kModifierPtrdiff_t:
                            *(ptrdiff_t*)pBufferData = (ptrdiff_t)nWriteCountSum;
                            break;

                        case kModifierSize_t:
                            *(size_t*)pBufferData = (size_t)nWriteCountSum;
                            break;

                        case kModifierMax_t:
                            *(intmax_t*)pBufferData = (intmax_t)nWriteCountSum;
                            break;

                      //case kModifierInt128:       // We really should generate an error with this. It's nearly pointless to support it.
                      //    // Fall through
                      //
                      //case kModifierWChar:        // This should be impossible to encounter.
                      //case kModifierLongDouble:   // This should be impossible to encounter.
                      //    // Fall through

                        case kModifierNone:
                        default:
                            *(int*)pBufferData = (int)nWriteCountSum;
                            break;
                    }
                    continue; // Intentionally continue instead break.

                } // case 'n'

                case 'c':
                case 'C':
                {
                    int charTypeSize;

                    switch (fd.mModifier)
                    {
                        case kModifierInt8:         // If the user specified %I8c or %I8c
                        case kModifierChar:         // If the user specified %hc or %hC or kModifierWChar was chosen implicitly for other reasons.
                            charTypeSize = 1;
                            break;

                        case kModifierInt16:        // If the user specified %I16c or %I16C
                            charTypeSize = 2;
                            break;

                        case kModifierInt32:        // If the user specified %I32c or %I32C
                            charTypeSize = 4;
                            break;

                        case kModifierWChar:        // If the user specified %lc or %lC or kModifierWChar was chosen implicitly for other reasons.
                           charTypeSize = sizeof(wchar_t);
                           break;

                        default:                    // If the user specified %I64c or %I64C or another invalid size.
                            goto FormatError;
                    }

                    switch (charTypeSize)
                    {
                        case 1:
                        {
                            pBuffer8[0] = (char8_t)va_arg(arguments, int); // We make the assumption here that sizeof(char16_t) is <= sizeof(int) and thus that a char16_t argument was promoted to int.
                            pBufferData8 = pBuffer8;
                            nWriteCount = 1;
                            EA_ASSERT(sizeof(*pBufferData8) == sizeof(char8_t));
                            break;
                        }
                        case 2:
                        {
                            const char16_t c16 = (char16_t)va_arg(arguments, unsigned int);
                            pBuffer8[0] = (char8_t)(uint8_t)c16; // We are losing data here. We can't do UTF8 here because we can write only a single char.
                            pBufferData8 = pBuffer8;
                            nWriteCount = 1;
                            break;
                        }
                        case 4:
                        {
                            const char32_t c32 = (char32_t)va_arg(arguments, unsigned int);
                            pBuffer8[0] = (char8_t)(uint8_t)c32; // We are losing data here. We can't do UTF8 here because we can write only a single char.
                            pBufferData8 = pBuffer8;
                            nWriteCount = 1;
                            break;
                        }
                    }

                    break;
                } // case 'c'

                case '%':
                {
                    // In this case we just write a single '%' char8_t to the output.
                    pBuffer8[0] = '%';
                    pBufferData8 = pBuffer8;
                    nWriteCount = 1;
                    break;
                }

                case kFormatError:
                default:
                    FormatError:
                    // We do what many printf implementations do here and simply print out the text
                    // as-is -- as if there wasn't any formatting specifier. This at least lets the
                    // user see what was (incorrectly) specified.
                    nWriteCount = (int)(pFormatCurrent - pFormatSpec);
                    nWriteCountSum += nWriteCount;

                    if(nWriteCount && (pWriteFunction8(pFormatSpec, (size_t)nWriteCount, pWriteFunctionContext8, kWFSIntermediate) == -1))
                        goto FunctionError; // This is an error; not the same as running out of space.
                    continue; // Try to continue displaying further data.
            }

            nWriteCountCurrent = nWriteCount; // We will write at least as much nWriteCount, possibly more if the format specified a specific width.

            if(fd.mAlignment != kAlignmentLeft) // If we have right alignment or zero fill...
            {
                char8_t nFill;

                if(fd.mAlignment == kAlignmentZeroFill)
                {
                    nFill = '0';

                    if(pBufferData8 && ((*pBufferData8 == '+') || (*pBufferData8 == '-') || (*pBufferData8 == ' ')))
                    {    // Skip zero fill for leading sign character.
                        if(pWriteFunction8(pBufferData8, 1, pWriteFunctionContext8, kWFSIntermediate) == -1)
                            goto FunctionError; // This is an error; not the same as running out of space.
                        --nWriteCount;
                        ++pBufferData8;
                    }
                }
                else
                    nFill = ' ';

                while(nWriteCountCurrent < fd.mnWidth)
                {
                    // Consider making an optimization which writes more than one fill character at a time.
                    // We can do this by using the space at the beginning of pBuffer8;
                    if(pWriteFunction8(&nFill, 1, pWriteFunctionContext8, kWFSIntermediate) == -1)
                        goto FunctionError; // This is an error; not the same as running out of space.
                    ++nWriteCountCurrent;
                }
            }

            if(nWriteCount && (pWriteFunction8(pBufferData8, (size_t)nWriteCount, pWriteFunctionContext8, kWFSIntermediate) == -1))
                goto FunctionError; // This is an error; not the same as running out of space.

            if(fd.mAlignment == kAlignmentLeft) // If we have left alignment... fill in space to the right of the data.
            {
                const char8_t nSpace = ' ';
                while(nWriteCountCurrent < fd.mnWidth)
                {
                    if(pWriteFunction8(&nSpace, 1, pWriteFunctionContext8, kWFSIntermediate) == -1)
                        goto FunctionError; // This is an error; not the same as running out of space.
                    ++nWriteCountCurrent;
                }
            }

            nWriteCountSum += nWriteCountCurrent;

        } // if(*pFormatSpec)

    } // while(*pFormatCurrent)

    pWriteFunction8(NULL, 0, pWriteFunctionContext8, kWFSEnd);
    return nWriteCountSum;

FunctionError:
    pWriteFunction8(NULL, 0, pWriteFunctionContext8, kWFSEnd);
    return -1;
}




///////////////////////////////////////////////////////////////////////////////
// 16 bit version
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// ReadFormat16
//
// Reads the current format into FormatData. Return value is pointer to first
// char16_t after the format data.
//
// To know how printf truly needs to work, see the ISO C 1999 standard, section 7.19.6.1.
// See http://www.cplusplus.com/ref/cstdio/printf.html or http://www.opengroup.org/onlinepubs/007908799/xsh/fprintf.html 
// for decent basic online documentation about how printf is supposed to work.
// 
// Argument pFormat is a string pointing to a % format specification of the form:
//        %[flags][width][.precision][modifiers]type
//
///////////////////////////////////////////////////////////////////////////////
//
const char16_t* ReadFormat16(const char16_t* EA_RESTRICT pFormat, SprintfLocal::FormatData* EA_RESTRICT pFormatData, va_list* EA_RESTRICT pArguments)
{
    using namespace SprintfLocal;

    const char16_t* pFormatCurrent       = pFormat;
    Alignment       alignmentNonZeroFill = kAlignmentLeft; // We have a chicken and egg problem in that the zero-fill alignment may or may not be ignored. So we save the value here for what the alignment would be if zero-fill needs to be ignored.
    FormatData      fd;
    char16_t        c;

    // Check for "%%". This is a quick test for early exit.
    if((c = *++pFormatCurrent) == '%')    // If the user specified "%%"...
    {
        fd.mnType = '%';
        *pFormatData = fd;    // pFormatData->mnType = '%'; Consider instead using just this line of code.
        return pFormatCurrent + 1;
    }

    // Check for flags field
    for(; ; (c = *++pFormatCurrent)) // Check for one or more flags ('-', '+', ' ', '#', or '0')
    {
        switch(c)
        {
            case '-': // '-' controls alignment, not the +/- sign before numbers.
                fd.mAlignment = kAlignmentLeft;
                break;

            case '+':
                fd.mSign = kSignMinusPlus;
                break;

            case ' ':    // The C99 language states (7.19.6.1.6): "If the space and + flags both appear, the space flag is ignored."
                if(fd.mSign != kSignMinusPlus)
                   fd.mSign  = kSignSpace;
                break;

            case '#':    // The C99 standard states (7.19.6.1.6): The result is converted to an "alternative form."
                fd.mbAlternativeForm = true; 
                break;

            case '0':    // The C99 standard states (7.19.6.1.6): If the 0 and - flags both appear, the 0 flag is ignored. For d, i, o, u, x, and X conversions, if a precision is specified, the 0 flag is ignored. For other conversions, the behavior is undefined.
                if(fd.mAlignment != kAlignmentLeft)     // Note that '0' is a flag (which can appear in any order) and not part of the number. This is a common misconception.
                {
                    if(fd.mAlignment != kAlignmentZeroFill) // The C99 standard says that for string fields, 0 fill means space fill.
                        alignmentNonZeroFill = fd.mAlignment;
                    fd.mAlignment  = kAlignmentZeroFill;
                }
                break;

            default:
                goto EndFlagCheck; // C/C++ unfortunately don't provide an efficient mechanism to break from multiple loops other than 'goto'. We could avoid the goto with alternative logic, but that would be less efficient.
        }
    }
    EndFlagCheck:

    // Check for width field. 
    // The C99 standard states (7.19.6.1.5): A field width, or precision, or both, may be 
    // indicated by an asterisk. In this case, an int argument supplies the field width or 
    // precision. The arguments specifying field width, or precision, or both, shall appear 
    // (in that order) before the argument (if any) to be converted. A negative field 
    // width argument is taken as a - flag followed by a positive field width. 
    // A negative precision argument is taken as if the precision were omitted.
    if(c == '*')
    {
        fd.mnWidth = va_arg(*pArguments, int);
        if(fd.mnWidth < 0)
        {
            fd.mAlignment = kAlignmentLeft; // Pretend that a '-' flag was applied, as specified by the standard.
            fd.mnWidth    = -fd.mnWidth;
        }
        c = *++pFormatCurrent;
    }
    else
    {
        // Read the width numerical value. We don't do error checking here as it 
        // would incur a performance penalty that just isn't worth it to us.
        while(((unsigned)(c - '0')) < 10)    // Don't call isdigit() here because that might cause a data cache miss.
        {
            fd.mnWidth = (int)((fd.mnWidth * 10) + (c - '0')); // Consider if there is any way to make this loop more 
            c = *++pFormatCurrent;                             // efficient by reducing multiplies, etc.
        }
    }

    if(fd.mnWidth > kMaxWidth)
    {
        // Note that we leave fd.mnType as zero, indicating an error.
        *pFormatData = fd; // pFormatData->mnType = 0; Consider instead using just this line of code.
        return pFormatCurrent + 1;
    }

    // Check for precision field.
    // An optional precision that gives the minimum number of digits to appear for the 
    // d, i, o, u, x, and X conversions, the number of digits to appear after the decimal-point
    // character for a, A, e, E, f, and F conversions, the maximum number of significant
    // digits for the g and G conversions, or the maximum number of bytes to be written for
    // s conversions. The precision takes the form of a period (.) followed either by an
    // asterisk * (described later) or by an optional decimal integer; if only the period 
    // is specified, the precision is taken as zero. If a precision appears with any other
    // conversion specifier, the behavior is undefined.
    if(c == (char16_t)pFormatData->mDecimalPoint) // If precision is specified...
    {
        if((c = *++pFormatCurrent) == '*') // If the precision is set as a value passed in as an argument...
        {
            fd.mnPrecision = va_arg(*pArguments, int);
            if(fd.mnPrecision < 0)
                fd.mnPrecision = 0;
            c = *++pFormatCurrent;
        }
        else
        {
            fd.mnPrecision = 0;
            while(((unsigned)(c - '0')) < 10) // Don't call isdigit() here because that might cause a data cache miss.
            {
                // Consider doing error checking 
                fd.mnPrecision = (int)((fd.mnPrecision * 10) + (c - '0'));
                c = *++pFormatCurrent;
            }
        }
    }

    // Check for length modifier field. C99 standard section 7.19.6.1.7.
    // We support the following modifiers, which include non-standard integer size-specific modifiers.
    //     hh, h, l, ll, I8, I16, I32, I64, I128
    bool bModifierPresent = true; // True until proven false below.

    switch(c)
    {
        case 'h':
            if(pFormatCurrent[1] == 'h') // If the user specified %hh ...
            {
                // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a signed char or unsigned char argument (the argument will have been promoted according to the integer promotions, but its value shall be converted to signed char or unsigned char before printing); or that a following n conversion specifier applies to a pointer to a signed char argument.
                fd.mModifier = kModifierChar;
                c = *++pFormatCurrent;
            }
            else // Else the user specified just %h
            {
                // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a short int or unsigned short int argument (the argument will have been promoted according to the integer promotions, but its value shall be converted to short int or unsigned short int before printing); or that a following n conversion specifier applies to a pointer to a short int argument.
                fd.mModifier = kModifierShort;
            }
            break;

        case 'l': // Check for ell (not one).
            if(pFormatCurrent[1] == 'l') // If the user specified %ll ...
            {
                // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a long long int or unsigned long long int argument; or that a following n conversion specifier applies to a pointer to a long long int argument.
                fd.mModifier = kModifierLongLong;
                c = *++pFormatCurrent;
            }
            else // Else the user specified just %l
            {
                // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a long int or unsigned long int argument; that a following n conversion specifier applies to a pointer to a long int argument; that a following c conversion specifier applies to a wint_t argument; that a following s conversion specifier applies to a pointer to a wchar_t argument; or has no effect on a following a, A, e, E, f, F, g, or G conversion specifier.
                fd.mModifier = kModifierLong;
            }
            break;

        case 'q': 
            // BSD-based OS's use %q to indicate "quad int", which is the same as "long long". We need to support it because iPhone's C99 headers define PRId64 as "qd". 
            fd.mModifier = kModifierLongLong;
            break;

        case 'j':
            // Specifies that a following d, i, o, u, x, or X conversion specifier applies to an intmax_t or uintmax_t argument; or that a following n conversion specifier applies to a pointer to an intmax_t argument.
            fd.mModifier = kModifierMax_t;
            break;

        case 'z':
            // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a size_t or the corresponding signed integer type argument; or that a following n conversion specifier applies to a pointer to a signed integer type corresponding to size_t argument.
            fd.mModifier = kModifierSize_t;
            break;

        case 't':
            // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a ptrdiff_t or the corresponding unsigned integer type argument; or that a following n conversion specifier applies to a pointer to a ptrdiff_t argument.
            fd.mModifier = kModifierPtrdiff_t;
            break;

        case 'L':
            // Specifies that a following a, A, e, E, f, F, g, or G conversion specifier applies to a long double argument.
            fd.mModifier = kModifierLongDouble;
            break;

        case 'I':
            if(pFormatCurrent[1] == '8') // If the user specified %I8 ...
            {
                fd.mModifier = kModifierInt8;
                c = *++pFormatCurrent; // Account for the '8' part of I8. We'll account for the 'I' part below for all formats.
            }
            else if((pFormatCurrent[1] == '1') && (pFormatCurrent[2] == '6'))
            {
                fd.mModifier = kModifierInt16;                    
                c = *(pFormatCurrent += 2);
            }
            else if((pFormatCurrent[1] == '3') && (pFormatCurrent[2] == '2'))
            {
                fd.mModifier = kModifierInt32;                    
                c = *(pFormatCurrent += 2);
            }
            else if((pFormatCurrent[1] == '6') && (pFormatCurrent[2] == '4'))
            {
                fd.mModifier = kModifierInt64;                    
                c = *(pFormatCurrent += 2); // Account for the '64' part of I64. We'll account for the 'I' part below for all formats.
            }
            else if((pFormatCurrent[1] == '1') && (pFormatCurrent[2] == '2') && (pFormatCurrent[3] == '8'))
            {
                fd.mModifier = kModifierInt128;                    
                c = *(pFormatCurrent += 3);
            }
            else // Else the specified modifier was invalid.
            {
                // Note that we leave fd.mnType as zero, indicating an error.
                *pFormatData = fd; // pFormatData->mnType = kFormatError; // Consider instead using just this line of code.
                return pFormatCurrent + 1;
            }
            break;

        default:
            bModifierPresent = false;
    }

    if(bModifierPresent)
        c = *++pFormatCurrent; // Move the pointer past the format (e.g. the 'f' in "%3.1f")

    // Read the conversion type. This must be present.
    fd.mnType = (int)c;

    switch(c)
    {
        case 'b': // unsigned binary. This is a convenient extension that we add.
        case 'd': // signed
        case 'i': // signed
        case 'u': // unsigned
        case 'o': // unsigned
        case 'x': // unsigned
        case 'X': // unsgined
            if(fd.mnPrecision == kNoPrecision)
               fd.mnPrecision = 1;
            else if(fd.mAlignment == kAlignmentZeroFill)
                fd.mAlignment = kAlignmentRight;
            break;

        case 'g':
        case 'G':
            if(fd.mnPrecision == 0) // For %g, if the precision is zero, it is taken as 1.
               fd.mnPrecision = 1;
            // fall through
        case 'e':
        case 'E':
        case 'f':
        case 'F':
        case 'a':  // See the C99 standard, section 7.19.6.1.8, for details on 'a' formatting.
        case 'A':
            if(fd.mnPrecision == kNoPrecision)
               fd.mnPrecision = 6;    // The C99 standard explicitly states that this defaults to 6.
            break;

        case 'p':
            if(sizeof(void*) == 2)
                fd.mModifier = kModifierInt16;
            else if(sizeof(void*) == 4)
                fd.mModifier = kModifierInt32;
            else
                fd.mModifier = kModifierInt64;
            fd.mnPrecision = sizeof(void*) / 4;  // This is 8 for a 32 bit pointer, 16 for a 64 bit pointer.
            fd.mnType      = 'x';

            // For the "alternative form" of x (or X) conversion, a nonzero result has 0x (or 0X) prefixed to it.
            // So if the user uses %#p, then the user gets something like 0x12345678, whereas otherwise the 
            // user gets just 12345678.

            break;

        case 'c': // We accept %hc, %c, %lc, %I8c, %I16c, %I32c (regular, regular, wide, char8_t, char16_t, char32_t)
        case 'C': // We accept %hC, %C, %lC, %I8C, %I16C, %I32C (regular, wide,    wide, char8_t, char16_t, char32_t)
        case 's': // We accept %hs, %s, %ls, %I8s, %I16s, %I32s (regular, regular, wide, char8_t, char16_t, char32_t)
        case 'S': // We accept %hS, %S, %lS, %I8s, %I16s, %I32s (regular, wide,    wide, char8_t, char16_t, char32_t)
            // If the user specified zero-fill above, then it is a mistake and we 
            // need to use spaces instead. So we restore the fallback alignment.
            if(fd.mAlignment == kAlignmentZeroFill)
                fd.mAlignment = alignmentNonZeroFill;

            // Microsoft's library goes against the standard: %s is not 
            // interpreted to mean char8_t string but instead is interpreted 
            // to be either char8_t or wchar_t depending on what the output
            // text format is. This is non-standard but has the convenience
            // of allowing users to migrate between char8_t and wchar_t usage
            // more easily. So we allow EASPRINTF_MS_STYLE_S_FORMAT to control this.
            if(fd.mModifier == kModifierShort)
               fd.mModifier =  kModifierChar;
            else if(fd.mModifier == kModifierLong)
                fd.mModifier = kModifierWChar;
            else if(fd.mModifier == kModifierNone) // If the user hasn't already specified, for example %I16.
            {
                #if EASPRINTF_MS_STYLE_S_FORMAT
                    if(c == 's')
                        fd.mModifier = (sizeof(*pFormat) == sizeof(char)) ? kModifierChar : kModifierWChar;
                    else
                        fd.mModifier = (sizeof(*pFormat) == sizeof(char)) ? kModifierWChar : kModifierChar;
                #else
                    if(c == 's')
                        fd.mModifier = kModifierChar;
                    else
                        fd.mModifier = kModifierWChar;
                #endif
            }
            //else if((fd.mModifier < kModifierInt8) || (fd.mModifier > kModifierInt32)) // This expression assumes that Int8, Int16, Int32 are contiguous enum values.
            //{
            //    EA_FAIL_MSG("Printf: Invalid %s modifier");
            //}
            break;

        case 'n':
            // The argument shall be a pointer to signed integer into which is written the 
            // number of characters written to the output stream so far by this call to printf. 
            // No argument is converted, but one is consumed. If the conversion specification 
            // includes any flags, a field width, or a precision, the behavior is undefined.

            // We don't really have anything to do here, as this function is merely reading
            // the format and not acting on it. The caller will act on this appropriately.
            break;
    }

    // If the field width is too long and it's not a string field...
    if((fd.mnPrecision > kMaxPrecision) && (fd.mnPrecision != kNoPrecision) && ((fd.mnType != 's') && (fd.mnType != 'S')))
        fd.mnType = kFormatError;

    // Note that at his point we haven't read the argument corresponding to the formatted value. 
    // We save this for the parent function, as otherwise we'd need some kind of union here to
    // hold all value types.
    *pFormatData = fd;
    return pFormatCurrent + 1;
}


///////////////////////////////////////////////////////////////////////////////
// WriteLong16
//
// Writes the given lValue to the given buffer and returns the start of the 
// data or returns NULL for error. Note that the buffer is passed in as the 
// end of the buffer and not the beginning. This is a common trick used when
// converting integer values to strings, as the conversion algorithm needs
// to work backwards as it is and it's quicker to simply start with the end
// of the buffer and move backwards.
//
char16_t* WriteLong16(const SprintfLocal::FormatData& fd, long lValue, char16_t* EA_RESTRICT pBufferEnd)
{
    using namespace SprintfLocal;

    unsigned long ulValue = (unsigned long)lValue;
    unsigned int  nBase;
    unsigned int  nShift = 0;
    unsigned int  nAnd = 0;
    Sign          sign = kSignNone;
    char16_t*     pCurrent = pBufferEnd;
    int           nDigitCount = 0;
    int           nDigitCountSum = fd.mnPrecision;
    bool          bNegative = false;

    *--pCurrent = 0;

    if((lValue > 0) || (fd.mnPrecision > 0) || fd.mbAlternativeForm)
    {
        // Do initial setup. 
        switch(fd.mnType)
        {
            case 'b': // Binary (this is non-standard, though many would like it to be so)
                nBase  = 2;
                nShift = 0x01;
                nAnd   = 0x01;
                break;

            case 'o': // Octal
                nBase  = 8;
                nShift = 0x03;
                nAnd   = 0x07;
                break;

            case 'd': // Decimal (signed)
            case 'i': // i and d are defined by the standard to be the same.
            default:
                nBase = 10;
                sign  = fd.mSign;
                if(lValue < 0)
                {
                    ulValue   = (unsigned long)-lValue;
                    bNegative = true;
                }
                break;

            case 'u': // Decimal (unsigned)
                nBase = 10;
                break;

            case 'x': // Hexidecimal
            case 'X':
                nBase  = 16;
                nShift = 0x04;
                nAnd   = 0x0f;
                break;
        }

        // Write the individual digits.
        do
        {
            // Optimization: Replace the % and / below with >> and & for cases where
            // we can do this (i.e. nBase = even power of two).
            int nDigit;

            if(nBase == 10)
            {
                nDigit   = (int)(ulValue%nBase);
                ulValue /= nBase;
            }
            else // Else take faster pathway.
            {
                nDigit = (int)(ulValue & nAnd);
                ulValue >>= nShift;
            }

            if(nDigit < 10)
               nDigit = '0' + nDigit;
            else
            {
                nDigit -= 10;
                if(fd.mnType == 'x')
                    nDigit = 'a' + nDigit;
                else
                    nDigit = 'A' + nDigit;
            }

            *--pCurrent = (char16_t)nDigit;
            ++nDigitCount;
        } while(ulValue > 0);

        // For octal mode, the standard specifies that when 'alternative form' is enabled, 
        // the number is prefixed with a zero. This is like how the C language interprets 
        // integers that begin with zero as octal. 
        if((nBase == 8) && fd.mbAlternativeForm && (*pCurrent != (char16_t)'0'))
        {
            *--pCurrent = (char16_t)'0';
            ++nDigitCount;
        }

        // Calculate any leading zeroes required by the 'zero fill' alignment option.
        if(fd.mAlignment == kAlignmentZeroFill) // If we are to precede the number with zeroes...
        {
            if(bNegative || (sign != kSignNone))
                nDigitCountSum = fd.mnWidth - 1; // Take into account the leading sign that we'll need to write.
            else if(fd.mbAlternativeForm && ((nBase == 2) || (nBase == 16)))
                nDigitCountSum = fd.mnWidth - 2; // Take into account the leading "0x" that we'll need to write.
            else
                nDigitCountSum = fd.mnWidth;
        }

        // Write in any leading zeroes as required by the precision specifier(or the zero fill alignment option). 
        while(nDigitCount < nDigitCountSum)
        {
            *--pCurrent = (char16_t)'0';
            ++nDigitCount;
        }

        // Potentially add the sign prefix, which might be either nothing, '-', '+', or ' '.
        if(nBase == 10) // Signs can only apply to decimal types.
        {
            if((fd.mnType == 'd') || (fd.mnType == 'i')) // The standard seems to say that only signed decimal types can have signs.
            {
                if(bNegative)
                    *--pCurrent = (char16_t)'-';
                else if(fd.mSign == kSignMinusPlus)
                    *--pCurrent = (char16_t)'+';
                else if(fd.mSign == kSignSpace)
                    *--pCurrent = (char16_t)' ';
            }
        }
        else if(fd.mbAlternativeForm && ((nBase == 2) || (nBase == 16)))
        {
            // Add the leading 0x, 0X, 0b, or 0B (for our binary extension).
            *--pCurrent = (char16_t)fd.mnType;
            *--pCurrent = (char16_t)'0';
        }
    }

    return pCurrent;
}


///////////////////////////////////////////////////////////////////////////////
// WriteLongLong16
//
// This function is identical to WriteLong except that it works with long long
// instead of long. It is a separate function because on many platforms the
// long long data type is larger than the (efficient) machine word size and is
// thus to be avoided if possible.
//
char16_t* WriteLongLong16(const SprintfLocal::FormatData& fd, long long lValue, char16_t* EA_RESTRICT pBufferEnd)
{
    using namespace SprintfLocal;

    #ifdef EA_PLATFORM_PLAYSTATION2
        // The PS2's long long is 128 bits and no mathematical operations are supported with it.
        // We could solve this by using the int128_t library (see Paul Pedriana), but for now we 
        // just map to long. Note that the PS3 uses a conventional 64 bit long long. 
        return WriteLong16(fd, (long)lValue, pBufferEnd);
    #else
        unsigned long long  ulValue = (unsigned long long)lValue;
        unsigned int        nBase;
        unsigned int        nShift = 0;
        unsigned int        nAnd = 0;
        Sign                sign = kSignNone;
        char16_t*           pCurrent = pBufferEnd;
        int                 nDigitCount = 0;
        int                 nDigitCountSum = fd.mnPrecision;
        bool                bNegative = false;

        *--pCurrent = 0;

        if((lValue > 0) || (fd.mnPrecision > 0) || fd.mbAlternativeForm)
        {
            // Do initial setup. 
            switch(fd.mnType)
            {
                case 'b': // Binary.
                    nBase  = 2;
                    nShift = 1;
                    nAnd   = 0x01;
                    break;

                case 'o':
                    nBase  = 8;
                    nShift = 3;
                    nAnd   = 0x07;
                    break;

                case 'd':
                case 'i':
                default:
                    nBase = 10;
                    sign  = fd.mSign;
                    if(lValue < 0)
                    {
                        ulValue   = (unsigned long long)-lValue;
                        bNegative = true;
                    }
                    break;

                case 'u':
                    nBase = 10;
                    break;

                case 'x':
                case 'X':
                    nBase  = 16;
                    nShift = 4;
                    nAnd   = 0x0f;
                    break;
            }

            // Write the individual digits.
            do
            {
                // Optimization: Replace the % and / below with >> and & for cases where
                // we can do this (i.e. nBase = even power of two).
                int nDigit;

                if(nBase == 10)
                {
                    nDigit   = (int)(ulValue % nBase);
                    ulValue /= nBase;
                }
                else // Else take faster pathway.
                {
                    nDigit  =  (int)(ulValue & nAnd);
                    ulValue >>= nShift;
                }

                if(nDigit < 10)
                   nDigit = '0' + nDigit;
                else
                {
                    nDigit -= 10;
                    if(fd.mnType == 'x')
                        nDigit = 'a' + nDigit;
                    else
                        nDigit = 'A' + nDigit;
                }

                *--pCurrent = (char16_t)nDigit;
                ++nDigitCount;
            } while(ulValue > 0);

            // For octal mode, the standard specifies that when 'alternative form' is enabled, the 
            // number is prefixed with a zero. This is like how the C language interprets integers
            // that begin with zero as octal. 
            if((nBase == 8) && fd.mbAlternativeForm && (*pCurrent != (char16_t)'0'))
            {
                *--pCurrent = (char16_t)'0';
                ++nDigitCount;
            }

            // Calculate any leading zeroes required by the 'zero fill' alignment option.
            if(fd.mAlignment == kAlignmentZeroFill) // If we are to precede the number with zeroes...
            {
                if(bNegative || (sign != kSignNone))
                    nDigitCountSum = fd.mnWidth - 1; // Take into account the leading sign that we'll need to write.
                else if(fd.mbAlternativeForm && ((nBase == 2) || (nBase == 16)))
                    nDigitCountSum = fd.mnWidth - 2; // Take into account the leading "0x" that we'll need to write.
                else
                    nDigitCountSum = fd.mnWidth;
            }

            // Write in any leading zeroes as required by the precision specifier(or the zero fill alignment option). 
            while(nDigitCount < nDigitCountSum)
            {
                *--pCurrent = (char16_t)'0';
                ++nDigitCount;
            }

            // Potentially add the sign prefix, which might be either nothing, '-', '+', or ' '.
            if(nBase == 10) // Signs can only apply to decimal types.
            {
                if((fd.mnType == 'd') || (fd.mnType == 'i')) // The standard seems to say that only signed decimal types can have signs.
                {
                    if(bNegative)
                        *--pCurrent = (char16_t)'-';
                    else if(fd.mSign == kSignMinusPlus)
                        *--pCurrent = (char16_t)'+';
                    else if(fd.mSign == kSignSpace)
                        *--pCurrent = (char16_t)' ';
                }
            }
            else if(fd.mbAlternativeForm && ((nBase == 2) || (nBase == 16)))
            {
                // Add the leading 0x, 0X, 0b, or 0B (for our binary extension).
                *--pCurrent = (char16_t)fd.mnType;
                *--pCurrent = (char16_t)'0';
            }
        }

        return pCurrent;
    #endif
}



///////////////////////////////////////////////////////////////////////////////
// WriteDouble16
//
char16_t* WriteDouble16(const SprintfLocal::FormatData& fd, double dValue, char16_t* EA_RESTRICT pBufferEnd16)
{
    using namespace SprintfLocal;

    // Check for nan or inf strings.
    if(IsNaN(dValue))
    {
        *--pBufferEnd16 = 0;
        if(fd.mnType >= 'a') // If type is f, e, g, a, and not F, E, G, A.
        {
            *--pBufferEnd16 = 'n';
            *--pBufferEnd16 = 'a';
            *--pBufferEnd16 = 'n';
        }
        else
        {
            *--pBufferEnd16 = 'N';
            *--pBufferEnd16 = 'A';
            *--pBufferEnd16 = 'N';
        }
        if(IsNeg(dValue))
            *--pBufferEnd16 = '-';
        return pBufferEnd16;
    }
    else if(IsInf(dValue))
    {
        *--pBufferEnd16 = 0;
        if(fd.mnType >= 'a') // If type is f, e, g, a, and not F, E, G, A.
        {
            *--pBufferEnd16 = 'f';
            *--pBufferEnd16 = 'n';
            *--pBufferEnd16 = 'i';
        }
        else
        {
            *--pBufferEnd16 = 'F';
            *--pBufferEnd16 = 'N';
            *--pBufferEnd16 = 'I';
        }
        if(IsNeg(dValue))
            *--pBufferEnd16 = '-';
        return pBufferEnd16;
    }

    // Regular processing.
    int       nType = fd.mnType;
    int       nPrecision = fd.mnPrecision;
    bool      bStripTrailingZeroes = false;      // If true, then don't write useless trailing zeroes, a with the three at the end of: "1.23000"
    bool      bStripPointlessDecimal = false;    // If true, then don't write a decimal point that has no digits after it, as with: "13."
    char16_t* pResult16 = NULL;

    *--pBufferEnd16 = 0;

    if(fd.mnPrecision <= kConversionBufferSize) // If there is enough space for the data...
    {
        int       nDecimalPoint, nSign, nExponent;
        char16_t  pBufferCvt[kFcvtBufMaxSize]; pBufferCvt[0] = 0;
        int       nBufferLength;
        char16_t* pCurrent16 = pBufferEnd16;

        switch(fd.mnType)
        {
            default :
            case 'g':
            case 'G':
            {
                // From section 7.19.6.1.8:
                // A double argument representing a floating-point number is converted in
                // style f or e (or in style F or E in the case of a G conversion specifier), with
                // the precision specifying the number of significant digits. If the precision is
                // zero, it is taken as 1. The style used depends on the value converted; style e
                // (or E) is used only if the exponent resulting from such a conversion is less
                // than -4 or greater than or equal to the precision. Trailing zeros are removed
                // from the fractional portion of the result unless the # flag is specified; a
                // decimal-point character appears only if it is followed by a digit.
                // 
                // A double argument representing an infinity or NaN is converted in the style
                // of an f or F conversion specifier.

                EcvtBuf(dValue, nPrecision, &nDecimalPoint, &nSign, pBufferCvt);
                nExponent = nDecimalPoint - 1; // Exponent can be a positive, zero, or negative value.

                if(!fd.mbAlternativeForm)
                    bStripTrailingZeroes = true;
                bStripPointlessDecimal = true;

                if(!((nExponent < -4) || (nExponent >= nPrecision)))
                {
                    if(nExponent >= 0) // If there are any digits to the left of the decimal...
                        nPrecision -= (nExponent + 1);
                    goto FType;
                }

                if(nType == 'g')
                    nType = 'e';
                else
                    nType = 'E';
                goto EContinuation;
            } // case g:

            case 'e':
            case 'E':
            {
                // From section 7.19.6.1.8:
                // A double argument representing a floating-point number is converted in the
                // style [-]d.ddd edd, where there is one digit (which is nonzero if the
                // argument is nonzero) before the decimal-point character and the number of
                // digits after it is equal to the precision; if the precision is missing, it is 
                // taken as 6; if the precision is zero and the # flag is not specified, no decimal-point
                // character appears. The value is rounded to the appropriate number of digits.
                // The E conversion specifier produces a number with E instead of e
                // introducing the exponent. The exponent always contains at least two digits,
                // and only as many more digits as necessary to represent the exponent. If the
                // value is zero, the exponent is zero.
                // 
                // A double argument representing an infinity or NaN is converted in the style
                // of an f or F conversion specifier.

                EcvtBuf(dValue, nPrecision + 1, &nDecimalPoint, &nSign, pBufferCvt);
                nExponent = nDecimalPoint - 1; // Exponent can be a positive, zero, or negative value.
                if(dValue == 0) // Should we instead compare dValue to a very small value?
                    nExponent = 0; // In this case we are working with the value 0, which is always displayed as 0.???e+00

            EContinuation:
                nBufferLength = (int)Strlen(pBufferCvt);

                // Write the exponent digits, at least two of them.
                int nExponentAbs = abs(nExponent);
                while(nExponentAbs > 0)
                {
                    *--pCurrent16 = (char16_t)('0' + (nExponentAbs % 10));
                    nExponentAbs /= 10;
                }
                if(pCurrent16 >= (pBufferEnd16 - 1)) // The C99 standard states that at least two zeroes be present.
                    *--pCurrent16 = '0';
                if(pCurrent16 >= (pBufferEnd16 - 1))
                    *--pCurrent16 = '0';

                // Write the decimal point sign, always + or -.
                if(nExponent >= 0)
                    *--pCurrent16 = '+';
                else
                    *--pCurrent16 = '-';

                // Write 'e' or 'E'.
                *--pCurrent16 = (char16_t)nType;

                // Write all digits but the first one.
                for(char16_t* pTemp = pBufferCvt + nBufferLength; pTemp > pBufferCvt + 1; )
                {
                    const char16_t c = *--pTemp;

                    if(c != '0') // As we move right to left, as soon as we encounter a non-'0', we are done with trialing zeroes.
                        bStripTrailingZeroes = false;
                    if((c != '0') || !bStripTrailingZeroes)
                        *--pCurrent16 = c;
                }

                // Write the decimal point.
                if((*pCurrent16 != (char16_t)nType) || !bStripPointlessDecimal) // If bStripPointlessDecimal is true, then draw decimal only if there are digits after it.
                {
                    if((nBufferLength > 1) || fd.mbAlternativeForm) // If the 'alternative form' is set, then always show a decimal.
                        *--pCurrent16 = (char16_t)fd.mDecimalPoint;
                }

                // Write the first digit.
                *--pCurrent16 = pBufferCvt[0];

                break;
            } // case e:

            case 'f':
            case 'F':
            FType:
            {
                // From section 7.19.6.1.8:
                // A double argument representing a floating-point number is converted to
                // decimal notation in the style [-]ddd.ddd, where the number of digits after
                // the decimal-point character is equal to the precision specification. 
                // If the precision is missing, it is taken as 6; if the precision is zero 
                // and the # flag is not specified, no decimal-point character appears. 
                // If a decimal-point character appears, at least one digit appears before it. 
                // The value is rounded to the appropriate number of digits.
                //
                // A double argument representing an infinity is converted in one of the 
                // styles [-]inf or [-]infinity  which style is implementation-defined. 
                // A double argument representing a NaN is converted in one of the styles
                // [-]nan or [-]nan(n-char-sequence)  which style, and the meaning of
                // any n-char-sequence, is implementation-defined. The F conversion specifier
                // produces INF, INFINITY, or NAN instead of inf, infinity, or nan,
                // respectively.)

                FcvtBuf(dValue, nPrecision, &nDecimalPoint, &nSign, pBufferCvt);
                nBufferLength = (int)Strlen(pBufferCvt);

                // If the 'alternative form' is set, then always show a decimal.
                if(fd.mbAlternativeForm && (nDecimalPoint >= nBufferLength) && !bStripPointlessDecimal)
                    *--pCurrent16 = (char16_t)fd.mDecimalPoint;

                // Write the values that are after the decimal point.
                const char16_t* const pDecimalPoint  = pBufferCvt + nDecimalPoint - 1;
                const char16_t*       pCurrentSource = pBufferCvt + nBufferLength - 1;

                if((pCurrentSource - pDecimalPoint) > nPrecision) // If dValue is very small, this may be true.
                    pCurrentSource = pDecimalPoint + nPrecision;

                while(pCurrentSource > pDecimalPoint)
                {
                    char16_t c;

                    if((pCurrentSource >= pBufferCvt) && (pCurrentSource <= (pBufferCvt + nBufferLength)))
                        c = *pCurrentSource;
                    else
                        c = '0';

                    if(c != '0') // As we move right to left, as soon as we encounter a non-'0', we are done with trialing zeroes.
                        bStripTrailingZeroes = false;

                    if((c != '0') || !bStripTrailingZeroes)
                        *--pCurrent16 = c;
                    --pCurrentSource;
                }

                // Write the decimal point.
                if(*pCurrent16 || !bStripPointlessDecimal) // If bStripPointlessDecimal is true, then draw decimal only if there is something after it.
                {
                    if(nDecimalPoint < nBufferLength) // The standard specifies to not write the decimal point if the precision is zero. 
                        *--pCurrent16 = (char16_t)fd.mDecimalPoint;
                }

                // Write the values that are before the decimal point.
                if(nDecimalPoint > 0)
                {
                    pCurrentSource = pBufferCvt + nDecimalPoint;

                    while(pCurrentSource > pBufferCvt)
                        *--pCurrent16 = *--pCurrentSource;
                }
                else
                    *--pCurrent16 = '0'; // Write the "0" before the decimal point, as in "0.1234".
                break;
            } // case f:
        } // switch

        // Write a sign character.
        if(nSign)
            *--pCurrent16 = '-';
        else if(fd.mSign == kSignMinusPlus)
            *--pCurrent16 = '+';
        else if(fd.mSign == kSignSpace)
            *--pCurrent16 = ' ';

        // Write leading spaces.
        if(fd.mAlignment == kAlignmentRight)
        {
            // Write in any leading spaces as required by the width specifier (or the zero fill alignment option). 
            int nWidth = (int)(intptr_t)(pBufferEnd16 - pCurrent16);

            while(nWidth < fd.mnWidth)
            {
                *--pCurrent16 = (char16_t)' ';
                ++nWidth;
            }
        }
        pResult16 = pCurrent16;
    }

    return pResult16;
}


///////////////////////////////////////////////////////////////////////////////
// VprintfCore
//
int VprintfCore(WriteFunction16 pWriteFunction16, void* EA_RESTRICT pWriteFunctionContext16, const char16_t* EA_RESTRICT pFormat, va_list arguments)
{
    using namespace SprintfLocal;

    const char16_t*     pFormatCurrent = pFormat;   // Current position within entire format string.
    const char16_t*     pFormatSpec;                // Current format specification (e.g. "%3.2f").
    FormatData          fd;
    int                 nWriteCount;
    int                 nWriteCountSum = 0;
    int                 nWriteCountCurrent;
    char16_t            pBuffer16[kConversionBufferSize + 1]; // The +1 isn't necessary but placates code analysis tools.
    char16_t* const     pBufferEnd16 = pBuffer16 + kConversionBufferSize;
    const char16_t*     pBufferData16 = NULL;      // Where within pBuffer16 the data we are interested in begins.
    long                lValue = 0;                // All known supported platforms have 'long' support in hardware. 'int' is always only 32 bits (even on 64 bit systems).
    unsigned long       ulValue = 0;               // 
    long long           llValue = 0;               // Most compilers support 'long long' at this point. VC++ v6 and earlier are notable exceptions.
    unsigned long long  ullValue = 0;              // 

    pWriteFunction16(NULL, 0, pWriteFunctionContext16, kWFSBegin);

    // We walk through the format string and echo characters to the output until we 
    // come across a % specifier, at which point we process it and then move on as before.
    while(*pFormatCurrent)
    {
        // Find the next format specification (or end of the string).
        pFormatSpec = pFormatCurrent;
        while(*pFormatSpec && (*pFormatSpec != '%'))
            ++pFormatSpec;

        // Write out non-formatted text
        nWriteCount = (int)(pFormatSpec - pFormatCurrent);
        if(nWriteCount)
        {
            if(pWriteFunction16(pFormatCurrent, (size_t)nWriteCount, pWriteFunctionContext16, kWFSIntermediate) == -1)
                goto FunctionError; // This is an error; not the same as running out of space.
            nWriteCountSum += nWriteCount;
            pFormatCurrent  = pFormatSpec;
        }

        if(*pFormatSpec)
        {
            pFormatCurrent = ReadFormat16(pFormatSpec, &fd, VA_LIST_REFERENCE(arguments));

            switch(fd.mnType)
            {
                case 'd':    // These are signed values.
                case 'i':    // The standard specifies that 'd' and 'i' are identical.
                {
                    if(fd.mModifier == kModifierLongLong)
                        llValue = va_arg(arguments, long long); // If the user didn't pass a long long, unexpected behaviour will occur.
                    else if((fd.mModifier == kModifierLong) || (fd.mModifier == kModifierLongDouble)) // It is questionable whether we should allow %Ld here as we do. The standard doesn't define this behaviour.
                        lValue = va_arg(arguments, long);
                    else if(fd.mModifier == kModifierInt64)
                    {
                        if(sizeof(int64_t) == sizeof(long))
                        {
                            // fd.mModifier == kModifierLong; -- Not necessary, as the logic below doesn't need this.
                            lValue = va_arg(arguments, long);
                        }
                        else if(sizeof(int64_t) == sizeof(long long))
                        {
                            fd.mModifier = kModifierLongLong;
                            llValue = va_arg(arguments, long long);
                        }
                    }
                    else if(fd.mModifier == kModifierInt128)
                    {
                        if(sizeof(int64_t) < sizeof(long long)) // If long long is 128 bits... (we don't test sizeof(int128_t) because there may be no such thing. Hopefully there is no int96_t.
                            llValue = va_arg(arguments, long long);
                        else
                        {
                            // We have a problem here. The user wants to print a 128 bit value but 
                            // there is no built-in type to support this. For the time being, we 
                            // simply use only 64 bits of data. If we really need this, we can
                            // add the functionality later. We have the EAStdC int128_t type we can use.
                            // I don't think calling two 64 bit va_args is the same as what a single
                            // 128 bit arg would be. If we are using EAStdC int128_t then we handle the 
                            // value the same as passing a struct by value. And that's compiler/ABI-specific.
                            llValue = va_arg(arguments, long long);
                            llValue = va_arg(arguments, long long);
                        }
                    }
                    else // else we have kModifierChar, kModifierShort, kModifierInt8, kModifierInt16, kModifierInt32.
                    {
                        // COMPILE_TIME_ASSERT(sizeof(int32_t) <= sizeof(int));
                        lValue = va_arg(arguments, int);
                        if((fd.mModifier == kModifierShort) || (fd.mModifier == kModifierInt16))
                            lValue = (long)(signed short)lValue; // We carefully do our casting here in order to preserve intent.
                        else if((fd.mModifier == kModifierChar) || (fd.mModifier == kModifierInt8))
                            lValue = (long)(signed char)lValue;  // We carefully do our casting here in order to preserve intent.
                    }

                    if(fd.mModifier == kModifierLongLong)
                    {
                        pBufferData16 = WriteLongLong16(fd, llValue, pBufferEnd16);
                        if(!pBufferData16)
                            goto FormatError;
                    }
                    else
                    {
                        pBufferData16 = WriteLong16(fd, lValue, pBufferEnd16);
                        if(!pBufferData16)
                            goto FormatError;
                    }

                    nWriteCount = (int)((pBufferEnd16 - pBufferData16) - 1); // -1 because the written string is 0-terminated and we don't want to write the final 0.
                    break;
                }

                case 'b': // 'b' means binary. This is a convenient extension that we provide.
                case 'o': // These are unsigned values.
                case 'u':
                case 'x':
                case 'X':
                {
                    if(fd.mModifier == kModifierLong)
                        ulValue = va_arg(arguments, unsigned long);
                    else if(fd.mModifier == kModifierLongLong)
                        ullValue = va_arg(arguments, unsigned long long);
                    else if(fd.mModifier == kModifierInt64)
                    {
                        if(sizeof(uint64_t) == sizeof(unsigned long))
                        {
                            // fd.mModifier == kModifierLong; -- Not necessary, as the logic below doesn't need this.
                            ulValue = va_arg(arguments, unsigned long);
                        }
                        else if(sizeof(uint64_t) == sizeof(unsigned long long))
                        {
                            fd.mModifier = kModifierLongLong;
                            ullValue = va_arg(arguments, unsigned long long);
                        }
                    }
                    else if(fd.mModifier == kModifierInt128)
                    {
                        if(sizeof(uint64_t) < sizeof(unsigned long long)) // If long long is 128 bits... (we don't test sizeof(int128_t) because there may be no such thing. Hopefully there is no int96_t.
                            ullValue = va_arg(arguments, unsigned long long);
                        else
                        {
                            // We have a problem here. The user wants to print a 128 bit value but 
                            // there is no built-in type to support this. For the time being, we 
                            // simply use only 64 bits of data. If we really need this, we can
                            // add the functionality later.
                            #ifdef EA_SYSTEM_BIG_ENDIAN
                                     (void)va_arg(arguments, unsigned long long);
                                ullValue = va_arg(arguments, unsigned long long);
                            #else
                                ullValue = va_arg(arguments, unsigned long long);
                                     (void)va_arg(arguments, unsigned long long);
                            #endif
                        }
                    }
                    else // else we have kModifierChar, kModifierShort, kModifierInt8, kModifierInt16, kModifierInt32.
                    {
                        ulValue = va_arg(arguments, unsigned int);
                        if((fd.mModifier == kModifierShort) || (fd.mModifier == kModifierInt16))
                            ulValue = (unsigned long)(unsigned short)ulValue; // We carefully do our casting here in order to preserve intent.
                        else if((fd.mModifier == kModifierChar) || (fd.mModifier == kModifierInt8))
                            ulValue = (unsigned long)(unsigned char)ulValue;  // We carefully do our casting here in order to preserve intent.
                    }

                    if(fd.mModifier == kModifierLongLong)
                    {
                        pBufferData16 = WriteLongLong16(fd, (long long)ullValue, pBufferEnd16);
                        if(!pBufferData16)
                            goto FormatError;
                    }
                    else
                    {
                        pBufferData16 = WriteLong16(fd, (long)ulValue, pBufferEnd16);
                        if(!pBufferData16)
                            goto FormatError;
                    }

                    nWriteCount = (int)((pBufferEnd16 - pBufferData16) - 1); // -1 because the written string is 0-terminated and we don't want to write the final 0.
                    break;
                }

                case 'e':
                case 'E':
                case 'f':
                case 'F':
                case 'g':
                case 'G':
                case 'a': // See the C99 standard, section 7.19.6.1.8, for details on 'a' formatting.
                case 'A':
                {
                    double dValue;
                    if(fd.mModifier == kModifierLongDouble)
                        dValue = va_arg(arguments, double);
                    else
                        dValue = va_arg(arguments, double); // Since on most systems long double is the same as double, it's really no big deal to just work with long double, much like we do with long int instead of int above.

                    pBufferData16 = WriteDouble16(fd, dValue, pBufferEnd16);
                    if(!pBufferData16)
                        goto FormatError;

                    nWriteCount = (int)((pBufferEnd16 - pBufferData16) - 1); // -1 because the written string is 0-terminated and we don't want to write the final 0.
                    break;
                }

                case 's':
                case 'S':
                {
                    int stringTypeSize;

                    switch (fd.mModifier)
                    {
                        case kModifierInt8:         // If the user specified %I8s or %I8S
                        case kModifierChar:         // If the user specified %hs or %hS or kModifierWChar was chosen implicitly for other reasons.
                            stringTypeSize = 1;
                            break;

                        case kModifierInt16:        // If the user specified %I16s or %I16S
                            stringTypeSize = 2;
                            break;

                        case kModifierInt32:        // If the user specified %I32s or %I32S
                            stringTypeSize = 4;
                            break;

                        case kModifierWChar:        // If the user specified %ls or %lS or kModifierWChar was chosen implicitly for other reasons.
                           stringTypeSize = sizeof(wchar_t);
                           break;

                        default:                    // If the user specified %I64s or %I64S or another invalid size.
                            goto FormatError;
                    }

                    switch (stringTypeSize)
                    {
                        case 1:
                        {
                            const char* pBufferData8 = va_arg(arguments, char8_t*);

                            // I don't see the C99 standard specifying the behaviour for a NULL string pointer, 
                            // but both GCC and MSVC use "(null)" when such a NULL pointer is encountered.
                            if(pBufferData8 == NULL)
                                pBufferData8 = kStringNull8;

                            // For strings, the precision modifier refers to the number of chars to display.
                            if(fd.mnPrecision != kNoPrecision) // If the user specified some precision...
                            {
                                // Find which is shorter, the length or the precision.
                                const char8_t*       pBufferCurrent8 = pBufferData8;
                                const char8_t* const pBufferMax8     = pBufferData8 + fd.mnPrecision;

                                while(*pBufferCurrent8 && (pBufferCurrent8 < pBufferMax8))
                                    ++pBufferCurrent8;
                                nWriteCount = (int)(pBufferCurrent8 - pBufferData8);
                            }
                            else
                            {
                                // Set the write count to be the string length. 
                                // Don't call strlen, as that would jump outside this module.
                                const char8_t* pBufferCurrent8 = pBufferData8;

                                while(*pBufferCurrent8) // Implement a small inline strlen.
                                    ++pBufferCurrent8;
                                nWriteCount = (int)(pBufferCurrent8 - pBufferData8);
                            }

                            // We have a problem here. We need to convert a char8_t string to a char16_t string but 
                            // there is only so much space (kConversionBufferSize) for the conversion. Should 
                            // we allocate memory via operator new[] here if nWriteCount > kConversionBufferSize? 
                            // Also, what do we do about string encodings? We assume the source is UTF8.
                            if(nWriteCount >= kConversionBufferSize)
                            {
                                EA_ASSERT(nWriteCount < kConversionBufferSize);
                                goto FormatError;
                            }

                            nWriteCount = Strlcpy(pBuffer16, pBufferData8, (size_t)(unsigned)kConversionBufferSize, (size_t)(unsigned)nWriteCount);

                            if(nWriteCount < 0) // If there was a conversion error...
                            {
                                pBuffer16[0] = 0;
                                goto FormatError;
                            }

                            pBufferData16 = pBuffer16;
                            break;
                        } // case 1

                        case 2:
                        {
                            pBufferData16 = va_arg(arguments, char16_t*);

                            // I don't see the C99 standard specifying the behaviour for a NULL string pointer, 
                            // but both GCC and MSVC use "(null)" when such a NULL pointer is encountered.
                            if(pBufferData16 == NULL)
                                pBufferData16 = kStringNull16;

                            // For strings, the precision modifier refers to the number of chars to display.
                            if(fd.mnPrecision != kNoPrecision) // If the user specified some precision...
                            {
                                // Find which is shorter, the length or the precision.
                                const char16_t*       pBufferCurrent16 = pBufferData16;
                                const char16_t* const pBufferMax16     = pBufferData16 + fd.mnPrecision;

                                while(*pBufferCurrent16 && (pBufferCurrent16 < pBufferMax16))
                                    ++pBufferCurrent16;
                                nWriteCount = (int)(pBufferCurrent16 - pBufferData16);
                            }
                            else
                            {
                                // Set the write count to be the string length. 
                                // Don't call strlen, as that would jump outside this module.
                                const char16_t* pBufferCurrent16 = pBufferData16;

                                while(*pBufferCurrent16) // Implement a small inline strlen.
                                    ++pBufferCurrent16;
                                nWriteCount = (int)(pBufferCurrent16 - pBufferData16);
                            }
                            break;
                        } // case 2

                        case 4:
                        {
                            const char32_t* pBufferData32 = va_arg(arguments, char32_t*);

                            // I don't see the C99 standard specifying the behaviour for a NULL string pointer, 
                            // but both GCC and MSVC use "(null)" when such a NULL pointer is encountered.
                            if(pBufferData32 == NULL)
                                pBufferData32 = kStringNull32;

                            // For strings, the precision modifier refers to the number of chars to display.
                            if(fd.mnPrecision != kNoPrecision) // If the user specified some precision...
                            {
                                // Find which is shorter, the length or the precision.
                                const char32_t*       pBufferCurrent32 = pBufferData32;
                                const char32_t* const pBufferMax32     = pBufferData32 + fd.mnPrecision;

                                while(*pBufferCurrent32 && (pBufferCurrent32 < pBufferMax32))
                                    ++pBufferCurrent32;
                                nWriteCount = (int)(pBufferCurrent32 - pBufferData32);
                            }
                            else
                            {
                                // Set the write count to be the string length. 
                                // Don't call strlen, as that would jump outside this module.
                                const char32_t* pBufferCurrent32 = pBufferData32;

                                while(*pBufferCurrent32) // Implement a small inline strlen.
                                    ++pBufferCurrent32;
                                nWriteCount = (int)(pBufferCurrent32 - pBufferData32);
                            }

                            // We have a problem here. We need to convert a char32_t string to a char16_t string.
                            // We assume both are encoded as UCS2, because we don't currently support Unicode
                            // characters beyond U+FFFF. The reason we don't is that it provides extra weight that 
                            // no game software could conceivably use in any near time frame.
                            if(nWriteCount >= kConversionBufferSize)
                            {
                                EA_ASSERT(nWriteCount < kConversionBufferSize);
                                goto FormatError;
                            }

                            nWriteCount = Strlcpy(pBuffer16, pBufferData32, (size_t)(unsigned)kConversionBufferSize, (size_t)(unsigned)nWriteCount);

                            if(nWriteCount < 0) // If there was a conversion error...
                            {
                                pBuffer16[0] = 0;
                                goto FormatError;
                            }

                            pBufferData16 = pBuffer16;
                            break;

                        } // case 4

                    } // switch (stringTypeSize)

                    break;
                } // case 's'

                case 'n': // %n %hn %ln %lln %I64n %I32n %I16n, %I8n, %jn, %tn, %zn etc.
                {
                    // In this case, we write the numer of chars written so far to the passed in argument.
                    void* pBufferData = va_arg(arguments, void*);

                    switch(fd.mModifier)
                    {
                        case kModifierInt8:
                        case kModifierChar:
                            *(char8_t*)pBufferData = (char8_t)nWriteCountSum; 
                            break;

                        case kModifierInt16: 
                        case kModifierShort:
                            *(int16_t*)pBufferData = (int16_t)nWriteCountSum;
                            break;

                        case kModifierInt32:
                            *(int32_t*)pBufferData = (int32_t)nWriteCountSum;
                            break;

                        case kModifierInt64:
                            *(int64_t*)pBufferData = (int32_t)nWriteCountSum;
                            break;

                        case kModifierLong:
                            *(long*)pBufferData = (long)nWriteCountSum;
                            break;

                        case kModifierLongLong:
                            *(long long*)pBufferData = (long long)nWriteCountSum;
                            break;

                        case kModifierPtrdiff_t:
                            *(ptrdiff_t*)pBufferData = (ptrdiff_t)nWriteCountSum;
                            break;

                        case kModifierSize_t:
                            *(size_t*)pBufferData = (size_t)nWriteCountSum;
                            break;

                        case kModifierMax_t:
                            *(intmax_t*)pBufferData = (intmax_t)nWriteCountSum;
                            break;

                      //case kModifierInt128:       // We really should generate an error with this. It's nearly pointless to support it.
                      //    // Fall through
                      //
                      //case kModifierWChar:        // This should be impossible to encounter.
                      //case kModifierLongDouble:   // This should be impossible to encounter.
                      //    // Fall through

                        case kModifierNone:
                        default:
                            *(int*)pBufferData = (int)nWriteCountSum;
                            break;
                    }
                    continue; // Intentionally continue instead break.
                } // case 'n'

                case 'c':
                case 'C':
                {
                    int charTypeSize;

                    switch (fd.mModifier)
                    {
                        case kModifierInt8:         // If the user specified %I8c or %I8c
                        case kModifierChar:         // If the user specified %hc or %hC or kModifierWChar was chosen implicitly for other reasons.
                            charTypeSize = 1;
                            break;

                        case kModifierInt16:        // If the user specified %I16c or %I16C
                            charTypeSize = 2;
                            break;

                        case kModifierInt32:        // If the user specified %I32c or %I32C
                            charTypeSize = 4;
                            break;

                        case kModifierWChar:        // If the user specified %lc or %lC or kModifierWChar was chosen implicitly for other reasons.
                           charTypeSize = sizeof(wchar_t);
                           break;

                        default:                    // If the user specified %I64c or %I64C or another invalid size.
                            goto FormatError;
                    }

                    switch (charTypeSize)
                    {
                        case 1:
                        {
                            const char8_t c8 = (char8_t)va_arg(arguments, int);
                            pBuffer16[0] = (char16_t)(uint8_t)c8;
                            pBufferData16 = pBuffer16;
                            nWriteCount = 1;
                            break;
                        }
                        case 2:
                        {
                            pBuffer16[0] = (char16_t)va_arg(arguments, int); // We make the assumption here that sizeof(char16_t) is <= sizeof(int) and thus that a char16_t argument was promoted to int.
                            pBufferData16 = pBuffer16;
                            nWriteCount = 1;
                            EA_ASSERT(sizeof(*pBufferData16) == sizeof(char16_t));
                            break;
                        }
                        case 4:
                        {
                            const char32_t c32 = (char32_t)va_arg(arguments, int);
                            pBuffer16[0] = (char16_t)(uint32_t)c32; // We are doing a UCS4 to UCS2 chop here. This is because we encode char16_t strings as UCS2 and not UTF16.
                            pBufferData16 = pBuffer16;
                            nWriteCount = 1;
                            break;
                        }
                    }

                    break;
                } // case 'c'

                case '%':
                {
                    // In this case we just write a single '%' char16_t to the output.
                    pBuffer16[0] = '%';
                    pBufferData16 = pBuffer16;
                    nWriteCount = 1;
                    break;
                }

                case kFormatError:
                default:
                    FormatError:
                    // We do what many printf implementations do here and simply print out the text
                    // as-is -- as if there wasn't any formatting specifier. This at least lets the
                    // user see what was (incorrectly) specified.
                    nWriteCount = (int)(pFormatCurrent - pFormatSpec);
                    nWriteCountSum+=nWriteCount;

                    if(nWriteCount && (pWriteFunction16(pFormatSpec, (size_t)nWriteCount, pWriteFunctionContext16, kWFSIntermediate) == -1))
                        goto FunctionError; // This is an error; not the same as running out of space.
                    continue; // Try to continue displaying further data.
            }

            nWriteCountCurrent = nWriteCount; // We will write at least as much nWriteCount, possibly more if the format specified a specific width.

            if(fd.mAlignment != kAlignmentLeft) // If we have right alignment or zero fill...
            {
                char16_t nFill;

                if(fd.mAlignment == kAlignmentZeroFill)
                {
                    nFill = '0';

                    if(pBufferData16 && ((*pBufferData16 == '+') || (*pBufferData16 == '-') || (*pBufferData16 == ' ')))
                    {    // Skip zero fill for leading sign character.
                        if(pWriteFunction16(pBufferData16, 1, pWriteFunctionContext16, kWFSIntermediate) == -1)
                            goto FunctionError; // This is an error; not the same as running out of space.
                        --nWriteCount;
                        ++pBufferData16;
                    }
                }
                else
                    nFill = ' ';

                while(nWriteCountCurrent < fd.mnWidth)
                {
                    // Consider making an optimization which writes more than one fill character at a time.
                    // We can do this by using the space at the beginning of pBuffer16;
                    if(pWriteFunction16(&nFill, 1, pWriteFunctionContext16, kWFSIntermediate) == -1)
                        goto FunctionError; // This is an error; not the same as running out of space.
                    ++nWriteCountCurrent;
                }
            }

            if(nWriteCount && (pWriteFunction16(pBufferData16, (size_t)nWriteCount, pWriteFunctionContext16, kWFSIntermediate) == -1))
                goto FunctionError; // This is an error; not the same as running out of space.

            if(fd.mAlignment == kAlignmentLeft) // If we have left alignment... fill in space to the right of the data.
            {
                const char16_t nSpace = ' ';
                while(nWriteCountCurrent < fd.mnWidth)
                {
                    if(pWriteFunction16(&nSpace, 1, pWriteFunctionContext16, kWFSIntermediate) == -1)
                        goto FunctionError; // This is an error; not the same as running out of space.
                    ++nWriteCountCurrent;
                }
            }

            nWriteCountSum += nWriteCountCurrent;

        } // if(*pFormatSpec)

    } // while(*pFormatCurrent)

    pWriteFunction16(NULL, 0, pWriteFunctionContext16, kWFSEnd);
    return nWriteCountSum;

FunctionError:
    pWriteFunction16(NULL, 0, pWriteFunctionContext16, kWFSEnd);
    return -1;
}


///////////////////////////////////////////////////////////////////////////////
// 32 bit version
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// ReadFormat32
//
// Reads the current format into FormatData. Return value is pointer to first
// char32_t after the format data.
//
// To know how printf truly needs to work, see the ISO C 1999 standard, section 7.19.6.1.
// See http://www.cplusplus.com/ref/cstdio/printf.html or http://www.opengroup.org/onlinepubs/007908799/xsh/fprintf.html 
// for decent basic online documentation about how printf is supposed to work.
// 
// Argument pFormat is a string pointing to a % format specification of the form:
//        %[flags][width][.precision][modifiers]type
//
///////////////////////////////////////////////////////////////////////////////
//
const char32_t* ReadFormat32(const char32_t* EA_RESTRICT pFormat, SprintfLocal::FormatData* EA_RESTRICT pFormatData, va_list* EA_RESTRICT pArguments)
{
    using namespace SprintfLocal;

    const char32_t* pFormatCurrent       = pFormat;
    Alignment       alignmentNonZeroFill = kAlignmentLeft; // We have a chicken and egg problem in that the zero-fill alignment may or may not be ignored. So we save the value here for what the alignment would be if zero-fill needs to be ignored.
    FormatData      fd;
    char32_t        c;

    // Check for "%%". This is a quick test for early exit.
    if((c = *++pFormatCurrent) == '%')    // If the user specified "%%"...
    {
        fd.mnType = '%';
        *pFormatData = fd;    // pFormatData->mnType = '%'; Consider instead using just this line of code.
        return pFormatCurrent + 1;
    }

    // Check for flags field
    for(; ; (c = *++pFormatCurrent)) // Check for one or more flags ('-', '+', ' ', '#', or '0')
    {
        switch(c)
        {
            case '-': // '-' controls alignment, not the +/- sign before numbers.
                fd.mAlignment = kAlignmentLeft;
                break;

            case '+':
                fd.mSign = kSignMinusPlus;
                break;

            case ' ':    // The C99 language states (7.19.6.1.6): "If the space and + flags both appear, the space flag is ignored."
                if(fd.mSign != kSignMinusPlus)
                   fd.mSign  = kSignSpace;
                break;

            case '#':    // The C99 standard states (7.19.6.1.6): The result is converted to an "alternative form."
                fd.mbAlternativeForm = true; 
                break;

            case '0':    // The C99 standard states (7.19.6.1.6): If the 0 and - flags both appear, the 0 flag is ignored. For d, i, o, u, x, and X conversions, if a precision is specified, the 0 flag is ignored. For other conversions, the behavior is undefined.
                if(fd.mAlignment != kAlignmentLeft)     // Note that '0' is a flag (which can appear in any order) and not part of the number. This is a common misconception.
                {
                    if(fd.mAlignment != kAlignmentZeroFill) // The C99 standard says that for string fields, 0 fill means space fill.
                        alignmentNonZeroFill = fd.mAlignment;
                    fd.mAlignment  = kAlignmentZeroFill;
                }
                break;

            default:
                goto EndFlagCheck; // C/C++ unfortunately don't provide an efficient mechanism to break from multiple loops other than 'goto'. We could avoid the goto with alternative logic, but that would be less efficient.
        }
    }
    EndFlagCheck:

    // Check for width field. 
    // The C99 standard states (7.19.6.1.5): A field width, or precision, or both, may be 
    // indicated by an asterisk. In this case, an int argument supplies the field width or 
    // precision. The arguments specifying field width, or precision, or both, shall appear 
    // (in that order) before the argument (if any) to be converted. A negative field 
    // width argument is taken as a - flag followed by a positive field width. 
    // A negative precision argument is taken as if the precision were omitted.
    if(c == '*')
    {
        fd.mnWidth = va_arg(*pArguments, int);
        if(fd.mnWidth < 0)
        {
            fd.mAlignment = kAlignmentLeft; // Pretend that a '-' flag was applied, as specified by the standard.
            fd.mnWidth    = -fd.mnWidth;
        }
        c = *++pFormatCurrent;
    }
    else
    {
        // Read the width numerical value. We don't do error checking here as it 
        // would incur a performance penalty that just isn't worth it to us.
        while(((unsigned)(c - '0')) < 10)    // Don't call isdigit() here because that might cause a data cache miss.
        {
            fd.mnWidth = (int)((fd.mnWidth * 10) + (c - '0')); // Consider if there is any way to make this loop more 
            c = *++pFormatCurrent;                             // efficient by reducing multiplies, etc.
        }
    }

    if(fd.mnWidth > kMaxWidth)
    {
        // Note that we leave fd.mnType as zero, indicating an error.
        *pFormatData = fd; // pFormatData->mnType = 0; Consider instead using just this line of code.
        return pFormatCurrent + 1;
    }

    // Check for precision field.
    // An optional precision that gives the minimum number of digits to appear for the 
    // d, i, o, u, x, and X conversions, the number of digits to appear after the decimal-point
    // character for a, A, e, E, f, and F conversions, the maximum number of significant
    // digits for the g and G conversions, or the maximum number of bytes to be written for
    // s conversions. The precision takes the form of a period (.) followed either by an
    // asterisk * (described later) or by an optional decimal integer; if only the period 
    // is specified, the precision is taken as zero. If a precision appears with any other
    // conversion specifier, the behavior is undefined.
    if(c == (char32_t)pFormatData->mDecimalPoint) // If precision is specified...
    {
        if((c = *++pFormatCurrent) == '*') // If the precision is set as a value passed in as an argument...
        {
            fd.mnPrecision = va_arg(*pArguments, int);
            if(fd.mnPrecision < 0)
                fd.mnPrecision = 0;
            c = *++pFormatCurrent;
        }
        else
        {
            fd.mnPrecision = 0;
            while(((unsigned)(c - '0')) < 10) // Don't call isdigit() here because that might cause a data cache miss.
            {
                // Consider doing error checking 
                fd.mnPrecision = (int)((fd.mnPrecision * 10) + (c - '0'));
                c = *++pFormatCurrent;
            }
        }
    }

    // Check for length modifier field. C99 standard section 7.19.6.1.7.
    // We support the following modifiers, which include non-standard integer size-specific modifiers.
    //     hh, h, l, ll, I8, I16, I32, I64, I128
    bool bModifierPresent = true; // True until proven false below.

    switch(c)
    {
        case 'h':
            if(pFormatCurrent[1] == 'h') // If the user specified %hh ...
            {
                // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a signed char or unsigned char argument (the argument will have been promoted according to the integer promotions, but its value shall be converted to signed char or unsigned char before printing); or that a following n conversion specifier applies to a pointer to a signed char argument.
                fd.mModifier = kModifierChar;
                c = *++pFormatCurrent;
            }
            else // Else the user specified just %h
            {
                // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a short int or unsigned short int argument (the argument will have been promoted according to the integer promotions, but its value shall be converted to short int or unsigned short int before printing); or that a following n conversion specifier applies to a pointer to a short int argument.
                fd.mModifier = kModifierShort;
            }
            break;

        case 'l': // Check for ell (not one).
            if(pFormatCurrent[1] == 'l') // If the user specified %ll ...
            {
                // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a long long int or unsigned long long int argument; or that a following n conversion specifier applies to a pointer to a long long int argument.
                fd.mModifier = kModifierLongLong;
                c = *++pFormatCurrent;
            }
            else // Else the user specified just %l
            {
                // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a long int or unsigned long int argument; that a following n conversion specifier applies to a pointer to a long int argument; that a following c conversion specifier applies to a wint_t argument; that a following s conversion specifier applies to a pointer to a wchar_t argument; or has no effect on a following a, A, e, E, f, F, g, or G conversion specifier.
                fd.mModifier = kModifierLong;
            }
            break;

        case 'q': 
            // BSD-based OS's use %q to indicate "quad int", which is the same as "long long". We need to support it because iPhone's C99 headers define PRId64 as "qd". 
            fd.mModifier = kModifierLongLong;
            break;

        case 'j':
            // Specifies that a following d, i, o, u, x, or X conversion specifier applies to an intmax_t or uintmax_t argument; or that a following n conversion specifier applies to a pointer to an intmax_t argument.
            fd.mModifier = kModifierMax_t;
            break;

        case 'z':
            // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a size_t or the corresponding signed integer type argument; or that a following n conversion specifier applies to a pointer to a signed integer type corresponding to size_t argument.
            fd.mModifier = kModifierSize_t;
            break;

        case 't':
            // Specifies that a following d, i, o, u, x, or X conversion specifier applies to a ptrdiff_t or the corresponding unsigned integer type argument; or that a following n conversion specifier applies to a pointer to a ptrdiff_t argument.
            fd.mModifier = kModifierPtrdiff_t;
            break;

        case 'L':
            // Specifies that a following a, A, e, E, f, F, g, or G conversion specifier applies to a long double argument.
            fd.mModifier = kModifierLongDouble;
            break;

        case 'I':
            if(pFormatCurrent[1] == '8') // If the user specified %I8 ...
            {
                fd.mModifier = kModifierInt8;
                c = *++pFormatCurrent; // Account for the '8' part of I8. We'll account for the 'I' part below for all formats.
            }
            else if((pFormatCurrent[1] == '1') && (pFormatCurrent[2] == '6'))
            {
                fd.mModifier = kModifierInt16;                    
                c = *(pFormatCurrent += 2);
            }
            else if((pFormatCurrent[1] == '3') && (pFormatCurrent[2] == '2'))
            {
                fd.mModifier = kModifierInt32;                    
                c = *(pFormatCurrent += 2);
            }
            else if((pFormatCurrent[1] == '6') && (pFormatCurrent[2] == '4'))
            {
                fd.mModifier = kModifierInt64;                    
                c = *(pFormatCurrent += 2); // Account for the '64' part of I64. We'll account for the 'I' part below for all formats.
            }
            else if((pFormatCurrent[1] == '1') && (pFormatCurrent[2] == '2') && (pFormatCurrent[3] == '8'))
            {
                fd.mModifier = kModifierInt128;                    
                c = *(pFormatCurrent += 3);
            }
            else // Else the specified modifier was invalid.
            {
                // Note that we leave fd.mnType as zero, indicating an error.
                *pFormatData = fd; // pFormatData->mnType = kFormatError; // Consider instead using just this line of code.
                return pFormatCurrent + 1;
            }
            break;

        default:
            bModifierPresent = false;
    }

    if(bModifierPresent)
        c = *++pFormatCurrent; // Move the pointer past the format (e.g. the 'f' in "%3.1f")

    // Read the conversion type. This must be present.
    fd.mnType = (int)c;

    switch(c)
    {
        case 'b': // unsigned binary. This is a convenient extension that we add.
        case 'd': // signed
        case 'i': // signed
        case 'u': // unsigned
        case 'o': // unsigned
        case 'x': // unsigned
        case 'X': // unsgined
            if(fd.mnPrecision == kNoPrecision)
               fd.mnPrecision = 1;
            else if(fd.mAlignment == kAlignmentZeroFill)
                fd.mAlignment = kAlignmentRight;
            break;

        case 'g':
        case 'G':
            if(fd.mnPrecision == 0) // For %g, if the precision is zero, it is taken as 1.
               fd.mnPrecision = 1;
            // fall through
        case 'e':
        case 'E':
        case 'f':
        case 'F':
        case 'a':  // See the C99 standard, section 7.19.6.1.8, for details on 'a' formatting.
        case 'A':
            if(fd.mnPrecision == kNoPrecision)
               fd.mnPrecision = 6;    // The C99 standard explicitly states that this defaults to 6.
            break;

        case 'p':
            if(sizeof(void*) == 2)
                fd.mModifier = kModifierInt16;
            else if(sizeof(void*) == 4)
                fd.mModifier = kModifierInt32;
            else
                fd.mModifier = kModifierInt64;
            fd.mnPrecision = sizeof(void*) / 4;  // This is 8 for a 32 bit pointer, 16 for a 64 bit pointer.
            fd.mnType      = 'x';

            // For the "alternative form" of x (or X) conversion, a nonzero result has 0x (or 0X) prefixed to it.
            // So if the user uses %#p, then the user gets something like 0x12345678, whereas otherwise the 
            // user gets just 12345678.

            break;

        case 'c': // We accept %hc, %c, %lc, %I8c, %I16c, %I32c (regular, regular, wide, char8_t, char16_t, char32_t)
        case 'C': // We accept %hC, %C, %lC, %I8C, %I16C, %I32C (regular, wide,    wide, char8_t, char16_t, char32_t)
        case 's': // We accept %hs, %s, %ls, %I8s, %I16s, %I32s (regular, regular, wide, char8_t, char16_t, char32_t)
        case 'S': // We accept %hS, %S, %lS, %I8s, %I16s, %I32s (regular, wide,    wide, char8_t, char16_t, char32_t)
            // If the user specified zero-fill above, then it is a mistake and we 
            // need to use spaces instead. So we restore the fallback alignment.
            if(fd.mAlignment == kAlignmentZeroFill)
                fd.mAlignment = alignmentNonZeroFill;

            // Microsoft's library goes against the standard: %s is not 
            // interpreted to mean char8_t string but instead is interpreted 
            // to be either char8_t or wchar_t depending on what the output
            // text format is. This is non-standard but has the convenience
            // of allowing users to migrate between char8_t and wchar_t usage
            // more easily. So we allow EASPRINTF_MS_STYLE_S_FORMAT to control this.
            if(fd.mModifier == kModifierShort)
               fd.mModifier =  kModifierChar;
            else if(fd.mModifier == kModifierLong)
                fd.mModifier = kModifierWChar;
            else if(fd.mModifier == kModifierNone) // If the user hasn't already specified, for example %I16.
            {
                #if EASPRINTF_MS_STYLE_S_FORMAT
                    if(c == 's')
                        fd.mModifier = (sizeof(*pFormat) == sizeof(char)) ? kModifierChar : kModifierWChar;
                    else
                        fd.mModifier = (sizeof(*pFormat) == sizeof(char)) ? kModifierWChar : kModifierChar;
                #else
                    if(c == 's')
                        fd.mModifier = kModifierChar;
                    else
                        fd.mModifier = kModifierWChar;
                #endif
            }
            //else if((fd.mModifier < kModifierInt8) || (fd.mModifier > kModifierInt32)) // This expression assumes that Int8, Int16, Int32 are contiguous enum values.
            //{
            //    EA_FAIL_MSG("Printf: Invalid %s modifier");
            //}
            break;

        case 'n':
            // The argument shall be a pointer to signed integer into which is written the 
            // number of characters written to the output stream so far by this call to printf. 
            // No argument is converted, but one is consumed. If the conversion specification 
            // includes any flags, a field width, or a precision, the behavior is undefined.

            // We don't really have anything to do here, as this function is merely reading
            // the format and not acting on it. The caller will act on this appropriately.
            break;
    }

    // If the field width is too long and it's not a string field...
    if((fd.mnPrecision > kMaxPrecision) && (fd.mnPrecision != kNoPrecision) && ((fd.mnType != 's') && (fd.mnType != 'S')))
        fd.mnType = kFormatError;

    // Note that at his point we haven't read the argument corresponding to the formatted value. 
    // We save this for the parent function, as otherwise we'd need some kind of union here to
    // hold all value types.
    *pFormatData = fd;
    return pFormatCurrent + 1;
}


///////////////////////////////////////////////////////////////////////////////
// WriteLong32
//
// Writes the given lValue to the given buffer and returns the start of the 
// data or returns NULL for error. Note that the buffer is passed in as the 
// end of the buffer and not the beginning. This is a common trick used when
// converting integer values to strings, as the conversion algorithm needs
// to work backwards as it is and it's quicker to simply start with the end
// of the buffer and move backwards.
//
char32_t* WriteLong32(const SprintfLocal::FormatData& fd, long lValue, char32_t* EA_RESTRICT pBufferEnd)
{
    using namespace SprintfLocal;

    unsigned long ulValue = (unsigned long)lValue;
    unsigned int  nBase;
    unsigned int  nShift = 0;
    unsigned int  nAnd = 0;
    Sign          sign = kSignNone;
    char32_t*     pCurrent = pBufferEnd;
    int           nDigitCount = 0;
    int           nDigitCountSum = fd.mnPrecision;
    bool          bNegative = false;

    *--pCurrent = 0;

    if((lValue > 0) || (fd.mnPrecision > 0) || fd.mbAlternativeForm)
    {
        // Do initial setup. 
        switch(fd.mnType)
        {
            case 'b': // Binary (this is non-standard, though many would like it to be so)
                nBase  = 2;
                nShift = 0x01;
                nAnd   = 0x01;
                break;

            case 'o': // Octal
                nBase  = 8;
                nShift = 0x03;
                nAnd   = 0x07;
                break;

            case 'd': // Decimal (signed)
            case 'i': // i and d are defined by the standard to be the same.
            default:
                nBase = 10;
                sign  = fd.mSign;
                if(lValue < 0)
                {
                    ulValue   = (unsigned long)-lValue;
                    bNegative = true;
                }
                break;

            case 'u': // Decimal (unsigned)
                nBase = 10;
                break;

            case 'x': // Hexidecimal
            case 'X':
                nBase  = 16;
                nShift = 0x04;
                nAnd   = 0x0f;
                break;
        }

        // Write the individual digits.
        do
        {
            // Optimization: Replace the % and / below with >> and & for cases where
            // we can do this (i.e. nBase = even power of two).
            int nDigit;

            if(nBase == 10)
            {
                nDigit   = (int)(ulValue%nBase);
                ulValue /= nBase;
            }
            else // Else take faster pathway.
            {
                nDigit = (int)(ulValue & nAnd);
                ulValue >>= nShift;
            }

            if(nDigit < 10)
               nDigit = '0' + nDigit;
            else
            {
                nDigit -= 10;
                if(fd.mnType == 'x')
                    nDigit = 'a' + nDigit;
                else
                    nDigit = 'A' + nDigit;
            }

            *--pCurrent = (char32_t)nDigit;
            ++nDigitCount;
        } while(ulValue > 0);

        // For octal mode, the standard specifies that when 'alternative form' is enabled, 
        // the number is prefixed with a zero. This is like how the C language interprets 
        // integers that begin with zero as octal. 
        if((nBase == 8) && fd.mbAlternativeForm && (*pCurrent != (char32_t)'0'))
        {
            *--pCurrent = (char32_t)'0';
            ++nDigitCount;
        }

        // Calculate any leading zeroes required by the 'zero fill' alignment option.
        if(fd.mAlignment == kAlignmentZeroFill) // If we are to precede the number with zeroes...
        {
            if(bNegative || (sign != kSignNone))
                nDigitCountSum = fd.mnWidth - 1; // Take into account the leading sign that we'll need to write.
            else if(fd.mbAlternativeForm && ((nBase == 2) || (nBase == 16)))
                nDigitCountSum = fd.mnWidth - 2; // Take into account the leading "0x" that we'll need to write.
            else
                nDigitCountSum = fd.mnWidth;
        }

        // Write in any leading zeroes as required by the precision specifier(or the zero fill alignment option). 
        while(nDigitCount < nDigitCountSum)
        {
            *--pCurrent = (char32_t)'0';
            ++nDigitCount;
        }

        // Potentially add the sign prefix, which might be either nothing, '-', '+', or ' '.
        if(nBase == 10) // Signs can only apply to decimal types.
        {
            if((fd.mnType == 'd') || (fd.mnType == 'i')) // The standard seems to say that only signed decimal types can have signs.
            {
                if(bNegative)
                    *--pCurrent = (char32_t)'-';
                else if(fd.mSign == kSignMinusPlus)
                    *--pCurrent = (char32_t)'+';
                else if(fd.mSign == kSignSpace)
                    *--pCurrent = (char32_t)' ';
            }
        }
        else if(fd.mbAlternativeForm && ((nBase == 2) || (nBase == 16)))
        {
            // Add the leading 0x, 0X, 0b, or 0B (for our binary extension).
            *--pCurrent = (char32_t)fd.mnType;
            *--pCurrent = (char32_t)'0';
        }
    }

    return pCurrent;
}


///////////////////////////////////////////////////////////////////////////////
// WriteLongLong32
//
// This function is identical to WriteLong except that it works with long long
// instead of long. It is a separate function because on many platforms the
// long long data type is larger than the (efficient) machine word size and is
// thus to be avoided if possible.
//
char32_t* WriteLongLong32(const SprintfLocal::FormatData& fd, long long lValue, char32_t* EA_RESTRICT pBufferEnd)
{
    using namespace SprintfLocal;

    #ifdef EA_PLATFORM_PLAYSTATION2
        // The PS2's long long is 128 bits and no mathematical operations are supported with it.
        // We could solve this by using the int128_t library (see Paul Pedriana), but for now we 
        // just map to long. Note that the PS3 uses a conventional 64 bit long long. 
        return WriteLong32(fd, (long)lValue, pBufferEnd);
    #else
        unsigned long long  ulValue = (unsigned long long)lValue;
        unsigned int        nBase;
        unsigned int        nShift = 0;
        unsigned int        nAnd = 0;
        Sign                sign = kSignNone;
        char32_t*           pCurrent = pBufferEnd;
        int                 nDigitCount = 0;
        int                 nDigitCountSum = fd.mnPrecision;
        bool                bNegative = false;

        *--pCurrent = 0;

        if((lValue > 0) || (fd.mnPrecision > 0) || fd.mbAlternativeForm)
        {
            // Do initial setup. 
            switch(fd.mnType)
            {
                case 'b': // Binary.
                    nBase  = 2;
                    nShift = 1;
                    nAnd   = 0x01;
                    break;

                case 'o':
                    nBase  = 8;
                    nShift = 3;
                    nAnd   = 0x07;
                    break;

                case 'd':
                case 'i':
                default:
                    nBase = 10;
                    sign  = fd.mSign;
                    if(lValue < 0)
                    {
                        ulValue   = (unsigned long long)-lValue;
                        bNegative = true;
                    }
                    break;

                case 'u':
                    nBase = 10;
                    break;

                case 'x':
                case 'X':
                    nBase  = 16;
                    nShift = 4;
                    nAnd   = 0x0f;
                    break;
            }

            // Write the individual digits.
            do
            {
                // Optimization: Replace the % and / below with >> and & for cases where
                // we can do this (i.e. nBase = even power of two).
                int nDigit;

                if(nBase == 10)
                {
                    nDigit   = (int)(ulValue % nBase);
                    ulValue /= nBase;
                }
                else // Else take faster pathway.
                {
                    nDigit  =  (int)(ulValue & nAnd);
                    ulValue >>= nShift;
                }

                if(nDigit < 10)
                   nDigit = '0' + nDigit;
                else
                {
                    nDigit -= 10;
                    if(fd.mnType == 'x')
                        nDigit = 'a' + nDigit;
                    else
                        nDigit = 'A' + nDigit;
                }

                *--pCurrent = (char32_t)nDigit;
                ++nDigitCount;
            } while(ulValue > 0);

            // For octal mode, the standard specifies that when 'alternative form' is enabled, the 
            // number is prefixed with a zero. This is like how the C language interprets integers
            // that begin with zero as octal. 
            if((nBase == 8) && fd.mbAlternativeForm && (*pCurrent != (char32_t)'0'))
            {
                *--pCurrent = (char32_t)'0';
                ++nDigitCount;
            }

            // Calculate any leading zeroes required by the 'zero fill' alignment option.
            if(fd.mAlignment == kAlignmentZeroFill) // If we are to precede the number with zeroes...
            {
                if(bNegative || (sign != kSignNone))
                    nDigitCountSum = fd.mnWidth - 1; // Take into account the leading sign that we'll need to write.
                else if(fd.mbAlternativeForm && ((nBase == 2) || (nBase == 16)))
                    nDigitCountSum = fd.mnWidth - 2; // Take into account the leading "0x" that we'll need to write.
                else
                    nDigitCountSum = fd.mnWidth;
            }

            // Write in any leading zeroes as required by the precision specifier(or the zero fill alignment option). 
            while(nDigitCount < nDigitCountSum)
            {
                *--pCurrent = (char32_t)'0';
                ++nDigitCount;
            }

            // Potentially add the sign prefix, which might be either nothing, '-', '+', or ' '.
            if(nBase == 10) // Signs can only apply to decimal types.
            {
                if((fd.mnType == 'd') || (fd.mnType == 'i')) // The standard seems to say that only signed decimal types can have signs.
                {
                    if(bNegative)
                        *--pCurrent = (char32_t)'-';
                    else if(fd.mSign == kSignMinusPlus)
                        *--pCurrent = (char32_t)'+';
                    else if(fd.mSign == kSignSpace)
                        *--pCurrent = (char32_t)' ';
                }
            }
            else if(fd.mbAlternativeForm && ((nBase == 2) || (nBase == 16)))
            {
                // Add the leading 0x, 0X, 0b, or 0B (for our binary extension).
                *--pCurrent = (char32_t)fd.mnType;
                *--pCurrent = (char32_t)'0';
            }
        }

        return pCurrent;
    #endif
}



///////////////////////////////////////////////////////////////////////////////
// WriteDouble32
//
char32_t* WriteDouble32(const SprintfLocal::FormatData& fd, double dValue, char32_t* EA_RESTRICT pBufferEnd32)
{
    using namespace SprintfLocal;

    // Check for nan or inf strings.
    if(IsNaN(dValue))
    {
        *--pBufferEnd32 = 0;
        if(fd.mnType >= 'a') // If type is f, e, g, a, and not F, E, G, A.
        {
            *--pBufferEnd32 = 'n';
            *--pBufferEnd32 = 'a';
            *--pBufferEnd32 = 'n';
        }
        else
        {
            *--pBufferEnd32 = 'N';
            *--pBufferEnd32 = 'A';
            *--pBufferEnd32 = 'N';
        }
        if(IsNeg(dValue))
            *--pBufferEnd32 = '-';
        return pBufferEnd32;
    }
    else if(IsInf(dValue))
    {
        *--pBufferEnd32 = 0;
        if(fd.mnType >= 'a') // If type is f, e, g, a, and not F, E, G, A.
        {
            *--pBufferEnd32 = 'f';
            *--pBufferEnd32 = 'n';
            *--pBufferEnd32 = 'i';
        }
        else
        {
            *--pBufferEnd32 = 'F';
            *--pBufferEnd32 = 'N';
            *--pBufferEnd32 = 'I';
        }
        if(IsNeg(dValue))
            *--pBufferEnd32 = '-';
        return pBufferEnd32;
    }

    // Regular processing.
    int       nType = fd.mnType;
    int       nPrecision = fd.mnPrecision;
    bool      bStripTrailingZeroes = false;      // If true, then don't write useless trailing zeroes, a with the three at the end of: "1.23000"
    bool      bStripPointlessDecimal = false;    // If true, then don't write a decimal point that has no digits after it, as with: "13."
    char32_t* pResult32 = NULL;

    *--pBufferEnd32 = 0;

    if(fd.mnPrecision <= kConversionBufferSize) // If there is enough space for the data...
    {
        int       nDecimalPoint, nSign, nExponent;
        char32_t  pBufferCvt[kFcvtBufMaxSize]; pBufferCvt[0] = 0;
        int       nBufferLength;
        char32_t* pCurrent32 = pBufferEnd32;

        switch(fd.mnType)
        {
            default :
            case 'g':
            case 'G':
            {
                // From section 7.19.6.1.8:
                // A double argument representing a floating-point number is converted in
                // style f or e (or in style F or E in the case of a G conversion specifier), with
                // the precision specifying the number of significant digits. If the precision is
                // zero, it is taken as 1. The style used depends on the value converted; style e
                // (or E) is used only if the exponent resulting from such a conversion is less
                // than -4 or greater than or equal to the precision. Trailing zeros are removed
                // from the fractional portion of the result unless the # flag is specified; a
                // decimal-point character appears only if it is followed by a digit.
                // 
                // A double argument representing an infinity or NaN is converted in the style
                // of an f or F conversion specifier.

                EcvtBuf(dValue, nPrecision, &nDecimalPoint, &nSign, pBufferCvt);
                nExponent = nDecimalPoint - 1; // Exponent can be a positive, zero, or negative value.

                if(!fd.mbAlternativeForm)
                    bStripTrailingZeroes = true;
                bStripPointlessDecimal = true;

                if(!((nExponent < -4) || (nExponent >= nPrecision)))
                {
                    if(nExponent >= 0) // If there are any digits to the left of the decimal...
                        nPrecision -= (nExponent + 1);
                    goto FType;
                }

                if(nType == 'g')
                    nType = 'e';
                else
                    nType = 'E';
                goto EContinuation;
            } // case g:

            case 'e':
            case 'E':
            {
                // From section 7.19.6.1.8:
                // A double argument representing a floating-point number is converted in the
                // style [-]d.ddd edd, where there is one digit (which is nonzero if the
                // argument is nonzero) before the decimal-point character and the number of
                // digits after it is equal to the precision; if the precision is missing, it is 
                // taken as 6; if the precision is zero and the # flag is not specified, no decimal-point
                // character appears. The value is rounded to the appropriate number of digits.
                // The E conversion specifier produces a number with E instead of e
                // introducing the exponent. The exponent always contains at least two digits,
                // and only as many more digits as necessary to represent the exponent. If the
                // value is zero, the exponent is zero.
                // 
                // A double argument representing an infinity or NaN is converted in the style
                // of an f or F conversion specifier.

                EcvtBuf(dValue, nPrecision + 1, &nDecimalPoint, &nSign, pBufferCvt);
                nExponent = nDecimalPoint - 1; // Exponent can be a positive, zero, or negative value.
                if(dValue == 0) // Should we instead compare dValue to a very small value?
                    nExponent = 0; // In this case we are working with the value 0, which is always displayed as 0.???e+00

            EContinuation:
                nBufferLength = (int)Strlen(pBufferCvt);

                // Write the exponent digits, at least two of them.
                int nExponentAbs = abs(nExponent);
                while(nExponentAbs > 0)
                {
                    *--pCurrent32 = (char32_t)('0' + (nExponentAbs % 10));
                    nExponentAbs /= 10;
                }
                if(pCurrent32 >= (pBufferEnd32 - 1)) // The C99 standard states that at least two zeroes be present.
                    *--pCurrent32 = '0';
                if(pCurrent32 >= (pBufferEnd32 - 1))
                    *--pCurrent32 = '0';

                // Write the decimal point sign, always + or -.
                if(nExponent >= 0)
                    *--pCurrent32 = '+';
                else
                    *--pCurrent32 = '-';

                // Write 'e' or 'E'.
                *--pCurrent32 = (char32_t)nType;

                // Write all digits but the first one.
                for(char32_t* pTemp = pBufferCvt + nBufferLength; pTemp > pBufferCvt + 1; )
                {
                    const char32_t c = *--pTemp;

                    if(c != '0') // As we move right to left, as soon as we encounter a non-'0', we are done with trialing zeroes.
                        bStripTrailingZeroes = false;
                    if((c != '0') || !bStripTrailingZeroes)
                        *--pCurrent32 = c;
                }

                // Write the decimal point.
                if((*pCurrent32 != (char32_t)nType) || !bStripPointlessDecimal) // If bStripPointlessDecimal is true, then draw decimal only if there are digits after it.
                {
                    if((nBufferLength > 1) || fd.mbAlternativeForm) // If the 'alternative form' is set, then always show a decimal.
                        *--pCurrent32 = (char32_t)fd.mDecimalPoint;
                }

                // Write the first digit.
                *--pCurrent32 = pBufferCvt[0];

                break;
            } // case e:

            case 'f':
            case 'F':
            FType:
            {
                // From section 7.19.6.1.8:
                // A double argument representing a floating-point number is converted to
                // decimal notation in the style [-]ddd.ddd, where the number of digits after
                // the decimal-point character is equal to the precision specification. 
                // If the precision is missing, it is taken as 6; if the precision is zero 
                // and the # flag is not specified, no decimal-point character appears. 
                // If a decimal-point character appears, at least one digit appears before it. 
                // The value is rounded to the appropriate number of digits.
                //
                // A double argument representing an infinity is converted in one of the 
                // styles [-]inf or [-]infinity  which style is implementation-defined. 
                // A double argument representing a NaN is converted in one of the styles
                // [-]nan or [-]nan(n-char-sequence)  which style, and the meaning of
                // any n-char-sequence, is implementation-defined. The F conversion specifier
                // produces INF, INFINITY, or NAN instead of inf, infinity, or nan,
                // respectively.)

                FcvtBuf(dValue, nPrecision, &nDecimalPoint, &nSign, pBufferCvt);
                nBufferLength = (int)Strlen(pBufferCvt);

                // If the 'alternative form' is set, then always show a decimal.
                if(fd.mbAlternativeForm && (nDecimalPoint >= nBufferLength) && !bStripPointlessDecimal)
                    *--pCurrent32 = (char32_t)fd.mDecimalPoint;

                // Write the values that are after the decimal point.
                const char32_t* const pDecimalPoint  = pBufferCvt + nDecimalPoint - 1;
                const char32_t*       pCurrentSource = pBufferCvt + nBufferLength - 1;

                if((pCurrentSource - pDecimalPoint) > nPrecision) // If dValue is very small, this may be true.
                    pCurrentSource = pDecimalPoint + nPrecision;

                while(pCurrentSource > pDecimalPoint)
                {
                    char32_t c;

                    if((pCurrentSource >= pBufferCvt) && (pCurrentSource <= (pBufferCvt + nBufferLength)))
                        c = *pCurrentSource;
                    else
                        c = '0';

                    if(c != '0') // As we move right to left, as soon as we encounter a non-'0', we are done with trialing zeroes.
                        bStripTrailingZeroes = false;

                    if((c != '0') || !bStripTrailingZeroes)
                        *--pCurrent32 = c;
                    --pCurrentSource;
                }

                // Write the decimal point.
                if(*pCurrent32 || !bStripPointlessDecimal) // If bStripPointlessDecimal is true, then draw decimal only if there is something after it.
                {
                    if(nDecimalPoint < nBufferLength) // The standard specifies to not write the decimal point if the precision is zero. 
                        *--pCurrent32 = (char32_t)fd.mDecimalPoint;
                }

                // Write the values that are before the decimal point.
                if(nDecimalPoint > 0)
                {
                    pCurrentSource = pBufferCvt + nDecimalPoint;

                    while(pCurrentSource > pBufferCvt)
                        *--pCurrent32 = *--pCurrentSource;
                }
                else
                    *--pCurrent32 = '0'; // Write the "0" before the decimal point, as in "0.1234".
                break;
            } // case f:
        } // switch

        // Write a sign character.
        if(nSign)
            *--pCurrent32 = '-';
        else if(fd.mSign == kSignMinusPlus)
            *--pCurrent32 = '+';
        else if(fd.mSign == kSignSpace)
            *--pCurrent32 = ' ';

        // Write leading spaces.
        if(fd.mAlignment == kAlignmentRight)
        {
            // Write in any leading spaces as required by the width specifier (or the zero fill alignment option). 
            int nWidth = (int)(intptr_t)(pBufferEnd32 - pCurrent32);

            while(nWidth < fd.mnWidth)
            {
                *--pCurrent32 = (char32_t)' ';
                ++nWidth;
            }
        }
        pResult32 = pCurrent32;
    }

    return pResult32;
}


///////////////////////////////////////////////////////////////////////////////
// VprintfCore
//
int VprintfCore(WriteFunction32 pWriteFunction32, void* EA_RESTRICT pWriteFunctionContext32, const char32_t* EA_RESTRICT pFormat, va_list arguments)
{
    using namespace SprintfLocal;

    const char32_t*     pFormatCurrent = pFormat;   // Current position within entire format string.
    const char32_t*     pFormatSpec;                // Current format specification (e.g. "%3.2f").
    FormatData          fd;
    int                 nWriteCount;
    int                 nWriteCountSum = 0;
    int                 nWriteCountCurrent;
    char32_t            pBuffer32[kConversionBufferSize + 1]; // The +1 isn't necessary but placates code analysis tools.
    char32_t* const     pBufferEnd32 = pBuffer32 + kConversionBufferSize;
    const char32_t*     pBufferData32 = NULL;      // Where within pBuffer32 the data we are interested in begins.
    long                lValue = 0;                // All known supported platforms have 'long' support in hardware. 'int' is always only 32 bits (even on 64 bit systems).
    unsigned long       ulValue = 0;               // 
    long long           llValue = 0;               // Most compilers support 'long long' at this point. VC++ v6 and earlier are notable exceptions.
    unsigned long long  ullValue = 0;              // 

    pWriteFunction32(NULL, 0, pWriteFunctionContext32, kWFSBegin);

    // We walk through the format string and echo characters to the output until we 
    // come across a % specifier, at which point we process it and then move on as before.
    while(*pFormatCurrent)
    {
        // Find the next format specification (or end of the string).
        pFormatSpec = pFormatCurrent;
        while(*pFormatSpec && (*pFormatSpec != '%'))
            ++pFormatSpec;

        // Write out non-formatted text
        nWriteCount = (int)(pFormatSpec - pFormatCurrent);
        if(nWriteCount)
        {
            if(pWriteFunction32(pFormatCurrent, (size_t)nWriteCount, pWriteFunctionContext32, kWFSIntermediate) == -1)
                goto FunctionError; // This is an error; not the same as running out of space.
            nWriteCountSum += nWriteCount;
            pFormatCurrent  = pFormatSpec;
        }

        if(*pFormatSpec)
        {
            pFormatCurrent = ReadFormat32(pFormatSpec, &fd, VA_LIST_REFERENCE(arguments));

            switch(fd.mnType)
            {
                case 'd':    // These are signed values.
                case 'i':    // The standard specifies that 'd' and 'i' are identical.
                {
                    if(fd.mModifier == kModifierLongLong)
                        llValue = va_arg(arguments, long long); // If the user didn't pass a long long, unexpected behaviour will occur.
                    else if((fd.mModifier == kModifierLong) || (fd.mModifier == kModifierLongDouble)) // It is questionable whether we should allow %Ld here as we do. The standard doesn't define this behaviour.
                        lValue = va_arg(arguments, long);
                    else if(fd.mModifier == kModifierInt64)
                    {
                        if(sizeof(int64_t) == sizeof(long))
                        {
                            // fd.mModifier == kModifierLong; -- Not necessary, as the logic below doesn't need this.
                            lValue = va_arg(arguments, long);
                        }
                        else if(sizeof(int64_t) == sizeof(long long))
                        {
                            fd.mModifier = kModifierLongLong;
                            llValue = va_arg(arguments, long long);
                        }
                    }
                    else if(fd.mModifier == kModifierInt128)
                    {
                        if(sizeof(int64_t) < sizeof(long long)) // If long long is 128 bits... (we don't test sizeof(int128_t) because there may be no such thing. Hopefully there is no int96_t.
                            llValue = va_arg(arguments, long long);
                        else
                        {
                            // We have a problem here. The user wants to print a 128 bit value but 
                            // there is no built-in type to support this. For the time being, we 
                            // simply use only 64 bits of data. If we really need this, we can
                            // add the functionality later. We have the EAStdC int128_t type we can use.
                            // I don't think calling two 64 bit va_args is the same as what a single
                            // 128 bit arg would be. If we are using EAStdC int128_t then we handle the 
                            // value the same as passing a struct by value. And that's compiler/ABI-specific.
                            llValue = va_arg(arguments, long long);
                            llValue = va_arg(arguments, long long);
                        }
                    }
                    else // else we have kModifierChar, kModifierShort, kModifierInt8, kModifierInt16, kModifierInt32.
                    {
                        // COMPILE_TIME_ASSERT(sizeof(int32_t) <= sizeof(int));
                        lValue = va_arg(arguments, int);
                        if((fd.mModifier == kModifierShort) || (fd.mModifier == kModifierInt16))
                            lValue = (long)(signed short)lValue; // We carefully do our casting here in order to preserve intent.
                        else if((fd.mModifier == kModifierChar) || (fd.mModifier == kModifierInt8))
                            lValue = (long)(signed char)lValue;  // We carefully do our casting here in order to preserve intent.
                    }

                    if(fd.mModifier == kModifierLongLong)
                    {
                        pBufferData32 = WriteLongLong32(fd, llValue, pBufferEnd32);
                        if(!pBufferData32)
                            goto FormatError;
                    }
                    else
                    {
                        pBufferData32 = WriteLong32(fd, lValue, pBufferEnd32);
                        if(!pBufferData32)
                            goto FormatError;
                    }

                    nWriteCount = (int)((pBufferEnd32 - pBufferData32) - 1); // -1 because the written string is 0-terminated and we don't want to write the final 0.
                    break;
                }

                case 'b': // 'b' means binary. This is a convenient extension that we provide.
                case 'o': // These are unsigned values.
                case 'u':
                case 'x':
                case 'X':
                {
                    if(fd.mModifier == kModifierLong)
                        ulValue = va_arg(arguments, unsigned long);
                    else if(fd.mModifier == kModifierLongLong)
                        ullValue = va_arg(arguments, unsigned long long);
                    else if(fd.mModifier == kModifierInt64)
                    {
                        if(sizeof(uint64_t) == sizeof(unsigned long))
                        {
                            // fd.mModifier == kModifierLong; -- Not necessary, as the logic below doesn't need this.
                            ulValue = va_arg(arguments, unsigned long);
                        }
                        else if(sizeof(uint64_t) == sizeof(unsigned long long))
                        {
                            fd.mModifier = kModifierLongLong;
                            ullValue = va_arg(arguments, unsigned long long);
                        }
                    }
                    else if(fd.mModifier == kModifierInt128)
                    {
                        if(sizeof(uint64_t) < sizeof(unsigned long long)) // If long long is 128 bits... (we don't test sizeof(int128_t) because there may be no such thing. Hopefully there is no int96_t.
                            ullValue = va_arg(arguments, unsigned long long);
                        else
                        {
                            // We have a problem here. The user wants to print a 128 bit value but 
                            // there is no built-in type to support this. For the time being, we 
                            // simply use only 64 bits of data. If we really need this, we can
                            // add the functionality later. We have the EAStdC int128_t type we can use.
                            // I don't think calling two 64 bit va_args is the same as what a single
                            // 128 bit arg would be. If we are using EAStdC int128_t then we handle the 
                            // value the same as passing a struct by value. And that's compiler/ABI-specific.
                            #ifdef EA_SYSTEM_BIG_ENDIAN
                                     (void)va_arg(arguments, unsigned long long);
                                ullValue = va_arg(arguments, unsigned long long);
                            #else
                                ullValue = va_arg(arguments, unsigned long long);
                                     (void)va_arg(arguments, unsigned long long);
                            #endif
                        }
                    }
                    else // else we have kModifierChar, kModifierShort, kModifierInt8, kModifierInt16, kModifierInt32.
                    {
                        ulValue = va_arg(arguments, unsigned int);
                        if((fd.mModifier == kModifierShort) || (fd.mModifier == kModifierInt16))
                            ulValue = (unsigned long)(unsigned short)ulValue; // We carefully do our casting here in order to preserve intent.
                        else if((fd.mModifier == kModifierChar) || (fd.mModifier == kModifierInt8))
                            ulValue = (unsigned long)(unsigned char)ulValue;  // We carefully do our casting here in order to preserve intent.
                    }

                    if(fd.mModifier == kModifierLongLong)
                    {
                        pBufferData32 = WriteLongLong32(fd, (long long)ullValue, pBufferEnd32);
                        if(!pBufferData32)
                            goto FormatError;
                    }
                    else
                    {
                        pBufferData32 = WriteLong32(fd, (long)ulValue, pBufferEnd32);
                        if(!pBufferData32)
                            goto FormatError;
                    }

                    nWriteCount = (int)((pBufferEnd32 - pBufferData32) - 1); // -1 because the written string is 0-terminated and we don't want to write the final 0.
                    break;
                }

                case 'e':
                case 'E':
                case 'f':
                case 'F':
                case 'g':
                case 'G':
                case 'a': // See the C99 standard, section 7.19.6.1.8, for details on 'a' formatting.
                case 'A':
                {
                    double dValue;
                    if(fd.mModifier == kModifierLongDouble)
                        dValue = va_arg(arguments, double);
                    else
                        dValue = va_arg(arguments, double); // Since on most systems long double is the same as double, it's really no big deal to just work with long double, much like we do with long int instead of int above.

                    pBufferData32 = WriteDouble32(fd, dValue, pBufferEnd32);
                    if(!pBufferData32)
                        goto FormatError;

                    nWriteCount = (int)((pBufferEnd32 - pBufferData32) - 1); // -1 because the written string is 0-terminated and we don't want to write the final 0.
                    break;
                }

                case 's':
                case 'S':
                {
                    int stringTypeSize;

                    switch (fd.mModifier)
                    {
                        case kModifierInt8:         // If the user specified %I8s or %I8S
                        case kModifierChar:         // If the user specified %hs or %hS or kModifierWChar was chosen implicitly for other reasons.
                            stringTypeSize = 1;
                            break;

                        case kModifierInt16:        // If the user specified %I16s or %I16S
                            stringTypeSize = 2;
                            break;

                        case kModifierInt32:        // If the user specified %I32s or %I32S
                            stringTypeSize = 4;
                            break;

                        case kModifierWChar:        // If the user specified %ls or %lS or kModifierWChar was chosen implicitly for other reasons.
                           stringTypeSize = sizeof(wchar_t);
                           break;

                        default:                    // If the user specified %I64s or %I64S or another invalid size.
                            goto FormatError;
                    }

                    switch (stringTypeSize)
                    {
                        case 1:
                        {
                            const char* pBufferData8 = va_arg(arguments, char8_t*);

                            // I don't see the C99 standard specifying the behaviour for a NULL string pointer, 
                            // but both GCC and MSVC use "(null)" when such a NULL pointer is encountered.
                            if(pBufferData8 == NULL)
                                pBufferData8 = kStringNull8;

                            // For strings, the precision modifier refers to the number of chars to display.
                            if(fd.mnPrecision != kNoPrecision) // If the user specified some precision...
                            {
                                // Find which is shorter, the length or the precision.
                                const char8_t*       pBufferCurrent8 = pBufferData8;
                                const char8_t* const pBufferMax8     = pBufferData8 + fd.mnPrecision;

                                while(*pBufferCurrent8 && (pBufferCurrent8 < pBufferMax8))
                                    ++pBufferCurrent8;
                                nWriteCount = (int)(pBufferCurrent8 - pBufferData8);
                            }
                            else
                            {
                                // Set the write count to be the string length. 
                                // Don't call strlen, as that would jump outside this module.
                                const char8_t* pBufferCurrent8 = pBufferData8;

                                while(*pBufferCurrent8) // Implement a small inline strlen.
                                    ++pBufferCurrent8;
                                nWriteCount = (int)(pBufferCurrent8 - pBufferData8);
                            }

                            // We have a problem here. We need to convert a char8_t string to a char32_t string but 
                            // there is only so much space (kConversionBufferSize) for the conversion. Should 
                            // we allocate memory via operator new[] here if nWriteCount > kConversionBufferSize? 
                            // Also, what do we do about string encodings? We assume the source is UTF8.
                            if(nWriteCount >= kConversionBufferSize)
                            {
                                EA_ASSERT(nWriteCount < kConversionBufferSize);
                                goto FormatError;
                            }

                            nWriteCount = Strlcpy(pBuffer32, pBufferData8, (size_t)(unsigned)kConversionBufferSize, (size_t)(unsigned)nWriteCount);

                            if(nWriteCount < 0) // If there was a conversion error...
                            {
                                pBuffer32[0] = 0;
                                goto FormatError;
                            }

                            pBufferData32 = pBuffer32;
                            break;
                        } // case 1

                        case 2:
                        {
                            const char16_t* pBufferData16 = va_arg(arguments, char16_t*);

                            // I don't see the C99 standard specifying the behaviour for a NULL string pointer, 
                            // but both GCC and MSVC use "(null)" when such a NULL pointer is encountered.
                            if(pBufferData16 == NULL)
                                pBufferData16 = kStringNull16;

                            // For strings, the precision modifier refers to the number of chars to display.
                            if(fd.mnPrecision != kNoPrecision) // If the user specified some precision...
                            {
                                // Find which is shorter, the length or the precision.
                                const char16_t*       pBufferCurrent16 = pBufferData16;
                                const char16_t* const pBufferMax16     = pBufferData16 + fd.mnPrecision;

                                while(*pBufferCurrent16 && (pBufferCurrent16 < pBufferMax16))
                                    ++pBufferCurrent16;
                                nWriteCount = (int)(pBufferCurrent16 - pBufferData16);
                            }
                            else
                            {
                                // Set the write count to be the string length. 
                                // Don't call strlen, as that would jump outside this module.
                                const char16_t* pBufferCurrent16 = pBufferData16;

                                while(*pBufferCurrent16) // Implement a small inline strlen.
                                    ++pBufferCurrent16;
                                nWriteCount = (int)(pBufferCurrent16 - pBufferData16);
                            }

                            if(nWriteCount >= kConversionBufferSize)
                            {
                                EA_ASSERT(nWriteCount < kConversionBufferSize);
                                goto FormatError;
                            }

                            nWriteCount = Strlcpy(pBuffer32, pBufferData16, (size_t)(unsigned)kConversionBufferSize, (size_t)(unsigned)nWriteCount);

                            if(nWriteCount < 0) // If there was a conversion error...
                            {
                                pBuffer32[0] = 0;
                                goto FormatError;
                            }

                            pBufferData32 = pBuffer32;
                            break;
                        } // case 2

                        case 4:
                        {
                            pBufferData32 = va_arg(arguments, char32_t*);

                            // I don't see the C99 standard specifying the behaviour for a NULL string pointer, 
                            // but both GCC and MSVC use "(null)" when such a NULL pointer is encountered.
                            if(pBufferData32 == NULL)
                                pBufferData32 = kStringNull32;

                            // For strings, the precision modifier refers to the number of chars to display.
                            if(fd.mnPrecision != kNoPrecision) // If the user specified some precision...
                            {
                                // Find which is shorter, the length or the precision.
                                const char32_t*       pBufferCurrent32 = pBufferData32;
                                const char32_t* const pBufferMax32     = pBufferData32 + fd.mnPrecision;

                                while(*pBufferCurrent32 && (pBufferCurrent32 < pBufferMax32))
                                    ++pBufferCurrent32;
                                nWriteCount = (int)(pBufferCurrent32 - pBufferData32);
                            }
                            else
                            {
                                // Set the write count to be the string length. 
                                // Don't call strlen, as that would jump outside this module.
                                const char32_t* pBufferCurrent32 = pBufferData32;

                                while(*pBufferCurrent32) // Implement a small inline strlen.
                                    ++pBufferCurrent32;
                                nWriteCount = (int)(pBufferCurrent32 - pBufferData32);
                            }
                            break;
                        } // case 4

                    } // switch (stringTypeSize)

                    break;
                } // case 's'

                case 'n': // %n %hn %ln %lln %I64n %I32n %I16n, %I8n, %jn, %tn, %zn etc.
                {
                    // In this case, we write the numer of chars written so far to the passed in argument.
                    void* pBufferData = va_arg(arguments, void*);

                    switch(fd.mModifier)
                    {
                        case kModifierInt8:
                        case kModifierChar:
                            *(char8_t*)pBufferData = (char8_t)nWriteCountSum; 
                            break;

                        case kModifierInt16: 
                        case kModifierShort:
                            *(int16_t*)pBufferData = (int16_t)nWriteCountSum;
                            break;

                        case kModifierInt32:
                            *(int32_t*)pBufferData = (int32_t)nWriteCountSum;
                            break;

                        case kModifierInt64:
                            *(int64_t*)pBufferData = (int32_t)nWriteCountSum;
                            break;

                        case kModifierLong:
                            *(long*)pBufferData = (long)nWriteCountSum;
                            break;

                        case kModifierLongLong:
                            *(long long*)pBufferData = (long long)nWriteCountSum;
                            break;

                        case kModifierPtrdiff_t:
                            *(ptrdiff_t*)pBufferData = (ptrdiff_t)nWriteCountSum;
                            break;

                        case kModifierSize_t:
                            *(size_t*)pBufferData = (size_t)nWriteCountSum;
                            break;

                        case kModifierMax_t:
                            *(intmax_t*)pBufferData = (intmax_t)nWriteCountSum;
                            break;

                      //case kModifierInt128:       // We really should generate an error with this. It's nearly pointless to support it.
                      //    // Fall through
                      //
                      //case kModifierWChar:        // This should be impossible to encounter.
                      //case kModifierLongDouble:   // This should be impossible to encounter.
                      //    // Fall through

                        case kModifierNone:
                        default:
                            *(int*)pBufferData = (int)nWriteCountSum;
                            break;
                    }
                    continue; // Intentionally continue instead break.
                } // case 'n'

                case 'c':
                case 'C':
                {
                    int charTypeSize;

                    switch (fd.mModifier)
                    {
                        case kModifierInt8:         // If the user specified %I8c or %I8c
                        case kModifierChar:         // If the user specified %hc or %hC or kModifierWChar was chosen implicitly for other reasons.
                            charTypeSize = 1;
                            break;

                        case kModifierInt16:        // If the user specified %I16c or %I16C
                            charTypeSize = 2;
                            break;

                        case kModifierInt32:        // If the user specified %I32c or %I32C
                            charTypeSize = 4;
                            break;

                        case kModifierWChar:        // If the user specified %lc or %lC or kModifierWChar was chosen implicitly for other reasons.
                           charTypeSize = sizeof(wchar_t);
                           break;

                        default:                    // If the user specified %I64c or %I64C or another invalid size.
                            goto FormatError;
                    }

                    switch (charTypeSize)
                    {
                        case 1:
                        {
                            const char8_t c8 = (char8_t)va_arg(arguments, int);
                            pBuffer32[0] = (char16_t)(uint8_t)c8;
                            pBufferData32 = pBuffer32;
                            nWriteCount = 1;
                            break;
                        }
                        case 2:
                        {
                            const char16_t c16 = (char16_t)va_arg(arguments, int);
                            pBuffer32[0] = (char32_t)(uint32_t)c16;
                            pBufferData32 = pBuffer32;
                            nWriteCount = 1;
                            break;
                        }
                        case 4:
                        {
                            pBuffer32[0] = (char32_t)va_arg(arguments, int); // We make the assumption here that sizeof(char32_t) is <= sizeof(int).
                            pBufferData32 = pBuffer32;
                            nWriteCount = 1;
                            EA_ASSERT(sizeof(*pBufferData32) == sizeof(char32_t));
                            break;
                        }
                    }

                    break;
                } // case 'c'

                case '%':
                {
                    // In this case we just write a single '%' char32_t to the output.
                    pBuffer32[0] = '%';
                    pBufferData32 = pBuffer32;
                    nWriteCount = 1;
                    break;
                }

                case kFormatError:
                default:
                    FormatError:
                    // We do what many printf implementations do here and simply print out the text
                    // as-is -- as if there wasn't any formatting specifier. This at least lets the
                    // user see what was (incorrectly) specified.
                    nWriteCount = (int)(pFormatCurrent - pFormatSpec);
                    nWriteCountSum+=nWriteCount;

                    if(nWriteCount && (pWriteFunction32(pFormatSpec, (size_t)nWriteCount, pWriteFunctionContext32, kWFSIntermediate) == -1))
                        goto FunctionError; // This is an error; not the same as running out of space.
                    continue; // Try to continue displaying further data.
            }

            nWriteCountCurrent = nWriteCount; // We will write at least as much nWriteCount, possibly more if the format specified a specific width.

            if(fd.mAlignment != kAlignmentLeft) // If we have right alignment or zero fill...
            {
                char32_t nFill;

                if(fd.mAlignment == kAlignmentZeroFill)
                {
                    nFill = '0';

                    if(pBufferData32 && ((*pBufferData32 == '+') || (*pBufferData32 == '-') || (*pBufferData32 == ' ')))
                    {    // Skip zero fill for leading sign character.
                        if(pWriteFunction32(pBufferData32, 1, pWriteFunctionContext32, kWFSIntermediate) == -1)
                            goto FunctionError; // This is an error; not the same as running out of space.
                        --nWriteCount;
                        ++pBufferData32;
                    }
                }
                else
                    nFill = ' ';

                while(nWriteCountCurrent < fd.mnWidth)
                {
                    // Consider making an optimization which writes more than one fill character at a time.
                    // We can do this by using the space at the beginning of pBuffer32;
                    if(pWriteFunction32(&nFill, 1, pWriteFunctionContext32, kWFSIntermediate) == -1)
                        goto FunctionError; // This is an error; not the same as running out of space.
                    ++nWriteCountCurrent;
                }
            }

            if(nWriteCount && (pWriteFunction32(pBufferData32, (size_t)nWriteCount, pWriteFunctionContext32, kWFSIntermediate) == -1))
                goto FunctionError; // This is an error; not the same as running out of space.

            if(fd.mAlignment == kAlignmentLeft) // If we have left alignment... fill in space to the right of the data.
            {
                const char32_t nSpace = ' ';
                while(nWriteCountCurrent < fd.mnWidth)
                {
                    if(pWriteFunction32(&nSpace, 1, pWriteFunctionContext32, kWFSIntermediate) == -1)
                        goto FunctionError; // This is an error; not the same as running out of space.
                    ++nWriteCountCurrent;
                }
            }

            nWriteCountSum += nWriteCountCurrent;

        } // if(*pFormatSpec)

    } // while(*pFormatCurrent)

    pWriteFunction32(NULL, 0, pWriteFunctionContext32, kWFSEnd);
    return nWriteCountSum;

FunctionError:
    pWriteFunction32(NULL, 0, pWriteFunctionContext32, kWFSEnd);
    return -1;
}


} // namespace SprintfLocal
} // namespace StdC
} // namespace EA


// For bulk build friendliness, undef all local #defines.
#undef IsNaN
#undef IsInf
#undef IsNeg
#undef EASPRINTF_MIN
#undef EASPRINTF_MAX


#ifdef _MSC_VER
    #pragma warning(pop)
#elif defined(__ghs__) // Green Hills compiler
    #pragma diag_default 1798
#endif







