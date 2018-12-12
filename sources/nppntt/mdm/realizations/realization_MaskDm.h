#pragma once

#include "../MaskDm.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "../FileFilters.hxx"
#include "../processing/NewFileAppenders.hxx"
#include "../StatisticsQueues.hxx"
#include "../ProcessingQueues.hxx"
#include "../StatisticsProcesses.hxx"
#include "../ProcessingProcesses.hxx"
#include "../ExternalSoftware.hxx"

#include "jmsf/mtf/Thread.hxx"
#include "jmsf/assisting/Functors.hxx"

#include "realization_factory_MaskDm.hxx"

namespace nppntt {
namespace mdm {
namespace realizations {

class realization_MaskDm :
	public MaskDm,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals MaskDm
	::jmsf::Boolean wasInitializedCorrectly() const throw();
	void continueDecipchering() throw();
	void stopDecipchering() throw();

	void changeFileAppenderFolders(
		const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< ::jmsf::TextString > > > &pathToFolderWithFilesContainer ) throw();

	void updateFileFilter( const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter ) throw();
	void setDecipheringTimeLimit( const ::jmsf::ConstantPointer< _decipherTimeLimit > &timeLimitData ) throw();
	const ::jmsf::ConstantProxy< externals::data::statistics::ed_Summary > &getStatistics() throw();

	void clearExpiredServiceFiles() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_MaskDm() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_MaskDm;
	realization_MaskDm(
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
		const ::jmsf::ConstantProxy< ::jmsf::assisting::ConstantFunctor< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &threadWaitTillTerminatingIsCompletedFunctor ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< MaskDm > createClone() const throw();

private:
	realization_MaskDm( const realization_MaskDm &other ) throw();
	const realization_MaskDm &operator =( const realization_MaskDm &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< FileFilters > _fileFilters;
	::jmsf::Proxy< processing::NewFileAppenders > _newFileAppenders;
	::jmsf::Proxy< StatisticsQueues > _statisticsQueues;
	::jmsf::Proxy< ProcessingQueues > _processingQueues;
	::jmsf::Proxy< StatisticsProcesses > _statisticsProcesses;
	::jmsf::Proxy< ProcessingProcesses > _processingProcesses;
	::jmsf::Proxy< ExternalSoftware > _externalSoftware;

	::jmsf::Proxy< ::jmsf::mtf::Thread > _newFileAppendersThread;

	::jmsf::Proxy< ::jmsf::assisting::Functor< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > _threadLaunchFunctor;
	::jmsf::Proxy< ::jmsf::assisting::Functor< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > _threadResumeFunctor;
	::jmsf::Proxy< ::jmsf::assisting::Functor< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > _threadSuspendFunctor;
	const ::jmsf::ConstantProxy< ::jmsf::assisting::ConstantFunctor< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > _threadWaitTillIsSuspendedFunctor;
	const ::jmsf::ConstantProxy< ::jmsf::assisting::ConstantFunctor< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > _threadWaitTillTerminatingIsCompletedFunctor;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	::jmsf::Boolean _wasNewFileAppendersLaunched;
	::jmsf::Boolean _wasLaunched;
	::jmsf::Boolean _isDecipheringStopped;
	::jmsf::Boolean _wasInitializedCorrectly;

};


} // namespace
}
}
