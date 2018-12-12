#include "observer_FileFilter.h"
#include "../externals/data/ed_FileFilter.h"
#include "jmsf/mixins/mixin_null_Observer.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace file_filters {

class null_observer_FileFilter :
	public observer_FileFilter,
	public ::jmsf::mixins::mixin_null_Observer,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_observer_FileFilter >
{

public:
	// virtuals observer_FileFilter
	const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &getFileFilter() const throw() {
		return _fileFilterCrtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_observer_FileFilter() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_observer_FileFilter >;
	static null_observer_FileFilter *createInstance() throw() {
		return new null_observer_FileFilter;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_observer_FileFilter() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< observer_FileFilter > createClone() const throw() {
		return ::jmsf::Proxy< observer_FileFilter >::createUnique( this );
	}

private:
	null_observer_FileFilter( const null_observer_FileFilter & ) throw() {} // other
	
	const null_observer_FileFilter &operator =( const null_observer_FileFilter &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_observer_FileFilter::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > _fileFilterCrtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_observer_FileFilter :
	public observer_FileFilter,
	public ::jmsf::mixins::mixin_null_Observer,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_observer_FileFilter > {

public:
	// virtuals observer_FileFilter
	const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &getFileFilter() const throw() {
		return _fileFilterCrtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_observer_FileFilter() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_observer_FileFilter >;
	static exception_observer_FileFilter *createInstance() throw() {
		return new exception_observer_FileFilter;
	}

private:
	exception_observer_FileFilter() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< observer_FileFilter > createClone() const throw() {
		return ::jmsf::Proxy< observer_FileFilter >::createUnique( this );
	}

private:
	exception_observer_FileFilter( const exception_observer_FileFilter & ) throw() {} // other

	const exception_observer_FileFilter &operator =( const exception_observer_FileFilter &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_observer_FileFilter::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > _fileFilterCrtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
observer_FileFilter *observer_FileFilter::getNull() throw() {
	return null_observer_FileFilter::instance();
}

// static
observer_FileFilter *observer_FileFilter::getException() throw() {
	return exception_observer_FileFilter::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace file_filters
} // namespace mdm
} // namespace nppntt
