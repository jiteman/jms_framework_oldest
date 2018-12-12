#pragma once


#include "Doubly_linked_node.hxx"
#include "jmsf/memorying/Omp.hpp"
#include "jmsf/memorying/Womp.hxx"

#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/memorying/Allocator.hxx"



namespace jmsf {
namespace structing {
namespace noding {


template< class A_type >
class Doubly_linked_node {

public:
	A_type &take_object() noexept;
	const A_type &get_object() const noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	memorying::Omp< Doubly_linked_node > &take_previous_node() noexept;
	const memorying::Omp< Doubly_linked_node > &get_previous_node() const noexept;

	memorying::Omp< Doubly_linked_node > &take_next_node() noexept;
	const memorying::Omp< Doubly_linked_node > &get_next_node() const noexept;

	void set_previous_node( const memorying::Omp< Doubly_linked_node > &previous_node ) noexept;
	void set_next_node( const memorying::Omp< Doubly_linked_node > &next_node ) noexept;	

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< Doubly_linked_node >;
	~Doubly_linked_node() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static memorying::Omp< Doubly_linked_node< A_type > > create( const memorying::Womp< memorying::Allocator > &an_allocator );
	static memorying::Omp< Doubly_linked_node< A_type > > create( const A_type &an_object, const memorying::Womp< memorying::Allocator > &an_allocator );

	static memorying::Omp< Doubly_linked_node< A_type > > create(
		const A_type &an_object,
		const memorying::Omp< Doubly_linked_node > &previous_node,
		const memorying::Omp< Doubly_linked_node > &next_node,
		const memorying::Womp< memorying::Allocator > &an_allocator );

private: friend memorying::Constructor< Doubly_linked_node, Doubly_linked_node >;
	Doubly_linked_node() noexept;
	Doubly_linked_node( const A_type &an_object ) noexept;
	Doubly_linked_node( const A_type &an_object, const memorying::Omp< Doubly_linked_node > &previous_node, const memorying::Omp< Doubly_linked_node > &next_node ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Doubly_linked_node( const Doubly_linked_node &another ) noexept;
	const Doubly_linked_node &operator =( const Doubly_linked_node &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Omp< Doubly_linked_node > _previous_node;
	memorying::Omp< Doubly_linked_node > _next_node;	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	A_type _the_object;

};


} // namespace noding
} // namespace structing
} // namespace jmsf
