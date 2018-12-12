#pragma once


#include "List.hxx"

#include "List_agent.hpp"

#include "jmsf/memorying/Omp.hpp"
#include "jmsf/typing/Naturals.hpp"
#include "jmsf/typing/Boolean.h"

#include "../traversing/List_traverser.hxx"
#include "../noding/Doubly_linked_node.hxx"

#include "jmsf/assisting/Comparator.hxx"


#include "jmsf/validating/Exception.hxx"

#include "jmsf/memorying/Allocator.hxx"


namespace jmsf {
namespace structing {
namespace containing {


template< class A_type >
class List :
	public List_agent< A_type >
{

public: // common getters
	typing::Boolean is_empty() const noexept;
	typing::Boolean is_not_empty() const noexept;
	typing::Memory_size get_quantity_of_elements() const noexept;
	typing::Boolean is_sorted() const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // appending modifiers
	void append_to_begin( const memorying::Womp< memorying::Allocator > &node_allocator, const A_type &an_object ) noexept;
	void append_to_end( const memorying::Womp< memorying::Allocator > &node_allocator, const A_type &an_object ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // sorting
	void sort( const assisting::Comparator< A_type > &a_comparator ) noexept;
	void append_sorted( const memorying::Womp< memorying::Allocator > &node_allocator, const assisting::Comparator< A_type > &a_comparator, const A_type &an_object ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // factories
	traversing::List_traverser< A_type > create_traverser_at_begin();
	traversing::List_traverser< A_type > create_traverser_at_end();
	traversing::List_traverser< A_type > create_traverser_from_begin( typing::Memory_size an_index );
	traversing::List_traverser< A_type > create_traverser_from_end( typing::Memory_size an_index );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: // friend traversing::List_traverser< A_type >
	// virtuals List_agent< A_type >
	memorying::Omp< noding::Doubly_linked_node< A_type > > &take_begin() noexept;
	memorying::Omp< noding::Doubly_linked_node< A_type > > &take_end() noexept;
	typing::Memory_size &take_quantity() noexept;
	//~virtuals List_agent< A_type >

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~List() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	List() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	List( const List &another ) noexept;
	const List &operator =( const List &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Omp< noding::Doubly_linked_node< A_type > > _the_begin;
	memorying::Omp< noding::Doubly_linked_node< A_type > > _the_end;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	typing::Memory_size _quantity_of_elements;
	typing::Boolean _is_sorted;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace containing
} // namespace sructing
} // namespace jmsf
