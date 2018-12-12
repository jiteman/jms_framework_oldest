#pragma once


#include "AssociativeIterator.hxx"

#include "jmsf/patterning/Object.h"

#include "jmsf/pointing/Proxy.hxx"


namespace jmsf {
namespace containing {


template< class A_key, class A_type >
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
	virtual void rewindToLeftmostEnd() throw() = 0;
	virtual void rewindToRightmostEnd() throw() = 0;
	virtual void moveOneStepToLeftmostEnd() throw( validating::Exception ) = 0;
	virtual void moveOneStepToRightmostEnd() throw( validating::Exception ) = 0;
	virtual void rewindToRoot() throw() = 0;
	virtual void moveOneStepToRoot() throw( validating::Exception ) = 0;
	virtual void moveOneStepFromRoot() throw( validating::Exception ) = 0;

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
	friend realization_AssociativeContainerArraySet< A_key, A_type >;
	friend realization_AssociativeContainerArrayMultiSet< A_key, A_type >;
	friend realization_AssociativeContainerArrayMap< A_key, A_type >;
	friend realization_AssociativeContainerArrayMultiMap< A_key, A_type >;
	virtual pointing::Proxy< AssociativeContainerAgent > getAgent() const throw() = 0;

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
