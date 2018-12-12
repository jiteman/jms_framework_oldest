#pragma once


#include "../Iterator.hpp"
#include "jmsf/mixins/mixin_Object.h"

#include "realization_ContainerArray.hxx"


namespace jmsf {
namespace containers {
namespace realizations {

template< class A_type >
class realization_ArrayIterator :
	public Iterator< A_type >,
	public ::jmsf::mixins::mixin_Object
{

public: // getters
	// virtuals Iterator
	const Boolean isNotDone() const throw();
	const Boolean isDone() const throw();

	const A_type &getContainie() const throw( Exception );
	A_type &takeContainie() throw( Exception );

	void rewindToBegin() throw();
	void rewindToEnd() throw();
	void moveOneStepToBegin() throw( Exception );
	void moveOneStepToEnd() throw( Exception );
	//~virtuals Iterator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // modifiers
	// virtuals Iterator
	void eraseContainie() throw( Exception );
	A_type withdrawContainie() throw( Exception );

	void insertAfter( const A_type &placeholder ) throw( Exception );
	void insertBefore( const A_type &placeholder ) throw( Exception );
	//~virtuals Iterator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // service
	// virtuals Iterator
	natural_size getIndexOfContainie() const throw();
	const A_type *getAddressOfContainie() const throw();
	const Proxy< Container< A_type > > &getAddressOfContainer() const throw();
	Boolean isDirectionFromBeginToEnd() const throw();
	//~virtuals Iterator

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ArrayIterator() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_ContainerArray< A_type >;
	realization_ArrayIterator() throw( jmsf::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< Iterator< A_type > > createClone() const throw();

private:
	realization_ArrayIterator( const realization_ArrayIterator &other ) throw();
	const realization_ArrayIterator &operator =( const realization_ArrayIterator &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	natural_size _indexOfContainieInContainer;
	A_type *_addresOfContainieInContainer;
	Proxy< Container< A_type > > _container;
	Boolean _isDirectionFromBeginToEnd;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace realizations
} // namespace containers
} // namespace jmsf


#include "jmsf/factory_TextObject.h"
#include "jmsf/Proxies.hpp"


namespace jmsf {
namespace containers {
namespace realizations {


template< A_type >
const Boolean realization_ArrayIterator< A_type >::isNotDone() const throw() {
	return isDone().not();
}

template< A_type >
const Boolean realization_ArrayIterator< A_type >::isDone() const throw() {
	return _addresOfContainieInContainer == nullptr && _indexOfContainieInContainer == ~0 ? true : false;
}

template< A_type >
const A_type &realization_ArrayIterator< A_type >::getContainie() const throw( Exception ) {
	if ( isDone() ) {
	}

	return *_addresOfContainieInContainer;
}

template< A_type >
A_type &realization_ArrayIterator< A_type >::takeContainie() throw( Exception ) {
	if ( isDone() ) {
	}

	return *_addresOfContainieInContainer;
}

template< A_type >
void realization_ArrayIterator< A_type >::rewindToBegin() throw() {
	*this = _container->createIteratorAtBegin();
}

template< A_type >
void realization_ArrayIterator< A_type >::rewindToEnd() throw() {
	*this = _container->createIteratorAtEnd();
}

template< A_type >
void realization_ArrayIterator< A_type >::moveOneStepToBegin() throw( Exception ) {
	
}

template< A_type >
void realization_ArrayIterator< A_type >::moveOneStepToEnd() throw( Exception ) {
	
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< A_type >
void realization_ArrayIterator< A_type >::eraseContainie() throw( Exception ) {
	if ( isDone() ) {
	}

	*this = _container->eraseContainie( *this );
}

template< A_type >
A_type realization_ArrayIterator< A_type >::withdrawContainie() throw( Exception ) {
	if ( isDone() ) {
	}

	A_type withdrawedObject;
	*this = _container->withdrawContainie( withdrawedObject, *this );
	return withdrawedObject;
}

template< A_type >
void realization_ArrayIterator< A_type >::insertAfter( const A_type &placeholder ) throw( Exception ) {
	if ( isDone() ) {
	}

	*this = _container->insertAfter( *this, placeholder );
}

template< A_type >
void realization_ArrayIterator< A_type >::insertBefore( const A_type &placeholder ) throw( Exception ) {
	if ( isDone() ) {
	}

	*this = _container->insertBefore( *this, placeholder );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< A_type >
natural_size realization_ArrayIterator< A_type >::getIndexOfContainie() const throw() {
	return _indexOfContainieInContainer;
}

template< A_type >
const A_type *realization_ArrayIterator< A_type >::getAddressOfContainie() const throw() {
	return _addresOfContainieInContainer;
}

template< A_type >
const Proxy< Container< A_type > > &realization_ArrayIterator< A_type >::getAddressOfContainer() const throw() {
	return _container;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< A_type >
realization_ArrayIterator< A_type >::~realization_ArrayIterator() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< A_type >
realization_ArrayIterator< A_type >::realization_ArrayIterator() throw( jmsf::Exception )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< A_type >
::jmsf::Proxy< Iterator< A_type > > realization_ArrayIterator< A_type >::createClone() const throw() {
	return ::jmsf::Proxy< Iterator< A_type > >::createUnique( new realization_ArrayIterator< A_type >( *this ) );
}

template< A_type >
realization_ArrayIterator< A_type >::realization_ArrayIterator( const realization_ArrayIterator< A_type > & ) throw() // other
{}

template< A_type >
const realization_ArrayIterator< A_type > &realization_ArrayIterator< A_type >::operator =( const realization_ArrayIterator< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace realizations
} // namespace containers
} // namespace jmsf
