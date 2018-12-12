#include "ms_windows_File.h"

#include "jmsf/pointing/Proxy.inl"

namespace jmsf {
namespace osie {
namespace ms_windows {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_File::~ms_windows_File() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ms_windows_File::ms_windows_File() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
pointing::Proxy< File > ms_windows_File::createClone() const throw() {
	ms_windows_File *file = new ms_windows_File( *this );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( file, MACROS_FILE_AND_LINE ) );
	return pointing::Proxy< File >::createUnique( file );
}

ms_windows_File::ms_windows_File( const ms_windows_File & ) throw() // other
{}

const ms_windows_File &ms_windows_File::operator =( const ms_windows_File &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
