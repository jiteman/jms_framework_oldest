#include "null_NotDecipheredVoiceFileStatisticsProcess.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_NotDecipheredVoiceFileStatisticsProcess::~null_NotDecipheredVoiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_NotDecipheredVoiceFileStatisticsProcess *null_NotDecipheredVoiceFileStatisticsProcess::createInstance() throw() {
	return new null_NotDecipheredVoiceFileStatisticsProcess;
}

null_NotDecipheredVoiceFileStatisticsProcess::null_NotDecipheredVoiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< NotDecipheredVoiceFileStatisticsProcess > null_NotDecipheredVoiceFileStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< NotDecipheredVoiceFileStatisticsProcess >::createUnique( this );
}

null_NotDecipheredVoiceFileStatisticsProcess::null_NotDecipheredVoiceFileStatisticsProcess( const null_NotDecipheredVoiceFileStatisticsProcess & ) throw() // other
{}

const null_NotDecipheredVoiceFileStatisticsProcess &null_NotDecipheredVoiceFileStatisticsProcess::operator =( const null_NotDecipheredVoiceFileStatisticsProcess &other ) throw() {
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
