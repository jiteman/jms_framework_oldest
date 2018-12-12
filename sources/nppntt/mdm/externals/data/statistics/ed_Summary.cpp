#include "ed_Summary.h"
#include "../../others/abstractStatistics.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/PointersAndProxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {

class null_ed_Summary :
	public ed_Summary,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ed_Summary >
{

public:
	// virtuals ed_Summary
	::jmsf::Pointer< GlobalStatisticsData > &takeData() throw( ::jmsf::Exception ) {
		return _globalStatisticsData;
	}

	const ::jmsf::ConstantPointer< GlobalStatisticsData > &getData() const throw( ::jmsf::Exception ) {
		return _constantGlobalStatisticsData;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ed_Summary() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ed_Summary >;
	static null_ed_Summary *createInstance() throw() {
		return new null_ed_Summary;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ed_Summary() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_Summary > createClone() const throw() {
		return ::jmsf::Proxy< ed_Summary >::createUnique( this );
	}

private:
	null_ed_Summary( const null_ed_Summary & ) throw() {} // other
	
	const null_ed_Summary &operator =( const null_ed_Summary &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ed_Summary::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< GlobalStatisticsData > _globalStatisticsData;
	::jmsf::ConstantPointer< GlobalStatisticsData > _constantGlobalStatisticsData;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_ed_Summary :
	public ed_Summary,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ed_Summary > {

public:
	// virtuals ed_Summary
	::jmsf::Pointer< GlobalStatisticsData > &takeData() throw( ::jmsf::Exception ) {
		return _globalStatisticsData;
	}

	const ::jmsf::ConstantPointer< GlobalStatisticsData > &getData() const throw( ::jmsf::Exception ) {
		return _constantGlobalStatisticsData;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ed_Summary() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ed_Summary >;
	static exception_ed_Summary *createInstance() throw() {
		return new exception_ed_Summary;
	}

private:
	exception_ed_Summary() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_Summary > createClone() const throw() {
		return ::jmsf::Proxy< ed_Summary >::createUnique( this );
	}

private:
	exception_ed_Summary( const exception_ed_Summary & ) throw() {} // other

	const exception_ed_Summary &operator =( const exception_ed_Summary &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ed_Summary::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< GlobalStatisticsData > _globalStatisticsData;
	::jmsf::ConstantPointer< GlobalStatisticsData > _constantGlobalStatisticsData;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
ed_Summary *ed_Summary::getNull() throw() {
	return null_ed_Summary::instance();
}

// static
ed_Summary *ed_Summary::getException() throw() {
	return exception_ed_Summary::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace statistics
} // namespace data
} // namespace externals
} // namespace mdm
} // namespace nppntt
