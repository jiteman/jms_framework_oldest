#pragma once


#include "jmsf/mixins/mixin_Exception.h"
#include "jmsf/types.h"
#include "jmsf/jmsf.h"


namespace jmsf {
namespace exceptions {


class JMSF_DLL_INTERFACE exception_BadContainerDereferencing :
	public mixins::mixin_Exception
{

public:
	// virtuals	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Exception
	~exception_BadContainerDereferencing() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_BadContainerDereferencing( const ConstantProxy< TextString > &reason ) throw();
	exception_BadContainerDereferencing( const Proxy< TextStream > &reason ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_BadContainerDereferencing( const exception_BadContainerDereferencing &other ) throw();
	const exception_BadContainerDereferencing &operator =( const exception_BadContainerDereferencing &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const char_type *EXCEPTION_MESSAGE_exception_BadContainerDereferencing;

};


} // namespace exceptions
} // namespace jmsf
