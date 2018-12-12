#pragma once

#include "jmsf/mtf/Runnable.h"
#include "jmsf/Object.h"

#include "../others/DataTypes.hxx"
#include "../data/ed_VoiceFile.hxx"
#include "../data/ed_Key.hxx"
#include "jmsf/Pair.hxx"
#include "jmsf/Pointers.hxx"
#include "jmsf/Proxies.hxx"

namespace nppntt {
namespace mdm {
namespace externals {
namespace software {


class es_VoiceFileAndKeyPairMatchChecker :
	public virtual ::jmsf::mtf::Runnable,
	public virtual ::jmsf::Object
{

public:
	virtual void setPair( const ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< data::ed_VoiceFile >, ::jmsf::ConstantProxy< data::ed_Key > > > &voiceFileAndKeyPair ) throw() = 0;
	virtual const ::jmsf::Boolean isPairMatched() const throw() = 0;
	virtual const ::jmsf::ConstantProxy< data::ed_Key > &getTheKey() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static es_VoiceFileAndKeyPairMatchChecker *getNull() throw();
	static es_VoiceFileAndKeyPairMatchChecker *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< es_VoiceFileAndKeyPairMatchChecker > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
