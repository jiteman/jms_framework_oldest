#pragma once

#include "../ImmediateVoiceFileAndKeyPairVerifier.h"
#include "jmsf/osie/runup/mixin_nulls/mixin_null_Runnable.h"
#include "jmsf/mixin_nulls/mixin_null_Object.h"
#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {


class null_ImmediateVoiceFileAndKeyPairVerifier :
	public ImmediateVoiceFileAndKeyPairVerifier,
	public ::jmsf::osie::runup::mixin_nulls::mixin_null_Runnable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_ImmediateVoiceFileAndKeyPairVerifier >
{

public:
	// virtuals ImmediateVoiceFileAndKeyPairVerifier
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ImmediateVoiceFileAndKeyPairVerifier() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_ImmediateVoiceFileAndKeyPairVerifier >;
	static null_ImmediateVoiceFileAndKeyPairVerifier *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ImmediateVoiceFileAndKeyPairVerifier() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ImmediateVoiceFileAndKeyPairVerifier > createClone() const throw();

private:
	null_ImmediateVoiceFileAndKeyPairVerifier( const null_ImmediateVoiceFileAndKeyPairVerifier &other ) throw();
	const null_ImmediateVoiceFileAndKeyPairVerifier &operator =( const null_ImmediateVoiceFileAndKeyPairVerifier &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
