#pragma once

#include "../ProcessingQueues.h"
#include "jmsf/mixin_nulls/mixin_null_Object.h"
#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace nulls {


class null_ProcessingQueues :
	public ProcessingQueues,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_ProcessingQueues >
{

public:
	// virtuals ProcessingQueues
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > getOneselfNewVoiceFileQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > getOneselfVoiceFileForDecipheringQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > getOneselfVoiceFileForPreliminarySearchForAMatchWithKeyQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > getOneselfVoiceFileForRecurrentSearchForAMatchWithKeyQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, ::jmsf::VariousPair< ::jmsf::Proxy, externals::data::ed_VoiceFile, ::jmsf::ConstantProxy, externals::data::ed_Key > > > getOneselfNewVoiceFileAndKeyPairForImmediateMatchVerificationQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, ::jmsf::VariousPair< ::jmsf::Proxy, externals::data::ed_VoiceFile, ::jmsf::ConstantProxy, externals::data::ed_Key > > > getOneselfMatchedVoiceFileAndKeyPairQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > > getOneselfNewServiceFileQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::ConstantProxy, externals::data::ed_Key > > getOneselfNewKeyQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, ::jmsf::Pair< ::jmsf::Proxy, externals::data::ed_VoiceFile, externals::data::ed_ServiceFile > > > getOneselfDecipheredVoiceFileAndServiceFilePairForAppendingToStorageQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > getOneselfDecipheredVoiceFileForAppendingToStorageQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > > getOneselfDecipheredServiceFileForAppendingToStorageQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > getOneselfVoiceFileForDeletingQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > > getOneselfServiceFileForLastChanceMatchFindQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > > getOneselfServiceFileForDeletingQueue() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ProcessingQueues() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_ProcessingQueues >;
	static null_ProcessingQueues *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ProcessingQueues() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ProcessingQueues > createClone() const throw();

private:
	null_ProcessingQueues( const null_ProcessingQueues &other ) throw();
	const null_ProcessingQueues &operator =( const null_ProcessingQueues &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
