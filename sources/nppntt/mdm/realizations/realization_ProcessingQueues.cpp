#include "realization_ProcessingQueues.h"
#include "../externals/data/ed_VoiceFile.h"
#include "../externals/data/ed_ServiceFile.h"
#include "../externals/data/ed_Key.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/osie/Event.h"
#include "jmsf/Pair.hpp"
#include "jmsf/Pointers.hpp"

namespace nppntt {
namespace mdm {
namespace realizations {

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &impl_ProcessingQueues::takeNewVoiceFileQueue() throw() {
	return _newVoiceFileQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &impl_ProcessingQueues::takeVoiceFileForDecipheringQueue() throw() {
	return _voiceFileForDecipheringQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &impl_ProcessingQueues::takeVoiceFileForPreliminarySearchForAMatchWithKeyQueue() throw() {
	return _voiceFileForPreliminarySearchForAMatchWithKeyQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &impl_ProcessingQueues::takeVoiceFileForRecurrentSearchForAMatchWithKeyQueue() throw() {
	return _voiceFileForRecurrentSearchForAMatchWithKeyQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &impl_ProcessingQueues::takeNewVoiceFileAndKeyPairForImmediateMatchVerificationQueue() throw() {
	return _newVoiceFileAndKeyPairForImmediateMatchVerificationQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &impl_ProcessingQueues::takeMatchedVoiceFileAndKeyPairQueue() throw() {
	return _matchedVoiceFileAndKeyPairQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &impl_ProcessingQueues::takeNewServiceFileQueue() throw() {
	return _newServiceFileQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::ConstantProxy< externals::data::ed_Key > > > &impl_ProcessingQueues::takeNewKeyQueue() throw() {
	return _newKeyQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > &impl_ProcessingQueues::takeDecipheredVoiceFileAndServiceFilePairForAppendingToStorageQueue() throw() {
	return _decipheredVoiceFileAndServiceFilePairForAppendingToStorageQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &impl_ProcessingQueues::takeDecipheredVoiceFileForAppendingToStorageQueue() throw() {
	return _decipheredVoiceFileForAppendingToStorageQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &impl_ProcessingQueues::takeDecipheredServiceFileForAppendingToStorageQueue() throw() {
	return _decipheredServiceFileForAppendingToStorageQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &impl_ProcessingQueues::takeVoiceFileForDeletingQueue() throw() {
	return _voiceFileForDeletingQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &impl_ProcessingQueues::takeServiceFileForLastChanceMatchFindQueue() throw() {
	return _serviceFileForLastChanceMatchFindQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &impl_ProcessingQueues::takeServiceFileForDeletingQueue() throw() {
	return _serviceFileForDeletingQueue;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
impl_ProcessingQueues::~impl_ProcessingQueues() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
impl_ProcessingQueues::impl_ProcessingQueues(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &newVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &voiceFileForDecipheringQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &voiceFileForPreliminarySearchForAMatchWithKeyQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &voiceFileForRecurrentSearchForAMatchWithKeyQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &newVoiceFileAndKeyPairForImmediateMatchVerificationQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &matchedVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &newServiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::ConstantProxy< externals::data::ed_Key > > > &newKeyQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > &decipheredVoiceFileAndServiceFilePairForAppendingToStorageQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &decipheredVoiceFileForAppendingToStorageQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &decipheredServiceFileForAppendingToStorageQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &voiceFileForDeletingQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &serviceFileForLastChanceMatchFindQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &serviceFileForDeletingQueue ) throw()
	:
		_newVoiceFileQueue( newVoiceFileQueue ),
		_voiceFileForDecipheringQueue( voiceFileForDecipheringQueue ),
		_voiceFileForPreliminarySearchForAMatchWithKeyQueue( voiceFileForPreliminarySearchForAMatchWithKeyQueue ),
		_voiceFileForRecurrentSearchForAMatchWithKeyQueue( voiceFileForRecurrentSearchForAMatchWithKeyQueue ),
		_newVoiceFileAndKeyPairForImmediateMatchVerificationQueue( newVoiceFileAndKeyPairForImmediateMatchVerificationQueue ),
		_matchedVoiceFileAndKeyPairQueue( matchedVoiceFileAndKeyPairQueue ),
		_newServiceFileQueue( newServiceFileQueue ),
		_newKeyQueue( newKeyQueue ),
		_decipheredVoiceFileAndServiceFilePairForAppendingToStorageQueue( decipheredVoiceFileAndServiceFilePairForAppendingToStorageQueue ),
		_decipheredVoiceFileForAppendingToStorageQueue( decipheredVoiceFileForAppendingToStorageQueue ),
		_decipheredServiceFileForAppendingToStorageQueue( decipheredServiceFileForAppendingToStorageQueue ),
		_voiceFileForDeletingQueue( voiceFileForDeletingQueue ),
		_serviceFileForLastChanceMatchFindQueue( serviceFileForLastChanceMatchFindQueue ),
		_serviceFileForDeletingQueue( serviceFileForDeletingQueue )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ProcessingQueues > impl_ProcessingQueues::createClone() const throw() {
	return ::jmsf::Proxy< ProcessingQueues >::createUnique( new impl_ProcessingQueues( *this ) );
}

impl_ProcessingQueues::impl_ProcessingQueues( const impl_ProcessingQueues & ) throw() // other
{}

const impl_ProcessingQueues &impl_ProcessingQueues::operator =( const impl_ProcessingQueues &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
