#pragma once

#include "Functors.hpp"


namespace jmsf {
namespace assists {


template< class Indirected_container_type, class Indirected_functor_type >
void doForEvery( Indirected_container_type &container, Indirected_functor_type &functor ) throw( Exception ) {
	for (
		Proxy< typename Indirected_container_type::type_indirected::type_container_iterator > containerIterator = container->createForwardIterator();
		containerIterator->isNotDone();
		containerIterator->advance() )
	{
		functor->runMethod( containerIterator->takeContainie() );
	}	
}

template< class Indirected_container_type, class Indirected_functor_type >
void constantDoForEvery( const Indirected_container_type &container, Indirected_functor_type &functor ) throw( Exception ) {
	for (
		Proxy< typename Indirected_container_type::type_indirected::type_container_constant_iterator > containerIterator = container->createConstantForwardIterator();
		containerIterator->isNotDone();
		containerIterator->advance() )
	{
		functor->runMethod( containerIterator->getContainie() );
	}	
}


} // namespace
}
