#include "mixin_null_Runnable.h"
#include "jmsf/Should.h"

#include "../../warning_suppressor.h"

namespace jmsf {
namespace mtf {
namespace mixins {

void mixin_null_Runnable::run() throw( Exception )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_null_Runnable::~mixin_null_Runnable() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_null_Runnable::mixin_null_Runnable() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_null_Runnable::mixin_null_Runnable( const mixin_null_Runnable & ) throw( Exception ) { // other
	Should::neverViolateCopyingProhibition( "mixin_null_Runnable::mixin_null_Runnable()" );
}

const mixin_null_Runnable &mixin_null_Runnable::operator =( const mixin_null_Runnable &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	Should::neverViolateCopyingProhibition( "mixin_null_Runnable::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace mixins
} // namespace mtf
} // namespace jmsf
