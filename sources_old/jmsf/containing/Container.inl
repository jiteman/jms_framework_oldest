#pragma once


#include "Container.hpp"

#include "jmsf/patterning/mixing/mixin_null_Object.h"
#include "jmsf/patterning/mixing/mixin_exception_Object.h"
#include "jmsf/patterning/Singleton.inl"
#include "jmsf/pointing/Proxy.inl"
#include "jmsf/validating/Should.h"


namespace jmsf {
namespace containing {


template< class A_type >
class null_Container :
	public Container< A_type >,
	public ::jmsf::patterning::mixing::mixin_null_Object,
	public ::jmsf::patterning::Singleton< null_Container< A_type > >
{

public: // common getters
	// virtuals Container
	typing::Boolean isEmpty() const throw() { return typing::True; }
	typing::Boolean isNotEmpty() const throw() { return typing::False; }
	typing::Natural getQuantityOfElements() const throw() { return typing::Natural( 0 ); }
	//~virtuals Container

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // appending modifiers
	// virtuals Container
	void appendToBegin( const A_type & ) throw() {} // object
	void appendToEnd( const A_type & ) throw() {} // object
	//~virtuals Container

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // factories
	// virtuals Container
	pointing::Proxy< Iterator< A_type > > createIteratorAtBegin() throw() { return pointing::Proxy< Iterator< A_type > >(); }
	pointing::Proxy< Iterator< A_type > > createIteratorAtEnd() throw() { return pointing::Proxy< Iterator< A_type > >(); }
	pointing::Proxy< Iterator< A_type > > createIteratorAt( typing::Natural  ) throw( validating::Exception ) { return pointing::Proxy< Iterator< A_type > >(); } // index

	pointing::Proxy< ConstantIterator< A_type > > createConstantIteratorAtBegin() throw() { return pointing::Proxy< ConstantIterator< A_type > >(); }
	pointing::Proxy< ConstantIterator< A_type > > createConstantIteratorAtEnd() throw() { return pointing::Proxy< ConstantIterator< A_type > >(); }
	pointing::Proxy< ConstantIterator< A_type > > createConstantIteratorAt( typing::Natural  ) throw( validating::Exception ) { return pointing::Proxy< ConstantIterator< A_type > >(); } // index
	//~virtuals Container

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_Container() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::patterning::Singleton< null_Container< A_type > >;
	static null_Container *createInstance() throw() {
		return new null_Container;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_Container() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< Container > createClone() const throw() {
		return ::jmsf::pointing::Proxy< Container >::createNonlinkedFor( this );
	}

private:
	null_Container( const null_Container & ) throw() {} // other
	
	const null_Container &operator =( const null_Container &other ) throw( ::jmsf::validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::validating::Should::neverViolateCopyingProhibition( "null_Container< A_type >::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _referenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

template< class A_type >
class exception_Container :
	public Container< A_type >,
	public ::jmsf::patterning::mixing::mixin_exception_Object,
	public ::jmsf::patterning::Singleton< exception_Container< A_type > >
{

public: // common getters
	// virtuals Container
	typing::Boolean isEmpty() const throw() { return typing::True; }
	typing::Boolean isNotEmpty() const throw() { return typing::False; }
	typing::Natural getQuantityOfElements() const throw() { return typing::Natural( 0 ); }
	//~virtuals Container

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // appending modifiers
	// virtuals Container
	void appendToBegin( const A_type & ) throw() {} // object
	void appendToEnd( const A_type & ) throw() {} // object
	//~virtuals Container

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // factories
	// virtuals Container
	pointing::Proxy< Iterator< A_type > > createIteratorAtBegin() throw() { return pointing::Proxy< Iterator< A_type > >(); }
	pointing::Proxy< Iterator< A_type > > createIteratorAtEnd() throw() { return pointing::Proxy< Iterator< A_type > >(); }
	pointing::Proxy< Iterator< A_type > > createIteratorAt( typing::Natural  ) throw( validating::Exception ) { return pointing::Proxy< Iterator< A_type > >(); } // index

	pointing::Proxy< ConstantIterator< A_type > > createConstantIteratorAtBegin() throw() { return pointing::Proxy< ConstantIterator< A_type > >(); }
	pointing::Proxy< ConstantIterator< A_type > > createConstantIteratorAtEnd() throw() { return pointing::Proxy< ConstantIterator< A_type > >(); }
	pointing::Proxy< ConstantIterator< A_type > > createConstantIteratorAt( typing::Natural  ) throw( validating::Exception ) { return pointing::Proxy< ConstantIterator< A_type > >(); } // index
	//~virtuals Container

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_Container() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::patterning::Singleton< exception_Container< A_type > >;
	static exception_Container *createInstance() throw() {
		return new exception_Container;
	}

private:
	exception_Container() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< Container > createClone() const throw() {
		return ::jmsf::pointing::Proxy< Container >::createNonlinkedFor( this );
	}

private:
	exception_Container( const exception_Container & ) throw() {} // other

	const exception_Container &operator =( const exception_Container &other ) throw( ::jmsf::validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::validating::Should::neverViolateCopyingProhibition( "exception_Container< A_type >::operator =()", FILE_AND_LINE );
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
Container< A_type > *Container< A_type >::getNull() throw() {
	return null_Container< A_type >::instance();
}

// static
template< class A_type >
Container< A_type > *Container< A_type >::getException() throw() {
	return exception_Container< A_type >::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace containing
} // namespace jmsf
