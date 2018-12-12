#pragma once

#include "../es_ServiceFileAndKeyPairMatchChecker.h"
//#include "jmsf/mtf/mixing/mixin_Runnable.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"
#include "jmsf/osie/Mutex.hxx"

#include "realization_factory_ExternalSoftware.hxx"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace realizations {


class realization_es_ServiceFileAndKeyPairMatchChecker :
	public es_ServiceFileAndKeyPairMatchChecker,
//	public ::jmsf::osie::runup::mixing::mixin_Runnable,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals es_ServiceFileAndKeyPairMatchChecker
	void setPair( const ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< data::ed_ServiceFile >, ::jmsf::ConstantProxy< data::ed_Key > > > &serviceFileAndKeyPair ) throw();
	const ::jmsf::Boolean isPairMatched() const throw();
	const ::jmsf::ConstantProxy< data::ed_Key > &getTheKey() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals Runnable
	void run() throw( ::jmsf::Exception );
	//~virtuals

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_es_ServiceFileAndKeyPairMatchChecker() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ExternalSoftware;
	realization_es_ServiceFileAndKeyPairMatchChecker(
		::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) throw( jmsf::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_ServiceFileAndKeyPairMatchChecker > createClone() const throw();

private:
	realization_es_ServiceFileAndKeyPairMatchChecker( const realization_es_ServiceFileAndKeyPairMatchChecker &other ) throw();
	const realization_es_ServiceFileAndKeyPairMatchChecker &operator =( const realization_es_ServiceFileAndKeyPairMatchChecker &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< data::ed_ServiceFile >, ::jmsf::ConstantProxy< data::ed_Key > > > _serviceFileAndKeyPair;
	::jmsf::Boolean _isPairMatched;
	::jmsf::Proxy< ::jmsf::osie::Mutex > _serviceFileAndKeyPairMatchCheckerMutex;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
