#include "ms_windows_FileSystemControl.h"


#include "jmsf/pointing/Proxy.inl"
#include "jmsf/validating/Should.h"
//#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace osie {
namespace ms_windows {

// Proxy< File > ms_windows_FileSystemControl::createBufferedFileForInput() {
// 	
// }
// 
// Proxy< File > ms_windows_FileSystemControl::createBufferedFileForOutput() {
// 	
// }
// 
// Proxy< File > ms_windows_FileSystemControl::createBufferedFileForInputAndOutput() {
// 	
// }
// 
// Proxy< File > ms_windows_FileSystemControl::createNonbufferedFileForInput() {
// 	
// }
// 
// Proxy< File > ms_windows_FileSystemControl::createNonbufferedFileForOutput() {
// 	
// }
// 
// Proxy< File > ms_windows_FileSystemControl::createNonbufferedFileForInputAndOutput() {
// 	
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_FileSystemControl::~ms_windows_FileSystemControl() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ms_windows_FileSystemControl::ms_windows_FileSystemControl() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
pointing::Proxy< FileSystemControl > ms_windows_FileSystemControl::createClone() const throw() {
	ms_windows_FileSystemControl *fileSystemControl = new ms_windows_FileSystemControl( *this );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( fileSystemControl, MACROS_FILE_AND_LINE ) );
	return pointing::Proxy< FileSystemControl >::createUnique( fileSystemControl );
}

ms_windows_FileSystemControl::ms_windows_FileSystemControl( const ms_windows_FileSystemControl & ) throw() // other
{}

const ms_windows_FileSystemControl &ms_windows_FileSystemControl::operator =( const ms_windows_FileSystemControl &other ) throw( validating::Exception ) {
	if ( this == &other ) return *this;

	validating::Should::neverViolateCopyingProhibition( "ms_windows_FileSystemControl::operator =()", FILE_AND_LINE );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
