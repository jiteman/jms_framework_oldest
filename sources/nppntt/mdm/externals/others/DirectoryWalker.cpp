#include "DirectoryWalker.h"
#include "exception_FileAppender.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/mtf/Thread.h"


namespace nppntt {
namespace mdm {
namespace externals {
namespace others {


void DirectoryWalker::run() throw( jmsf::Exception )
{
    if ( !_scanDone ) {
        FindFileInDirectory(_workDirectory);

        //_scanDone = true;
        _thisThread->suspend();
        _thisThread->terminate();
    }
    else
        ::Sleep(10);
}

//catch( const jmsf::Exception &catchedException.getReason()->getCtext() )
void DirectoryWalker::FindFileInDirectory( const std::string &directory ) throw ( jmsf::Exception )
{
    WIN32_FIND_DATAA ffd;
    HANDLE hFind;
    std::string searchMask ("*");

    hFind = FindFirstFileA((directory /*+ "\\"*/ + searchMask).c_str(), &ffd);

    if (INVALID_HANDLE_VALUE == hFind) {
        throw exception_FileAppender( "FindFirstFile return invalid handle" );
        return;
    } 
    do {
        if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if ( (strcmp(ffd.cFileName, ".") != 0) && (strcmp(ffd.cFileName, "..") != 0) )
            {
                std::string subDirName;
                subDirName = directory + ffd.cFileName + "\\";
                
                try {
                    FindFileInDirectory(subDirName);
                } catch ( const jmsf::Exception & ) {
                    throw;
                }
            }
        }
        else {
            // append file to queue
            // Имя папки должно заканчиваться символом '\' 
            std::string newFile ( ffd.cFileName );
			_foundFiles->takeMutex()->lock();
            _foundFiles->appendBack( ::jmsf::Pointer< std::string >::createUnique( new std::string( directory /*+ "\\"*/ + newFile ) ) );
			_foundFiles->takeMutex()->unlock();
            Log( "Find file: " + directory + newFile );
        }
    }
    while (FindNextFileA(hFind, &ffd) != 0);

    FindClose(hFind);
}


} // namespace
}
}
}
