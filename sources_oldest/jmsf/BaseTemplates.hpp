#pragma once

//#include "Iterators.hxx"


namespace jmsf {


template< class A_type >
struct IndirectorBase {
	typedef A_type type_indirected;
};

// template< class A_type >
// struct ContainerBase {
// 	typedef ConstantIterator< A_type > type_contained_constant_iterator;
// 	typedef Iterator< A_type > type_container_iterator;
// };


} // namespace
