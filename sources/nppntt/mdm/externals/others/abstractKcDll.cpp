#include "abstractKcDll.h"

#include "external_source_antiwarning.h"

tDoItTCH DoItTCH;
tDoItSDCCH DoItSDCCH;

tDatabaseInit       DataBaseInit;
tDatabaseUnInit     DataBaseUnInit;
tDatabaseConnect    DataBaseConnect;
tDatabaseDisconnect DataBaseDisconnect;
tDatabaseAddRecord  DataBaseAddRecord;

static HINSTANCE hApplyKcDll = NULL;

bool loadApplyKcDll() {
	if( hApplyKcDll != NULL )
		return true;

    hApplyKcDll = LoadLibraryA("apply_kc.dll");
    if (hApplyKcDll != NULL) {
        DoItTCH = (tDoItTCH)GetProcAddress(hApplyKcDll, "DoItTCH");
        if (NULL == DoItTCH) { FreeLibrary(hApplyKcDll); return false; }

        DoItSDCCH = (tDoItSDCCH)GetProcAddress(hApplyKcDll, "DoItSDCCH");
        if (NULL == DoItSDCCH) { FreeLibrary(hApplyKcDll); return false; }

		DataBaseInit = (tDatabaseInit)GetProcAddress(hApplyKcDll, "DatabaseInit");
        if (NULL == DataBaseInit) { FreeLibrary(hApplyKcDll); return false; }

        DataBaseUnInit = (tDatabaseUnInit)GetProcAddress(hApplyKcDll, "DatabaseUnInit");
        if (NULL == DataBaseUnInit) { FreeLibrary(hApplyKcDll); return false; }

        DataBaseConnect = (tDatabaseConnect)GetProcAddress(hApplyKcDll, "DatabaseConnect");
        if (NULL == DataBaseConnect) { FreeLibrary(hApplyKcDll); return false; }

        DataBaseDisconnect = (tDatabaseDisconnect)GetProcAddress(hApplyKcDll, "DatabaseDisconnect");
        if (NULL == DataBaseDisconnect) { FreeLibrary(hApplyKcDll); return false; }

        DataBaseAddRecord = (tDatabaseAddRecord)GetProcAddress(hApplyKcDll, "DatabaseAddRecord");
        if (NULL == DataBaseAddRecord) { FreeLibrary(hApplyKcDll); return false; }
    }
    else {
        return false;
    }

    return true;
}

void unloadApplyKcDll() {
	if( hApplyKcDll == NULL )
		return;
    FreeLibrary(hApplyKcDll);
    hApplyKcDll = NULL;

// #ifdef _DUMP_APPLYED_RESULT
//     _applyedDataResultTCH.flush();
//     _applyedDataResultTCH.close();
// 
//     _applyedDataResultSDCCH.flush();
//     _applyedDataResultSDCCH.close();
// #endif
}

bool loadDataBaseDll() {
// #ifdef _DEBUG
//     DWORD currentThreadID = ::GetCurrentThreadId();
//     std::ostringstream o;
//     o << currentThreadID;
//     _mkdir("dataBaseLogs");
//     _logDataBaseTCHandSDCCH.open( "dataBaseLogs\\" + o.str() + "_logDataBaseTCHandSDCCH.log" );
// 	_logDataBaseOnlySDCCH.open( "dataBaseLogs\\" + o.str() + "_logDataBaseOnlySDCCH.log" );
// #endif

//     hDataBaseDll = LoadLibraryA("apply_kc.dll");
//     if (hDataBaseDll != NULL) {
//         DataBaseInit = (tDatabaseInit)GetProcAddress(hDataBaseDll, "DatabaseInit");
//         if (NULL == DataBaseInit) { FreeLibrary(hDataBaseDll); return false; }
// 
//         DataBaseUnInit = (tDatabaseUnInit)GetProcAddress(hDataBaseDll, "DatabaseUnInit");
//         if (NULL == DataBaseUnInit) { FreeLibrary(hDataBaseDll); return false; }
// 
//         DataBaseConnect = (tDatabaseConnect)GetProcAddress(hDataBaseDll, "DatabaseConnect");
//         if (NULL == DataBaseConnect) { FreeLibrary(hDataBaseDll); return false; }
// 
//         DataBaseDisconnect = (tDatabaseDisconnect)GetProcAddress(hDataBaseDll, "DatabaseDisconnect");
//         if (NULL == DataBaseDisconnect) { FreeLibrary(hDataBaseDll); return false; }
// 
//         DataBaseAddRecord = (tDatabaseAddRecord)GetProcAddress(hDataBaseDll, "DatabaseAddRecord");
//         if (NULL == DataBaseAddRecord) { FreeLibrary(hDataBaseDll); return false; }
//     }
//     else {
// #ifdef _DEBUG
//     if( _logDataBaseTCHandSDCCH.is_open() ) 
//         _logDataBaseTCHandSDCCH << "Load dataBase dll BAD" << std::endl;
// #endif
//         return false;
//     }

// #ifdef _DEBUG
// //     if( _logDataBase.is_open() ) 
// //         _logDataBase << "Load dataBase dll OK" << std::endl;
// #endif
    return true;
}

void unloadDataBaseDll() {
// #ifdef _DEBUG
//     if( _logDataBaseTCHandSDCCH.is_open() ) {
//         _logDataBaseTCHandSDCCH << "Unload dataBase dll" << std::endl;
//         _logDataBaseTCHandSDCCH.flush();
//         _logDataBaseTCHandSDCCH.close();
//     }
// #endif
//     FreeLibrary(hDataBaseDll);
//     hDataBaseDll = NULL;
}