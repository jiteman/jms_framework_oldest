#include "realization_factory_ExternalData.h"
#include "../../others/abstractFilter.h"
#include "../../others/abstractKey.h"
#include "realization_ed_FileFilter.h"
#include "realization_ed_VoiceFile.h"
#include "realization_ed_ServiceFile.h"
#include "realization_ed_Key.h"

#include "jmsf/osie/factory_OperatingSystem.h"
#include "jmsf/osie/MultithreadingControl.h"
#include "jmsf/osie/Mutex.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace realizations {


::jmsf::Proxy< ed_FileFilter > realization_factory_ExternalData::createFileFilter(
	::jmsf::Pointer< FilterData > fileFilterData ) const throw()
{
	return ::jmsf::Proxy< ed_FileFilter >::createUnique(
		new realization_ed_FileFilter(
			fileFilterData,
			::jmsf::osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createMutex() ) );
}

::jmsf::Proxy< ed_VoiceFile > realization_factory_ExternalData::createVoiceFile(
	::jmsf::Pointer< FileDescriptorData > voiceFileData ) const throw()
{
	return ::jmsf::Proxy< ed_VoiceFile >::createUnique( new realization_ed_VoiceFile( voiceFileData ) );
}

::jmsf::Proxy< ed_ServiceFile > realization_factory_ExternalData::createServiceFile(
	::jmsf::Pointer< FileDescriptorData > serviceFileData ) const throw()
{
	return ::jmsf::Proxy< ed_ServiceFile >::createUnique( new realization_ed_ServiceFile( serviceFileData ) );
}

::jmsf::Proxy< ed_Key > realization_factory_ExternalData::createKey(
	const ::jmsf::natural_size identifier,
	::jmsf::Pointer< KeyData > keyData ) const throw()
{
	return ::jmsf::Proxy< ed_Key >::createUnique(
		new realization_ed_Key(
			identifier,
			keyData ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_factory_ExternalData::~realization_factory_ExternalData() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_ExternalData::realization_factory_ExternalData() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_ExternalData::realization_factory_ExternalData( const realization_factory_ExternalData & ) throw() // other
{}

const realization_factory_ExternalData &realization_factory_ExternalData::operator =( const realization_factory_ExternalData &other ) throw() {
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
