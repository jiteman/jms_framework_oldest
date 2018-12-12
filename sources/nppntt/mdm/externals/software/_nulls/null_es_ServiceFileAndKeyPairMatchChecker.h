#pragma once

#include "../es_ServiceFileAndKeyPairMatchChecker.h"
#include "jmsf/osie/runup/mixin_nulls/mixin_null_Runnable.h"
#include "jmsf/mixin_nulls/mixin_null_Object.h"
#include "jmsf/Singleton.hpp"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace nulls {


class null_es_ServiceFileAndKeyPairMatchChecker :
	public es_ServiceFileAndKeyPairMatchChecker,
	public ::jmsf::osie::runup::mixin_nulls::mixin_null_Runnable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_es_ServiceFileAndKeyPairMatchChecker >
{

public:
	// virtuals es_ServiceFileAndKeyPairMatchCkecker
	void setPair( ::jmsf::Pointer< ::jmsf::VariousPair< ::jmsf::Proxy, data::ed_ServiceFile, ::jmsf::ConstantProxy, data::ed_Key > > serviceFileAndKeyPair ) throw();
	const ::jmsf::Boolean &isPairMatched() const throw();
	const ::jmsf::ConstantProxy< data::ed_Key > getTheKey() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_es_ServiceFileAndKeyPairMatchChecker() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_es_ServiceFileAndKeyPairMatchChecker >;
	static null_es_ServiceFileAndKeyPairMatchChecker *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_es_ServiceFileAndKeyPairMatchChecker() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_ServiceFileAndKeyPairMatchChecker > createClone() const throw();

private:
	null_es_ServiceFileAndKeyPairMatchChecker( const null_es_ServiceFileAndKeyPairMatchChecker &other ) throw();
	const null_es_ServiceFileAndKeyPairMatchChecker &operator =( const null_es_ServiceFileAndKeyPairMatchChecker &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::ConstantProxy< data::ed_Key > _key;
	::jmsf::Boolean _boolean;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
