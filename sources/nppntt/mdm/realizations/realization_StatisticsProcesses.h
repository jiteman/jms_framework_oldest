#pragma once

#include "../StatisticsProcesses.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "realization_factory_MaskDmObjects.hxx"

namespace nppntt {
namespace mdm {
namespace realizations {

class realization_StatisticsProcesses :
	public StatisticsProcesses,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals StatisticsProcesses
	::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess > &takeNewVoiceFileStatisticsProcess() throw();
	::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess > &takeNewServiceFileStatisticsProcess() throw();
	::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess > &takeVoiceFileForDecipheringStatisticsProcess() throw();
	::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess > &takeDecipheredVoiceFileAndKeyPairStatisticsProcess() throw();
	::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess > &takeNotDecipheredVoiceFileStatisticsProcess() throw();
	::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess > &takeResultVoiceFileAndServiceFilePairStatisticsProcess() throw();
	::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess > &takeResultVoiceFileStatisticsProcess() throw();
	::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess > &takeResultServiceFileStatisticsProcess() throw();
	::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess > &takeDeletedVoiceFileStatisticsProcess() throw();
	::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess > &takeDeletedServiceFileStatisticsProcess() throw();

	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &takeThreadContainer() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_StatisticsProcesses() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_MaskDmObjects;
	realization_StatisticsProcesses(
		const ::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess > &newVoiceFileStatisticsProcess,
		const ::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess > &newServiceFileStatisticsProcess,
		const ::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess > &voiceFileForDecipheringStatisticsProcess,
		const ::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess > &decipheredVoiceFileAndKeyPairStatisticsProcess,
		const ::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess > &notDecipheredVoiceFileStatisticsProcess,
		const ::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess > &resultVoiceFileAndServiceFilePairStatisticsProcess,
		const ::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess > &resultVoiceFileStatisticsProcess,
		const ::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess > &resultServiceFileStatisticsProcess,
		const ::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess > &deletedVoiceFileStatisticsProcess,
		const ::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess > &deletedServiceFileStatisticsProcess,
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &threadContainer ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< StatisticsProcesses > createClone() const throw();

private:
	realization_StatisticsProcesses( const realization_StatisticsProcesses &other ) throw();
	const realization_StatisticsProcesses &operator =( const realization_StatisticsProcesses &other ) throw();

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

	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > _threadContainer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
}
