#pragma once


#include "realization_flyweight_factory_Functor.hpp"

#include "realization_Functor.inl"
#include "realization_ConstantFunctor.inl"

#include "../flyweight_factory_Functor.inl"

#include "jmsf/texting/factory_TextObject.h"
#include "jmsf/containing/factory_Container.inl"
#include "jmsf/containing/Container.inl"
#include "jmsf/runtiming/Casts.inl"
#include "jmsf/pointing/Pointer.inl"
#include "jmsf/pointing/Proxy.inl"
#include "jmsf/pointing/ConstantProxy.inl"

#include "jmsf/validating/Should.h"


namespace jmsf {
namespace assisting {
namespace realizing {


template< class A_type >
Proxy< Functor< A_type > > realization_flyweight_factory_Functor< A_type >::createFunctor( void ( A_type::containing_type_data::the_type:: *pointerToMethod )() ) throw() {
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
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( newFunctorPointer, MACROS_FILE_AND_LINE ) );
		pointing::Proxy< Functor< A_type > > newFunctor = pointing::Proxy< Functor< A_type > >::createUnique( newFunctorPointer );
		functorToReturn = newFunctor.getNonlinked();
		_functorContainer->appendBack( newFunctor );
	}

	return functorToReturn;
}

template< class A_type >
const ConstantProxy< ConstantFunctor< A_type > > realization_flyweight_factory_Functor< A_type >::createConstantFunctor( void ( A_type::containing_type_data::the_type:: *pointerToMethod )() const ) throw() {
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
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( newConstantFunctorPointer, MACROS_FILE_AND_LINE ) );
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
const realization_flyweight_factory_Functor< A_type > &realization_flyweight_factory_Functor< A_type >::operator =( const realization_flyweight_factory_Functor< A_type > &other ) throw( validating::Exception ) {
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
