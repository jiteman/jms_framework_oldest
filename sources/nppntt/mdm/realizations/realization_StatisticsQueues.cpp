#include "realization_StatisticsQueues.h"
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

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &impl_StatisticsQueues::takeNewVoiceFileStatisticsQueue() throw() {
	return _newVoiceFileStatisticsQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &impl_StatisticsQueues::takeNewServiceFileStatisticsQueue() throw() {
	return _newServiceFileStatisticsQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &impl_StatisticsQueues::takeVoiceFileForDecipheringStatisticsQueue() throw() {
	return _voiceFileForDecipheringStatisticsQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &impl_StatisticsQueues::takeDecipheredVoiceFileAndKeyPairStatisticsQueue() throw() {
	return _decipheredVoiceFileAndKeyPairStatisticsQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &impl_StatisticsQueues::takeNotDecipheredVoiceFileStatisticsQueue() throw() {
	return _notDecipheredVoiceFileStatisticsQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > &impl_StatisticsQueues::takeResultVoiceFileAndServiceFilePairStatisticsQueue() throw() {
	return _resultVoiceFileAndServiceFilePairStatisticsQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &impl_StatisticsQueues::takeResultVoiceFileStatisticsQueue() throw() {
	return _resultVoiceFileStatisticsQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &impl_StatisticsQueues::takeResultServiceFileStatisticsQueue() throw() {
	return _resultServiceFileStatisticsQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &impl_StatisticsQueues::takeDeletedVoiceFileStatisticsQueue() throw() {
	return _deletedVoiceFileStatisticsQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &impl_StatisticsQueues::takeDeletedServiceFileStatisticsQueue() throw() {
	return _deletedServiceFileStatisticsQueue;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
impl_StatisticsQueues::~impl_StatisticsQueues() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
impl_StatisticsQueues::impl_StatisticsQueues(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &newVoiceFileStatisticsQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &newServiceFileStatisticsQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &voiceFileForDecipheringStatisticsQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &decipheredVoiceFileAndKeyPairStatisticsQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &notDecipheredVoiceFileStatisticsQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > &resultVoiceFileAndServiceFilePairStatisticsQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &resultVoiceFileStatisticsQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &resultServiceFileStatisticsQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &deletedVoiceFileStatisticsQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &deletedServiceFileStatisticsQueue ) throw()
	:
		_newVoiceFileStatisticsQueue( newVoiceFileStatisticsQueue ),
		_newServiceFileStatisticsQueue( newServiceFileStatisticsQueue ),
		_voiceFileForDecipheringStatisticsQueue( voiceFileForDecipheringStatisticsQueue ),
		_decipheredVoiceFileAndKeyPairStatisticsQueue( decipheredVoiceFileAndKeyPairStatisticsQueue ),
		_notDecipheredVoiceFileStatisticsQueue( notDecipheredVoiceFileStatisticsQueue ),
		_resultVoiceFileAndServiceFilePairStatisticsQueue( resultVoiceFileAndServiceFilePairStatisticsQueue ),
		_resultVoiceFileStatisticsQueue( resultVoiceFileStatisticsQueue ),
		_resultServiceFileStatisticsQueue( resultServiceFileStatisticsQueue ),
		_deletedVoiceFileStatisticsQueue( deletedVoiceFileStatisticsQueue ),
		_deletedServiceFileStatisticsQueue( deletedServiceFileStatisticsQueue )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< StatisticsQueues > impl_StatisticsQueues::createClone() const throw() {
	return ::jmsf::Proxy< StatisticsQueues >::createUnique( new impl_StatisticsQueues( *this ) );
}

impl_StatisticsQueues::impl_StatisticsQueues( const impl_StatisticsQueues & ) throw() // other
{}

const impl_StatisticsQueues &impl_StatisticsQueues::operator =( const impl_StatisticsQueues &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
