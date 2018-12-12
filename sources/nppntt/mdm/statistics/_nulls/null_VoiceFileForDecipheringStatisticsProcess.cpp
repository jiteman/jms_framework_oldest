#include "null_VoiceFileForDecipheringStatisticsProcess.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_VoiceFileForDecipheringStatisticsProcess::~null_VoiceFileForDecipheringStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_VoiceFileForDecipheringStatisticsProcess *null_VoiceFileForDecipheringStatisticsProcess::createInstance() throw() {
	return new null_VoiceFileForDecipheringStatisticsProcess;
}

null_VoiceFileForDecipheringStatisticsProcess::null_VoiceFileForDecipheringStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< VoiceFileForDecipheringStatisticsProcess > null_VoiceFileForDecipheringStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< VoiceFileForDecipheringStatisticsProcess >::createUnique( this );
}

null_VoiceFileForDecipheringStatisticsProcess::null_VoiceFileForDecipheringStatisticsProcess( const null_VoiceFileForDecipheringStatisticsProcess & ) throw() // other
{}

const null_VoiceFileForDecipheringStatisticsProcess &null_VoiceFileForDecipheringStatisticsProcess::operator =( const null_VoiceFileForDecipheringStatisticsProcess &other ) throw() {
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
