#pragma once

#include "jmsf/mixins/mixin_Exception.h"
#include "jmsf/types.h"

namespace jmsf {
namespace exceptions {

class exception_CantOpenFile :
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
	~exception_CantOpenFile() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_CantOpenFile( const ConstantProxy< TextString > &reason ) throw();
	exception_CantOpenFile( const Proxy< TextStream > &reason ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_CantOpenFile( const exception_CantOpenFile &other ) throw();
	const exception_CantOpenFile &operator =( const exception_CantOpenFile &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const char_type *EXCEPTION_MESSAGE_exception_CantOpenFile;

};

} // namespace exceptions
} // namespace jmsf
