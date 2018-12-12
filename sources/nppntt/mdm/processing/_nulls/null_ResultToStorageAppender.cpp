#include "null_ResultToStorageAppender.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ResultToStorageAppender::~null_ResultToStorageAppender() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ResultToStorageAppender *null_ResultToStorageAppender::createInstance() throw() {
	return new null_ResultToStorageAppender;
}

null_ResultToStorageAppender::null_ResultToStorageAppender() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ResultToStorageAppender > null_ResultToStorageAppender::createClone() const throw() {
	return ::jmsf::Proxy< ResultToStorageAppender >::createUnique( this );
}

null_ResultToStorageAppender::null_ResultToStorageAppender( const null_ResultToStorageAppender & ) throw() // other
{}

const null_ResultToStorageAppender &null_ResultToStorageAppender::operator =( const null_ResultToStorageAppender &other ) throw() {
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
