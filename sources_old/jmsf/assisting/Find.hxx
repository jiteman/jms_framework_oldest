#pragma once


#include "jmsf/containing/Iterator.hxx"
#include "jmsf/containing/ConstaintIterator.hxx"
#include "jmsf/containing/Container.hxx"
#include "jmsf/pointing/Proxy.hxx"
#include "jmsf/pointing/ConstantProxy.hxx"
#include "jmsf/validating/Exception.hxx"


namespace jmsf {
namespace assisting {


template< class A_type >
pointing::Proxy< containing::Iterator< A_type > > find( pointing::Proxy< containing::Container< A_type > > &container, A_type &object ) throw( validating::Exception );

template< class A_type >
pointing::ConstantProxy< containing::ConstantIterator< A_type > constantFind( const pointing::ConstantProxy< containing::Container< A_type > > &container, const A_type &object ) throw ( validating::Exception );

} // namespace
}
