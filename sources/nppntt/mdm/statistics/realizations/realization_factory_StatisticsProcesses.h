#pragma once

#include "../factory_StatisticsProcesses.h"

namespace nppntt {
namespace mdm {
namespace statistics {
namespace realizations {

class realization_factory_StatisticsProcesses :
	public factory_StatisticsProcesses
{

public:
	// virtuals factory_StatisticsProcesses
	::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess > createNewVoiceFileStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess > createNewServiceFileStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess > createVoiceFileForDecipheringStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess > createDecipheredVoiceFileAndKeyPairStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess > createNotDecipheredVoiceFileStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess > createResultVoiceFileAndServiceFilePairStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess > createResultVoiceFileStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess > createResultServiceFileStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess > createDeletedVoiceFileStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();

	::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess > createDeletedServiceFileStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_StatisticsProcesses() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class factory_StatisticsProcesses;
	realization_factory_StatisticsProcesses() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_StatisticsProcesses( const realization_factory_StatisticsProcesses &other ) throw();
	const realization_factory_StatisticsProcesses &operator =( const realization_factory_StatisticsProcesses &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
}
}
