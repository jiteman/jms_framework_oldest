#include "realization_DeletedVoiceFileStatisticsProcess.h"
#include "../../externals/software/es_StatisticsUpdater.h"
#include "../../externals/data/ed_VoiceFile.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"

namespace nppntt {
namespace mdm {
namespace statistics {
namespace realizations {

void realization_DeletedVoiceFileStatisticsProcess::run() throw( ::jmsf::Exception ) {
	_sourceVoiceFileQueue->takeMutex()->lock();

	if ( _sourceVoiceFileQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceVoiceFileQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::Proxy< externals::data::ed_VoiceFile > voiceFile = _sourceVoiceFileQueue->withdrawFirst();
	_sourceVoiceFileQueue->takeMutex()->unlock();
	_statisticsUpdater->updateDeletedFiles( voiceFile.getWeakConstant() );
	_destinationVoiceFileQueue->takeMutex()->lock();
	_destinationVoiceFileQueue->appendBack( voiceFile );
	_destinationVoiceFileQueue->takeMutex()->unlock();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_DeletedVoiceFileStatisticsProcess::~realization_DeletedVoiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_DeletedVoiceFileStatisticsProcess::realization_DeletedVoiceFileStatisticsProcess(
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
::jmsf::Proxy< DeletedVoiceFileStatisticsProcess > realization_DeletedVoiceFileStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< DeletedVoiceFileStatisticsProcess >::createUnique( new realization_DeletedVoiceFileStatisticsProcess( *this ) );
}

realization_DeletedVoiceFileStatisticsProcess::realization_DeletedVoiceFileStatisticsProcess( const realization_DeletedVoiceFileStatisticsProcess & ) throw() // other
{}

const realization_DeletedVoiceFileStatisticsProcess &realization_DeletedVoiceFileStatisticsProcess::operator =( const realization_DeletedVoiceFileStatisticsProcess &other ) throw() {
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
