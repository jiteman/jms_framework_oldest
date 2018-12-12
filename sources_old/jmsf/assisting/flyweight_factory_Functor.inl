#pragma once


#include "flyweight_factory_Functor.hpp"

#include "realizing/realization_flyweight_factory_Functor.hpp"
//#include "jmsf/debugging/ObjectCreationLogging.h"

#include "jmsf/validating/Should.h"


namespace jmsf {
namespace assisting {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
flyweight_factory_Functor< A_type >::~flyweight_factory_Functor() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class A_type >
flyweight_factory_Functor< A_type > *flyweight_factory_Functor< A_type >::createInstance() throw() {
	flyweight_factory_Functor< A_type > *flyweightFactoryFunctor = new realizing::realization_flyweight_factory_Functor< A_type >;
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( flyweightFactoryFunctor, MACROS_FILE_AND_LINE ) );
	return flyweightFactoryFunctor;
}

template< class A_type >
flyweight_factory_Functor< A_type >::flyweight_factory_Functor() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
flyweight_factory_Functor< A_type >::flyweight_factory_Functor( const flyweight_factory_Functor< A_type > & ) throw() // other
{}

template< class A_type >
const flyweight_factory_Functor< A_type > &flyweight_factory_Functor< A_type >::operator =( const flyweight_factory_Functor< A_type > &other ) throw( validating::Exception ) {
	if ( this == &other ) return *this;

	// copy
	Should::neverReachHere();
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -