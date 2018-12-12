#include "null_PreliminaryVoiceFileAndKeyMatchFinder.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_PreliminaryVoiceFileAndKeyMatchFinder::~null_PreliminaryVoiceFileAndKeyMatchFinder() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_PreliminaryVoiceFileAndKeyMatchFinder *null_PreliminaryVoiceFileAndKeyMatchFinder::createInstance() throw() {
	return new null_PreliminaryVoiceFileAndKeyMatchFinder;
}

null_PreliminaryVoiceFileAndKeyMatchFinder::null_PreliminaryVoiceFileAndKeyMatchFinder() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< PreliminaryVoiceFileAndKeyMatchFinder > null_PreliminaryVoiceFileAndKeyMatchFinder::createClone() const throw() {
	return ::jmsf::Proxy< PreliminaryVoiceFileAndKeyMatchFinder >::createUnique( this );
}

null_PreliminaryVoiceFileAndKeyMatchFinder::null_PreliminaryVoiceFileAndKeyMatchFinder( const null_PreliminaryVoiceFileAndKeyMatchFinder & ) throw() // other
{}

const null_PreliminaryVoiceFileAndKeyMatchFinder &null_PreliminaryVoiceFileAndKeyMatchFinder::operator =( const null_PreliminaryVoiceFileAndKeyMatchFinder &other ) throw() {
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
