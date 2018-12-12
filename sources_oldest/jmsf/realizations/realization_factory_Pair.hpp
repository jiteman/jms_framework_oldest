#pragma once

#include "../factory_Pair.hpp"

namespace jmsf {
namespace realizations {

template< class A_first_type, class A_second_type >
class realization_factory_Pair :
	public factory_Pair< A_first_type, A_second_type >
{

public:
	// virtuals factory_Pair< A_first_type, A_second_type >
	Proxy< Pair< A_first_type, A_second_type > > createPair( const A_first_type &firstObject, const A_second_type &secondObject );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_Pair() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend factory_Pair< A_first_type, A_second_type >;
	realization_factory_Pair() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_Pair( const realization_factory_Pair &other ) throw();
	const realization_factory_Pair &operator =( const realization_factory_Pair &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace realizations
} // namespace jmsf


#include "realization_Pair.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace realizations {

template< class A_first_type, class A_second_type >
Proxy< Pair< A_first_type, A_second_type > > realization_factory_Pair< A_first_type, A_second_type >::createPair( const A_first_type &firstObject, const A_second_type &secondObject ) {
	Pair< A_first_type, A_second_type > *newPair = new realization_Pair< A_first_type, A_second_type >( firstObject, secondObject );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( newPair, MACROS_FILE_AND_LINE ) );
	return Proxy< Pair< A_first_type, A_second_type > >::createUnique( newPair );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_first_type, class A_second_type >
realization_factory_Pair< A_first_type, A_second_type >::~realization_factory_Pair() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_first_type, class A_second_type >
realization_factory_Pair< A_first_type, A_second_type >::realization_factory_Pair() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_first_type, class A_second_type >
realization_factory_Pair< A_first_type, A_second_type >::realization_factory_Pair( const realization_factory_Pair< A_first_type, A_second_type > & ) throw() // other
{}

template< class A_first_type, class A_second_type >
const realization_factory_Pair< A_first_type, A_second_type > &realization_factory_Pair< A_first_type, A_second_type >::operator =( const realization_factory_Pair< A_first_type, A_second_type > &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	// copy
	Should::neverViolateCopyingProhibition( "realization_factory_Pair< A_first_type, A_second_type >::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace realizations
} // namespace jmsf
