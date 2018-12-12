#include "NewServiceFileDispatcher.h"
#include "jmsf/mtf/mixins/mixin_null_Runnable.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace processing {

class null_NewServiceFileDispatcher :
	public NewServiceFileDispatcher,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_NewServiceFileDispatcher >
{

public:
	// virtuals NewServiceFileDispatcher
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_NewServiceFileDispatcher() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_NewServiceFileDispatcher >;
	static null_NewServiceFileDispatcher *createInstance() throw() {
		return new null_NewServiceFileDispatcher;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_NewServiceFileDispatcher() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< NewServiceFileDispatcher > createClone() const throw() {
		return ::jmsf::Proxy< NewServiceFileDispatcher >::createUnique( this );
	}

private:
	null_NewServiceFileDispatcher( const null_NewServiceFileDispatcher & ) throw() {} // other
	
	const null_NewServiceFileDispatcher &operator =( const null_NewServiceFileDispatcher &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_NewServiceFileDispatcher::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_NewServiceFileDispatcher :
	public NewServiceFileDispatcher,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_NewServiceFileDispatcher > {

public:
	// virtuals NewServiceFileDispatcher
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_NewServiceFileDispatcher() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_NewServiceFileDispatcher >;
	static exception_NewServiceFileDispatcher *createInstance() throw() {
		return new exception_NewServiceFileDispatcher;
	}

private:
	exception_NewServiceFileDispatcher() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< NewServiceFileDispatcher > createClone() const throw() {
		return ::jmsf::Proxy< NewServiceFileDispatcher >::createUnique( this );
	}

private:
	exception_NewServiceFileDispatcher( const exception_NewServiceFileDispatcher & ) throw() {} // other

	const exception_NewServiceFileDispatcher &operator =( const exception_NewServiceFileDispatcher &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_NewServiceFileDispatcher::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
NewServiceFileDispatcher *NewServiceFileDispatcher::getNull() throw() {
	return null_NewServiceFileDispatcher::instance();
}

// static
NewServiceFileDispatcher *NewServiceFileDispatcher::getException() throw() {
	return exception_NewServiceFileDispatcher::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace processing
} // namespace mdm
} // namespace nppntt
