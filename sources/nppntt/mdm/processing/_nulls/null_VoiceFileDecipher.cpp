#include "null_VoiceFileDecipher.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_VoiceFileDecipher::~null_VoiceFileDecipher() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_VoiceFileDecipher *null_VoiceFileDecipher::createInstance() throw() {
	return new null_VoiceFileDecipher;
}

null_VoiceFileDecipher::null_VoiceFileDecipher() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< VoiceFileDecipher > null_VoiceFileDecipher::createClone() const throw() {
	return ::jmsf::Proxy< VoiceFileDecipher >::createUnique( this );
}

null_VoiceFileDecipher::null_VoiceFileDecipher( const null_VoiceFileDecipher & ) throw() // other
{}

const null_VoiceFileDecipher &null_VoiceFileDecipher::operator =( const null_VoiceFileDecipher &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
}
