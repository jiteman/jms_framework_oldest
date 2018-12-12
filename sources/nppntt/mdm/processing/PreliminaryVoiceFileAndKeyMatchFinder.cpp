#include "PreliminaryVoiceFileAndKeyMatchFinder.h"
#include "jmsf/mtf/mixins/mixin_null_Runnable.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace processing {

class null_PreliminaryVoiceFileAndKeyMatchFinder :
	public PreliminaryVoiceFileAndKeyMatchFinder,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_PreliminaryVoiceFileAndKeyMatchFinder >
{

public:
	// virtuals PreliminaryVoiceFileAndKeyMatchFinder
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_PreliminaryVoiceFileAndKeyMatchFinder() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_PreliminaryVoiceFileAndKeyMatchFinder >;
	static null_PreliminaryVoiceFileAndKeyMatchFinder *createInstance() throw() {
		return new null_PreliminaryVoiceFileAndKeyMatchFinder;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_PreliminaryVoiceFileAndKeyMatchFinder() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< PreliminaryVoiceFileAndKeyMatchFinder > createClone() const throw() {
		return ::jmsf::Proxy< PreliminaryVoiceFileAndKeyMatchFinder >::createUnique( this );
	}

private:
	null_PreliminaryVoiceFileAndKeyMatchFinder( const null_PreliminaryVoiceFileAndKeyMatchFinder & ) throw() {} // other
	
	const null_PreliminaryVoiceFileAndKeyMatchFinder &operator =( const null_PreliminaryVoiceFileAndKeyMatchFinder &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_PreliminaryVoiceFileAndKeyMatchFinder::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_PreliminaryVoiceFileAndKeyMatchFinder :
	public PreliminaryVoiceFileAndKeyMatchFinder,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_PreliminaryVoiceFileAndKeyMatchFinder > {

public:
	// virtuals PreliminaryVoiceFileAndKeyMatchFinder
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_PreliminaryVoiceFileAndKeyMatchFinder() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_PreliminaryVoiceFileAndKeyMatchFinder >;
	static exception_PreliminaryVoiceFileAndKeyMatchFinder *createInstance() throw() {
		return new exception_PreliminaryVoiceFileAndKeyMatchFinder;
	}

private:
	exception_PreliminaryVoiceFileAndKeyMatchFinder() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< PreliminaryVoiceFileAndKeyMatchFinder > createClone() const throw() {
		return ::jmsf::Proxy< PreliminaryVoiceFileAndKeyMatchFinder >::createUnique( this );
	}

private:
	exception_PreliminaryVoiceFileAndKeyMatchFinder( const exception_PreliminaryVoiceFileAndKeyMatchFinder & ) throw() {} // other

	const exception_PreliminaryVoiceFileAndKeyMatchFinder &operator =( const exception_PreliminaryVoiceFileAndKeyMatchFinder &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_PreliminaryVoiceFileAndKeyMatchFinder::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
PreliminaryVoiceFileAndKeyMatchFinder *PreliminaryVoiceFileAndKeyMatchFinder::getNull() throw() {
	return null_PreliminaryVoiceFileAndKeyMatchFinder::instance();
}

// static
PreliminaryVoiceFileAndKeyMatchFinder *PreliminaryVoiceFileAndKeyMatchFinder::getException() throw() {
	return exception_PreliminaryVoiceFileAndKeyMatchFinder::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace processing
} // namespace mdm
} // namespace nppntt
