#include "null_ed_Summary.h"

#include "../../../others/abstractStatistics.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace nulls {


::jmsf::Pointer< GlobalStatisticsData > null_ed_Summary::getOneselfData() throw( ::jmsf::Exception ) {
	return _summaryFilesData.getWeak();
}

const ::jmsf::ConstantPointer< GlobalStatisticsData > null_ed_Summary::getData() const throw( ::jmsf::Exception ) {
	return _summaryFilesData.getWeak();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ed_Summary::~null_ed_Summary() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ed_Summary *null_ed_Summary::createInstance() throw() {
	return new null_ed_Summary;
}

null_ed_Summary::null_ed_Summary() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_Summary > null_ed_Summary::createClone() const throw() {
	return ::jmsf::Proxy< ed_Summary >::createUnique( this );
}

null_ed_Summary::null_ed_Summary( const null_ed_Summary & ) throw() // other
{}

const null_ed_Summary &null_ed_Summary::operator =( const null_ed_Summary &other ) throw() {
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
}
}
