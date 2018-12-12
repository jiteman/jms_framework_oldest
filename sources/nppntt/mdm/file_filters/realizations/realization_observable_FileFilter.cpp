#include "realization_observable_FileFilter.h"

#include "../../externals/data/ed_FileFilter.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace file_filters {
namespace realizations {


::jmsf::Proxy< externals::data::ed_FileFilter > &realization_observable_FileFilter::takeFileFilter() throw() {
	return _fileFilter;
}

const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &realization_observable_FileFilter::getFileFilter() const throw() {
	return _constantFileFilter;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_observable_FileFilter::~realization_observable_FileFilter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_observable_FileFilter::realization_observable_FileFilter(
	const ::jmsf::Proxy< externals::data::ed_FileFilter > &fileFilter ) throw()
	:
		_fileFilter( fileFilter )
{
	_constantFileFilter = _fileFilter.getWeakConstant();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< observable_FileFilter > realization_observable_FileFilter::createClone() const throw() {
	return ::jmsf::Proxy< observable_FileFilter >::createUnique( new realization_observable_FileFilter( *this ) );
}

realization_observable_FileFilter::realization_observable_FileFilter( const realization_observable_FileFilter & ) throw() // other
{}

const realization_observable_FileFilter &realization_observable_FileFilter::operator =( const realization_observable_FileFilter &other ) throw() {
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
