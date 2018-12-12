#include "RecurrentVoiceFileAndKeyMatchFinder.h"
#include "jmsf/mtf/mixins/mixin_null_Runnable.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace processing {

class null_RecurrentVoiceFileAndKeyMatchFinder :
	public RecurrentVoiceFileAndKeyMatchFinder,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_RecurrentVoiceFileAndKeyMatchFinder >
{

public:
	// virtuals RecurrentVoiceFileAndKeyMatchFinder
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_RecurrentVoiceFileAndKeyMatchFinder() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_RecurrentVoiceFileAndKeyMatchFinder >;
	static null_RecurrentVoiceFileAndKeyMatchFinder *createInstance() throw() {
		return new null_RecurrentVoiceFileAndKeyMatchFinder;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_RecurrentVoiceFileAndKeyMatchFinder() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< RecurrentVoiceFileAndKeyMatchFinder > createClone() const throw() {
		return ::jmsf::Proxy< RecurrentVoiceFileAndKeyMatchFinder >::createUnique( this );
	}

private:
	null_RecurrentVoiceFileAndKeyMatchFinder( const null_RecurrentVoiceFileAndKeyMatchFinder & ) throw() {} // other
	
	const null_RecurrentVoiceFileAndKeyMatchFinder &operator =( const null_RecurrentVoiceFileAndKeyMatchFinder &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_RecurrentVoiceFileAndKeyMatchFinder::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_RecurrentVoiceFileAndKeyMatchFinder :
	public RecurrentVoiceFileAndKeyMatchFinder,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_RecurrentVoiceFileAndKeyMatchFinder > {

public:
	// virtuals RecurrentVoiceFileAndKeyMatchFinder
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_RecurrentVoiceFileAndKeyMatchFinder() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_RecurrentVoiceFileAndKeyMatchFinder >;
	static exception_RecurrentVoiceFileAndKeyMatchFinder *createInstance() throw() {
		return new exception_RecurrentVoiceFileAndKeyMatchFinder;
	}

private:
	exception_RecurrentVoiceFileAndKeyMatchFinder() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< RecurrentVoiceFileAndKeyMatchFinder > createClone() const throw() {
		return ::jmsf::Proxy< RecurrentVoiceFileAndKeyMatchFinder >::createUnique( this );
	}

private:
	exception_RecurrentVoiceFileAndKeyMatchFinder( const exception_RecurrentVoiceFileAndKeyMatchFinder & ) throw() {} // other

	const exception_RecurrentVoiceFileAndKeyMatchFinder &operator =( const exception_RecurrentVoiceFileAndKeyMatchFinder &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_RecurrentVoiceFileAndKeyMatchFinder::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
RecurrentVoiceFileAndKeyMatchFinder *RecurrentVoiceFileAndKeyMatchFinder::getNull() throw() {
	return null_RecurrentVoiceFileAndKeyMatchFinder::instance();
}

// static
RecurrentVoiceFileAndKeyMatchFinder *RecurrentVoiceFileAndKeyMatchFinder::getException() throw() {
	return exception_RecurrentVoiceFileAndKeyMatchFinder::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace processing
} // namespace mdm
} // namespace nppntt
