#include "exception_BadDynamicCast.h"


#include "jmsf/texting/factory_TextObject.h"
#include "jmsf/texting/TextStream.h"
#include "jmsf/texting/TextString.h"
#include "jmsf/pointing/Proxy.inl"
#include "jmsf/pointing/ConstantProxy.inl"


namespace jmsf {
namespace runtiming {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_BadDynamicCast::~exception_BadDynamicCast() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_BadDynamicCast::exception_BadDynamicCast( const pointing::ConstantProxy< texting::TextString > &reason, const validating::FileAndLine &fileAndLine ) throw()
	:
		mixin_Exception( texting::factory_TextObject::instance()->createTextStream()->put( CONSTANT_TEXT_STRING( "Bad dynamic cast for: " ) )->put( reason ), fileAndLine )
{}

exception_BadDynamicCast::exception_BadDynamicCast( const pointing::Proxy< texting::TextStream > &reason, const validating::FileAndLine &fileAndLine ) throw()
	:
		mixin_Exception( reason, fileAndLine )
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


} // namespace exceptions
} // namespace runtiming
} // namespace jsmf
