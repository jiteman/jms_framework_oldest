#include "null_ServiceFileArray.h"
#include "../../externals/data/ed_ServiceFile.h"
#include "jmsf/Container.hpp"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {


void null_ServiceFileArray::append( const ::jmsf::Proxy< externals::data::ed_ServiceFile > & ) throw( ::jmsf::Exception ) // serviceFile
{}

::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy, externals::data::ed_ServiceFile > > &null_ServiceFileArray::getAccessToServiceFiles() throw( ::jmsf::Exception ) {
	return _serviceFiles;
}

void null_ServiceFileArray::clearExpired() throw( ::jmsf::Exception )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ServiceFileArray::~null_ServiceFileArray() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ServiceFileArray *null_ServiceFileArray::createInstance() throw() {
	return new null_ServiceFileArray;
}

null_ServiceFileArray::null_ServiceFileArray() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ServiceFileArray > null_ServiceFileArray::createClone() const throw() {
	return ::jmsf::Proxy< ServiceFileArray >::createUnique( this );
}

null_ServiceFileArray::null_ServiceFileArray( const null_ServiceFileArray & ) throw() // other
{}

const null_ServiceFileArray &null_ServiceFileArray::operator =( const null_ServiceFileArray &other ) throw() {
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
