#pragma once


#include "Type_data.hxx"


namespace jmsf {
namespace temping {
namespace internals {


template< class A_type, template< class > class A_deleter >
class Type_data {

public:
	typedef A_type the_type;
	typedef A_deleter< A_type > the_deleter;

};


} // namespace internals
} // namespace temping
} // namespace jmsf
