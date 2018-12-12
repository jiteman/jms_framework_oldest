#pragma once

#include "jmsf/Observable.h"
#include "jmsf/Object.h"

#include "../externals/data/ed_FileFilter.hxx"
#include "jmsf/Proxies.hxx"

namespace nppntt {
namespace mdm {
namespace file_filters {

class observable_FileFilter :
	public virtual ::jmsf::Observable,
	public virtual ::jmsf::Object
{

public:
	virtual ::jmsf::Proxy< externals::data::ed_FileFilter > &takeFileFilter() throw() = 0;
	virtual const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &getFileFilter() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static observable_FileFilter *getNull() throw();
	static observable_FileFilter *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< observable_FileFilter > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace file_filters
} // namespace mdm
} // namespace nppntt
