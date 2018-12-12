#pragma once

#include "abstractFileDescriptor.h"

#include "temporary_windows_include.h"

#include "jmsf/stdal/stdal_stl.h"

#include "external_header_antiwarning.h"


struct KeyData {
    unsigned int R1;
    unsigned int R2;
    unsigned int R3;

	unsigned int networkAndBaseStationId;
    std::string BsName;
};

#pragma pack(push,1)
struct tPat
{

public:
    byte B0[15];
    byte B1[15];
    byte B2[15];
    byte B3[15];
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct tA51_Burst
{

public:
    byte B[15];
    unsigned FN;
    byte Tag;
    char SNR; // Shortint
    byte Flags;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct tBurst
{

public:
    byte B[16];
    unsigned C;
    byte Tag;
} ;
#pragma pack(pop)


#pragma pack(push,1)
struct tA51_SDCCH_Session
{

public:
    byte CallType;
    int Bscntr;
    tBurst Bs[4][100];
    byte TN;
    bool Hopping;
    union
    {
        struct 
        {
            byte HSN;
            byte MAIO;

        };
        struct 
        {
            WORD ARFCN;

        };

    };
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct tA51_Handle
{

public:
    tA51_SDCCH_Session SDCCH_Sessions[4];
    byte Sys5[23];
    byte Sys5bis[23];
    byte Sys5ter[23];
    byte Sys6[23];
    tPat Sys5Pat;
    tPat Sys5bisPat;
    tPat Sys5terPat;
    tPat Sys6Pat;
    byte PL;
    byte TA;
    byte TN;
    bool Hopping;
    union
    {
        struct 
        {
            byte HSN;
            byte MAIO;

        };
        struct 
        {
            WORD ARFCN;

        };

    };
} ;
#pragma pack(pop)

KeyData *createKey();
void deleteKey( KeyData *key );

bool isSuitableFileDescriptorToKey( const FileDescriptorData *descriptor, const KeyData *key );
bool areKeysEqual( const KeyData *firstKey, const KeyData *secondKey );
