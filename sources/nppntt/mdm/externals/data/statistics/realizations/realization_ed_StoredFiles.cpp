#include "realization_ed_StoredFiles.h"
#include "../../../others/abstractStatistics.h"
#include "jmsf/osie/Mutex.h"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace realizations {

::jmsf::Pointer< DataBaseStatisticsData > &realization_ed_StoredFiles::takeData() throw( ::jmsf::Exception ) {
	::jmsf::Should::alwaysBe( getMutex()->isLocked() );
	return _storedFilesData;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ed_StoredFiles::~realization_ed_StoredFiles() throw() {
	::deleteDataBaseStatistics( _storedFilesData.get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ed_StoredFiles::realization_ed_StoredFiles( ::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) throw()
	:
		mixin_Lockable( mutex ),
		_storedFilesData( ::jmsf::Pointer< DataBaseStatisticsData >::createNonlinkedFor( ::createDataBaseStatistics() ) )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_StoredFiles > realization_ed_StoredFiles::createClone() const throw() {
	return ::jmsf::Proxy< ed_StoredFiles >::createUnique( new realization_ed_StoredFiles( *this ) );
}

realization_ed_StoredFiles::realization_ed_StoredFiles( const realization_ed_StoredFiles & ) throw( ::jmsf::Exception ) // other
	:
		mixin_Lockable( ::jmsf::Proxy< ::jmsf::osie::Mutex >::createEmpty() )
{
	::jmsf::Should::neverViolateCopyingProhibition( "realization_ed_StoredFiles::realization_ed_StoredFiles()" );
}

const realization_ed_StoredFiles &realization_ed_StoredFiles::operator =( const realization_ed_StoredFiles &other ) throw( ::jmsf::Exception ) {
	if ( this == &other ) return *this;

	::jmsf::Should::neverViolateCopyingProhibition( "realization_ed_StoredFiles::operator =()" );
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
