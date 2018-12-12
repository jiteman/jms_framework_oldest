#pragma once


#include "internals/Base_for_pointer_and_proxy.hpp"
#include "internals/Type_data.hpp"
#include "internals/Proxy_deleter.hpp"

#include "Constant_proxy.hxx"

#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace pointing {


template< class A_type >
class Proxy :
	public internals::Base_for_pointer_and_proxy< internals::Type_data< A_type, internals::Proxy_deleter > >
{

public:
	Proxy get_nonlinked() const;
	const Constant_proxy< A_type > get_nonlinked_constant() const ;
	const Constant_proxy< A_type > take_constant() const;

	const Proxy get_as_shared( memorying::Womp< memorying::Allocator > reference_counters_allocator = memorying::Womp< memorying::Allocator >() ) const;
	Proxy take_as_shared( memorying::Womp< memorying::Allocator > reference_counters_allocator = memorying::Womp< memorying::Allocator >() );
	
public:
	static Proxy create_none();
	static Proxy create_empty();	
	static Proxy create_nonlinked_for( const memorying::Omp< A_type > &pointerToObject );
	static Proxy create_unique( const memorying::Omp< A_type > &pointerToObject );
	static Proxy create_shared( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &pointerToObject );

public:
	Proxy() noexept;

// public:
// 	Proxy( const Proxy &other ) throw( validating::Exception );
// 	const Proxy &operator =( const Proxy &other ) throw( validating::Exception );

private:
	Proxy( typing::Shortest_natural type, const memorying::Omp< A_type > &pointerToObject );
	Proxy( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &pointerToObject );

};


} // namespace pointing
} // namespace jmsf
