#pragma once


#include "Functor.hpp"

#include "jmsf/patterning/mixing/mixin_null_Object.h"
#include "jmsf/patterning/Singleton.inl"
#include "jmsf/pointing/Proxy.inl"
#include "jmsf/validating/Should.h"
//#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace assisting {


template< class A_type >
class null_Functor :
	public Functor< A_type >,
	public patterning::mixing::mixin_null_Object,
	public patterning::Singleton< null_Functor< A_type > >
{

public:
	// virtuals	Functor
	void runMethod( A_type & ) throw( validating::Exception ) {} // indirectedObject
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_Functor() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< null_Functor >;
	static null_Functor *createInstance() throw() {
		null_Functor *nullFunctor = new null_Functor;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullFunctor, MACROS_FILE_AND_LINE ) );
		return nullFunctor;
	}

private:
	null_Functor() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtual
	pointing::Proxy< Functor< A_type > > createClone() const throw() { return pointing::Proxy< Functor< A_type > >::createUnique( this ); }

private:
	null_Functor( const null_Functor & ) throw() {}

	const null_Functor &operator =( const null_Functor &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverReachHere();
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class A_type >
Functor< A_type > *Functor< A_type >::getNull() throw() {
	return null_Functor< A_type >::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
