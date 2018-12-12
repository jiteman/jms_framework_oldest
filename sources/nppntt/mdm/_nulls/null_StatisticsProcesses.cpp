#include "null_StatisticsProcesses.h"

#include "../statistics/NewVoiceFileStatisticsProcess.h"
#include "../statistics/NewServiceFileStatisticsProcess.h"
#include "../statistics/VoiceFileForDecipheringStatisticsProcess.h"
#include "../statistics/DecipheredVoiceFileAndKeyPairStatisticsProcess.h"
#include "../statistics/NotDecipheredVoiceFileStatisticsProcess.h"
#include "../statistics/ResultVoiceFileAndServiceFilePairStatisticsProcess.h"
#include "../statistics/ResultVoiceFileStatisticsProcess.h"
#include "../statistics/ResultServiceFileStatisticsProcess.h"
#include "../statistics/DeletedVoiceFileStatisticsProcess.h"
#include "../statistics/DeletedServiceFileStatisticsProcess.h"

#include "jmsf/osie/runup/RunnableArray.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace nulls {


::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess > null_StatisticsProcesses::getOneselfNewVoiceFileStatisticsProcess() throw() {
	return _newVoiceFileStatisticsProcess;
}

::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess > null_StatisticsProcesses::getOneselfNewServiceFileStatisticsProcess() throw() {
	return _newServiceFileStatisticsProcess;
}

::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess > null_StatisticsProcesses::getOneselfVoiceFileForDecipheringStatisticsProcess() throw() {
	return _voiceFileForDecipheringStatisticsProcess;
}

::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess > null_StatisticsProcesses::getOneselfDecipheredVoiceFileAndKeyPairStatisticsProcess() throw() {
	return _decipheredVoiceFileAndKeyPairStatisticsProcess;
}

::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess > null_StatisticsProcesses::getOneselfNotDecipheredVoiceFileStatisticsProcess() throw() {
	return _notDecipheredVoiceFileStatisticsProcess;
}

::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess > null_StatisticsProcesses::getOneselfResultVoiceFileAndServiceFilePairStatisticsProcess() throw() {
	return _resultVoiceFileAndServiceFilePairStatisticsProcess;
}

::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess > null_StatisticsProcesses::getOneselfResultVoiceFileStatisticsProcess() throw() {
	return _resultVoiceFileStatisticsProcess;
}

::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess > null_StatisticsProcesses::getOneselfResultServiceFileStatisticsProcess() throw() {
	return _resultServiceFileStatisticsProcess;
}

::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess > null_StatisticsProcesses::getOneselfDeletedVoiceFileStatisticsProcess() throw() {
	return _deletedVoiceFileStatisticsProcess;
}

::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess > null_StatisticsProcesses::getOneselfDeletedServiceFileStatisticsProcess() throw() {
	return _deletedServiceFileStatisticsProcess;
}

::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray > null_StatisticsProcesses::getOneselfProcessArray() throw() {
	return _processArray;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_StatisticsProcesses::~null_StatisticsProcesses() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_StatisticsProcesses *null_StatisticsProcesses::createInstance() throw() {
	return new null_StatisticsProcesses;
}

null_StatisticsProcesses::null_StatisticsProcesses() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< StatisticsProcesses > null_StatisticsProcesses::createClone() const throw() {
	return ::jmsf::Proxy< StatisticsProcesses >::createUnique( this );
}

null_StatisticsProcesses::null_StatisticsProcesses( const null_StatisticsProcesses & ) throw() // other
{}

const null_StatisticsProcesses &null_StatisticsProcesses::operator =( const null_StatisticsProcesses &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
