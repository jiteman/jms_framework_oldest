#include "null_RecurrentVoiceFileAndKeyMatchFinder.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_RecurrentVoiceFileAndKeyMatchFinder::~null_RecurrentVoiceFileAndKeyMatchFinder() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_RecurrentVoiceFileAndKeyMatchFinder *null_RecurrentVoiceFileAndKeyMatchFinder::createInstance() throw() {
	return new null_RecurrentVoiceFileAndKeyMatchFinder;
}

null_RecurrentVoiceFileAndKeyMatchFinder::null_RecurrentVoiceFileAndKeyMatchFinder() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< RecurrentVoiceFileAndKeyMatchFinder > null_RecurrentVoiceFileAndKeyMatchFinder::createClone() const throw() {
	return ::jmsf::Proxy< RecurrentVoiceFileAndKeyMatchFinder >::createUnique( this );
}

null_RecurrentVoiceFileAndKeyMatchFinder::null_RecurrentVoiceFileAndKeyMatchFinder( const null_RecurrentVoiceFileAndKeyMatchFinder & ) throw() // other
{}

const null_RecurrentVoiceFileAndKeyMatchFinder &null_RecurrentVoiceFileAndKeyMatchFinder::operator =( const null_RecurrentVoiceFileAndKeyMatchFinder &other ) throw() {
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
