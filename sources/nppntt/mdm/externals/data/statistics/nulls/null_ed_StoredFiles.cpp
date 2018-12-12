#include "null_ed_StoredFiles.h"

#include "../../../others/abstractStatistics.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace nulls {


::jmsf::Pointer< DataBaseStatisticsData > null_ed_StoredFiles::getOneselfData() throw( ::jmsf::Exception ) {
	return _storedFilesData;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ed_StoredFiles::~null_ed_StoredFiles() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ed_StoredFiles *null_ed_StoredFiles::createInstance() throw() {
	return new null_ed_StoredFiles;
}

null_ed_StoredFiles::null_ed_StoredFiles() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_StoredFiles > null_ed_StoredFiles::createClone() const throw() {
	return ::jmsf::Proxy< ed_StoredFiles >::createUnique( this );
}

null_ed_StoredFiles::null_ed_StoredFiles( const null_ed_StoredFiles & ) throw() // other
{}

const null_ed_StoredFiles &null_ed_StoredFiles::operator =( const null_ed_StoredFiles &other ) throw() {
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
