#include "mixin_null_Lockable.h"
#include "jmsf/osie/Mutex.h"
#include "jmsf/Should.h"

namespace jmsf {
namespace mtf {
namespace mixins {

Proxy< osie::Mutex > &mixin_null_Lockable::takeMutex() const throw() {
	return _mixin_null_LockableMutex;
}

const ConstantProxy< osie::Mutex > &mixin_null_Lockable::getMutex() const throw() {
	return _mixin_null_LockableConstantMutex;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_null_Lockable::~mixin_null_Lockable() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_null_Lockable::mixin_null_Lockable() throw()
	:
		_mixin_null_LockableMutex( Proxy< osie::Mutex >::createEmpty() ),
		_mixin_null_LockableConstantMutex( ConstantProxy< osie::Mutex >::createEmpty() )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_null_Lockable::mixin_null_Lockable( const mixin_null_Lockable & ) throw() // other
{}

const mixin_null_Lockable &mixin_null_Lockable::operator =( const mixin_null_Lockable &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	Should::neverViolateCopyingProhibition( "mixin_null_Lockable::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace mixins
} // namespace mtf
} // namespace jmsf
