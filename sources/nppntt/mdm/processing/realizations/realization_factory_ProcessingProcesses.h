#pragma once

#include "../factory_ProcessingProcesses.h"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

class realization_factory_ProcessingProcesses :
	public factory_ProcessingProcesses
{

public:
	// virtuals factory_ProcessingProcesses
	::jmsf::Proxy< NewFileAppenders > createNewFileAppenders(
		const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< ::jmsf::TextString > > > &pathToFolderWithDataFilesArray,
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< NewVoiceFileDispatcher > createNewVoiceFileDispatcher(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< FileFilters > &fileFilters,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< VoiceFileDecipher > createVoiceFileDecipher(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< KeyArray > &keyArray,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< FileFilters > &fileFilters,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< ImmediateVoiceFileAndKeyPairVerifier > createImmediateVoiceFileAndKeyPairVerifier(
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< PreliminaryVoiceFileAndKeyMatchFinder > createPreliminaryVoiceFileAndKeyMatchFinder(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< KeyArray > &keyArray,
		const ::jmsf::Proxy< FileFilters > &fileFilters,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< RecurrentVoiceFileAndKeyMatchFinder > createRecurrentVoiceFileAndKeyMatchFinder(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< KeyArray > &keyArray,
		const ::jmsf::Proxy< FileFilters > &fileFilters,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< VoiceFileDeleter > createVoiceFileDeleter(
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< NewServiceFileDispatcher > createNewServiceFileDispatcher(
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ServiceFileArray > &serviceFileArray,
		const ::jmsf::Proxy< FileFilters > &fileFilters,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< ServiceFileDeleter > createServiceFileDeleter(
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< ServiceFileAndKeyMatchFinder > createServiceFileAndKeyMatchFinder(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ServiceFileArray > &serviceFileArray,
		const ::jmsf::Proxy< FileFilters > &fileFilters,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< LastChanceServiceFileMatchFinder > createLastChanceServiceFileMatchFinder(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< KeyArray > &keyArray,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< ResultToStorageAppender > createResultToStorageAppender(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< NewKeyDispatcher > createNewKeyDispatcher(
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< KeyArray > &keyArray,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< KeyArray > createKeyArray() const throw();

	::jmsf::Proxy< ServiceFileArray > createServiceFileArray(
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< FileFilters > &fileFilters ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_ProcessingProcesses() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class factory_ProcessingProcesses;
	realization_factory_ProcessingProcesses() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_ProcessingProcesses( const realization_factory_ProcessingProcesses &other ) throw();
	const realization_factory_ProcessingProcesses &operator =( const realization_factory_ProcessingProcesses &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	static const ::jmsf::natural_size VOICE_FILE_AND_KEY_PAIR_CHECKER_FOR_PRELIMINARY_MATCH_FINDER_QUANTITY = 4;
	static const ::jmsf::natural_size VOICE_FILE_AND_KEY_PAIR_CHECKER_FOR_RECURRENT_MATCH_FINDER_QUANTITY = 4;
	static const ::jmsf::natural_size SERVICE_FILE_AND_KEY_PAIR_CHECKER_FOR_LAST_CHANCE_MATCH_FINDER_QUANTITY = 4;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
}
}
