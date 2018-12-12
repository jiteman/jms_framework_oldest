#pragma once

#include "jmsf/mixins/mixin_Exception.h"


namespace nppntt {
namespace mdm {
namespace exceptions {


class exception_CantStartDecipheringHardware : public ::jmsf::mixins::mixin_Exception {

public:
	// virtuals	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~exception_CantStartDecipheringHardware() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_CantStartDecipheringHardware( const ::jmsf::ConstantProxy< ::jmsf::TextString > &reason ) throw();
	exception_CantStartDecipheringHardware( const ::jmsf::Proxy< ::jmsf::TextStream > &reason ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_CantStartDecipheringHardware( const exception_CantStartDecipheringHardware &other ) throw();
	const exception_CantStartDecipheringHardware &operator =( const exception_CantStartDecipheringHardware &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
