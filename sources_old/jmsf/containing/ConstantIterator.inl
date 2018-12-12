#pragma once


#include "ConstantIterator.hpp"

#include "jmsf/patterning/mixing/mixin_null_Object.h"
#include "jmsf/patterning/mixing/mixin_exception_Object.h"
#include "jmsf/patterning/Singleton.inl"
#include "jmsf/pointing/Proxy.inl"
#include "jmsf/validating/Should.h"


namespace jmsf {
namespace containing {


template< class A_type >
class null_ConstantIterator :
	public ConstantIterator< A_type >,
	public ::jmsf::patterning::mixing::mixin_null_Object,
	public ::jmsf::patterning::Singleton< null_ConstantIterator< A_type > >
{

public: // common getters
	// virtuals ConstantIterator
	typing::Boolean isDone() const throw() { return typing::True; }
	typing::Boolean isNotDone() const throw() { return typing::False; }
	//~virtuals ConstantIterator
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // element getters
	// virtuals ConstantIterator
	const A_type &getContainie() const throw( validating::Exception ) { return _referenceToReturn; }
	//~virtuals ConstantIterator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // iterations
	// virtuals ConstantIterator
	void rewindToBegin() throw() {}
	void rewindToEnd() throw() {}
	void moveOneStepToBegin() throw( validating::Exception ) {}
	void moveOneStepToEnd() throw( validating::Exception ) {}
	//~virtuals ConstantIterator

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtuals ConstantIterator
	pointing::Proxy< ContainerAgent > getAgent() const throw() { return pointing::Proxy< ContainerAgent >(); }
	//~virtuals ConstantIterator

private:
	// virtual
	~null_ConstantIterator() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::patterning::Singleton< null_ConstantIterator< A_type > >;
	static null_ConstantIterator *createInstance() throw() {
		return new null_ConstantIterator;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ConstantIterator() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< ConstantIterator > createClone() const throw() {
		return ::jmsf::pointing::Proxy< ConstantIterator >::createNonlinkedFor( this );
	}

private:
	null_ConstantIterator( const null_ConstantIterator & ) throw() {} // other
	
	const null_ConstantIterator &operator =( const null_ConstantIterator &other ) throw( ::jmsf::validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::validating::Should::neverViolateCopyingProhibition( "null_ConstantIterator< A_type >::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _referenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

template< class A_type >
class exception_ConstantIterator :
	public ConstantIterator< A_type >,
	public ::jmsf::patterning::mixing::mixin_exception_Object,
	public ::jmsf::patterning::Singleton< exception_ConstantIterator< A_type > >
{

public: // common getters
	// virtuals ConstantIterator
	typing::Boolean isDone() const throw() { return typing::True; }
	typing::Boolean isNotDone() const throw() { return typing::False; }
	//~virtuals ConstantIterator
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // element getters
	// virtuals ConstantIterator
	const A_type &getContainie() const throw( validating::Exception ) { return _referenceToReturn; }
	//~virtuals ConstantIterator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // iterations
	// virtuals ConstantIterator
	void rewindToBegin() throw() {}
	void rewindToEnd() throw() {}
	void moveOneStepToBegin() throw( validating::Exception ) {}
	void moveOneStepToEnd() throw( validating::Exception ) {}
	//~virtuals ConstantIterator

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtuals ConstantIterator
	pointing::Proxy< ContainerAgent > getAgent() const throw() { return pointing::Proxy< ContainerAgent >(); }
	//~virtuals ConstantIterator

private:
	// virtual
	~exception_ConstantIterator() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::patterning::Singleton< exception_ConstantIterator< A_type > >;
	static exception_ConstantIterator *createInstance() throw() {
		return new exception_ConstantIterator;
	}

private:
	exception_ConstantIterator() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< ConstantIterator > createClone() const throw() {
		return ::jmsf::pointing::Proxy< ConstantIterator >::createNonlinkedFor( this );
	}

private:
	exception_ConstantIterator( const exception_ConstantIterator & ) throw() {} // other

	const exception_ConstantIterator &operator =( const exception_ConstantIterator &other ) throw( ::jmsf::validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::validating::Should::neverViolateCopyingProhibition( "exception_ConstantIterator< A_type >::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _referenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class A_type >
ConstantIterator< A_type > *ConstantIterator< A_type >::getNull() throw() {
	return null_ConstantIterator< A_type >::instance();
}

// static
template< class A_type >
ConstantIterator< A_type > *ConstantIterator< A_type >::getException() throw() {
	return exception_ConstantIterator< A_type >::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace containing
} // namespace jmsf
