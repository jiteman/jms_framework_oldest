#pragma once

#include "jmsf/Singleton.hpp"

#include "../StatisticsQueues.hxx"
#include "../ProcessingQueues.hxx"
#include "../ExternalSoftware.hxx"
#include "NewVoiceFileStatisticsProcess.hxx"
#include "NewServiceFileStatisticsProcess.hxx"
#include "VoiceFileForDecipheringStatisticsProcess.hxx"
#include "DecipheredVoiceFileAndKeyPairStatisticsProcess.hxx"
#include "NotDecipheredVoiceFileStatisticsProcess.hxx"
#include "ResultVoiceFileAndServiceFilePairStatisticsProcess.hxx"
#include "ResultVoiceFileStatisticsProcess.hxx"
#include "ResultServiceFileStatisticsProcess.hxx"
#include "DeletedVoiceFileStatisticsProcess.hxx"
#include "DeletedServiceFileStatisticsProcess.hxx"
#include "jmsf/mtf/Thread.hxx"
#include "jmsf/Proxies.hxx"


namespace nppntt {
namespace mdm {
namespace statistics {


class factory_StatisticsProcesses :
	public ::jmsf::Singleton< factory_StatisticsProcesses >
{

public:
	virtual ::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess > createNewVoiceFileStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess > createNewServiceFileStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess > createVoiceFileForDecipheringStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess > createDecipheredVoiceFileAndKeyPairStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess > createNotDecipheredVoiceFileStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess > createResultVoiceFileAndServiceFilePairStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess > createResultVoiceFileStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess > createResultServiceFileStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess > createDeletedVoiceFileStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

	virtual ::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess > createDeletedServiceFileStatisticsProcess(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< ::jmsf::mtf::Thread > &thread ) const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_StatisticsProcesses() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< factory_StatisticsProcesses >;
	static factory_StatisticsProcesses *createInstance() throw();

protected:
	factory_StatisticsProcesses() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_StatisticsProcesses( const factory_StatisticsProcesses &other ) throw();
	const factory_StatisticsProcesses &operator =( const factory_StatisticsProcesses &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
