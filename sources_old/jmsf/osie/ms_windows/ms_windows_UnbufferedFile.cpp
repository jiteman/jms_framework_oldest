#include "ms_windows_UnbufferedFile.h"


#include "jmsf/pointing/Proxy.inl"
#include "jmsf/validating/Should.h"


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
pointing::Proxy< File > ms_windows_UnbufferedFile::createClone() const throw() {
	ms_windows_UnbufferedFile *file = new ms_windows_UnbufferedFile( *this );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( file, MACROS_FILE_AND_LINE ) );
	return pointing::Proxy< File >::createUnique( file );
}

ms_windows_UnbufferedFile::ms_windows_UnbufferedFile( const ms_windows_UnbufferedFile & ) throw() // other
{}

const ms_windows_UnbufferedFile &ms_windows_UnbufferedFile::operator =( const ms_windows_UnbufferedFile &other ) throw( validating::Exception ) {
	if ( this == &other ) return *this;

	validating::Should::neverViolateCopyingProhibition( "ms_windows_UnbufferedFile::operator =()", FILE_AND_LINE );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
