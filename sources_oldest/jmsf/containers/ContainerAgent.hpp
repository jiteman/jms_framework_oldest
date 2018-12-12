#pragma once


#include "jmsf/Object.h"

#include "jmsf/Proxy.hxx"


namespace jmsf {
namespace containers {


template< class A_type >
class ContainerAgent :
	public virtual ::jmsf::Object
{

public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ContainerAgent *getNull() throw();
	static ContainerAgent *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< ContainerAgent > createClone() const throw() = 0;

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


namespace jmsf {
namespace containers {


template< class A_type >
class null_ContainerAgent :
	public ContainerAgent< A_type >,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ContainerAgent< A_type > >
{

public:
	// virtuals ContainerAgent
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ContainerAgent() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ContainerAgent< A_type > >;
	static null_ContainerAgent *createInstance() throw() {
		return new null_ContainerAgent;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ContainerAgent() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ContainerAgent > createClone() const throw() {
		return ::jmsf::Proxy< ContainerAgent >::createNonlinkedFor( this );
	}

private:
	null_ContainerAgent( const null_ContainerAgent & ) throw() {} // other
	
	const null_ContainerAgent &operator =( const null_ContainerAgent &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ContainerAgent< A_type >::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

template< class A_type >
class exception_ContainerAgent :
	public ContainerAgent< A_type >,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ContainerAgent< A_type > > {

public:
	// virtuals ExternalSoftware
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ContainerAgent() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ContainerAgent< A_type > >;
	static exception_ContainerAgent *createInstance() throw() {
		return new exception_ContainerAgent;
	}

private:
	exception_ContainerAgent() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ContainerAgent > createClone() const throw() {
		return ::jmsf::Proxy< ContainerAgent >::createNonlinkedFor( this );
	}

private:
	exception_ContainerAgent( const exception_ContainerAgent & ) throw() {} // other

	const exception_ContainerAgent &operator =( const exception_ContainerAgent &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ContainerAgent< A_type >::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< A_type >
ContainerAgent< A_type > *ContainerAgent< A_type >::getNull() throw() {
	return null_ContainerAgent< A_type >::instance();
}

// static
template< A_type >
ContainerAgent< A_type > *ContainerAgent< A_type >::getException() throw() {
	return exception_ContainerAgent< A_type >::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace containers
} // namespace jmsf
