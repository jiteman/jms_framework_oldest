#pragma once

#include "jmsf/Observer.h"
#include "jmsf/Object.h"

#include "../externals/data/ed_FileFilter.hxx"

#include "jmsf/Proxies.hxx"

namespace nppntt {
namespace mdm {
namespace file_filters {

class observer_FileFilter :
	public virtual ::jmsf::Observer,
	public virtual ::jmsf::Object
{

public:
	virtual const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &getFileFilter() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static observer_FileFilter *getNull() throw();
	static observer_FileFilter *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< observer_FileFilter > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace file_filters
} // namespace mdm
} // namespace nppntt
