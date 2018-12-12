#pragma once

#include "jmsf/Object.h"

#include "externals/data/ed_VoiceFile.hxx"
#include "externals/data/ed_ServiceFile.hxx"
#include "externals/data/ed_Key.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"
#include "jmsf/Pair.hxx"
#include "jmsf/PointersAndProxies.hxx"

namespace nppntt {
namespace mdm {

class ProcessingQueues :
	public virtual ::jmsf::Object
{

public:
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeNewVoiceFileQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeVoiceFileForDecipheringQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeVoiceFileForPreliminarySearchForAMatchWithKeyQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeVoiceFileForRecurrentSearchForAMatchWithKeyQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &takeNewVoiceFileAndKeyPairForImmediateMatchVerificationQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &takeMatchedVoiceFileAndKeyPairQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeNewServiceFileQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::ConstantProxy< externals::data::ed_Key > > > &takeNewKeyQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > &takeDecipheredVoiceFileAndServiceFilePairForAppendingToStorageQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeDecipheredVoiceFileForAppendingToStorageQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeDecipheredServiceFileForAppendingToStorageQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeVoiceFileForDeletingQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeServiceFileForLastChanceMatchFindQueue() throw() = 0;	
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeServiceFileForDeletingQueue() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ProcessingQueues *getNull() throw();
	static ProcessingQueues *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< ProcessingQueues > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace mdm
} // namespace nppntt
