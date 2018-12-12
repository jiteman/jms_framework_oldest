#pragma once

#include "jmsf/Object.h"

#include "jmsf/Proxies.hxx"


namespace jmsf {
namespace containers {


template< class A_type >
class ConstantIterator :
	public virtual Object
{

public:
	virtual void rewind() throw() = 0;
	virtual void advance() throw( Exception ) = 0;
	virtual void behind() throw( Exception ) = 0;
	virtual const Boolean isNotDone() const throw() = 0;
	virtual const Boolean isDone() const throw() = 0;
	virtual const A_type &getContainie() const throw( Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ConstantIterator *getNull() throw();
	static ConstantIterator *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual Proxy< ConstantIterator< A_type > > createClone() const throw() = 0;

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
class null_ConstantIterator :
	public ConstantIterator< A_type >,
	public mixins::mixin_null_Object,
	public Singleton< null_ConstantIterator< A_type > >
{

public:
	// virtuals	ConstantIterator< A_type >
	void rewind() throw() {}
	void advance() throw( Exception ) {}
	void behind() throw( Exception ) {}

	const Boolean isNotDone() const throw() {
		return False;
	}

	const Boolean isDone() const throw() {
		return True;
	}

	const A_type &getContainie() const throw( Exception ) {
		return _referenceToReturn;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ConstantIterator() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< null_ConstantIterator >;
	static null_ConstantIterator *createInstance() throw() {
		null_ConstantIterator *nullConstantIterator = new null_ConstantIterator;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullConstantIterator, MACROS_FILE_AND_LINE ) );
		return nullConstantIterator;
	}

private:
	null_ConstantIterator() throw()
		:
			_referenceToReturn( A_type::createEmpty() )
	{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< ConstantIterator< A_type > > createClone() const throw() {
		return Proxy< ConstantIterator< A_type > >::createUnique( this );
	}

private:
	null_ConstantIterator( const null_ConstantIterator & ) throw() {} // other

	const null_ConstantIterator &operator =( const null_ConstantIterator &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "null_ConstantIterator::operator =()" );
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
	public mixins::mixin_exception_Object,
	public Singleton< exception_ConstantIterator< A_type > >
{

public:
	// virtuals	ConstantIterator< A_type >
	void rewind() throw() {}
	void advance() throw( Exception ) {}
	void behind() throw( Exception ) {}

	const Boolean isNotDone() const throw() {
		return False;
	}

	const Boolean isDone() const throw() {
		return True;
	}

	const A_type &getContainie() const throw( Exception ) {
		return _referenceToReturn;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ConstantIterator() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< exception_ConstantIterator >;
	static exception_ConstantIterator *createInstance() throw() {
		return
			debugging::static_ObjectCreationLogger< exception_ConstantIterator< A_type > >::registerCreation(
				new exception_ConstantIterator< A_type >, sizeof( exception_ConstantIterator< A_type > ), MACROS_FILE_AND_LINE );
	}

private:
	exception_ConstantIterator() throw()
		:
			_referenceToReturn( A_type::_createEmpty() )
	{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< ConstantIterator< A_type > > createClone() const throw() {
		return Proxy< ConstantIterator< A_type > >::createUnique( this );
	}

private:
	exception_ConstantIterator( const exception_ConstantIterator & ) throw() {} // other

	const exception_ConstantIterator &operator =( const exception_ConstantIterator &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "exception_ConstantIterator::operator =()" );
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


} // namespace containers
} // namespace jmsf
