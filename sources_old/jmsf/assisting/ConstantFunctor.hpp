#pragma once


#include "ConstantFunctory.hxx"

#include "jmsf/patterning/Object.h"

#include "jmsf/pointing/Proxy.hxx"
#include "jmsf/valdiating/Exceptions.hxx"


namespace jmsf {
namespace assisting {


template< class A_type >
class ConstantFunctor :
	public virtual patterning::Object
{

public:
	virtual void runMethod( const A_type &indirectedObject ) const throw( validating::Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ConstantFunctor *getNull() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual pointing::Proxy< ConstantFunctor< A_type > > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
