#include "null_StatisticsQueues.h"

#include "../externals/data/ed_VoiceFile.h"
#include "../externals/data/ed_ServiceFile.h"
#include "../externals/data/ed_Key.h"

#include "jmsf/mtf/SynchronizedQueue.hpp"

#include "jmsf/Pairs.hpp"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace nulls {


::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > null_StatisticsQueues::getOneselfNewVoiceFileStatisticsQueue() throw() {
	return _voiceFileQueue;
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > > null_StatisticsQueues::getOneselfNewServiceFileStatisticsQueue() throw() {
	return _serviceFileQueue;
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > null_StatisticsQueues::getOneselfVoiceFileForDecipheringStatisticsQueue() throw() {
	return _voiceFileQueue;
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, ::jmsf::VariousPair< ::jmsf::Proxy, externals::data::ed_VoiceFile, ::jmsf::ConstantProxy, externals::data::ed_Key > > > null_StatisticsQueues::getOneselfDecipheredVoiceFileAndKeyPairStatisticsQueue() throw() {
	return _voiceFileAndKeyPairQueue;
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > null_StatisticsQueues::getOneselfNotDecipheredVoiceFileStatisticsQueue() throw() {
	return _voiceFileQueue;
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, ::jmsf::Pair< ::jmsf::Proxy, externals::data::ed_VoiceFile, externals::data::ed_ServiceFile > > > null_StatisticsQueues::getOneselfResultVoiceFileAndServiceFilePairStatisticsQueue() throw() {
	return _voiceFileAndServiceFilePairQueue;
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > null_StatisticsQueues::getOneselfResultVoiceFileStatisticsQueue() throw() {
	return _voiceFileQueue;
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > > null_StatisticsQueues::getOneselfResultServiceFileStatisticsQueue() throw() {
	return _serviceFileQueue;
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_VoiceFile > > null_StatisticsQueues::getOneselfDeletedVoiceFileStatisticsQueue() throw() {
	return _voiceFileQueue;
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy, externals::data::ed_ServiceFile > > null_StatisticsQueues::getOneselfDeletedServiceFileStatisticsQueue() throw() {
	return _serviceFileQueue;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_StatisticsQueues::~null_StatisticsQueues() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_StatisticsQueues *null_StatisticsQueues::createInstance() throw() {
	return new null_StatisticsQueues;
}

null_StatisticsQueues::null_StatisticsQueues() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< StatisticsQueues > null_StatisticsQueues::createClone() const throw() {
	return ::jmsf::Proxy< StatisticsQueues >::createUnique( this );
}

null_StatisticsQueues::null_StatisticsQueues( const null_StatisticsQueues & ) throw() // other
{}

const null_StatisticsQueues &null_StatisticsQueues::operator =( const null_StatisticsQueues &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
