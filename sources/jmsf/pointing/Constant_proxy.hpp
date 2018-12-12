#pragma once


#include "internals/Base_for_constant_pointer_and_constant_proxy.hpp"
#include "internals/Type_data.hpp"
#include "internals/Proxy_deleter.hpp"

#include "jmsf/typing/Naturals.hxx"

#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace pointing {


template< class A_type >
class Constant_proxy :
	public internals::Base_for_constant_pointer_and_constant_proxy< internals::Type_data< A_type, internals::Proxy_deleter > >
{

public:
	const Constant_proxy get_nonlinked() const;
	const Constant_proxy get_as_shared( memorying::Womp< memorying::Allocator > reference_counters_allocator = memorying::Womp< memorying::Allocator >() ) const;

public:
	static Constant_proxy create_none();
	static Constant_proxy create_empty();	
	static Constant_proxy create_nonlinked_for( const memorying::Omp< A_type > &pointerToObject );
	static Constant_proxy create_unique( const memorying::Omp< A_type > &pointerToObject );
	static Constant_proxy create_shared( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &pointerToObject );

public:
	Constant_proxy() noexept;

private:
	Constant_proxy( typing::Shortest_natural type, const memorying::Omp< A_type > &pointerToObject );
	Constant_proxy( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &pointerToObject );

};


} // namespace pointing
} // namespace jmsf
