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

class StatisticsQueues :
	public virtual ::jmsf::Object
{

public:
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeNewVoiceFileStatisticsQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeNewServiceFileStatisticsQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeVoiceFileForDecipheringStatisticsQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > >&takeDecipheredVoiceFileAndKeyPairStatisticsQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeNotDecipheredVoiceFileStatisticsQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > >&takeResultVoiceFileAndServiceFilePairStatisticsQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeResultVoiceFileStatisticsQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeResultServiceFileStatisticsQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeDeletedVoiceFileStatisticsQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeDeletedServiceFileStatisticsQueue() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static StatisticsQueues *getNull() throw();
	static StatisticsQueues *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< StatisticsQueues > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace mdm
} // namespace nppntt
