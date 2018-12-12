///////////////////////////////////////////////////////////////////////////////
// EAHashString.cpp
//
// Copyright (c) 2007 Criterion Software Limited and its licensors. All Rights Reserved.
// Created by Paul Pedriana
///////////////////////////////////////////////////////////////////////////////


#include "EA/StdC/internal/Config.h"
#include "EA/StdC/EAHashString.h"
#include "EA/StdC/EACType.h"


namespace EA
{
namespace StdC
{


///////////////////////////////////////////////////////////////////////////////
// DJB2
///////////////////////////////////////////////////////////////////////////////


EASTDC_API uint32_t DJB2(const void* pData, size_t nLength, uint32_t nInitialValue)
{
    const uint8_t* pData8 = (const uint8_t*)pData;
    const uint8_t* const pData8End = pData8 + nLength;

    while(pData8 < pData8End)
        nInitialValue = ((nInitialValue << 5) + nInitialValue) + *pData8++;

    return nInitialValue;
}


EASTDC_API uint32_t DJB2_String8(const char8_t* pData8, uint32_t nInitialValue, CharCase charCase)
{
    uint32_t c;

    switch (charCase)
    {
        case kCharCaseAny:
        {
            while((c = (uint8_t)*pData8++) != 0)
                nInitialValue = ((nInitialValue << 5) + nInitialValue) + c;
            break;
        }

        case kCharCaseLower:
        {
            while((c = (uint8_t)*pData8++) != 0)
                nInitialValue = ((nInitialValue << 5) + nInitialValue) + Tolower((char8_t)c);
            break;
        }

        case kCharCaseUpper:
        {
            while((c = (uint8_t)*pData8++) != 0)
                nInitialValue = ((nInitialValue << 5) + nInitialValue) + Toupper((char8_t)c);
            break;
        }
    }

    return nInitialValue;
}


EASTDC_API uint32_t DJB2_String16(const char16_t* pData16, uint32_t nInitialValue, CharCase charCase)
{
    uint32_t c;

    switch (charCase)
    {
        case kCharCaseAny:
        {
            while((c = (uint16_t)*pData16++) != 0)
                nInitialValue = ((nInitialValue << 5) + nInitialValue) + c;
            break;
        }

        case kCharCaseLower:
        {
            while((c = (uint16_t)*pData16++) != 0)
                nInitialValue = ((nInitialValue << 5) + nInitialValue) + Tolower((char16_t)c);
            break;
        }

        case kCharCaseUpper:
        {
            while((c = (uint16_t)*pData16++) != 0)
                nInitialValue = ((nInitialValue << 5) + nInitialValue) + Toupper((char16_t)c);
            break;
        }
    }

    return nInitialValue;
}




///////////////////////////////////////////////////////////////////////////////
// FNV1
///////////////////////////////////////////////////////////////////////////////

EASTDC_API uint32_t FNV1(const void* pData, size_t nLength, uint32_t nInitialValue)
{
    const uint8_t* pData8 = (const uint8_t*)pData;
    const uint8_t* const pData8End = pData8 + nLength;

    while(pData8 < pData8End)
        nInitialValue = (nInitialValue * 16777619) ^ *pData8++;

    return nInitialValue;
}


EASTDC_API uint32_t FNV1_String8(const char8_t* pData8, uint32_t nInitialValue, CharCase charCase)
{
    uint32_t c;

    switch (charCase)
    {
        case kCharCaseAny:
        {
            while((c = (uint8_t)*pData8++) != 0)
                nInitialValue = (nInitialValue * 16777619) ^ c;
            break;
        }

        case kCharCaseLower:
        {
            while((c = (uint8_t)*pData8++) != 0)
                nInitialValue = (nInitialValue * 16777619) ^ Tolower((char8_t)c);
            break;
        }

        case kCharCaseUpper:
        {
            while((c = (uint8_t)*pData8++) != 0)
                nInitialValue = (nInitialValue * 16777619) ^ Toupper((char8_t)c);
            break;
        }
    }

    return nInitialValue;
}


EASTDC_API uint32_t FNV1_String16(const char16_t* pData16, uint32_t nInitialValue, CharCase charCase)
{
    uint32_t c;

    switch (charCase)
    {
        case kCharCaseAny:
        {
            while((c = (uint16_t)*pData16++) != 0)
                nInitialValue = (nInitialValue * 16777619) ^ c;
            break;
        }

        case kCharCaseLower:
        {
            while((c = (uint16_t)*pData16++) != 0)
                nInitialValue = (nInitialValue * 16777619) ^ Tolower((char16_t)c);
            break;
        }

        case kCharCaseUpper:
        {
            while((c = (uint16_t)*pData16++) != 0)
                nInitialValue = (nInitialValue * 16777619) ^ Toupper((char16_t)c);
            break;
        }
    }

    return nInitialValue;
}

EASTDC_API uint32_t FNV1_String32(const char32_t* pData32, uint32_t nInitialValue, CharCase charCase)
{
    uint32_t c;

    switch (charCase)
    {
        case kCharCaseAny:
        {
            while((c = (uint32_t)*pData32++) != 0)
                nInitialValue = (nInitialValue * 16777619) ^ c;
            break;
        }

        case kCharCaseLower:
        {
            while((c = (uint32_t)*pData32++) != 0)
                nInitialValue = (nInitialValue * 16777619) ^ Tolower((char32_t)c);
            break;
        }

        case kCharCaseUpper:
        {
            while((c = (uint32_t)*pData32++) != 0)
                nInitialValue = (nInitialValue * 16777619) ^ Toupper((char32_t)c);
            break;
        }
    }

    return nInitialValue;
}


EASTDC_API uint64_t FNV64(const void* pData, size_t nLength, uint64_t nInitialValue)
{
    const uint8_t* pData8 = (const uint8_t*)pData;
    const uint8_t* const pData8End = pData8 + nLength;

    while(pData8 < pData8End)
        nInitialValue = (nInitialValue * UINT64_C(1099511628211)) ^ *pData8++;

    return nInitialValue;
}


EASTDC_API uint64_t FNV64_String8(const char8_t* pData8, uint64_t nInitialValue, CharCase charCase)
{
    uint64_t c;

    switch (charCase)
    {
        case kCharCaseAny:
        {
            while((c = (uint8_t)*pData8++) != 0)
                nInitialValue = (nInitialValue * UINT64_C(1099511628211)) ^ c;
            break;
        }

        case kCharCaseLower:
        {
            while((c = (uint8_t)*pData8++) != 0)
                nInitialValue = (nInitialValue * UINT64_C(1099511628211)) ^ Tolower((char8_t)c);
            break;
        }

        case kCharCaseUpper:
        {
            while((c = (uint8_t)*pData8++) != 0)
                nInitialValue = (nInitialValue * UINT64_C(1099511628211)) ^ Toupper((char8_t)c);
            break;
        }
    }

    return nInitialValue;
}


EASTDC_API uint64_t FNV64_String16(const char16_t* pData16, uint64_t nInitialValue, CharCase charCase)
{
    uint64_t c;

    switch (charCase)
    {
        case kCharCaseAny:
        {
            while((c = (uint16_t)*pData16++) != 0)
                nInitialValue = (nInitialValue * UINT64_C(1099511628211)) ^ c;
            break;
        }

        case kCharCaseLower:
        {
            while((c = (uint16_t)*pData16++) != 0)
                nInitialValue = (nInitialValue * UINT64_C(1099511628211)) ^ Tolower((char16_t)c);
            break;
        }

        case kCharCaseUpper:
        {
            while((c = (uint16_t)*pData16++) != 0)
                nInitialValue = (nInitialValue * UINT64_C(1099511628211)) ^ Toupper((char16_t)c);
            break;
        }
    }

    return nInitialValue;
}

EASTDC_API uint64_t FNV64_String32(const char32_t* pData32, uint64_t nInitialValue, CharCase charCase)
{
    uint64_t c;

    switch (charCase)
    {
        case kCharCaseAny:
        {
            while((c = (uint32_t)*pData32++) != 0)
                nInitialValue = (nInitialValue * UINT64_C(1099511628211)) ^ c;
            break;
        }

        case kCharCaseLower:
        {
            while((c = (uint32_t)*pData32++) != 0)
                nInitialValue = (nInitialValue * UINT64_C(1099511628211)) ^ Tolower((char32_t)c);
            break;
        }

        case kCharCaseUpper:
        {
            while((c = (uint32_t)*pData32++) != 0)
                nInitialValue = (nInitialValue * UINT64_C(1099511628211)) ^ Toupper((char32_t)c);
            break;
        }
    }

    return nInitialValue;
}



} // namespace StdC
} // namespace EA





