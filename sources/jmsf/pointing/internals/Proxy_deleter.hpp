#pragma once


#include "Proxy_deleter.hpp"
#include "jmsf/memorying/Womp.hxx"


namespace jmsf {
namespace pointing {
namespace internals {


template< class A_type >
class Proxy_deleter {

public:
	static void delete_object( const memorying::Omp< A_type > &memoryObject ) throw();
	static memorying::Womp< A_type > get_null_object_via_deleter() throw();

private:
	Proxy_deleter() throw();

};


} // namespace internals
} // namespace pointing
} // jmsf
