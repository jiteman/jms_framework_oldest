#pragma once

#include "jmsf/mixins/mixin_Exception.h"
#include "jmsf/types.h"

namespace jmsf {
namespace exceptions {

class exception_DivisionByZero :
	public mixins::mixin_Exception
{

public:
	// virtuals	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~exception_DivisionByZero() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_DivisionByZero( const ConstantProxy< TextString > &reason ) throw();
	exception_DivisionByZero( const Proxy< TextStream > &reason ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_DivisionByZero( const exception_DivisionByZero &other ) throw();
	const exception_DivisionByZero &operator =( const exception_DivisionByZero &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const char_type *EXCEPTION_MESSAGE_exception_DivisionByZero;

};

} // namespace exceptions

} // namespace jmsf
