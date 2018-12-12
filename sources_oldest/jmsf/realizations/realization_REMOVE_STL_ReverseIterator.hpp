#pragma once

#include "../Iterator.hpp"
#include "../mixins/mixin_Object.h"

#include "../Boolean.h"
#include "../Should.h"

#include "realization_REMOVE_STL_Array.hxx"
#include "realization_REMOVE_STL_List.hxx"

namespace jmsf {
namespace realizations {

template< class A_type, class A_container >
class realization_REMOVE_STL_ReverseIterator :
	public Iterator< A_type >,
	public mixins::mixin_Object
{

public:
	// virtuals
	void rewind() throw();
	void advance() throw( Exception );
	void behind() throw( Exception );
	void erase() throw();
	
	const Boolean isNotDone() const throw();
	const Boolean isDone() const throw();

	const A_type &getContainie() const throw( Exception );
	A_type &takeContainie() throw( Exception );

	A_type withdrawContainie() throw( Exception );

	void insert( const A_type &object ) throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_REMOVE_STL_ReverseIterator() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	friend realization_REMOVE_STL_Array< A_type >;
	friend realization_REMOVE_STL_List< A_type >;
	realization_REMOVE_STL_ReverseIterator( A_container &container ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Iterator< A_type > > createClone() const throw();

private:
	realization_REMOVE_STL_ReverseIterator( const realization_REMOVE_STL_ReverseIterator &other ) throw();
	const realization_REMOVE_STL_ReverseIterator &operator =( const realization_REMOVE_STL_ReverseIterator &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typename A_container::reverse_iterator _reverseIterator;
	A_container *_container;
	Boolean _skipNextAdvance;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace realizations
} // namespace jmsf


#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace realizations {

template< class A_type, class A_container >
void realization_REMOVE_STL_ReverseIterator< A_type, A_container >::rewind() throw() {
	_reverseIterator = _container->rbegin();
	_skipNextAdvance = False;
}

template< class A_type, class A_container >
void realization_REMOVE_STL_ReverseIterator< A_type, A_container >::advance() throw( Exception ) {
	if ( _skipNextAdvance ) {
		_skipNextAdvance = false;
		return;
	}

	Should::alwaysBe( isNotDone() );
	++_reverseIterator;
}

template< class A_type, class A_container >
void realization_REMOVE_STL_ReverseIterator< A_type, A_container >::behind() throw( Exception ) {
	if ( _skipNextAdvance ) {
		_skipNextAdvance = false;
		return;
	}

	Should::alwaysBe( isNotDone() );
	--_reverseIterator;
}

template< class A_type, class A_container >
void realization_REMOVE_STL_ReverseIterator< A_type, A_container >::erase() throw() {
	A_container::iterator forwardIterator = _container->erase( ( ++_reverseIterator ).base() );
	_reverseIterator = A_container::reverse_iterator( forwardIterator );
	_skipNextAdvance = true;
}

template< class A_type, class A_container >
const Boolean realization_REMOVE_STL_ReverseIterator< A_type, A_container >::isNotDone() const throw() {
	return _reverseIterator != _container->rend();
}

template< class A_type, class A_container >
const Boolean realization_REMOVE_STL_ReverseIterator< A_type, A_container >::isDone() const throw() {
	return _reverseIterator == _container->rend();
}

template< class A_type, class A_container >
const A_type &realization_REMOVE_STL_ReverseIterator< A_type, A_container >::getContainie() const throw( Exception ) {
	Should::alwaysBe( isNotDone() );
	return *_reverseIterator;
}

template< class A_type, class A_container >
A_type &realization_REMOVE_STL_ReverseIterator< A_type, A_container >::takeContainie() throw( Exception ) {
	Should::alwaysBe( isNotDone() );
	return *_reverseIterator;
}

template< class A_type, class A_container >
A_type realization_REMOVE_STL_ReverseIterator< A_type, A_container >::withdrawContainie() throw( Exception ) {
	Should::alwaysBe( isNotDone() );
	A_type containie = *_reverseIterator;
	erase();
	return containie;
}

template< class A_type, class A_container >
void realization_REMOVE_STL_ReverseIterator< A_type, A_container >::insert( const A_type &object ) throw() {
	A_container::iterator forwardIterator = isDone() ? _container->end() : ( ++_reverseIterator ).base();
	forwardIterator = _container->insert( forwardIterator, object );
	_reverseIterator = A_container::reverse_iterator( forwardIterator );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type, class A_container >
realization_REMOVE_STL_ReverseIterator< A_type, A_container >::~realization_REMOVE_STL_ReverseIterator() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type, class A_container >
realization_REMOVE_STL_ReverseIterator< A_type, A_container >::realization_REMOVE_STL_ReverseIterator( A_container &container ) throw()
	:
		_reverseIterator( container.rbegin() )
{
	_container = &container;
	_skipNextAdvance = False;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type, class A_container >
Proxy< Iterator< A_type > > realization_REMOVE_STL_ReverseIterator< A_type, A_container >::createClone() const throw() {
	realization_REMOVE_STL_ReverseIterator< A_type, A_container > *iterator = new realization_REMOVE_STL_ReverseIterator< A_type, A_container >( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( iterator, MACROS_FILE_AND_LINE ) );
	return Proxy< Iterator< A_type > >::createUnique( iterator );
}

template< class A_type, class A_container >
realization_REMOVE_STL_ReverseIterator< A_type, A_container >::realization_REMOVE_STL_ReverseIterator( const realization_REMOVE_STL_ReverseIterator< A_type, A_container > &other ) throw()
	:
		_reverseIterator( other._reverseIterator )
{
	_container = other._container;
	_skipNextAdvance = other._skipNextAdvance;
}

template< class A_type, class A_container >
const realization_REMOVE_STL_ReverseIterator< A_type, A_container > &realization_REMOVE_STL_ReverseIterator< A_type, A_container >::operator =( const realization_REMOVE_STL_ReverseIterator< A_type, A_container > &other ) throw() {
	if ( this == &other ) return *this;

	_reverseIterator = other._reverseIterator;
	_container = other._container;
	_skipNextAdvance = other._skipNextAdvance;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
