#include "realization_MaskDm.h"
//#include "../externals/others/abstractFilter.h"
//#include "../externals/others/abstractDecipher.h"
//#include "../externals/others/abstractStatistics.h"
#include "../externals/data/statistics/ed_Summary.h"
#include "../externals/data/factory_ExternalData.h"
#include "../externals/data/ed_FileFilter.h"
#include "../externals/software/es_Decipher.h"
#include "../externals/software/es_StatisticsUpdater.h"
#include "../file_filters/observable_FileFilter.h"
#include "../factory_MaskDmObjects.h"
#include "../FileFilters.h"
#include "../processing/factory_ProcessingProcesses.h"
#include "../processing/NewFileAppenders.h"
#include "../processing/ServiceFileArray.h"
#include "../StatisticsQueues.h"
#include "../ProcessingQueues.h"
#include "../StatisticsProcesses.h"
#include "../ProcessingProcesses.h"
#include "../ExternalSoftware.h"
#include "jmsf/mtf/factory_Multithreading.h"
#include "jmsf/mtf/Thread.h"
#include "jmsf/mtf/Runnable.h"
#include "jmsf/assisting/DoForEvery.hpp"
#include "jmsf/Container.hpp"
#include "jmsf/Casts.hpp"
#include "jmsf/Pointers.hpp"

namespace nppntt {
namespace mdm {
namespace realizations {

::jmsf::Boolean realization_MaskDm::wasInitializedCorrectly() const throw() {
	return _wasInitializedCorrectly;
}

void realization_MaskDm::continueDecipchering() throw() {
	_isDecipheringStopped = ::jmsf::False;

	if ( _wasNewFileAppendersLaunched.not() ) {
		if ( _newFileAppenders.isNotEmpty() ) {
//			_newFileAppenders->launchRunning();
			_newFileAppendersThread->launch();
		}
	}

	if ( _wasLaunched.not() ) {
// 		_processingProcesses->getOneselfProcessArray()->launchRunnables();
// 		_statisticsProcesses->getOneselfProcessArray()->launchRunnables();
		::jmsf::assisting::doForEvery( _processingProcesses->takeThreadContainer(), _threadLaunchFunctor );
		::jmsf::assisting::doForEvery( _statisticsProcesses->takeThreadContainer(), _threadLaunchFunctor );

		_wasLaunched = ::jmsf::True;
	}

	if ( _newFileAppenders.isNotEmpty() ) {
//		_newFileAppenders->continueRunning();
		_newFileAppendersThread->resume();
	}

// 	_processingProcesses->getOneselfProcessArray()->continueRunnablesRunning();
// 	_statisticsProcesses->getOneselfProcessArray()->continueRunnablesRunning();
	::jmsf::assisting::doForEvery( _processingProcesses->takeThreadContainer(), _threadResumeFunctor );
	::jmsf::assisting::doForEvery( _statisticsProcesses->takeThreadContainer(), _threadResumeFunctor );
}

void realization_MaskDm::stopDecipchering() throw() {
	if ( _newFileAppenders.isNotEmpty() ) {
//		_newFileAppenders->stopRunning();
		_newFileAppendersThread->suspend();
	}

// 	_processingProcesses->getOneselfProcessArray()->stopRunnables();
// 	_statisticsProcesses->getOneselfProcessArray()->stopRunnables();
	::jmsf::assisting::doForEvery( _processingProcesses->takeThreadContainer(), _threadSuspendFunctor );
	::jmsf::assisting::doForEvery( _statisticsProcesses->takeThreadContainer(), _threadSuspendFunctor );

	if ( _newFileAppenders.isNotEmpty() ) {
//		_newFileAppenders.getWeakConstant()->waitTillRunningIsStopped();
		_newFileAppendersThread->waitTillIsSuspended();
	}

// 	_processingProcesses->getOneselfProcessArray()->waitTillRunningOfRunnablesIsStopped();
// 	_statisticsProcesses->getOneselfProcessArray()->waitTillRunningOfRunnablesIsStopped();
	::jmsf::assisting::doForEvery( _processingProcesses->takeThreadContainer(), _threadWaitTillIsSuspendedFunctor );
	::jmsf::assisting::doForEvery( _statisticsProcesses->takeThreadContainer(), _threadWaitTillIsSuspendedFunctor );

	_isDecipheringStopped = ::jmsf::True;
}

void realization_MaskDm::changeFileAppenderFolders(
	const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< ::jmsf::TextString > > > &pathToFolderWithFilesContainer ) throw()
{
	::jmsf::Should::alwaysBe( _isDecipheringStopped );

	if ( _newFileAppenders.isNotEmpty() ) {
// 		_newFileAppenders->stopRunning();
// 		_newFileAppenders.getWeakConstant()->waitTillRunningIsStopped();
// 		_newFileAppenders->finalizeRunning();
// 		_newFileAppenders->waitTillFinalizingIsCompleted();
		_newFileAppendersThread->suspend();
		_newFileAppendersThread->waitTillIsSuspended();
		_newFileAppendersThread->terminate();
		_newFileAppendersThread->waitTillTerminatingIsCompleted();
	}

	_newFileAppendersThread = ::jmsf::mtf::factory_Multithreading::instance()->createContinuousThread();

	_newFileAppenders =
		processing::factory_ProcessingProcesses::instance()->createNewFileAppenders(
			pathToFolderWithFilesContainer,
			_statisticsQueues.getWeak(),
			_newFileAppendersThread.getWeak() );
	
	_newFileAppendersThread->registerRunnable( ::jmsf::adjacentCast< ::jmsf::mtf::Runnable >( _newFileAppenders.getWeak() ) );

	// clear queues

	_wasNewFileAppendersLaunched = ::jmsf::True;
	_newFileAppendersThread->launch();
}

void realization_MaskDm::updateFileFilter( const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter ) throw() {
	_fileFilters->takeObservableFileFilter()->takeFileFilter()->takeMutex()->lock();
	_fileFilters->takeObservableFileFilter()->takeFileFilter()->renew( fileFilter );
	_fileFilters->takeObservableFileFilter()->takeFileFilter()->takeMutex()->unlock();
	_fileFilters->takeObservableFileFilter()->notify();
}

void realization_MaskDm::setDecipheringTimeLimit( const ::jmsf::ConstantPointer< _decipherTimeLimit > &timeLimitData ) throw() {
	_externalSoftware->takeDecipher()->setTimeLimit( timeLimitData );
}

const ::jmsf::ConstantProxy< externals::data::statistics::ed_Summary > &realization_MaskDm::getStatistics() throw() {
	//return;
// 	::copyGlobalStatistics(
// 		_externalSoftware->getOneselfStatisticsUpdater()->updateAndGetOneselfSummary().getWeakConstant()->getData().get(),
// 		_statisticsSummary->getOneselfData().get() );

	return _externalSoftware->takeStatisticsUpdater()->updateAndGetSummary();
}

void realization_MaskDm::clearExpiredServiceFiles() throw() {
	_processingProcesses->takeServiceFileArray()->takeMutex()->lock();
	_processingProcesses->takeServiceFileArray()->clearExpired();
	_processingProcesses->takeServiceFileArray()->takeMutex()->unlock();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_MaskDm::~realization_MaskDm() throw() {
	if ( _newFileAppenders.isNotEmpty() ) {
//		_newFileAppenders->finalizeRunning();
		_newFileAppendersThread->terminate();
	}

// 	_processingProcesses->getOneselfProcessArray()->finalizeRunnables();
// 	_statisticsProcesses->getOneselfProcessArray()->finalizeRunnables();
	::jmsf::assisting::doForEvery( _processingProcesses->takeThreadContainer(), _threadWaitTillIsSuspendedFunctor );
	::jmsf::assisting::doForEvery( _statisticsProcesses->takeThreadContainer(), _threadWaitTillIsSuspendedFunctor );

	if ( _newFileAppenders.isNotEmpty() ) {
//		_newFileAppenders->waitTillFinalizingIsCompleted();
		_newFileAppendersThread->waitTillTerminatingIsCompleted();
	}

// 	_processingProcesses->getOneselfProcessArray()->waitTillFinalizingOfRunnablesIsCompleted();
// 	_statisticsProcesses->getOneselfProcessArray()->waitTillFinalizingOfRunnablesIsCompleted();
	::jmsf::assisting::doForEvery( _processingProcesses->takeThreadContainer(), _threadWaitTillIsSuspendedFunctor );
	::jmsf::assisting::doForEvery( _statisticsProcesses->takeThreadContainer(), _threadWaitTillIsSuspendedFunctor );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_MaskDm::realization_MaskDm(
		const ::jmsf::Proxy< FileFilters > &fileFilters,
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< StatisticsProcesses > &statisticsProcesses,
		const ::jmsf::Proxy< ProcessingProcesses > &processingProcesses,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::assisting::Functor< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &threadLaunchFunctor,
		const ::jmsf::Proxy< ::jmsf::assisting::Functor< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &threadResumeFunctor,
		const ::jmsf::Proxy< ::jmsf::assisting::Functor< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &threadSuspendFunctor,
		const ::jmsf::ConstantProxy< ::jmsf::assisting::ConstantFunctor< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &threadWaitTillIsSuspendedFunctor,
		const ::jmsf::ConstantProxy< ::jmsf::assisting::ConstantFunctor< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &threadWaitTillTerminatingIsCompletedFunctor ) throw()
	:
		_isDecipheringStopped( ::jmsf::True ),
		_fileFilters( fileFilters ),
		_statisticsQueues( statisticsQueues ),
		_processingQueues( processingQueues ),
		_statisticsProcesses( statisticsProcesses ),
		_processingProcesses( processingProcesses ),
		_externalSoftware( externalSoftware ),
		_threadLaunchFunctor( threadLaunchFunctor ),
		_threadResumeFunctor( threadResumeFunctor ),
		_threadSuspendFunctor( threadSuspendFunctor ),
		_threadWaitTillIsSuspendedFunctor( threadWaitTillIsSuspendedFunctor ),
		_threadWaitTillTerminatingIsCompletedFunctor( threadWaitTillTerminatingIsCompletedFunctor )
{
	_wasInitializedCorrectly = ::jmsf::True;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< MaskDm > realization_MaskDm::createClone() const throw() {
	return ::jmsf::Proxy< MaskDm >::createUnique( new realization_MaskDm( *this ) );
}

realization_MaskDm::realization_MaskDm( const realization_MaskDm & ) throw() // other
{}

const realization_MaskDm &realization_MaskDm::operator =( const realization_MaskDm &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
