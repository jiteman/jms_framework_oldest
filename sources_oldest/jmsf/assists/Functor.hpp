#pragma once

#include "jmsf/Object.h"

#include "jmsf/Proxies.hxx"


namespace jmsf {
namespace assists {


template< class A_type >
class Functor :
	public virtual Object
{

public:
	virtual void runMethod( A_type &indirectedObject ) throw( Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Functor *getNull() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual Proxy< Functor< A_type > > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}


#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace assists {


template< class A_type >
class null_Functor :
	public Functor< A_type >,
	public mixins::mixin_null_Object,
	public Singleton< null_Functor< A_type > >
{

public:
	// virtuals	Functor
	void runMethod( A_type & ) throw( Exception ) {} // indirectedObject
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
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullFunctor, MACROS_FILE_AND_LINE ) );
		return nullFunctor;
	}

private:
	null_Functor() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtual
	Proxy< Functor< A_type > > createClone() const throw() { return Proxy< Functor< A_type > >::createUnique( this ); }

private:
	null_Functor( const null_Functor & ) throw() {}

	const null_Functor &operator =( const null_Functor &other ) throw( Exception ) {
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
