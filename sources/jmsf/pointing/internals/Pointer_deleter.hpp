#pragma once


#include "Pointer_deleter.hxx"
#include "jmsf/memorying/Omp.hxx"


namespace jmsf {
namespace pointing {
namespace internals {


template< class A_type >
class Pointer_deleter {

public:
	static void delete_object( const memorying::Omp< A_type > &object ) throw();
	static memorying::Womp< A_type > get_null_object_via_deleter() throw();

private:
	Pointer_deleter() throw();

};


} // namespace internals
} // namespace pointing
} // namespace jmsf
