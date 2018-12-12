#pragma once

#include "jmsf/mtf/Runnable.h"
#include "jmsf/mtf/SynchronizedQueue.hxx"
#include "jmsf/mtf/Thread.hxx"

#include "StringAlgorithms.h"

#include "temporary_windows_include.h"

#include <direct.h>

#include <iostream>
#include <fstream>

//#include <iso646.h>

#include <string>
//#include <queue>

#include "jmsf/Proxies.hpp"
#include "jmsf/Pointers.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace others {


// Занимается обходом по дереву и возвращает имена файликов

// Имя папки должно заканчиваться символом '\'
class DirectoryWalker :
	public ::jmsf::mtf::Runnable
{
public:
    static ::jmsf::Pointer< DirectoryWalker > create(
		const BOOL traceMode,
		const std::string &workDirectory,
		::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< std::string > > > existentFilenameQueue )
	{
        return ::jmsf::Pointer< DirectoryWalker >::createUnique(
			new DirectoryWalker(
				traceMode,
				workDirectory,
				existentFilenameQueue ) );
    }

    ~DirectoryWalker() { Log( "Done" ); closeLog(); }

//     // May be Lock !!!!
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
    void run() throw(jmsf::Exception );
    //~virtuals
    
private:
    std::string _workDirectory;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< std::string > > > _foundFiles;
//    std::queue< std::string > _foundFiles;
    BOOL _scanDone; // Флаг выставляется после вызова FindFileInDirecroty. Дальше поток переходит в Sleep(10)
    BOOL _traceMode;
    std::ofstream _logFile;
	::jmsf::Proxy< ::jmsf::mtf::Thread > _thisThread;

    void openLog( const std::string &logName ) {
        if ( _traceMode ) {
            _mkdir( "appenderLogs" );
            _logFile.open( "appenderLogs\\" + ::getLastFolderName( _workDirectory ) + logName );
        }
    }

    void closeLog() {
        if ( _traceMode ) {
            _logFile.flush();
            _logFile.close();
        }
    }

    void Log( std::string line ) {
        if ( _traceMode && _logFile.is_open() ) {
            _logFile << line << std::endl;
        }
    }

    DirectoryWalker(
		const BOOL traceMode,
		const std::string &workDirectory,
		::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< std::string > > > existentFilenameQueue )
		:
			_foundFiles( existentFilenameQueue ),
			_workDirectory( workDirectory )
	{        
        _scanDone = FALSE;
        _traceMode = traceMode;
        openLog( "_directoryWalker.log" );
    }

	void setPointerToThisThread( const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) throw() {
		_thisThread = thread;
	}
    
    void FindFileInDirectory( const std::string &directory ) throw ( jmsf::Exception );

private:
	DirectoryWalker( const DirectoryWalker & ) throw()
	{}

	const DirectoryWalker &operator =( const DirectoryWalker &other ) throw() {
		if ( this == &other ) return *this;

		// copy
		return *this;
	}

};


} // namespace
}
}
}
