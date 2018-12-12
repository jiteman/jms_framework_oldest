#pragma once

#include "realization_REMOVE_STL_Array.hpp"
#include "realization_REMOVE_STL_List.hpp"

#include "../factory_Container.hpp"

namespace jmsf {
namespace realizations {

template< class A_type >
class realization_factory_Container :
	public factory_Container< A_type >
{

public:
	// virtuals
	Proxy< Container< A_type > > createArray() const throw();
	Proxy< Container< A_type > > createList() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_Container() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class factory_Container< A_type >;
	realization_factory_Container() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_Container( const realization_factory_Container &other ) throw();
	const realization_factory_Container &operator =( const realization_factory_Container &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace realizations
} // namespace jmsf


#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace realizations {

template< class A_type >
Proxy< Container< A_type > > realization_factory_Container< A_type >::createArray() const throw() {
	realization_REMOVE_STL_Array< A_type > *container = new realization_REMOVE_STL_Array< A_type >;
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( container, MACROS_FILE_AND_LINE ) );
	return Proxy< Container< A_type > >::createUnique( container );
}

template< class A_type >
Proxy< Container< A_type > > realization_factory_Container< A_type >::createList() const throw() {
	realization_REMOVE_STL_List< A_type > *container = new realization_REMOVE_STL_List< A_type >;
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( container, MACROS_FILE_AND_LINE ) );
	return Proxy< Container< A_type > >::createUnique( container );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_factory_Container< A_type >::~realization_factory_Container() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_factory_Container< A_type >::realization_factory_Container() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_factory_Container< A_type >::realization_factory_Container( const realization_factory_Container< A_type > &other ) throw()
{}

template< class A_type >
const realization_factory_Container< A_type > &realization_factory_Container< A_type >::operator =( const realization_factory_Container< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
