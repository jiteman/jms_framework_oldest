#include "ms_windows_UtilityControl.h"
#include "ms_windows_Stopwatch.h"
#include "ms_windows_PopUpMessage.h"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace osie {
namespace ms_windows {

Proxy< Stopwatch > ms_windows_UtilityControl::createStopwatch() const throw() {
	ms_windows_Stopwatch *stopwatch = new ms_windows_Stopwatch;
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( stopwatch, MACROS_FILE_AND_LINE ) );
	return Proxy< Stopwatch >::createUnique( stopwatch );
}

Proxy< PopUpMessage > ms_windows_UtilityControl::createPopUpMessage() const throw() {
	ms_windows_PopUpMessage *popUpMessage = new ms_windows_PopUpMessage;
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( popUpMessage, MACROS_FILE_AND_LINE ) );
	return Proxy< PopUpMessage >::createUnique( popUpMessage );
}

Proxy< PopUpMessage > ms_windows_UtilityControl::createPopUpMessage( const ConstantProxy< TextString > &caption ) const throw() {
	ms_windows_PopUpMessage *popUpMessage = new ms_windows_PopUpMessage( caption );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( popUpMessage, MACROS_FILE_AND_LINE ) );
	return Proxy< PopUpMessage >::createUnique( popUpMessage );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
ms_windows_UtilityControl::~ms_windows_UtilityControl() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ms_windows_UtilityControl::ms_windows_UtilityControl() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Proxy< UtilityControl > ms_windows_UtilityControl::createClone() const throw() {
	ms_windows_UtilityControl *utilityControl = new ms_windows_UtilityControl( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( utilityControl, MACROS_FILE_AND_LINE ) );
	return Proxy< UtilityControl >::createUnique( utilityControl );
}

ms_windows_UtilityControl::ms_windows_UtilityControl( const ms_windows_UtilityControl & ) throw() // other
{}

const ms_windows_UtilityControl &ms_windows_UtilityControl::operator =( const ms_windows_UtilityControl &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	Should::neverViolateCopyingProhibition( "ms_windows_UtilityControl::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
