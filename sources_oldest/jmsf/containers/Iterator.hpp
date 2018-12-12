#pragma once

#include "jmsf/Object.h"

#include "jmsf/Proxies.hxx"


namespace jmsf {
namespace containers {

template< class A_type >
class Iterator :
	public virtual Object
{

public: // getters
	virtual const Boolean isNotDone() const throw() = 0;
	virtual const Boolean isDone() const throw() = 0;

	virtual const A_type &getContainie() const throw( Exception ) = 0;
	virtual A_type &takeContainie() throw( Exception ) = 0;

	virtual void rewindToBegin() throw() = 0;
	virtual void rewindToEnd() throw() = 0;
	virtual void moveOneStepToBegin() throw( Exception ) = 0;
	virtual void moveOneStepToEnd() throw( Exception ) = 0;

public: // modifiers
	virtual void eraseContainie() throw( Exception ) = 0;

	virtual A_type withdrawContainie() throw( Exception ) = 0;

	virtual void insertAfter( const A_type &placeholder ) throw( Exception ) = 0;
	virtual void insertBefore( const A_type &placeholder ) throw( Exception ) = 0;

public: // service
	virtual natural_size getIndexOfContainie() const throw() = 0;
	virtual const A_type *getAddressOfContainie() const throw() = 0;
	virtual const Proxy< Container< A_type > > &getAddressOfContainer() const throw() = 0;
	virtual Boolean isDirectionFromBeginToEnd() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Iterator *getNull() throw();
	static Iterator *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual Proxy< Iterator< A_type > > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace containers
} // namespace jmsf


#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace containers {


template< class A_type >
class null_Iterator :
	public Iterator< A_type >,
	public mixins::mixin_null_Object,
	public Singleton< null_Iterator< A_type > >
{

public: // getters
	// virtuals Iterator
	Boolean isNotDone() const throw() { return False; }
	Boolean isDone() const throw() { return True; }

	const A_type &getContainie() const throw( Exception ) { return _referenceToReturn; }
	A_type &takeContainie() throw( Exception ) { return _referenceToReturn; }

	void rewindToBegin() throw() {}
	void rewindToEnd() throw() {}
	void moveOneStepToBegin() throw( Exception ) {}
	void moveOneStepToEnd() throw( Exception ) {}
	//~virtuals Iterator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // modifiers
	// virtuals Iterator
	void eraseContainie() throw( Exception ) {}
	A_type withdrawContainie() throw( Exception ) { return A_type(); }

	void insertAfter( const A_type & ) throw( Exception ) {} // placeholder
	void insertBefore( const A_type & ) throw( Exception ) {} // placeholder
	//~virtuals Iterator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // service
	// virtuals Iterator
	natural_size getIndexOfContainie() const throw() { return ~0; }
	const A_type *getAddressOfContainie() const throw() { return nullptr; }
	const Proxy< Container< A_type > > &getAddressOfContainer() const throw() { return _containerReferenceToReturn; }
	Boolean isDirectionFromBeginToEnd() const throw() { return True; }
	//~virtuals Iterator

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_Iterator() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< null_Iterator >;
	static null_Iterator *createInstance() throw() {
		null_Iterator *nullIterator = new null_Iterator;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullIterator, MACROS_FILE_AND_LINE ) );
		return nullIterator;
	}

private:
	null_Iterator() throw()	{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Iterator< A_type > > createClone() const throw() {
		return Proxy< Iterator< A_type > >::createUnique( this );
	}

private:
	null_Iterator( const null_Iterator & ) throw() {} // other

	const null_Iterator &operator =( const null_Iterator &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "null_Iterator::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _referenceToReturn;
	Proxy< Container< A_type > > _containerReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


template< class A_type >
class exception_Iterator :
	public Iterator< A_type >,
	public mixins::mixin_exception_Object,
	public Singleton< exception_Iterator< A_type > >
{

public: // getters
	// virtuals Iterator
	const Boolean isNotDone() const throw() { return False; }
	const Boolean isDone() const throw() { return True; }

	const A_type &getContainie() const throw( Exception ) { return _referenceToReturn; }
	A_type &takeContainie() throw( Exception ) { return _referenceToReturn; }

	void rewindToBegin() throw() {}
	void rewindToEnd() throw() {}
	void moveOneStepToBegin() throw( Exception ) {}
	void moveOneStepToEnd() throw( Exception ) {}
	//~virtuals Iterator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // modifiers
	// virtuals Iterator
	void eraseContainie() throw( Exception ) {}
	A_type withdrawContainie() throw( Exception ) { return A_type(); }

	void insertAfter( const A_type & ) throw( Exception ) {} // placeholder
	void insertBefore( const A_type & ) throw( Exception ) {} // placeholder
	//~virtuals Iterator

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // service
	// virtuals Iterator
	natural_size getIndexOfContainie() const throw() { return ~0; }
	const A_type *getAddressOfContainie() const throw() { return nullptr; }
	const Proxy< Container< A_type > > &getAddressOfContainer() const throw() { return _containerReferenceToReturn; }
	Boolean isDirectionFromBeginToEnd() const throw() { return True; }
	//~virtuals Iterator

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_Iterator() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< exception_Iterator >;
	static exception_Iterator *createInstance() throw() {
		return
			debugging::static_ObjectCreationLogger< exception_Iterator< A_type > >::registerCreation(
				new exception_Iterator< A_type >, sizeof( exception_Iterator< A_type > ), MACROS_FILE_AND_LINE );
	}

private:
	exception_Iterator() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Iterator< A_type > > createClone() const throw() {
		return Proxy< Iterator< A_type > >::createUnique( this );
	}

private:
	exception_Iterator( const exception_Iterator & ) throw() {} // other

	const exception_Iterator &operator =( const exception_Iterator &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "exception_Iterator::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _referenceToReturn;
	Proxy< Container< A_type > > _containerRefereceToReturn;

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



} // namespace containers
} // namespace jmsf
