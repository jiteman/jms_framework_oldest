#include "null_NewVoiceFileDispatcher.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_NewVoiceFileDispatcher::~null_NewVoiceFileDispatcher() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_NewVoiceFileDispatcher *null_NewVoiceFileDispatcher::createInstance() throw() {
	return new null_NewVoiceFileDispatcher;
}

null_NewVoiceFileDispatcher::null_NewVoiceFileDispatcher() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< NewVoiceFileDispatcher > null_NewVoiceFileDispatcher::createClone() const throw() {
	return ::jmsf::Proxy< NewVoiceFileDispatcher >::createUnique( this );
}

null_NewVoiceFileDispatcher::null_NewVoiceFileDispatcher( const null_NewVoiceFileDispatcher & ) throw() // other
{}

const null_NewVoiceFileDispatcher &null_NewVoiceFileDispatcher::operator =( const null_NewVoiceFileDispatcher &other ) throw() {
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
