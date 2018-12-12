#include "null_ServiceFileDeleter.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ServiceFileDeleter::~null_ServiceFileDeleter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ServiceFileDeleter *null_ServiceFileDeleter::createInstance() throw() {
	return new null_ServiceFileDeleter;
}

null_ServiceFileDeleter::null_ServiceFileDeleter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ServiceFileDeleter > null_ServiceFileDeleter::createClone() const throw() {
	return ::jmsf::Proxy< ServiceFileDeleter >::createUnique( this );
}

null_ServiceFileDeleter::null_ServiceFileDeleter( const null_ServiceFileDeleter & ) throw() // other
{}

const null_ServiceFileDeleter &null_ServiceFileDeleter::operator =( const null_ServiceFileDeleter &other ) throw() {
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
