#pragma once

#include "../Iterators.hpp"
#include "../Container.hpp"
#include "../Proxies.hpp"


namespace jmsf {
namespace assists {


template< class Indirected_container_type, class Indirected_type >
Proxy< typename Indirected_container_type::type_indirected::type_container_iterator > find( Indirected_container_type &container, Indirected_type &object ) throw( Exception ) {
	for (
		Proxy< typename Indirected_container_type::type_indirected::type_container_iterator > containerIterator = container->createForwardIterator();
		containerIterator->isNotDone();
		containerIterator->advance() )
	{
		if ( containerIterator->takeContainie() == object ) {
			return containerIterator;
		}
	}

	return Proxy< typename Indirected_container_type::type_indirected::type_container_iterator >();
}

template< class Indirected_container_type, class Indirected_type >
Proxy< typename Indirected_container_type::type_indirected::type_container_constant_iterator > constantFind( const Indirected_container_type &container, const Indirected_type &object ) throw( Exception ) {
	for (
		Proxy< typename Indirected_container_type::type_indirected::type_container_constant_iterator > containerIterator = container->createConstantForwardIterator();
		containerIterator->isNotDone();
		containerIterator->advance() )
	{
		if ( containerIterator->getContainie() == object ) {
			return containerIterator;
		}
	}

	return Proxy< typename Indirected_container_type::type_indirected::type_container_iterator >();
}


} // namespace
}
