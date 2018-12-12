#include "null_NewServiceFileStatisticsProcess.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_NewServiceFileStatisticsProcess::~null_NewServiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_NewServiceFileStatisticsProcess *null_NewServiceFileStatisticsProcess::createInstance() throw() {
	return new null_NewServiceFileStatisticsProcess;
}

null_NewServiceFileStatisticsProcess::null_NewServiceFileStatisticsProcess() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< NewServiceFileStatisticsProcess > null_NewServiceFileStatisticsProcess::createClone() const throw() {
	return ::jmsf::Proxy< NewServiceFileStatisticsProcess >::createUnique( this );
}

null_NewServiceFileStatisticsProcess::null_NewServiceFileStatisticsProcess( const null_NewServiceFileStatisticsProcess & ) throw() // other
{}

const null_NewServiceFileStatisticsProcess &null_NewServiceFileStatisticsProcess::operator =( const null_NewServiceFileStatisticsProcess &other ) throw() {
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
