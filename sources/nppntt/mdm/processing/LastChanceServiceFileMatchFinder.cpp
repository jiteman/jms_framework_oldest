#include "LastChanceServiceFileMatchFinder.h"
#include "jmsf/mtf/mixins/mixin_null_Runnable.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace processing {

class null_LastChanceServiceFileMatchFinder :
	public LastChanceServiceFileMatchFinder,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_LastChanceServiceFileMatchFinder >
{

public:
	// virtuals LastChanceServiceFileMatchFinder
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_LastChanceServiceFileMatchFinder() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_LastChanceServiceFileMatchFinder >;
	static null_LastChanceServiceFileMatchFinder *createInstance() throw() {
		return new null_LastChanceServiceFileMatchFinder;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_LastChanceServiceFileMatchFinder() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< LastChanceServiceFileMatchFinder > createClone() const throw() {
		return ::jmsf::Proxy< LastChanceServiceFileMatchFinder >::createUnique( this );
	}

private:
	null_LastChanceServiceFileMatchFinder( const null_LastChanceServiceFileMatchFinder & ) throw() {} // other
	
	const null_LastChanceServiceFileMatchFinder &operator =( const null_LastChanceServiceFileMatchFinder &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_LastChanceServiceFileMatchFinder::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_LastChanceServiceFileMatchFinder :
	public LastChanceServiceFileMatchFinder,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_LastChanceServiceFileMatchFinder > {

public:
	// virtuals LastChanceServiceFileMatchFinder
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_LastChanceServiceFileMatchFinder() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_LastChanceServiceFileMatchFinder >;
	static exception_LastChanceServiceFileMatchFinder *createInstance() throw() {
		return new exception_LastChanceServiceFileMatchFinder;
	}

private:
	exception_LastChanceServiceFileMatchFinder() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< LastChanceServiceFileMatchFinder > createClone() const throw() {
		return ::jmsf::Proxy< LastChanceServiceFileMatchFinder >::createUnique( this );
	}

private:
	exception_LastChanceServiceFileMatchFinder( const exception_LastChanceServiceFileMatchFinder & ) throw() {} // other

	const exception_LastChanceServiceFileMatchFinder &operator =( const exception_LastChanceServiceFileMatchFinder &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_LastChanceServiceFileMatchFinder::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
LastChanceServiceFileMatchFinder *LastChanceServiceFileMatchFinder::getNull() throw() {
	return null_LastChanceServiceFileMatchFinder::instance();
}

// static
LastChanceServiceFileMatchFinder *LastChanceServiceFileMatchFinder::getException() throw() {
	return exception_LastChanceServiceFileMatchFinder::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace processing
} // namespace mdm
} // namespace nppntt
