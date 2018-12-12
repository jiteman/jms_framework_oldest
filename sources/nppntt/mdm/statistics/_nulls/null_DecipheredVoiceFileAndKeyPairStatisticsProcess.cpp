#include "null_DecipheredVoiceFileAndKeyPairStatisticsProcess.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_DecipheredVoiceFileAndKeyPairStatisticsProcess::~null_DecipheredVoiceFileAndKeyPairStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_DecipheredVoiceFileAndKeyPairStatisticsProcess *null_DecipheredVoiceFileAndKeyPairStatisticsProcess::createInstance() throw() {
	return new null_DecipheredVoiceFileAndKeyPairStatisticsProcess;
}

null_DecipheredVoiceFileAndKeyPairStatisticsProcess::null_DecipheredVoiceFileAndKeyPairStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< DecipheredVoiceFileAndKeyPairStatisticsProcess > null_DecipheredVoiceFileAndKeyPairStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< DecipheredVoiceFileAndKeyPairStatisticsProcess >::createUnique( this );
}

null_DecipheredVoiceFileAndKeyPairStatisticsProcess::null_DecipheredVoiceFileAndKeyPairStatisticsProcess( const null_DecipheredVoiceFileAndKeyPairStatisticsProcess & ) throw() // other
{}

const null_DecipheredVoiceFileAndKeyPairStatisticsProcess &null_DecipheredVoiceFileAndKeyPairStatisticsProcess::operator =( const null_DecipheredVoiceFileAndKeyPairStatisticsProcess &other ) throw() {
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
