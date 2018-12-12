#include "realization_NewVoiceFileStatisticsProcess.h"
#include "../../externals/software/es_StatisticsUpdater.h"
#include "../../externals/data/ed_VoiceFile.h"
#include "jmsf/osie/EventArray.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace statistics {
namespace realizations {

void realization_NewVoiceFileStatisticsProcess::run() throw( ::jmsf::Exception ) {
	_sourceVoiceFileQueue->takeMutex()->lock();

	if ( _sourceVoiceFileQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceVoiceFileQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::Proxy< externals::data::ed_VoiceFile > voiceFile = _sourceVoiceFileQueue->withdrawFirst();
	_sourceVoiceFileQueue->takeMutex()->unlock();
	_statisticsUpdater->updateAppendedFiles( voiceFile.getWeakConstant() );
	_destinationVoiceFileQueue->takeMutex()->lock();
	_destinationVoiceFileQueue->appendBack( voiceFile );
	_destinationVoiceFileQueue->takeMutex()->unlock();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_NewVoiceFileStatisticsProcess::~realization_NewVoiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_NewVoiceFileStatisticsProcess::realization_NewVoiceFileStatisticsProcess(
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
::jmsf::Proxy< NewVoiceFileStatisticsProcess > realization_NewVoiceFileStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< NewVoiceFileStatisticsProcess >::createUnique( new realization_NewVoiceFileStatisticsProcess( *this ) );
}

realization_NewVoiceFileStatisticsProcess::realization_NewVoiceFileStatisticsProcess( const realization_NewVoiceFileStatisticsProcess & ) throw() // other
{}

const realization_NewVoiceFileStatisticsProcess &realization_NewVoiceFileStatisticsProcess::operator =( const realization_NewVoiceFileStatisticsProcess &other ) throw() {
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
