#pragma once


#include "AssociativeContainer.hxx"

#include "jmsf/patterning/Object.h"

#include "jmsf/containing/AssociativeIterator.hxx"
#include "jmsf/containing/AssociativeConstantIterator.hxx"
#include "jmsf/pointing/Proxy.hxx"


namespace jmsf {
namespace containing {


template< class A_key, class A_type >
class AssociativeContainer :
	public virtual ::jmsf::patterning::Object
{

public: // common getters
	virtual typing::Boolean isEmpty() const throw() = 0;
	virtual typing::Boolean isNotEmpty() const throw() = 0;
	virtual typing::Natural getQuantityOfElements() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // appending modifiers
	virtual void append( const A_key &aKey, const A_type &anObject ) throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // factories
	virtual pointing::Proxy< AssociativeIterator< A_key, A_type > > createIteratorAtLeftmostEnd() throw() = 0;
	virtual pointing::Proxy< AssociativeIterator< A_key, A_type > > createIteratorAtRightmostEnd() throw() = 0;
	virtual pointing::Proxy< AssociativeIterator< A_key, A_type > > createIteratorAtRoot() throw() = 0;
	virtual pointing::Proxy< AssociativeIterator< A_key, A_type > > createIteratorAt( const A_key &aKey ) throw() = 0;

 	virtual pointing::Proxy< AssociativeConstantIterator< A_key, A_type > > createConstantIteratorAtLeftmostEnd() throw() = 0;
 	virtual pointing::Proxy< AssociativeConstantIterator< A_key, A_type > > createConstantIteratorAtRightmostEnd() throw() = 0;
	virtual pointing::Proxy< AssociativeConstantIterator< A_key, A_type > > createConstantIteratorAtRoot() throw() = 0;
	virtual pointing::Proxy< AssociativeConstantIterator< A_key, A_type > > createConstantIteratorAt( const A_key &aKey ) throw() = 0;

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
