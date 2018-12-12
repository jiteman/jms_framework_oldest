#include "null_ProcessingQueues.h"

#include "../externals/data/ed_VoiceFile.h"
#include "../externals/data/ed_ServiceFile.h"
#include "../externals/data/ed_Key.h"

#include "jmsf/mtf/SynchronizedQueue.hpp"

#include "jmsf/Pairs.hpp"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace nulls {


::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > null_ProcessingQueues::getOneselfNewVoiceFileQueue() throw() {
	return ::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > >();
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > null_ProcessingQueues::getOneselfVoiceFileForDecipheringQueue() throw() {
	return ::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > >();
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > null_ProcessingQueues::getOneselfVoiceFileForPreliminarySearchForAMatchWithKeyQueue() throw() {
	return ::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > >();
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > null_ProcessingQueues::getOneselfVoiceFileForRecurrentSearchForAMatchWithKeyQueue() throw() {
	return ::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > >();
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, ::jmsf::VariousPair< ::jmsf::Proxy, externals::data::ed_VoiceFile, ::jmsf::ConstantProxy, externals::data::ed_Key > > > null_ProcessingQueues::getOneselfNewVoiceFileAndKeyPairForImmediateMatchVerificationQueue() throw() {
	return ::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, ::jmsf::VariousPair< ::jmsf::Proxy, externals::data::ed_VoiceFile, ::jmsf::ConstantProxy, externals::data::ed_Key > > >();
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, ::jmsf::VariousPair< ::jmsf::Proxy, externals::data::ed_VoiceFile, ::jmsf::ConstantProxy, externals::data::ed_Key > > > null_ProcessingQueues::getOneselfMatchedVoiceFileAndKeyPairQueue() throw() {
	return ::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, ::jmsf::VariousPair< ::jmsf::Proxy, externals::data::ed_VoiceFile, ::jmsf::ConstantProxy, externals::data::ed_Key > > >();
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > > null_ProcessingQueues::getOneselfNewServiceFileQueue() throw() {
	return ::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > >();
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::ConstantProxy, externals::data::ed_Key > > null_ProcessingQueues::getOneselfNewKeyQueue() throw() {
	return ::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::ConstantProxy, externals::data::ed_Key > >();
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, ::jmsf::Pair< ::jmsf::Proxy, externals::data::ed_VoiceFile, externals::data::ed_ServiceFile > > > null_ProcessingQueues::getOneselfDecipheredVoiceFileAndServiceFilePairForAppendingToStorageQueue() throw() {
	return ::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, ::jmsf::Pair< ::jmsf::Proxy, externals::data::ed_VoiceFile, externals::data::ed_ServiceFile > > >();
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > null_ProcessingQueues::getOneselfDecipheredVoiceFileForAppendingToStorageQueue() throw() {
	return ::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > >();
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > > null_ProcessingQueues::getOneselfDecipheredServiceFileForAppendingToStorageQueue() throw() {
	return ::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > >();
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > null_ProcessingQueues::getOneselfVoiceFileForDeletingQueue() throw() {
	return ::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > >();
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > > null_ProcessingQueues::getOneselfServiceFileForLastChanceMatchFindQueue() throw() {
	return ::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > >();
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > > null_ProcessingQueues::getOneselfServiceFileForDeletingQueue() throw() {
	return ::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > >();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ProcessingQueues::~null_ProcessingQueues() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ProcessingQueues *null_ProcessingQueues::createInstance() throw() {
	return new null_ProcessingQueues;
}

null_ProcessingQueues::null_ProcessingQueues() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ProcessingQueues > null_ProcessingQueues::createClone() const throw() {
	return ::jmsf::Proxy< ProcessingQueues >::createUnique( this );
}

null_ProcessingQueues::null_ProcessingQueues( const null_ProcessingQueues & ) throw() // other
{}

const null_ProcessingQueues &null_ProcessingQueues::operator =( const null_ProcessingQueues &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
