#include "realization_ed_DeletedFiles.h"
#include "../../../others/abstractStatistics.h"
#include "jmsf/osie/Mutex.h"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace realizations {

::jmsf::Pointer< DeleteFilesStatisticsData > &realization_ed_DeletedFiles::takeData() throw( ::jmsf::Exception ) {
	::jmsf::Should::alwaysBe( getMutex()->isLocked() );
	return _deletedFilesData;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ed_DeletedFiles::~realization_ed_DeletedFiles() throw() {
	::deleteDeleteFilesStatistics( _deletedFilesData.get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ed_DeletedFiles::realization_ed_DeletedFiles(
	::jmsf::Proxy< ::jmsf::osie::Mutex > mutex  ) throw()
	:
		mixin_Lockable( mutex ),
		_deletedFilesData( ::jmsf::Pointer< DeleteFilesStatisticsData >::createWeakFor( ::createDeleteFilesStatistics() ) )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_DeletedFiles > realization_ed_DeletedFiles::createClone() const throw() {
	return ::jmsf::Proxy< ed_DeletedFiles >::createUnique( new realization_ed_DeletedFiles( *this ) );
}

realization_ed_DeletedFiles::realization_ed_DeletedFiles( const realization_ed_DeletedFiles & ) throw( ::jmsf::Exception ) // other
	:
		mixin_Lockable( ::jmsf::Proxy< ::jmsf::osie::Mutex >::createNone() )
{
	::jmsf::Should::neverViolateCopyingProhibition( "realization_ed_DeletedFiles::realiazation_ed_DeletedFiles()" );
}

const realization_ed_DeletedFiles &realization_ed_DeletedFiles::operator =( const realization_ed_DeletedFiles &other ) throw( ::jmsf::Exception ) {
	if ( this == &other ) return *this;

	::jmsf::Should::neverViolateCopyingProhibition( "realization_ed_DeletedFiles::opreator =()" );
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
