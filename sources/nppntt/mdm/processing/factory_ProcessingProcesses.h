#pragma once

#include "jmsf/Singleton.hpp"

#include "NewFileAppenders.hxx"
#include "NewVoiceFileDispatcher.hxx"
#include "VoiceFileDecipher.hxx"
#include "PreliminaryVoiceFileAndKeyMatchFinder.hxx"
#include "RecurrentVoiceFileAndKeyMatchFinder.hxx"
#include "ImmediateVoiceFileAndKeyPairVerifier.hxx"
#include "LastChanceServiceFileMatchFinder.hxx"
#include "VoiceFileDeleter.hxx"

#include "NewServiceFileDispatcher.hxx"
#include "ServiceFileDeleter.hxx"

#include "ServiceFileAndKeyMatchFinder.hxx"
#include "ResultToStorageAppender.hxx"

#include "NewKeyDispatcher.hxx"
#include "KeyArray.hxx"
#include "ServiceFileArray.hxx"

#include "../FileFilters.hxx"
#include "../StatisticsQueues.hxx"
#include "../ProcessingQueues.hxx"
#include "../ExternalSoftware.hxx"

#include "jmsf/mtf/Thread.hxx"
#include "jmsf/TextString.hxx"
#include "jmsf/Container.hxx"
#include "jmsf/Proxies.hxx"


namespace nppntt {
namespace mdm {
namespace processing {


class factory_ProcessingProcesses :
	public ::jmsf::Singleton< factory_ProcessingProcesses >
{

public:
	virtual ::jmsf::Proxy< NewFileAppenders > createNewFileAppenders(
		const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< ::jmsf::TextString > > > &pathToFolderWithDataFilesArray,
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< NewVoiceFileDispatcher > createNewVoiceFileDispatcher(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< FileFilters > &fileFilter,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< VoiceFileDecipher > createVoiceFileDecipher(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< KeyArray > &keyArray,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< FileFilters > &fileFilters,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< ImmediateVoiceFileAndKeyPairVerifier > createImmediateVoiceFileAndKeyPairVerifier(
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< PreliminaryVoiceFileAndKeyMatchFinder > createPreliminaryVoiceFileAndKeyMatchFinder(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< KeyArray > &keyArray,
		const ::jmsf::Proxy< FileFilters > &fileFilters,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< RecurrentVoiceFileAndKeyMatchFinder > createRecurrentVoiceFileAndKeyMatchFinder(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< KeyArray > &keyArray,
		const ::jmsf::Proxy< FileFilters > &fileFilters,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< VoiceFileDeleter > createVoiceFileDeleter(
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< NewServiceFileDispatcher > createNewServiceFileDispatcher(
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ServiceFileArray > &serviceFileArray,
		const ::jmsf::Proxy< FileFilters > &fileFilters,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< ServiceFileDeleter > createServiceFileDeleter(
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< ServiceFileAndKeyMatchFinder > createServiceFileAndKeyMatchFinder(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ServiceFileArray > &serviceFileArray,
		const ::jmsf::Proxy< FileFilters > &fileFilters,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< LastChanceServiceFileMatchFinder > createLastChanceServiceFileMatchFinder(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< KeyArray > &keyArray,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< ResultToStorageAppender > createResultToStorageAppender(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< NewKeyDispatcher > createNewKeyDispatcher(
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< KeyArray > &keyArray,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< KeyArray > createKeyArray() const throw() = 0;

	virtual ::jmsf::Proxy< ServiceFileArray > createServiceFileArray(
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< FileFilters > &fileFilters ) const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_ProcessingProcesses() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< factory_ProcessingProcesses >;
	static factory_ProcessingProcesses *createInstance() throw();

protected:
	factory_ProcessingProcesses() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_ProcessingProcesses( const factory_ProcessingProcesses &other ) throw();
	const factory_ProcessingProcesses &operator =( const factory_ProcessingProcesses &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
