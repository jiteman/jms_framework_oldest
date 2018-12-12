#include "null_ExternalSoftware.h"
#include "../externals/software/es_FileAppender.h"
#include "../externals/software/es_Decipher.h"
#include "../externals/software/es_StatisticsUpdater.h"
#include "jmsf/osie/runup/RunnableArray.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace nulls {


::jmsf::Proxy< externals::software::es_FileAppender > null_ExternalSoftware::getOneselfFileAppender() throw() {
	return _fileAppender.getWeak();
}

::jmsf::Proxy< externals::software::es_Decipher > null_ExternalSoftware::getOneselfDecipher() throw() {
	return _decipher.getWeak();
}

::jmsf::Proxy< externals::software::es_StatisticsUpdater > null_ExternalSoftware::getOneselfStatisticsUpdater() throw() {
	return _statisticsUpdater.getWeak();
}

const ::jmsf::ConstantProxy< externals::software::es_StatisticsUpdater > null_ExternalSoftware::getStatisticsUpdater() const throw() {
	return _statisticsUpdater.getWeak();
}

::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray > null_ExternalSoftware::getOneselfProcessArray() throw() {
	return _processArray.getWeak();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ExternalSoftware::~null_ExternalSoftware() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ExternalSoftware *null_ExternalSoftware::createInstance() throw() {
	return new null_ExternalSoftware;
}

null_ExternalSoftware::null_ExternalSoftware() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ExternalSoftware > null_ExternalSoftware::createClone() const throw() {
	return ::jmsf::Proxy< ExternalSoftware >::createUnique( this );
}

null_ExternalSoftware::null_ExternalSoftware( const null_ExternalSoftware & ) throw() // other
{}

const null_ExternalSoftware &null_ExternalSoftware::operator =( const null_ExternalSoftware &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
