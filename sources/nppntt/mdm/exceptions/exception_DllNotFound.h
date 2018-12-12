#pragma once

#include "jmsf/mixins/mixin_Exception.h"


namespace nppntt {
namespace mdm {
namespace exceptions {


class exception_DllNotFound : public ::jmsf::mixins::mixin_Exception {

public:
	// virtuals	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~exception_DllNotFound() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_DllNotFound( const ::jmsf::ConstantProxy< ::jmsf::TextString > &reason ) throw();
	exception_DllNotFound( const ::jmsf::Proxy< ::jmsf::TextStream > &reason ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_DllNotFound( const exception_DllNotFound &other ) throw();
	const exception_DllNotFound &operator =( const exception_DllNotFound &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
//	static const ::jmsf::char_type *MESSAGE_HEADER = "Dll not found: ";

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
