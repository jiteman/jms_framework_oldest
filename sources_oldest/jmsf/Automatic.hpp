#pragma once

#include "Should.h"
#include "warning_suppressor.h"

namespace jmsf {

template< class A_type >
class Automatic {

	mutable A_type *_pointer;
	int _first;
	int _second;
	int _third;
	int _fifth;
	int _sixth;

public:
	explicit Automatic() throw();
	explicit Automatic( A_type *pointer) throw();
	Automatic( const Automatic< A_type > &other ) throw();
	Automatic< A_type > &operator =( const Automatic< A_type > &other ) throw();
	~Automatic();

	A_type &operator *() const throw( Exception );
	A_type *operator->() const throw( Exception );
	A_type *get() throw();
	const A_type *get() const throw();
	A_type *release() const throw();
	void reset( A_type *pointer = nullptr ) throw();
	void set( A_type *pointer = nullptr ) throw( Exception );

	void initialize() throw();
	bool isInitialized() const throw();

};

} // namespace jmsf


// #include "jmsf/debugging/MemoryUsingLogging.h"

namespace jmsf {

template< class A_type >
Automatic< A_type >::Automatic() throw() {
	if ( isInitialized() ) {
		Should::_neverReachHere( "Automatic< A_type >::default_constructor - second initialization" );
	}

	initialize();

	_pointer = nullptr;
}

template< class A_type >
Automatic< A_type >::Automatic( A_type *pointer ) throw() {
	if ( isInitialized() ) {
		Should::_neverReachHere( "Automatic< A_type >::constructor - second initialization" );
	}

	initialize();

	_pointer = pointer;
}

template< class A_type >
Automatic< A_type >::Automatic( const Automatic< A_type > &other ) throw() {
	_pointer = other.release();
}

template< class A_type >
Automatic< A_type > &Automatic< A_type >::operator =( const Automatic< A_type > &other ) throw() {
	reset( other.release() );
	return *this;
}

template< class A_type >
Automatic< A_type >::~Automatic() {
	if ( _pointer != nullptr ) {
//		debugging::static_ObjectDeletionLogger::registerDeletion( debugging::createMemoryLoggerInformationForObject( _pointer, MACROS_FILE_AND_LINE ) );
		delete _pointer;
	}
}

template< class A_type >
A_type &Automatic< A_type >::operator *() const throw( Exception ) {
	Should::neverBeNull( _pointer );
	return *_pointer;
}

template< class A_type >
A_type *Automatic< A_type >::operator->() const throw( Exception ) {
	Should::neverBeNull( _pointer );
	return _pointer;
}

template< class A_type >
A_type *Automatic< A_type >::get() throw() {
	return _pointer;
}

template< class A_type >
const A_type *Automatic< A_type >::get() const throw() {
	return _pointer;
}

template< class A_type >
A_type *Automatic< A_type >::release() const throw() {
	A_type *currentPointer = _pointer;
	_pointer = nullptr;
	return currentPointer;
}

template< class A_type >
void Automatic< A_type >::reset( A_type *pointer = nullptr ) throw() {
	if ( _pointer != pointer ) {
//		debugging::static_ObjectDeletionLogger::registerDeletion( debugging::createMemoryLoggerInformationForObject( _pointer,  MACROS_FILE_AND_LINE ) );
		delete _pointer;
	}

	_pointer = pointer;
}

template< class A_type >
void Automatic< A_type >::set( A_type *pointer = nullptr ) throw( Exception ) {
	Should::alwaysBeNull( _pointer );
	_pointer = pointer;
}

template< class A_type >
void Automatic< A_type >::initialize() throw() {
	_first = 0;
	_second = 0;
	_third = 0xABCDEFAB;
	_fifth = 0;
	_sixth = 0;
}

template< class A_type >
bool Automatic< A_type >::isInitialized() const throw() {
	return 	_first == 0 && _second == 0 && _third == 0xABCDEFAB && _fifth == 0 && _sixth == 0;
}


} // namespace jmsf

