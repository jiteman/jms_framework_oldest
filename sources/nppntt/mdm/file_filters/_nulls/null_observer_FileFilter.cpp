#include "null_observer_FileFilter.h"

#include "../../externals/data/ed_FileFilter.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace file_filters {
namespace nulls {


const ::jmsf::Proxy< externals::data::ed_FileFilter > null_observer_FileFilter::getFileFilter() const throw() {
	return _fileFilter;
}

void null_observer_FileFilter::update() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_observer_FileFilter::~null_observer_FileFilter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_observer_FileFilter *null_observer_FileFilter::createInstance() throw() {
	return new null_observer_FileFilter;
}

null_observer_FileFilter::null_observer_FileFilter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< observer_FileFilter > null_observer_FileFilter::createClone() const throw() {
	return ::jmsf::Proxy< observer_FileFilter >::createUnique( this );
}

null_observer_FileFilter::null_observer_FileFilter( const null_observer_FileFilter & ) throw() // other
{}

const null_observer_FileFilter &null_observer_FileFilter::operator =( const null_observer_FileFilter &other ) throw() {
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
