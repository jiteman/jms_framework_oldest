#include "mixin_Lockable.h"
#include "jmsf/osie/Mutex.h"
#include "jmsf/Should.h"

namespace jmsf {
namespace mtf {
namespace mixins {

Proxy< osie::Mutex > &mixin_Lockable::takeMutex() const throw() {
	return _mixin_Lockable_mutex;
}

const ConstantProxy< osie::Mutex > &mixin_Lockable::getMutex() const throw() {
	return _mixin_Lockable_constantMutex;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_Lockable::~mixin_Lockable() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Lockable::mixin_Lockable( Proxy< osie::Mutex > mutex ) throw()
	:
		_mixin_Lockable_mutex( mutex )
{
	_mixin_Lockable_constantMutex = _mixin_Lockable_mutex.getNonlinkedConstant();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Lockable::mixin_Lockable( const mixin_Lockable & ) throw( Exception ) { // other
	Should::neverViolateCopyingProhibition( "mixin_Lockable::mixin_Lockable()" );
}

const mixin_Lockable &mixin_Lockable::operator =( const mixin_Lockable &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	Should::neverViolateCopyingProhibition( "mixin_Lockable::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace mixins
} // namespace mtf
} // namespace jmsf
