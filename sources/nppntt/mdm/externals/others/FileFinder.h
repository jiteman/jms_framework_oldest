#pragma once

#include "jmsf/mtf/Runnable.h"
#include "jmsf/mtf/SynchronizedQueue.hxx"
#include "jmsf/mtf/Thread.hxx"
#include "jmsf/PointersAndProxies.hpp"

#include "StringAlgorithms.h"

#include "temporary_windows_include.h"
#include <string>
//#include <queue>

#include <direct.h>

#include <iostream>
#include <fstream>

//#include <iso646.h>

#include "external_header_antiwarning.h"


namespace nppntt {
namespace mdm {
namespace externals {
namespace others {


// Становится на эвент и ждет появления новых файлов
// Имя папки должно заканчиваться символом '\'
class FileFinder :
	public ::jmsf::mtf::Runnable
{

public:
    static ::jmsf::Pointer< FileFinder > create(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< std::string > > > &newFilenameQueue )
	{
		return ::jmsf::Pointer< FileFinder >::createUnique( new FileFinder( newFilenameQueue ) );
	}

    ~FileFinder() {}

    BOOL initializeFileFinder( BOOL traceMode, const std::string workDirectory );
    void releaseFileFinder();

    void stopRunning() {
        ::SetEvent( _waitEvents[0] );
    }

//     // Must be Lock !!!!
//     BOOL get( std::string &fileName ) {
//         if ( not _foundFiles.empty() ) {
//             fileName = _foundFiles.front();
//             _foundFiles.pop();
//             return TRUE;
//         } 
//         return FALSE;
//     }

public:
    // virtuals 
    void run() throw( jmsf::Exception );
    //~virtuals

private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< std::string > > > _foundFiles;
//    std::queue< std::string > _foundFiles;
    std::string _folder;

    BOOL _traceMode;
    std::ofstream _logFile;
    
    HANDLE _hDirectory;

    DWORD _dwNotifyFilter;
    _FILE_NOTIFY_INFORMATION _notifyInfo;
    BYTE _notifyBuffer[4096];
    OVERLAPPED _asyncWait;
    HANDLE _waitEvents[2];
    BOOL _done;

	::jmsf::Proxy< ::jmsf::mtf::Thread > _thisThread;

    std::wstring convertStringToWideString( const std::string &s ) {
        int len;
        int slength = (int)s.length() + 1;
        len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0); 
        wchar_t* buf = new wchar_t[len];
        MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
        std::wstring r(buf);
        delete[] buf;
        return r;
    }

    std::string convertWidestringToString( const std::wstring &s ) {
        int len;
        int slength = (int)s.length() + 1;
        len = WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, 0, 0, 0, 0); 
        char* buf = new char[len];
        WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, buf, len, 0, 0); 
        std::string r(buf);
        delete[] buf;
        return r;
    }

    void openLog( const std::string &logName ) {
        if ( _traceMode ) {
            _mkdir( "appenderLogs" );
			DWORD currentThreadID = ::GetCurrentThreadId();
			std::ostringstream o;
			o << currentThreadID;
            _logFile.open( "appenderLogs\\" + ::getLastFolderName( _folder ) + o.str() + logName );
        }
    }

    void closeLog() {
        if ( _traceMode ) {
            _logFile.flush();
            _logFile.close();
        }
    }

    void Log( const std::string &line ) {
        if ( _traceMode && _logFile.is_open() ) {
            _logFile << line << std::endl;
        }
    }

    FileFinder( const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< std::string > > > &newFilenameQueue )
		:
			_foundFiles( newFilenameQueue )
	{
        _hDirectory = INVALID_HANDLE_VALUE;
        _dwNotifyFilter = FILE_NOTIFY_CHANGE_FILE_NAME; 
            /*Any file name change in the watched directory or subtree causes a change 
			  notification wait operation to return. 
			  Changes include renaming, creating, or deleting a file.*/
	
	    _waitEvents[0] = _waitEvents[1] = INVALID_HANDLE_VALUE;
	    _done = FALSE;

	    memset( &_notifyInfo, 0x00, sizeof(_notifyInfo) );
	    memset( _notifyBuffer, 0x00, sizeof(_notifyBuffer) );
	    memset( &_asyncWait, 0x00, sizeof(OVERLAPPED) );
    }

	void setPointerToThisThread( const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) throw() {
		_thisThread = thread;
	}

private:
	FileFinder( const FileFinder & ) throw()
	{}

	const FileFinder &operator =( const FileFinder &other ) {
		if ( this == &other ) return *this;

		// copy
		return *this;
	}

};


} // namespace
}
}
}
