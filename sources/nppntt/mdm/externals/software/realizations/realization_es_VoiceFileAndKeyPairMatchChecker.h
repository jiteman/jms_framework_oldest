#pragma once

#include "../es_VoiceFileAndKeyPairMatchChecker.h"
//#include "jmsf/osie/runup/mixing/mixin_Runnable.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/PointersAndProxies.hpp"
#include "jmsf/osie/Mutex.hxx"

#include "realization_factory_ExternalSoftware.hxx"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace realizations {


class realization_es_VoiceFileAndKeyPairMatchChecker :
	public es_VoiceFileAndKeyPairMatchChecker,
//	public ::jmsf::osie::runup::mixing::mixin_Runnable,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals es_VoiceFileAndKeyPairMatchCkecker
	void setPair( const ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< data::ed_VoiceFile >, ::jmsf::ConstantProxy< data::ed_Key > > > &voiceFileAndKeyPair ) throw();
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
	~realization_es_VoiceFileAndKeyPairMatchChecker() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ExternalSoftware;
	realization_es_VoiceFileAndKeyPairMatchChecker(
		::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_VoiceFileAndKeyPairMatchChecker > createClone() const throw();

private:
	realization_es_VoiceFileAndKeyPairMatchChecker( const realization_es_VoiceFileAndKeyPairMatchChecker &other ) throw();
	const realization_es_VoiceFileAndKeyPairMatchChecker &operator =( const realization_es_VoiceFileAndKeyPairMatchChecker &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< data::ed_VoiceFile >, ::jmsf::ConstantProxy< data::ed_Key > > > _voiceFileAndKeyPair;
	::jmsf::Boolean _isPairMatched;
	::jmsf::Proxy< ::jmsf::osie::Mutex > _voiceFileMutex;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
