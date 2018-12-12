#include "FileAppender.h"
#include "jmsf/osie/EventArray.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/factory_GenericMultithreading.hpp"
#include "jmsf/mtf/factory_Multithreading.h"
#include "jmsf/mtf/Thread.h"
#include "jmsf/Casts.hpp"
#include "external_source_antiwarning.h"
#include "exception_FileAppender.h"


namespace nppntt {
namespace mdm {
namespace externals {
namespace others {


::jmsf::Boolean FileAppender::initializeFileAppender(
	const BOOL traceMode,
	const std::string &workFolder )
{
    _traceMode = FALSE;//traceMode;
    _workFolder = workFolder;
    oneTimeCheck = FALSE;

    openLog( "_fileAppender.log" );
    Log ( "Initialize fileFinder" );

    if ( !loadLastFileTime( _lastFoundFileTime ) ) {
        _lastFoundFileTime.dwHighDateTime = ULONG_MAX;
        _lastFoundFileTime.dwLowDateTime = ULONG_MAX;
        Log( "Loading last file time Error. Set to max" );
    }

    _fileFinder = FileFinder::create( _newFilenameQueue.getWeak() );

    if ( !_fileFinder->initializeFileFinder( traceMode, workFolder ) ) {
        _fileFinder.empty();
        Log( "fileFinder return error while initialize" );
        closeLog();
        return ::jmsf::False;
    }

    Log( "Initialize directoryWalker" );
    _directoryWalker = DirectoryWalker::create( _traceMode, _workFolder, _existentFilenameQueue.getWeak() );

    return ::jmsf::True;
}

void FileAppender::releaseFileAppender() {
    Log( "Stop fileFinder" );
    oneTimeCheck = FALSE;

    _fileFinder->releaseFileFinder();
    _fileFinder.empty();

    Log( "Stop directoryWalker" );

    _directoryWalker.empty();

    saveLastFileTime( _lastFoundFileTime );

    Log( "Done" );
    closeLog();
}

/*
[tswitch( T , V )]
T - тип перебора.
V - значение с которым сравниваем.
*/
#    define tswitch( T , V )\
    if( int __tswitch_check = 0 );\
    else for(\
    const T &__tswitch_value(V);\
    __tswitch_check == 0;\
    ++__tswitch_check )\
{int __tswitch_open = 0;

#    define tcase( D )\
}if( __tswitch_open || __tswitch_value == D ){__tswitch_open = 1;

#    define tdefault break;__tswitch_open = 0;};
#    define tbreak break;__tswitch_open = 0;

void FileAppender::run() throw( jmsf::Exception ) {
    FILETIME ft = {};
	BOOL fileWasFound = FALSE;

	if ( _existentFilenameQueue->takeMutex()->lock(), _existentFilenameQueue->getIsObjectAvailableEvent()->isSet() ) {
		const ::jmsf::ConstantPointer< std::string > existentFilename = _existentFilenameQueue->withdrawFirst().takeConstant();
		_existentFilenameQueue->takeMutex()->unlock();

		fileWasFound = TRUE;
        if( checkSaveFileTime( *existentFilename, &ft ) ) {
            Log( "Walker found New file: " + *existentFilename );
            std::string drive, dir, fileName, ext;
            ::std::list< FileDescriptorData >::iterator i;
            
            if( !parseFileName( *existentFilename, drive, dir, fileName, ext ) ) 
                throw 12;

            if( !findAppropriateFile( /*ext,*/ fileName, i ) ) {
                Log( "Append to notCompleteFiles" );
                FileDescriptorData newFileDescriptor = {};
                newFileDescriptor.fileName = fileName;
                newFileDescriptor.longPath = drive + dir;
                
                newFileDescriptor.appenderWorkFolder = _workFolder;

                newFileDescriptor.creationTime = ft;
                if( (newFileDescriptor.type = getFileType( ext )) == _INI ) {
                    Log( "Is INI file. Parse" );
                    parseIniFile( *existentFilename, newFileDescriptor );
                }
                _notCompleteFiles.push_back( newFileDescriptor );
            } else {
                // check extension of newFile
                switch( getFileType(ext) ) {
                case _SDC:
                    // переносим все из ини
                    Log( "Is SDC file. Found INI: " + i->longPath + i->fileName );
                    fillSDCDescriptorAndAppend( *existentFilename, i );
                    break;
                case _FTC:
                    // переносим все из ини
                    Log( "Is FTC file. Found INI: " + i->longPath + i->fileName );
                    fillFTCDescriptorAndAppend( *existentFilename, i );
                    break;
                case _INI:
                    // выясняем расширение сохраненного файла
                    if( i->type == _SDC ) {
                        Log( "Is INI file. Found SDC: " + i->longPath + i->fileName );
                        // читаем ини.
                        fillSDCDescriptorAndAppend( *existentFilename, i );
                    } else if ( i->type == _FTC ) {
                        Log( "Is INI file. Found FTC: " + i->longPath + i->fileName );
                        fillFTCDescriptorAndAppend( *existentFilename, i );
                    }
                    break;
                }
            }
        }
    } else {
		_existentFilenameQueue->takeMutex()->unlock();
	}

    if ( _newFilenameQueue->takeMutex()->lock(), _newFilenameQueue->getIsObjectAvailableEvent()->isSet() ) {
		const ::jmsf::ConstantPointer< std::string > newFilename = _newFilenameQueue->withdrawFirst().takeConstant();
		_newFilenameQueue->takeMutex()->unlock();
		fileWasFound = TRUE;
        // не проверяем на время, т.к. это всегда новые файлы
        const std::string fullFileName = _workFolder + *newFilename;
        Log( "Finder found New file: " + fullFileName );
        std::string drive, dir, fileName, ext;
        ::std::list< FileDescriptorData >::iterator i;
        if( !parseFileName( fullFileName, drive, dir, fileName, ext ) ) throw 12;
        if( !findAppropriateFile( fileName, i ) )
        {
            Log( "Append to notCompleteFiles" );
            FileDescriptorData newFileDescriptor = {};
            newFileDescriptor.fileName = fileName;
            newFileDescriptor.longPath = drive + dir;
            newFileDescriptor.appenderWorkFolder = _workFolder;
            getCreationTimeOfFile( fullFileName, &ft );

            // One time save NewFile time
            if ( !oneTimeCheck ) {
                _lastFoundFileTime = ft;
                oneTimeCheck = TRUE;
            }
            newFileDescriptor.creationTime = ft;
            if( (newFileDescriptor.type = getFileType( ext )) == _INI ) {
                Log( "Is INI file. Parse" );
                parseIniFile( fullFileName, newFileDescriptor );
            }
            _notCompleteFiles.push_back( newFileDescriptor );
        } else {
            // check extension of newFile
            switch( getFileType(ext) ) {
            case _SDC:
                // переносим все из ини
                Log( "Is SDC file. Found INI: " + i->longPath + i->fileName );
                fillSDCDescriptorAndAppend( fullFileName, i );
                break;
            case _FTC:
                // переносим все из ини
                Log( "Is FTC file. Found INI: " + i->longPath + i->fileName );
                fillFTCDescriptorAndAppend( fullFileName, i );
                break;
            case _INI:
                // выясняем расширение сохраненного файла
                if( i->type == _SDC ) {
                    Log( "Is INI file. Found SDC: " + i->longPath + i->fileName );
                    // читаем ини.
                    fillSDCDescriptorAndAppend( fullFileName, i );
                } else if ( i->type == _FTC ) {
                    Log( "Is INI file. Found FTC: " + i->longPath + i->fileName );
                    fillFTCDescriptorAndAppend( fullFileName, i );
                }
                break;
            }
        }
    } else {
		_newFilenameQueue->takeMutex()->unlock();
	}
}

BOOL FileAppender::getCreationTimeOfFile(const std::string fullFileName, FILETIME *creationTime)
{
    HANDLE hFile = INVALID_HANDLE_VALUE;
    hFile = ::CreateFileA( fullFileName.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if ( hFile != INVALID_HANDLE_VALUE ) {
		
        FILETIME ftWrite = {};
        SYSTEMTIME stUTC = {}, stLocal = {};
        
        if ( ::GetFileTime( hFile, NULL, NULL, &ftWrite ) ) {
            ::FileTimeToSystemTime(&ftWrite, &stUTC);
            ::SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
            ::SystemTimeToFileTime( &stLocal, creationTime );
            //::FileTimeToLocalFileTime( &ftWrite, creationTime );
            ::CloseHandle(hFile);
            return TRUE;
        }
        else {
            ::CloseHandle(hFile);
			return FALSE;
        }
    }
    else
        return FALSE;
}

BOOL FileAppender::checkSaveFileTime( const std::string fileName, FILETIME *ft )
{
    if ( getCreationTimeOfFile( fileName, ft ) )
    {
        // Проверяем, если время создания файла позже, чем сохраненное, то это новый файл
        if( (_lastFoundFileTime.dwHighDateTime != ULONG_MAX) &&
            (_lastFoundFileTime.dwLowDateTime != ULONG_MAX) )
        {
             // First file time is later than second file time.
             if( ::CompareFileTime( ft, &_lastFoundFileTime ) == 1 )
                return FALSE;
             else
                return TRUE;
        }
    }
    else
        return FALSE;

    return TRUE;
}


namespace hiddens {

	class ToUpper {

	public:
		  char operator ()( const char symbol ) const throw() {
			 return std::toupper( symbol );
		  }

	};

} // namespace


BOOL FileAppender::parseFileName( const std::string fullFileName, std::string &_drive, std::string &directory, std::string &fileName, std::string &fileExtension)
{
    // parse this file
    char fname[MAX_PATH] = {};
    char ext[MAX_PATH] = {};
    char dir[MAX_PATH] = {};
    char drive[MAX_PATH] = {};

    _splitpath(fullFileName.c_str(), drive, dir, fname, ext);

    fileExtension = ext;
    fileName      = fname;
    directory     = dir;
    _drive = drive;

    if ( fileExtension == "" ) {
        return FALSE;
	} else {
        std::transform( fileExtension.begin(), fileExtension.end(), fileExtension.begin(), hiddens::ToUpper() );
		return TRUE;
	}
}

BOOL FileAppender::findAppropriateFile( const std::string fileName, /*_FileType &type,*/ std::list< FileDescriptorData >::iterator &i)
{
    for ( i = _notCompleteFiles.begin(); i != _notCompleteFiles.end(); ++i ) {
        if ( i->fileName == fileName ) {
            return TRUE;
        }
    }
    return FALSE;
}

_FileType FileAppender::getFileType( const std::string ext )
{
    tswitch (std::string, ext){
        tcase (".INI") {
            return _INI;
        }tbreak;
        tcase (".SDC") {
            return _SDC;
        }tbreak;
        tcase (".FTC") {
            return _FTC;
        }tbreak;
        tdefault {
            return _INVALID;
        }
    }
    return _INVALID;
}

void FileAppender::parseIniFile( const std::string fullFilePath, FileDescriptorData &file)
{
    file.baseStation = findTokenData( fullFilePath, "BSName" );
	if( file.baseStation == "" )
		throw 12;
		
    file.network = findTokenData( fullFilePath, "Network" );
	if( file.network == "" )
		throw 12;

    file.temporaryNumber = findTokenData( fullFilePath, "Number0" );
	if( file.temporaryNumber == "" )
		throw 12;

    file.creationTimeIni = stringToFILETIME( findTokenData( fullFilePath, "CreateTime" ) );	
}

std::string FileAppender::findTokenData( const std::string fullFilePath, const std::string token )
{
    Log( "Parse ini file: " + fullFilePath + " search token: " + token );

    std::ifstream file;
    std::string tokenData ("");
    INT numberOfAttempts = 10;

    while( numberOfAttempts > 0 ) {
        file.open( fullFilePath );
        if( file.is_open() ) {
            while( !file.eof() ) {
                std::string line;
                std::getline(file, line);

                INT tokenPosition;
                if( (tokenPosition = line.find('='))== line.npos ) {
                    numberOfAttempts = 0;
                    break;
                }
                std::string key (line.begin(), line.begin() + tokenPosition);
                std::string data (line.begin() + tokenPosition + 1, line.end());

                if( key == token ) {
                    tokenData = data;

					if( tokenData == "" )
						throw 12;
                }
            }
            file.close();

			if( tokenData == "" )
				throw 12;

            break;
        }
        else {
            numberOfAttempts -= 1;
            ::Sleep(100);
        }
    }
	if( tokenData == "" )
		throw 12;

    return tokenData;
}

FILETIME FileAppender::stringToFILETIME( const std::string dateTime )
{
    FILETIME ft = {};
    if ( dateTime != "" ) {
        // parse string : 16.06.2010 21:01:23
        std::string workString = dateTime;
        INT tokenPosition = workString.find(".");

        std::string str_day ( workString.begin(), workString.begin() + tokenPosition );
        workString.erase( workString.begin(), workString.begin() + tokenPosition + 1 );

        tokenPosition = workString.find(".");
        std::string str_month ( workString.begin(), workString.begin() + tokenPosition );
        workString.erase( workString.begin(), workString.begin() + tokenPosition + 1 );

        tokenPosition = workString.find(" ");
        std::string str_year ( workString.begin(), workString.begin() + tokenPosition );
        workString.erase( workString.begin(), workString.begin() + tokenPosition + 1 );

        tokenPosition = workString.find(":");
        std::string str_hour ( workString.begin(), workString.begin() + tokenPosition );
        workString.erase( workString.begin(), workString.begin() + tokenPosition + 1 );

        tokenPosition = workString.find(":");
        std::string str_minute ( workString.begin(), workString.begin() + tokenPosition );
        workString.erase( workString.begin(), workString.begin() + tokenPosition + 1 );

        std::string str_second ( workString.begin(), workString.end() );
        workString.erase( workString.begin(), workString.end() );

        WORD year = convertStringToInt(str_year);
        WORD month = convertStringToInt(str_month);
        WORD day = convertStringToInt(str_day);
        WORD hour = convertStringToInt(str_hour);
        WORD minute = convertStringToInt(str_minute);
        WORD second = convertStringToInt(str_second);
        WORD millisecond = 0;

        //DateTime(year, month, day, hour, minute, second, millisecond, ft);
        SYSTEMTIME st = { year, month, 0, day, hour, minute, second, millisecond };
        ::SystemTimeToFileTime(&st, &ft);
    }
    else
        Log( "Empty dateTime string" );

    return ft;
}

WORD FileAppender::convertStringToInt(const std::string str) {
    WORD result = 0;
    std::istringstream s_year(str);
    s_year >> result;
    return result;
}

std::string FileAppender::convertIntToString( const DWORD value ) {
    std::ostringstream o;
    o << value;
    return o.str();
}

void FileAppender::fillSDCDescriptorAndAppend( const std::string SDCFileName, const std::list< FileDescriptorData >::iterator i ) {
    FILETIME currentTime = {};
    SYSTEMTIME currentSystemTime = {};
    //GetSystemTime(&currentSystemTime);
    ::GetLocalTime( &currentSystemTime );
    ::SystemTimeToFileTime(&currentSystemTime, &currentTime);

    // Выясним расширение
    if( i->type != _INI ) {
        // parse ini
        std::string drive, dir, fileName, ext;
        if( !parseFileName( SDCFileName, drive, dir, fileName, ext ) ) throw 12;

        std::string INIfullFilePath = i->longPath + i->fileName + ".INI";

        FileDescriptorData INIFileDescriptor = {};
        Log( "Is INI file. Parse" );
        parseIniFile( INIfullFilePath, INIFileDescriptor );

        // copy to SDC descriptor
        ::jmsf::Pointer< FileDescriptorData > SDCFileDescriptor =
			::jmsf::Pointer< FileDescriptorData >::createWeakFor(
				new FileDescriptorData );

        SDCFileDescriptor->type = _SDC;
        SDCFileDescriptor->R1 = SDCFileDescriptor->R2 = SDCFileDescriptor->R3 = 0;
		if( INIFileDescriptor.baseStation != "" )
			SDCFileDescriptor->baseStation = INIFileDescriptor.baseStation;
		else 
			throw 12;

        if( INIFileDescriptor.network != "" )
			SDCFileDescriptor->network = INIFileDescriptor.network;
		else
			throw 12;

		SDCFileDescriptor->networkAndBaseStationId = ~( unsigned int( 0 ) );
		SDCFileDescriptor->isSMSSussesfullSent = FALSE;
		SDCFileDescriptor->isStatisticsAlreadyPassed = FALSE;

        getCreationTimeOfFile( SDCFileName, &SDCFileDescriptor->creationTime );
        
		SDCFileDescriptor->creationTimeIni = INIFileDescriptor.creationTimeIni; 
		SDCFileDescriptor->addFileTime = currentTime;
		
// 		::FileTimeToSystemTime( &SDCFileDescriptor->addFileTime, &SDCFileDescriptor->st_addFileTime );
// 		::FileTimeToSystemTime( &SDCFileDescriptor->creationTime, &SDCFileDescriptor->st_creationTime );
// 		::FileTimeToSystemTime( &SDCFileDescriptor->creationTimeIni, &SDCFileDescriptor->st_creationTimeIni );

        SDCFileDescriptor->fileName = fileName;
        SDCFileDescriptor->longPath = drive + dir;
		if( INIFileDescriptor.temporaryNumber != "" )
			SDCFileDescriptor->temporaryNumber = INIFileDescriptor.temporaryNumber;
		else
			throw 12;
        
		SDCFileDescriptor->isSMS = FALSE;
        SDCFileDescriptor->donePercent = 0;

        dumpDescriptor( *SDCFileDescriptor );

		if( isBadTime( SDCFileDescriptor->addFileTime ) )
				Sleep( 0 );

		if( isBadTime( SDCFileDescriptor->creationTime ) )
				Sleep( 0 );

		if( isBadTime( SDCFileDescriptor->creationTimeIni ) )
				Sleep( 0 );

		_foundSDCfile->takeMutex()->lock();
        _foundSDCfile->appendBack( SDCFileDescriptor );
		_foundSDCfile->takeMutex()->unlock();

        _notCompleteFiles.erase( i );

    } else {
        // read info from i and append to SDC queue
        ::jmsf::Pointer< FileDescriptorData > SDCFileDescriptor =
			::jmsf::Pointer< FileDescriptorData >::createWeakFor(
				new FileDescriptorData );

        SDCFileDescriptor->type = _SDC;
        SDCFileDescriptor->R1 = SDCFileDescriptor->R2 = SDCFileDescriptor->R3 = 0;
		if( i->baseStation != "" )
			SDCFileDescriptor->baseStation = i->baseStation;
		else
			throw 12;
		if( i->network != "" )
			SDCFileDescriptor->network = i->network;
		else
			throw 12;

		SDCFileDescriptor->networkAndBaseStationId = ~( unsigned int( 0 ) );
		SDCFileDescriptor->isSMSSussesfullSent = FALSE;
		SDCFileDescriptor->isStatisticsAlreadyPassed = FALSE;

        /*SDCFileDescriptor->creationTime = */getCreationTimeOfFile( SDCFileName, &SDCFileDescriptor->creationTime ); //i->creationTime;
        SDCFileDescriptor->creationTimeIni = i->creationTimeIni;
        SDCFileDescriptor->fileName = i->fileName;
        SDCFileDescriptor->longPath = i->longPath;
		if( i->temporaryNumber != "" )
			SDCFileDescriptor->temporaryNumber = i->temporaryNumber;
		else
			throw 12;
        SDCFileDescriptor->addFileTime = currentTime;
        SDCFileDescriptor->isSMS = FALSE;
		SDCFileDescriptor->donePercent = 0;

// 		::FileTimeToSystemTime( &SDCFileDescriptor->addFileTime, &SDCFileDescriptor->st_addFileTime );
// 		::FileTimeToSystemTime( &SDCFileDescriptor->creationTime, &SDCFileDescriptor->st_creationTime );
// 		::FileTimeToSystemTime( &SDCFileDescriptor->creationTimeIni, &SDCFileDescriptor->st_creationTimeIni );

        dumpDescriptor( *SDCFileDescriptor );

		if( isBadTime( SDCFileDescriptor->addFileTime ) )
				Sleep( 0 );

		if( isBadTime( SDCFileDescriptor->creationTime ) )
				Sleep( 0 );

		if( isBadTime( SDCFileDescriptor->creationTimeIni ) )
				Sleep( 0 );

		_foundSDCfile->takeMutex()->lock();
        _foundSDCfile->appendBack( SDCFileDescriptor );
		_foundSDCfile->takeMutex()->unlock();

        _notCompleteFiles.erase( i );
    }
}

void FileAppender::fillFTCDescriptorAndAppend( const std::string FTCFileName, const std::list< FileDescriptorData >::iterator i )
{
    FILETIME currentTime = {};
    SYSTEMTIME currentSystemTime = {};
    //GetSystemTime(&currentSystemTime);
    ::GetLocalTime( &currentSystemTime );
    ::SystemTimeToFileTime(&currentSystemTime, &currentTime);

    // Выясним расширение
    if( i->type != _INI ) {
        // parse ini
        std::string drive, dir, fileName, ext;
        if( !parseFileName( FTCFileName, drive, dir, fileName, ext ) ) throw 12;

        std::string INIfullFilePath = i->longPath + i->fileName + ".INI";

        FileDescriptorData INIFileDescriptor = {};
        Log( "Is INI file. Parse" );
        parseIniFile( INIfullFilePath, INIFileDescriptor );

        // copy to FTC descriptor
        ::jmsf::Pointer< FileDescriptorData > FTCFileDescriptor =
			::jmsf::Pointer< FileDescriptorData >::createUnique(
				new FileDescriptorData );

        FTCFileDescriptor->type = _FTC;
        FTCFileDescriptor->R1 = FTCFileDescriptor->R2 = FTCFileDescriptor->R3 = 0;
		if( INIFileDescriptor.baseStation != "" )
			FTCFileDescriptor->baseStation = INIFileDescriptor.baseStation;
		else
			throw 12;
		if( INIFileDescriptor.network != "" )
			FTCFileDescriptor->network = INIFileDescriptor.network;
		else
			throw 12;

		FTCFileDescriptor->networkAndBaseStationId = ~( unsigned int( 0 ) );
		FTCFileDescriptor->isSMSSussesfullSent = FALSE;
		FTCFileDescriptor->isStatisticsAlreadyPassed = FALSE;

        getCreationTimeOfFile( FTCFileName, &FTCFileDescriptor->creationTime );
        FTCFileDescriptor->creationTimeIni = INIFileDescriptor.creationTimeIni;
        FTCFileDescriptor->fileName = fileName;
        FTCFileDescriptor->longPath = drive + dir;
		if( INIFileDescriptor.temporaryNumber != "" )
			FTCFileDescriptor->temporaryNumber = INIFileDescriptor.temporaryNumber;
		else
			throw 12;
        FTCFileDescriptor->addFileTime = currentTime;
        FTCFileDescriptor->isSMS = FALSE;
		FTCFileDescriptor->donePercent = 0;

// 		::FileTimeToSystemTime( &FTCFileDescriptor->addFileTime, &FTCFileDescriptor->st_addFileTime );
// 		::FileTimeToSystemTime( &FTCFileDescriptor->creationTime, &FTCFileDescriptor->st_creationTime );
// 		::FileTimeToSystemTime( &FTCFileDescriptor->creationTimeIni, &FTCFileDescriptor->st_creationTimeIni );

        dumpDescriptor( *FTCFileDescriptor );

		if( isBadTime( FTCFileDescriptor->addFileTime ) )
				Sleep( 0 );

		if( isBadTime( FTCFileDescriptor->creationTime ) )
				Sleep( 0 );

		if( isBadTime( FTCFileDescriptor->creationTimeIni ) )
				Sleep( 0 );

		_foundFTCfile->takeMutex()->lock();
        _foundFTCfile->appendBack( FTCFileDescriptor );
		_foundFTCfile->takeMutex()->unlock();

        _notCompleteFiles.erase( i );
    } else {
        // i is INI file
        ::jmsf::Pointer< FileDescriptorData > FTCFileDescriptor = ::jmsf::Pointer< FileDescriptorData >::createUnique( new FileDescriptorData );
        
        FTCFileDescriptor->type = _FTC;
        FTCFileDescriptor->R1 = FTCFileDescriptor->R2 = FTCFileDescriptor->R3 = 0;
		if( i->baseStation != "" )
			FTCFileDescriptor->baseStation = i->baseStation;
		else
			throw 12;
		if( i->network != "" )
			FTCFileDescriptor->network = i->network;
		else
			throw 12;

		FTCFileDescriptor->networkAndBaseStationId = ~( unsigned int( 0 ) );
		FTCFileDescriptor->isSMSSussesfullSent = FALSE;
		FTCFileDescriptor->isStatisticsAlreadyPassed = FALSE;

        /*FTCFileDescriptor->creationTime = */getCreationTimeOfFile( FTCFileName, &FTCFileDescriptor->creationTime );//i->creationTime;
        FTCFileDescriptor->creationTimeIni = i->creationTimeIni;
        FTCFileDescriptor->fileName = i->fileName;
        FTCFileDescriptor->longPath = i->longPath;
		if( i->temporaryNumber != "" )
			FTCFileDescriptor->temporaryNumber = i->temporaryNumber;
		else
			throw 12;
        FTCFileDescriptor->addFileTime = currentTime;
		FTCFileDescriptor->isSMS = FALSE;
        FTCFileDescriptor->donePercent = 0;

// 		::FileTimeToSystemTime( &FTCFileDescriptor->addFileTime, &FTCFileDescriptor->st_addFileTime );
// 		::FileTimeToSystemTime( &FTCFileDescriptor->creationTime, &FTCFileDescriptor->st_creationTime );
// 		::FileTimeToSystemTime( &FTCFileDescriptor->creationTimeIni, &FTCFileDescriptor->st_creationTimeIni );

        dumpDescriptor( *FTCFileDescriptor );

		if( isBadTime( FTCFileDescriptor->addFileTime ) )
				Sleep( 0 );

		if( isBadTime( FTCFileDescriptor->creationTime ) )
				Sleep( 0 );

		if( isBadTime( FTCFileDescriptor->creationTimeIni ) )
				Sleep( 0 );

		_foundFTCfile->takeMutex()->lock();
        _foundFTCfile->appendBack( FTCFileDescriptor );
		_foundFTCfile->takeMutex()->unlock();

        _notCompleteFiles.erase( i );
    }
}

void FileAppender::dumpDescriptor( FileDescriptorData &descriptor ) {
    std::string type;
    if( descriptor.type == _FTC ) type = "FTC";
    else if ( descriptor.type == _SDC ) type = "SDC";
    else if ( descriptor.type == _INI ) type = "INI";
    else if ( descriptor.type == _RTC ) type = "RTC";
    else if ( descriptor.type == _INVALID ) type = "INVALID";
    Log( "" );
    Log( "---- Start dump descriptor ----" );
    Log( "Type: " + type );
    Log( "BS: " + descriptor.baseStation );
    Log( "AddTime: " + convertIntToString( descriptor.addFileTime.dwLowDateTime ) + " " +
        convertIntToString( descriptor.addFileTime.dwHighDateTime ) );
    Log( "CreationTime: " + convertIntToString( descriptor.creationTime.dwLowDateTime ) + " " +
        convertIntToString( descriptor.creationTime.dwHighDateTime ) );
    Log( "CreationTimeIni: " + convertIntToString( descriptor.creationTimeIni.dwLowDateTime ) + " " +
        convertIntToString( descriptor.creationTimeIni.dwHighDateTime ) );
    Log( "FileName: " + descriptor.fileName );
    Log( "LongPath: " + descriptor.longPath );
    Log( "Network: " + descriptor.network );
    Log( "R1: " + convertIntToString( descriptor.R1 ) +
        " R2: " + convertIntToString( descriptor.R2 ) +
        " R3: " + convertIntToString( descriptor.R3 ) );
    Log( "TemporaryNumber: " + descriptor.temporaryNumber );
    Log( "---- Dump descriptor Done ----" );
    Log( "" );
}

 FileAppender::~FileAppender() {
	 releaseFileAppender();
 }

FileAppender::FileAppender(
		const ::jmsf::ConstantProxy< ::jmsf::TextString > &pathToFolderWithFiles,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > &newVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > &newServiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thisThread )
	:
		_pathToFolderWithFiles( pathToFolderWithFiles ),
		_foundFTCfile( newVoiceFileQueue ),
		_foundSDCfile( newServiceFileQueue ),
		_newFilenameQueue( ::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Pointer< std::string > >::instance()->createSynchronizedQueue() ),
		_existentFilenameQueue( ::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Pointer< std::string > >::instance()->createSynchronizedQueue() )
{
	::jmsf::Proxy< ::jmsf::mtf::Thread > internalThisThread = thisThread;
	initializeFileAppender( true, pathToFolderWithFiles->getCtext() );

	::jmsf::Proxy< ::jmsf::mtf::Thread > fileFinderThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();
	fileFinderThread->registerRunnable( ::jmsf::adjacentCast< Runnable >( _fileFinder.getWeak() ) );
	internalThisThread->appendNestedThread( fileFinderThread );

	::jmsf::Proxy< ::jmsf::mtf::Thread > directoryWalkerThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();
	directoryWalkerThread->registerRunnable( ::jmsf::adjacentCast< Runnable >( _directoryWalker.getWeak() ) );
	internalThisThread->appendNestedThread( directoryWalkerThread );

	internalThisThread->appendWaitableEvent( _newFilenameQueue->takeIsObjectAvailableEvent().getWeak() );
	internalThisThread->appendWaitableEvent( _existentFilenameQueue->takeIsObjectAvailableEvent().getWeak() );

//	appendNestedRunnable( ::jmsf::adjacentCast< Runnable >( _fileFinder.getWeak() ) );
//	appendNestedRunnable( ::jmsf::adjacentCast< Runnable >( _directoryWalker.getWeak() ) );
//	appendWaitableEvent( _newFilenameQueue->getOneselfIsObjectAvailableEvent() );
//	appendWaitableEvent( _existentFilenameQueue->getOneselfIsObjectAvailableEvent() );
}


} // namespace
}
}
}
