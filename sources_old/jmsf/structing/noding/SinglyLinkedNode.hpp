#pragma once


#include "jmsf/pointing/Pointer.inl"
#include "jmsf/pointing/ConstantPointer.inl"


namespace jmsf {
namespace structing {
namespace noding {


template< class A_type >
class SinglyLinkedNode {

public:
	A_type &takeObject() throw();
	const A_type &getObject() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	pointing::Pointer< SinglyLinkedNode > &takeNextNode() throw();
	const pointing::ConstantPointer< SinglyLinkedNode > &getNextNode() const throw();

	void setNextNode( const pointing::Pointer< SinglyLinkedNode > &nextNode ) throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~SinglyLinkedNode() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	SinglyLinkedNode() throw();
	SinglyLinkedNode( const A_type &object, const pointing::Pointer< SinglyLinkedNode > &nextNode ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	SinglyLinkedNode( const SinglyLinkedNode &other ) throw();
	const SinglyLinkedNode &operator =( const SinglyLinkedNode &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::Pointer< SinglyLinkedNode > _nextNode;
	pointing::ConstantPointer< SinglyLinkedNode > _constantNextNode;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	A_type _object;

};


} // namespace noding
} // namespace structing
} // namespace jmsf
