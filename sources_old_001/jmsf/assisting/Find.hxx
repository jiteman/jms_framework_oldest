#pragma once


// #include "jmsf/containing/Iterator.hxx"
// #include "jmsf/containing/ConstaintIterator.hxx"
// #include "jmsf/containing/Container.hxx"
// #include "jmsf/pointing/Proxy.hxx"
// #include "jmsf/pointing/ConstantProxy.hxx"
// #include "jmsf/validating/Exception.hxx"

#include "Comparator.hxx"
#include "jmsf/typeing/Comparasion_result.h"


namespace jmsf {
namespace assisting {


template< template< class > class A_traverser, class A_type >
A_traverser< A_type > find_first( const A_type &a_sample, const A_traverser< A_type > &a_traverser, const Comparator< A_type > &a_comparator, typeing::Comparasion_result comparation_result = typeing::Comparasion_result::create_equal() );
//A_traverser< typename A_type > find_first( const A_type &a_sample, const A_traverser< A_type > &a_traverser, const Comparator< A_type > &a_comparator, typeing::Comparasion_result comparation_result = typeing::Comparasion_result::create_equal() );

template< template< class > class A_traverser, class A_type >
A_traverser< A_type > find_first_not( const A_type &a_sample, const A_traverser< A_type > &a_traverser, const Comparator< A_type > &a_comparator, typeing::Comparasion_result comparation_result = typeing::Comparasion_result::create_equal() );

template< template< class > class A_traverser, class A_type >
A_traverser< A_type > find_last( const A_type &a_sample, const A_traverser< A_type > &a_traverser, const Comparator< A_type > &a_comparator, typeing::Comparasion_result comparation_result = typeing::Comparasion_result::create_equal() );

template< template< class > class A_traverser, class A_type >
A_traverser< A_type > find_last_not( const A_type &a_sample, const A_traverser< A_type > &a_traverser, const Comparator< A_type > &a_comparator, typeing::Comparasion_result comparation_result = typeing::Comparasion_result::create_equal() );

// template< class A_type >
// pointing::Proxy< containing::Iterator< A_type > > find_first_equal( pointing::Proxy< containing::Container< A_type > > &container, A_type &object ) throw( validating::Exception );
//
// template< class A_type >
// pointing::ConstantProxy< containing::ConstantIterator< A_type > constantFind( const pointing::ConstantProxy< containing::Container< A_type > > &container, const A_type &object ) throw ( validating::Exception );


} // namespace
}
