#include "null_NewServiceFileDispatcher.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_NewServiceFileDispatcher::~null_NewServiceFileDispatcher() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_NewServiceFileDispatcher *null_NewServiceFileDispatcher::createInstance() throw() {
	return new null_NewServiceFileDispatcher;
}

null_NewServiceFileDispatcher::null_NewServiceFileDispatcher() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< NewServiceFileDispatcher > null_NewServiceFileDispatcher::createClone() const throw() {
	return ::jmsf::Proxy< NewServiceFileDispatcher >::createUnique( this );
}

null_NewServiceFileDispatcher::null_NewServiceFileDispatcher( const null_NewServiceFileDispatcher & ) throw() // other
{}

const null_NewServiceFileDispatcher &null_NewServiceFileDispatcher::operator =( const null_NewServiceFileDispatcher &other ) throw() {
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
