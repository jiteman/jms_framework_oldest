#include "realization_StatisticsProcesses.h"
#include "../statistics/NewVoiceFileStatisticsProcess.h"
#include "../statistics/NewServiceFileStatisticsProcess.h"
#include "../statistics/VoiceFileForDecipheringStatisticsProcess.h"
#include "../statistics/DecipheredVoiceFileAndKeyPairStatisticsProcess.h"
#include "../statistics/NotDecipheredVoiceFileStatisticsProcess.h"
#include "../statistics/ResultVoiceFileAndServiceFilePairStatisticsProcess.h"
#include "../statistics/ResultVoiceFileStatisticsProcess.h"
#include "../statistics/ResultServiceFileStatisticsProcess.h"
#include "../statistics/DeletedVoiceFileStatisticsProcess.h"
#include "../statistics/DeletedServiceFileStatisticsProcess.h"
#include "jmsf/mtf/Thread.h"
#include "jmsf/Container.hpp"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace realizations {

::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess > &realization_StatisticsProcesses::takeNewVoiceFileStatisticsProcess() throw() {
	return _newVoiceFileStatisticsProcess;
}

::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess > &realization_StatisticsProcesses::takeNewServiceFileStatisticsProcess() throw() {
	return _newServiceFileStatisticsProcess;
}

::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess > &realization_StatisticsProcesses::takeVoiceFileForDecipheringStatisticsProcess() throw() {
	return _voiceFileForDecipheringStatisticsProcess;
}

::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess > &realization_StatisticsProcesses::takeDecipheredVoiceFileAndKeyPairStatisticsProcess() throw() {
	return _decipheredVoiceFileAndKeyPairStatisticsProcess;
}

::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess > &realization_StatisticsProcesses::takeNotDecipheredVoiceFileStatisticsProcess() throw() {
	return _notDecipheredVoiceFileStatisticsProcess;
}

::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess > &realization_StatisticsProcesses::takeResultVoiceFileAndServiceFilePairStatisticsProcess() throw() {
	return _resultVoiceFileAndServiceFilePairStatisticsProcess;
}

::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess > &realization_StatisticsProcesses::takeResultVoiceFileStatisticsProcess() throw() {
	return _resultVoiceFileStatisticsProcess;
}

::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess > &realization_StatisticsProcesses::takeResultServiceFileStatisticsProcess() throw() {
	return _resultServiceFileStatisticsProcess;
}

::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess > &realization_StatisticsProcesses::takeDeletedVoiceFileStatisticsProcess() throw() {
	return _deletedVoiceFileStatisticsProcess;
}

::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess > &realization_StatisticsProcesses::takeDeletedServiceFileStatisticsProcess() throw() {
	return _deletedServiceFileStatisticsProcess;
}

::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &realization_StatisticsProcesses::takeThreadContainer() throw() {
	return _threadContainer;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_StatisticsProcesses::~realization_StatisticsProcesses() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_StatisticsProcesses::realization_StatisticsProcesses(
		const ::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess > &newVoiceFileStatisticsProcess,
		const ::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess > &newServiceFileStatisticsProcess,
		const ::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess > &voiceFileForDecipheringStatisticsProcess,
		const ::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess > &decipheredVoiceFileAndKeyPairStatisticsProcess,
		const ::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess > &notDecipheredVoiceFileStatisticsProcess,
		const ::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess > &resultVoiceFileAndServiceFilePairStatisticsProcess,
		const ::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess > &resultVoiceFileStatisticsProcess,
		const ::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess > &resultServiceFileStatisticsProcess,
		const ::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess > &deletedVoiceFileStatisticsProcess,
		const ::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess > &deletedServiceFileStatisticsProcess,
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &threadContainer ) throw()
	:
		_newVoiceFileStatisticsProcess( newVoiceFileStatisticsProcess ),
		_newServiceFileStatisticsProcess( newServiceFileStatisticsProcess ),
		_voiceFileForDecipheringStatisticsProcess( voiceFileForDecipheringStatisticsProcess ),
		_decipheredVoiceFileAndKeyPairStatisticsProcess( decipheredVoiceFileAndKeyPairStatisticsProcess ),
		_notDecipheredVoiceFileStatisticsProcess( notDecipheredVoiceFileStatisticsProcess ),
		_resultVoiceFileAndServiceFilePairStatisticsProcess( resultVoiceFileAndServiceFilePairStatisticsProcess ),
		_resultVoiceFileStatisticsProcess( resultVoiceFileStatisticsProcess ),
		_resultServiceFileStatisticsProcess( resultServiceFileStatisticsProcess ),
		_deletedVoiceFileStatisticsProcess( deletedVoiceFileStatisticsProcess ),
		_deletedServiceFileStatisticsProcess( deletedServiceFileStatisticsProcess ),
		_threadContainer( threadContainer )
{
// 	_threadContainer->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _newVoiceFileStatisticsProcess.get() ) );
// 	_threadContainer->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _newServiceFileStatisticsProcess.get() ) );
// 	_threadContainer->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _voiceFileForDecipheringStatisticsProcess.get() ) );
// 	_threadContainer->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _decipheredVoiceFileAndKeyPairStatisticsProcess.get() ) );
// 	_threadContainer->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _notDecipheredVoiceFileStatisticsProcess.get() ) );
// 	_threadContainer->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _resultVoiceFileAndServiceFilePairStatisticsProcess.get() ) );
// 	_threadContainer->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _resultVoiceFileStatisticsProcess.get() ) );
// 	_threadContainer->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _resultServiceFileStatisticsProcess.get() ) );
// 	_threadContainer->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _deletedVoiceFileStatisticsProcess.get() ) );
// 	_threadContainer->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _deletedServiceFileStatisticsProcess.get() ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< StatisticsProcesses > realization_StatisticsProcesses::createClone() const throw() {
	return ::jmsf::Proxy< StatisticsProcesses >::createUnique( new realization_StatisticsProcesses( *this ) );
}

realization_StatisticsProcesses::realization_StatisticsProcesses( const realization_StatisticsProcesses & ) throw() // other
{}

const realization_StatisticsProcesses &realization_StatisticsProcesses::operator =( const realization_StatisticsProcesses &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
