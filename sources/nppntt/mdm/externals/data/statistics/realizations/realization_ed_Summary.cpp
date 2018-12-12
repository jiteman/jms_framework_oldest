#include "realization_ed_Summary.h"
#include "../../../others/abstractStatistics.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace realizations {


::jmsf::Pointer< GlobalStatisticsData > &realization_ed_Summary::takeData() throw( ::jmsf::Exception ) {
	return _summaryFilesData;
}

const ::jmsf::ConstantPointer< GlobalStatisticsData > &realization_ed_Summary::getData() const throw( ::jmsf::Exception ) {
	return _constantSummaryFilesData;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ed_Summary::~realization_ed_Summary() throw() {
	::deleteGlobalStatistics( _summaryFilesData.get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ed_Summary::realization_ed_Summary() throw()
	:
		_summaryFilesData( ::jmsf::Pointer< GlobalStatisticsData >::createWeakFor( ::createGlobalStatistics() ) )
{
	_constantSummaryFilesData = _summaryFilesData.getWeakConstant();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_Summary > realization_ed_Summary::createClone() const throw() {
	return ::jmsf::Proxy< ed_Summary >::createUnique( new realization_ed_Summary( *this ) );
}

realization_ed_Summary::realization_ed_Summary( const realization_ed_Summary & ) throw() // other
{}

const realization_ed_Summary &realization_ed_Summary::operator =( const realization_ed_Summary &other ) throw() {
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
