#pragma once


#include "internals/Base_for_constant_pointer_and_constant_proxy.hpp"
#include "internals/Type_data.hpp"
#include "internals/Pointer_deleter.hpp"

////#include "jmsf/typing/ShortestNatural.hxx"
#include "jmsf/typeing/Naturals.hxx"

#include "jmsf/encodebuba/common_standard_support.h"


namespace jmsf {
namespace temping {


template< class A_type >
class Constant_pointer :
	public internals::Base_for_constant_pointer_and_constant_proxy< internals::Type_data< A_type, internals::Pointer_deleter > >
{
	typedef internals::Base_for_constant_pointer_and_constant_proxy< internals::Type_data< A_type, internals::Pointer_deleter > > temping_Constant_pointer_base_class_type;


public:
	const Constant_pointer get_nonlinked() const;
	const Constant_pointer get_as_shared( memorying::Womp< memorying::Allocator > reference_counters_allocator = memorying::Womp< memorying::Allocator >() ) const;
	
public:
	static const Constant_pointer create_none(); // exceptions: Exception
	static const Constant_pointer create_empty(); // exceptions: Exception
	static const Constant_pointer create_nonlinked_for( const memorying::Omp< A_type > &pointerToObject );
	static const Constant_pointer create_unique( const memorying::Omp< A_type > &pointerToObject );
	static const Constant_pointer create_shared( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &pointerToObject );

public:
	Constant_pointer() noexcept;

private:
	Constant_pointer( typeing::Shortest_natural type, const memorying::Omp< A_type > &pointerToObject );
	Constant_pointer( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &pointerToObject );

};


} // namespace temping
} // namespace jmsf
