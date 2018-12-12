#include "null_VoiceFileDeleter.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_VoiceFileDeleter::~null_VoiceFileDeleter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_VoiceFileDeleter *null_VoiceFileDeleter::createInstance() throw() {
	return new null_VoiceFileDeleter;
}

null_VoiceFileDeleter::null_VoiceFileDeleter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< VoiceFileDeleter > null_VoiceFileDeleter::createClone() const throw() {
	return ::jmsf::Proxy< VoiceFileDeleter >::createUnique( this );
}

null_VoiceFileDeleter::null_VoiceFileDeleter( const null_VoiceFileDeleter & ) throw() // other
{}

const null_VoiceFileDeleter &null_VoiceFileDeleter::operator =( const null_VoiceFileDeleter &other ) throw() {
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
