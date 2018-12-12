#pragma once

#include "Lockable.h"
#include "jmsf/Object.h"

#include "jmsf/osie/Event.hxx"
#include "jmsf/Proxies.hxx"

namespace jmsf {
namespace mtf {

template< class A_type >
class SynchronizedQueue :
	public virtual Lockable,
	public virtual Object
{

public:
	virtual void appendBack( const A_type &object ) throw( Exception ) = 0;
	virtual void appendFront( const A_type &object ) throw( Exception ) = 0;
	virtual A_type withdrawFirst() throw( Exception ) = 0;
	virtual A_type withdrawLast() throw( Exception ) = 0;
	virtual integer_big getFirstTime() const throw( Exception ) = 0;
	virtual integer_big getLastTime() const throw( Exception ) = 0;
	virtual void empty() throw( Exception ) = 0;
	virtual const Boolean isEmpty() const throw( Exception ) = 0;
	virtual const Boolean isNotEmpty() const throw( Exception ) = 0;
	virtual natural_size getQuantityOfObjects() const throw( Exception ) = 0;
	virtual Proxy< osie::Event > &takeIsObjectAvailableEvent() throw() = 0;
	virtual const ConstantProxy< osie::Event > &getIsObjectAvailableEvent() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static SynchronizedQueue *getNull() throw();
	static SynchronizedQueue *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual Proxy< SynchronizedQueue< A_type > > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace mtf
} // namespace jmsf


#include "mixins/mixin_null_Lockable.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace jmsf {
namespace mtf {

template< class A_type >
class null_SynchronizedQueue :
	public SynchronizedQueue< A_type >,
	public mixins::mixin_null_Lockable,
	public ::jmsf::mixins::mixin_null_Object,
	public Singleton< null_SynchronizedQueue< A_type > >
{

public:
	// virtuals	SynchronizedQueue< A_type >
	void appendBack( const A_type & ) throw( Exception ) {} // object
	void appendFront( const A_type & ) throw( Exception ) {} // object

	A_type withdrawFirst() throw( Exception ) {
		return A_type();
	}

	A_type withdrawLast() throw( Exception ) {
		return A_type();
	}

	integer_big getFirstTime() const throw( Exception ) {
		return integer_big( 0 );
	}

	integer_big getLastTime() const throw( Exception ) {
		return integer_big( 0 );
	}

	void empty() throw( Exception ) {}

	const Boolean isEmpty() const throw( Exception ) {
		return True;
	}

	const Boolean isNotEmpty() const throw( Exception ) {
		return False;
	}

	natural_size getQuantityOfObjects() const throw( Exception ) {
		return natural_size( 0 );
	}

	Proxy< osie::Event > &takeIsObjectAvailableEvent() throw() {
		return _eventRtr;
	}

	const ConstantProxy< osie::Event > &getIsObjectAvailableEvent() const throw() {
		return _eventCrtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_SynchronizedQueue() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< null_SynchronizedQueue >;
	static null_SynchronizedQueue *createInstance() throw() {
		return new null_SynchronizedQueue< A_type >;
	}

private:
	null_SynchronizedQueue() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< SynchronizedQueue< A_type > > createClone() const throw() {
		return Proxy< SynchronizedQueue< A_type > >::createUnique( this );
	}

private:
	null_SynchronizedQueue( const null_SynchronizedQueue & ) throw() {} // other

	const null_SynchronizedQueue &operator =( const null_SynchronizedQueue &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "null_SynchronizedQueue::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Proxy< osie::Event > _eventRtr;
	ConstantProxy< osie::Event > _eventCrtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


template< class A_type >
class exception_SynchronizedQueue :
	public SynchronizedQueue< A_type >,
	public mixins::mixin_null_Lockable,
	public mixins::mixin_exception_Object,
	public Singleton< exception_SynchronizedQueue< A_type > >
{

public:
	// virtuals	SynchronizedQueue< A_type >
	void appendBack( const A_type & ) throw( Exception ) {} // object
	void appendFront( const A_type & ) throw( Exception ) {} // object

	A_type withdrawFirst() throw( Exception ) {
		return A_type();
	}

	A_type withdrawLast() throw( Exception ) {
		return A_type();
	}

	integer_big getFirstTime() const throw( Exception ) {
		return integer_big( 0 );
	}

	integer_big getLastTime() const throw( Exception ) {
		return integer_big( 0 );
	}

	void empty() throw( Exception ) {}

	const Boolean isEmpty() const throw( Exception ) {
		return True;
	}

	const Boolean isNotEmpty() const throw( Exception ) {
		return False;
	}

	natural_size getQuantityOfObjects() const throw( Exception ) {
		return natural_size( 0 );
	}

	Proxy< osie::Event > &takeIsObjectAvailableEvent() throw() {
		return _eventRtr;
	}

	const ConstantProxy< osie::Event > &getIsObjectAvailableEvent() const throw() {
		return _eventCrtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_SynchronizedQueue() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< exception_SynchronizedQueue >;
	static exception_SynchronizedQueue *createInstance() throw() {
		return new exception_SynchronizedQueue< A_type >;
	}

private:
	exception_SynchronizedQueue() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< SynchronizedQueue< A_type > > createClone() const throw() {
		return Proxy< SynchronizedQueue< A_type > >::createUnique( this );
	}

private:
	exception_SynchronizedQueue( const exception_SynchronizedQueue & ) throw() {} // other

	const exception_SynchronizedQueue &operator =( const exception_SynchronizedQueue &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "exception_SynchronizedQueue::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Proxy< osie::Event > _eventRtr;
	ConstantProxy< osie::Event > _eventCrtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class A_type >
SynchronizedQueue< A_type > *SynchronizedQueue< A_type >::getNull() throw() {
	return null_SynchronizedQueue< A_type >::instance();
}

// static
template< class A_type >
SynchronizedQueue< A_type > *SynchronizedQueue< A_type >::getException() throw() {
	return exception_SynchronizedQueue< A_type >::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace mtf
} // namespace jmsf
