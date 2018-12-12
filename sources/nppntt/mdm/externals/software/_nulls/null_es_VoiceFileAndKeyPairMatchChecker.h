#pragma once

#include "../es_VoiceFileAndKeyPairMatchChecker.h"
#include "jmsf/osie/runup/mixin_nulls/mixin_null_Runnable.h"
#include "jmsf/mixin_nulls/mixin_null_Object.h"
#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace nulls {


class null_es_VoiceFileAndKeyPairMatchChecker :
	public es_VoiceFileAndKeyPairMatchChecker,
	public ::jmsf::osie::runup::mixin_nulls::mixin_null_Runnable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_es_VoiceFileAndKeyPairMatchChecker >
{

public:
	// virtuals es_VoiceFileAndKeyPairMatchCkecker
	void setPair( ::jmsf::Pointer< ::jmsf::VariousPair< ::jmsf::Proxy, data::ed_VoiceFile, ::jmsf::ConstantProxy, data::ed_Key > > voiceFileAndKeyPair ) throw();
	const ::jmsf::Boolean isPairMatched() const throw();
	const ::jmsf::ConstantProxy< data::ed_Key > getTheKey() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_es_VoiceFileAndKeyPairMatchChecker() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_es_VoiceFileAndKeyPairMatchChecker >;
	static null_es_VoiceFileAndKeyPairMatchChecker *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_es_VoiceFileAndKeyPairMatchChecker() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_VoiceFileAndKeyPairMatchChecker > createClone() const throw();

private:
	null_es_VoiceFileAndKeyPairMatchChecker( const null_es_VoiceFileAndKeyPairMatchChecker &other ) throw();
	const null_es_VoiceFileAndKeyPairMatchChecker &operator =( const null_es_VoiceFileAndKeyPairMatchChecker &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
