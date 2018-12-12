#include "Should.h"
#include "realizations/exception_Should.h"
#include "factory_TextObject.h"
#include "TextStream.h"
#include "Boolean.h"


namespace jmsf {


void Should::alwaysBe( const Boolean expression ) throw( Exception ) {
	if ( expression.not() ) {
		throw realizations::exception_Should( CONSTANT_TEXT_STRING( "Should::alwaysBe( false )" ) );
	}
}

void Should::neverBe( const Boolean expression ) throw( Exception ) {
	if ( expression ) {
		throw realizations::exception_Should( CONSTANT_TEXT_STRING( "Should::neverBe( true )" ) );
	}
}

void Should::alwaysBeNull( const void *pointer ) throw( Exception ) {
	if ( pointer != nullptr ) {
		throw realizations::exception_Should( CONSTANT_TEXT_STRING( "Should::alwaysBeNull( not nullptr )" ) );
	}
}

void Should::neverBeNull( const void *pointer ) throw( Exception ) {
	if ( pointer == nullptr ) {
		throw realizations::exception_Should( CONSTANT_TEXT_STRING( "Should::neverBeNull( nullptr )" ) );
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void Should::_neverReachHere( const char_type *const reason ) throw( Exception ) {
	Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
	textStream->put( CONSTANT_TEXT_STRING( "Should::neverReachHere() - " ) );
	textStream->put( CONSTANT_TEXT_STRING( reason ) );
	throw realizations::exception_Should( textStream->createTextString() );
}

void Should::neverViolateCopyingProhibition( const char_type *const place ) throw( Exception ) {
	Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
	textStream->put( CONSTANT_TEXT_STRING( "Should::neverViolateCopyingProhibition() - " ) );
	textStream->put( CONSTANT_TEXT_STRING( place ) );
	throw realizations::exception_Should( textStream->createTextString() );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Should::~Should() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Should::Should() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Should::Should( const Should & ) throw() // other
{}

const Should &Should::operator =( const Should &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
