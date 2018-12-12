#include "mixin_Observable.h"
#include "../Observer.h"
#include "../factory_Container.hpp"
#include "../Iterator.hpp"
#include "../ConstantIterator.hpp"
#include "../Proxies.hpp"
#include "../Pointers.hpp"

namespace jmsf {
namespace mixins {


void mixin_Observable::attach( const Pointer< Observer > &observer ) throw() {
	for ( Proxy< ConstantIterator< Pointer< Observer > > > iterator = _observers->createConstantForwardIterator(); iterator->isNotDone(); iterator->advance() ) {
		if ( iterator->getContainie() == observer ) return;
	}

	_observers->appendBack( observer );
}

void mixin_Observable::detach( const Pointer< Observer > &observer ) throw() {
	for ( Proxy< Iterator< Pointer< Observer > > > iterator = _observers->createForwardIterator(); iterator->isNotDone(); iterator->advance() ) {
		if ( iterator->getContainie() == observer ) {
			iterator->erase();
			break;
		}
	}
}

void mixin_Observable::notify() throw() {
	for ( Proxy< Iterator< Pointer< Observer > > > iterator = _observers->createForwardIterator(); iterator->isNotDone(); iterator->advance() ) {
		iterator->takeContainie()->update();
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
mixin_Observable::~mixin_Observable() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Observable::mixin_Observable() throw()
	:
		_observers( factory_Container< Pointer< Observer > >::instance()->createList() )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
mixin_Observable::mixin_Observable( const mixin_Observable &other ) throw() // other
	:
		_observers( other._observers.getNonlinkedConstant()->createClone() )
{}

const mixin_Observable &mixin_Observable::operator =( const mixin_Observable &other ) throw() {
	if ( this == &other ) return *this;

	_observers = other._observers.getNonlinkedConstant()->createClone();
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
