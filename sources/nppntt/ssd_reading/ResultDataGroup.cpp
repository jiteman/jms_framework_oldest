#include "ResultDataGroup.h"


namespace nppntt {
namespace ssd_reading {


ResultDataGroup::~ResultDataGroup() throw()
{}

ResultDataGroup::ResultDataGroup() throw()
{}

void ResultDataGroup::addSingleResultData( const ::jmsf::natural_big singleResultData ) throw() {
	_resultData.push_back( singleResultData );
}

const std::vector< ::jmsf::natural_big > &ResultDataGroup::getResultData() const throw() {
	return _resultData;
}

::jmsf::Boolean ResultDataGroup::isEmpty() const throw() {
	return _resultData.empty();
}

void ResultDataGroup::clear() throw() {
	_resultData.clear();
}

// jms::boolean ResultDataGroup::operator <( const ResultDataGroup &other ) const throw() {
// 	if ( _ordinalNumberOfGroup < other._ordinalNumberOfGroup ) {
// 		return true;
// 	} else if ( _ordinalNumberOfGroup > other._ordinalNumberOfGroup ) {
// 		return false;
// 	}
// 
// 	return false;
// }


} // namespace
}
