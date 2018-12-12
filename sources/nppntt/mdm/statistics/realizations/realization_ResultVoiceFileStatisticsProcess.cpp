#include "realization_ResultVoiceFileStatisticsProcess.h"
#include "../../externals/software/es_StatisticsUpdater.h"
#include "../../externals/data/ed_VoiceFile.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"

namespace nppntt {
namespace mdm {
namespace statistics {
namespace realizations {

void realization_ResultVoiceFileStatisticsProcess::run() throw( ::jmsf::Exception ) {
	_sourceVoiceFileQueue->takeMutex()->lock();

	if ( _sourceVoiceFileQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceVoiceFileQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::Proxy< externals::data::ed_VoiceFile > voiceFile = _sourceVoiceFileQueue->withdrawFirst();
	_sourceVoiceFileQueue->takeMutex()->unlock();
	_statisticsUpdater->updateResultVoiceFile( voiceFile.getWeakConstant() );
	_destinationVoiceFileQueue->takeMutex()->lock();
	_destinationVoiceFileQueue->appendBack( voiceFile );
	_destinationVoiceFileQueue->takeMutex()->unlock();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ResultVoiceFileStatisticsProcess::~realization_ResultVoiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ResultVoiceFileStatisticsProcess::realization_ResultVoiceFileStatisticsProcess(
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
::jmsf::Proxy< ResultVoiceFileStatisticsProcess > realization_ResultVoiceFileStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< ResultVoiceFileStatisticsProcess >::createUnique( new realization_ResultVoiceFileStatisticsProcess( *this ) );
}

realization_ResultVoiceFileStatisticsProcess::realization_ResultVoiceFileStatisticsProcess( const realization_ResultVoiceFileStatisticsProcess & ) throw() // other
{}

const realization_ResultVoiceFileStatisticsProcess &realization_ResultVoiceFileStatisticsProcess::operator =( const realization_ResultVoiceFileStatisticsProcess &other ) throw() {
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
