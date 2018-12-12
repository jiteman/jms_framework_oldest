#include "exception_CantStartDecipheringHardware.h"
#include "jmsf/TextStream.h"


namespace nppntt {
namespace mdm {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_CantStartDecipheringHardware::~exception_CantStartDecipheringHardware() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_CantStartDecipheringHardware::exception_CantStartDecipheringHardware( const ::jmsf::ConstantProxy< ::jmsf::TextString > &reason ) throw()
	: mixin_Exception( reason )
{}

exception_CantStartDecipheringHardware::exception_CantStartDecipheringHardware( const ::jmsf::Proxy< ::jmsf::TextStream > &reason ) throw()
	: mixin_Exception( reason )
{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_CantStartDecipheringHardware::exception_CantStartDecipheringHardware( const exception_CantStartDecipheringHardware &other ) throw()
	: mixin_Exception( other )
{}

const exception_CantStartDecipheringHardware &exception_CantStartDecipheringHardware::operator =( const exception_CantStartDecipheringHardware &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
