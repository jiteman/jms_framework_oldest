#pragma once

#include "jmsf/mtf/Lockable.h"
#include "jmsf/Object.h"

#include "../externals/data/ed_ServiceFile.hxx"

#include "jmsf/Container.hxx"
#include "jmsf/Proxies.hxx"

namespace nppntt {
namespace mdm {
namespace processing {

class ServiceFileArray :
	public virtual ::jmsf::mtf::Lockable,
	public virtual ::jmsf::Object
{

public:
	virtual void append( const ::jmsf::Proxy< externals::data::ed_ServiceFile > &serviceFile ) throw( ::jmsf::Exception ) = 0;
	virtual ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeAccessToServiceFiles() throw( ::jmsf::Exception ) = 0;
	virtual void clearExpired() throw( ::jmsf::Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ServiceFileArray *getNull() throw();
	static ServiceFileArray *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< ServiceFileArray > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace processing
} // namespace mdm
} // namespace nppntt
