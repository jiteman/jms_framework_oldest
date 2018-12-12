#pragma once


#include "Constructor.hxx"

#include "Allocator.hxx"
#include "Omp.hxx"
#include "Amp.hxx"
#include "Womp.hxx"

#include "jmsf/typing/Naturals.hxx"


namespace jmsf {
namespace memorying {


template< class A_type, class A_creating_type >
class Constructor {

public:
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator ) throw(); // default construction
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_creating_type &original ) throw(); // copy construction

	template< class A_first >
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first ) throw();

	template< class A_first, class A_second >
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second ) throw();

	template< class A_first, class A_second, class A_third >
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third ) throw();

	template< class A_first, class A_second, class A_third, class A_fourth >
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth ) throw();

	template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth >
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth ) throw();

	template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth >
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth ) throw();

	template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth, class A_seventh >
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth, const A_seventh &seventh ) throw();

	template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth, class A_seventh, class An_eighth >
	static Omp< A_type > construct( const Womp< Allocator > &an_allocator, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth, const A_seventh &seventh, const An_eighth &eighth ) throw();


	static Amp< A_type > construct_default_as_array( const Womp< Allocator > &an_allocator, typing::Memory_size quantity_of_objects ) throw(); // default array construction
	static Amp< A_type > construct_copy_as_array( const Womp< Allocator > &an_allocator, typing::Memory_size quantity_of_objects, const A_creating_type &original ) throw(); // array copy construction

	template< class A_first >
	static Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, typing::Memory_size quantity_of_objects, const A_first &first ) throw();

	template< class A_first, class A_second >
	static Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second ) throw();

	template< class A_first, class A_second, class A_third >
	static Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &third ) throw();

	template< class A_first, class A_second, class A_third, class A_fourth >
	static Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth ) throw();

	template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth >
	static Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth ) throw();

	template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth >
	static Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth ) throw();

	template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth, class A_seventh >
	static Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth, const A_seventh &seventh ) throw();

	template< class A_first, class A_second, class A_third, class A_fourth, class A_fifth, class A_sixth, class A_seventh, class An_eighth >
	static Amp< A_type > construct_as_array( const Womp< Allocator > &an_allocator, typing::Memory_size quantity_of_objects, const A_first &first, const A_second &second, const A_third &third, const A_fourth &fourth, const A_fifth &fifth, const A_sixth &sixth, const A_seventh &seventh, const An_eighth &eighth ) throw();


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace memorying
} // namespace jmsf

