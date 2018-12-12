#include "ImmediateVoiceFileAndKeyPairVerifier.h"
#include "jmsf/mtf/mixins/mixin_null_Runnable.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace processing {

class null_ImmediateVoiceFileAndKeyPairVerifier :
	public ImmediateVoiceFileAndKeyPairVerifier,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ImmediateVoiceFileAndKeyPairVerifier >
{

public:
	// virtuals ImmediateVoiceFileAndKeyPairVerifier
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ImmediateVoiceFileAndKeyPairVerifier() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ImmediateVoiceFileAndKeyPairVerifier >;
	static null_ImmediateVoiceFileAndKeyPairVerifier *createInstance() throw() {
		return new null_ImmediateVoiceFileAndKeyPairVerifier;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ImmediateVoiceFileAndKeyPairVerifier() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ImmediateVoiceFileAndKeyPairVerifier > createClone() const throw() {
		return ::jmsf::Proxy< ImmediateVoiceFileAndKeyPairVerifier >::createUnique( this );
	}

private:
	null_ImmediateVoiceFileAndKeyPairVerifier( const null_ImmediateVoiceFileAndKeyPairVerifier & ) throw() {} // other
	
	const null_ImmediateVoiceFileAndKeyPairVerifier &operator =( const null_ImmediateVoiceFileAndKeyPairVerifier &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ImmediateVoiceFileAndKeyPairVerifier::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_ImmediateVoiceFileAndKeyPairVerifier :
	public ImmediateVoiceFileAndKeyPairVerifier,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ImmediateVoiceFileAndKeyPairVerifier > {

public:
	// virtuals ImmediateVoiceFileAndKeyPairVerifier
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ImmediateVoiceFileAndKeyPairVerifier() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ImmediateVoiceFileAndKeyPairVerifier >;
	static exception_ImmediateVoiceFileAndKeyPairVerifier *createInstance() throw() {
		return new exception_ImmediateVoiceFileAndKeyPairVerifier;
	}

private:
	exception_ImmediateVoiceFileAndKeyPairVerifier() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ImmediateVoiceFileAndKeyPairVerifier > createClone() const throw() {
		return ::jmsf::Proxy< ImmediateVoiceFileAndKeyPairVerifier >::createUnique( this );
	}

private:
	exception_ImmediateVoiceFileAndKeyPairVerifier( const exception_ImmediateVoiceFileAndKeyPairVerifier & ) throw() {} // other

	const exception_ImmediateVoiceFileAndKeyPairVerifier &operator =( const exception_ImmediateVoiceFileAndKeyPairVerifier &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ImmediateVoiceFileAndKeyPairVerifier::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
ImmediateVoiceFileAndKeyPairVerifier *ImmediateVoiceFileAndKeyPairVerifier::getNull() throw() {
	return null_ImmediateVoiceFileAndKeyPairVerifier::instance();
}

// static
ImmediateVoiceFileAndKeyPairVerifier *ImmediateVoiceFileAndKeyPairVerifier::getException() throw() {
	return exception_ImmediateVoiceFileAndKeyPairVerifier::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace processing
} // namespace mdm
} // namespace nppntt
