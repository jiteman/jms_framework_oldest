#include "exception_FileAppender.h"

#include "jmsf/TextStream.h"


#include "jmsf/factory_TextObject.h"


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_FileAppender::~exception_FileAppender() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_FileAppender::exception_FileAppender( const std::string &reason ) throw()
	: mixin_Exception( ::jmsf::factory_TextObject::instance()->createTextStream()->put( ::jmsf::factory_TextObject::instance()->createTextString( reason.c_str() ) ) )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_FileAppender::exception_FileAppender( const exception_FileAppender &other ) throw()
	: mixin_Exception( other )
{}

const exception_FileAppender &exception_FileAppender::operator =( const exception_FileAppender &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
