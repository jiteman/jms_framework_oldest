#pragma once


// #include "jmsf/containing/Iterator.inl"
// #include "jmsf/containing/ConstaintIterator.inl"
// #include "jmsf/containing/Container.inl"
// #include "jmsf/pointing/Proxy.inl"
// #include "jmsf/pointing/ConstantProxy.inl"

#include "Find.hpp"

#include "Comparator.inl"

#include "jmsf/typing/Comparasion_result.h"


namespace jmsf {
namespace assisting {


template< template< class > class A_traverser, class A_type >
A_traverser< A_type > find_first( const A_type &a_sample, const A_traverser< A_type > &a_traverser, const Comparator< A_type > &a_comparator, const typing::Comparasion_result comparation_result ) {
	for ( A_traverser< A_type > the_traverser = a_traverser; the_traverser.is_not_done(); the_traverser.move_one_step_to_end() ) {
		if ( a_comparator.compare( a_sample, the_traverser.get_object() ) == comparation_result ) {
			return the_traverser;
		}
	}

	return A_traverser< A_type >();
}

template< template< class > class A_traverser, class A_type >
A_traverser< A_type > find_first_not( const A_type &a_sample, const A_traverser< A_type > &a_traverser, const Comparator< A_type > &a_comparator, const typing::Comparasion_result comparation_result ) {
	for ( A_traverser< A_type > the_traverser = a_traverser; the_traverser.is_not_done(); the_traverser.move_one_step_to_end() ) {
		if ( a_comparator.compare( a_sample, the_traverser.get_object() ) != comparation_result ) {
			return the_traverser;
		}
	}

	return A_traverser< A_type >();
}

template< template< class > class A_traverser, class A_type >
A_traverser< A_type > find_last( const A_type &a_sample, const A_traverser< A_type > &a_traverser, const Comparator< A_type > &a_comparator, const typing::Comparasion_result comparation_result ) {
	A_traverser< A_type > last_found;

	for ( A_traverser< A_type > the_traverser = a_traverser; the_traverser.is_not_done(); the_traverser.move_one_step_to_end() ) {
		if ( a_comparator.compare( a_sample, the_traverser.get_object() ) == comparation_result ) {
			last_found = the_traverser;
		}
	}

	return last_found;
}

template< template< class > class A_traverser, class A_type >
A_traverser< A_type > find_last_not( const A_type &a_sample, const A_traverser< A_type > &a_traverser, const Comparator< A_type > &a_comparator, const typing::Comparasion_result comparation_result ) {
	A_traverser< A_type > last_found;

	for ( A_traverser< A_type > the_traverser = a_traverser; the_traverser.is_not_done(); the_traverser.move_one_step_to_end() ) {
		if ( a_comparator.compare( a_sample, the_traverser.get_object() ) != comparation_result ) {
			last_found = the_traverser;
		}
	}

	return last_found;
}

// template< class A_type >
// pointing::Proxy< containing::Iterator< A_type > > find_first_equal( pointing::Proxy< containing::Container< A_type > > &container, A_type &object ) throw( validating::Exception ) {
// 	for (
// 		Proxy< containing::Iterator< A_type > > containerIterator = container->createForwardIterator();
// 		containerIterator->isNotDone();
// 		containerIterator->advance() )
// 	{
// 		if ( containerIterator->takeContainie() == object ) {
// 			return containerIterator;
// 		}
// 	}
// 
// 	return pointing::Proxy< containing::Iterator< A_type > >();
// }
// 
// template< class A_type >
// pointing::ConstantProxy< containing::ConstantIterator< A_type > constantFind( const pointing::ConstantProxy< containing::Container< A_type > > &container, const A_type &object ) throw ( validating::Exception ) {
// 	for (
// 		pointing::ConstantProxy< containing::ConstantIterator< A_type > > containerIterator = container->createConstantForwardIterator();
// 		containerIterator->isNotDone();
// 		containerIterator->advance() )
// 	{
// 		if ( containerIterator->getContainie() == object ) {
// 			return containerIterator;
// 		}
// 	}
// 
// 	return pointing::ConstantProxy< containing::ConstantIterator< A_type > >();
// }


} // namespace
}
