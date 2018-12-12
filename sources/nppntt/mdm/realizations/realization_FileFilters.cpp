#include "realization_FileFilters.h"

#include "../file_filters/observer_FileFilter.h"
#include "../file_filters/observable_FileFilter.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace realizations {


::jmsf::Proxy< file_filters::observable_FileFilter > &impl_FileFilters::takeObservableFileFilter() throw() {
	return _observableFileFilter;
}

const ::jmsf::ConstantProxy< file_filters::observable_FileFilter > &impl_FileFilters::getObservableFileFilter() const throw() {
	return _constantObservableFileFilter;
}

const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &impl_FileFilters::getNewVoiceFileDispatcherObserverFileFilter() const throw() {
	return _newVoiceFileDispatcherObserverFileFilter;
}

const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &impl_FileFilters::getNewServiceFileDispatcherObserverFileFilter() const throw() {
	return _newServiceFileDispatcherObserverFileFilter;
}

const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &impl_FileFilters::getPreliminaryVoiceFileAndKeyMatchFinderObserverFileFilter() const throw() {
	return _preliminaryVoiceFileAndKeyMatchFinderObserverFileFilter;
}

const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &impl_FileFilters::getDecipherObserverFileFilter() const throw() {
	return _decipherObserverFileFilter;
}

const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &impl_FileFilters::getRecurrentVoiceFileAndKeyCheckerObserverFileFilter() const throw() {
	return _recurrentVoiceFileAndKeyCheckerObserverFileFilter;
}

const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &impl_FileFilters::getServiceFileAndKeyMatchFinderObserverFileFilter() const throw() {
	return _serviceFileAndKeyMatchFinderObserverFileFilter;
}

const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &impl_FileFilters::getServiceFileArrayFileFilter() const throw() {
	return _serviceFileArrayFileFilter;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
impl_FileFilters::~impl_FileFilters() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
impl_FileFilters::impl_FileFilters(
		const ::jmsf::Proxy< file_filters::observable_FileFilter > &observableFileFilter,
		const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &newVoiceFileDispatcherObserverFileFilter,
		const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &newServiceFileDispatcherObserverFileFilter,
		const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &preliminaryVoiceFileAndKeyMatchFinderObserverFileFilter,
		const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &decipherObserverFileFilter,
		const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &recurrentVoiceFileAndKeyCheckerObserverFileFilter,
		const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &serviceFileAndKeyMatchFinderObserverFileFilter,
		const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &serviceFileArrayFileFilter ) throw()
	:
		_constantObservableFileFilter( observableFileFilter.getWeakConstant() ),
		_newVoiceFileDispatcherObserverFileFilter( newVoiceFileDispatcherObserverFileFilter ),
		_newServiceFileDispatcherObserverFileFilter( newServiceFileDispatcherObserverFileFilter ),
		_preliminaryVoiceFileAndKeyMatchFinderObserverFileFilter( preliminaryVoiceFileAndKeyMatchFinderObserverFileFilter ),
		_decipherObserverFileFilter( decipherObserverFileFilter ),
		_recurrentVoiceFileAndKeyCheckerObserverFileFilter( recurrentVoiceFileAndKeyCheckerObserverFileFilter ),
		_serviceFileAndKeyMatchFinderObserverFileFilter( serviceFileAndKeyMatchFinderObserverFileFilter ),
		_serviceFileArrayFileFilter( serviceFileArrayFileFilter )
{
	_observableFileFilter = observableFileFilter;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< FileFilters > impl_FileFilters::createClone() const throw() {
	return ::jmsf::Proxy< FileFilters >::createUnique( new impl_FileFilters( *this ) );
}

impl_FileFilters::impl_FileFilters( const impl_FileFilters & ) throw() // other
{}

const impl_FileFilters &impl_FileFilters::operator =( const impl_FileFilters &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
