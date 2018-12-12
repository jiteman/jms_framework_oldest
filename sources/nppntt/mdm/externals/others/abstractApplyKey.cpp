#include "abstractApplyKey.h"

#include "abstractKcDll.h"

#include "external_source_antiwarning.h"

//static HINSTANCE hApplyKcDll = NULL;

/*
typedef int (__stdcall *tDoItTCH) (tTCHHandle *data);
typedef bool (__stdcall *tDoItSDCCH) (tSDCCHHandle *data);

tDoItTCH DoItTCH;
tDoItSDCCH DoItSDCCH;
*/

extern std::string convertIntToString( const ULONG value );
extern ULONG ConvertFileTimeToSeconds( const FILETIME &ft );

// #ifdef _DUMP_APPLYED_RESULT
// static std::ofstream _applyedDataResultTCH( "_applyedDataResultTCH.log" ); 
// static std::ofstream _applyedDataResultSDCCH( "_applyedDataResultSDCCH.log" ); 
// 
// void dumpApplyedDataResultTCH( const std::string &fileName, unsigned int R1, unsigned int R2, unsigned int R3 ) {
//     _applyedDataResultTCH << fileName << " " 
//         << convertIntToString(R1) << " " 
//         << convertIntToString(R2) << " " 
//         << convertIntToString(R3) << " " << std::endl;
//     _applyedDataResultTCH.flush();
// }
// 
// void dumpApplyedDataResultSDCCH( const std::string &fileName, unsigned int R1, unsigned int R2, unsigned int R3 ) {
//     _applyedDataResultSDCCH << fileName << " " 
//         << convertIntToString(R1) << " " 
//         << convertIntToString(R2) << " " 
//         << convertIntToString(R3) << " " << std::endl;
//     _applyedDataResultSDCCH.flush();
// }
// #endif

// bool loadApplyKcDll() {
//     hApplyKcDll = LoadLibraryA("apply_kc.dll");
//     if (hApplyKcDll != NULL) {
//         DoItTCH = (tDoItTCH)GetProcAddress(hApplyKcDll, "DoItTCH");
//         if (NULL == DoItTCH) { FreeLibrary(hApplyKcDll); return false; }
// 
//         DoItSDCCH = (tDoItSDCCH)GetProcAddress(hApplyKcDll, "DoItSDCCH");
//         if (NULL == DoItSDCCH) { FreeLibrary(hApplyKcDll); return false; }
//     }
//     else {
//         return false;
//     }
// 
//     return true;
// }

// void unloadApplyKcDll() {
//     FreeLibrary(hApplyKcDll);
//     hApplyKcDll = NULL;
// 
// // #ifdef _DUMP_APPLYED_RESULT
// //     _applyedDataResultTCH.flush();
// //     _applyedDataResultTCH.close();
// // 
// //     _applyedDataResultSDCCH.flush();
// //     _applyedDataResultSDCCH.close();
// // #endif
// }
                 
int readFile( const FileDescriptorData *file, AppliedData *data ) {
    if( data == NULL ) 
        return 0;

    std::string extension;
    if( file->type == _FTC ) extension = ".FTC";
    else if( file->type == _SDC ) extension = ".SDC";

    const std::string fileName = file->longPath + file->fileName + extension;

    HANDLE hFile = ::CreateFileA( fileName.c_str(), 
        GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );

    if( hFile != INVALID_HANDLE_VALUE ) {

        DWORD fileSize = 0;
        fileSize = ::GetFileSize( hFile, NULL );
        
        if( fileSize != INVALID_FILE_SIZE ) {
			if( file->type == _FTC )
                fileSize = ( fileSize / sizeof( tA51_Handle ) ) * sizeof( tA51_Handle );

            data->dataAfterApplyKey.resize( fileSize, 0 );
            DWORD bytesRead = 0;
            ::ReadFile( hFile, &(data->dataAfterApplyKey[0]), fileSize, &bytesRead, NULL );
            if( bytesRead != fileSize ) {
                data->dataAfterApplyKey = std::vector< BYTE >();
                ::CloseHandle( hFile );
                return 0;
            }
            ::CloseHandle( hFile );
            return fileSize;
        }
        else {
            ::CloseHandle( hFile );
            return 0;
        }
    }
    else
        return 0;
}


AppliedData* CheckTCH( const FileDescriptorData *const file, const KeyData *const keyData, LogFile *logFile ) {
    if( logFile != NULL ) {
        logFile->dump( "Call CheckTCH with params: " );
        logFile->dump( "FileName: " + file->fileName );
        logFile->dump( "BS: " + file->baseStation );
        logFile->dump( "Key BS: " + keyData->BsName );
        logFile->dump( "Key: R1=" + convertIntToString(keyData->R1) + 
                           " R2=" + convertIntToString(keyData->R2) + 
                           " R3=" + convertIntToString(keyData->R3) );
    }

	//return NULL;

    AppliedData *data = new AppliedData;
    int dataSize = 0;

	data->tch_duration = 0;
    memset( &data->sdcData, 0x00, sizeof( tSDCCHHandle ) );
    memset( &data->tchData, 0x00, sizeof( tTCHHandle ) );
     
     //data->tchData.RevData = NULL;
    data->dataAfterApplyKey = std::vector< BYTE >();

//     memset( &localData.sdcData, 0x00, sizeof( tSDCCHHandle ) );
//     memset( &localData.tchData, 0x00, sizeof( tTCHHandle ) );
//     //localData.tchData.RevData = NULL;
//     localData.dataAfterApplyKey = std::vector< BYTE >();

    dataSize = readFile( file, data /*&localData*/ );
    if( logFile!= NULL) 
        logFile->dump( "CheckTCH: readFile return: " + convertIntToString(dataSize) );

    if ( ( dataSize != 0 ) && ( keyData->R1 != 0 ) && ( keyData->R2 != 0 ) && ( keyData->R3 != 0 ) ) {
        data->tchData.FwdData = &(data->dataAfterApplyKey[0]);
        data->tchData.FwdSize = dataSize;
        data->tchData.RevSize = 0;
        data->tchData.R1 = keyData->R1;
        data->tchData.R2 = keyData->R2;
        data->tchData.R3 = keyData->R3; 

//         localData.tchData.FwdData = &(localData.dataAfterApplyKey[0]);
//         localData.tchData.FwdSize = dataSize;
//         //localData.tchData.RevData = new BYTE[ 65537 ];
//         localData.tchData.RevSize = 0;
//         localData.tchData.R1 = keyData->R1;
//         localData.tchData.R2 = keyData->R2;
//         localData.tchData.R3 = keyData->R3; 

        int doItTCHResult = FALSE;

        try {
            doItTCHResult = DoItTCH( &data->tchData /*&localData.tchData*/ );
        } catch ( ... ) {
            if( logFile != NULL )
                logFile->dump( "Exception in DoItTCH" );
        }

        if ( doItTCHResult != 0 ) {
            if( logFile != NULL ) 
                logFile->dump( "CheckTCH: DoItTCH: OK" );
			data->tch_duration = doItTCHResult;
            return data;
            //AppliedData *outData = new AppliedData;
//             outData->tchData.FwdData = NULL;
//             outData->tchData.RevData = NULL;
            //outData->sdcData.Data = NULL;

            //memcpy( outData, &localData, sizeof( AppliedData ) );

            //return outData;
        }
        else {
            data->dataAfterApplyKey = std::vector< BYTE >();
			data->tch_duration = 0;
            memset( &data->sdcData, 0x00, sizeof( tSDCCHHandle ) );
            memset( &data->tchData, 0x00, sizeof( tTCHHandle ) );
            delete data;

//             localData.dataAfterApplyKey = std::vector< BYTE >();
//             //delete [] localData.tchData.RevData;
//             memset( &localData.sdcData, 0x00, sizeof( tSDCCHHandle ) );
//             memset( &localData.tchData, 0x00, sizeof( tTCHHandle ) );

            if( logFile != NULL ) 
                logFile->dump( "CheckTCH: DoItTCH: BAD" );

            return NULL;
        }
    }
	if( data->dataAfterApplyKey.size() != 0 ) 
        data->dataAfterApplyKey = std::vector< BYTE >();

//     if( localData.dataAfterApplyKey.size() != 0 ) 
//         localData.dataAfterApplyKey = std::vector< BYTE >();

    memset( &data->sdcData, 0x00, sizeof( tSDCCHHandle ) );
    memset( &data->tchData, 0x00, sizeof( tTCHHandle ) );
    delete data;

    //delete [] localData.tchData.RevData;
//     memset( &localData.sdcData, 0x00, sizeof( tSDCCHHandle ) );
//     memset( &localData.tchData, 0x00, sizeof( tTCHHandle ) );
    
    if( logFile != NULL ) 
        logFile->dump( "CheckTCH: readFile return bad code. Exit" );

    return NULL;
}

BOOL isZeroBufferA( const byte *buffer ) {
	int badCount = 0;
	for( int i = 0; i < 6; i++ )
		if( buffer[i] == 0x00 ) badCount ++;

	return (badCount > 5);
}

BOOL isZeroBufferW( const wchar_t *buffer ) {
	int badCount = 0;
	for( int i = 0; i < 6; i++ )
		if( buffer[i] == (wchar_t)0x00 ) badCount ++;

	return (badCount > 5);
}

AppliedData* CheckSDCCH( FileDescriptorData *file, const KeyData *const keyData, LogFile *logFile ) {
    if( logFile != NULL ) {
        logFile->dump( "Call CheckSDCCH with params: " );
        logFile->dump( "FileName: " + file->fileName );
        logFile->dump( "BS: " + file->baseStation );
        logFile->dump( "Key BS: " + keyData->BsName );
        logFile->dump( "Key: R1=" + convertIntToString(keyData->R1) + 
                           " R2=" + convertIntToString(keyData->R2) + 
                           " R3=" + convertIntToString(keyData->R3) );
    }

	//return NULL;

    AppliedData *data = new AppliedData;
    
    int dataSize = 0;

	data->tch_duration = 0;
	memset( &data->sdcData, 0x00, sizeof( tSDCCHHandle ) );
	memset( &data->tchData, 0x00, sizeof( tTCHHandle ) );
	data->dataAfterApplyKey = std::vector< BYTE >();

//     memset( &localData.sdcData, 0x00, sizeof( tSDCCHHandle ) );
//     memset( &localData.tchData, 0x00, sizeof( tTCHHandle ) );
//     localData.dataAfterApplyKey = std::vector< BYTE >();

    dataSize = readFile( file, data /*&localData*/ );
    if( logFile!= NULL) 
        logFile->dump( "CheckSDCCH: readFile return: " + convertIntToString(dataSize) );

    if ( ( dataSize != 0 ) && ( keyData->R1 != 0 ) && ( keyData->R2 != 0 ) && ( keyData->R3 != 0 ) ) {
        data->sdcData.Abet = 0xFF;

        data->sdcData.Data = &(data->dataAfterApplyKey[0]);
        data->sdcData.DataSize = dataSize;

//         localData.sdcData.Abet = 0xFF;
// 
//         localData.sdcData.Data = &(localData.dataAfterApplyKey[0]);
//         localData.sdcData.DataSize = dataSize;
                
        
        data->sdcData.R1 = keyData->R1;
        data->sdcData.R2 = keyData->R2;
        data->sdcData.R3 = keyData->R3;

//         localData.sdcData.R1 = keyData->R1;
//         localData.sdcData.R2 = keyData->R2;
//         localData.sdcData.R3 = keyData->R3;

        BOOL doItSDCCHResult = FALSE;
        
        try {
            doItSDCCHResult = DoItSDCCH( &data->sdcData /*&localData.sdcData*/ );
        } catch ( ... ) {
            if( logFile != NULL )
                logFile->dump( "Exception in DoItSDCCH" );
        }

        if ( doItSDCCHResult ) { 
            if( logFile != NULL ) 
                logFile->dump( "CheckSDCCH: DoItSDCCH OK" );

            if( data->sdcData.Abet /*localData.sdcData.Abet*/ != 0xFF ) {
				// МЕГА КОСТЫЛЬ !!!
				// проверим сам текст !!!
				if( data->sdcData.Abet == 0 ) {
					if( !isZeroBufferA( data->sdcData.Text ) )
						file->isSMS = TRUE;
				}
				else 
					if( !isZeroBufferW( data->sdcData.TextUCS2 ) )
						file->isSMS = TRUE;


                if( logFile != NULL ) 
                    logFile->dump( "CheckSDCCH: DoItSDCCH found SMS" );
            }

//             AppliedData *outData = new AppliedData;
//             memset( &outData->sdcData, 0x00, sizeof( tSDCCHHandle ) );
//             memset( &outData->tchData, 0x00, sizeof( tTCHHandle ) );
//             outData->dataAfterApplyKey = std::vector< BYTE >();
			
            return data; 
        }
        else {
            data->dataAfterApplyKey = std::vector< BYTE >();
            memset( &data->sdcData, 0x00, sizeof( tSDCCHHandle ) );
            memset( &data->tchData, 0x00, sizeof( tTCHHandle ) );            
            delete data;
//             localData.dataAfterApplyKey = std::vector< BYTE >();
//             memset( &localData.sdcData, 0x00, sizeof( tSDCCHHandle ) );
//             memset( &localData.tchData, 0x00, sizeof( tTCHHandle ) );            

            if( logFile != NULL ) 
                logFile->dump( "CheckSDCCH: DoItSDCCH: BAD" );

            return NULL;
        }
    }
    if( data->dataAfterApplyKey.size() != 0 ) 
        data->dataAfterApplyKey = std::vector< BYTE >();
    memset( &data->sdcData, 0x00, sizeof( tSDCCHHandle ) );
    memset( &data->tchData, 0x00, sizeof( tTCHHandle ) );
    delete data;

//     if( localData.dataAfterApplyKey.size() != 0 ) 
//         localData.dataAfterApplyKey = std::vector< BYTE >();
//     memset( &localData.sdcData, 0x00, sizeof( tSDCCHHandle ) );
//     memset( &localData.tchData, 0x00, sizeof( tTCHHandle ) );
    
    if( logFile != NULL ) logFile->dump( "CheckSDCCH: readFile return bad code. Exit" );
    return NULL;
}

bool isInRange( const FileDescriptorData &voiceFile, const FileDescriptorData &serviceFile, LogFile *logFile ) {
    //if( voiceFile.baseStation != serviceFile.baseStation )
	if( voiceFile.networkAndBaseStationId != serviceFile.networkAndBaseStationId )
        return false;

    if( logFile != NULL ) {
        logFile->dump( "isInRange: compare files:" );
        logFile->dump( "VoiceFile: " + voiceFile.fileName );
        logFile->dump( "ServiceFile: " + serviceFile.fileName );
    }

    // First file time is later than second file time.
    // SDC файл позже чем FTC
    if( ::CompareFileTime( &serviceFile.creationTimeIni, &voiceFile.creationTimeIni ) == 1 ) {
        if( logFile != NULL ) logFile->dump( "Service file later then voice file. Exit" );
        return false;
    }

    ULONG serviceFileTimeInSeconds = ConvertFileTimeToSeconds( serviceFile.creationTimeIni );
    ULONG voiceFileTimeInSeconds = ConvertFileTimeToSeconds( voiceFile.creationTimeIni );

    if( logFile != NULL ) {
        logFile->dump( "VoiceFile time in seconds: " + convertIntToString( voiceFileTimeInSeconds ) );
        logFile->dump( "ServiceFile time in seconds: " + convertIntToString( serviceFileTimeInSeconds ) );
    }

    // SDC раньше чем FTC
    __int64 elaps = static_cast<__int64>(voiceFileTimeInSeconds - serviceFileTimeInSeconds);
    if( (elaps <= 10) && (elaps >= 0) ) {
        if( logFile != NULL ) logFile->dump( "Service file isInRange. Exit" );
        return true;
    }
    else {
        if( logFile != NULL ) logFile->dump( "Service file later then voice file. Exit" );
        return false;
    }
}

void deleteAppliedData( AppliedData *data, LogFile *logFile ) {
    if( data != NULL ) {
        if( logFile != NULL ) logFile->dump( "deleteAppliedData: data not NULL" );

        if( data->dataAfterApplyKey.size() != 0 ) 
            data->dataAfterApplyKey = std::vector< BYTE >();
        
        
        memset( &data->sdcData, 0x00, sizeof( tSDCCHHandle ) );
        memset( &data->tchData, 0x00, sizeof( tTCHHandle ) );

        delete data;
    }
    else {
        if( logFile != NULL ) logFile->dump( "deleteAppliedData: data NULL. ERROR!!!" );
    }
}
