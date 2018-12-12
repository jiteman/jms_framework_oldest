#include "ms_windows_PopUpMessage.h"


#include "jmsf/texting/TextString.h"
#include "jmsf/pointing/Proxy.inl"
#include "jmsf/pointing/ConstantProxy.inl"
#include "jmsf/validating/Should.h"
#include "temporary_windows_include.h"


namespace jmsf {
namespace osie {
namespace ms_windows {


void ms_windows_PopUpMessage::showOk( const pointing::ConstantProxy< texting::TextString > &message ) const throw() {
	::MessageBoxA( NULL, message->getCtext(), _caption->getCtext(), MB_OK );
}

const typing::Boolean ms_windows_PopUpMessage::showOkCancel( const pointing::ConstantProxy< texting::TextString > &message ) const throw() {
	return typing::Boolean::create( ::MessageBoxA( NULL, message->getCtext(), _caption->getCtext(), MB_OKCANCEL ) != IDCANCEL );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_PopUpMessage::~ms_windows_PopUpMessage() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ms_windows_PopUpMessage::ms_windows_PopUpMessage() throw()
{}

ms_windows_PopUpMessage::ms_windows_PopUpMessage( const pointing::ConstantProxy< texting::TextString > &caption ) throw()
	:
		_caption( caption )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
pointing::Proxy< PopUpMessage > ms_windows_PopUpMessage::createClone() const throw() {
	ms_windows_PopUpMessage *popUpMessage = new ms_windows_PopUpMessage( *this );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( popUpMessage, MACROS_FILE_AND_LINE ) );
	return pointing::Proxy< PopUpMessage >::createUnique( popUpMessage );
}

ms_windows_PopUpMessage::ms_windows_PopUpMessage( const ms_windows_PopUpMessage & ) throw() // other
{}

const ms_windows_PopUpMessage &ms_windows_PopUpMessage::operator =( const ms_windows_PopUpMessage &other ) throw( validating::Exception ) {
	if ( this == &other ) return *this;

	validating::Should::neverViolateCopyingProhibition( "ms_windows_PopUpMessage::operator =()", FILE_AND_LINE );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
