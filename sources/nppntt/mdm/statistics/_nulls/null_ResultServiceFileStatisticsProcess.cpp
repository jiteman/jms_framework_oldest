#include "null_ResultServiceFileStatisticsProcess.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ResultServiceFileStatisticsProcess::~null_ResultServiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ResultServiceFileStatisticsProcess *null_ResultServiceFileStatisticsProcess::createInstance() throw() {
	return new null_ResultServiceFileStatisticsProcess;
}

null_ResultServiceFileStatisticsProcess::null_ResultServiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ResultServiceFileStatisticsProcess > null_ResultServiceFileStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< ResultServiceFileStatisticsProcess >::createUnique( this );
}

null_ResultServiceFileStatisticsProcess::null_ResultServiceFileStatisticsProcess( const null_ResultServiceFileStatisticsProcess & ) throw() // other
{}

const null_ResultServiceFileStatisticsProcess &null_ResultServiceFileStatisticsProcess::operator =( const null_ResultServiceFileStatisticsProcess &other ) throw() {
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
