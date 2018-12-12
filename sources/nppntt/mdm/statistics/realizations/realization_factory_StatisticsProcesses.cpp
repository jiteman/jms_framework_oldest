#include "realization_factory_StatisticsProcesses.h"
#include "realization_NewVoiceFileStatisticsProcess.h"
#include "realization_NewServiceFileStatisticsProcess.h"
#include "realization_VoiceFileForDecipheringStatisticsProcess.h"
#include "realization_DecipheredVoiceFileAndKeyPairStatisticsProcess.h"
#include "realization_NotDecipheredVoiceFileStatisticsProcess.h"
#include "realization_ResultVoiceFileAndServiceFilePairStatisticsProcess.h"
#include "realization_ResultVoiceFileStatisticsProcess.h"
#include "realization_ResultServiceFileStatisticsProcess.h"
#include "realization_DeletedVoiceFileStatisticsProcess.h"
#include "realization_DeletedServiceFileStatisticsProcess.h"
#include "../../externals/software/es_StatisticsUpdater.h"
#include "../../externals/data/ed_VoiceFile.h"
#include "../../externals/data/ed_ServiceFile.h"
#include "../../externals/data/ed_Key.h"
#include "../../StatisticsQueues.h"
#include "../../ProcessingQueues.h"
#include "../../ExternalSoftware.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/Thread.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/Pair.hpp"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace statistics {
namespace realizations {

::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess > realization_factory_StatisticsProcesses::createNewVoiceFileStatisticsProcess(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;
	::jmsf::Proxy< ExternalSoftware > internalExternalSoftware = externalSoftware;
	::jmsf::Proxy< ::jmsf::mtf::Thread > internalThread = thread;

	return ::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess >::createUnique(
		new statistics::realizations::realization_NewVoiceFileStatisticsProcess(
			internalStatisticsQueues->takeNewVoiceFileStatisticsQueue(),
			internalProcessingQueues->takeNewVoiceFileQueue(),
			internalExternalSoftware->takeStatisticsUpdater() ) );
}

::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess > realization_factory_StatisticsProcesses::createNewServiceFileStatisticsProcess(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;
	::jmsf::Proxy< ExternalSoftware > internalExternalSoftware = externalSoftware;

	return ::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess >::createUnique(
		new statistics::realizations::realization_NewServiceFileStatisticsProcess(
			internalStatisticsQueues->takeNewServiceFileStatisticsQueue().getWeak(),
			internalProcessingQueues->takeNewServiceFileQueue().getWeak(),
			internalExternalSoftware->takeStatisticsUpdater().getWeak() ) );
}

::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess > realization_factory_StatisticsProcesses::createVoiceFileForDecipheringStatisticsProcess(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;
	::jmsf::Proxy< ExternalSoftware > internalExternalSoftware = externalSoftware;

	return ::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess >::createUnique(
		new statistics::realizations::realization_VoiceFileForDecipheringStatisticsProcess(
			internalStatisticsQueues->takeVoiceFileForDecipheringStatisticsQueue().getWeak(),
			internalProcessingQueues->takeVoiceFileForDecipheringQueue().getWeak(),
			internalExternalSoftware->takeStatisticsUpdater().getWeak() ) );
}

::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess > realization_factory_StatisticsProcesses::createDecipheredVoiceFileAndKeyPairStatisticsProcess(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;
	::jmsf::Proxy< ExternalSoftware > internalExternalSoftware = externalSoftware;

	return ::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess >::createUnique(
		new statistics::realizations::realization_DecipheredVoiceFileAndKeyPairStatisticsProcess(
			internalStatisticsQueues->takeDecipheredVoiceFileAndKeyPairStatisticsQueue().getWeak(),
			internalProcessingQueues->takeNewVoiceFileAndKeyPairForImmediateMatchVerificationQueue().getWeak(),
			internalExternalSoftware->takeStatisticsUpdater().getWeak() ) );
}

::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess > realization_factory_StatisticsProcesses::createNotDecipheredVoiceFileStatisticsProcess(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;
	::jmsf::Proxy< ExternalSoftware > internalExternalSoftware = externalSoftware;

	return ::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess >::createUnique(
		new statistics::realizations::realization_NotDecipheredVoiceFileStatisticsProcess(
			internalStatisticsQueues->takeNotDecipheredVoiceFileStatisticsQueue().getWeak(),
			internalProcessingQueues->takeVoiceFileForRecurrentSearchForAMatchWithKeyQueue().getWeak(),
			internalExternalSoftware->takeStatisticsUpdater().getWeak() ) );
}

::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess > realization_factory_StatisticsProcesses::createResultVoiceFileAndServiceFilePairStatisticsProcess(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;
	::jmsf::Proxy< ExternalSoftware > internalExternalSoftware = externalSoftware;

	return ::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess >::createUnique(
		new statistics::realizations::realization_ResultVoiceFileAndServiceFilePairStatisticsProcess(
			internalStatisticsQueues->takeResultVoiceFileAndServiceFilePairStatisticsQueue().getWeak(),
			internalProcessingQueues->takeDecipheredVoiceFileAndServiceFilePairForAppendingToStorageQueue().getWeak(),
			internalExternalSoftware->takeStatisticsUpdater().getWeak() ) );
}

::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess > realization_factory_StatisticsProcesses::createResultVoiceFileStatisticsProcess(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;
	::jmsf::Proxy< ExternalSoftware > internalExternalSoftware = externalSoftware;

	return ::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess >::createUnique(
		new statistics::realizations::realization_ResultVoiceFileStatisticsProcess(
			internalStatisticsQueues->takeResultVoiceFileStatisticsQueue().getWeak(),
			internalProcessingQueues->takeDecipheredVoiceFileForAppendingToStorageQueue().getWeak(),
			internalExternalSoftware->takeStatisticsUpdater().getWeak() ) );
}

::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess > realization_factory_StatisticsProcesses::createResultServiceFileStatisticsProcess(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;
	::jmsf::Proxy< ExternalSoftware > internalExternalSoftware = externalSoftware;

	return ::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess >::createUnique(
		new statistics::realizations::realization_ResultServiceFileStatisticsProcess(
			internalStatisticsQueues->takeResultServiceFileStatisticsQueue().getWeak(),
			internalProcessingQueues->takeDecipheredServiceFileForAppendingToStorageQueue().getWeak(),
			internalExternalSoftware->takeStatisticsUpdater().getWeak() ) );
}

::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess > realization_factory_StatisticsProcesses::createDeletedVoiceFileStatisticsProcess(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;
	::jmsf::Proxy< ExternalSoftware > internalExternalSoftware = externalSoftware;

	return ::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess >::createUnique(
		new statistics::realizations::realization_DeletedVoiceFileStatisticsProcess(
			internalStatisticsQueues->takeDeletedVoiceFileStatisticsQueue().getWeak(),
			internalProcessingQueues->takeVoiceFileForDeletingQueue().getWeak(),
			internalExternalSoftware->takeStatisticsUpdater().getWeak() ) );
}

::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess > realization_factory_StatisticsProcesses::createDeletedServiceFileStatisticsProcess(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;
	::jmsf::Proxy< ExternalSoftware > internalExternalSoftware = externalSoftware;

	return ::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess >::createUnique(
		new statistics::realizations::realization_DeletedServiceFileStatisticsProcess(
			internalStatisticsQueues->takeDeletedServiceFileStatisticsQueue().getWeak(),
			internalProcessingQueues->takeServiceFileForDeletingQueue().getWeak(),
			internalExternalSoftware->takeStatisticsUpdater().getWeak() ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_factory_StatisticsProcesses::~realization_factory_StatisticsProcesses() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_StatisticsProcesses::realization_factory_StatisticsProcesses() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_StatisticsProcesses::realization_factory_StatisticsProcesses( const realization_factory_StatisticsProcesses & ) throw() // other
{}

const realization_factory_StatisticsProcesses &realization_factory_StatisticsProcesses::operator =( const realization_factory_StatisticsProcesses &other ) throw() {
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
