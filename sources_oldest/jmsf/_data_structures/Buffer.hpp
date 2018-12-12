#pragma once

#include "jmsf/types.h"
#include "jmsf/Boolean.hxx"

namespace jmsf {
namespace data_structures {

template< class A_type >
class Buffer {

public:
	static const Boolean CLEAR;
	static const natural_size EMPTY = 0;

public:
	~Buffer() throw();
	
	Buffer( natural_size size, Boolean need_to_clear = False ) throw();
	Buffer( const Buffer &other ) throw();
	const Buffer &operator =( const Buffer &other ) throw();

	operator A_type *() throw();

	A_type *get() throw();
	const A_type *get() const throw();

	natural_size size() const throw();
	void limit() throw();
	void limit( natural_size sizeToLimit ) throw();
	void clear() throw();

private:
	bool create() throw();
	bool recreate() throw();
	void copy( const Buffer &source_buffer ) throw();

private:
	A_type *_buffer;
	natural_size _size;

};

} // namespace data_stuctures
} // namespace jmsf


#include "jmsf/Boolean.h"
#include "jmsf/Should.h"

namespace jmsf {
namespace data_structures {

// static
template< class A_type >
const Boolean Buffer< A_type >::CLEAR = True;


template< class A_type >
Buffer< A_type >::~Buffer() throw() {
	delete[] _buffer;
}

template< class A_type >
Buffer< A_type >::Buffer( const natural_size size, const Boolean need_to_clear ) throw() {
	_size = size + 1;

	if ( create() ) {
		if ( need_to_clear ) {
			clear();
		}
	} else {
		_size = 0;
	}
}

template< class A_type >
Buffer< A_type >::Buffer( const Buffer< A_type > &other ) throw() {
	_size = other.size();

	if ( create() ) {
		copy( other );
	} else {
		_size = 0;
	}
}

template< class A_type >
const Buffer< A_type > &Buffer< A_type >::operator =( const Buffer< A_type > &other ) throw() {
	if ( this != &other ) {
		_size = other.size();

		if ( recreate() ) {
			copy( other );
		} else {
			_size = 0;
		}
	}

	return *this;
}

template< class A_type >
natural_size Buffer< A_type >::size() const throw() {
	return _size;
}

template< class A_type >
void Buffer< A_type >::limit() throw() {
	if ( size() == 0 ) return;
	
	limit( size() - 1 );
}

template< class A_type >
void Buffer< A_type >::limit( const natural_size sizeToLimit ) throw() {
	if ( size() == 0 ) return;

	// EugeneSh: To Do - Refactor: to exception
	if ( limit >= size() ) return;

	_buffer[ limit ] = static_cast< A_type >( 0 );
}

template< class A_type >
void Buffer< A_type >::clear() throw() {
	if ( size() == 0 ) return;

	A_type *pointer = _buffer;
	const A_type zero_value = A_type( 0 );
	//const int size_of_buffer = size;

	for ( size_t i = 0; i < size(); i++ ) {
		*pointer++ = zero_value;
	}
}

template< class A_type >
bool Buffer< A_type >::create() throw() {
	_buffer = size() ? new A_type[ size() ] : 0;
	return _buffer != 0 ? true : false;
}

template< class A_type >
void Buffer< A_type >::copy( const Buffer< A_type > &source_buffer ) throw() {
	const A_type *source = source_buffer._buffer;
	A_type *destination = _buffer;
	
	for ( size_t i = 0; i < size(); i++ ) {
		*( destination++ ) = *( source++ );
	}
}

template< class A_type >
bool Buffer< A_type >::recreate() throw() {
	delete[] _buffer;
	return create();
}

template< class A_type >
Buffer< A_type >::operator A_type *() throw () {
	Should::neverBeNull( _buffer );
	return _buffer;
}

template< class A_type >
A_type *Buffer< A_type >::get() throw() {
	return _buffer;
}

template< class A_type >
const A_type *Buffer< A_type >::get() const throw() {
	return _buffer;
}


typedef Buffer< char_type > CharTypeBuffer;
typedef Buffer< Boolean > BooleanBuffer;

} // namespace data_structures
} // namespace jmsf
