#include "realization_factory_ExternalSoftware.h"
#include "../../data/statistics/factory_ed_Statistics.h"
#include "../../data/statistics/ed_Summary.h"
#include "../../data/statistics/ed_AppendedFiles.h"
#include "../../data/statistics/ed_DecipheringFiles.h"
#include "../../data/statistics/ed_StoredFiles.h"
#include "../../data/statistics/ed_DeletedFiles.h"
#include "../../others/abstractApplyKey.h"
#include "../../others/abstractDataBase.h"
#include "realization_es_FileAppender.h"
#include "realization_es_Decipher.h"
#include "realization_es_FileDeleter.h"
#include "realization_es_VoiceFileAndKeyPairMatchChecker.h"
#include "realization_es_ServiceFileAndKeyPairMatchChecker.h"
#include "realization_es_StorageAppender.h"
#include "realization_es_StatisticsUpdater.h"

#include "jmsf/mtf/factory_GenericMultithreading.hpp"
#include "jmsf/osie/Event.h"
#include "jmsf/Pair.hpp"
#include "jmsf/TextString.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace realizations {


::jmsf::Proxy< es_FileAppender > realization_factory_ExternalSoftware::createFileAppender(
	const ::jmsf::ConstantProxy< ::jmsf::TextString > &pathToFolderWithFiles,
	::jmsf::Proxy< ::jmsf::mtf::Thread > thisThread ) const throw()
{
	return ::jmsf::Proxy< es_FileAppender >::createUnique(
		new realization_es_FileAppender(
			pathToFolderWithFiles,
			::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Pointer< FileDescriptorData > >::instance()->createSynchronizedQueue(),
			::jmsf::mtf::factory_GenericMultithreading< ::jmsf::Pointer< FileDescriptorData > >::instance()->createSynchronizedQueue(),
			thisThread ) );
}

::jmsf::Proxy< es_Decipher > realization_factory_ExternalSoftware::createDecipher() const throw() {
	return ::jmsf::Proxy< es_Decipher >::createUnique(
		new realization_es_Decipher );
}

::jmsf::Proxy< es_FileDeleter > realization_factory_ExternalSoftware::createFileDeleter() const throw() {
	return ::jmsf::Proxy< es_FileDeleter >::createUnique(
		new realization_es_FileDeleter );
}

::jmsf::Proxy< es_VoiceFileAndKeyPairMatchChecker > realization_factory_ExternalSoftware::createVoiceFileAndKeyPairMatchChecker(
	::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) const throw()
{
	return ::jmsf::Proxy< es_VoiceFileAndKeyPairMatchChecker >::createUnique(
		new realization_es_VoiceFileAndKeyPairMatchChecker(
			mutex ) );
}

::jmsf::Proxy< es_ServiceFileAndKeyPairMatchChecker > realization_factory_ExternalSoftware::createServiceFileAndKeyPairMatchChecker(
	::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) const throw()
{
	return ::jmsf::Proxy< es_ServiceFileAndKeyPairMatchChecker >::createUnique(
		new realization_es_ServiceFileAndKeyPairMatchChecker(
			mutex ) );
}

::jmsf::Proxy< es_StorageAppender > realization_factory_ExternalSoftware::createStorageAppender() const throw() {
	return ::jmsf::Proxy< es_StorageAppender >::createUnique(
		new realization_es_StorageAppender );
}

::jmsf::Proxy< es_StatisticsUpdater > realization_factory_ExternalSoftware::createStatisticsUpdater( const ::jmsf::ConstantProxy< es_Decipher > &decipher ) const throw() {
	return ::jmsf::Proxy< es_StatisticsUpdater >::createUnique(
		new realization_es_StatisticsUpdater(
			externals::data::statistics::factory_ed_Statistics::instance()->createSummary(),
			externals::data::statistics::factory_ed_Statistics::instance()->createAppendedFiles(),
			externals::data::statistics::factory_ed_Statistics::instance()->createDecipheringFiles(),
			externals::data::statistics::factory_ed_Statistics::instance()->createStoredFiles(),
			externals::data::statistics::factory_ed_Statistics::instance()->createDeletedFiles(),
			decipher ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_factory_ExternalSoftware::~realization_factory_ExternalSoftware() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_ExternalSoftware::realization_factory_ExternalSoftware() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_ExternalSoftware::realization_factory_ExternalSoftware( const realization_factory_ExternalSoftware & ) throw() // other
{}

const realization_factory_ExternalSoftware &realization_factory_ExternalSoftware::operator =( const realization_factory_ExternalSoftware &other ) throw() {
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
