#include "exception_PriorityLevelIsOutOfRange.h"


#include "jmsf/pointing/Proxy.inl"

#include "jmsf/texting/factory_TextObject.h"
#include "jmsf/texting/TextStream.h"
#include "jmsf/texting/TextString.h"


namespace jmsf {
namespace osie {
namespace exceptions {


// static
const typing::internals::platform_char *exception_PriorityLevelIsOutOfRange::EXCEPTION_MESSAGE_exception_PriorityLevelIsOutOfRange = " - exception_PriorityLevelIsOutOfRange";


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_PriorityLevelIsOutOfRange::~exception_PriorityLevelIsOutOfRange() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_PriorityLevelIsOutOfRange::exception_PriorityLevelIsOutOfRange( const pointing::ConstantProxy< texting::TextString > &reason, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( texting::factory_TextObject::instance()->createTextStream()->put( reason )->put( CONSTANT_TEXT_STRING( EXCEPTION_MESSAGE_exception_PriorityLevelIsOutOfRange ) ), fileAndLine )
{}

exception_PriorityLevelIsOutOfRange::exception_PriorityLevelIsOutOfRange( const pointing::Proxy< texting::TextStream > &reason, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( reason->createClone()->put( CONSTANT_TEXT_STRING( EXCEPTION_MESSAGE_exception_PriorityLevelIsOutOfRange ) ), fileAndLine )
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
