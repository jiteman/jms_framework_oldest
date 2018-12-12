#pragma once

#include "../ServiceFileArray.h"
#include "jmsf/mtf/mixin_nulls/mixin_null_Synchronizable.h"
#include "jmsf/mixin_nulls/mixin_null_Object.h"
#include "jmsf/Singleton.hpp"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {


class null_ServiceFileArray :
	public ServiceFileArray,
	public ::jmsf::mtf::mixin_nulls::mixin_null_Synchronizable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_ServiceFileArray >
{

public:
	// virtuals ServiceFileArray
	void append( const ::jmsf::Proxy< externals::data::ed_ServiceFile > &serviceFile ) throw( ::jmsf::Exception );
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy, externals::data::ed_ServiceFile > > &getAccessToServiceFiles() throw( ::jmsf::Exception );
	void clearExpired() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ServiceFileArray() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_ServiceFileArray >;
	static null_ServiceFileArray *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ServiceFileArray() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ServiceFileArray > createClone() const throw();

private:
	null_ServiceFileArray( const null_ServiceFileArray &other ) throw();
	const null_ServiceFileArray &operator =( const null_ServiceFileArray &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy, externals::data::ed_ServiceFile > > _serviceFiles;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
