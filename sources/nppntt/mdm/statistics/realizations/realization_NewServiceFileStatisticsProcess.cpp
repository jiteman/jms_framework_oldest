#include "realization_NewServiceFileStatisticsProcess.h"
#include "../../externals/software/es_StatisticsUpdater.h"
#include "../../externals/data/ed_ServiceFile.h"
#include "jmsf/osie/EventArray.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace statistics {
namespace realizations {

void realization_NewServiceFileStatisticsProcess::run() throw( ::jmsf::Exception ) {
	_sourceServiceFileQueue->takeMutex()->lock();

	if ( _sourceServiceFileQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceServiceFileQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::Proxy< externals::data::ed_ServiceFile > serviceFile = _sourceServiceFileQueue->withdrawFirst();
	_sourceServiceFileQueue->takeMutex()->unlock();
	_statisticsUpdater->updateAppendedFiles( serviceFile.getWeakConstant() );
	_destinationServiceFileQueue->takeMutex()->lock();
	_destinationServiceFileQueue->appendBack( serviceFile );
	_destinationServiceFileQueue->takeMutex()->unlock();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_NewServiceFileStatisticsProcess::~realization_NewServiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_NewServiceFileStatisticsProcess::realization_NewServiceFileStatisticsProcess(
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
::jmsf::Proxy< NewServiceFileStatisticsProcess > realization_NewServiceFileStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< NewServiceFileStatisticsProcess >::createUnique( new realization_NewServiceFileStatisticsProcess( *this ) );
}

realization_NewServiceFileStatisticsProcess::realization_NewServiceFileStatisticsProcess( const realization_NewServiceFileStatisticsProcess & ) throw() // other
{}

const realization_NewServiceFileStatisticsProcess &realization_NewServiceFileStatisticsProcess::operator =( const realization_NewServiceFileStatisticsProcess &other ) throw() {
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
