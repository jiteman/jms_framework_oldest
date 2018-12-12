#include "realization_DeletedServiceFileStatisticsProcess.h"
#include "../../externals/software/es_StatisticsUpdater.h"
#include "../../externals/data/ed_ServiceFile.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"

namespace nppntt {
namespace mdm {
namespace statistics {
namespace realizations {

void realization_DeletedServiceFileStatisticsProcess::run() throw( ::jmsf::Exception ) {
	_sourceServiceFileQueue->takeMutex()->lock();

	if ( _sourceServiceFileQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceServiceFileQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::Proxy< externals::data::ed_ServiceFile > serviceFile = _sourceServiceFileQueue->withdrawFirst();
	_sourceServiceFileQueue->takeMutex()->unlock();
	_statisticsUpdater->updateDeletedFiles( serviceFile.getWeakConstant() );
	_destinationServiceFileQueue->takeMutex()->lock();
	_destinationServiceFileQueue->appendBack( serviceFile );
	_destinationServiceFileQueue->takeMutex()->unlock();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_DeletedServiceFileStatisticsProcess::~realization_DeletedServiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_DeletedServiceFileStatisticsProcess::realization_DeletedServiceFileStatisticsProcess(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &sourceServiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileQueue,
		const ::jmsf::Proxy< externals::software::es_StatisticsUpdater > &statisticsUpdater ) throw()
	:
		_sourceServiceFileQueue( sourceServiceFileQueue ),
		_destinationServiceFileQueue( destinationServiceFileQueue ),
		_statisticsUpdater( statisticsUpdater )
{
//	appendWaitableEvent( _sourceServiceFileQueue->getOneselfIsObjectAvailableEvent() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< DeletedServiceFileStatisticsProcess > realization_DeletedServiceFileStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< DeletedServiceFileStatisticsProcess >::createUnique( new realization_DeletedServiceFileStatisticsProcess( *this ) );
}

realization_DeletedServiceFileStatisticsProcess::realization_DeletedServiceFileStatisticsProcess( const realization_DeletedServiceFileStatisticsProcess & ) throw() // other
{}

const realization_DeletedServiceFileStatisticsProcess &realization_DeletedServiceFileStatisticsProcess::operator =( const realization_DeletedServiceFileStatisticsProcess &other ) throw() {
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
