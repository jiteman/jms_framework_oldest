#pragma once

#include "../StatisticsProcesses.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace nulls {


class null_StatisticsProcesses :
	public StatisticsProcesses,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_StatisticsProcesses >
{

public:
	// virtuals StatisticsProcesses
	::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess > getOneselfNewVoiceFileStatisticsProcess() throw();
	::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess > getOneselfNewServiceFileStatisticsProcess() throw();
	::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess > getOneselfVoiceFileForDecipheringStatisticsProcess() throw();
	::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess > getOneselfDecipheredVoiceFileAndKeyPairStatisticsProcess() throw();
	::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess > getOneselfNotDecipheredVoiceFileStatisticsProcess() throw();
	::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess > getOneselfResultVoiceFileAndServiceFilePairStatisticsProcess() throw();
	::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess > getOneselfResultVoiceFileStatisticsProcess() throw();
	::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess > getOneselfResultServiceFileStatisticsProcess() throw();
	::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess > getOneselfDeletedVoiceFileStatisticsProcess() throw();
	::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess > getOneselfDeletedServiceFileStatisticsProcess() throw();

	::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray > getOneselfProcessArray() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_StatisticsProcesses() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_StatisticsProcesses >;
	static null_StatisticsProcesses *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_StatisticsProcesses() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< StatisticsProcesses > createClone() const throw();

private:
	null_StatisticsProcesses( const null_StatisticsProcesses &other ) throw();
	const null_StatisticsProcesses &operator =( const null_StatisticsProcesses &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess > _newVoiceFileStatisticsProcess;
	::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess > _newServiceFileStatisticsProcess;
	::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess > _voiceFileForDecipheringStatisticsProcess;
	::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess > _decipheredVoiceFileAndKeyPairStatisticsProcess;
	::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess > _notDecipheredVoiceFileStatisticsProcess;
	::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess > _resultVoiceFileAndServiceFilePairStatisticsProcess;
	::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess > _resultVoiceFileStatisticsProcess;
	::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess > _resultServiceFileStatisticsProcess;
	::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess > _deletedVoiceFileStatisticsProcess;
	::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess > _deletedServiceFileStatisticsProcess;

	::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray > _processArray;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
