#include "abstractDataBase.h"

#include "abstractKcDll.h"

#include "external_source_antiwarning.h"

#include <direct.h>

#ifdef _DEBUG 
    static std::ofstream _logDataBaseTCHandSDCCH;
	static std::ofstream _logDataBaseOnlySDCCH;
#endif

//static HINSTANCE hDataBaseDll = NULL;

// typedef void (__stdcall *tDatabaseInit)(char *SaveDir);
// typedef void (__stdcall *tDatabaseUnInit)();
// typedef bool (__stdcall *tDatabaseConnect)(char *ServerName, char *DatabaseName, char *Login, char *Password);
// typedef void (__stdcall *tDatabaseDisconnect)();
// 
// typedef bool (__stdcall *tDatabaseAddRecord)(int tch_duration, FILETIME creationTime, FILETIME creationTimeIni,
//     char *BSName,
//     char *Network,
//     tSDCCHHandle *sdcch,
//     tTCHHandle *tch,
//     char *TemporaryNumber);
// 
// tDatabaseInit       DataBaseInit;
// tDatabaseUnInit     DataBaseUnInit;
// tDatabaseConnect    DataBaseConnect;
// tDatabaseDisconnect DataBaseDisconnect;
// tDatabaseAddRecord  DataBaseAddRecord;


// »ÒÔÓÎ¸ÁÛÂÚÒˇ ‚ FileAppender. Õ¿ƒŒ ”¡–¿“‹ ¬—≈ ¬ Œœ»—¿“≈À‹ ƒ≈— –»œ“Œ–¿
// ----------------------------------------------------------------------------------
std::string convertIntToString( const ULONG value ) {
    std::ostringstream o;
    o << value;
    return o.str();
}

#ifdef _DEBUG
void dumpDescriptor_DB( const FileDescriptorData *descriptor, std::ofstream &logFile ) {
    std::string type;
    if( descriptor->type == _FTC ) type = "FTC";
    else if ( descriptor->type == _SDC ) type = "SDC";
    else if ( descriptor->type == _INI ) type = "INI";
    else if ( descriptor->type == _RTC ) type = "RTC";
    else if ( descriptor->type == _INVALID ) type = "INVALID";

    logFile << "" << std::endl;
    logFile << "---- Start dump descriptor ----" << std::endl;
    logFile << "Type: " + type << std::endl;
    logFile << "BS: " + descriptor->baseStation << std::endl;
    logFile << "AddTime: " + convertIntToString( descriptor->addFileTime.dwLowDateTime ) + " " +
        convertIntToString( descriptor->addFileTime.dwHighDateTime ) << std::endl;
    logFile << "CreationTime: " + convertIntToString( descriptor->creationTime.dwLowDateTime ) + " " +
        convertIntToString( descriptor->creationTime.dwHighDateTime ) << std::endl;
    logFile << "CreationTimeIni: " + convertIntToString( descriptor->creationTimeIni.dwLowDateTime ) + " " +
        convertIntToString( descriptor->creationTimeIni.dwHighDateTime ) << std::endl;
    logFile << "FileName: " + descriptor->fileName << std::endl;
    logFile << "LongPath: " + descriptor->longPath << std::endl;
    logFile << "Network: " + descriptor->network << std::endl;
    logFile << "R1: " + convertIntToString( descriptor->R1 ) +
        " R2: " + convertIntToString( descriptor->R2 ) +
        " R3: " + convertIntToString( descriptor->R3 ) << std::endl;
    logFile << "TemporaryNumber: " + descriptor->temporaryNumber << std::endl;
    logFile << "---- Dump descriptor Done ----" << std::endl << std::endl;
}

void dumpSDCCH( std::ofstream &logFile, const AppliedData *data ) {
#define _TO_LOG logFile<<
#define _END_LOG <<std::endl;
	_TO_LOG "Abet: " + convertAnyDigitsToString(data->sdcData.Abet) _END_LOG
	_TO_LOG "CallType: " + convertAnyDigitsToString(data->sdcData.CallType) _END_LOG
	_TO_LOG "DataSize: " + convertAnyDigitsToString(data->sdcData.DataSize) _END_LOG
	_TO_LOG "IMEI: " + convertAnyDigitsToString(data->sdcData.IMEI) _END_LOG
	_TO_LOG "IMSI: " + convertAnyDigitsToString(data->sdcData.IMSI) _END_LOG
	_TO_LOG "R1: " + convertAnyDigitsToString(data->sdcData.R1) _END_LOG
	_TO_LOG "R2: " + convertAnyDigitsToString(data->sdcData.R2) _END_LOG
	_TO_LOG "R3: " + convertAnyDigitsToString(data->sdcData.R3) _END_LOG
	_TO_LOG "TMSI: " + convertAnyDigitsToString(data->sdcData.TMSI) _END_LOG
	_TO_LOG "" _END_LOG
#undef _TO_LOG
#undef _END_LOG
	return;
}
#endif
// ----------------------------------------------------------------------------------
// bool loadDataBaseDll() {
// #ifdef _DEBUG
//     DWORD currentThreadID = ::GetCurrentThreadId();
//     std::ostringstream o;
//     o << currentThreadID;
//     _mkdir("dataBaseLogs");
//     _logDataBaseTCHandSDCCH.open( "dataBaseLogs\\" + o.str() + "_logDataBaseTCHandSDCCH.log" );
// 	_logDataBaseOnlySDCCH.open( "dataBaseLogs\\" + o.str() + "_logDataBaseOnlySDCCH.log" );
// #endif
// 
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
// 
// #ifdef _DEBUG
// //     if( _logDataBase.is_open() ) 
// //         _logDataBase << "Load dataBase dll OK" << std::endl;
// #endif
//     return true;
// }

// void unloadDataBaseDll() {
// #ifdef _DEBUG
//     if( _logDataBaseTCHandSDCCH.is_open() ) {
//         _logDataBaseTCHandSDCCH << "Unload dataBase dll" << std::endl;
//         _logDataBaseTCHandSDCCH.flush();
//         _logDataBaseTCHandSDCCH.close();
//     }
// #endif
//     FreeLibrary(hDataBaseDll);
//     hDataBaseDll = NULL;
// }

char* getBaseStationFromDescriptor( const FileDescriptorData *file ) {
    char *baseStation = new char[file->baseStation.length() + 1];
    strncpy(baseStation, file->baseStation.c_str(), file->baseStation.length());
    baseStation[file->baseStation.length()] = '\0';
    return baseStation;
}

char* getNetworkFromDescriptor( const FileDescriptorData *file ) {
    char *network = new char[file->network.length() + 1];
    strncpy(network, file->network.c_str(), file->network.length());
    network[file->network.length()] = '\0';
    return network;
}

char* getTemporaryNumberFromDescriptor( const FileDescriptorData *file ) {
    char *temporaryNumber = new char[file->temporaryNumber.length() + 1];    
    strncpy(temporaryNumber, file->temporaryNumber.c_str(), file->temporaryNumber.length());
    temporaryNumber[file->temporaryNumber.length()] = '\0';
    return temporaryNumber;
}

bool sendFilesToDataBase( const FileDescriptorData *voiceFile, FileDescriptorData *sdcFile,  
                          const AppliedData *voiceDataToSend, const AppliedData *serviceDataToSend ) {
    BOOL sendResult = FALSE;

	::Sleep( 100 );
    
    if( (voiceFile != NULL && sdcFile != NULL) && (voiceDataToSend != NULL && serviceDataToSend != NULL) ) {
#ifdef _DEBUG
		dumpSDCCH( _logDataBaseTCHandSDCCH, serviceDataToSend );
#endif
        char *BS = getBaseStationFromDescriptor( voiceFile );
        char *network = getNetworkFromDescriptor( voiceFile );
        char *temporaryNumber = getTemporaryNumberFromDescriptor( voiceFile );   

		if( (!sdcFile->isSMSSussesfullSent) && (serviceDataToSend->sdcData.Abet != 0xFF) ) { 
			sdcFile->isSMSSussesfullSent = TRUE;
#ifndef _EMULATION_DB
			try {
			sendResult = DataBaseAddRecord(voiceDataToSend->tch_duration, voiceFile->creationTime, 
                                           voiceFile->creationTimeIni, 
                                           BS, 
                                           network, 
                                           &const_cast< AppliedData * >( serviceDataToSend )->sdcData,
                                           &const_cast< AppliedData * >( voiceDataToSend )->tchData,
                                           temporaryNumber);
			} catch (...) {}
#endif
		} else {
			const_cast< AppliedData * >( serviceDataToSend )->sdcData.Abet = 0xFF;
#ifndef _EMULATION_DB
			try {
			sendResult = DataBaseAddRecord(voiceDataToSend->tch_duration, voiceFile->creationTime, 
                                           voiceFile->creationTimeIni, 
                                           BS, 
                                           network, 
                                           &const_cast< AppliedData * >( serviceDataToSend )->sdcData,
                                           &const_cast< AppliedData * >( voiceDataToSend )->tchData,
                                           temporaryNumber);
			} catch (...) {}
#endif
		}
        // free
        delete BS;
        delete network;
        delete temporaryNumber;
    }
    else if( (voiceFile != NULL && sdcFile == NULL) && (voiceDataToSend != NULL && serviceDataToSend == NULL) ) {
        char *BS = getBaseStationFromDescriptor( voiceFile );
        char *network = getNetworkFromDescriptor( voiceFile );
        char *temporaryNumber = getTemporaryNumberFromDescriptor( voiceFile );   
#ifndef _EMULATION_DB
		try {
        sendResult = DataBaseAddRecord(voiceDataToSend->tch_duration, voiceFile->creationTimeIni, 
                                       voiceFile->creationTime, 
                                       BS, 
                                       network, 
                                       NULL,
                                       &const_cast< AppliedData * >( voiceDataToSend )->tchData, 
                                       temporaryNumber);
		} catch (...) {}
#endif
        // free
        delete BS;
        delete network;
        delete temporaryNumber;
    }
    else if( (sdcFile != NULL && voiceFile == NULL) && (serviceDataToSend != NULL && voiceDataToSend == NULL) ) {
#ifdef _DEBUG
		dumpSDCCH( _logDataBaseOnlySDCCH, serviceDataToSend );
#endif
		if( (!sdcFile->isSMSSussesfullSent) && (serviceDataToSend->sdcData.Abet != 0xFF) ) {
			sdcFile->isSMSSussesfullSent = TRUE;
			char *BS = getBaseStationFromDescriptor( sdcFile );
			char *network = getNetworkFromDescriptor( sdcFile );
			char *temporaryNumber = getTemporaryNumberFromDescriptor( sdcFile );   
#ifndef _EMULATION_DB
			try {
			sendResult = DataBaseAddRecord(0, sdcFile->creationTime, 
				                           sdcFile->creationTimeIni, 
					                       BS, 
						                   network, 
							               &const_cast< AppliedData * >( serviceDataToSend )->sdcData,
								           NULL,
									       temporaryNumber);
			} catch (...) {}
#endif
			// free
			delete BS;
			delete network;
			delete temporaryNumber;
		}
    } 

    if (sendResult) return true;
    else return false;
}

void initializeDataBase( const std::string &workDir )
{
    char *workDirS = new char[workDir.length() + 1];
    strncpy(workDirS, workDir.c_str(), workDir.length());
    workDirS[workDir.length()] = '\0';

#ifndef _EMULATION_DB
    try {
    DataBaseInit( workDirS );
    } catch ( ... ) {}
#endif

    delete workDirS;
}

bool connectToDataBase( const std::string &IP, const std::string &dataBaseName, const std::string &User, const std::string &Password ) {
    char *ipS = new char[IP.length() + 1];
    char *dataBaseNameS = new char[dataBaseName.length() + 1];
    char *userS = new char[User.length() + 1];
    char *passwordS = new char[Password.length() + 1];

    strncpy(ipS, IP.c_str(), IP.length());
    ipS[IP.length()] = '\0';

    strncpy(dataBaseNameS, dataBaseName.c_str(), dataBaseName.length());
    dataBaseNameS[dataBaseName.length()] = '\0';

    strncpy(userS, User.c_str(), User.length());
    userS[User.length()] = '\0';

    strncpy(passwordS, Password.c_str(), Password.length());
    passwordS[Password.length()] = '\0';

#ifndef _EMULATION_DB
    BOOL dataBaseConnectResult = FALSE;
    dataBaseConnectResult = DataBaseConnect( ipS, dataBaseNameS, userS, passwordS );
#else
    BOOL dataBaseConnectResult = TRUE;
#endif

    delete ipS;
    delete dataBaseNameS;
    delete userS;
    delete passwordS;

    return dataBaseConnectResult;
}

void disconnectFromDataBase() {
#ifndef _EMULATION_DB
    DataBaseDisconnect();
#endif
}

void releaseDataBase() {
#ifndef _EMULATION_DB
    DataBaseUnInit();    
#endif
}


