#include "abstractLog.h"

LogFile *createLog() {
    return NULL;                       
}

void deleteLog( LogFile * ) { // logFile

}    


LogFile::LogFile( const LogFile & ) throw() // other
{}

const LogFile &LogFile::operator =( const LogFile &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}
