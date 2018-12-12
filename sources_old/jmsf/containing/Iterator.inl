#pragma once


#include "Iterator.hpp"

#include "jmsf/patterning/mixing/mixin_null_Object.h"
#include "jmsf/patterning/mixing/mixin_exception_Object.h"
#include "jmsf/patterning/Singleton.inl"
#include "jmsf/pointing/Proxy.inl"
#include "jmsf/validating/Should.h"


namespace jmsf {
namespace containing {


template< class A_type >
class null_Iterator :
	public Iterator< A_type >,
	public ::jmsf::patterning::mixing::mixin_null_Object,
	public ::jmsf::patterning::Singleton< null_Iterator< A_type > >
{

public: // common getters
	// virtuals Iterator
	typing::Boolean isDone() const throw() { return typing::True; }
	typing::Boolean isNotDone() const throw() { return typing::False; }
	//~virtuals Iterator
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // element getters
	// virtuals Iterator
	const A_type &getContainie() const throw( validating::Exception ) { return _referenceToReturn; }
	A_type &takeContainie() throw( validating::Exception ) { return _referenceToReturn; }
	//~virtuals Iterator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // iterations
	// virtuals Iterator
	void rewindToBegin() throw() {}
	void rewindToEnd() throw() {}
	void moveOneStepToBegin() throw( validating::Exception ) {}
	void moveOneStepToEnd() throw( validating::Exception ) {}
	//~virtuals Iterator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // appending modifiers
	// virtuals Iterator
	void insertAfter( const A_type & ) throw( validating::Exception ) {} // object
	void insertBefore( const A_type & ) throw( validating::Exception ) {} // object
	//~virtuals Iterator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // erasing modifiers
	// virtuals Iterator
	void eraseContainie() throw( validating::Exception ) {}
	A_type withdrawContainie() throw( validating::Exception ) { return A_type(); }
	//~virtuals Iterator

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtuals Iterator
	pointing::Proxy< ContainerAgent > getAgent() const throw() { return pointing::Proxy< ContainerAgent >(); }
	//~virtuals Iterator

private:
	// virtual
	~null_Iterator() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::patterning::Singleton< null_Iterator< A_type > >;
	static null_Iterator *createInstance() throw() {
		return new null_Iterator;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_Iterator() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< Iterator > createClone() const throw() {
		return ::jmsf::pointing::Proxy< Iterator >::createNonlinkedFor( this );
	}

private:
	null_Iterator( const null_Iterator & ) throw() {} // other
	
	const null_Iterator &operator =( const null_Iterator &other ) throw( ::jmsf::validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::validating::Should::neverViolateCopyingProhibition( "null_Iterator< A_type >::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _referenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

template< class A_type >
class exception_Iterator :
	public Iterator< A_type >,
	public ::jmsf::patterning::mixing::mixin_exception_Object,
	public ::jmsf::patterning::Singleton< exception_Iterator< A_type > >
{

public: // common getters
	// virtuals Iterator
	typing::Boolean isDone() const throw() { return typing::True; }
	typing::Boolean isNotDone() const throw() { return typing::False; }
	//~virtuals Iterator
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // element getters
	// virtuals Iterator
	const A_type &getContainie() const throw( validating::Exception ) { return _referenceToReturn; }
	A_type &takeContainie() throw( validating::Exception ) { return _referenceToReturn; }
	//~virtuals Iterator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // iterations
	// virtuals Iterator
	void rewindToBegin() throw() {}
	void rewindToEnd() throw() {}
	void moveOneStepToBegin() throw( validating::Exception ) {}
	void moveOneStepToEnd() throw( validating::Exception ) {}
	//~virtuals Iterator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // appending modifiers
	// virtuals Iterator
	void insertAfter( const A_type & ) throw( validating::Exception ) {} // object
	void insertBefore( const A_type & ) throw( validating::Exception ) {} // object
	//~virtuals Iterator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // erasing modifiers
	// virtuals Iterator
	void eraseContainie() throw( validating::Exception ) {}
	A_type withdrawContainie() throw( validating::Exception ) { return A_type(); }
	//~virtuals Iterator

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtuals Iterator
	pointing::Proxy< ContainerAgent > getAgent() const throw() { return pointing::Proxy< ContainerAgent >(); }
	//~virtuals Iterator

private:
	// virtual
	~exception_Iterator() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::patterning::Singleton< exception_Iterator< A_type > >;
	static exception_Iterator *createInstance() throw() {
		return new exception_Iterator;
	}

private:
	exception_Iterator() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< Iterator > createClone() const throw() {
		return ::jmsf::pointing::Proxy< Iterator >::createNonlinkedFor( this );
	}

private:
	exception_Iterator( const exception_Iterator & ) throw() {} // other

	const exception_Iterator &operator =( const exception_Iterator &other ) throw( ::jmsf::validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::validating::Should::neverViolateCopyingProhibition( "exception_Iterator< A_type >::operator =()", FILE_AND_LINE );
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
Iterator< A_type > *Iterator< A_type >::getNull() throw() {
	return null_Iterator< A_type >::instance();
}

// static
template< class A_type >
Iterator< A_type > *Iterator< A_type >::getException() throw() {
	return exception_Iterator< A_type >::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace containing
} // namespace jmsf
