#pragma once

#include "Automatic.hxx"

namespace jmsf {

template< class A_type >
class Singleton {

public:	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: friend Automatic< Singleton< A_type > >;
	virtual ~Singleton() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static A_type *instance() throw();

protected:
	Singleton() throw();

// protected:
// 	static A_type *testing_setInstance( A_type *testingInstance );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Singleton( const Singleton &other ) throw();
	const Singleton &operator =( const Singleton &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static Automatic< Singleton< A_type > > _singletonInstance;

};

} // namespace


#include "osie/static_factory_OperatingSystemSpecial.h"
#include "osie/Mutex.h"
#include "Automatic.hpp"

namespace jmsf {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Singleton< A_type >::~Singleton() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
A_type *Singleton< A_type >::instance() throw() {
	Singleton< A_type > *currentInstance = _singletonInstance.get();

	if ( currentInstance == nullptr ) {
		osie::static_factory_OperatingSystemSpecial::takeOperatingSystemMutex()->lock();

		if ( currentInstance == nullptr ) {
			currentInstance = A_type::createInstance();
			_singletonInstance = Automatic< Singleton< A_type > >( currentInstance );
		}

		osie::static_factory_OperatingSystemSpecial::takeOperatingSystemMutex()->unlock();
	}

	return static_cast< A_type * >( currentInstance );
}

template< class A_type >
Singleton< A_type >::Singleton() throw()
{}

// template< class A_type >
// A_type *Singleton< A_type >::testing_setInstance( A_type *testingInstance ) {
// 	A_type *previousInstance = static_cast< A_type * >( _instance.releasePointer() );
// 	_instance.setPointer( testingInstance );
// 	return previousInstance;
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Singleton< A_type >::Singleton( const Singleton & ) throw() // other
{}

template< class A_type >
const Singleton< A_type > &Singleton< A_type >::operator =( const Singleton &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Automatic< Singleton< A_type > > Singleton< A_type >::_singletonInstance;


} // namespace
