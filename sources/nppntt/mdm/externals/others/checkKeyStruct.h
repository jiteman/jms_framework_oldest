#pragma once

#include "temporary_windows_include.h"

#pragma pack(push,1) 
struct tTCHHandle {
    unsigned int R1,R2,R3;
    byte *FwdData;
    int FwdSize;
    //byte *RevData;
    byte RevData[ 65537 ];
    int RevSize;
    byte DataType;
};
#pragma pack(pop)

#pragma pack(push,1) 
struct tSDCCHHandle {
    unsigned int R1,R2,R3;
    byte *Data;
    int DataSize;
    int CallType;
    byte Talker[256]; // shortstring N + 1 byte. 0 byte - length
    __int64 IMSI;
    unsigned int TMSI;
    __int64 IMEI;
    byte Abet;
    byte Text[256]; // shortstring;
    wchar_t TextUCS2[256]; // of widechar;
};
#pragma pack(pop)
