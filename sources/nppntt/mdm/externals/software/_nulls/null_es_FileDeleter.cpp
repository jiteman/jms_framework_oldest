#include "null_es_FileDeleter.h"
#include "../../others/abstractFileDescriptor.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace nulls {


void null_es_FileDeleter::deleteFile(
		::jmsf::Pointer< FileDescriptorData > ,
		::jmsf::Pointer< AppliedData >  ) const throw() // fileData, appliedData, isDeletedFromDecipher
{}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_es_FileDeleter::~null_es_FileDeleter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_es_FileDeleter *null_es_FileDeleter::createInstance() throw() {
	return new null_es_FileDeleter;
}

null_es_FileDeleter::null_es_FileDeleter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< es_FileDeleter > null_es_FileDeleter::createClone() const throw() {
	return ::jmsf::Proxy< es_FileDeleter >::createUnique( this );
}

null_es_FileDeleter::null_es_FileDeleter( const null_es_FileDeleter & ) throw() // other
{}

const null_es_FileDeleter &null_es_FileDeleter::operator =( const null_es_FileDeleter &other ) throw() {
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
}
