#include "null_ExternalHardware.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ExternalHardware::~null_ExternalHardware() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ExternalHardware *null_ExternalHardware::createInstance() throw() {
	return new null_ExternalHardware;
}

null_ExternalHardware::null_ExternalHardware() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ExternalHardware > null_ExternalHardware::createClone() const throw() {
	return ::jmsf::Proxy< ExternalHardware >::createUnique( this );
}

null_ExternalHardware::null_ExternalHardware( const null_ExternalHardware & ) throw() // other
{}

const null_ExternalHardware &null_ExternalHardware::operator =( const null_ExternalHardware &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
