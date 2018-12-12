#include "null_ResultVoiceFileStatisticsProcess.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ResultVoiceFileStatisticsProcess::~null_ResultVoiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ResultVoiceFileStatisticsProcess *null_ResultVoiceFileStatisticsProcess::createInstance() throw() {
	return new null_ResultVoiceFileStatisticsProcess;
}

null_ResultVoiceFileStatisticsProcess::null_ResultVoiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ResultVoiceFileStatisticsProcess > null_ResultVoiceFileStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< ResultVoiceFileStatisticsProcess >::createUnique( this );
}

null_ResultVoiceFileStatisticsProcess::null_ResultVoiceFileStatisticsProcess( const null_ResultVoiceFileStatisticsProcess & ) throw() // other
{}

const null_ResultVoiceFileStatisticsProcess &null_ResultVoiceFileStatisticsProcess::operator =( const null_ResultVoiceFileStatisticsProcess &other ) throw() {
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
