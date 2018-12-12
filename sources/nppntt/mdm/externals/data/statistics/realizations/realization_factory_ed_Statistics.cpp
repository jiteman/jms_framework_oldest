#include "realization_factory_ed_Statistics.h"

#include "realization_ed_Summary.h"
#include "realization_ed_AppendedFiles.h"
#include "realization_ed_DecipheringFiles.h"
#include "realization_ed_StoredFiles.h"
#include "realization_ed_DeletedFiles.h"

#include "jmsf/osie/factory_OperatingSystem.h"
#include "jmsf/osie/MultithreadingControl.h"
#include "jmsf/osie/Mutex.h"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace realizations {

::jmsf::Proxy< ed_Summary > realization_factory_ed_Statistics::createSummary() const throw() {
	return ::jmsf::Proxy< ed_Summary >::createUnique( new realization_ed_Summary );
}

::jmsf::Proxy< ed_AppendedFiles > realization_factory_ed_Statistics::createAppendedFiles() const throw() {
	return ::jmsf::Proxy< ed_AppendedFiles >::createUnique(
		new realization_ed_AppendedFiles(
			::jmsf::osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createMutex() ) );
}

::jmsf::Proxy< ed_DecipheringFiles > realization_factory_ed_Statistics::createDecipheringFiles() const throw() {
	return ::jmsf::Proxy< ed_DecipheringFiles >::createUnique(
		new realization_ed_DecipheringFiles(
			::jmsf::osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createMutex() ) );
}

::jmsf::Proxy< ed_StoredFiles > realization_factory_ed_Statistics::createStoredFiles() const throw() {
	return ::jmsf::Proxy< ed_StoredFiles >::createUnique(
		new realization_ed_StoredFiles(
			::jmsf::osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createMutex() ) );
}

::jmsf::Proxy< ed_DeletedFiles > realization_factory_ed_Statistics::createDeletedFiles() const throw() {
	return ::jmsf::Proxy< ed_DeletedFiles >::createUnique(
		new realization_ed_DeletedFiles(
			::jmsf::osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createMutex() ) );
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_factory_ed_Statistics::~realization_factory_ed_Statistics() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_ed_Statistics::realization_factory_ed_Statistics() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_ed_Statistics::realization_factory_ed_Statistics( const realization_factory_ed_Statistics & ) throw() // other
{}

const realization_factory_ed_Statistics &realization_factory_ed_Statistics::operator =( const realization_factory_ed_Statistics &other ) throw() {
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
