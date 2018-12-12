#include "null_ResultVoiceFileAndServiceFilePairStatisticsProcess.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ResultVoiceFileAndServiceFilePairStatisticsProcess::~null_ResultVoiceFileAndServiceFilePairStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ResultVoiceFileAndServiceFilePairStatisticsProcess *null_ResultVoiceFileAndServiceFilePairStatisticsProcess::createInstance() throw() {
	return new null_ResultVoiceFileAndServiceFilePairStatisticsProcess;
}

null_ResultVoiceFileAndServiceFilePairStatisticsProcess::null_ResultVoiceFileAndServiceFilePairStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ResultVoiceFileAndServiceFilePairStatisticsProcess > null_ResultVoiceFileAndServiceFilePairStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< ResultVoiceFileAndServiceFilePairStatisticsProcess >::createUnique( this );
}

null_ResultVoiceFileAndServiceFilePairStatisticsProcess::null_ResultVoiceFileAndServiceFilePairStatisticsProcess( const null_ResultVoiceFileAndServiceFilePairStatisticsProcess & ) throw() // other
{}

const null_ResultVoiceFileAndServiceFilePairStatisticsProcess &null_ResultVoiceFileAndServiceFilePairStatisticsProcess::operator =( const null_ResultVoiceFileAndServiceFilePairStatisticsProcess &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
}
