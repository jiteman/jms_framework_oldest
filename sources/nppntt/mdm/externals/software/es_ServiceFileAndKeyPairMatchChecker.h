#pragma once

#include "jmsf/mtf/Runnable.h"
#include "jmsf/Object.h"

#include "../others/DataTypes.hxx"
#include "../data/ed_ServiceFile.hxx"
#include "../data/ed_Key.hxx"
#include "jmsf/Pair.hxx"
#include "jmsf/PointersAndProxies.hxx"

namespace nppntt {
namespace mdm {
namespace externals {
namespace software {


class es_ServiceFileAndKeyPairMatchChecker :
	public virtual ::jmsf::mtf::Runnable,
	public virtual ::jmsf::Object
{

public:
	virtual void setPair( const ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< data::ed_ServiceFile >, ::jmsf::ConstantProxy< data::ed_Key > > > &serviceFileAndKeyPair ) throw() = 0;
	virtual const ::jmsf::Boolean isPairMatched() const throw() = 0;
	virtual const ::jmsf::ConstantProxy< data::ed_Key > &getTheKey() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static es_ServiceFileAndKeyPairMatchChecker *getNull() throw();
	static es_ServiceFileAndKeyPairMatchChecker *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< es_ServiceFileAndKeyPairMatchChecker > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
