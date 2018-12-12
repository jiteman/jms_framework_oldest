#pragma once

#include "../observable_FileFilter.h"

#include "jmsf/mixin_nulls/mixin_null_Observable.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace file_filters {
namespace nulls {


class null_observable_FileFilter :
	public observable_FileFilter,
	public ::jmsf::mixin_nulls::mixin_null_Observable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_observable_FileFilter > {

public:
	// virtuals observable_FileFilter
	::jmsf::Proxy< externals::data::ed_FileFilter > getOneselfFileFilter() throw();
	const ::jmsf::Proxy< externals::data::ed_FileFilter > getFileFilter() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_observable_FileFilter() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_observable_FileFilter >;
	static null_observable_FileFilter *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_observable_FileFilter() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< observable_FileFilter > createClone() const throw();

private:
	null_observable_FileFilter( const null_observable_FileFilter &other ) throw();
	const null_observable_FileFilter &operator =( const null_observable_FileFilter &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< externals::data::ed_FileFilter > _fileFilter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
