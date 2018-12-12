#pragma once

#include "jmsf/Object.h"

#include "file_filters/observable_FileFilter.hxx"
#include "file_filters/observer_FileFilter.hxx"
#include "jmsf/Proxies.hxx"

namespace nppntt {
namespace mdm {

class FileFilters :
	public virtual ::jmsf::Object
{

public:
	virtual ::jmsf::Proxy< file_filters::observable_FileFilter > &takeObservableFileFilter() throw() = 0;
	virtual const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getNewVoiceFileDispatcherObserverFileFilter() const throw() = 0;
	virtual const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getNewServiceFileDispatcherObserverFileFilter() const throw() = 0;
	virtual const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getPreliminaryVoiceFileAndKeyMatchFinderObserverFileFilter() const throw() = 0;
	virtual const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getDecipherObserverFileFilter() const throw() = 0;
	virtual const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getRecurrentVoiceFileAndKeyCheckerObserverFileFilter() const throw() = 0;
	virtual const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getServiceFileAndKeyMatchFinderObserverFileFilter() const throw() = 0;
	virtual const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getServiceFileArrayFileFilter() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static FileFilters *getNull() throw();
	static FileFilters *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< FileFilters > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace mdm
} // namespace nppntt
