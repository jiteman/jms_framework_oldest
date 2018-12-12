#include "observable_FileFilter.h"
#include "../externals/data/ed_FileFilter.h"
#include "jmsf/mixins/mixin_null_Observable.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace file_filters {

class null_observable_FileFilter :
	public observable_FileFilter,
	public ::jmsf::mixins::mixin_null_Observable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_observable_FileFilter >
{

public:
	// virtuals observable_FileFilter
	::jmsf::Proxy< externals::data::ed_FileFilter > &takeFileFilter() throw() {
		return _fileFilterRtr;
	}

	const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &getFileFilter() const throw() {
		return _fileFilterCrtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_observable_FileFilter() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_observable_FileFilter >;
	static null_observable_FileFilter *createInstance() throw() {
		return new null_observable_FileFilter;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_observable_FileFilter() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< observable_FileFilter > createClone() const throw() {
		return ::jmsf::Proxy< observable_FileFilter >::createUnique( this );
	}

private:
	null_observable_FileFilter( const null_observable_FileFilter & ) throw() {} // other
	
	const null_observable_FileFilter &operator =( const null_observable_FileFilter &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_observable_FileFilter::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< externals::data::ed_FileFilter > _fileFilterRtr;
	::jmsf::ConstantProxy< externals::data::ed_FileFilter > _fileFilterCrtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_observable_FileFilter :
	public observable_FileFilter,
	public ::jmsf::mixins::mixin_null_Observable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_observable_FileFilter > {

public:
	// virtuals observable_FileFilter
	::jmsf::Proxy< externals::data::ed_FileFilter > &takeFileFilter() throw() {
		return _fileFilterRtr;
	}

	const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &getFileFilter() const throw() {
		return _fileFilterCrtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_observable_FileFilter() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_observable_FileFilter >;
	static exception_observable_FileFilter *createInstance() throw() {
		return new exception_observable_FileFilter;
	}

private:
	exception_observable_FileFilter() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< observable_FileFilter > createClone() const throw() {
		return ::jmsf::Proxy< observable_FileFilter >::createUnique( this );
	}

private:
	exception_observable_FileFilter( const exception_observable_FileFilter & ) throw() {} // other

	const exception_observable_FileFilter &operator =( const exception_observable_FileFilter &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_observable_FileFilter::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< externals::data::ed_FileFilter > _fileFilterRtr;
	::jmsf::ConstantProxy< externals::data::ed_FileFilter > _fileFilterCrtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
observable_FileFilter *observable_FileFilter::getNull() throw() {
	return null_observable_FileFilter::instance();
}

// static
observable_FileFilter *observable_FileFilter::getException() throw() {
	return exception_observable_FileFilter::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace file_filters
} // namespace mdm
} // namespace nppntt
