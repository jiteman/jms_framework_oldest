#pragma once

#include "../Container.hpp"
#include "../mixins/mixin_Object.h"
#include "realization_REMOVE_STL_ForwardIterator.hpp"
#include "realization_REMOVE_STL_ReverseIterator.hpp"
#include "realization_REMOVE_STL_ConstantForwardIterator.hpp"
#include "realization_REMOVE_STL_ConstantReverseIterator.hpp"
#include "jmsf/stdal/stdal_stl.h"
#include "realization_factory_Container.hxx"

namespace jmsf {
namespace realizations {

template< class A_type >
class realization_REMOVE_STL_Array :
	public Container< A_type >,
	public mixins::mixin_Object
{

public:
	// virtuals
	void appendFront( const A_type &object ) throw();
	void appendBack( const A_type &object ) throw();	
	void clear() throw();

	const Boolean isEmpty() const throw();
	const Boolean isNotEmpty() const throw();
	natural_size getQuantityOfElements() const throw();

	const A_type &getContainie( natural_size index ) const throw();
	A_type &takeContainie( natural_size index ) throw();
	const A_type &getFirstContainie() const throw();
	A_type &takeFirstContainie() throw();
	const A_type &getLastContainie() const throw();
	A_type &takeLastContainie() throw();

	A_type withdrawContainie( natural_size index ) throw();
	A_type withdrawFirstContainie() throw();
	A_type withdrawLastContainie() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals
	Proxy< Iterator< A_type > > createForwardIterator() throw();
	Proxy< Iterator< A_type > > createReverseIterator() throw();
	Proxy< ConstantIterator< A_type > > createConstantForwardIterator() const throw();
	Proxy< ConstantIterator< A_type > > createConstantReverseIterator() const throw();
	//~virtuals

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_REMOVE_STL_Array() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_Container< A_type >;
	realization_REMOVE_STL_Array() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Container< A_type > > createClone() const throw();

private:
	realization_REMOVE_STL_Array( const realization_REMOVE_STL_Array &other ) throw();
	const realization_REMOVE_STL_Array &operator =( const realization_REMOVE_STL_Array &other ) throw();
	
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	std::vector< A_type > _vector;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace realizations
} // namespace jmsf


#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace realizations {

template< class A_type >
void realization_REMOVE_STL_Array< A_type >::appendFront( const A_type &object ) throw() {
	_vector.insert( _vector.begin(), object );
}

template< class A_type >
void realization_REMOVE_STL_Array< A_type >::appendBack( const A_type &object ) throw() {
	_vector.push_back( object );
}

template< class A_type >
void realization_REMOVE_STL_Array< A_type >::clear() throw() {
	_vector.clear();
}

template< class A_type >
const Boolean realization_REMOVE_STL_Array< A_type >::isEmpty() const throw() {
	return _vector.empty();
}

template< class A_type >
const Boolean realization_REMOVE_STL_Array< A_type >::isNotEmpty() const throw() {
	return !_vector.empty();
}

template< class A_type >
natural_size realization_REMOVE_STL_Array< A_type >::getQuantityOfElements() const throw() {
	return _vector.size();
}

template< class A_type >
const A_type &realization_REMOVE_STL_Array< A_type >::getContainie( const natural_size index ) const throw() {
	return _vector.at( index );
}

template< class A_type >
A_type &realization_REMOVE_STL_Array< A_type >::takeContainie( const natural_size index ) throw() {
	return _vector.at( index );	
}

template< class A_type >
const A_type &realization_REMOVE_STL_Array< A_type >::getFirstContainie() const throw() {
	return _vector.front();
}

template< class A_type >
A_type &realization_REMOVE_STL_Array< A_type >::takeFirstContainie() throw() {
	return _vector.front();
}

template< class A_type >
const A_type &realization_REMOVE_STL_Array< A_type >::getLastContainie() const throw() {
	return _vector.back();
}

template< class A_type >
A_type &realization_REMOVE_STL_Array< A_type >::takeLastContainie() throw() {
	return _vector.back();
}

template< class A_type >
A_type realization_REMOVE_STL_Array< A_type >::withdrawContainie( const natural_size index ) throw() {	
	std::vector< A_type >::iterator containieByIndex = _vector.begin();

	for ( natural_size currentIndex = 0; currentIndex < index; currentIndex += 1 ) {
		++containieByIndex;
	}

	A_type containie = *containieByIndex;
	_vector.erase( containieByIndex );
	return containie;
}

template< class A_type >
A_type realization_REMOVE_STL_Array< A_type >::withdrawFirstContainie() throw() {
	A_type containie = _vector.front();
	_vector.erase( _vector.begin() );
	return containie;
}

template< class A_type >
A_type realization_REMOVE_STL_Array< A_type >::withdrawLastContainie() throw() {
	A_type containie = _vector.back();
	_vector.pop_back();
	return containie;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Proxy< Iterator< A_type > > realization_REMOVE_STL_Array< A_type >::createForwardIterator() throw() {
	realization_REMOVE_STL_ForwardIterator< A_type, std::vector< A_type > > *iterator = new realization_REMOVE_STL_ForwardIterator< A_type, std::vector< A_type > >( _vector );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( iterator, MACROS_FILE_AND_LINE ) );
	return Proxy< Iterator< A_type > >::createUnique( iterator );
}

template< class A_type >
Proxy< Iterator< A_type > > realization_REMOVE_STL_Array< A_type >::createReverseIterator() throw() {
	realization_REMOVE_STL_ReverseIterator< A_type, std::vector< A_type > > *iterator = new realization_REMOVE_STL_ReverseIterator< A_type, std::vector< A_type > >( _vector );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( iterator, MACROS_FILE_AND_LINE ) );
	return Proxy< Iterator< A_type > >::createUnique( iterator );
}

template< class A_type >
Proxy< ConstantIterator< A_type > > realization_REMOVE_STL_Array< A_type >::createConstantForwardIterator() const throw() {
	realization_REMOVE_STL_ConstantForwardIterator< A_type, std::vector< A_type > > *constantIterator = new realization_REMOVE_STL_ConstantForwardIterator< A_type, std::vector< A_type > >( _vector );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( constantIterator, MACROS_FILE_AND_LINE ) );
	return Proxy< ConstantIterator< A_type > >::createUnique( constantIterator );
}

template< class A_type >
Proxy< ConstantIterator< A_type > > realization_REMOVE_STL_Array< A_type >::createConstantReverseIterator() const throw() {
	realization_REMOVE_STL_ConstantReverseIterator< A_type, std::vector< A_type > > *constantIterator = new realization_REMOVE_STL_ConstantReverseIterator< A_type, std::vector< A_type > >( _vector );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( constantIterator, MACROS_FILE_AND_LINE ) );
	return Proxy< ConstantIterator< A_type > >::createUnique( constantIterator );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_REMOVE_STL_Array< A_type >::~realization_REMOVE_STL_Array() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_REMOVE_STL_Array< A_type >::realization_REMOVE_STL_Array() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Proxy< Container< A_type > > realization_REMOVE_STL_Array< A_type >::createClone() const throw() {
	realization_REMOVE_STL_Array< A_type > *container = new realization_REMOVE_STL_Array< A_type >( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( container, MACROS_FILE_AND_LINE ) );
	return Proxy< Container< A_type > >::createUnique( container );
}

template< class A_type >
realization_REMOVE_STL_Array< A_type >::realization_REMOVE_STL_Array( const realization_REMOVE_STL_Array< A_type > &other ) throw()
	:
		_vector( other._vector )
{}

template< class A_type >
const realization_REMOVE_STL_Array< A_type > &realization_REMOVE_STL_Array< A_type >::operator =( const realization_REMOVE_STL_Array< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	_vector.clear();
	_vector = other._vector;
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
