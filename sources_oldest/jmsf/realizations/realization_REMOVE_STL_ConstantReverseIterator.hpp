#pragma once

#include "../ConstantIterator.hpp"
#include "../mixins/mixin_Object.h"

#include "../Boolean.h"
#include "../Should.h"

#include "realization_REMOVE_STL_Array.hxx"
#include "realization_REMOVE_STL_List.hxx"

namespace jmsf {
namespace realizations {

template< class A_type, class A_container >
class realization_REMOVE_STL_ConstantReverseIterator :
	public ConstantIterator< A_type >,
	public mixins::mixin_Object
{

public:
	// virtuals
	void rewind() throw();
	void advance() throw( Exception );
	void behind() throw( Exception );
	const Boolean isNotDone() const throw();
	const Boolean isDone() const throw();
	const A_type &getContainie() const throw( Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_REMOVE_STL_ConstantReverseIterator() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	friend realization_REMOVE_STL_Array< A_type >;
	friend realization_REMOVE_STL_List< A_type >;
	realization_REMOVE_STL_ConstantReverseIterator( const A_container &container ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< ConstantIterator< A_type > > createClone() const throw();

private:
	realization_REMOVE_STL_ConstantReverseIterator( const realization_REMOVE_STL_ConstantReverseIterator &other ) throw();
	const realization_REMOVE_STL_ConstantReverseIterator &operator =( const realization_REMOVE_STL_ConstantReverseIterator &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typename A_container::const_reverse_iterator _reverseIterator;
	const A_container *_container;
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
void realization_REMOVE_STL_ConstantReverseIterator< A_type, A_container >::rewind() throw() {
	_reverseIterator = _container->rbegin();
	_skipNextAdvance = False;
}

template< class A_type, class A_container >
void realization_REMOVE_STL_ConstantReverseIterator< A_type, A_container >::advance() throw( Exception ) {
	if ( _skipNextAdvance ) {
		_skipNextAdvance = false;
		return;
	}

	Should::alwaysBe( isNotDone() );
	++_reverseIterator;
}

template< class A_type, class A_container >
void realization_REMOVE_STL_ConstantReverseIterator< A_type, A_container >::behind() throw( Exception ) {
	if ( _skipNextAdvance ) {
		_skipNextAdvance = false;
		return;
	}

	Should::alwaysBe( isNotDone() );
	--_reverseIterator;
}

template< class A_type, class A_container >
const Boolean realization_REMOVE_STL_ConstantReverseIterator< A_type, A_container >::isNotDone() const throw() {
	return _reverseIterator != _container->rend();
}

template< class A_type, class A_container >
const Boolean realization_REMOVE_STL_ConstantReverseIterator< A_type, A_container >::isDone() const throw() {
	return _reverseIterator == _container->rend();
}

template< class A_type, class A_container >
const A_type &realization_REMOVE_STL_ConstantReverseIterator< A_type, A_container >::getContainie() const throw( Exception ) {
	Should::alwaysBe( isNotDone() );
	return *_reverseIterator;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type, class A_container >
realization_REMOVE_STL_ConstantReverseIterator< A_type, A_container >::~realization_REMOVE_STL_ConstantReverseIterator() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type, class A_container >
realization_REMOVE_STL_ConstantReverseIterator< A_type, A_container >::realization_REMOVE_STL_ConstantReverseIterator( const A_container &container ) throw()
	:
		_reverseIterator( container.rbegin() )
{
	_container = &container;
	_skipNextAdvance = False;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type, class A_container >
Proxy< ConstantIterator< A_type > > realization_REMOVE_STL_ConstantReverseIterator< A_type, A_container >::createClone() const throw() {
	realization_REMOVE_STL_ConstantReverseIterator< A_type, A_container > *constantIterator = new realization_REMOVE_STL_ConstantReverseIterator< A_type, A_container >( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( constantIterator, MACROS_FILE_AND_LINE ) );
	return Proxy< ConstantIterator< A_type > >::createUnique( constantIterator );
}

template< class A_type, class A_container >
realization_REMOVE_STL_ConstantReverseIterator< A_type, A_container >::realization_REMOVE_STL_ConstantReverseIterator( const realization_REMOVE_STL_ConstantReverseIterator< A_type, A_container > &other ) throw()
	:
		_reverseIterator( other._reverseIterator )
{
	_container = other._container;
	_skipNextAdvance = other._skipNextAdvance;
}

template< class A_type, class A_container >
const realization_REMOVE_STL_ConstantReverseIterator< A_type, A_container > &realization_REMOVE_STL_ConstantReverseIterator< A_type, A_container >::operator =( const realization_REMOVE_STL_ConstantReverseIterator< A_type, A_container > &other ) throw() {
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
