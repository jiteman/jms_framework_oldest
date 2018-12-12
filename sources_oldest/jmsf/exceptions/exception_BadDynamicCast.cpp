#include "exception_BadDynamicCast.h"
#include "../factory_TextObject.h"
#include "../TextStream.h"
#include "../Proxies.hpp"


namespace jmsf {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_BadDynamicCast::~exception_BadDynamicCast() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_BadDynamicCast::exception_BadDynamicCast( const ConstantProxy< TextString > &reason ) throw()
	:
		mixin_Exception( factory_TextObject::instance()->createTextStream()->put( CONSTANT_TEXT_STRING( "Bad dynamic cast for: " ) )->put( reason ) )
{}

exception_BadDynamicCast::exception_BadDynamicCast( const Proxy< TextStream > &reason ) throw()
	:
		mixin_Exception( reason )
{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_BadDynamicCast::exception_BadDynamicCast( const exception_BadDynamicCast &other ) throw()
	: mixin_Exception( other )
{}

const exception_BadDynamicCast &exception_BadDynamicCast::operator =( const exception_BadDynamicCast &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
