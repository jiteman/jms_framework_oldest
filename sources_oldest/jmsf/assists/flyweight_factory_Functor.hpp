#pragma once

#include "jmsf/Singleton.hpp"

#include "jmsf/Should.h"

#include "Functors.hxx"


namespace jmsf {
namespace assists {


template< class A_type >
class flyweight_factory_Functor :
	public Singleton< flyweight_factory_Functor< A_type > >
{

public:
	virtual Proxy< Functor< A_type > > createFunctor( void ( A_type::type_indirected:: *pointerToMethod )() ) throw() = 0;
	virtual const ConstantProxy< ConstantFunctor< A_type > > createConstantFunctor( void ( A_type::type_indirected:: *pointerToMethod )() const ) throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~flyweight_factory_Functor() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< flyweight_factory_Functor >;
	static flyweight_factory_Functor *createInstance() throw();

protected:
	flyweight_factory_Functor() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	flyweight_factory_Functor( const flyweight_factory_Functor &other ) throw();
	const flyweight_factory_Functor &operator =( const flyweight_factory_Functor &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}


#include "realizations/realization_flyweight_factory_Functor.hpp"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace assists {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
flyweight_factory_Functor< A_type >::~flyweight_factory_Functor() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class A_type >
flyweight_factory_Functor< A_type > *flyweight_factory_Functor< A_type >::createInstance() throw() {
	flyweight_factory_Functor< A_type > *flyweightFactoryFunctor = new realizations::realization_flyweight_factory_Functor< A_type >;
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( flyweightFactoryFunctor, MACROS_FILE_AND_LINE ) );
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
const flyweight_factory_Functor< A_type > &flyweight_factory_Functor< A_type >::operator =( const flyweight_factory_Functor< A_type > &other ) throw( Exception ) {
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