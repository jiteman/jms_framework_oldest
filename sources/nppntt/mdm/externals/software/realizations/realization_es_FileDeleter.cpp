#include "realization_es_FileDeleter.h"
#include "../../others/abstractFilter.h"
#include "jmsf/Proxies.hpp"
#include "jmsf/Pointers.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace realizations {


void realization_es_FileDeleter::deleteFile( ::jmsf::Pointer< FileDescriptorData > fileData, ::jmsf::Pointer< AppliedData > appliedData ) const throw() {
	::deleteFile( fileData.get(), appliedData.get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_es_FileDeleter::~realization_es_FileDeleter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_es_FileDeleter::realization_es_FileDeleter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< es_FileDeleter > realization_es_FileDeleter::createClone() const throw() {
	return ::jmsf::Proxy< es_FileDeleter >::createUnique( new realization_es_FileDeleter( *this ) );
}

realization_es_FileDeleter::realization_es_FileDeleter( const realization_es_FileDeleter & ) throw() // other
{}

const realization_es_FileDeleter &realization_es_FileDeleter::operator =( const realization_es_FileDeleter &other ) throw() {
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
