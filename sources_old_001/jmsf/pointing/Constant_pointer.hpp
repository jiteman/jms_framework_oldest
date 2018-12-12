#pragma once

#include "Constant_pointer.hxx"


#include "internalling/Base_for_const_pap.hpp"
#include "internalling/Type_data.hpp"
#include "internalling/Pointer_deleter.hpp"

#include "jmsf/memorying/Omp.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"


namespace jmsf {
namespace pointing {


template< class A_type >
class Constant_pointer :
	public internalling::Base_for_const_pap< internalling::Type_data< A_type, internalling::Pointer_deleter > >
{
	typedef internalling::Base_for_const_pap< internalling::Type_data< A_type, internalling::Pointer_deleter > > internalling_Constant_pointer_base_class;

public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Constant_pointer get_as_weak() noexcept;
	Constant_pointer get_as_shared() noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Constant_pointer() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Constant_pointer() noexcept;

private:
	Constant_pointer( const memorying::Omp< A_type > &object_memory_pointer ) noexcept;
	Constant_pointer( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &object_memory_pointer ) noexcept;

public:
	static Constant_pointer create_empty() noexcept;
	static Constant_pointer create_non_linked( const memorying::Omp< A_type > &object_memory_pointer ) noexcept;
	static Constant_pointer create_shared( const memorying::Womp< memorying::Allocator > &reference_counters_allocator, const memorying::Omp< A_type > &object_memory_pointer ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
//	Constant_pointer( const Constant_pointer &another ) noexcept;
//	const Constant_pointer &operator =( const Constant_pointer &another ) noexcept;

//	Constant_pointer( Constant_pointer &&another ) noexcept;
//	Constant_pointer &operator =( Constant_pointer &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace pointing
} // namespace jmsf
