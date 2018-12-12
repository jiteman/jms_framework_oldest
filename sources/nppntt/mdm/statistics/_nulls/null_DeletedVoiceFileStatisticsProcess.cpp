#include "null_DeletedVoiceFileStatisticsProcess.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_DeletedVoiceFileStatisticsProcess::~null_DeletedVoiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_DeletedVoiceFileStatisticsProcess *null_DeletedVoiceFileStatisticsProcess::createInstance() throw() {
	return new null_DeletedVoiceFileStatisticsProcess;
}

null_DeletedVoiceFileStatisticsProcess::null_DeletedVoiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< DeletedVoiceFileStatisticsProcess > null_DeletedVoiceFileStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< DeletedVoiceFileStatisticsProcess >::createUnique( this );
}

null_DeletedVoiceFileStatisticsProcess::null_DeletedVoiceFileStatisticsProcess( const null_DeletedVoiceFileStatisticsProcess & ) throw() // other
{}

const null_DeletedVoiceFileStatisticsProcess &null_DeletedVoiceFileStatisticsProcess::operator =( const null_DeletedVoiceFileStatisticsProcess &other ) throw() {
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
