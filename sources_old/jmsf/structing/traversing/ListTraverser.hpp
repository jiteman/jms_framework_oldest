#pragma once


#include "ListTraverser.hxx"

#include "jmsf/structing/containing/List.hxx"
#include "jmsf/structing/noding/DoublyLinkedNode.hxx"

#include "jmsf/pointing/WeakReference.hpp"
#include "jmsf/pointing/Reference.hpp"

#include "jmsf/typing/Boolean.h"


namespace jmsf {
namespace sructing {
namespace traversing {


template< class A_type >
class ListTraverser
{

public: // common getters
	typing::Boolean isDone() const throw();
	typing::Boolean isNotDone() const throw();
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // element getters
	const A_type &getObject() const throw( validating::Exception );
	A_type &takeObject() throw( validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // iterations
	void rewindToBegin() throw();
	void rewindToEnd() throw();
	void moveOneStepToBegin() throw( validating::Exception );
	void moveOneStepToEnd() throw( validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // appending modifiers
	void insertAfter( const memorying::Allocator &aNodeAllocator, const A_type &anObject ) throw( validating::Exception );
	void insertBefore( const memorying::Allocator &aNodeAllocator, const A_type &anObject ) throw( validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // erasing modifiers
	void eraseObject() throw( validating::Exception );
	A_type withdrawObject() throw( validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	void inverseReversing() throw();
	void setRevercing( typing::Boolean isReversed ) throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~ListTraverser() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	ListTraverser( const pointing::WeakReference< containing::ListAgent< A_type > > &aListAgent, const pointing::Reference< noding::DoublyLinkedNode< A_type > > &aNode, typing::Boolean isReversed ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	ListTraverser( const ListTraverser &other ) throw();
	const ListTraverser &operator =( const ListTraverser &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::WeakReference< containing::ListAgent< A_type > > _theListAgent;
	pointing::Reference< noding::DoublyLinkedNode< A_type > > _theNode;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Boolean _isReversed;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace traversing
} // namespace sructing
} // namespace jmsf
