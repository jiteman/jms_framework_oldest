#include "null_NewKeyDispatcher.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_NewKeyDispatcher::~null_NewKeyDispatcher() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_NewKeyDispatcher *null_NewKeyDispatcher::createInstance() throw() {
	return new null_NewKeyDispatcher;
}

null_NewKeyDispatcher::null_NewKeyDispatcher() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< NewKeyDispatcher > null_NewKeyDispatcher::createClone() const throw() {
	return ::jmsf::Proxy< NewKeyDispatcher >::createUnique( this );
}

null_NewKeyDispatcher::null_NewKeyDispatcher( const null_NewKeyDispatcher & ) throw() // other
{}

const null_NewKeyDispatcher &null_NewKeyDispatcher::operator =( const null_NewKeyDispatcher &other ) throw() {
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
