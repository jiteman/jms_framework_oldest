#pragma once

#include "../FileFilters.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "realization_factory_MaskDmObjects.hxx"

namespace nppntt {
namespace mdm {
namespace realizations {

class impl_FileFilters :
	public FileFilters,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals FileFilters
	::jmsf::Proxy< file_filters::observable_FileFilter > &takeObservableFileFilter() throw();
	const ::jmsf::ConstantProxy< file_filters::observable_FileFilter > &getObservableFileFilter() const throw();
	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getNewVoiceFileDispatcherObserverFileFilter() const throw();
	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getNewServiceFileDispatcherObserverFileFilter() const throw();
	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getPreliminaryVoiceFileAndKeyMatchFinderObserverFileFilter() const throw();
	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getDecipherObserverFileFilter() const throw();
	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getRecurrentVoiceFileAndKeyCheckerObserverFileFilter() const throw();
	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getServiceFileAndKeyMatchFinderObserverFileFilter() const throw();
	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getServiceFileArrayFileFilter() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~impl_FileFilters() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_MaskDmObjects;
	impl_FileFilters(
		const ::jmsf::Proxy< file_filters::observable_FileFilter > &observableFileFilter,
		const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &newVoiceFileDispatcherObserverFileFilter,
		const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &newServiceFileDispatcherObserverFileFilter,
		const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &preliminaryVoiceFileAndKeyMatchFinderObserverFileFilter,
		const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &decipherObserverFileFilter,
		const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &recurrentVoiceFileAndKeyCheckerObserverFileFilter,
		const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &serviceFileAndKeyMatchFinderObserverFileFilter,
		const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &serviceFileArrayFileFilter ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< FileFilters > createClone() const throw();

private:
	impl_FileFilters( const impl_FileFilters &other ) throw();
	const impl_FileFilters &operator =( const impl_FileFilters &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< file_filters::observable_FileFilter > _observableFileFilter;
	const ::jmsf::ConstantProxy< file_filters::observable_FileFilter > _constantObservableFileFilter;
	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > _newVoiceFileDispatcherObserverFileFilter;
	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > _newServiceFileDispatcherObserverFileFilter;
	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > _preliminaryVoiceFileAndKeyMatchFinderObserverFileFilter;
	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > _decipherObserverFileFilter;
	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > _recurrentVoiceFileAndKeyCheckerObserverFileFilter;
	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > _serviceFileAndKeyMatchFinderObserverFileFilter;
	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > _serviceFileArrayFileFilter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
