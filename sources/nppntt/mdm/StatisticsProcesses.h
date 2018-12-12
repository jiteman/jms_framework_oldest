#pragma once

#include "jmsf/Object.h"

#include "statistics/NewVoiceFileStatisticsProcess.hxx"
#include "statistics/NewServiceFileStatisticsProcess.hxx"
#include "statistics/VoiceFileForDecipheringStatisticsProcess.hxx"
#include "statistics/DecipheredVoiceFileAndKeyPairStatisticsProcess.hxx"
#include "statistics/NotDecipheredVoiceFileStatisticsProcess.hxx"
#include "statistics/ResultVoiceFileAndServiceFilePairStatisticsProcess.hxx"
#include "statistics/ResultVoiceFileStatisticsProcess.hxx"
#include "statistics/ResultServiceFileStatisticsProcess.hxx"
#include "statistics/DeletedVoiceFileStatisticsProcess.hxx"
#include "statistics/DeletedServiceFileStatisticsProcess.hxx"

#include "jmsf/mtf/Thread.hxx"
#include "jmsf/Container.hxx"
#include "jmsf/Proxies.hxx"

namespace nppntt {
namespace mdm {

class StatisticsProcesses :
	public virtual ::jmsf::Object
{

public:
	virtual ::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess > &takeNewVoiceFileStatisticsProcess() throw() = 0;
	virtual ::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess > &takeNewServiceFileStatisticsProcess() throw() = 0;
	virtual ::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess > &takeVoiceFileForDecipheringStatisticsProcess() throw() = 0;
	virtual ::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess > &takeDecipheredVoiceFileAndKeyPairStatisticsProcess() throw() = 0;
	virtual ::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess > &takeNotDecipheredVoiceFileStatisticsProcess() throw() = 0;
	virtual ::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess > &takeResultVoiceFileAndServiceFilePairStatisticsProcess() throw() = 0;
	virtual ::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess > &takeResultVoiceFileStatisticsProcess() throw() = 0;
	virtual ::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess > &takeResultServiceFileStatisticsProcess() throw() = 0;
	virtual ::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess > &takeDeletedVoiceFileStatisticsProcess() throw() = 0;
	virtual ::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess > &takeDeletedServiceFileStatisticsProcess() throw() = 0;

	virtual ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &takeThreadContainer() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static StatisticsProcesses *getNull() throw();
	static StatisticsProcesses *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< StatisticsProcesses > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace mdm
} // namespace nppntt
