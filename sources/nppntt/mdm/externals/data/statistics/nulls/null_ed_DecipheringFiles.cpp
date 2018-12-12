#include "null_ed_DecipheringFiles.h"

#include "../../../others/abstractStatistics.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace nulls {


::jmsf::Pointer< DecipherStatisticsData > null_ed_DecipheringFiles::getOneselfData() throw( ::jmsf::Exception ) {
	return _decipheringFilesData;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ed_DecipheringFiles::~null_ed_DecipheringFiles() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ed_DecipheringFiles *null_ed_DecipheringFiles::createInstance() throw() {
	return new null_ed_DecipheringFiles;
}

null_ed_DecipheringFiles::null_ed_DecipheringFiles() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_DecipheringFiles > null_ed_DecipheringFiles::createClone() const throw() {
	return ::jmsf::Proxy< ed_DecipheringFiles >::createUnique( this );
}

null_ed_DecipheringFiles::null_ed_DecipheringFiles( const null_ed_DecipheringFiles & ) throw() // other
{}

const null_ed_DecipheringFiles &null_ed_DecipheringFiles::operator =( const null_ed_DecipheringFiles &other ) throw() {
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
}
