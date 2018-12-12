#include "realization_factory_FileFilters.h"
#include "../../externals/others/abstractFilter.h"
#include "../../externals/data/factory_ExternalData.h"
#include "../../externals/data/ed_FileFilter.h"

#include "realization_observable_FileFilter.h"
#include "realization_observer_FileFilter.h"

#include "jmsf/Pointers.hpp"


namespace nppntt {
namespace mdm {
namespace file_filters {
namespace realizations {


::jmsf::Proxy< observable_FileFilter > realization_factory_FileFilters::createObservableFileFilter() const throw() {
	return ::jmsf::Proxy< observable_FileFilter >::createUnique(
		new realization_observable_FileFilter(
			externals::data::factory_ExternalData::instance()->createFileFilter(
				::jmsf::Pointer< FilterData >::createUnique( ::createFilter() ) ) ) );
}

::jmsf::Proxy< observer_FileFilter > realization_factory_FileFilters::createObserverFileFilter(
	const ::jmsf::Proxy< observable_FileFilter > &observableFileFilter ) const throw()
{
	return ::jmsf::Proxy< observer_FileFilter >::createUnique(
		new realization_observer_FileFilter(
			observableFileFilter,
			externals::data::factory_ExternalData::instance()->createFileFilter(
				::jmsf::Pointer< FilterData >::createUnique( ::createFilter() ) ) ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_factory_FileFilters::~realization_factory_FileFilters() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_FileFilters::realization_factory_FileFilters() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_FileFilters::realization_factory_FileFilters( const realization_factory_FileFilters & ) throw() // other
{}

const realization_factory_FileFilters &realization_factory_FileFilters::operator =( const realization_factory_FileFilters &other ) throw() {
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
