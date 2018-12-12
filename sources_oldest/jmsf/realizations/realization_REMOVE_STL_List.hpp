#pragma once

#include "../Container.hpp"
#include "../mixins/mixin_Object.h"

#include "realization_REMOVE_STL_ForwardIterator.hpp"
#include "realization_REMOVE_STL_ConstantForwardIterator.hpp"
#include "realization_REMOVE_STL_ReverseIterator.hpp"
#include "realization_REMOVE_STL_ConstantReverseIterator.hpp"

#include "../Proxy.hpp"

#include "realization_factory_Container.hxx"

namespace jmsf {
namespace realizations {

template< class A_type >
class realization_REMOVE_STL_List :
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
	~realization_REMOVE_STL_List() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_Container< A_type >;
	realization_REMOVE_STL_List() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Container< A_type > > createClone() const throw();

private:
	realization_REMOVE_STL_List( const realization_REMOVE_STL_List &other ) throw();
	const realization_REMOVE_STL_List &operator =( const realization_REMOVE_STL_List &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	std::list< A_type > _list;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace realizations
} // namespace jmsf


#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace realizations {

template< class A_type >
void realization_REMOVE_STL_List< A_type >::appendFront( const A_type &object ) throw() {
	_list.push_front( object );
}

template< class A_type >
void realization_REMOVE_STL_List< A_type >::appendBack( const A_type &object ) throw() {
	_list.push_back( object );
}

template< class A_type >
void realization_REMOVE_STL_List< A_type >::clear() throw() {
	_list.clear();
}

template< class A_type >
const Boolean realization_REMOVE_STL_List< A_type >::isEmpty() const throw() {
	return _list.empty();
}

template< class A_type >
const Boolean realization_REMOVE_STL_List< A_type >::isNotEmpty() const throw() {
	return !_list.empty();
}

template< class A_type >
natural_size realization_REMOVE_STL_List< A_type >::getQuantityOfElements() const throw() {
	return _list.size();
}

template< class A_type >
const A_type &realization_REMOVE_STL_List< A_type >::getContainie( const natural_size index ) const throw() {
	std::list< A_type >::const_iterator containieByIndex = _list.begin();

	for ( natural_size currentIndex = 0; currentIndex < index; currentIndex += 1 ) {
		++containieByIndex;
	}

	return *containieByIndex;
}

template< class A_type >
A_type &realization_REMOVE_STL_List< A_type >::takeContainie( const natural_size index ) throw() {
	std::list< A_type >::iterator containieByIndex = _list.begin();

	for ( natural_size currentIndex = 0; currentIndex < index; currentIndex += 1 ) {
		++containieByIndex;
	}

	return *containieByIndex;
}

template< class A_type >
const A_type &realization_REMOVE_STL_List< A_type >::getFirstContainie() const throw() {
	return _list.front();
}

template< class A_type >
A_type &realization_REMOVE_STL_List< A_type >::takeFirstContainie() throw() {
	return _list.front();
}

template< class A_type >
const A_type &realization_REMOVE_STL_List< A_type >::getLastContainie() const throw() {
	return _list.back();
}

template< class A_type >
A_type &realization_REMOVE_STL_List< A_type >::takeLastContainie() throw() {
	return _list.back();
}

template< class A_type >
A_type realization_REMOVE_STL_List< A_type >::withdrawContainie( const natural_size index ) throw() {
	std::list< A_type >::iterator listIterator = _list.begin();

	for ( natural_size currentIndex = 0; currentIndex < index; currentIndex += 1 ) {
		++listIterator;
	}
	A_type containie = *listIterator;
	_list.erase( listIterator );
	return containie;
}

template< class A_type >
A_type realization_REMOVE_STL_List< A_type >::withdrawFirstContainie() throw() {
	A_type containie = _list.front();
	_list.pop_front();
	return containie;
}

template< class A_type >
A_type realization_REMOVE_STL_List< A_type >::withdrawLastContainie() throw() {
	A_type containie = _list.back();
	_list.pop_back();
	return containie;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Proxy< Iterator< A_type > > realization_REMOVE_STL_List< A_type >::createForwardIterator() throw() {
	realization_REMOVE_STL_ReverseIterator< A_type, std::list< A_type > > *iterator = new realization_REMOVE_STL_ReverseIterator< A_type, std::list< A_type > >( _list );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( iterator, MACROS_FILE_AND_LINE ) );
	return Proxy< Iterator< A_type > >::createUnique( iterator );
}

template< class A_type >
Proxy< Iterator< A_type > > realization_REMOVE_STL_List< A_type >::createReverseIterator() throw() {
	realization_REMOVE_STL_ForwardIterator< A_type, std::list< A_type > > *iterator = new realization_REMOVE_STL_ForwardIterator< A_type, std::list< A_type > >( _list );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( iterator, MACROS_FILE_AND_LINE ) );
	return Proxy< Iterator< A_type > >::createUnique( iterator );
}

template< class A_type >
Proxy< ConstantIterator< A_type > > realization_REMOVE_STL_List< A_type >::createConstantForwardIterator() const throw() {
	realization_REMOVE_STL_ConstantForwardIterator< A_type, std::list< A_type > > *constantIterator = new realization_REMOVE_STL_ConstantForwardIterator< A_type, std::list< A_type > >( _list );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( constantIterator, MACROS_FILE_AND_LINE ) );
	return Proxy< ConstantIterator< A_type > >::createUnique( constantIterator );
}

template< class A_type >
Proxy< ConstantIterator< A_type > > realization_REMOVE_STL_List< A_type >::createConstantReverseIterator() const throw() {
	realization_REMOVE_STL_ConstantReverseIterator< A_type, std::list< A_type > > *constantIterator = new realization_REMOVE_STL_ConstantReverseIterator< A_type, std::list< A_type > >( _list );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( constantIterator, MACROS_FILE_AND_LINE ) );
	return Proxy< ConstantIterator< A_type > >::createUnique( constantIterator );
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_REMOVE_STL_List< A_type >::~realization_REMOVE_STL_List() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_REMOVE_STL_List< A_type >::realization_REMOVE_STL_List() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Proxy< Container< A_type > > realization_REMOVE_STL_List< A_type >::createClone() const throw() {
	realization_REMOVE_STL_List< A_type > *container = new realization_REMOVE_STL_List< A_type >( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( container, MACROS_FILE_AND_LINE ) );
	return Proxy< Container< A_type > >::createUnique( container );
}

template< class A_type >
realization_REMOVE_STL_List< A_type >::realization_REMOVE_STL_List( const realization_REMOVE_STL_List< A_type > &other ) throw()
	:
		_list( other._list )
{}

template< class A_type >
const realization_REMOVE_STL_List< A_type > &realization_REMOVE_STL_List< A_type >::operator =( const realization_REMOVE_STL_List< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
