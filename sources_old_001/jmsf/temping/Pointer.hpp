#pragma once


#include "internals/Base_for_pointer_and_proxy.hpp"
#include "internals/Type_data.hpp"
#include "internals/Pointer_deleter.hpp"

#include "Constant_pointer.hxx"

#include "jmsf/typeing/Naturals.hxx"


namespace jmsf {
namespace temping {


template< class A_type >
class Pointer :
	public internals::Base_for_pointer_and_proxy< internals::Type_data< A_type, internals::Pointer_deleter > >
{
	typedef internals::Base_for_pointer_and_proxy< internals::Type_data< A_type, internals::Pointer_deleter > > temping_Pointer_base_class_type;

public:
	Pointer get_nonlinked() const;
	const Constant_pointer< A_type > get_nonlinked_constant() const;
	const Constant_pointer< A_type > take_constant() const;

	const Pointer get_as_shared( memorying::Womp< memorying::Allocator > reference_counters_allocator = memorying::Womp< memorying::Allocator >() ) const;
	Pointer take_as_shared( memorying::Womp< memorying::Allocator > reference_counters_allocator = memorying::Womp< memorying::Allocator >() );

public:
	static Pointer create_none();
	static Pointer create_empty();
	static Pointer create_nonlinked_for( const memorying::Omp< A_type > &pointerToObject );
	static Pointer create_unique( const memorying::Omp< A_type > &pointerToObject );
	static Pointer create_shared( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &pointerToObject );

public:
	Pointer() noexcept;

private:
	Pointer( typeing::Shortest_natural type, const memorying::Omp< A_type > &pointerToObject );
	Pointer( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &pointerToObject );

};


} // namespace temping
} // namespace jmsf
