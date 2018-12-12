#include "NewVoiceFileDispatcher.h"
#include "jmsf/mtf/mixins/mixin_null_Runnable.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace processing {

class null_NewVoiceFileDispatcher :
	public NewVoiceFileDispatcher,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_NewVoiceFileDispatcher >
{

public:
	// virtuals NewVoiceFileDispatcher
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_NewVoiceFileDispatcher() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_NewVoiceFileDispatcher >;
	static null_NewVoiceFileDispatcher *createInstance() throw() {
		return new null_NewVoiceFileDispatcher;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_NewVoiceFileDispatcher() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< NewVoiceFileDispatcher > createClone() const throw() {
		return ::jmsf::Proxy< NewVoiceFileDispatcher >::createUnique( this );
	}

private:
	null_NewVoiceFileDispatcher( const null_NewVoiceFileDispatcher & ) throw() {} // other
	
	const null_NewVoiceFileDispatcher &operator =( const null_NewVoiceFileDispatcher &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_NewVoiceFileDispatcher::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_NewVoiceFileDispatcher :
	public NewVoiceFileDispatcher,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_NewVoiceFileDispatcher > {

public:
	// virtuals NewVoiceFileDispatcher
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_NewVoiceFileDispatcher() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_NewVoiceFileDispatcher >;
	static exception_NewVoiceFileDispatcher *createInstance() throw() {
		return new exception_NewVoiceFileDispatcher;
	}

private:
	exception_NewVoiceFileDispatcher() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< NewVoiceFileDispatcher > createClone() const throw() {
		return ::jmsf::Proxy< NewVoiceFileDispatcher >::createUnique( this );
	}

private:
	exception_NewVoiceFileDispatcher( const exception_NewVoiceFileDispatcher & ) throw() {} // other

	const exception_NewVoiceFileDispatcher &operator =( const exception_NewVoiceFileDispatcher &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_NewVoiceFileDispatcher::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
NewVoiceFileDispatcher *NewVoiceFileDispatcher::getNull() throw() {
	return null_NewVoiceFileDispatcher::instance();
}

// static
NewVoiceFileDispatcher *NewVoiceFileDispatcher::getException() throw() {
	return exception_NewVoiceFileDispatcher::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace processing
} // namespace mdm
} // namespace nppntt
