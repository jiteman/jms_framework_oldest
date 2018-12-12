#include "null_NewVoiceFileStatisticsProcess.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_NewVoiceFileStatisticsProcess::~null_NewVoiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_NewVoiceFileStatisticsProcess *null_NewVoiceFileStatisticsProcess::createInstance() throw() {
	return new null_NewVoiceFileStatisticsProcess;
}

null_NewVoiceFileStatisticsProcess::null_NewVoiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< NewVoiceFileStatisticsProcess > null_NewVoiceFileStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< NewVoiceFileStatisticsProcess >::createUnique( this );
}

null_NewVoiceFileStatisticsProcess::null_NewVoiceFileStatisticsProcess( const null_NewVoiceFileStatisticsProcess & ) throw() // other
{}

const null_NewVoiceFileStatisticsProcess &null_NewVoiceFileStatisticsProcess::operator =( const null_NewVoiceFileStatisticsProcess &other ) throw() {
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
