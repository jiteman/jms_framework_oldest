#include "exception_UnsetCreator.h"


namespace jmsf {
namespace osie {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_UnsetCreator::~exception_UnsetCreator() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_UnsetCreator::exception_UnsetCreator( const ConstantProxy< TextString > &reason ) throw()
	: mixin_Exception( reason )
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
