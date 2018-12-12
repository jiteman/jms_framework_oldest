#include "realization_DecipheredVoiceFileAndKeyPairStatisticsProcess.h"
#include "../../externals/software/es_StatisticsUpdater.h"
#include "../../externals/data/ed_VoiceFile.h"
#include "../../externals/data/ed_Key.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/Pair.hpp"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace statistics {
namespace realizations {

void realization_DecipheredVoiceFileAndKeyPairStatisticsProcess::run() throw( ::jmsf::Exception ) {
	_sourceVoiceFileAndKeyPairQueue->takeMutex()->lock();

	if ( _sourceVoiceFileAndKeyPairQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceVoiceFileAndKeyPairQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > voiceFileAndKeyPair =
		_sourceVoiceFileAndKeyPairQueue->withdrawFirst();

	_sourceVoiceFileAndKeyPairQueue->takeMutex()->unlock();
	_statisticsUpdater->updateDecipheredVoiceFile( voiceFileAndKeyPair->getFirst().getWeakConstant() );
	_destinationVoiceFileAndKeyPairQueue->takeMutex()->lock();
	_destinationVoiceFileAndKeyPairQueue->appendBack( voiceFileAndKeyPair );
	_destinationVoiceFileAndKeyPairQueue->takeMutex()->unlock();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_DecipheredVoiceFileAndKeyPairStatisticsProcess::~realization_DecipheredVoiceFileAndKeyPairStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_DecipheredVoiceFileAndKeyPairStatisticsProcess::realization_DecipheredVoiceFileAndKeyPairStatisticsProcess(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &sourceVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &destinationVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< externals::software::es_StatisticsUpdater > &statisticsUpdater ) throw()
	:
		_sourceVoiceFileAndKeyPairQueue( sourceVoiceFileAndKeyPairQueue ),
		_destinationVoiceFileAndKeyPairQueue( destinationVoiceFileAndKeyPairQueue ),
		_statisticsUpdater( statisticsUpdater )
{
//	appendWaitableEvent( _sourceVoiceFileAndKeyPairQueue->getOneselfIsObjectAvailableEvent() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< DecipheredVoiceFileAndKeyPairStatisticsProcess > realization_DecipheredVoiceFileAndKeyPairStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< DecipheredVoiceFileAndKeyPairStatisticsProcess >::createUnique( new realization_DecipheredVoiceFileAndKeyPairStatisticsProcess( *this ) );
}

realization_DecipheredVoiceFileAndKeyPairStatisticsProcess::realization_DecipheredVoiceFileAndKeyPairStatisticsProcess( const realization_DecipheredVoiceFileAndKeyPairStatisticsProcess & ) throw() // other
{}

const realization_DecipheredVoiceFileAndKeyPairStatisticsProcess &realization_DecipheredVoiceFileAndKeyPairStatisticsProcess::operator =( const realization_DecipheredVoiceFileAndKeyPairStatisticsProcess &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
}
