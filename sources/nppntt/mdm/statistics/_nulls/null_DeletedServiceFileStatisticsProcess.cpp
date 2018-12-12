#include "null_DeletedServiceFileStatisticsProcess.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_DeletedServiceFileStatisticsProcess::~null_DeletedServiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_DeletedServiceFileStatisticsProcess *null_DeletedServiceFileStatisticsProcess::createInstance() throw() {
	return new null_DeletedServiceFileStatisticsProcess;
}

null_DeletedServiceFileStatisticsProcess::null_DeletedServiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< DeletedServiceFileStatisticsProcess > null_DeletedServiceFileStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< DeletedServiceFileStatisticsProcess >::createUnique( this );
}

null_DeletedServiceFileStatisticsProcess::null_DeletedServiceFileStatisticsProcess( const null_DeletedServiceFileStatisticsProcess & ) throw() // other
{}

const null_DeletedServiceFileStatisticsProcess &null_DeletedServiceFileStatisticsProcess::operator =( const null_DeletedServiceFileStatisticsProcess &other ) throw() {
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
