#include "realization_NotDecipheredVoiceFileStatisticsProcess.h"
#include "../../externals/software/es_StatisticsUpdater.h"
#include "../../externals/data/ed_VoiceFile.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"

namespace nppntt {
namespace mdm {
namespace statistics {
namespace realizations {

void realization_NotDecipheredVoiceFileStatisticsProcess::run() throw( ::jmsf::Exception ) {
	_sourceVoiceFileQueue->takeMutex()->lock();

	if ( _sourceVoiceFileQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceVoiceFileQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::Proxy< externals::data::ed_VoiceFile > voiceFile = _sourceVoiceFileQueue->withdrawFirst();
	_sourceVoiceFileQueue->takeMutex()->unlock();
	_statisticsUpdater->updateNotDecipheredVoiceFile( voiceFile.getWeakConstant() );
	_destinationVoiceFileQueue->takeMutex()->lock();
	_destinationVoiceFileQueue->appendBack( voiceFile );
	_destinationVoiceFileQueue->takeMutex()->unlock();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_NotDecipheredVoiceFileStatisticsProcess::~realization_NotDecipheredVoiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_NotDecipheredVoiceFileStatisticsProcess::realization_NotDecipheredVoiceFileStatisticsProcess(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &sourceVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileQueue,
		const ::jmsf::Proxy< externals::software::es_StatisticsUpdater > &statisticsUpdater ) throw()
	:
		_sourceVoiceFileQueue( sourceVoiceFileQueue ),
		_destinationVoiceFileQueue( destinationVoiceFileQueue ),
		_statisticsUpdater( statisticsUpdater )
{
//	appendWaitableEvent( _sourceVoiceFileQueue->getOneselfIsObjectAvailableEvent() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< NotDecipheredVoiceFileStatisticsProcess > realization_NotDecipheredVoiceFileStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< NotDecipheredVoiceFileStatisticsProcess >::createUnique( new realization_NotDecipheredVoiceFileStatisticsProcess( *this ) );
}

realization_NotDecipheredVoiceFileStatisticsProcess::realization_NotDecipheredVoiceFileStatisticsProcess( const realization_NotDecipheredVoiceFileStatisticsProcess & ) throw() // other
{}

const realization_NotDecipheredVoiceFileStatisticsProcess &realization_NotDecipheredVoiceFileStatisticsProcess::operator =( const realization_NotDecipheredVoiceFileStatisticsProcess &other ) throw() {
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
