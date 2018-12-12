#pragma once

#include "jmsf/Object.h"

#include "jmsf/Proxies.hxx"


namespace jmsf {
namespace assists {


template< class A_type >
class ConstantFunctor :
	public virtual Object
{

public:
	virtual void runMethod( const A_type &indirectedObject ) const throw( Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ConstantFunctor *getNull() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual Proxy< ConstantFunctor< A_type > > createClone() const throw() = 0;

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
class null_ConstantFunctor :
	public ConstantFunctor< A_type >,
	public mixins::mixin_null_Object,
	public Singleton< null_ConstantFunctor< A_type > >
{

public:
	// virtuals	ConstantFunctor
	void runMethod( const A_type & ) const throw( Exception ) {} // indirectedObject
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ConstantFunctor() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< null_ConstantFunctor >;
	static null_ConstantFunctor *createInstance() throw() {
		null_ConstantFunctor *nullConstantFunctor = new null_ConstantFunctor;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullConstantFunctor, MACROS_FILE_AND_LINE ) );
		return nullConstantFunctor;
	}

private:
	null_ConstantFunctor() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtual
	Proxy< ConstantFunctor< A_type > > createClone() const throw() { return Proxy< ConstantFunctor< A_type > >::createUnique( this ); }

private:
	null_ConstantFunctor( const null_ConstantFunctor & ) throw() {}

	const null_ConstantFunctor &operator =( const null_ConstantFunctor &other ) throw( Exception ) {
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
ConstantFunctor< A_type > *ConstantFunctor< A_type >::getNull() throw() {
	return null_ConstantFunctor< A_type >::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
