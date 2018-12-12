#include "realization_ed_AppendedFiles.h"
#include "../../../others/abstractStatistics.h"
#include "jmsf/osie/Mutex.h"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace realizations {

::jmsf::Pointer< FileAppenderStatisticsData > &realization_ed_AppendedFiles::takeData() throw( ::jmsf::Exception ) {
	::jmsf::Should::alwaysBe( getMutex()->isLocked() );
	return _appendedFilesData;
}

const ::jmsf::ConstantPointer< FileAppenderStatisticsData > &realization_ed_AppendedFiles::getData() const throw( ::jmsf::Exception ) {
	::jmsf::Should::alwaysBe( getMutex()->isLocked() );
	return _constantAppendedFilesData;	
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ed_AppendedFiles::~realization_ed_AppendedFiles() throw() {
	::deleteFileAppenderStatistics( _appendedFilesData.get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ed_AppendedFiles::realization_ed_AppendedFiles( ::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) throw()
	:
		mixin_Lockable( mutex ),
		_appendedFilesData( ::jmsf::Pointer< FileAppenderStatisticsData >::createWeakFor( ::createFileAppenderStatistics() ) )		
{
	_constantAppendedFilesData = _appendedFilesData.getWeakConstant();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_AppendedFiles > realization_ed_AppendedFiles::createClone() const throw() {
	return ::jmsf::Proxy< ed_AppendedFiles >::createUnique( new realization_ed_AppendedFiles( *this ) );
}

realization_ed_AppendedFiles::realization_ed_AppendedFiles( const realization_ed_AppendedFiles & ) throw() // other
	:
		mixin_Lockable( ::jmsf::Proxy< ::jmsf::osie::Mutex >() )
{}

const realization_ed_AppendedFiles &realization_ed_AppendedFiles::operator =( const realization_ed_AppendedFiles &other ) throw() {
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
