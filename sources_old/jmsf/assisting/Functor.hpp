#pragma once


#include "Functor.hxx"

#include "jmsf/patterning/Object.h"

#include "jmsf/pointing/Proxy.hxx"


namespace jmsf {
namespace assisting {


template< class A_type >
class Functor :
	public virtual patterning::Object
{

public:
	virtual void runMethod( A_type &indirectedObject ) throw( validating::Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Functor *getNull() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual pointing::Proxy< Functor< A_type > > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
