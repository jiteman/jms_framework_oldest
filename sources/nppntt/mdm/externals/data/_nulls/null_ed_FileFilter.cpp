#include "null_ed_FileFilter.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace nulls {


void null_ed_FileFilter::renew( const ::jmsf::ConstantProxy< ed_FileFilter > & ) throw( ::jmsf::Exception ) // fileFilter
{}

::jmsf::Boolean null_ed_FileFilter::isFileLifeTimeExpired( const ::jmsf::ConstantProxy< ed_VoiceFile > & ) const throw( ::jmsf::Exception ) { // voiceFile
	return ::jmsf::False;
}

::jmsf::Boolean null_ed_FileFilter::isFileLifeTimeExpired( const ::jmsf::ConstantProxy< ed_ServiceFile > & ) const throw( ::jmsf::Exception ) { // serviceFile
	return ::jmsf::False;
}

::jmsf::Boolean null_ed_FileFilter::isFileSuitableForDeciphering( const ::jmsf::ConstantProxy< ed_VoiceFile > & ) const throw( ::jmsf::Exception ) { // voiceFile
	return ::jmsf::False;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ed_FileFilter::~null_ed_FileFilter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ed_FileFilter *null_ed_FileFilter::createInstance() throw() {
	return new null_ed_FileFilter;
}

null_ed_FileFilter::null_ed_FileFilter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_FileFilter > null_ed_FileFilter::createClone() const throw() {
	return ::jmsf::Proxy< ed_FileFilter >::createUnique( this );
}

null_ed_FileFilter::null_ed_FileFilter( const null_ed_FileFilter & ) throw() // other
{}

const null_ed_FileFilter &null_ed_FileFilter::operator =( const null_ed_FileFilter &other ) throw() {
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
}
