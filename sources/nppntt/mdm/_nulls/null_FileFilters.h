#pragma once

#include "../FileFilters.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace nulls {


class null_FileFilters :
	public FileFilters,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_FileFilters >
{

public:
	// virtuals FileFilters
	::jmsf::Proxy< file_filters::observable_FileFilter > takeObservableFileFilter() throw();
	::jmsf::Proxy< file_filters::observable_FileFilter > getOneselfObservableFileFilter() throw();
	::jmsf::Proxy< file_filters::observer_FileFilter > getOneselfNewVoiceFileDispatcherObserverFileFilter() throw();
	::jmsf::Proxy< file_filters::observer_FileFilter > getOneselfNewServiceFileDispatcherObserverFileFilter() throw();
	::jmsf::Proxy< file_filters::observer_FileFilter > getOneselfPreliminaryVoiceFileAndKeyMatchFinderObserverFileFilter() throw();
	::jmsf::Proxy< file_filters::observer_FileFilter > getOneselfDecipherObserverFileFilter() throw();
	::jmsf::Proxy< file_filters::observer_FileFilter > getOneselfRecurrentVoiceFileAndKeyCheckerObserverFileFilter() throw();
	::jmsf::Proxy< file_filters::observer_FileFilter > getOneselfServiceFileAndKeyMatchFinderObserverFileFilter() throw();
	::jmsf::Proxy< file_filters::observer_FileFilter > getOneselfServiceFileArrayFileFilter() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_FileFilters() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_FileFilters >;
	static null_FileFilters *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_FileFilters() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< FileFilters > createClone() const throw();

private:
	null_FileFilters( const null_FileFilters &other ) throw();
	const null_FileFilters &operator =( const null_FileFilters &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< file_filters::observable_FileFilter > _observableFileFilter;
	::jmsf::Proxy< file_filters::observer_FileFilter > _observerFileFilter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
