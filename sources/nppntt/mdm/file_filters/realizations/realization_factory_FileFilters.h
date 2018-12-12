#pragma once

#include "../factory_FileFilters.h"


namespace nppntt {
namespace mdm {
namespace file_filters {
namespace realizations {


class realization_factory_FileFilters :
	public factory_FileFilters
{

public:
	// virtuals factory_FileFilters
	::jmsf::Proxy< observable_FileFilter > createObservableFileFilter() const throw();
	::jmsf::Proxy< observer_FileFilter >createObserverFileFilter( const ::jmsf::Proxy< observable_FileFilter > &observableFileFilter ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_FileFilters() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class factory_FileFilters;
	realization_factory_FileFilters() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_FileFilters( const realization_factory_FileFilters &other ) throw();
	const realization_factory_FileFilters &operator =( const realization_factory_FileFilters &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
