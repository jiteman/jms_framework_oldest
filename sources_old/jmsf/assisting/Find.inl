#pragma once


#include "jmsf/containing/Iterator.inl"
#include "jmsf/containing/ConstaintIterator.inl"
#include "jmsf/containing/Container.inl"
#include "jmsf/pointing/Proxy.inl"
#include "jmsf/pointing/ConstantProxy.inl"


namespace jmsf {
namespace assisting {


template< class A_type >
pointing::Proxy< containing::Iterator< A_type > > find( pointing::Proxy< containing::Container< A_type > > &container, A_type &object ) throw( validating::Exception ) {
	for (
		Proxy< containing::Iterator< A_type > > containerIterator = container->createForwardIterator();
		containerIterator->isNotDone();
		containerIterator->advance() )
	{
		if ( containerIterator->takeContainie() == object ) {
			return containerIterator;
		}
	}

	return pointing::Proxy< containing::Iterator< A_type > >();
}

template< class A_type >
pointing::ConstantProxy< containing::ConstantIterator< A_type > constantFind( const pointing::ConstantProxy< containing::Container< A_type > > &container, const A_type &object ) throw ( validating::Exception ) {
	for (
		pointing::ConstantProxy< containing::ConstantIterator< A_type > > containerIterator = container->createConstantForwardIterator();
		containerIterator->isNotDone();
		containerIterator->advance() )
	{
		if ( containerIterator->getContainie() == object ) {
			return containerIterator;
		}
	}

	return pointing::ConstantProxy< containing::ConstantIterator< A_type > >();
}


} // namespace
}
