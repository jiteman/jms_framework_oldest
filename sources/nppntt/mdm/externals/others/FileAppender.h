#pragma once

#include "jmsf/mtf/Runnable.h"
//#include "jmsf/osie/runup/Thread.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/TextString.hxx"

#include "StringAlgorithms.h"

#include <direct.h>

#include <string>
#include <queue>
#include <list>

#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <ctime>

// Собирает инфу от Walkera и Findera
// Читает конфиги и распределяет файлы по двум очередям: FTC и SDC

//#include "FileDescription.h"
#include "abstractFileDescriptor.h"

#include "DirectoryWalker.h"
#include "FileFinder.h"


namespace nppntt {
namespace mdm {
namespace externals {
namespace others {


class FileAppender :
	public virtual ::jmsf::mtf::Runnable
{

public:
	// virtual
    ~FileAppender();

    ::jmsf::Boolean initializeFileAppender( const BOOL traceMode, const std::string &workFolder );
    void releaseFileAppender();


    ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > getFtcQueue() {
		return _foundFTCfile.getWeak();
    }

    ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > getSdcQueue() {
        return _foundSDCfile.getWeak();
    }

public:
    // virtuals 
    void run() throw( jmsf::Exception );
    //~virtuals

private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > _foundFTCfile;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > _foundSDCfile;	
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< std::string > > > _newFilenameQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< std::string > > > _existentFilenameQueue;

    std::list< FileDescriptorData > _notCompleteFiles;

    std::string _workFolder;

    FILETIME _lastFoundFileTime;

    BOOL _traceMode;
    std::ofstream _logFile;

    BOOL oneTimeCheck;

    void openLog( const std::string &logName ) {
        if ( _traceMode ) {
            _mkdir( "appenderLogs" );
			DWORD currentThreadID = ::GetCurrentThreadId();
			std::ostringstream o;
			o << currentThreadID;
            _logFile.open( "appenderLogs\\" + ::getLastFolderName( _workFolder ) + o.str() + logName );
		}
    }

    void closeLog() {
        if ( _traceMode ) {
            _logFile.flush();
            _logFile.close();
        }
    }

    const std::string TimeToStr(const std::time_t& time) { return std::ctime( &time ); }
    std::time_t GetTimeT() { return std::time( 0 ); }
    const std::string GetTime() { return TimeToStr( GetTimeT() ); }

    void Log( std::string line ) {
        if ( _traceMode && _logFile.is_open() ) {
            std::string currentTime = GetTime();
            currentTime.erase( currentTime.end() - 1, currentTime.end() );
            _logFile <<  currentTime + "  " + line << std::endl;
        }
    }

    void dumpDescriptor( FileDescriptorData &descriptor ) ;

    BOOL loadLastFileTime( FILETIME &time ) {
        std::ifstream timeFile;
        timeFile.open( ::getLastFolderName( _workFolder ) + "lastTime.dat" );
        if ( timeFile.is_open() ) {
            timeFile >> time.dwLowDateTime;
            timeFile >> time.dwHighDateTime;

			if ( time.dwLowDateTime == 0 && time.dwHighDateTime == 0 ) {
				time.dwLowDateTime = ULONG_MAX;
				time.dwHighDateTime = ULONG_MAX;
			}

            timeFile.close();
            return TRUE;
        }
        return FALSE;
    }

    void saveLastFileTime( FILETIME time ) {
        std::ofstream timeFile;
        timeFile.open( ::getLastFolderName( _workFolder ) + "lastTime.dat" );
        if ( timeFile.is_open() ) {
            timeFile << time.dwLowDateTime << std::endl;
            timeFile << time.dwHighDateTime << std::endl;
            timeFile.flush();
            timeFile.close();
        }
    }
    
	BOOL isBadTime( FILETIME ft ) {
		if( ft.dwHighDateTime == 0x00 || ft.dwLowDateTime == 0x00 )
			return TRUE;

		return FALSE;
	}

    BOOL getCreationTimeOfFile(const std::string fullFileName, FILETIME *creationTime);
    BOOL checkSaveFileTime( const std::string fileName, FILETIME *ft );
    BOOL parseFileName( const std::string fullFileName, std::string &drive, std::string &directory, std::string &fileName, std::string &fileExtension);
    BOOL findAppropriateFile( /*const std::string ext,*/ const std::string fileName, std::list< FileDescriptorData >::iterator &i);
    _FileType getFileType( const std::string ext );
    void parseIniFile( const std::string fullFilePath, FileDescriptorData &file );
    std::string findTokenData( const std::string fullFilePath, const std::string token );
    FILETIME stringToFILETIME( const std::string dateTime );
    WORD convertStringToInt( const std::string str );
    std::string convertIntToString( const DWORD value );

    void fillSDCDescriptorAndAppend( const std::string newFile, const std::list< FileDescriptorData >::iterator i );
    void fillFTCDescriptorAndAppend( const std::string newFile, const std::list< FileDescriptorData >::iterator i );

    ::jmsf::Pointer< FileFinder > _fileFinder;
    ::jmsf::Pointer< DirectoryWalker > _directoryWalker;
 
protected:
    FileAppender(
		const ::jmsf::ConstantProxy< ::jmsf::TextString > &pathToFolderWithFiles,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > &newVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > &newServiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thisThread );

private:
	FileAppender( const FileAppender & ) throw()
	{}

	const FileAppender &operator =( const FileAppender &other ) throw() {
		if ( this == &other ) return *this;

		// copy
		return *this;
	}

private:
	const ::jmsf::ConstantProxy< ::jmsf::TextString > _pathToFolderWithFiles;
	
};


} // namespace
}
}
}
