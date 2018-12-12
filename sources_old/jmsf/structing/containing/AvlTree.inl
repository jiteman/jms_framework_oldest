#pragma once


#include "AvlTree.hpp"

#include "jmsf/structing/noding/AvlTreeNode.inl"
#include "jmsf/typing/Natural.inl"
#include "jmsf/typing/ShortestNatural.inl"
#include "jmsf/typing/Integer.inl"


namespace jmsf {
namespace structing {
namespace containing {


template< class A_type >
void AvlTree< A_type >::insertEntry( const typing::Natural aKey, const A_type &object ) throw() {
	_root = insert( aKey, object );
}

template< class A_type >
A_type AvlTree< A_type >::findEntry( const typing::Natural aKey ) throw() {
	pointing::Pointer< AvlTreeNode< A_type > > found = search( aKey );
	return found.isEmpty() ? A_type() : *found;
}

template< class A_type >
void AvlTree< A_type >::removeEntry( const typing::Natural aKey ) throw() {
	_root = remove( aKey );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
AvlTree< A_type >::~AvlTree() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
AvlTree< A_type >::AvlTree() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
AvlTree< A_type >::AvlTree( const AvlTree< A_type > & ) throw() { // other
}

template< class A_type >
const AvlTree< A_type > &AvlTree< A_type >::operator =( const AvlTree< A_type > &other ) throw() {
	if ( &other != this ) {
		// copy
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
template< class A_type >
pointing::Pointer< AvlTreeNode< A_type > > AvlTree< A_type >::insert( const typing::Natural aKey, const A_type &object ) throw() {
    if ( nodePointer.isEmpty() ) {
		return pointing::Pointer< AvlTreeNode< A_type > >::createShared( new AvlTreeNode< A_type >( aKey ) );
	}

    if ( key < nodePointer->getKey() ) {
        nodePointer->setLeft( insert( nodePointer->getLeft(), aKey ) );
	} else {
        nodePointer->setRight( insert( nodePointer->getRight(), aKey ) );
	}

    return balance( nodePointer );
}

template< class A_type >
pointing::Pointer< AvlTreeNode< A_type > > AvlTree< A_type >::search( const typing::Natural aKey ) throw() {
    if ( nodePointer.isEmpty() ) {
		return pointing::Pointer< AvlTreeNode< A_type > >();
	}

	if ( key == nodePointer->getKey() ) {
		return nodePointer;
	} else if ( key < nodePointer->getKey() ) {
		return search( nodePointer->getLeft(), aKey );
	} else {
		return search( nodePointer->getRight(), aKey );
	}
}

template< class A_type >
pointing::Pointer< AvlTreeNode< A_type > > AvlTree< A_type >::remove( const typing::Natural aKey ) throw() {
    if ( nodePointer.isEmpty() ) {
		return pointing::Pointer< AvlTreeNode< A_type > >();
	}

    if ( aKey < nodePointer->getKey() ) {
        nodePointer->setLeft( remove( nodePointer->getLeft(), aKey ) );
	} else if ( aKey > nodePointer->getKey() ) {
        nodePointer->setRight( remove( nodePointer->getRight(), aKey ) );
	} else { //  key == nodePointer->_key 
        pointing::Pointer< AvlTreeNode< A_type > > leftNode = nodePointer->getLeft();
        pointing::Pointer< AvlTreeNode< A_type > > rightNode = nodePointer->getRight();
        nodePointer.empty();

        if ( !rightNode ) {
			return leftNode;
		}

        pointing::Pointer< AvlTreeNode< A_type > > minimal = findMinimal( rightNode );
        minimal->setRight( removeMinimal( rightNode ) );
        minimal->setLeft( leftNode );
        return balance( minimal );
    }

    return balance( nodePointer );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
typing::ShortestNatural AvlTree< A_type >::getHeight( pointing::Pointer< AvlTreeNode< A_type > > nodePointer ) throw() {
	return nodePointer.isEmpty() ? typing::ShortestNaturalZero : nodePointer->getHeight();
}

template< class A_type >
typing::Integer AvlTree< A_type >::getBalanceFactor( pointing::Pointer< AvlTreeNode< A_type > > nodePointer ) throw() {
	return getHeight( nodePointer->getRight() ) - getHeight( nodePointer->getLeft() );
}

template< class A_type >
void AvlTree< A_type >::fixHeight( pointing::Pointer< AvlTreeNode< A_type > > nodePointer ) throw() {
    const unsigned char leftHeight = getHeight( nodePointer->getLeft() );
    const unsigned char rightHeight = getHeight( nodePointer->getRight() );
    nodePointer->setHeight( ( leftHeight > rightHeight ? leftHeight : rightHeight ) + typing::ShortestNaturalOne );
}

template< class A_type >
pointing::Pointer< AvlTreeNode< A_type > > AvlTree< A_type >::rotateRight( pointing::Pointer< AvlTreeNode< A_type > > nodePointer ) throw() {
    pointing::Pointer< AvlTreeNode< A_type > > leftNodePointer = nodePointer->getLeft();
    nodePointer->setLeft( leftNodePointer->getRight() );
    leftNodePointer->setRight( nodePointer );
    fixHeight( nodePointer );
    fixHeight( leftNodePointer );
    return leftNodePointer;
}

template< class A_type >
pointing::Pointer< AvlTreeNode< A_type > > AvlTree< A_type >::rotateLeft( pointing::Pointer< AvlTreeNode< A_type > > nodePointer ) throw() {
    node *rightNodePointer = nodePointer->getRight();
    nodePointer->setRight( rightNodePointer->getLeft() );
    rightNodePointer->setLeft( nodePointer );
    fixHeight( nodePointer );
    fixHeight( rightNodePointer );
    return rightNodePointer;
}

template< class A_type >
pointing::Pointer< AvlTreeNode< A_type > > AvlTree< A_type >::balance( pointing::Pointer< AvlTreeNode< A_type > > nodePointer ) throw() {
    fixHeight( nodePointer );

    if ( getBalanceFactor( nodePointer ) == 2 ) {
        if ( getBalanceFactor( nodePointer->getRight() ) < 0 ) {
            nodePointer->setRight( rotateRight( nodePointer->getRight() ) );
		}

        return rotateLeft( nodePointer );
    }

    if ( getBalanceFactor( nodePointer ) == -2 ) {
        if ( getBalanceFactor( nodePointer->getLeft() ) > 0  ) {
            nodePointer->setLeft( rotateLeft( nodePointer->getLeft() ) );
		}

        return rotateRight( nodePointer );
    }

    return nodePointer;
}

template< class A_type >
pointing::Pointer< AvlTreeNode< A_type > > AvlTree< A_type >::findMinimal( pointing::Pointer< AvlTreeNode< A_type > > nodePointer ) throw() {
	return nodePointer->getLeft().isEmpty() ? nodePointer :  findMinimal( nodePointer->getLeft() );
}

template< class A_type >
pointing::Pointer< AvlTreeNode< A_type > > AvlTree< A_type >::removeMinimal( pointing::Pointer< AvlTreeNode< A_type > > nodePointer ) throw() {
    if ( nodePointer->getLeft() == nullptr ) {
        return nodePointer->getRight();
	}

    nodePointer->setLeft( removeMinimal( nodePointer->getLeft() ) );
    return balance( nodePointer );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace containing
} // namespace structing
} // namespace jmsf
