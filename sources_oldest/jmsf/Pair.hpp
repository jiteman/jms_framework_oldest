#pragma once

#include "jmsf/Object.h"

#include "jmsf/Proxies.hxx"

namespace jmsf {

template< class A_first_type, class A_second_type >
class Pair :
	public virtual Object
{

public:
	virtual A_first_type &takeFirst() throw() = 0;
	virtual A_second_type &takeSecond() throw() = 0;

	virtual const A_first_type &getFirst() const throw() = 0;
	virtual const A_second_type &getSecond() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Pair *getNull() throw();
	static Pair *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual Proxy< Pair< A_first_type, A_second_type > > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace jmsf


#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace jmsf {

template< class A_first_type, class A_second_type >
class null_Pair :
	public Pair< A_first_type, A_second_type >,
	public mixins::mixin_null_Object,
	public Singleton< null_Pair< A_first_type, A_second_type > >
{

public:
	// virtuals	Pair< A_first_type, A_second_type >
	A_first_type &takeFirst() throw() {
		return _firstRtr;
	}

	A_second_type &takeSecond() throw() {
		return _secondRtr;
	}

	const A_first_type &getFirst() const throw() {
		return _firstRtr;
	}

	const A_second_type &getSecond() const throw() {
		return _secondRtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_Pair() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< null_Pair >;
	static null_Pair *createInstance() throw() {
		return new null_Pair< A_first_type, A_second_type >;
	}

private:
	null_Pair() throw()
		:
			_firstRtr( A_first_type() ),
			_secondRtr( A_second_type() )
	{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Pair< A_first_type, A_second_type > > createClone() const throw() {
		return Proxy< Pair< A_first_type, A_second_type > >::createUnique( this );
	}

private:
	null_Pair( const null_Pair & ) throw() {} // other

	const null_Pair &operator =( const null_Pair &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "null_Pair::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_first_type _firstRtr;
	A_second_type _secondRtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


template< class A_first_type, class A_second_type >
class exception_Pair :
	public Pair< A_first_type, A_second_type >,
	public mixins::mixin_exception_Object,
	public Singleton< exception_Pair< A_first_type, A_second_type > >
{

public:
	// virtuals	Pair< A_first_type, A_second_type >
	A_first_type &takeFirst() throw() {
		return _firstRtr;
	}

	A_second_type &takeSecond() throw() {
		return _secondRtr;
	}

	const A_first_type &getFirst() const throw() {
		return _firstRtr;
	}

	const A_second_type &getSecond() const throw() {
		return _secondRtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_Pair() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< exception_Pair >;
	static exception_Pair *createInstance() throw() {
		return _new exception_Pair< A_first_type, A_second_type >;
	}

private:
	exception_Pair() throw()
		:
			_firstRtr( A_first_type() ),
			_secondRtr( A_second_type() )
	{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Pair< A_first_type, A_second_type > > createClone() const throw() {
		return Proxy< Pair< A_first_type, A_second_type > >::createUnique( this );
	}

private:
	exception_Pair( const exception_Pair & ) throw() {} // other

	const exception_Pair &operator =( const exception_Pair &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "exception_Pair::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_first_type _firstRtr;
	A_second_type _secondRtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class A_first_type, class A_second_type >
Pair< A_first_type, A_second_type > *Pair< A_first_type, A_second_type >::getNull() throw() {
	return null_Pair< A_first_type, A_second_type >::instance();
}

// static
template< class A_first_type, class A_second_type >
Pair< A_first_type, A_second_type > *Pair< A_first_type, A_second_type >::getException() throw() {
	return exception_Pair< A_first_type, A_second_type >::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace jmsf
