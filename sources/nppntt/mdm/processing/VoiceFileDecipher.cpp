#include "VoiceFileDecipher.h"
#include "jmsf/mtf/mixins/mixin_null_Runnable.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace processing {

class null_VoiceFileDecipher :
	public VoiceFileDecipher,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_VoiceFileDecipher >
{

public:
	// virtuals VoiceFileDecipher
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_VoiceFileDecipher() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_VoiceFileDecipher >;
	static null_VoiceFileDecipher *createInstance() throw() {
		return new null_VoiceFileDecipher;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_VoiceFileDecipher() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< VoiceFileDecipher > createClone() const throw() {
		return ::jmsf::Proxy< VoiceFileDecipher >::createUnique( this );
	}

private:
	null_VoiceFileDecipher( const null_VoiceFileDecipher & ) throw() {} // other
	
	const null_VoiceFileDecipher &operator =( const null_VoiceFileDecipher &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_VoiceFileDecipher::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_VoiceFileDecipher :
	public VoiceFileDecipher,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_VoiceFileDecipher > {

public:
	// virtuals VoiceFileDecipher
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_VoiceFileDecipher() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_VoiceFileDecipher >;
	static exception_VoiceFileDecipher *createInstance() throw() {
		return new exception_VoiceFileDecipher;
	}

private:
	exception_VoiceFileDecipher() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< VoiceFileDecipher > createClone() const throw() {
		return ::jmsf::Proxy< VoiceFileDecipher >::createUnique( this );
	}

private:
	exception_VoiceFileDecipher( const exception_VoiceFileDecipher & ) throw() {} // other

	const exception_VoiceFileDecipher &operator =( const exception_VoiceFileDecipher &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_VoiceFileDecipher::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
VoiceFileDecipher *VoiceFileDecipher::getNull() throw() {
	return null_VoiceFileDecipher::instance();
}

// static
VoiceFileDecipher *VoiceFileDecipher::getException() throw() {
	return exception_VoiceFileDecipher::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace processing
} // namespace mdm
} // namespace nppntt
