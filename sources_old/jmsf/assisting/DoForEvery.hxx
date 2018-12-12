#pragma once


#include "Functor.hxx"
#include "jmsf/containing/Container.hxx"
#include "jmsf/containing/Iterator.hxx"
#include "jmsf/containing/ConstantIterator.hxx"
#include "jmsf/pointing/Proxy.hxx"
#include "jmsf/pointing/ConstantProxy.hxx"


namespace jmsf {
namespace assisting {


template< class A_type >
void doForEvery( pointing::Proxy< containing::Container< A_type > &container, pointing::Proxy< Functor< A_type > > &functor ) throw( validating::Exception ) {
	for (
		pointing::Proxy< containing::Iterator< A_type > > containerIterator = container->createForwardIterator();
		containerIterator->isNotDone();
		containerIterator->advance() )
	{
		functor->runMethod( containerIterator->takeContainie() );
	}	
}

template< class A_type >
void constantDoForEvery( const pointing::ConstantProxy< containing::Container< A_type > > &container, const pointing::ConstantProxy< ConstantFunctor< A_type > > &functor ) throw( validating::Exception ) {
	for (
		pointing::ConstantProxy< containing::Iterator< A_type > > containerIterator = container->createConstantForwardIterator();
		containerIterator->isNotDone();
		containerIterator->advance() )
	{
		functor->runMethod( containerIterator->getContainie() );
	}	
}


} // namespace
}
