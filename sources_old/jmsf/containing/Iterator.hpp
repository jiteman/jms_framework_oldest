#pragma once


#include "Iterator.hxx"

#include "jmsf/patterning/Object.h"

#include "jmsf/pointing/Proxy.hxx"


namespace jmsf {
namespace containing {


template< class A_type >
class Iterator :
	public virtual ::jmsf::patterning::Object
{

public: // common getters
	virtual typing::Boolean isDone() const throw() = 0;
	virtual typing::Boolean isNotDone() const throw() = 0;
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // element getters
	virtual const A_type &getContainie() const throw( validating::Exception ) = 0;
	virtual A_type &takeContainie() throw( validating::Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // iterations
	virtual void rewindToBegin() throw() = 0;
	virtual void rewindToEnd() throw() = 0;
	virtual void moveOneStepToBegin() throw( validating::Exception ) = 0;
	virtual void moveOneStepToEnd() throw( validating::Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // appending modifiers
	virtual void insertAfter( const A_type &object ) throw( validating::Exception ) = 0;
	virtual void insertBefore( const A_type &object ) throw( validating::Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // erasing modifiers
	virtual void eraseContainie() throw( validating::Exception ) = 0;
	virtual A_type withdrawContainie() throw( validating::Exception ) = 0;
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Iterator *getNull() throw();
	static Iterator *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	friend realization_ContainerArray< A_type >;
	friend realization_ContainerDeque< A_type >;
	friend realization_ContainerList< A_type >;
	virtual pointing::Proxy< ContainerAgent > getAgent() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::pointing::Proxy< Iterator > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};



} // namespace containing
} // namespace jmsf
