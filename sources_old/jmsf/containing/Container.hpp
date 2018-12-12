#pragma once


#include "Container.hxx"

#include "jmsf/patterning/Object.h"

#include "jmsf/containing/Iterator.hxx"
#include "jmsf/containing/ConstantIterator.hxx"
#include "jmsf/pointing/Proxy.hxx"


namespace jmsf {
namespace containing {


template< class A_type >
class Container :
	public virtual ::jmsf::patterning::Object
{

public: // common getters
	virtual typing::Boolean isEmpty() const throw() = 0;
	virtual typing::Boolean isNotEmpty() const throw() = 0;
	virtual typing::Natural getQuantityOfElements() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // appending modifiers
	virtual void appendToBegin( const A_type &object ) throw() = 0;
	virtual void appendToEnd( const A_type &object ) throw() = 0;


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // factories
	virtual pointing::Proxy< Iterator< A_type > > createIteratorAtBegin() throw() = 0;
	virtual pointing::Proxy< Iterator< A_type > > createIteratorAtEnd() throw() = 0;
	virtual pointing::Proxy< Iterator< A_type > > createIteratorAt( typing::Natural index ) throw( validating::Exception ) = 0;

	virtual pointing::Proxy< ConstantIterator< A_type > > createConstantIteratorAtBegin() throw() = 0;
	virtual pointing::Proxy< ConstantIterator< A_type > > createConstantIteratorAtEnd() throw() = 0;
	virtual pointing::Proxy< ConstantIterator< A_type > > createConstantIteratorAt( typing::Natural index ) throw( validating::Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Container *getNull() throw();
	static Container *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::pointing::Proxy< Container > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace containing
} // namespace jmsf
