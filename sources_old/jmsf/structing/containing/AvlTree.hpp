#pragma once


#include "AvlTree.hxx"

#include "jmsf/pointing/Pointer.inl"

#include "jmsf/structing/noding/AvlTreeNode.hxx"
#include "jmsf/typing/Natural.hxx"
#include "jmsf/typing/ShortestNatural.hxx"
#include "jmsf/typing/Integer.hxx"


namespace jmsf {
namespace structing {
namespace containing {


template< class A_type >
class AvlTree {

public:
	void insertEntry( typing::Natural aKey, const A_type &object ) throw();
	A_type findEntry( typing::Natural aKey ) throw();
	void removeEntry( typing::Natural aKey ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~AvlTree() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	AvlTree() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	AvlTree( const AvlTree &other ) throw();
	const AvlTree &operator =( const AvlTree &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::Pointer< AvlTreeNode< A_type > > insert( typing::Natural aKey, const A_type &object ) throw();
	pointing::Pointer< AvlTreeNode< A_type > > search( typing::Natural aKey ) throw();
	pointing::Pointer< AvlTreeNode< A_type > > remove( typing::Natural aKey ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	typing::ShortestNatural getHeight( pointing::Pointer< AvlTreeNode< A_type > > nodePointer ) throw();
	typing::Integer getBalanceFactor( pointing::Pointer< AvlTreeNode< A_type > > nodePointer ) throw();
	void fixHeight( pointing::Pointer< AvlTreeNode< A_type > > nodePointer ) throw();
	pointing::Pointer< AvlTreeNode< A_type > > rotateRight( pointing::Pointer< AvlTreeNode< A_type > > nodePointer ) throw();
	pointing::Pointer< AvlTreeNode< A_type > > rotateLeft( pointing::Pointer< AvlTreeNode< A_type > > nodePointer ) throw();
	pointing::Pointer< AvlTreeNode< A_type > > balance( pointing::Pointer< AvlTreeNode< A_type > > nodePointer ) throw();

	pointing::Pointer< AvlTreeNode< A_type > > findMinimal( pointing::Pointer< AvlTreeNode< A_type > > nodePointer ) throw();
	pointing::Pointer< AvlTreeNode< A_type > > removeMinimal( pointing::Pointer< AvlTreeNode< A_type > > nodePointer ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	pointing::Pointer< AvlTreeNode< A_type > > _root;

};


} // namespace containing
} // namespace structing
} // namespace jmsf
