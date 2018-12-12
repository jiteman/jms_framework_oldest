#pragma once

#include "../Pair.hpp"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Exception.hxx"
#include "realization_factory_Pair.hxx"

namespace jmsf {
namespace realizations {

template< class A_first_type, class A_second_type >
class realization_Pair :
	public Pair< A_first_type, A_second_type >,
	public mixins::mixin_Object
{

public:
	// virtuals Pair< A_first_type, A_second_type >
	A_first_type &takeFirst() throw();
	A_second_type &takeSecond() throw();

	const A_first_type &getFirst() const throw();
	const A_second_type &getSecond() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_Pair() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_Pair< A_first_type, A_second_type >;
	realization_Pair( const A_first_type &firstObject, const A_second_type &secondObject ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Pair< A_first_type, A_second_type > > createClone() const throw();

private:
	realization_Pair( const realization_Pair &other ) throw();
	const realization_Pair &operator =( const realization_Pair &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_first_type _firstObject;
	A_second_type _secondObject;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace realizations
} // namespace jmsf


#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace realizations {

template< class A_first_type, class A_second_type >
A_first_type &realization_Pair< A_first_type, A_second_type >::takeFirst() throw() {
	return _firstObject;
}

template< class A_first_type, class A_second_type >
A_second_type &realization_Pair< A_first_type, A_second_type >::takeSecond() throw() {
	return _secondObject;
}

template< class A_first_type, class A_second_type >
const A_first_type &realization_Pair< A_first_type, A_second_type >::getFirst() const throw() {
	return _firstObject;
}

template< class A_first_type, class A_second_type >
const A_second_type &realization_Pair< A_first_type, A_second_type >::getSecond() const throw() {
	return _secondObject;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_first_type, class A_second_type >
realization_Pair< A_first_type, A_second_type >::~realization_Pair() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_first_type, class A_second_type >
realization_Pair< A_first_type, A_second_type >::realization_Pair( const A_first_type &firstObject, const A_second_type &secondObject ) throw()
	:
		_firstObject( firstObject ),
		_secondObject( secondObject )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_first_type, class A_second_type >
Proxy< Pair< A_first_type, A_second_type > > realization_Pair< A_first_type, A_second_type >::createClone() const throw() {
	Pair< A_first_type, A_second_type > *newPair = new realization_Pair( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( newPair, MACROS_FILE_AND_LINE ) );
	return Proxy< Pair< A_first_type, A_second_type > >::createUnique( newPair );
}

template< class A_first_type, class A_second_type >
realization_Pair< A_first_type, A_second_type >::realization_Pair( const realization_Pair< A_first_type, A_second_type > &other ) throw() // other
	:
		_firstObject( other._firstObject ),
		_secondObject( other._secondObject )
{}

template< class A_first_type, class A_second_type >
const realization_Pair< A_first_type, A_second_type > &realization_Pair< A_first_type, A_second_type >::operator =( const realization_Pair< A_first_type, A_second_type > &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	Should::neverViolateCopyingProhibition( "realization_Pair::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace realizations
} // namespace jmsf
