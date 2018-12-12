#pragma once

#include "../StatisticsQueues.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace nulls {


class null_StatisticsQueues :
	public StatisticsQueues,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_StatisticsQueues >
{

public:
	// virtuals StatisticsQueues
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > getOneselfNewVoiceFileStatisticsQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > > getOneselfNewServiceFileStatisticsQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > getOneselfVoiceFileForDecipheringStatisticsQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, ::jmsf::VariousPair< ::jmsf::Proxy, externals::data::ed_VoiceFile, ::jmsf::ConstantProxy, externals::data::ed_Key > > > getOneselfDecipheredVoiceFileAndKeyPairStatisticsQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > getOneselfNotDecipheredVoiceFileStatisticsQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, ::jmsf::Pair< ::jmsf::Proxy, externals::data::ed_VoiceFile, externals::data::ed_ServiceFile > > > getOneselfResultVoiceFileAndServiceFilePairStatisticsQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > getOneselfResultVoiceFileStatisticsQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > > getOneselfResultServiceFileStatisticsQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > getOneselfDeletedVoiceFileStatisticsQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > > getOneselfDeletedServiceFileStatisticsQueue() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_StatisticsQueues() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_StatisticsQueues >;
	static null_StatisticsQueues *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_StatisticsQueues() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< StatisticsQueues > createClone() const throw();

private:
	null_StatisticsQueues( const null_StatisticsQueues &other ) throw();
	const null_StatisticsQueues &operator =( const null_StatisticsQueues &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > _voiceFileQueue;
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, ::jmsf::VariousPair< ::jmsf::Proxy, externals::data::ed_VoiceFile, ::jmsf::ConstantProxy, externals::data::ed_Key > > > _voiceFileAndKeyPairQueue;
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, ::jmsf::Pair< ::jmsf::Proxy, externals::data::ed_VoiceFile, externals::data::ed_ServiceFile > > > _voiceFileAndServiceFilePairQueue;
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > > _serviceFileQueue;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
