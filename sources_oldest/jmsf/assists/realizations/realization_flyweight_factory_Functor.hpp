#pragma once

#include "../flyweight_factory_Functor.hpp"

#include "jmsf/Should.h"

#include "jmsf/Container.hxx"

namespace jmsf {
namespace assists {
namespace realizations {


template< class A_type >
class realization_flyweight_factory_Functor :
	public flyweight_factory_Functor< A_type >
{

public:
	// virtuals flyweight_factory_Functor
	Proxy< Functor< A_type > > createFunctor( void ( A_type::type_indirected:: *pointerToMethod )() ) throw();
	const ConstantProxy< ConstantFunctor< A_type > > createConstantFunctor( void ( A_type::type_indirected:: *pointerToMethod )() const ) throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_flyweight_factory_Functor() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend flyweight_factory_Functor;
	realization_flyweight_factory_Functor() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_flyweight_factory_Functor( const realization_flyweight_factory_Functor &other ) throw();
	const realization_flyweight_factory_Functor &operator =( const realization_flyweight_factory_Functor &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Proxy< Container< Proxy< Functor< A_type > > > > _functorContainer;
	Proxy< Container< ConstantProxy< ConstantFunctor< A_type > > > > _constantFunctorContainer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizations
} // namespace assists
} // jmsf


#include "realization_Functor.hpp"
#include "realization_ConstantFunctor.hpp"
#include "jmsf/factory_TextObject.h"
#include "jmsf/factory_Container.hpp"
#include "jmsf/Casts.hpp"
#include "jmsf/Pointers.hpp"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace assists {
namespace realizations {


template< class A_type >
Proxy< Functor< A_type > > realization_flyweight_factory_Functor< A_type >::createFunctor( void ( A_type::type_indirected:: *pointerToMethod )() ) throw() {
	Proxy< Functor< A_type > > functorToReturn;

	for (
		Proxy< Iterator< Proxy< Functor< A_type > > > > functorIterator = _functorContainer->createForwardIterator();
		functorIterator->isNotDone();
		functorIterator->advance() )
	{
		Pointer< realization_Functor< A_type > > currentFunctorImplementation =
			downcast< realization_Functor< A_type > >(
				functorIterator->takeContainie(),
				CONSTANT_TEXT_STRING( "realization_flyweight_factory_Functor< A_type >::createFunctor() - Functor< A_type > -> realization_Functor< A_type >" ) );

		if ( pointerToMethod == currentFunctorImplementation->getPointerToMethod() ) {
			functorToReturn = functorIterator->takeContainie().getNonlinked();
			break;
		}
	}
	
	if ( functorToReturn.isEmpty() ) {
		realization_Functor< A_type > *newFunctorPointer = new realization_Functor< A_type >( pointerToMethod );
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( newFunctorPointer, MACROS_FILE_AND_LINE ) );
		Proxy< Functor< A_type > > newFunctor = Proxy< Functor< A_type > >::createUnique( newFunctorPointer );
		functorToReturn = newFunctor.getNonlinked();
		_functorContainer->appendBack( newFunctor );
	}

	return functorToReturn;
}

template< class A_type >
const ConstantProxy< ConstantFunctor< A_type > > realization_flyweight_factory_Functor< A_type >::createConstantFunctor( void ( A_type::type_indirected:: *pointerToMethod )() const ) throw() {
	ConstantProxy< ConstantFunctor< A_type > > constantFunctorToReturn;

	for (
		Proxy< ConstantIterator< ConstantProxy< ConstantFunctor< A_type > > > > constantFunctorIterator = _constantFunctorContainer->createConstantForwardIterator();
		constantFunctorIterator->isNotDone();
		constantFunctorIterator->advance() )
	{
		const ConstantPointer< realization_ConstantFunctor< A_type > > currentConstantFunctorrealizationementation =
			constantDowncast< realization_ConstantFunctor< A_type > >(
				constantFunctorIterator->getContainie(),
				CONSTANT_TEXT_STRING( "realization_flyweight_factory_Functor< A_type >::createConstantFunctor() - ConstantFunctor< A_type > -> realization_ConstantFunctor< A_type >" ) );

		if ( pointerToMethod == currentConstantFunctorrealizationementation->getPointerToMethod() ) {
			constantFunctorToReturn = constantFunctorIterator->getContainie().getNonlinked();
			break;
		}
	}
	
	if ( constantFunctorToReturn.isEmpty() ) {
		const realization_ConstantFunctor< A_type > *newConstantFunctorPointer = new realization_ConstantFunctor< A_type >( pointerToMethod );
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( newConstantFunctorPointer, MACROS_FILE_AND_LINE ) );
		const ConstantProxy< ConstantFunctor< A_type > > newConstantFunctor = ConstantProxy< ConstantFunctor< A_type > >::createUnique( newConstantFunctorPointer );
		constantFunctorToReturn = newConstantFunctor.getNonlinked();
		_constantFunctorContainer->appendBack( newConstantFunctor );
	}

	return constantFunctorToReturn;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_flyweight_factory_Functor< A_type >::~realization_flyweight_factory_Functor() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_flyweight_factory_Functor< A_type >::realization_flyweight_factory_Functor() throw()
	:
		_functorContainer( factory_Container< Proxy< Functor< A_type > > >::instance()->createArray() ),
		_constantFunctorContainer( factory_Container< ConstantProxy< ConstantFunctor< A_type > > >::instance()->createArray() )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_flyweight_factory_Functor< A_type >::realization_flyweight_factory_Functor( const realization_flyweight_factory_Functor< A_type > & ) throw() // other
{}

template< class A_type >
const realization_flyweight_factory_Functor< A_type > &realization_flyweight_factory_Functor< A_type >::operator =( const realization_flyweight_factory_Functor< A_type > &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	// copy
	Should::neverReachHere();
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
