#pragma once


#include "Proxy_deleter.hpp"
#include "jmsf/memorying/Womp.hxx"


namespace jmsf {
namespace pointing {
namespace internalling {


template< class A_type >
class Proxy_deleter {

public:
	static void delete_object( const memorying::Omp< A_type > &memoryObject ) noexcept;
	static memorying::Womp< A_type > get_null_object_via_deleter() noexcept;

private:
	Proxy_deleter() noexcept;

};


} // namespace internalling
} // namespace pointing
} // jmsf
