#pragma once

#include "../RecurrentVoiceFileAndKeyMatchFinder.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "../../externals/software/es_VoiceFileAndKeyPairMatchChecker.hxx"
#include "../../externals/data/ed_FileFilter.hxx"
#include "../../externals/data/ed_VoiceFile.hxx"
#include "../KeyArray.h"
#include "jmsf/osie/EventArray.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"
#include "jmsf/Pair.hxx"
#include "jmsf/Iterators.hxx"
#include "jmsf/Pointers.hxx"

#include "realization_factory_ProcessingProcesses.hxx"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

class realization_RecurrentVoiceFileAndKeyMatchFinder :
	public RecurrentVoiceFileAndKeyMatchFinder,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals RecurrentVoiceFileAndKeyMatchFinder
	
	//~virtuals

	// virtuals MOVE_Runnable
	void run() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_RecurrentVoiceFileAndKeyMatchFinder() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ProcessingProcesses;
	realization_RecurrentVoiceFileAndKeyMatchFinder(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &sourceVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &destinationMatchedVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileForDeletionQueue,
		const ::jmsf::Proxy< KeyArray > &keyArray,
		const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter,
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > > > &voiceFileAndKeyPairMatchCheckerArray,
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &voiceFileContainer,
		const ::jmsf::Proxy< ::jmsf::osie::EventArray > &firstEventArray,
		const ::jmsf::Proxy< ::jmsf::osie::EventArray > &secondEventArray ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< RecurrentVoiceFileAndKeyMatchFinder > createClone() const throw();

private:
	realization_RecurrentVoiceFileAndKeyMatchFinder( const realization_RecurrentVoiceFileAndKeyMatchFinder &other ) throw();
	const realization_RecurrentVoiceFileAndKeyMatchFinder &operator =( const realization_RecurrentVoiceFileAndKeyMatchFinder &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _sourceVoiceFileQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > _destinationMatchedVoiceFileAndKeyPairQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _destinationVoiceFileForDeletionQueue;
	::jmsf::Proxy< KeyArray > _keyArray;
	const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > _fileFilter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > > > _voiceFileAndKeyPairMatchCheckerArray;

	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _voiceFileContainer;
	::jmsf::Proxy< ::jmsf::Iterator< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _voiceFileIterator;
	::jmsf::Proxy< ::jmsf::osie::EventArray > _objectAvailableAndContinueRunningAndFinalizeRunningEvents;
	::jmsf::Proxy< ::jmsf::osie::EventArray > _objectAvailableAndNewKeyAvailableAndContinueRunningAndFinalizeRunningEvents;

	::jmsf::Boolean _areAllAvailableVoiceFilesAndKeysProcessed;
	::jmsf::Boolean _wasAtLeastOneKeySelected;
};


} // namespace
}
}
}
