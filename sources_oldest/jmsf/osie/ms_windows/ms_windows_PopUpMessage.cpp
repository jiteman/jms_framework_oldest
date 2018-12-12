#include "ms_windows_PopUpMessage.h"
#include "jmsf/TextString.h"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"
#include "temporary_windows_include.h"

namespace jmsf {
namespace osie {
namespace ms_windows {

void ms_windows_PopUpMessage::showOk( const ConstantProxy< TextString > &message ) const throw() {
	::MessageBoxA( NULL, message->getCtext(), _caption->getCtext(), MB_OK );
}

const Boolean ms_windows_PopUpMessage::showOkCancel( const ConstantProxy< TextString > &message ) const throw() {
	return ::MessageBoxA( NULL, message->getCtext(), _caption->getCtext(), MB_OKCANCEL ) != IDCANCEL;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_PopUpMessage::~ms_windows_PopUpMessage() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ms_windows_PopUpMessage::ms_windows_PopUpMessage() throw()
{}

ms_windows_PopUpMessage::ms_windows_PopUpMessage( const ConstantProxy< TextString > &caption ) throw()
	:
		_caption( caption )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Proxy< PopUpMessage > ms_windows_PopUpMessage::createClone() const throw() {
	ms_windows_PopUpMessage *popUpMessage = new ms_windows_PopUpMessage( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( popUpMessage, MACROS_FILE_AND_LINE ) );
	return Proxy< PopUpMessage >::createUnique( popUpMessage );
}

ms_windows_PopUpMessage::ms_windows_PopUpMessage( const ms_windows_PopUpMessage & ) throw() // other
{}

const ms_windows_PopUpMessage &ms_windows_PopUpMessage::operator =( const ms_windows_PopUpMessage &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	Should::neverViolateCopyingProhibition( "ms_windows_PopUpMessage::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
