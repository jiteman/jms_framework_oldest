#pragma once


#include "Singleton.hpp"


//#include "osie/static_factory_OperatingSystemSpecial.h"
//#include "osie/Mutex.h"
//#include "jmsf/pointing/AutomaticPointer.inl"
#include "jmsf/memorying/Omp.inl"
#include "jmsf/memorying/Womp.inl"
#include "jmsf/memorying/Destructor.inl"
#include "jmsf/typing/Aso.inl"


namespace jmsf {
namespace patterning {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Singleton< A_type >::~Singleton() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
template< class A_creating_type >
void Singleton< A_type >::create_instance( const memorying::Womp< memorying::Allocator > &objectAllocator ) {
	if ( _singletonInstance.is_not_empty() ) /* throw already created */ return;

	_singletonInstance = A_creating_type::create_singleton_instance( objectAllocator );
	_referenceToReturn = _singletonInstance.get_as_weak();
}

template< class A_type >
memorying::Womp< A_type > &Singleton< A_type >::instance() noexept {
	return _referenceToReturn;
// 	Singleton< A_type > *currentInstance = _singletonInstance.get();
// 
// 	if ( currentInstance == nullptr ) /* throw not created yet */ return memorying::Object_memory_pointer< 
// //		osie::static_factory_OperatingSystemSpecial::takeOperatingSystemMutex()->lock();
// 
// 		if ( currentInstance == nullptr ) {
// 			currentInstance = A_type::createInstance();
// 			_singletonInstance = pointing::AutomaticPointer< memorying::Singleton< A_type > >( currentInstance );
// 		}
// 
// //		osie::static_factory_OperatingSystemSpecial::takeOperatingSystemMutex()->unlock();
// 	}
// 
// 	return static_cast< A_type * >( currentInstance );
}

template< class A_type >
void Singleton< A_type >::destroy_instance() {
	if ( _referenceToReturn.is_not_empty() ) {
		_referenceToReturn = memorying::Womp< A_type >();
	}

	if ( _singletonInstance.is_not_empty() ) {
		memorying::Destructor< A_type >::destruct( _singletonInstance );
		_singletonInstance = memorying::Omp< A_type >();
	}
}

template< class A_type >
Singleton< A_type >::Singleton() noexept
{}

// template< class A_type >
// A_type *Singleton< A_type >::testing_setInstance( A_type *testingInstance ) {
// 	A_type *previousInstance = static_cast< A_type * >( _instance.releasePointer() );
// 	_instance.setPointer( testingInstance );
// 	return previousInstance;
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Singleton< A_type >::Singleton( const Singleton< A_type > & ) noexept // other
{}

template< class A_type >
const Singleton< A_type > &Singleton< A_type >::operator =( const Singleton< A_type > &another ) noexept {
	if ( this == &another ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
memorying::Omp< A_type > Singleton< A_type >::_singletonInstance;

template< class A_type >
memorying::Womp< A_type > Singleton< A_type >::_referenceToReturn;


} // namespace patterning
} // namespace jmsf
