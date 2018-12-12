#pragma once


#include "Pointer_deleter.hxx"
#include "jmsf/memorying/Omp.hxx"


namespace jmsf {
namespace pointing {
namespace internalling {


template< class A_type >
class Pointer_deleter {

public:
	static void delete_object( const memorying::Omp< A_type > &object ) noexcept;
	static memorying::Womp< A_type > get_null_object_via_deleter() noexcept;

private:
	Pointer_deleter() noexcept;

};


} // namespace internalling
} // namespace pointing
} // namespace jmsf
