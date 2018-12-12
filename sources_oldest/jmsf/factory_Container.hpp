#pragma once

#include "Singleton.hpp"


namespace jmsf {


template< class A_type >
class factory_Container :
	public Singleton< factory_Container< A_type > >
{

public:
	virtual Proxy< Container< A_type > > createArray() const throw() = 0;
	virtual Proxy< Container< A_type > > createList() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_Container() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class Singleton< factory_Container >;
	static factory_Container *createInstance() throw();

protected:
	factory_Container() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_Container( const factory_Container &other ) throw();
	const factory_Container &operator =( const factory_Container &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace


#include "realizations/realization_factory_Container.hpp"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
factory_Container< A_type >::~factory_Container() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class A_type >
factory_Container< A_type > *factory_Container< A_type >::createInstance() throw() {
	factory_Container< A_type > *factoryContainer = new realizations::realization_factory_Container< A_type >;
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( factoryContainer, MACROS_FILE_AND_LINE ) );
	return factoryContainer;
}

template< class A_type >
factory_Container< A_type >::factory_Container() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
factory_Container< A_type >::factory_Container( const factory_Container< A_type > &other ) throw()
{}

template< class A_type >
const factory_Container< A_type > &factory_Container< A_type >::operator =( const factory_Container< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -