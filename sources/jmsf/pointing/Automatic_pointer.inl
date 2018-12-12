#pragma once


#include "Automatic_pointer.hpp"

#include "jmsf/validating/Should.h"

#include "jmsf/texting/factory_TextObject.h"

#include "jmsf/validating/File_and_line.h"


namespace jmsf {
namespace pointing {


template< class A_type >
A_type &Automatic_pointer< A_type >::operator *() throw( validating::Exception ) {
	validating::Should::never_be_null( _pointer, FILE_AND_LINE );
	return *_pointer;
}

template< class A_type >
const A_type &Automatic_pointer< A_type >::operator *() const throw( validating::Exception ) {
	validating::Should::never_be_null( _pointer, FILE_AND_LINE );
	return *_pointer;
}

template< class A_type >
A_type *Automatic_pointer< A_type >::operator->() throw( validating::Exception ) {
	validating::Should::never_be_null( _pointer, FILE_AND_LINE );
	return _pointer;
}

template< class A_type >
const A_type *Automatic_pointer< A_type >::operator->() const throw( validating::Exception ) {
	validating::Should::never_be_null( _pointer, FILE_AND_LINE );
	return _pointer;
}

template< class A_type >
A_type *Automatic_pointer< A_type >::get() throw() {
	return _pointer;
}

template< class A_type >
const A_type *Automatic_pointer< A_type >::get() const throw() {
	return _pointer;
}

template< class A_type >
A_type *Automatic_pointer< A_type >::release() const throw() {
	A_type *currentPointer = _pointer;
	_pointer = nullptr;
	return currentPointer;
}

template< class A_type >
void Automatic_pointer< A_type >::reset( A_type *pointer = nullptr ) throw() {
	if ( _pointer != pointer ) {
		delete _pointer;
	}

	_pointer = pointer;
}

template< class A_type >
void Automatic_pointer< A_type >::set( A_type *pointer = nullptr ) throw( validating::Exception ) {
	validating::Should::always_be_null( _pointer, FILE_AND_LINE );
	_pointer = pointer;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
void Automatic_pointer< A_type >::initialize() throw() {
	_first = 0;
	_second = 0;
	_third = 0xABCDEFAB;
	_fifth = 0;
	_sixth = 0;
}

template< class A_type >
bool Automatic_pointer< A_type >::is_initialized() const throw() {
	return 	_first == 0 && _second == 0 && _third == 0xABCDEFAB && _fifth == 0 && _sixth == 0;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Automatic_pointer< A_type >::~Automatic_pointer() throw() {
	if ( _pointer != nullptr ) {
		delete _pointer;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Automatic_pointer< A_type >::Automatic_pointer() throw() {
	if ( is_initialized() ) {
		validating::Should::_never_reach_here( "Automatic_pointer< A_type >::default_constructor - second initialization", FILE_AND_LINE );
	}

	initialize();

	_pointer = nullptr;
}

template< class A_type >
Automatic_pointer< A_type >::Automatic_pointer( A_type *pointer ) throw() {
	if ( is_initialized() ) {
		validating::Should::_never_reach_here( "Automatic_pointer< A_type >::constructor - second initialization", FILE_AND_LINE );
	}

	initialize();

	_pointer = pointer;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Automatic_pointer< A_type >::Automatic_pointer( const Automatic_pointer< A_type > &other ) throw() {
	_pointer = other.release();
}

template< class A_type >
Automatic_pointer< A_type > &Automatic_pointer< A_type >::operator =( const Automatic_pointer< A_type > &other ) throw() {
	reset( other.release() );
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace pointing
} // namespace jmsf
