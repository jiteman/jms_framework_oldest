#include "Configuration.h"
#include "realizations/realization_Configuration.h"
#include "jmsf/Should.h"

namespace nppntt {
namespace ssd_reading {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Configuration::~Configuration() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
Configuration *Configuration::createInstance() throw() {
	return new realizations::realization_Configuration;
}

Configuration::Configuration() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Configuration::Configuration( const Configuration & ) throw() // other
{}

const Configuration &Configuration::operator =( const Configuration &other ) throw( ::jmsf::Exception ) {
	if ( this == &other ) return *this;

	// copy
	::jmsf::Should::neverViolateCopyingProhibition( "Configuration::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace ssd_reading
} // namespace nppntt
