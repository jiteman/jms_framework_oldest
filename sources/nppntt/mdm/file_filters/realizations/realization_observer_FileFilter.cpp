#include "realization_observer_FileFilter.h"
#include "../observable_FileFilter.h"
#include "../../externals/data/ed_FileFilter.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace file_filters {
namespace realizations {


const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &realization_observer_FileFilter::getFileFilter() const throw() {
	return _constantFileFilter;
}

void realization_observer_FileFilter::update() throw() {
	_fileFilter->takeMutex()->lock();
	_fileFilter->renew( _observableFileFilter->getFileFilter() );
	_fileFilter->takeMutex()->unlock();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_observer_FileFilter::~realization_observer_FileFilter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_observer_FileFilter::realization_observer_FileFilter(
	const ::jmsf::Proxy< observable_FileFilter > &observableFileFilter,
	const ::jmsf::Proxy< externals::data::ed_FileFilter > &fileFilter ) throw()
	:
		_observableFileFilter( observableFileFilter ),
		_fileFilter( fileFilter )
{
	_constantFileFilter = _fileFilter.getWeakConstant();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< observer_FileFilter > realization_observer_FileFilter::createClone() const throw() {
	return ::jmsf::Proxy< observer_FileFilter >::createUnique( new realization_observer_FileFilter( *this ) );
}

realization_observer_FileFilter::realization_observer_FileFilter( const realization_observer_FileFilter & ) throw() // other
{}

const realization_observer_FileFilter &realization_observer_FileFilter::operator =( const realization_observer_FileFilter &other ) throw() {
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
