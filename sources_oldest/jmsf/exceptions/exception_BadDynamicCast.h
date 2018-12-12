#pragma once

#include "jmsf/mixins/mixin_Exception.h"

#include "../jmsf.h"


namespace jmsf {
namespace exceptions {


class JMSF_DLL_INTERFACE exception_BadDynamicCast : public mixins::mixin_Exception {

public:
	// virtuals	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~exception_BadDynamicCast() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_BadDynamicCast( const ConstantProxy< TextString > &reason ) throw();
	exception_BadDynamicCast( const Proxy< TextStream > &reason ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_BadDynamicCast( const exception_BadDynamicCast &other ) throw();
	const exception_BadDynamicCast &operator =( const exception_BadDynamicCast &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
