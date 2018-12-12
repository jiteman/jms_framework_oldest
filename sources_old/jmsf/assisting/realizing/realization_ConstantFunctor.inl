#pragma once


#include "realization_ConstantFunctor.hpp"

#include "jmsf/pointing/Proxy.inl"


namespace jmsf {
namespace assisting {
namespace realizing {


template< class A_type >
void realization_ConstantFunctor< A_type >::runMethod( const A_type &indirectedObject ) const throw( validating::Exception ) {
	( ( *indirectedObject ).*_pointerToMethod )();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
typename realization_ConstantFunctor< A_type >::type_pointerToMethod realization_ConstantFunctor< A_type >::getPointerToMethod() const throw() {
	return _pointerToMethod;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_ConstantFunctor< A_type >::~realization_ConstantFunctor() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_ConstantFunctor< A_type >::realization_ConstantFunctor(
	typename realization_ConstantFunctor< A_type >::type_pointerToMethod pointerToMethod ) throw()
{
	_pointerToMethod = pointerToMethod;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
pointing::Proxy< ConstantFunctor< A_type > > realization_ConstantFunctor< A_type >::createClone() const throw() {
	return pointing::Proxy< ConstantFunctor< A_type > >::createNonlinkedFor( this );
}

template< class A_type >
realization_ConstantFunctor< A_type >::realization_ConstantFunctor( const realization_ConstantFunctor< A_type > & ) throw() // other
{}

template< class A_type >
const realization_ConstantFunctor< A_type > &realization_ConstantFunctor< A_type >::operator =( const realization_ConstantFunctor< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
