#pragma once

#include "../observer_FileFilter.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "../../externals/data/ed_FileFilter.hxx"
#include "../observable_FileFilter.hxx"
#include "realization_factory_FileFilters.hxx"


namespace nppntt {
namespace mdm {
namespace file_filters {
namespace realizations {

class realization_observer_FileFilter :
	public observer_FileFilter,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals observer_FileFilter
	const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &getFileFilter() const throw();
	//~virtuals

	// virtuals Observer
	void update() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_observer_FileFilter() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_FileFilters;
	realization_observer_FileFilter(
		const ::jmsf::Proxy< observable_FileFilter > &observableFileFilter,
		const ::jmsf::Proxy< externals::data::ed_FileFilter > &fileFilter ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< observer_FileFilter > createClone() const throw();

private:
	realization_observer_FileFilter( const realization_observer_FileFilter &other ) throw();
	const realization_observer_FileFilter &operator =( const realization_observer_FileFilter &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< observable_FileFilter > _observableFileFilter;
	::jmsf::Proxy< externals::data::ed_FileFilter > _fileFilter;
	::jmsf::ConstantProxy< externals::data::ed_FileFilter > _constantFileFilter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
