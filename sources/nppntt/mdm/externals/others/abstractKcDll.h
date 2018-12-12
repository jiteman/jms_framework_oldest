#pragma once

#include "abstractApplyKey.h"

typedef int (__stdcall *tDoItTCH) (tTCHHandle *data);
typedef bool (__stdcall *tDoItSDCCH) (tSDCCHHandle *data);

typedef void (__stdcall *tDatabaseInit)(char *SaveDir);
typedef void (__stdcall *tDatabaseUnInit)();
typedef bool (__stdcall *tDatabaseConnect)(char *ServerName, char *DatabaseName, char *Login, char *Password);
typedef void (__stdcall *tDatabaseDisconnect)();
typedef bool (__stdcall *tDatabaseAddRecord)(int tch_duration, FILETIME creationTime, FILETIME creationTimeIni,
    char *BSName,
    char *Network,
    tSDCCHHandle *sdcch,
    tTCHHandle *tch,
    char *TemporaryNumber);

extern tDoItTCH DoItTCH;
extern tDoItSDCCH DoItSDCCH;

extern tDatabaseInit       DataBaseInit;
extern tDatabaseUnInit     DataBaseUnInit;
extern tDatabaseConnect    DataBaseConnect;
extern tDatabaseDisconnect DataBaseDisconnect;
extern tDatabaseAddRecord  DataBaseAddRecord;

bool loadApplyKcDll();
void unloadApplyKcDll();