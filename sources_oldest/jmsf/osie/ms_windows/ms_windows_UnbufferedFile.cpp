#include "ms_windows_UnbufferedFile.h"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace osie {
namespace ms_windows {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_UnbufferedFile::~ms_windows_UnbufferedFile() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ms_windows_UnbufferedFile::ms_windows_UnbufferedFile() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Proxy< File > ms_windows_UnbufferedFile::createClone() const throw() {
	ms_windows_UnbufferedFile *file = new ms_windows_UnbufferedFile( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( file, MACROS_FILE_AND_LINE ) );
	return Proxy< File >::createUnique( file );
}

ms_windows_UnbufferedFile::ms_windows_UnbufferedFile( const ms_windows_UnbufferedFile & ) throw() // other
{}

const ms_windows_UnbufferedFile &ms_windows_UnbufferedFile::operator =( const ms_windows_UnbufferedFile &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	Should::neverViolateCopyingProhibition( "ms_windows_UnbufferedFile::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
