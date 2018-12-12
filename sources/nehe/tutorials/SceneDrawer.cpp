#include "SceneDrawer.h"


#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"


namespace nehe {
namespace tutorials {


class null_SceneDrawer :
	public SceneDrawer,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_SceneDrawer >
{

public:
	// virtuals SceneDrawer
	bool isInitialized() const throw() { return false; }
	bool prepare() const throw() { return false; }
	bool draw() const throw() { return false; }
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_SceneDrawer() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_SceneDrawer >;
	static null_SceneDrawer *createInstance() throw() {
		return new null_SceneDrawer;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_SceneDrawer() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< SceneDrawer > createClone() const throw() {
		return ::jmsf::Proxy< SceneDrawer >::createNonlinkedFor( this );
	}

private:
	null_SceneDrawer( const null_SceneDrawer & ) throw() {} // other
	
	const null_SceneDrawer &operator =( const null_SceneDrawer &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::never_violate_copy_prohibition( "null_SceneDrawer::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_SceneDrawer :
	public SceneDrawer,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_SceneDrawer > {

public:
	// virtuals ExternalSoftware
	bool isInitialized() const throw() { return false; }
	bool prepare() const throw() { return false; }
	bool draw() const throw() { return false; }
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_SceneDrawer() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_SceneDrawer >;
	static exception_SceneDrawer *createInstance() throw() {
		return new exception_SceneDrawer;
	}

private:
	exception_SceneDrawer() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< SceneDrawer > createClone() const throw() {
		return ::jmsf::Proxy< SceneDrawer >::createNonlinkedFor( this );
	}

private:
	exception_SceneDrawer( const exception_SceneDrawer & ) throw() {} // other

	const exception_SceneDrawer &operator =( const exception_SceneDrawer &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::never_violate_copy_prohibition( "exception_SceneDrawer::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
SceneDrawer *SceneDrawer::getNull() throw() {
	return null_SceneDrawer::instance();
}

// static
SceneDrawer *SceneDrawer::getException() throw() {
	return exception_SceneDrawer::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



} // namespace tutorials
} // namespace nehe
