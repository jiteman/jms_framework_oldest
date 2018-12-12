#pragma once


#include "List_traverser.hxx"

#include "jmsf/memorying/Womp.hpp"
#include "jmsf/memorying/Omp.hpp"

#include "jmsf/typing/Boolean.h"

#include "jmsf/structing/containing/List_agent.hxx"
#include "jmsf/structing/containing/List.hxx"
#include "jmsf/structing/noding/Doubly_linked_node.hxx"


#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace structing {
namespace traversing {


template< class A_type >
class List_traverser
{

public: // common getters
	typing::Boolean is_done() const noexept;
	typing::Boolean is_not_done() const noexept;
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // element getters
	const A_type &get_object() const;
	A_type &take_object();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // iterations
	void rewind_to_begin() noexept;
	void rewind_to_end() noexept;
	void move_one_step_to_begin();
	void move_one_step_to_end();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // appending modifiers
	void insert_after( const A_type &anObject, const memorying::Allocator &aNodeAllocator );
	void insert_before( const A_type &anObject, const memorying::Allocator &aNodeAllocator );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // erasing modifiers
	void erase_object();
	A_type withdraw_object();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	void inverse_reversing() noexept;
	void set_reversing( typing::Boolean isReversed ) noexept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~List_traverser() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	List_traverser() noexept;
	List_traverser create_next();
	List_traverser create_previous();

private: friend containing::List< A_type >;
	List_traverser( const memorying::Womp< containing::List_agent< A_type > > &aListAgent, const memorying::Omp< noding::Doubly_linked_node< A_type > > &aNode, typing::Boolean isReversed ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	List_traverser( const List_traverser &other ) noexept;
	const List_traverser &operator =( const List_traverser &other ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Womp< containing::List_agent< A_type > > _the_list_agent;
	memorying::Omp< noding::Doubly_linked_node< A_type > > _the_node;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	typing::Boolean _is_reversed;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace traversing
} // namespace structing
} // namespace jmsf
