#include "ms_windows_BufferedFile.h"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace osie {
namespace ms_windows {
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_BufferedFile::~ms_windows_BufferedFile() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ms_windows_BufferedFile::ms_windows_BufferedFile() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Proxy< File > ms_windows_BufferedFile::createClone() const throw() {
	ms_windows_BufferedFile *file = new ms_windows_BufferedFile( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( file, MACROS_FILE_AND_LINE ) );
	return Proxy< File >::createUnique( file );
}

ms_windows_BufferedFile::ms_windows_BufferedFile( const ms_windows_BufferedFile & ) throw() // other
{}

const ms_windows_BufferedFile &ms_windows_BufferedFile::operator =( const ms_windows_BufferedFile &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	Should::neverViolateCopyingProhibition( "ms_windows_BufferedFile::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
