#pragma once


#include "realization_Functor.hpp"

#include "jmsf/pointing/Proxy.inl"


namespace jmsf {
namespace assisting {
namespace realizing {


template< class A_type >
void realization_Functor< A_type >::runMethod( A_type &indirectedObject ) throw( validating::Exception ) {
	( ( *indirectedObject ).*_pointerToMethod )();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
typename realization_Functor< A_type >::type_pointerToMethod realization_Functor< A_type >::getPointerToMethod() throw() {
	return _pointerToMethod;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_Functor< A_type >::~realization_Functor() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_Functor< A_type >::realization_Functor(
	 typename realization_Functor< A_type >::type_pointerToMethod pointerToMethod ) throw()
{
	_pointerToMethod = pointerToMethod;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
pointing::Proxy< Functor< A_type > > realization_Functor< A_type >::createClone() const throw() {
	return pointing::Proxy< Functor< A_type > >::createNonlinkedFor( this );
}

template< class A_type >
realization_Functor< A_type >::realization_Functor( const realization_Functor< A_type > & ) throw() // other
{}

template< class A_type >
const realization_Functor< A_type > &realization_Functor< A_type >::operator =( const realization_Functor< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
