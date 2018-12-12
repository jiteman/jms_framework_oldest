#pragma once


#include "List.hpp"

#include "List_agent.inl"
#include "jmsf/memorying/Omp.inl"
#include "jmsf/memorying/Womp.inl"
#include "jmsf/structing/noding/Doubly_linked_node.inl"
#include "jmsf/memorying/Destructor.inl"


namespace jmsf {
namespace structing {
namespace containing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// common getters
template< class A_type >
typing::Boolean List< A_type >::is_empty() const noexept {
	return _quantity_of_elements.is_nill();
}

template< class A_type >
typing::Boolean List< A_type >::is_not_empty() const noexept {
	return _quantity_of_elements.is_not_nill();
}

template< class A_type >
typing::Memory_size List< A_type >::get_quantity_of_elements() const noexept {
	return _quantity_of_elements;
}

template< class A_type >
typing::Boolean List< A_type >::is_sorted() const noexept {
	return _is_sorted;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// appending modifiers
template< class A_type >
void List< A_type >::append_to_begin( const memorying::Womp< memorying::Allocator > &node_allocator, const A_type &an_object ) noexept {
	memorying::Omp< noding::Doubly_linked_node< A_type > > newBeginNode =
		noding::Doubly_linked_node< A_type >::create(
			an_object,
			memorying::Omp< noding::Doubly_linked_node< A_type > >(),
			_the_begin,
			node_allocator );

	if ( _the_begin.is_not_empty() ) {
		_the_begin->set_previous_node( newBeginNode );
	}

	_the_begin = newBeginNode;

	if ( _the_end.is_empty() ) {
		_the_end = _the_begin;
	}

	_is_sorted = typing::False;
}

template< class A_type >
void List< A_type >::append_to_end( const memorying::Womp< memorying::Allocator > &node_allocator, const A_type &an_object ) noexept {
	memorying::Omp< noding::Doubly_linked_node< A_type > > newEndNode =
		noding::Doubly_linked_node< A_type >::create(
			an_object,			
			_the_end,
			memorying::Omp< noding::Doubly_linked_node< A_type > >(),
			node_allocator );

	if ( _the_end.is_not_empty() ) {
		_the_end->set_next_node( newEndNode );
	}

	_the_end = newEndNode;

	if ( _the_begin.is_empty() ) {
		_the_begin = _the_end;
	}

	_is_sorted = typing::False;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// sorting
template< class A_type >
void List< A_type >::sort( const assisting::Comparator< A_type > &a_comparator ) noexept {
	if ( is_empty() ) return;

	memorying::Omp< noding::Doubly_linked_node< A_type > > last_node = _the_begin;
	memorying::Omp< noding::Doubly_linked_node< A_type > > current_node = _the_begin->get_next_node();	

	while ( current_node.is_empty() ) {
		if ( a_comparator.compare( last_node->get_object(), current_node->get_object() ).is_greater() ) {
			// find a place
			memorying::Omp< noding::Doubly_linked_node< A_type > > first_greater;
			for ( memorying::Omp< noding::Doubly_linked_node< A_type > > node_iterator = _the_begin; node_iterator.is_not_empty(); node_iterator = node_iterator->take_next_node() ) {
				if ( a_comparator.compare( node_iterator->get_object(), current_node->get_object() ).is_greater() ) {
					first_greater = node_iterator;
					break;
				}
			}
			
			const typing::Boolean removing_from_end = typing::Boolean::create( current_node.get() == _the_end.get() );
			const typing::Boolean inserting_at_begin = typing::Boolean::create( first_greater.get() == _the_begin.get() );
			
			last_node = current_node->get_previous_node();
			memorying::Omp< noding::Doubly_linked_node< A_type > > next_current_node = current_node->take_next_node();

			// remove node from old place
			{
				current_node->take_previous_node()->set_next_node( current_node->get_next_node() );

				if ( current_node.get() == _the_end.get() ) {
					// removing_from_end
					_the_end = current_node->take_previous_node();
					_the_end->set_next_node( current_node->get_next_node() );
				} else {
					current_node->take_next_node()->set_previous_node( current_node->get_previous_node() );
				}
			}

			// insert node into new place
			{
				if ( first_greater.get() == _the_begin.get() ) {
					// inserting_at_begin
					current_node->set_previous_node( _the_begin->get_previous_node() );
					current_node->set_next_node( _the_begin );
					_the_begin->set_previous_node( current_node );
					_the_begin = current_node;					
				} else {
					current_node->set_previous_node( first_greater->get_previous_node() );
					current_node->set_next_node( first_greater );
					first_greater->take_previous_node()->set_next_node( current_node );
					first_greater->set_previous_node( current_node );
				}
			}

			current_node = next_current_node;
		} else {
			current_node = current_node->get_next_node();
		}
	}

	_is_sorted = typing::True;
}

template< class A_type >
void List< A_type >::append_sorted( const memorying::Womp< memorying::Allocator > &node_allocator, const assisting::Comparator< A_type > &a_comparator, const A_type &an_object ) noexept {
	if ( _is_sorted.not() ) {
		sort( a_comparator );
	}

	memorying::Omp< noding::Doubly_linked_node< A_type > > first_greater;
	{
		for ( memorying::Omp< noding::Doubly_linked_node< A_type > > node_iterator = _the_begin; node_iterator.is_not_empty(); node_iterator = node_iterator->take_next_node() ) {
			if ( a_comparator.compare( node_iterator->get_object(), an_object ).is_greater() ) {
				first_greater = node_iterator;
				break;
			}
		}
	}

	if ( first_greater.is_empty() ) {
		// append to end
		append_to_end( node_allocator, an_object );
	} else if ( first_greater.get() == _the_begin.get() ) {
		// append to begin
		append_to_begin( node_allocator, an_object );
	} else {
		// append before first_greater
		memorying::Omp< noding::Doubly_linked_node< A_type > > new_middle_node =
			noding::Doubly_linked_node< A_type >::create(
				an_object,			
				first_greater->get_previous_node(),
				first_greater,
				node_allocator );

		first_greater->take_previous_node()->set_next_node( new_middle_node );
		first_greater->set_previous_node( new_middle_node );
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// factories
template< class A_type >
traversing::List_traverser< A_type > List< A_type >::create_traverser_at_begin() {
	return traversing::List_traverser< A_type >( memorying::Womp< List_agent< A_type > >::create_from_pointer( this ), _the_begin, typing::False );
}

template< class A_type >
traversing::List_traverser< A_type > List< A_type >::create_traverser_at_end() {
	return traversing::List_traverser< A_type >( memorying::Womp< List_agent< A_type > >::create_from_pointer( this ), _the_end, typing::True );
}

template< class A_type >
traversing::List_traverser< A_type > List< A_type >::create_traverser_from_begin( const typing::Memory_size an_index ) {
	// if is_empty() throw exception;
	// if index is negative throw exception
	// if index is out of range throw exception
	memorying::Omp< noding::Doubly_linked_node< A_type > > indexed_node = _the_begin;

	for ( typing::Memory_size node_counter = an_index; node_counter.is_not_nill(); --node_counter ) {
		indexed_node = indexed_node->take_next_node();
	}

	return traversing::List_traverser< A_type > >( memorying::Womp< List_agent< A_type > >::create( this ), indexed_node, typing::False );
}

template< class A_type >
traversing::List_traverser< A_type > List< A_type >::create_traverser_from_end( const typing::Memory_size an_index ) {
	// if is_empty() throw exception;
	// if index is negative throw exception
	// if index is out of range throw exception
	memorying::Omp< noding::Doubly_linked_node< A_type > > indexed_node = _the_end;

	for ( typing::Memory_size node_counter = an_index; node_counter.is_not_nill(); --node_counter ) {
		indexed_node = indexed_node->take_previous_node();
	}

	return traversing::List_traverser< A_type > >( memorying::Womp< List_agent< A_type > >::create( this ), indexed_node, typing::True );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// virtuals ListAgent< A_type >
template< class A_type >
memorying::Omp< noding::Doubly_linked_node< A_type > > &List< A_type >::take_begin() noexept {
	return _the_begin;
}

template< class A_type >
memorying::Omp< noding::Doubly_linked_node< A_type > > &List< A_type >::take_end() noexept {
	return _the_end;
}

template< class A_type >
typing::Memory_size &List< A_type >::take_quantity() noexept {
	return _quantity_of_elements;
}

//~virtuals ListAgent< A_type >
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
List< A_type >::~List() noexept {
	memorying::Omp< noding::Doubly_linked_node< A_type > > current_node = _the_begin;

	while ( current_node.is_not_empty() ) {
		memorying::Omp< noding::Doubly_linked_node< A_type > > next_node = current_node->take_next_node();
		memorying::Destructor< noding::Doubly_linked_node< A_type > >::destruct( current_node );
		current_node = next_node;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
List< A_type >::List() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
List< A_type >::List( const List< A_type > &another ) noexept
{}

template< class A_type >
const List< A_type > &List< A_type >::operator =( const List< A_type > &another ) noexept {
	if ( &another == this ) return *this;
	
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace containing
} // namespace structing
} // namespace jmsf
