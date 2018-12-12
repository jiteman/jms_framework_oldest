#include "realization_ResultVoiceFileAndServiceFilePairStatisticsProcess.h"
#include "../../externals/software/es_StatisticsUpdater.h"
#include "../../externals/data/ed_VoiceFile.h"
#include "../../externals/data/ed_ServiceFile.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/factory_Pair.hpp"
#include "jmsf/Pair.hpp"

namespace nppntt {
namespace mdm {
namespace statistics {
namespace realizations {

void realization_ResultVoiceFileAndServiceFilePairStatisticsProcess::run() throw( ::jmsf::Exception ) {
	_sourceVoiceFileAndServiceFilePairQueue->takeMutex()->lock();

	if ( _sourceVoiceFileAndServiceFilePairQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceVoiceFileAndServiceFilePairQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > voiceFileAndServiceFilePair =
		_sourceVoiceFileAndServiceFilePairQueue->withdrawFirst();

	_sourceVoiceFileAndServiceFilePairQueue->takeMutex()->unlock();

	const ::jmsf::ConstantProxy< ::jmsf::Pair< ::jmsf::ConstantProxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_ServiceFile > > > constantVoiceFileAndServiceFilePair =
		::jmsf::factory_Pair< ::jmsf::ConstantProxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_ServiceFile > >::instance()->createPair(
			voiceFileAndServiceFilePair->getFirst().getWeakConstant(),
			voiceFileAndServiceFilePair->getSecond().getWeakConstant() ).takeConstant();

	_statisticsUpdater->updateResultVoiceFileAndServiceFilePair( constantVoiceFileAndServiceFilePair.getWeak() );
	_destinationVoiceFileAndServiceFilePairQueue->takeMutex()->lock();
	_destinationVoiceFileAndServiceFilePairQueue->appendBack( voiceFileAndServiceFilePair );
	_destinationVoiceFileAndServiceFilePairQueue->takeMutex()->unlock();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ResultVoiceFileAndServiceFilePairStatisticsProcess::~realization_ResultVoiceFileAndServiceFilePairStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ResultVoiceFileAndServiceFilePairStatisticsProcess::realization_ResultVoiceFileAndServiceFilePairStatisticsProcess(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > &sourceVoiceFileAndServiceFilePairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > &destinationVoiceFileAndServiceFilePairQueue,
		const ::jmsf::Proxy< externals::software::es_StatisticsUpdater > &statisticsUpdater ) throw()
	:
		_sourceVoiceFileAndServiceFilePairQueue( sourceVoiceFileAndServiceFilePairQueue ),
		_destinationVoiceFileAndServiceFilePairQueue( destinationVoiceFileAndServiceFilePairQueue ),
		_statisticsUpdater( statisticsUpdater )
{
//	appendWaitableEvent( _sourceVoiceFileAndServiceFilePairQueue->getOneselfIsObjectAvailableEvent() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ResultVoiceFileAndServiceFilePairStatisticsProcess > realization_ResultVoiceFileAndServiceFilePairStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< ResultVoiceFileAndServiceFilePairStatisticsProcess >::createUnique( new realization_ResultVoiceFileAndServiceFilePairStatisticsProcess( *this ) );
}

realization_ResultVoiceFileAndServiceFilePairStatisticsProcess::realization_ResultVoiceFileAndServiceFilePairStatisticsProcess( const realization_ResultVoiceFileAndServiceFilePairStatisticsProcess & ) throw() // other
{}

const realization_ResultVoiceFileAndServiceFilePairStatisticsProcess &realization_ResultVoiceFileAndServiceFilePairStatisticsProcess::operator =( const realization_ResultVoiceFileAndServiceFilePairStatisticsProcess &other ) throw() {
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
