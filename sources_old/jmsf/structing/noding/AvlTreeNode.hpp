#pragma once


#include "AvlTreeNode.hxx"


#include "jmsf/pointing/Pointer.inl"
#include "jmsf/pointing/ConstantPointer.inl"


namespace jmsf {
namespace structing {
namespace noding {


template< class A_type >
class AvlTreeNode {

public:
	A_type &takeObject() throw();
	const A_type &getObject() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	pointing::Pointer< AvlTreeNode > &takeLeftChild() throw();
	pointing::ConstantPointer< AvlTreeNode > &getLeftChild() const throw();
	pointing::Pointer< AvlTreeNode > &takeRightChild() throw();
	pointing::ConstantPointer< AvlTreeNode > &getRightChild() const throw();

	void setLeftChild( const pointing::Pointer< AvlTreeNode > &leftChild ) throw();
	void setRightChild( const pointing::Pointer< AvlTreeNode > &rightChild ) throw();

	typing::Natural getKey() const throw();
	typing::ShortestNatural getHeight() const throw();

	void setHeight( typing::ShortestNatural height ) throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~AvlTreeNode() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	AvlTreeNode() throw();
	AvlTreeNode( types::Natural key, const A_type &object ) throw();
	AvlTreeNode( const pointing::Pointer< AvlTreeNode > &leftChild, const pointing::Pointer< AvlTreeNode > &rightChild, const A_type &object ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	AvlTreeNode( const AvlTreeNode &other ) throw();
	const AvlTreeNode &operator =( const AvlTreeNode &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	types::Natural _key;
	types::ShortestNatural _height;
	pointing::Pointer< AvlTreeNode > _leftChild;
	pointing::ConstantPointer< AvlTreeNode > _constantLeftChild;
	pointing::Pointer< AvlTreeNode > _rightChild;
	pointing::ConstantPointer< AvlTreeNode > _constantRightChild;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	A_type _object;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace noding
} // namespace structing
} // namespace jmsf
