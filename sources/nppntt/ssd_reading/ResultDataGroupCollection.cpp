#include "ResultDataGroupCollection.h"

#include "jmsf/Pointer.hpp"


namespace nppntt {
namespace ssd_reading {


::jmsf::Pointer< ResultDataGroupCollection > ResultDataGroupCollection::create() throw() {
	return ::jmsf::Pointer< ResultDataGroupCollection >::createUnique( new ResultDataGroupCollection );
}

ResultDataGroupCollection::~ResultDataGroupCollection() throw()
{}

ResultDataGroupCollection::ResultDataGroupCollection() throw()
{}

void ResultDataGroupCollection::resizeIfNeeded( ::jmsf::natural_size requiredSize ) throw() {
	const ::jmsf::natural_size sizeOfResultDataGroups = _resultDataGroups.size();

	if ( sizeOfResultDataGroups < requiredSize ) {
		_resultDataGroups.resize( requiredSize );
	}
}

ResultDataGroup &ResultDataGroupCollection::getResultDataGroup( ::jmsf::natural_size resultDataGroupIndex ) throw( std::out_of_range ) {
	return _resultDataGroups.at( resultDataGroupIndex );
}

void ResultDataGroupCollection::clear() throw() {
	for ( std::vector< ResultDataGroup >::iterator resultDataGroupIterator = _resultDataGroups.begin(); resultDataGroupIterator != _resultDataGroups.end(); ++resultDataGroupIterator ) {
		resultDataGroupIterator->clear();
	}
}

const std::vector< ResultDataGroup > &ResultDataGroupCollection::getResultDataGroups() const throw() {
	return _resultDataGroups;
}


} // namespace
}
