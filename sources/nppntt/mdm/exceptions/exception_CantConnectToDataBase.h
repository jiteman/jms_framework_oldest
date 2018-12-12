#pragma once

#include "jmsf/mixins/mixin_Exception.h"


namespace nppntt {
namespace mdm {
namespace exceptions {


class exception_CantConnectToDataBase : public ::jmsf::mixins::mixin_Exception {

public:
	// virtuals	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~exception_CantConnectToDataBase() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_CantConnectToDataBase( const ::jmsf::ConstantProxy< ::jmsf::TextString > &reason ) throw();
	exception_CantConnectToDataBase( const ::jmsf::Proxy< ::jmsf::TextStream > &reason ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_CantConnectToDataBase( const exception_CantConnectToDataBase &other ) throw();
	const exception_CantConnectToDataBase &operator =( const exception_CantConnectToDataBase &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
