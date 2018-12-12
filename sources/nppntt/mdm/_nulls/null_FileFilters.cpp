#include "null_FileFilters.h"

#include "../file_filters/observer_FileFilter.h"
#include "../file_filters/observable_FileFilter.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace nulls {


::jmsf::Proxy< file_filters::observable_FileFilter > null_FileFilters::takeObservableFileFilter() throw() {
	return _observableFileFilter.getWeak();
}

::jmsf::Proxy< file_filters::observable_FileFilter > null_FileFilters::getOneselfObservableFileFilter() throw() {
	return _observableFileFilter.getWeak();
}

::jmsf::Proxy< file_filters::observer_FileFilter > null_FileFilters::getOneselfNewVoiceFileDispatcherObserverFileFilter() throw() {
	return _observerFileFilter.getWeak();
}

::jmsf::Proxy< file_filters::observer_FileFilter > null_FileFilters::getOneselfNewServiceFileDispatcherObserverFileFilter() throw() {
	return _observerFileFilter.getWeak();
}

::jmsf::Proxy< file_filters::observer_FileFilter > null_FileFilters::getOneselfPreliminaryVoiceFileAndKeyMatchFinderObserverFileFilter() throw() {
	return _observerFileFilter.getWeak();
}

::jmsf::Proxy< file_filters::observer_FileFilter > null_FileFilters::getOneselfDecipherObserverFileFilter() throw() {
	return _observerFileFilter.getWeak();
}

::jmsf::Proxy< file_filters::observer_FileFilter > null_FileFilters::getOneselfRecurrentVoiceFileAndKeyCheckerObserverFileFilter() throw() {
	return _observerFileFilter.getWeak();
}

::jmsf::Proxy< file_filters::observer_FileFilter > null_FileFilters::getOneselfServiceFileAndKeyMatchFinderObserverFileFilter() throw() {
	return _observerFileFilter.getWeak();
}

::jmsf::Proxy< file_filters::observer_FileFilter > null_FileFilters::getOneselfServiceFileArrayFileFilter() throw() {
	return _observerFileFilter.getWeak();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_FileFilters::~null_FileFilters() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_FileFilters *null_FileFilters::createInstance() throw() {
	return new null_FileFilters;
}

null_FileFilters::null_FileFilters() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< FileFilters > null_FileFilters::createClone() const throw() {
	return ::jmsf::Proxy< FileFilters >::createUnique( this );
}

null_FileFilters::null_FileFilters( const null_FileFilters & ) throw() // other
{}

const null_FileFilters &null_FileFilters::operator =( const null_FileFilters &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
