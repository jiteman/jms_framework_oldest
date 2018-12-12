#include "FileFilters.h"
#include "file_filters/observable_FileFilter.h"
#include "file_filters/observer_FileFilter.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {

class null_FileFilters :
	public FileFilters,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_FileFilters >
{

public:
	// virtuals FileFilters
	::jmsf::Proxy< file_filters::observable_FileFilter > &takeObservableFileFilter() throw() {
		return _observableFileFilterRtr;
	}

	const ::jmsf::ConstantProxy< file_filters::observable_FileFilter > &getObservableFileFilter() const throw() {
		return _observableFileFilterCrtr;
	}

	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getNewVoiceFileDispatcherObserverFileFilter() const throw() {
		return _observerFileFilterCrtr;
	}

	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getNewServiceFileDispatcherObserverFileFilter() const throw() {
		return _observerFileFilterCrtr;
	}

	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getPreliminaryVoiceFileAndKeyMatchFinderObserverFileFilter() const throw() {
		return _observerFileFilterCrtr;
	}

	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getDecipherObserverFileFilter() const throw() {
		return _observerFileFilterCrtr;
	}

	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getRecurrentVoiceFileAndKeyCheckerObserverFileFilter() const throw() {
		return _observerFileFilterCrtr;
	}

	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getServiceFileAndKeyMatchFinderObserverFileFilter() const throw() {
		return _observerFileFilterCrtr;
	}

	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getServiceFileArrayFileFilter() const throw() {
		return _observerFileFilterCrtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_FileFilters() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_FileFilters >;
	static null_FileFilters *createInstance() throw() {
		return new null_FileFilters;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_FileFilters() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< FileFilters > createClone() const throw() {
		return ::jmsf::Proxy< FileFilters >::createUnique( this );
	}

private:
	null_FileFilters( const null_FileFilters & ) throw() {} // other
	
	const null_FileFilters &operator =( const null_FileFilters &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_FileFilters::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< file_filters::observable_FileFilter > _observableFileFilterRtr;
	::jmsf::ConstantProxy< file_filters::observable_FileFilter > _observableFileFilterCrtr;
	::jmsf::ConstantProxy< file_filters::observer_FileFilter > _observerFileFilterCrtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_FileFilters :
	public FileFilters,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_FileFilters > {

public:
	// virtuals FileFilters
	::jmsf::Proxy< file_filters::observable_FileFilter > &takeObservableFileFilter() throw() {
		return _observableFileFilterRtr;
	}

	const ::jmsf::ConstantProxy< file_filters::observable_FileFilter > &getObservableFileFilter() const throw() {
		return _observableFileFilterCrtr;
	}

	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getNewVoiceFileDispatcherObserverFileFilter() const throw() {
		return _observerFileFilterCrtr;
	}

	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getNewServiceFileDispatcherObserverFileFilter() const throw() {
		return _observerFileFilterCrtr;
	}

	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getPreliminaryVoiceFileAndKeyMatchFinderObserverFileFilter() const throw() {
		return _observerFileFilterCrtr;
	}

	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getDecipherObserverFileFilter() const throw() {
		return _observerFileFilterCrtr;
	}

	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getRecurrentVoiceFileAndKeyCheckerObserverFileFilter() const throw() {
		return _observerFileFilterCrtr;
	}

	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getServiceFileAndKeyMatchFinderObserverFileFilter() const throw() {
		return _observerFileFilterCrtr;
	}

	const ::jmsf::ConstantProxy< file_filters::observer_FileFilter > &getServiceFileArrayFileFilter() const throw() {
		return _observerFileFilterCrtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_FileFilters() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_FileFilters >;
	static exception_FileFilters *createInstance() throw() {
		return new exception_FileFilters;
	}

private:
	exception_FileFilters() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< FileFilters > createClone() const throw() {
		return ::jmsf::Proxy< FileFilters >::createUnique( this );
	}

private:
	exception_FileFilters( const exception_FileFilters & ) throw() {} // other

	const exception_FileFilters &operator =( const exception_FileFilters &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_FileFilters::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< file_filters::observable_FileFilter > _observableFileFilterRtr;
	::jmsf::ConstantProxy< file_filters::observable_FileFilter > _observableFileFilterCrtr;
	::jmsf::ConstantProxy< file_filters::observer_FileFilter > _observerFileFilterCrtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
FileFilters *FileFilters::getNull() throw() {
	return null_FileFilters::instance();
}

// static
FileFilters *FileFilters::getException() throw() {
	return exception_FileFilters::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace mdm
} // namespace nppntt
