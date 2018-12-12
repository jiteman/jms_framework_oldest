#pragma once

#include "jmsf/Singleton.hpp"

#include "Pair.hxx"

namespace jmsf {

template< class A_first_type, class A_second_type >
class factory_Pair :
	public Singleton< factory_Pair< A_first_type, A_second_type > >
{

public:
	virtual Proxy< Pair< A_first_type, A_second_type > > createPair( const A_first_type &firstObject, const A_second_type &secondObject ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: friend DeleterForPointer< factory_Pair >;
	~factory_Pair() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< factory_Pair >;
	static factory_Pair *createInstance() throw();

protected:
	factory_Pair() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	factory_Pair( const factory_Pair &other ) throw();
	const factory_Pair &operator =( const factory_Pair &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace jmsf


#include "realizations/realization_factory_Pair.hpp"
#include "jmsf/Should.h"


namespace jmsf {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_first_type, class A_second_type >
factory_Pair< A_first_type, A_second_type >::~factory_Pair() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class A_first_type, class A_second_type >
factory_Pair< A_first_type, A_second_type > *factory_Pair< A_first_type, A_second_type >::createInstance() throw() {
	return new realizations::realization_factory_Pair< A_first_type, A_second_type >;
}

template< class A_first_type, class A_second_type >
factory_Pair< A_first_type, A_second_type >::factory_Pair() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_first_type, class A_second_type >
factory_Pair< A_first_type, A_second_type >::factory_Pair( const factory_Pair< A_first_type, A_second_type > & ) throw() // other
{}

template< class A_first_type, class A_second_type >
const factory_Pair< A_first_type, A_second_type > &factory_Pair< A_first_type, A_second_type >::operator =( const factory_Pair< A_first_type, A_second_type > &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	// copy
	Should::neverViolateCopyingProhibition( "factory_Pair< A_first_type, A_second_type >::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace jmsf
