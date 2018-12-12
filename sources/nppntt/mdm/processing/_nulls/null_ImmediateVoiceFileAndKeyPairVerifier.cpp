#include "null_ImmediateVoiceFileAndKeyPairVerifier.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ImmediateVoiceFileAndKeyPairVerifier::~null_ImmediateVoiceFileAndKeyPairVerifier() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ImmediateVoiceFileAndKeyPairVerifier *null_ImmediateVoiceFileAndKeyPairVerifier::createInstance() throw() {
	return new null_ImmediateVoiceFileAndKeyPairVerifier;
}

null_ImmediateVoiceFileAndKeyPairVerifier::null_ImmediateVoiceFileAndKeyPairVerifier() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ImmediateVoiceFileAndKeyPairVerifier > null_ImmediateVoiceFileAndKeyPairVerifier::createClone() const throw() {
	return ::jmsf::Proxy< ImmediateVoiceFileAndKeyPairVerifier >::createUnique( this );
}

null_ImmediateVoiceFileAndKeyPairVerifier::null_ImmediateVoiceFileAndKeyPairVerifier( const null_ImmediateVoiceFileAndKeyPairVerifier & ) throw() // other
{}

const null_ImmediateVoiceFileAndKeyPairVerifier &null_ImmediateVoiceFileAndKeyPairVerifier::operator =( const null_ImmediateVoiceFileAndKeyPairVerifier &other ) throw() {
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
