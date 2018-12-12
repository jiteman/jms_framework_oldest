class node {

public:
    node( const int key ) {
		_key = key;
		_left = nullptr;
		_right = nullptr;
		_height = 1;
	}

	unsigned char getHeight() const {
		return _height;
	}

	void setHeight( unsigned char height ) {
		_height = height;
	}

	node *getLeft() {
		return _left;
	}

	void setLeft( node *left ) {
		_left = left;
	}

	node *getRight() {
		return _right;
	}

	void setRight( node *right ) {
		_right = right;
	}

	int getKey() const {
		return _key;
	}

private:
    int _key;
    unsigned char _height;
    node *_left;
    node *_right;

};


unsigned char get_node_height( node *nodePointer ) {
    return nodePointer != nullptr ? nodePointer->getHeight() : unsigned char( 0 );
}

int balance_factor( node *nodePointer ) {
    return get_node_height( nodePointer->getRight() ) - get_node_height( nodePointer->getLeft() );
}

void fix_height( node *nodePointer ) {
    const unsigned char leftHeight = get_node_height( nodePointer->getLeft() );
    const unsigned char rightHeight = get_node_height( nodePointer->getRight() );
    nodePointer->setHeight( static_cast< unsigned char >( ( leftHeight > rightHeight ? leftHeight : rightHeight ) + unsigned char( 1 ) ) );
}

node *rotate_right( node *nodePointer ) {
    node *otherNodePointer = nodePointer->getLeft();
    nodePointer->setLeft( otherNodePointer->getRight() );
    otherNodePointer->setRight( nodePointer );
    fix_height( nodePointer );
    fix_height( otherNodePointer );
    return otherNodePointer;
}

node *rotate_left( node *nodePointer ) {
    node *otherNodePointer = nodePointer->getRight();
    nodePointer->setRight( otherNodePointer->getLeft() );
    otherNodePointer->setLeft( nodePointer );
    fix_height( nodePointer );
    fix_height( otherNodePointer );
    return otherNodePointer;
}

node *balance( node *nodePointer ) {
    fix_height( nodePointer );

    if ( balance_factor( nodePointer ) == 2 ) {
        if ( balance_factor( nodePointer->getRight() ) < 0 ) {
            nodePointer->setRight( rotate_right( nodePointer->getRight() ) );
		}

        return rotate_left( nodePointer );
    }

    if ( balance_factor( nodePointer ) == -2 ) {
        if ( balance_factor( nodePointer->getLeft() ) > 0  ) {
            nodePointer->setLeft( rotate_left( nodePointer->getLeft() ) );
		}

        return rotate_right( nodePointer );
    }

    return nodePointer;
}

node *search( node *nodePointer, const int key ) {
    if ( nodePointer == nullptr ) {
		return nullptr;
	}

	if ( key == nodePointer->getKey() ) {
		return nodePointer;
	} else if ( key < nodePointer->getKey() ) {
		return search( nodePointer->getLeft(), key );
	} else {
		return search( nodePointer->getRight(), key );
	}
}

node *insert( node *nodePointer, const int key ) {
    if ( nodePointer == nullptr ) {
		return new node( key );
	}

    if ( key < nodePointer->getKey() ) {
        nodePointer->setLeft( insert( nodePointer->getLeft(), key ) );
	} else {
        nodePointer->setRight( insert( nodePointer->getRight(), key ) );
	}

    return balance( nodePointer );
}

node *find_min( node *nodePointer ) {
    return nodePointer->getLeft() != nullptr ? find_min( nodePointer->getLeft() ) : nodePointer;
}

node *remove_min( node *nodePointer ) {
    if ( nodePointer->getLeft() == nullptr ) {
        return nodePointer->getRight();
	}

    nodePointer->setLeft( remove_min( nodePointer->getLeft() ) );
    return balance( nodePointer );
}

node *remove( node *nodePointer, const int key ) {
    if ( nodePointer == nullptr ) return nullptr;

    if ( key < nodePointer->getKey() ) {
        nodePointer->setLeft( remove( nodePointer->getLeft(), key ) );
	} else if ( key > nodePointer->getKey() ) {
        nodePointer->setRight( remove( nodePointer->getRight(), key ) );
	} else { //  key == nodePointer->_key 
        node *leftNode = nodePointer->getLeft();
        node *rightNode = nodePointer->getRight();
        delete nodePointer;

        if ( !rightNode ) {
			return leftNode;
		}

        node *min = find_min( rightNode );
        min->setRight( remove_min( rightNode ) );
        min->setLeft( leftNode );
        return balance( min );
    }

    return balance( nodePointer );
}
