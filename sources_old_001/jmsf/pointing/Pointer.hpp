#pragma once

#include "Pointer.hxx"


#include "internalling/Base_for_pap.hpp"
#include "internalling/Type_data.hpp"
#include "internalling/Pointer_deleter.hpp"

#include "Constant_pointer.hxx"
#include "jmsf/memorying/Omp.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"


namespace jmsf {
namespace pointing {


template< class A_type >
class Pointer :
	public internalling::Base_for_pap< internalling::Type_data< A_type, internalling::Pointer_deleter > >
{
	typedef internalling::Base_for_pap< internalling::Type_data< A_type, internalling::Pointer_deleter > > internalling_Pointer_base_class;

public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Pointer get_as_weak() noexcept;
	Pointer get_as_shared() noexcept;
	Constant_pointer< A_type > get_as_constant() noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Pointer() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Pointer() noexcept;

private:
	Pointer( const memorying::Omp< A_type > &object_memory_pointer ) noexcept;
	Pointer( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &object_memory_pointer ) noexcept;

public:
	static Pointer create_empty() noexcept;
	static Pointer create_non_linked( const memorying::Omp< A_type > &object_memory_pointer ) noexcept;
	static Pointer create_shared( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &object_memory_pointer ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
//	Pointer( const Pointer &another ) noexcept;
//	const Pointer &operator =( const Pointer &another ) noexcept;

//	Pointer( Pointer &&another ) noexcept;
//	Pointer &operator =( Pointer &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace pointing
} // namespace jmsf
