#pragma once

#include "../observable_FileFilter.h"
#include "jmsf/mixins/mixin_Observable.h"
#include "jmsf/mixins/mixin_Object.h"

#include "../../externals/data/ed_FileFilter.hxx"
#include "realization_factory_FileFilters.hxx"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace file_filters {
namespace realizations {

class realization_observable_FileFilter :
	public observable_FileFilter,
	public ::jmsf::mixins::mixin_Observable,
	public ::jmsf::mixins::mixin_Object {

public:
	// virtuals observable_FileFilter
	::jmsf::Proxy< externals::data::ed_FileFilter > &takeFileFilter() throw();
	const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &getFileFilter() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_observable_FileFilter() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_FileFilters;
	realization_observable_FileFilter(
		const ::jmsf::Proxy< externals::data::ed_FileFilter > &fileFilter ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< observable_FileFilter > createClone() const throw();

private:
	realization_observable_FileFilter( const realization_observable_FileFilter &other ) throw();
	const realization_observable_FileFilter &operator =( const realization_observable_FileFilter &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< externals::data::ed_FileFilter > _fileFilter;
	::jmsf::ConstantProxy< externals::data::ed_FileFilter > _constantFileFilter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
