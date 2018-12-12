#include "realization_ResultServiceFileStatisticsProcess.h"
#include "../../externals/software/es_StatisticsUpdater.h"
#include "../../externals/data/ed_ServiceFile.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"

namespace nppntt {
namespace mdm {
namespace statistics {
namespace realizations {

void realization_ResultServiceFileStatisticsProcess::run() throw( ::jmsf::Exception ) {
	_sourceServiceFileQueue->takeMutex()->lock();

	if ( _sourceServiceFileQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceServiceFileQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::Proxy< externals::data::ed_ServiceFile > serviceFile = _sourceServiceFileQueue->withdrawFirst();
	_sourceServiceFileQueue->takeMutex()->unlock();
	_statisticsUpdater->updateResultServiceFile( serviceFile.getWeakConstant() );
	_destinationServiceFileQueue->takeMutex()->lock();
	_destinationServiceFileQueue->appendBack( serviceFile );
	_destinationServiceFileQueue->takeMutex()->unlock();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ResultServiceFileStatisticsProcess::~realization_ResultServiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ResultServiceFileStatisticsProcess::realization_ResultServiceFileStatisticsProcess(
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
::jmsf::Proxy< ResultServiceFileStatisticsProcess > realization_ResultServiceFileStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< ResultServiceFileStatisticsProcess >::createUnique( new realization_ResultServiceFileStatisticsProcess( *this ) );
}

realization_ResultServiceFileStatisticsProcess::realization_ResultServiceFileStatisticsProcess( const realization_ResultServiceFileStatisticsProcess & ) throw() // other
{}

const realization_ResultServiceFileStatisticsProcess &realization_ResultServiceFileStatisticsProcess::operator =( const realization_ResultServiceFileStatisticsProcess &other ) throw() {
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
