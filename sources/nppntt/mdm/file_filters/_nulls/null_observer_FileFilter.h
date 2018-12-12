#pragma once

#include "../observer_FileFilter.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace file_filters {
namespace nulls {


class null_observer_FileFilter :
	public observer_FileFilter,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_observer_FileFilter >
{

public:
	// virtuals observer_FileFilter
	const ::jmsf::Proxy< externals::data::ed_FileFilter > getFileFilter() const throw();
	//~virtuals

	// virtuals Observer
	void update() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_observer_FileFilter() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_observer_FileFilter >;
	static null_observer_FileFilter *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_observer_FileFilter() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< observer_FileFilter > createClone() const throw();

private:
	null_observer_FileFilter( const null_observer_FileFilter &other ) throw();
	const null_observer_FileFilter &operator =( const null_observer_FileFilter &other ) throw();

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
