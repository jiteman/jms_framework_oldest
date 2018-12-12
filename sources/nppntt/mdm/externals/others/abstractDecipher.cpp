#include "abstractDecipher.h"

#include "external_source_antiwarning.h"

#include <direct.h>

#ifdef _DEBUG
    static std::ofstream _logDecipher;
#endif

#ifdef _EMULATION_DECIPHER
static unsigned int emulationDecipherTime = 0;
static int emulationDoneCounter = 1;

static std::hash_map< std::string, _Keys > _keysMap;

int emulationGetRegsForThisFile( const std::string &fileName, unsigned int *Reg1, unsigned int *Reg2, unsigned int *Reg3  ) {
    const std::hash_map< std::string, _Keys >::const_iterator foundedKey = _keysMap.find( fileName );
    int sessionResult = 0;

    if( foundedKey == _keysMap.end() )
        return -1;
    else {
        *Reg1 = foundedKey->second.R1;
        *Reg2 = foundedKey->second.R2;
        *Reg3 = foundedKey->second.R3;
        sessionResult = foundedKey->second.sessionResult;

        return sessionResult;
    }
}
#endif

#ifdef _DUMP_KEYS
extern std::string convertIntToString( const ULONG value );

static std::ofstream _decipherKeys( "_decipherKeys.log" ); 
    
void dumpDecipherKeys( const std::string fileName, unsigned int R1, unsigned int R2, unsigned int R3, int sessionResult ) {
    _decipherKeys << fileName << " " 
        << convertIntToString( R1 ) << " " 
        << convertIntToString( R2 ) << " " 
        << convertIntToString( R3 ) << " " 
        << convertIntToString( sessionResult ) << std::endl;
    _decipherKeys.flush();
}
#endif

static HINSTANCE hDecipherDll = NULL;

typedef int (__stdcall *fDecipher_Init)( int AlphaCount, bool logToFile, bool Emulation );
typedef int (__stdcall *fDecipher_Destroy)();
typedef int (__stdcall *fDecipher_StartSession)( void *data, int dataSize, char *baseStationName );
typedef int (__stdcall *fDecipher_GetSessionProgress)( int &sessionProgress ); // var
typedef int (__stdcall *fDecipher_GetBusy) (bool &Busy ); // var
typedef int (__stdcall *fDecipher_SetTimeLimit)( int limit );
typedef int (__stdcall *fDecipher_Wait)();
typedef int (__stdcall *fDecipher_GetSessionResult)( int &sessionResult ); // var
typedef int (__stdcall *fDecipher_GetSessionRegs)( unsigned int &R1, unsigned int &R2, unsigned int &R3 );

fDecipher_Init               decipher_Init;
fDecipher_Destroy            decipher_Destroy;
fDecipher_StartSession       decipher_StartSession;
fDecipher_GetSessionProgress decipher_GetSessionProgress;
fDecipher_GetBusy            decipher_GetBusy;
fDecipher_SetTimeLimit       decipher_SetTimeLimit;
fDecipher_Wait               decipher_Wait;
fDecipher_GetSessionResult   decipher_GetSessionResult;
fDecipher_GetSessionRegs     decipher_GetSessionRegs;

bool loadDecipherDll()
{
#ifdef _DEBUG
    DWORD currentThreadID = ::GetCurrentThreadId();
    std::ostringstream o;
    o << currentThreadID;
    _mkdir("decipherLogs");
    _logDecipher.open( "decipherLogs\\" + o.str() + "decipher.log" );    
#endif
    hDecipherDll = LoadLibraryA("DecipherDLL.dll");
    if (hDecipherDll != NULL) {
        decipher_Init = (fDecipher_Init)GetProcAddress(hDecipherDll, "Decipher_Init");
        if (NULL == decipher_Init) { FreeLibrary(hDecipherDll); return false; }

        decipher_Destroy = (fDecipher_Destroy)GetProcAddress(hDecipherDll, "Decipher_Destroy");
        if (NULL == decipher_Destroy) { FreeLibrary(hDecipherDll); return false; }

        decipher_StartSession = (fDecipher_StartSession)GetProcAddress(hDecipherDll, "Decipher_StartSession");
        if (NULL == decipher_StartSession) { FreeLibrary(hDecipherDll); return false; }

        decipher_GetSessionProgress = (fDecipher_GetSessionProgress)GetProcAddress(hDecipherDll, "Decipher_GetSessionProgress");
        if (NULL == decipher_GetSessionProgress) { FreeLibrary(hDecipherDll); return false; }

        decipher_GetBusy = (fDecipher_GetBusy)GetProcAddress(hDecipherDll, "Decipher_GetBusy");
        if (NULL == decipher_GetBusy) { FreeLibrary(hDecipherDll); return false; }

        decipher_SetTimeLimit = (fDecipher_SetTimeLimit)GetProcAddress(hDecipherDll, "Decipher_SetTimeLimit");
        if (NULL == decipher_SetTimeLimit) { FreeLibrary(hDecipherDll); return false; }

        decipher_Wait = (fDecipher_Wait)GetProcAddress(hDecipherDll, "Decipher_Wait");
        if (NULL == decipher_Wait) { FreeLibrary(hDecipherDll); return false; }

        decipher_GetSessionResult = (fDecipher_GetSessionResult)GetProcAddress(hDecipherDll, "Decipher_GetSessionResult");
        if (NULL == decipher_GetSessionResult) { FreeLibrary(hDecipherDll); return false; }

        decipher_GetSessionRegs = (fDecipher_GetSessionRegs)GetProcAddress(hDecipherDll, "Decipher_GetSessionRegs");
        if (NULL == decipher_GetSessionRegs) { FreeLibrary(hDecipherDll); return false; }
    }
    else {
#ifdef _DEBUG
        if( _logDecipher.is_open() ) 
            _logDecipher << "Load decipher dll BAD" << std::endl;
#endif
        return false;
    }
#ifdef _DEBUG
    if( _logDecipher.is_open() ) 
        _logDecipher << "Load decipher dll OK" << std::endl;
#endif
    return true;
}

void unloadDecipherDll()
{
#ifdef _DEBUG
    if( _logDecipher.is_open() ) {
        _logDecipher.flush();
        _logDecipher.close();
    }
#endif
#ifdef _DUMP_KEYS
    if( _decipherKeys.is_open() ) {
        _decipherKeys.flush();
        _decipherKeys.close();
    }
#endif
    FreeLibrary(hDecipherDll);
    hDecipherDll = NULL;
}

bool decipherInitialize()
{
    try {
#ifdef _DEBUG
        _logDecipher << "Initialize decipher" << std::endl;
#endif
#ifndef _EMULATION_DECIPHER
        decipher_Init( 4, TRUE, FALSE );
#else
        // load saved keys from file
        std::ifstream _decipherKeys( "_decipherKeys.log" );
        if( _decipherKeys.is_open() ) {
            while( !_decipherKeys.eof() ) {
                std::string fileName;
                unsigned int R1 = 0, R2 = 0, R3 = 0;
                int sessionResult = 0;

                _decipherKeys >> fileName; if( _decipherKeys.eof() ) break;
                _decipherKeys >> R1;       if( _decipherKeys.eof() ) break;
                _decipherKeys >> R2;       if( _decipherKeys.eof() ) break;
                _decipherKeys >> R3;       if( _decipherKeys.eof() ) break;
                _decipherKeys >> sessionResult;

                _Keys key = {};
                key.R1 = R1; key.R2 = R2; key.R3 = R3; key.sessionResult = sessionResult;
                _keysMap.insert( _keysMap.end(),  std::make_pair(fileName, key) );
            }
            _decipherKeys.close();
        }
#endif
    } catch ( ... ) {
        return false;
    }
    return true;
}

bool decipherRelease()
{
    try {
#ifdef _DEBUG
        _logDecipher << "Release decipher" << std::endl;
#endif
#ifndef _EMULATION_DECIPHER
        decipher_Destroy();
#endif
    } catch ( ... ) {
        return false;
    }
    return true;
}

bool decipherThisFile( FileDescriptorData *voiceFile, KeyData *key ) {
    key->R1 = 0; key->R2 = 0; key->R3 = 0;
	key->networkAndBaseStationId = ~(unsigned int ( 0 ) );
    key->BsName = "";

    HANDLE hFile = INVALID_HANDLE_VALUE;
    std::string fullFilePath = voiceFile->longPath + voiceFile->fileName + ".FTC";
    hFile = ::CreateFileA( fullFilePath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
    if( hFile != INVALID_HANDLE_VALUE ) {
		
        DWORD fileSize = 0;
        fileSize = ::GetFileSize( hFile, NULL);
        if( fileSize != INVALID_FILE_SIZE ) {
			// Сколько полных tA51_Handle в файле
            //fileSize = ( fileSize / sizeof( tA51_Handle ) ) * sizeof( tA51_Handle );

            std::vector< BYTE >fileData( fileSize );
            DWORD bytesRead = 0;
            ::ReadFile( hFile, /*fileData*/&fileData[ 0 ], fileSize, &bytesRead, NULL );
            ::CloseHandle( hFile );
            if( bytesRead == fileSize ) {
                char *BS = new char[voiceFile->baseStation.length() + 1];
                strncpy(BS, voiceFile->baseStation.c_str(), voiceFile->baseStation.length());
                BS[voiceFile->baseStation.length()] = '\0';

				int sessionResult = 0;
                
				unsigned int Reg1 = 0, Reg2 = 0, Reg3 = 0;
				try {

#ifndef _EMULATION_DECIPHER
                decipher_StartSession( /*fileData*/&fileData[ 0 ], fileSize, BS );
                sessionResult = decipher_Wait();
                decipher_GetSessionRegs(Reg1, Reg2, Reg3);
#else
                sessionResult = emulationGetRegsForThisFile( voiceFile->fileName, &Reg1, &Reg2, &Reg3 );
                if( sessionResult == -1 ) {
                    Reg1 = 0; Reg2 = 0; Reg3 = 0;
                }
#endif
				//delete fileData;
                fileData = std::vector< BYTE >();
				delete BS;
#ifdef _DUMP_KEYS
                dumpDecipherKeys( voiceFile->fileName, Reg1, Reg2, Reg3, sessionResult );                
#endif
				} catch( ... ) {
#ifdef _DEBUG
	 				_logDecipher << "Error catched" << std::endl;
#endif
	 			}

                if( sessionResult == 0 ) {
                    if( ( Reg1 != 0 ) && ( Reg2 != 0 ) && ( Reg3 != 0 ) ) {
                        
                        key->R1 = Reg1; key->R2 = Reg2; key->R3 = Reg3;
                        key->BsName = voiceFile->baseStation;
						key->networkAndBaseStationId = voiceFile->networkAndBaseStationId;

                        voiceFile->R1 = Reg1; voiceFile->R2 = Reg2; voiceFile->R3 = Reg3;
						return true;
                    }
                    else {
                        return false;
                    }
                }
                else {
#ifdef _DEBUG
					_logDecipher << "Error while deciphering was: " << sessionResult << std::endl;
#endif
				}
            }
            else {
                //delete fileData;
                fileData = std::vector< BYTE >();
                return false;   
            }
        }
        else {
            ::CloseHandle( hFile );
            return false;
        }
    }
    else 
        return false;
	
    return false;
}

void decipherSetTimeLimit( const _decipherTimeLimit &timeLimit ) {
#ifdef _DEBUG   
    _logDecipher << "decipherSetTimeLimit with params: " + timeLimit.timeLimitInSeconds << std::endl;
#endif

#ifndef _EMULATION_DECIPHER
    decipher_SetTimeLimit(timeLimit.timeLimitInSeconds * 1000);
#else
    emulationDecipherTime = timeLimit.timeLimitInSeconds * 1000;
#endif
}

int  decipherGetCurrentVoiceFileProgress() {
    int sessionProgress = 0;

#ifndef _EMULATION_DECIPHER
    decipher_GetSessionProgress( sessionProgress );
#else
    sessionProgress = emulationDoneCounter ++; 
#endif

    return sessionProgress;
}
