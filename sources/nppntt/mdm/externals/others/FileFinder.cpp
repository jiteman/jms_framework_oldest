#include "FileFinder.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/mtf/Thread.h"
#include "jmsf/osie/Event.h"
#include "jmsf/osie/ms_windows/ms_windows_Event.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/Casts.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace others {


BOOL FileFinder::initializeFileFinder( BOOL traceMode, const std::string workDirectory ) 
{
    _traceMode = traceMode;
    _folder = workDirectory;

    openLog( "_fileFinder.log" );

    _hDirectory = ::CreateFileA(_folder.c_str(), 
        GENERIC_READ,
        FILE_SHARE_READ|FILE_SHARE_WRITE|FILE_SHARE_DELETE,
        NULL,
        OPEN_EXISTING,
        FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED,
        NULL);

    if ( _hDirectory == INVALID_HANDLE_VALUE ) {
        {
            DWORD lastError = 0;
            lastError = ::GetLastError();
            std::string log (__FILE__); log += __LINE__; log += " LastError was: " + lastError;
            Log( log );
            closeLog();
        }
        return FALSE;
    }

    _asyncWait.hEvent = ::CreateEvent( NULL, TRUE, FALSE, NULL );
    if ( _asyncWait.hEvent == INVALID_HANDLE_VALUE ) {
        ::CloseHandle( _hDirectory );
        {
            DWORD lastError = 0;
            lastError = ::GetLastError();
            std::string log (__FILE__); log += __LINE__; log += " LastError was: " + lastError;
            Log( log );
            closeLog();
        }
        return FALSE;
    }
    // stop event
	_waitEvents[ 0 ] =
		::jmsf::constantDowncast< ::jmsf::osie::ms_windows::ms_windows_Event >(
			_thisThread->takeSuspendEvent().getWeak(), ::jmsf::CONSTANT_TEXT_STRING( "::jmsf::osie::Event -> ::jmsf::osie::ms_windows::ms_windows_Event" ) )->getHandle();

//    _waitEvents[0] = ::CreateEvent( NULL, TRUE, FALSE, NULL );
    if ( _waitEvents[0] == INVALID_HANDLE_VALUE ) {
        ::CloseHandle( _asyncWait.hEvent );
        ::CloseHandle( _hDirectory );
        {
            DWORD lastError = 0;
            lastError = ::GetLastError();
            std::string log (__FILE__); log += __LINE__; log += " LastError was: " + lastError;
            Log( log );
            closeLog();
        }
        return FALSE;
    }
    _waitEvents[1] = _asyncWait.hEvent;
    return TRUE;
}

void FileFinder::releaseFileFinder()
{
    if ( _hDirectory != INVALID_HANDLE_VALUE )
        ::CloseHandle( _hDirectory );
    if ( _asyncWait.hEvent != INVALID_HANDLE_VALUE ) 
        ::CloseHandle( _asyncWait.hEvent );
    if ( _waitEvents[0] != INVALID_HANDLE_VALUE )
        ::CloseHandle( _waitEvents[0] );

//     //////////////////////////////////////////////////////////////////////////
//     // Begin. Блядский код. Хз как ваще
//     // Типа что бы почистить queue
//     std::string temp;
//     while ( get(temp) ) {}
//     // End. Блядский код. Хз как ваще
//     //////////////////////////////////////////////////////////////////////////
    Log( "Release Done" );
    closeLog();
}

void FileFinder::run() throw( jmsf::Exception )
{
    DWORD numberOfBytesTransferred = 0;
    INT notifyBufferSize = sizeof( _notifyBuffer );
    memset( _notifyBuffer, 0x00, notifyBufferSize );
    ::ReadDirectoryChangesW(_hDirectory, _notifyBuffer, notifyBufferSize, TRUE, 
                            _dwNotifyFilter, NULL, &_asyncWait, NULL);

    // Must be waits Stop/New file events
    if ( !_done ) {
        if ( ::WaitForMultipleObjects( 2, _waitEvents, FALSE, INFINITE) == WAIT_OBJECT_0 ) {
            ::ResetEvent( _waitEvents[0] );
            //_done = TRUE;
            Log( "Catch stop event" );
            _thisThread->suspend();
            _thisThread->terminate();
        }
        else {
            ::ResetEvent( _asyncWait.hEvent );
            ::GetOverlappedResult( _hDirectory, &_asyncWait, &numberOfBytesTransferred, FALSE );

            if ( numberOfBytesTransferred != 0) {
                DWORD seek = 0;
                while ( seek < numberOfBytesTransferred ) {
                    // Внимательно сюда глядеть. Первое поле - это смещение для следующей структуры
                    PFILE_NOTIFY_INFORMATION pNotify = PFILE_NOTIFY_INFORMATION( _notifyBuffer + seek );
                    seek += pNotify->NextEntryOffset;

                    if ( pNotify->Action == FILE_ACTION_ADDED ) {
                        WCHAR szwFileName[MAX_PATH] = {};
                        ULONG ulCount = std::min( static_cast< DWORD >( pNotify->FileNameLength / 2 ), static_cast< DWORD >( MAX_PATH - 1 ) );
                        wcsncpy(szwFileName, pNotify->FileName, ulCount);
                        std::wstring wFileName ( szwFileName );
                        std::string fileName = convertWidestringToString( wFileName );
						_foundFiles->takeMutex()->lock();
                        _foundFiles->appendBack( ::jmsf::Pointer< std::string >::createUnique( new std::string( fileName ) ) );
						_foundFiles->takeMutex()->unlock();
                        Log( "Found file: " + fileName );
                    }
                    if( pNotify->NextEntryOffset == 0 )
                        break;
                } // while
            }
        }
    } // if not _done
    else Sleep(10);
}


} // namespace
}
}
}
