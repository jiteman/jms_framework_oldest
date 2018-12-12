#pragma once

#include "checkKeyStruct.h"
#include "abstractFileDescriptor.h"
#include "abstractKey.h"

#include "abstractLog.h"

// #pragma pack(push,1)
// struct tBurst
// {
// public:
//     BYTE B[16];
//     unsigned C;
//     BYTE Tag;
// } ;
// #pragma pack(pop)
// 
// #pragma pack(push,1)
// struct tA51_SDCCH_Session
// {
// public:
//     BYTE CallType;
//     int Bscntr;
//     tBurst Bs[4][100];
//     BYTE TN;
//     bool Hopping;
//     union
//     {
//         struct 
//         {
//             BYTE HSN;
//             BYTE MAIO;
// 
//         };
//         struct 
//         {
//             WORD ARFCN;
// 
//         };
// 
//     };
// } ;
// #pragma pack(pop)

//bool loadApplyKcDll();
//void unloadApplyKcDll();

// voice file
AppliedData* CheckTCH( const FileDescriptorData *const file, const KeyData *const keyData, LogFile *logFile = NULL );
// service file
AppliedData* CheckSDCCH( FileDescriptorData *file, const KeyData *const keyData, LogFile *logFile = NULL );

bool isInRange( const FileDescriptorData &voiceFile, const FileDescriptorData &serviceFile, LogFile *logFile = NULL );

void deleteAppliedData( AppliedData *data, LogFile *logFile = NULL );
