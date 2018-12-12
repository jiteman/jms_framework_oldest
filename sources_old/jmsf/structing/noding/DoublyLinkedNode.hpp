#pragma once


#include "DoublyLinkedNode.hxx"
#include "jmsf/pointing/Reference.hpp"

#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/memorying/Allocator.hxx"
#include "jmsf/validating/Exception.hxx"


namespace jmsf {
namespace structing {
namespace noding {


template< class A_type >
class DoublyLinkedNode {

public:
	A_type &takeObject() throw();
	const A_type &getObject() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	pointing::Reference< DoublyLinkedNode > &takePreviousNode() throw();
	const pointing::Reference< DoublyLinkedNode > &getPreviousNode() const throw();

	pointing::Reference< DoublyLinkedNode > &takeNextNode() throw();
	const pointing::Reference< DoublyLinkedNode > &getNextNode() const throw();

	void setPreviousNode( const pointing::Reference< DoublyLinkedNode > &previousNode ) throw();
	void setNextNode( const pointing::Reference< DoublyLinkedNode > &nextNode ) throw();	

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< DoublyLinkedNode >;
	~DoublyLinkedNode() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static pointing::Reference< DoublyLinkedNode< A_type > > create( memorying::Allocator &allocator ) throw( validating::Exception );
	static pointing::Reference< DoublyLinkedNode< A_type > > create( const A_type &anObject, memorying::Allocator &allocator ) throw( validating::Exception );
	static pointing::Reference< DoublyLinkedNode< A_type > > create( const A_type &anObject, const pointing::Reference< DoublyLinkedNode > &previousNode, const pointing::Reference< DoublyLinkedNode > &nextNode, memorying::Allocator &allocator ) throw( validating::Exception );

private: friend memorying::Constructor< DoublyLinkedNode >;
	DoublyLinkedNode() throw();
	DoublyLinkedNode( const A_type &anObject ) throw();
	DoublyLinkedNode( const A_type &anObject, const pointing::Reference< DoublyLinkedNode > &previousNode, const pointing::Reference< DoublyLinkedNode > &nextNode ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	DoublyLinkedNode( const DoublyLinkedNode &other ) throw();
	const DoublyLinkedNode &operator =( const DoublyLinkedNode &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::Reference< DoublyLinkedNode > _previousNode;
	pointing::Reference< DoublyLinkedNode > _nextNode;	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	A_type _theObject;

};


} // namespace noding
} // namespace structing
} // namespace jmsf
