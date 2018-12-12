#pragma once


#include "ConstantFunctor.hpp"

#include "jmsf/patterning/mixing/mixin_null_Object.h"
#include "jmsf/patterning/Singleton.inl"
#include "jmsf/pointing/Proxy.inl"
#include "jmsf/validating/Should.h"


namespace jmsf {
namespace assisting {


template< class A_type >
class null_ConstantFunctor :
	public ConstantFunctor< A_type >,
	public patterning::mixing::mixin_null_Object,
	public patterning::Singleton< null_ConstantFunctor< A_type > >
{

public:
	// virtuals	ConstantFunctor
	void runMethod( const A_type & ) const throw( validating::Exception ) {} // indirectedObject
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ConstantFunctor() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend patterning::Singleton< null_ConstantFunctor >;
	static null_ConstantFunctor *createInstance() throw() {
		null_ConstantFunctor *nullConstantFunctor = new null_ConstantFunctor;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullConstantFunctor, MACROS_FILE_AND_LINE ) );
		return nullConstantFunctor;
	}

private:
	null_ConstantFunctor() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtual
	pointing::Proxy< ConstantFunctor< A_type > > createClone() const throw() { return pointing::Proxy< ConstantFunctor< A_type > >::createUnique( this ); }

private:
	null_ConstantFunctor( const null_ConstantFunctor & ) throw() {}

	const null_ConstantFunctor &operator =( const null_ConstantFunctor &other ) throw( validating::Exception ) {
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
