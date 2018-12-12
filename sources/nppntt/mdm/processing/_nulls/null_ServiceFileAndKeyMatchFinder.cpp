#include "null_ServiceFileAndKeyMatchFinder.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ServiceFileAndKeyMatchFinder::~null_ServiceFileAndKeyMatchFinder() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ServiceFileAndKeyMatchFinder *null_ServiceFileAndKeyMatchFinder::createInstance() throw() {
	return new null_ServiceFileAndKeyMatchFinder;
}

null_ServiceFileAndKeyMatchFinder::null_ServiceFileAndKeyMatchFinder() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ServiceFileAndKeyMatchFinder > null_ServiceFileAndKeyMatchFinder::createClone() const throw() {
	return ::jmsf::Proxy< ServiceFileAndKeyMatchFinder >::createUnique( this );
}

null_ServiceFileAndKeyMatchFinder::null_ServiceFileAndKeyMatchFinder( const null_ServiceFileAndKeyMatchFinder & ) throw() // other
{}

const null_ServiceFileAndKeyMatchFinder &null_ServiceFileAndKeyMatchFinder::operator =( const null_ServiceFileAndKeyMatchFinder &other ) throw() {
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
