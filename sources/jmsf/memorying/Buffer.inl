#pragma once


#include "Buffer.hpp"

#include "jmsf/validating/Should.h"
#include "jmsf/validating/File_and_line.h"


namespace jmsf {
namespace memorying {


template< class A_type >
Buffer< A_type >::~Buffer() throw() {
	delete[] _buffer;
}

template< class A_type >
Buffer< A_type >::Buffer( const typing::Natural size, const typing::Boolean need_to_clear ) throw() {
	_size = size + typing::Natural::create( 1 );

	if ( create() ) {
		if ( need_to_clear ) {
			clear();
		}
	} else {
		_size = typing::Natural::create( 0 );
	}
}

template< class A_type >
Buffer< A_type >::Buffer( const Buffer< A_type > &other ) throw() {
	_size = other.size();

	if ( create() ) {
		copy( other );
	} else {
		_size = typing::Natural::create( 0 );
	}
}

template< class A_type >
const Buffer< A_type > &Buffer< A_type >::operator =( const Buffer< A_type > &other ) throw() {
	if ( this != &other ) {
		_size = other.size();

		if ( recreate() ) {
			copy( other );
		} else {
			_size = typing::Natural::create( 0 );
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
	if ( size() == typing::Natural::create( 0 ) ) return;
	
	limit( size() - typing::Natural::create( 1 ) );
}

template< class A_type >
void Buffer< A_type >::limit( const natural_size sizeToLimit ) throw() {
	if ( size() == typing::Natural::create( 0 ) ) return;

	// EugeneSh: To Do - Refactor: to exception
	if ( limit >= size() ) return;

	_buffer[ limit ] = static_cast< A_type >( 0 );
}

template< class A_type >
void Buffer< A_type >::clear() throw() {
	if ( size() == typing::Natural::create( 0 ) ) return;

	A_type *pointer = _buffer;
	const A_type zero_value = A_type( 0 );
	//const int size_of_buffer = size;

	for ( typing::Natural i; i < size(); i += typing::Natural::create( 1 ) ) {
		*pointer++ = zero_value;
	}
}

template< class A_type >
bool Buffer< A_type >::create() throw() {
	_buffer = size() ? new A_type[ size() ] : 0;
	return typing::Boolean::create( _buffer != 0 );
}

template< class A_type >
void Buffer< A_type >::copy( const Buffer< A_type > &source_buffer ) throw() {
	const A_type *source = source_buffer._buffer;
	A_type *destination = _buffer;
	
	for ( typing::Natural i; i < size(); i += typing::Natural::create( 1 ) ) {
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
	validating::Should::never_be_null( _buffer, FILE_AND_LINE );
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


} // namespace memorying
} // namespace jmsf
