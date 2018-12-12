#pragma once


#include "Proxy_deleter.hpp"
#include "jmsf/memorying/Womp.hxx"


namespace jmsf {
namespace temping {
namespace internals {


template< class A_type >
class Proxy_deleter {

public:
	static void delete_object( const memorying::Omp< A_type > &memoryObject ) noexcept;
	static memorying::Womp< A_type > get_null_object_via_deleter() noexcept;

private:
	Proxy_deleter() noexcept;

};


} // namespace internals
} // namespace temping
} // jmsf
