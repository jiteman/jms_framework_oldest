#include "null_ed_AppendedFiles.h"

#include "../../../others/abstractStatistics.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace nulls {


::jmsf::Pointer< FileAppenderStatisticsData > null_ed_AppendedFiles::getOneselfData() throw( ::jmsf::Exception ) {
	return _appendedFilesData.getWeak();
}

const ::jmsf::ConstantPointer< FileAppenderStatisticsData > null_ed_AppendedFiles::getData() const throw( ::jmsf::Exception ) {
	return _appendedFilesData.getWeakConstant();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ed_AppendedFiles::~null_ed_AppendedFiles() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ed_AppendedFiles *null_ed_AppendedFiles::createInstance() throw() {
	return new null_ed_AppendedFiles;
}

null_ed_AppendedFiles::null_ed_AppendedFiles() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_AppendedFiles > null_ed_AppendedFiles::createClone() const throw() {
	return ::jmsf::Proxy< ed_AppendedFiles >::createUnique( this );
}

null_ed_AppendedFiles::null_ed_AppendedFiles( const null_ed_AppendedFiles & ) throw() // other
{}

const null_ed_AppendedFiles &null_ed_AppendedFiles::operator =( const null_ed_AppendedFiles &other ) throw() {
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
