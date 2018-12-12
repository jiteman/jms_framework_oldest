#pragma once


#include "List.hxx"

#include "ListAgent.hpp"

#include "jmsf/pointing/Reference.hpp"
#include "jmsf/typing/Asd.h"

#include "../traversing/ListTraverser.hxx"
#include "../noding/DoublyLinkedNode.hxx"

#include "jmsf/typing/Boolean.hxx"
#include "jmsf/validating/Exception.hxx"

#include "jmsf/memorying/Allocator.hxx"


namespace jmsf {
namespace sructing {
namespace containing {


template< class A_type >
class List :
	public ListAgent< A_type >
{

public: // common getters
	typing::Boolean isEmpty() const throw();
	typing::Boolean isNotEmpty() const throw();
	const typing::Asd &getQuantityOfElements() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // appending modifiers
	void appendToBegin( const A_type &anObject, memorying::Allocator &nodeAllocator ) throw();
	void appendToEnd( const A_type &anObject, memorying::Allocator &nodeAllocator ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // factories
	pointing::Reference< traversing::ListTraverser< A_type > > createTraverserAtBegin( const memorying::Allocator &traverserAllocator ) throw( validating::Exception );
	pointing::Reference< traversing::ListTraverser< A_type > > createTraverserAtEnd( const memorying::Allocator &traverserAllocator ) throw( validating::Exception );
	pointing::Reference< traversing::ListTraverser< A_type > > createTraverserAtFromBegin( const typing::Asd &anIndex, const memorying::Allocator &traverserAllocator ) throw( validating::Exception );
	pointing::Reference< traversing::ListTraverser< A_type > > createTraverserAtFromEnd( const typing::Asd &anIndex, const memorying::Allocator &traverserAllocator ) throw( validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: // friend traversing::ListTraverser< A_type >
	// virtuals ListAgent< A_type >
	pointing::Reference< noding::DoublyLinkedNode< A_type > > &takeBegin() throw();
	pointing::Reference< noding::DoublyLinkedNode< A_type > > &takeEnd() throw();
	typing::Asd &takeQuantity() throw();
	//~virtuals ListAgent< A_type >

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~List() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	List() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	List( const List &another ) throw();
	const List &operator =( const List &another ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::Reference< noding::DoublyLinkedNode< A_type > > _begin;
	pointing::Reference< noding::DoublyLinkedNode< A_type > > _end;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	typing::Asd _quantityOfElements;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace containing
} // namespace sructing
} // namespace jmsf
