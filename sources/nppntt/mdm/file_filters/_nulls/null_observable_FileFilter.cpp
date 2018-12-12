#include "null_observable_FileFilter.h"

#include "../../externals/data/ed_FileFilter.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace file_filters {
namespace nulls {


::jmsf::Proxy< externals::data::ed_FileFilter > null_observable_FileFilter::getOneselfFileFilter() throw() {
	return _fileFilter.getWeak();
}

const ::jmsf::Proxy< externals::data::ed_FileFilter > null_observable_FileFilter::getFileFilter() const throw() {
	return _fileFilter.getWeak();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_observable_FileFilter::~null_observable_FileFilter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_observable_FileFilter *null_observable_FileFilter::createInstance() throw() {
	return new null_observable_FileFilter;
}

null_observable_FileFilter::null_observable_FileFilter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< observable_FileFilter > null_observable_FileFilter::createClone() const throw() {
	return ::jmsf::Proxy< observable_FileFilter >::createUnique( this );
}

null_observable_FileFilter::null_observable_FileFilter( const null_observable_FileFilter & ) throw() // other
{}

const null_observable_FileFilter &null_observable_FileFilter::operator =( const null_observable_FileFilter &other ) throw() {
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
