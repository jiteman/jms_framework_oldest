#include "exception_UnsetCreator.h"


namespace jmsf {
namespace osie {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_UnsetCreator::~exception_UnsetCreator() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_UnsetCreator::exception_UnsetCreator( const pointing::ConstantProxy< texting::TextString > &reason, const validating::FileAndLine &fileAndLine ) throw()
	: mixin_Exception( reason, fileAndLine )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_UnsetCreator::exception_UnsetCreator( const exception_UnsetCreator &other ) throw()
	: mixin_Exception( other )
{}

const exception_UnsetCreator &exception_UnsetCreator::operator =( const exception_UnsetCreator &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
