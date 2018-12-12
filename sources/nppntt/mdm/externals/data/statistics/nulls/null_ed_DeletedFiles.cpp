#include "null_ed_DeletedFiles.h"

#include "../../../others/abstractStatistics.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace nulls {


::jmsf::Pointer< DeleteFilesStatisticsData > null_ed_DeletedFiles::getOneselfData() throw( ::jmsf::Exception ) {
	return _deletedFilesData;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ed_DeletedFiles::~null_ed_DeletedFiles() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ed_DeletedFiles *null_ed_DeletedFiles::createInstance() throw() {
	return new null_ed_DeletedFiles;
}

null_ed_DeletedFiles::null_ed_DeletedFiles() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_DeletedFiles > null_ed_DeletedFiles::createClone() const throw() {
	return ::jmsf::Proxy< ed_DeletedFiles >::createUnique( this );
}

null_ed_DeletedFiles::null_ed_DeletedFiles( const null_ed_DeletedFiles & ) throw() // other
{}

const null_ed_DeletedFiles &null_ed_DeletedFiles::operator =( const null_ed_DeletedFiles &other ) throw() {
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
