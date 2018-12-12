#pragma once

#include "../ImmediateVoiceFileAndKeyPairVerifier.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Boolean.h"
#include "jmsf/Proxies.hpp"

#include "../../externals/software/es_VoiceFileAndKeyPairMatchChecker.hxx"
#include "../../externals/data/ed_VoiceFile.hxx"
#include "../../externals/data/ed_Key.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"
#include "jmsf/Pair.hxx"
#include "jmsf/Pointers.hxx"

#include "realization_factory_ProcessingProcesses.hxx"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

class realization_ImmediateVoiceFileAndKeyPairVerifier :
	public ImmediateVoiceFileAndKeyPairVerifier,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals ImmediateVoiceFileAndKeyPairVerifier
	void run() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ImmediateVoiceFileAndKeyPairVerifier() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ProcessingProcesses;
	realization_ImmediateVoiceFileAndKeyPairVerifier(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &sourceVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &destinationMatchedVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileWithNoMatchFoundQueue,
		const ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > &voiceFileAndKeyPairMatchChecker ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ImmediateVoiceFileAndKeyPairVerifier > createClone() const throw();

private:
	realization_ImmediateVoiceFileAndKeyPairVerifier( const realization_ImmediateVoiceFileAndKeyPairVerifier &other ) throw();
	const realization_ImmediateVoiceFileAndKeyPairVerifier &operator =( const realization_ImmediateVoiceFileAndKeyPairVerifier &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Boolean _isSubthreadStarted;

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > >_sourceVoiceFileAndKeyPairQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > _destinationMatchedVoiceFileAndKeyPairQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _destinationVoiceFileWithNoMatchFoundQueue;

	::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > _voiceFileAndKeyPairMatchChecker;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
}
}
