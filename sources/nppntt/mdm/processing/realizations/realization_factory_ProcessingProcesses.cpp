#include "realization_factory_ProcessingProcesses.h"

#include "realization_NewFileAppenders.h"
#include "realization_NewVoiceFileDispatcher.h"
#include "realization_VoiceFileDecipher.h"
#include "realization_PreliminaryVoiceFileAndKeyMatchFinder.h"
#include "realization_RecurrentVoiceFileAndKeyMatchFinder.h"
#include "realization_ImmediateVoiceFileAndKeyPairVerifier.h"
#include "realization_VoiceFileDeleter.h"

#include "realization_NewServiceFileDispatcher.h"
#include "realization_LastChanceServiceFileMatchFinder.h"
#include "realization_ServiceFileDeleter.h"

#include "realization_ServiceFileAndKeyMatchFinder.h"
#include "realization_ResultToStorageAppender.h"

#include "realization_NewKeyDispatcher.h"
#include "realization_KeyArray.h"
#include "realization_ServiceFileArray.h"

#include "../../externals/software/factory_ExternalSoftware.h"
#include "../../FileFilters.h"
#include "../../StatisticsQueues.h"
#include "../../ProcessingQueues.h"
#include "../../ExternalSoftware.h"
#include "../../externals/software/es_FileAppender.h"
#include "../../externals/software/es_FileDeleter.h"
#include "../../externals/software/es_Decipher.h"
#include "../../externals/software/es_VoiceFileAndKeyPairMatchChecker.h"
#include "../../externals/software/es_ServiceFileAndKeyPairMatchChecker.h"
#include "../../externals/software/es_StorageAppender.h"

#include "../../file_filters/observer_FileFilter.h"

#include "../../externals/data/ed_VoiceFile.h"
#include "../../externals/data/ed_ServiceFile.h"
#include "../../externals/data/ed_Key.h"
#include "../../externals/data/ed_FileFilter.h"
#include "../../externals/others/abstractFileDescriptor.h"

//#include "jmsf/osie/runup/Mutex.h"
#include "jmsf/osie/factory_OperatingSystem.h"
#include "jmsf/osie/MultithreadingControl.h"
#include "jmsf/osie/EventArray.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/mtf/factory_Multithreading.h"
#include "jmsf/factory_Container.hpp"
#include "jmsf/TextString.h"
#include "jmsf/Container.hpp"
#include "jmsf/Pair.hpp"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {


::jmsf::Proxy< NewFileAppenders > realization_factory_ProcessingProcesses::createNewFileAppenders(
	const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< ::jmsf::TextString > > > &pathToFolderWithDataFilesArray,
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &newFileAppendersThread ) const throw()
{
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::software::es_FileAppender > > > fileAppenderContainer =
		::jmsf::factory_Container< ::jmsf::Proxy< externals::software::es_FileAppender > >::instance()->createArray();

	{
		::jmsf::Proxy< ::jmsf::mtf::Thread > internalNewFileAppendersThread = newFileAppendersThread;

		for (
			::jmsf::Proxy< ::jmsf::ConstantIterator< ::jmsf::ConstantProxy< ::jmsf::TextString > > > pathToFolderIterator =
				pathToFolderWithDataFilesArray->createConstantForwardIterator();
			pathToFolderIterator->isNotDone();
			pathToFolderIterator->advance() )
		{
			::jmsf::Proxy< ::jmsf::mtf::Thread > newFileAppenderThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();
		
			::jmsf::Proxy< externals::software::es_FileAppender > fileAppender =
				externals::software::factory_ExternalSoftware::instance()->createFileAppender(
					pathToFolderIterator->getContainie().getWeak(),
					newFileAppenderThread.getWeak() );

			internalNewFileAppendersThread->appendNestedThread( newFileAppenderThread );
			internalNewFileAppendersThread->appendWaitableEvent( fileAppender->takeVoiceFileDataQueue()->takeIsObjectAvailableEvent().getWeak() );
			internalNewFileAppendersThread->appendWaitableEvent( fileAppender->takeServiceFileDataQueue()->takeIsObjectAvailableEvent().getWeak() );
			fileAppenderContainer->appendBack( fileAppender );
		}
	}

	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;

	return ::jmsf::Proxy< NewFileAppenders >::createUnique(
		new realization_NewFileAppenders(			
			internalStatisticsQueues->takeNewVoiceFileStatisticsQueue().getWeak(),
			internalStatisticsQueues->takeNewServiceFileStatisticsQueue().getWeak(),
			fileAppenderContainer ) );
}

::jmsf::Proxy< NewVoiceFileDispatcher > realization_factory_ProcessingProcesses::createNewVoiceFileDispatcher(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< FileFilters > &fileFilters,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;



	return ::jmsf::Proxy< NewVoiceFileDispatcher >::createUnique(
		new realization_NewVoiceFileDispatcher(
			internalProcessingQueues->takeNewVoiceFileQueue().getWeak(),
			internalStatisticsQueues->takeVoiceFileForDecipheringStatisticsQueue(),
			internalProcessingQueues->takeVoiceFileForDecipheringQueue(),
			internalProcessingQueues->takeVoiceFileForPreliminarySearchForAMatchWithKeyQueue(),
			internalStatisticsQueues->takeDeletedVoiceFileStatisticsQueue(),
			fileFilters->getNewVoiceFileDispatcherObserverFileFilter()->getFileFilter() ) );
}

::jmsf::Proxy< VoiceFileDecipher > realization_factory_ProcessingProcesses::createVoiceFileDecipher(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< KeyArray > &keyArray,
	const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
	const ::jmsf::Proxy< FileFilters > &fileFilters,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;
	::jmsf::Proxy< ExternalSoftware > internalExternalsSoftware = externalSoftware;
	::jmsf::Proxy< FileFilters > internalFileFilters = fileFilters;

	return ::jmsf::Proxy< VoiceFileDecipher >::createUnique(
		new realization_VoiceFileDecipher(
			internalProcessingQueues->takeVoiceFileForDecipheringQueue().getWeak(),
			internalStatisticsQueues->takeDecipheredVoiceFileAndKeyPairStatisticsQueue().getWeak(),
			internalProcessingQueues->takeNewKeyQueue().getWeak(),
			internalStatisticsQueues->takeNotDecipheredVoiceFileStatisticsQueue().getWeak(),
			internalStatisticsQueues->takeDeletedVoiceFileStatisticsQueue().getWeak(),
			keyArray,
			internalExternalsSoftware->takeDecipher().getWeak(),
			internalFileFilters->getDecipherObserverFileFilter()->getFileFilter() ) );
}

::jmsf::Proxy< ImmediateVoiceFileAndKeyPairVerifier > realization_factory_ProcessingProcesses::createImmediateVoiceFileAndKeyPairVerifier(
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;

	return ::jmsf::Proxy< ImmediateVoiceFileAndKeyPairVerifier >::createUnique(
		new realization_ImmediateVoiceFileAndKeyPairVerifier(
			internalProcessingQueues->takeNewVoiceFileAndKeyPairForImmediateMatchVerificationQueue().getWeak(),
			internalProcessingQueues->takeMatchedVoiceFileAndKeyPairQueue().getWeak(),
			internalProcessingQueues->takeVoiceFileForRecurrentSearchForAMatchWithKeyQueue().getWeak(),
			externals::software::factory_ExternalSoftware::instance()->createVoiceFileAndKeyPairMatchChecker(
				::jmsf::osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createMutex() ) ) );			
}

::jmsf::Proxy< PreliminaryVoiceFileAndKeyMatchFinder > realization_factory_ProcessingProcesses::createPreliminaryVoiceFileAndKeyMatchFinder(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< KeyArray > &keyArray,
	const ::jmsf::Proxy< FileFilters > &fileFilters,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &preliminaryVoiceFileAndKeyMatchFinderThread ) const throw()
{
	::jmsf::Proxy< ::jmsf::osie::Mutex > voiceFileMutex = ::jmsf::Proxy< ::jmsf::osie::Mutex >::createShared( ::jmsf::osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createMutex().release() );

	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > > > voiceFileAndKeyPairMatchCheckerArray =
		::jmsf::factory_Container< ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > >::instance()->createArray();

	for (
		::jmsf::natural_size voiceFileAndKeyPairMatchCheckerCounter = 0;
		voiceFileAndKeyPairMatchCheckerCounter < VOICE_FILE_AND_KEY_PAIR_CHECKER_FOR_PRELIMINARY_MATCH_FINDER_QUANTITY; 
		voiceFileAndKeyPairMatchCheckerCounter += 1 )
	{
		::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > voiceFileAndKeyPairMatchChecker =
			externals::software::factory_ExternalSoftware::instance()->createVoiceFileAndKeyPairMatchChecker(
				voiceFileMutex );

		voiceFileAndKeyPairMatchCheckerArray->appendBack( voiceFileAndKeyPairMatchChecker );
	}

	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;
	::jmsf::Proxy< FileFilters > internalFileFilters = fileFilters;

	return ::jmsf::Proxy< PreliminaryVoiceFileAndKeyMatchFinder >::createUnique(
		new realization_PreliminaryVoiceFileAndKeyMatchFinder(
			internalProcessingQueues->takeVoiceFileForPreliminarySearchForAMatchWithKeyQueue().getWeak(),
			internalProcessingQueues->takeMatchedVoiceFileAndKeyPairQueue().getWeak(),
			internalStatisticsQueues->takeVoiceFileForDecipheringStatisticsQueue().getWeak(),
			internalStatisticsQueues->takeDeletedVoiceFileStatisticsQueue().getWeak(),
			keyArray,
			internalFileFilters->getPreliminaryVoiceFileAndKeyMatchFinderObserverFileFilter()->getFileFilter(),
			voiceFileAndKeyPairMatchCheckerArray ) );
}

::jmsf::Proxy< RecurrentVoiceFileAndKeyMatchFinder > realization_factory_ProcessingProcesses::createRecurrentVoiceFileAndKeyMatchFinder(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< KeyArray > &keyArray,
	const ::jmsf::Proxy< FileFilters > &fileFilters,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &recurrentVoiceFileAndKeyMatchFinderThread ) const throw()
{
	::jmsf::Proxy< ::jmsf::osie::Mutex > voiceFileMutex = ::jmsf::Proxy< ::jmsf::osie::Mutex >::createShared( ::jmsf::osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createMutex().release() );

	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > > > voiceFileAndKeyPairMatchCheckerContainer =
		::jmsf::factory_Container< ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > >::instance()->createArray();

	for (
		::jmsf::natural_size voiceFileAndKeyPairMatchCheckerCounter = 0;
		voiceFileAndKeyPairMatchCheckerCounter < VOICE_FILE_AND_KEY_PAIR_CHECKER_FOR_RECURRENT_MATCH_FINDER_QUANTITY; 
		voiceFileAndKeyPairMatchCheckerCounter += 1 )
	{
		::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > voiceFileAndKeyPairMatchChecker =
			externals::software::factory_ExternalSoftware::instance()->createVoiceFileAndKeyPairMatchChecker(
				voiceFileMutex );

		voiceFileAndKeyPairMatchCheckerContainer->appendBack( voiceFileAndKeyPairMatchChecker );
	}

	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;
	::jmsf::Proxy< FileFilters > internalFileFilters = fileFilters;

	return ::jmsf::Proxy< RecurrentVoiceFileAndKeyMatchFinder >::createUnique(
		new realization_RecurrentVoiceFileAndKeyMatchFinder(
			internalProcessingQueues->takeVoiceFileForRecurrentSearchForAMatchWithKeyQueue().getWeak(),
			internalProcessingQueues->takeMatchedVoiceFileAndKeyPairQueue().getWeak(),
			internalStatisticsQueues->takeDeletedVoiceFileStatisticsQueue().getWeak(),
			keyArray,
			internalFileFilters->getRecurrentVoiceFileAndKeyCheckerObserverFileFilter()->getFileFilter(),
			voiceFileAndKeyPairMatchCheckerContainer,
			::jmsf::factory_Container< ::jmsf::Proxy< externals::data::ed_VoiceFile > >::instance()->createList(),
			::jmsf::osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createEventArray(),
			::jmsf::osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createEventArray() ) );
}

::jmsf::Proxy< VoiceFileDeleter > realization_factory_ProcessingProcesses::createVoiceFileDeleter(
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;

	return ::jmsf::Proxy< VoiceFileDeleter >::createUnique(
		new realization_VoiceFileDeleter(
			internalProcessingQueues->takeVoiceFileForDeletingQueue().getWeak(),
			externals::software::factory_ExternalSoftware::instance()->createFileDeleter() ) );
}

::jmsf::Proxy< NewServiceFileDispatcher > realization_factory_ProcessingProcesses::createNewServiceFileDispatcher(
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< ServiceFileArray > &serviceFileArray,
	const ::jmsf::Proxy< FileFilters > &fileFilters,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;
	::jmsf::Proxy< FileFilters > internalFileFilters = fileFilters;
	
	return ::jmsf::Proxy< NewServiceFileDispatcher >::createUnique(
		new realization_NewServiceFileDispatcher(
			internalProcessingQueues->takeNewServiceFileQueue().getWeak(),
			internalProcessingQueues->takeServiceFileForLastChanceMatchFindQueue().getWeak(),
			serviceFileArray,
			internalFileFilters->getNewServiceFileDispatcherObserverFileFilter()->getFileFilter() ) );
}

::jmsf::Proxy< ServiceFileDeleter > realization_factory_ProcessingProcesses::createServiceFileDeleter(
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;

	return ::jmsf::Proxy< ServiceFileDeleter >::createUnique(
		new realization_ServiceFileDeleter(
			internalProcessingQueues->takeServiceFileForDeletingQueue().getWeak(),
			externals::software::factory_ExternalSoftware::instance()->createFileDeleter() ) );
}

::jmsf::Proxy< ServiceFileAndKeyMatchFinder > realization_factory_ProcessingProcesses::createServiceFileAndKeyMatchFinder(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< ServiceFileArray > &serviceFileArray,
	const ::jmsf::Proxy< FileFilters > &fileFilters,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;
	::jmsf::Proxy< FileFilters > internalFileFilters = fileFilters;

	return ::jmsf::Proxy< ServiceFileAndKeyMatchFinder >::createUnique(
		new realization_ServiceFileAndKeyMatchFinder(
			internalProcessingQueues->takeMatchedVoiceFileAndKeyPairQueue().getWeak(),
			internalStatisticsQueues->takeResultVoiceFileAndServiceFilePairStatisticsQueue().getWeak(),
			internalStatisticsQueues->takeResultVoiceFileStatisticsQueue().getWeak(),
			internalStatisticsQueues->takeResultServiceFileStatisticsQueue().getWeak(),
			internalProcessingQueues->takeServiceFileForLastChanceMatchFindQueue().getWeak(),
			internalFileFilters->getServiceFileAndKeyMatchFinderObserverFileFilter()->getFileFilter(),
			serviceFileArray,
			externals::software::factory_ExternalSoftware::instance()->createServiceFileAndKeyPairMatchChecker(
				::jmsf::osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createMutex() ) ) );
}

::jmsf::Proxy< LastChanceServiceFileMatchFinder > realization_factory_ProcessingProcesses::createLastChanceServiceFileMatchFinder(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< KeyArray > &keyArray,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &lastChanceServiceFileMatchFinderThread ) const throw()
{
	::jmsf::Proxy< ::jmsf::osie::Mutex > serviceFileMutex =
		::jmsf::Proxy< ::jmsf::osie::Mutex >::createShared( ::jmsf::osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createMutex().release() );

	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::software::es_ServiceFileAndKeyPairMatchChecker > > > serviceFileAndKeyPairMatchCheckerArray =
		::jmsf::factory_Container< ::jmsf::Proxy< externals::software::es_ServiceFileAndKeyPairMatchChecker > >::instance()->createArray();

	for (
		::jmsf::natural_size serviceFileAndKeyPairMatchCheckerCounter = 0;
		serviceFileAndKeyPairMatchCheckerCounter < SERVICE_FILE_AND_KEY_PAIR_CHECKER_FOR_LAST_CHANCE_MATCH_FINDER_QUANTITY; 
		serviceFileAndKeyPairMatchCheckerCounter += 1 )
	{
		::jmsf::Proxy< externals::software::es_ServiceFileAndKeyPairMatchChecker > serviceFileAndKeyPairMatchChecker =
			externals::software::factory_ExternalSoftware::instance()->createServiceFileAndKeyPairMatchChecker(
				serviceFileMutex );

		serviceFileAndKeyPairMatchCheckerArray->appendBack( serviceFileAndKeyPairMatchChecker );
	}

	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;

	return ::jmsf::Proxy< LastChanceServiceFileMatchFinder >::createUnique(
		new realization_LastChanceServiceFileMatchFinder(
			internalProcessingQueues->takeServiceFileForLastChanceMatchFindQueue().getWeak(),
			internalStatisticsQueues->takeResultServiceFileStatisticsQueue().getWeak(),
			internalStatisticsQueues->takeDeletedServiceFileStatisticsQueue().getWeak(),
			keyArray,
			serviceFileAndKeyPairMatchCheckerArray ) );
}

::jmsf::Proxy< ResultToStorageAppender > realization_factory_ProcessingProcesses::createResultToStorageAppender(
	const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< StatisticsQueues > internalStatisticsQueues = statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;

	return ::jmsf::Proxy< ResultToStorageAppender >::createUnique(
		new realization_ResultToStorageAppender(
			internalProcessingQueues->takeDecipheredVoiceFileAndServiceFilePairForAppendingToStorageQueue().getWeak(),
			internalProcessingQueues->takeDecipheredVoiceFileForAppendingToStorageQueue().getWeak(),
			internalProcessingQueues->takeDecipheredServiceFileForAppendingToStorageQueue().getWeak(),
			internalStatisticsQueues->takeDeletedVoiceFileStatisticsQueue().getWeak(),
			internalStatisticsQueues->takeDeletedServiceFileStatisticsQueue().getWeak(),
			externals::software::factory_ExternalSoftware::instance()->createStorageAppender() ) );
}

::jmsf::Proxy< NewKeyDispatcher > realization_factory_ProcessingProcesses::createNewKeyDispatcher(
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< KeyArray > &keyArray,
	const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw()
{
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;

	return ::jmsf::Proxy< NewKeyDispatcher >::createUnique( new realization_NewKeyDispatcher(
		internalProcessingQueues->takeNewKeyQueue().getWeak(),
		keyArray ) );
}

::jmsf::Proxy< KeyArray > realization_factory_ProcessingProcesses::createKeyArray() const throw() {
	return ::jmsf::Proxy< KeyArray >::createUnique(
		new realization_KeyArray(
			::jmsf::factory_Container< ::jmsf::ConstantProxy< externals::data::ed_Key > >::instance()->createArray(),
			::jmsf::osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createEvent(),
			::jmsf::osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createMutex() ) );
}

::jmsf::Proxy< ServiceFileArray > realization_factory_ProcessingProcesses::createServiceFileArray(
	const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
	const ::jmsf::Proxy< FileFilters > &fileFilters ) const throw()
{
	::jmsf::Proxy< ProcessingQueues > internalProcessingQueues = processingQueues;
	::jmsf::Proxy< FileFilters > internalFileFilters = fileFilters;

	return ::jmsf::Proxy< ServiceFileArray >::createUnique(
		new realization_ServiceFileArray(
			internalProcessingQueues->takeServiceFileForLastChanceMatchFindQueue().getWeak(),
			internalFileFilters->getServiceFileArrayFileFilter()->getFileFilter(),
			::jmsf::factory_Container< ::jmsf::Proxy< externals::data::ed_ServiceFile > >::instance()->createList(),
			::jmsf::osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createMutex() ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_factory_ProcessingProcesses::~realization_factory_ProcessingProcesses() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_ProcessingProcesses::realization_factory_ProcessingProcesses() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_ProcessingProcesses::realization_factory_ProcessingProcesses( const realization_factory_ProcessingProcesses & ) throw() // other
{}

const realization_factory_ProcessingProcesses &realization_factory_ProcessingProcesses::operator =( const realization_factory_ProcessingProcesses &other ) throw() {
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
