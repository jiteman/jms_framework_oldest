#include "realization_factory_MaskDmObjects.h"
#include "../file_filters/factory_FileFilters.h"
#include "../file_filters/observable_FileFilter.h"
#include "../file_filters/observer_FileFilter.h"
#include "../statistics/factory_StatisticsProcesses.h"
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
#include "../processing/factory_ProcessingProcesses.h"
#include "../processing/NewVoiceFileDispatcher.h"
#include "../processing/VoiceFileDecipher.h"
#include "../processing/ImmediateVoiceFileAndKeyPairVerifier.h"
#include "../processing/PreliminaryVoiceFileAndKeyMatchFinder.h"
#include "../processing/RecurrentVoiceFileAndKeyMatchFinder.h"
#include "../processing/VoiceFileDeleter.h"
#include "../processing/NewServiceFileDispatcher.h"
#include "../processing/LastChanceServiceFileMatchFinder.h"
#include "../processing/ServiceFileDeleter.h"
#include "../processing/ServiceFileAndKeyMatchFinder.h"
#include "../processing/ResultToStorageAppender.h"
#include "../processing/NewKeyDispatcher.h"
#include "../processing/KeyArray.h"
#include "../processing/ServiceFileArray.h"
#include "../externals/software/factory_ExternalSoftware.h"
#include "../externals/software/es_FileAppender.h"
#include "../externals/software/es_Decipher.h"
#include "../externals/software/es_StatisticsUpdater.h"
#include "../externals/data/ed_VoiceFile.h"
#include "../externals/data/ed_ServiceFile.h"
#include "../externals/data/ed_Key.h"

#include "realization_FileFilters.h"
#include "realization_StatisticsQueues.h"
#include "realization_ProcessingQueues.h"
#include "realization_StatisticsProcesses.h"
#include "realization_ProcessingProcesses.h"
#include "realization_ExternalSoftware.h"

#include "jmsf/osie/Event.h"
#include "jmsf/mtf/factory_GenericMultithreading.hpp"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/mtf/factory_Multithreading.h"
#include "jmsf/mtf/Thread.h"
#include "jmsf/Pair.hpp"
#include "jmsf/Casts.hpp"

namespace nppntt {
namespace mdm {
namespace realizations {

::jmsf::Proxy< FileFilters > realization_factory_MaskDmObjects::createFileFilters() const throw() {
	::jmsf::Proxy< file_filters::observable_FileFilter > observableFileFilter  =
		file_filters::factory_FileFilters::instance()->createObservableFileFilter();

	::jmsf::Proxy< file_filters::observer_FileFilter > newVoiceFileDispatcherObserverFileFilter =
		file_filters::factory_FileFilters::instance()->createObserverFileFilter( observableFileFilter.getWeak() );

	::jmsf::Proxy< file_filters::observer_FileFilter > newServiceFileDispatcherObserverFileFilter =
		file_filters::factory_FileFilters::instance()->createObserverFileFilter( observableFileFilter.getWeak() );

	::jmsf::Proxy< file_filters::observer_FileFilter > preliminaryVoiceFileAndKeyMatchFinderObserverFileFilter =
		file_filters::factory_FileFilters::instance()->createObserverFileFilter( observableFileFilter.getWeak() );

	::jmsf::Proxy< file_filters::observer_FileFilter > decipherObserverFileFilter =
		file_filters::factory_FileFilters::instance()->createObserverFileFilter( observableFileFilter.getWeak() );

	::jmsf::Proxy< file_filters::observer_FileFilter > recurrentVoiceFileAndKeyCheckerObserverFileFilter =
		file_filters::factory_FileFilters::instance()->createObserverFileFilter( observableFileFilter.getWeak() );

	::jmsf::Proxy< file_filters::observer_FileFilter > serviceFileAndKeyMatchFinderObserverFileFilter =
		file_filters::factory_FileFilters::instance()->createObserverFileFilter( observableFileFilter.getWeak() );

	::jmsf::Proxy< file_filters::observer_FileFilter > serviceFileArrayObserverFileFilter =
		file_filters::factory_FileFilters::instance()->createObserverFileFilter( observableFileFilter.getWeak() );

	observableFileFilter->attach( ::jmsf::adjacentCast< ::jmsf::Observer >( newVoiceFileDispatcherObserverFileFilter ) );
	observableFileFilter->attach( ::jmsf::adjacentCast< ::jmsf::Observer >( newServiceFileDispatcherObserverFileFilter ) );
	observableFileFilter->attach( ::jmsf::adjacentCast< ::jmsf::Observer >( preliminaryVoiceFileAndKeyMatchFinderObserverFileFilter ) );
	observableFileFilter->attach( ::jmsf::adjacentCast< ::jmsf::Observer >( decipherObserverFileFilter ) );
	observableFileFilter->attach( ::jmsf::adjacentCast< ::jmsf::Observer >( recurrentVoiceFileAndKeyCheckerObserverFileFilter ) );
	observableFileFilter->attach( ::jmsf::adjacentCast< ::jmsf::Observer >( serviceFileAndKeyMatchFinderObserverFileFilter ) );
	observableFileFilter->attach( ::jmsf::adjacentCast< ::jmsf::Observer >( serviceFileArrayObserverFileFilter ) );

	return ::jmsf::Proxy< FileFilters >::createUnique(
		new impl_FileFilters(
			observableFileFilter,
			newVoiceFileDispatcherObserverFileFilter.takeConstant(),
			newServiceFileDispatcherObserverFileFilter.takeConstant(),
			preliminaryVoiceFileAndKeyMatchFinderObserverFileFilter.takeConstant(),
			decipherObserverFileFilter.takeConstant(),
			recurrentVoiceFileAndKeyCheckerObserverFileFilter.takeConstant(),
			serviceFileAndKeyMatchFinderObserverFileFilter.takeConstant(),
			serviceFileArrayObserverFileFilter.takeConstant() ) );
}

::jmsf::Proxy< StatisticsQueues > realization_factory_MaskDmObjects::createStatisticsQueues() const throw() {
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > newVoiceFileStatisticsQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_VoiceFile > >::instance()->createSynchronizedQueue();

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > newServiceFileStatisticsQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_ServiceFile > >::instance()->createSynchronizedQueue();

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > voiceFileForDecipheringStatisticsQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_VoiceFile > >::instance()->createSynchronizedQueue();

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > decipheredVoiceFileAndKeyPairStatisticsQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > >::instance()->createSynchronizedQueue();

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > notDecipheredVoiceFileStatisticsQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_VoiceFile > >::instance()->createSynchronizedQueue();

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > resultVoiceFileAndServiceFilePairStatisticsQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > >::instance()->createSynchronizedQueue();

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > resultVoiceFileStatisticsQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_VoiceFile > >::instance()->createSynchronizedQueue();

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > resultServiceFileStatisticsQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_ServiceFile > >::instance()->createSynchronizedQueue();

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > deletedVoiceFileStatisticsQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_VoiceFile > >::instance()->createSynchronizedQueue();

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > deletedServiceFileStatisticsQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_ServiceFile > >::instance()->createSynchronizedQueue();

	return ::jmsf::Proxy< StatisticsQueues >::createUnique(
		new impl_StatisticsQueues(
			newVoiceFileStatisticsQueue,
			newServiceFileStatisticsQueue,
			voiceFileForDecipheringStatisticsQueue,
			decipheredVoiceFileAndKeyPairStatisticsQueue,
			notDecipheredVoiceFileStatisticsQueue,
			resultVoiceFileAndServiceFilePairStatisticsQueue,
			resultVoiceFileStatisticsQueue,
			resultServiceFileStatisticsQueue,
			deletedVoiceFileStatisticsQueue,
			deletedServiceFileStatisticsQueue ) );
}

::jmsf::Proxy< ProcessingQueues > realization_factory_MaskDmObjects::createProcessingQueues() const throw() {
	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > newVoiceFileQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_VoiceFile > >::instance()->createSynchronizedQueue();

	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > voiceFileForDecipheringQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_VoiceFile > >::instance()->createSynchronizedQueue();

	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > voiceFileForPreliminarySearchForAMatchWithKeyQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_VoiceFile > >::instance()->createSynchronizedQueue();

	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > voiceFileForRecurrentSearchForAMatchWithKeyQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_VoiceFile > >::instance()->createSynchronizedQueue();

	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > newVoiceFileAndKeyPairForImmediateMatchVerificationQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > >::instance()->createSynchronizedQueue();

	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > matchedVoiceFileAndKeyPairQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > >::instance()->createSynchronizedQueue();

	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > newServiceFileQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_ServiceFile > >::instance()->createSynchronizedQueue();

	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::ConstantProxy< externals::data::ed_Key > > > newKeyQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::ConstantProxy< externals::data::ed_Key > >::instance()->createSynchronizedQueue();

	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > decipheredVoiceFileAndServiceFilePairForAppendingToStorageQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > >::instance()->createSynchronizedQueue();

	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > decipheredVoiceFileForAppendingToStorageQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_VoiceFile > >::instance()->createSynchronizedQueue();

	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > decipheredServiceFileForAppendingToStorageQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_ServiceFile > >::instance()->createSynchronizedQueue();

	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > voiceFileForDeletingQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_VoiceFile > >::instance()->createSynchronizedQueue();

	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > serviceFileForLastChanceMatchFindQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_ServiceFile > >::instance()->createSynchronizedQueue();

	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > serviceFileForDeletingQueue =
		::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Proxy< externals::data::ed_ServiceFile > >::instance()->createSynchronizedQueue();

	return ::jmsf::Proxy< ProcessingQueues >::createUnique(
		new impl_ProcessingQueues(
			newVoiceFileQueue,
			voiceFileForDecipheringQueue,
			voiceFileForPreliminarySearchForAMatchWithKeyQueue,
			voiceFileForRecurrentSearchForAMatchWithKeyQueue,
			newVoiceFileAndKeyPairForImmediateMatchVerificationQueue,
			matchedVoiceFileAndKeyPairQueue,
			newServiceFileQueue,
			newKeyQueue,
			decipheredVoiceFileAndServiceFilePairForAppendingToStorageQueue,
			decipheredVoiceFileForAppendingToStorageQueue,
			decipheredServiceFileForAppendingToStorageQueue,
			voiceFileForDeletingQueue,
			serviceFileForLastChanceMatchFindQueue,
			serviceFileForDeletingQueue ) );
}

::jmsf::Proxy< ExternalSoftware > realization_factory_MaskDmObjects::createExternalSoftware() const throw( ::jmsf::Exception ) {
	::jmsf::Proxy< externals::software::es_Decipher > decipher =
		externals::software::factory_ExternalSoftware::instance()->createDecipher();

	const ::jmsf::Proxy< externals::software::es_StatisticsUpdater > statisticsUpdater =
		externals::software::factory_ExternalSoftware::instance()->createStatisticsUpdater(
			decipher.getWeakConstant() );

	decipher->setStatisticsUpdater( statisticsUpdater.getWeak() );

	return ::jmsf::Proxy< ExternalSoftware >::createUnique(
		new realization_ExternalSoftware(
			decipher,
			statisticsUpdater ) );
}

::jmsf::Proxy< StatisticsProcesses > realization_factory_MaskDmObjects::createStatisticProcesses(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware ) const throw()
{
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > newVoiceFileStatisticsProcessThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess > newVoiceFileStatisticsProcess =
		statistics::factory_StatisticsProcesses::instance()->createNewVoiceFileStatisticsProcess(
			statisticsQueues,
			processingQueues,
			externalSoftware,
			newVoiceFileStatisticsProcessThread.getWeak() );

	const ::jmsf::Proxy< ::jmsf::mtf::Thread > newServiceFileStatisticsProcessThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess > newServiceFileStatisticsProcess =
		statistics::factory_StatisticsProcesses::instance()->createNewServiceFileStatisticsProcess(
			statisticsQueues,
			processingQueues,
			externalSoftware,
			newServiceFileStatisticsProcessThread.getWeak() );

	const ::jmsf::Proxy< ::jmsf::mtf::Thread > voiceFileForDecipheringStatisticsProcessThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess > voiceFileForDecipheringStatisticsProcess =
		statistics::factory_StatisticsProcesses::instance()->createVoiceFileForDecipheringStatisticsProcess(
			statisticsQueues,
			processingQueues,
			externalSoftware,
			voiceFileForDecipheringStatisticsProcessThread.getWeak() );

	const ::jmsf::Proxy< ::jmsf::mtf::Thread > decipheredVoiceFileAndKeyPairStatisticsProcessThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess > decipheredVoiceFileAndKeyPairStatisticsProcess =
		statistics::factory_StatisticsProcesses::instance()->createDecipheredVoiceFileAndKeyPairStatisticsProcess(
			statisticsQueues,
			processingQueues,
			externalSoftware,
			decipheredVoiceFileAndKeyPairStatisticsProcessThread.getWeak() );

	const ::jmsf::Proxy< ::jmsf::mtf::Thread > notDecipheredVoiceFileStatisticsProcessThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess > notDecipheredVoiceFileStatisticsProcess =
		statistics::factory_StatisticsProcesses::instance()->createNotDecipheredVoiceFileStatisticsProcess(
			statisticsQueues,
			processingQueues,
			externalSoftware,
			notDecipheredVoiceFileStatisticsProcessThread.getWeak() );

	const ::jmsf::Proxy< ::jmsf::mtf::Thread > resultVoiceFileAndServiceFilePairStatisticsProcessThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess > resultVoiceFileAndServiceFilePairStatisticsProcess =
		statistics::factory_StatisticsProcesses::instance()->createResultVoiceFileAndServiceFilePairStatisticsProcess(
			statisticsQueues,
			processingQueues,
			externalSoftware,
			resultVoiceFileAndServiceFilePairStatisticsProcessThread.getWeak() );

	const ::jmsf::Proxy< ::jmsf::mtf::Thread > resultVoiceFileStatisticsProcessThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess > resultVoiceFileStatisticsProcess =
		statistics::factory_StatisticsProcesses::instance()->createResultVoiceFileStatisticsProcess(
			statisticsQueues,
			processingQueues,
			externalSoftware,
			resultVoiceFileStatisticsProcessThread.getWeak() );

	const ::jmsf::Proxy< ::jmsf::mtf::Thread > resultServiceFileStatisticsProcessThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess > resultServiceFileStatisticsProcess =
		statistics::factory_StatisticsProcesses::instance()->createResultServiceFileStatisticsProcess(
			statisticsQueues,
			processingQueues,
			externalSoftware,
			resultServiceFileStatisticsProcessThread.getWeak() );

	const ::jmsf::Proxy< ::jmsf::mtf::Thread > deletedVoiceFileStatisticsProcessThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess > deletedVoiceFileStatisticsProcess =
		statistics::factory_StatisticsProcesses::instance()->createDeletedVoiceFileStatisticsProcess(
			statisticsQueues,
			processingQueues,
			externalSoftware,
			deletedVoiceFileStatisticsProcessThread.getWeak() );

	const ::jmsf::Proxy< ::jmsf::mtf::Thread > deletedServiceFileStatisticsProcessThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess > deletedServiceFileStatisticsProcess =
		statistics::factory_StatisticsProcesses::instance()->createDeletedServiceFileStatisticsProcess(
			statisticsQueues,
			processingQueues,
			externalSoftware,
			deletedServiceFileStatisticsProcessThread.getWeak() );

//	const ::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray > processArray = ::jmsf::osie::runup::RunnableArray::create();

	const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > threadContainer =
		::jmsf::factory_Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > >::instance()->createArray();

	return ::jmsf::Proxy< StatisticsProcesses >::createUnique(
		new realization_StatisticsProcesses (
			newVoiceFileStatisticsProcess,
			newServiceFileStatisticsProcess,
			voiceFileForDecipheringStatisticsProcess,
			decipheredVoiceFileAndKeyPairStatisticsProcess,
			notDecipheredVoiceFileStatisticsProcess,
			resultVoiceFileAndServiceFilePairStatisticsProcess,
			resultVoiceFileStatisticsProcess,
			resultServiceFileStatisticsProcess,
			deletedVoiceFileStatisticsProcess,
			deletedServiceFileStatisticsProcess,
			threadContainer ) );
}

::jmsf::Proxy< ProcessingProcesses > realization_factory_MaskDmObjects::createProcessingProcesses(		
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< FileFilters > &fileFilters ) const throw()
{
	const ::jmsf::Proxy< processing::KeyArray > keyArray = processing::factory_ProcessingProcesses::instance()->createKeyArray();
	const ::jmsf::Proxy< processing::ServiceFileArray > serviceFileArray = processing::factory_ProcessingProcesses::instance()->createServiceFileArray( processingQueues, fileFilters );
	::jmsf::Proxy< ::jmsf::mtf::Thread > newVoiceFileDispatcherThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< processing::NewVoiceFileDispatcher > newVoiceFileDispatcher =
		processing::factory_ProcessingProcesses::instance()->createNewVoiceFileDispatcher(
			statisticsQueues,
			processingQueues,
			fileFilters,
			newVoiceFileDispatcherThread.getWeak() );

	newVoiceFileDispatcherThread->registerRunnable( ::jmsf::adjacentCast< ::jmsf::mtf::Runnable >( newVoiceFileDispatcher ) );
	::jmsf::Proxy< ::jmsf::mtf::Thread > voiceFileDecipherThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< processing::VoiceFileDecipher > voiceFileDecipher =
		processing::factory_ProcessingProcesses::instance()->createVoiceFileDecipher(
			statisticsQueues,
			processingQueues,
			keyArray.getWeak(),
			externalSoftware,
			fileFilters,
			voiceFileDecipherThread.getWeak() );

	voiceFileDecipherThread->registerRunnable( ::jmsf::adjacentCast< ::jmsf::mtf::Runnable >( voiceFileDecipher ) );
	::jmsf::Proxy< ::jmsf::mtf::Thread > immediateVoiceFileAndKeyPairVerifierThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< processing::ImmediateVoiceFileAndKeyPairVerifier > immediateVoiceFileAndKeyPairVerifier =
		processing::factory_ProcessingProcesses::instance()->createImmediateVoiceFileAndKeyPairVerifier(
			processingQueues,
			immediateVoiceFileAndKeyPairVerifierThread.getWeak() );

	immediateVoiceFileAndKeyPairVerifierThread->registerRunnable( ::jmsf::adjacentCast< ::jmsf::mtf::Runnable >( immediateVoiceFileAndKeyPairVerifier ) );
	::jmsf::Proxy< ::jmsf::mtf::Thread > preliminaryVoiceFileAndKeyMatchFinderThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< processing::PreliminaryVoiceFileAndKeyMatchFinder > preliminaryVoiceFileAndKeyMatchFinder =
		processing::factory_ProcessingProcesses::instance()->createPreliminaryVoiceFileAndKeyMatchFinder(
			statisticsQueues,
			processingQueues,
			keyArray.getWeak(),
			fileFilters,
			preliminaryVoiceFileAndKeyMatchFinderThread.getWeak() );

	preliminaryVoiceFileAndKeyMatchFinderThread->registerRunnable( ::jmsf::adjacentCast< ::jmsf::mtf::Runnable >( preliminaryVoiceFileAndKeyMatchFinder ) );
	::jmsf::Proxy< ::jmsf::mtf::Thread > recurrentVoiceFileAndKeyMatchFinderThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< processing::RecurrentVoiceFileAndKeyMatchFinder > recurrentVoiceFileAndKeyMatchFinder =
		processing::factory_ProcessingProcesses::instance()->createRecurrentVoiceFileAndKeyMatchFinder(
			statisticsQueues,
			processingQueues,
			keyArray.getWeak(),
			fileFilters,
			recurrentVoiceFileAndKeyMatchFinderThread.getWeak() );

	recurrentVoiceFileAndKeyMatchFinderThread->registerRunnable( ::jmsf::adjacentCast< ::jmsf::mtf::Runnable >( recurrentVoiceFileAndKeyMatchFinder ) );
	::jmsf::Proxy< ::jmsf::mtf::Thread > voiceFileDeleterThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< processing::VoiceFileDeleter > voiceFileDeleter =
		processing::factory_ProcessingProcesses::instance()->createVoiceFileDeleter(
			processingQueues,
			voiceFileDeleterThread.getWeak() );

	voiceFileDeleterThread->registerRunnable( ::jmsf::adjacentCast< ::jmsf::mtf::Runnable >( voiceFileDeleter ) );
	::jmsf::Proxy< ::jmsf::mtf::Thread > newServiceFileDispatcherThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< processing::NewServiceFileDispatcher > newServiceFileDispatcher =
		processing::factory_ProcessingProcesses::instance()->createNewServiceFileDispatcher(
			processingQueues,
			serviceFileArray.getWeak(),
			fileFilters,
			newServiceFileDispatcherThread.getWeak() );

	newServiceFileDispatcherThread->registerRunnable( ::jmsf::adjacentCast< ::jmsf::mtf::Runnable >( newServiceFileDispatcher ) );
	::jmsf::Proxy< ::jmsf::mtf::Thread > lastChanceServiceFileMatchFinderThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< processing::LastChanceServiceFileMatchFinder > lastChanceServiceFileMatchFinder =
		processing::factory_ProcessingProcesses::instance()->createLastChanceServiceFileMatchFinder(
			statisticsQueues,
			processingQueues,
			keyArray.getWeak(),
			lastChanceServiceFileMatchFinderThread.getWeak() );

	lastChanceServiceFileMatchFinderThread->registerRunnable( ::jmsf::adjacentCast< ::jmsf::mtf::Runnable >( lastChanceServiceFileMatchFinder ) );
	::jmsf::Proxy< ::jmsf::mtf::Thread > serviceFileDeleterThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< processing::ServiceFileDeleter > serviceFileDeleter =
		processing::factory_ProcessingProcesses::instance()->createServiceFileDeleter(
			processingQueues,
			serviceFileDeleterThread.getWeak() );

	serviceFileDeleterThread->registerRunnable( ::jmsf::adjacentCast< ::jmsf::mtf::Runnable >( serviceFileDeleter ) );
	::jmsf::Proxy< ::jmsf::mtf::Thread > serviceFileAndKeyMatchFinderThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< processing::ServiceFileAndKeyMatchFinder > serviceFileAndKeyMatchFinder =
		processing::factory_ProcessingProcesses::instance()->createServiceFileAndKeyMatchFinder(
			statisticsQueues,
			processingQueues,
			serviceFileArray.getWeak(),
			fileFilters,
			serviceFileAndKeyMatchFinderThread.getWeak() );
	
	serviceFileAndKeyMatchFinderThread->registerRunnable( ::jmsf::adjacentCast< ::jmsf::mtf::Runnable >( serviceFileAndKeyMatchFinder ) );
	::jmsf::Proxy< ::jmsf::mtf::Thread > resultToStorageAppenderThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< processing::ResultToStorageAppender > resultToStorageAppender =
		processing::factory_ProcessingProcesses::instance()->createResultToStorageAppender(
			statisticsQueues,
			processingQueues,
			resultToStorageAppenderThread.getWeak() );
	
	resultToStorageAppenderThread->registerRunnable( ::jmsf::adjacentCast< ::jmsf::mtf::Runnable >( resultToStorageAppender ) );
	::jmsf::Proxy< ::jmsf::mtf::Thread > newKeyDispatcherThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	const ::jmsf::Proxy< processing::NewKeyDispatcher > newKeyDispatcher =
		processing::factory_ProcessingProcesses::instance()->createNewKeyDispatcher(
			processingQueues,
			keyArray.getWeak(),
			newKeyDispatcherThread.getWeak() );

	newKeyDispatcherThread->registerRunnable( ::jmsf::adjacentCast< ::jmsf::mtf::Runnable >( newKeyDispatcher ) );
	const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > threadContainer = ::jmsf::factory_Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > >::instance()->createArray();

	return ::jmsf::Proxy< ProcessingProcesses >::createUnique(
		new realization_ProcessingProcesses(
			newVoiceFileDispatcher,
			voiceFileDecipher,
			immediateVoiceFileAndKeyPairVerifier,
			preliminaryVoiceFileAndKeyMatchFinder,
			recurrentVoiceFileAndKeyMatchFinder,
			voiceFileDeleter,
			newServiceFileDispatcher,
			lastChanceServiceFileMatchFinder,
			serviceFileDeleter,
			serviceFileAndKeyMatchFinder,
			resultToStorageAppender,
			newKeyDispatcher,
			keyArray,
			serviceFileArray,
			threadContainer ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_factory_MaskDmObjects::~realization_factory_MaskDmObjects() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_MaskDmObjects::realization_factory_MaskDmObjects() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_MaskDmObjects::realization_factory_MaskDmObjects( const realization_factory_MaskDmObjects & ) throw() // other
{}

const realization_factory_MaskDmObjects &realization_factory_MaskDmObjects::operator =( const realization_factory_MaskDmObjects &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
