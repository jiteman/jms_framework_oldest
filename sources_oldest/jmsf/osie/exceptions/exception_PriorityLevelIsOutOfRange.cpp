#include "exception_PriorityLevelIsOutOfRange.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/TextStream.h"

namespace jmsf {
namespace osie {
namespace exceptions {

// static
const char_type *exception_PriorityLevelIsOutOfRange::EXCEPTION_MESSAGE_exception_PriorityLevelIsOutOfRange = " - exception_PriorityLevelIsOutOfRange";


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_PriorityLevelIsOutOfRange::~exception_PriorityLevelIsOutOfRange() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_PriorityLevelIsOutOfRange::exception_PriorityLevelIsOutOfRange( const ConstantProxy< TextString > &reason ) throw()
	: mixin_Exception( factory_TextObject::instance()->createTextStream()->put( reason )->put( CONSTANT_TEXT_STRING( EXCEPTION_MESSAGE_exception_PriorityLevelIsOutOfRange ) ) )
{}

exception_PriorityLevelIsOutOfRange::exception_PriorityLevelIsOutOfRange( const Proxy< TextStream > &reason ) throw()
	: mixin_Exception( reason->createClone()->put( CONSTANT_TEXT_STRING( EXCEPTION_MESSAGE_exception_PriorityLevelIsOutOfRange ) ) )
{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_PriorityLevelIsOutOfRange::exception_PriorityLevelIsOutOfRange( const exception_PriorityLevelIsOutOfRange &other ) throw()
	: mixin_Exception( other )
{}

const exception_PriorityLevelIsOutOfRange &exception_PriorityLevelIsOutOfRange::operator =( const exception_PriorityLevelIsOutOfRange &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace exceptions	
} // namespace osie
} // namespace jmsf
