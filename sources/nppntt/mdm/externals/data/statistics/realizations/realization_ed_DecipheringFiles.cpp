#include "realization_ed_DecipheringFiles.h"
#include "../../../others/abstractStatistics.h"
#include "jmsf/osie/Mutex.h"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace realizations {

::jmsf::Pointer< DecipherStatisticsData > &realization_ed_DecipheringFiles::takeData() throw( ::jmsf::Exception ) {
	::jmsf::Should::alwaysBe( getMutex()->isLocked() );
	return _decipheringFilesData;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ed_DecipheringFiles::~realization_ed_DecipheringFiles() throw() {
	::deleteDecipherStatistics( _decipheringFilesData.get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ed_DecipheringFiles::realization_ed_DecipheringFiles(
	::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) throw()
	:
		mixin_Lockable( mutex ),
		_decipheringFilesData( ::jmsf::Pointer< DecipherStatisticsData >::createWeakFor( ::createDecipherStatistics() ) )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_DecipheringFiles > realization_ed_DecipheringFiles::createClone() const throw() {
	return ::jmsf::Proxy< ed_DecipheringFiles >::createUnique( new realization_ed_DecipheringFiles( *this ) );
}

realization_ed_DecipheringFiles::realization_ed_DecipheringFiles( const realization_ed_DecipheringFiles & ) throw() // other
	:
		mixin_Lockable( ::jmsf::Proxy< ::jmsf::osie::Mutex >::createNone() )
{}

const realization_ed_DecipheringFiles &realization_ed_DecipheringFiles::operator =( const realization_ed_DecipheringFiles &other ) throw() {
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
