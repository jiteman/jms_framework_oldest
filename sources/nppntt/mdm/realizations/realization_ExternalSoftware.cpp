#include "realization_ExternalSoftware.h"
#include "../exceptions/exception_DllNotFound.h"
#include "../externals/others/abstractApplyKey.h"
#include "../externals/others/abstractKcDll.h"
#include "../externals/software/es_FileAppender.h"
#include "../externals/software/es_Decipher.h"
#include "../externals/software/es_StatisticsUpdater.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace realizations {

::jmsf::Proxy< externals::software::es_Decipher > &realization_ExternalSoftware::takeDecipher() throw() {
	return _decipher;
}

::jmsf::Proxy< externals::software::es_StatisticsUpdater > &realization_ExternalSoftware::takeStatisticsUpdater() throw() {
	return _statisticsUpdater;
}

const ::jmsf::ConstantProxy< externals::software::es_StatisticsUpdater > &realization_ExternalSoftware::getStatisticsUpdater() const throw() {
	return _constantStatisticsUpdater;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ExternalSoftware::~realization_ExternalSoftware() throw() {
	::unloadApplyKcDll();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ExternalSoftware::realization_ExternalSoftware(
		::jmsf::Proxy< externals::software::es_Decipher > decipher,
		::jmsf::Proxy< externals::software::es_StatisticsUpdater > statisticsUpdater ) throw( jmsf::Exception )
	:
		_decipher( decipher ),
		_statisticsUpdater( statisticsUpdater )
{
	_constantStatisticsUpdater = _statisticsUpdater.getWeakConstant();

	// REFACTOR: remove it to single key checker with two methods (for voice file and service file)
	if ( ::jmsf::Boolean( ::loadApplyKcDll() ).not() ) {
		throw exceptions::exception_DllNotFound( ::jmsf::CONSTANT_TEXT_STRING( "File and key match checker dll was not found" ) );
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ExternalSoftware > realization_ExternalSoftware::createClone() const throw() {
	return ::jmsf::Proxy< ExternalSoftware >::createUnique( new realization_ExternalSoftware( *this ) );
}

realization_ExternalSoftware::realization_ExternalSoftware( const realization_ExternalSoftware & ) throw() // other
{}

const realization_ExternalSoftware &realization_ExternalSoftware::operator =( const realization_ExternalSoftware &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
