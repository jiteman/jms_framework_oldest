#include "realization_es_StorageAppender.h"
#include "../../../exceptions/exception_DllNotFound.h"
#include "../../../exceptions/exception_CantConnectToDataBase.h"
#include "../../others/abstractDataBase.h"
#include "../../others/abstractKcDll.h"
#include "../../data/ed_VoiceFile.h"
#include "../../data/ed_ServiceFile.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/Pair.hpp"
#include "jmsf/PointersAndProxies.hpp"

namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace realizations {

void realization_es_StorageAppender::store( const ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::ConstantProxy< data::ed_VoiceFile >, ::jmsf::Proxy< data::ed_ServiceFile > > > &voiceFileAndServiceFilePair ) throw() {
	::jmsf::Proxy< ::jmsf::Pair< ::jmsf::ConstantProxy< data::ed_VoiceFile >, ::jmsf::Proxy< data::ed_ServiceFile > > > internalVoiceFileAndServiceFilePair = voiceFileAndServiceFilePair;

	::sendFilesToDataBase(
		internalVoiceFileAndServiceFilePair->getFirst()->getData().get(),
		internalVoiceFileAndServiceFilePair->takeSecond()->takeData().get(),
		internalVoiceFileAndServiceFilePair->getFirst()->getAppliedData().get(),
		internalVoiceFileAndServiceFilePair->getSecond()->getAppliedData().get() );
}

void realization_es_StorageAppender::store( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw() {
	::sendFilesToDataBase(
		voiceFile->getData().get(),
		nullptr,
		voiceFile->getAppliedData().get(),
		nullptr );
}

void realization_es_StorageAppender::store( const ::jmsf::Proxy< data::ed_ServiceFile > &serviceFile ) throw() {
	::jmsf::Proxy< data::ed_ServiceFile > internalServiceFile = serviceFile;

	::sendFilesToDataBase(
		nullptr,
		internalServiceFile->takeData().get(),
		nullptr,
		internalServiceFile->getAppliedData().get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_es_StorageAppender::~realization_es_StorageAppender() throw() {
	::disconnectFromDataBase();
	::releaseDataBase();
//	::unloadDataBaseDll();
	::unloadApplyKcDll();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_es_StorageAppender::realization_es_StorageAppender() throw( ::jmsf::Exception ) {
	if ( ::jmsf::Boolean( /*::loadDataBaseDll()*/::loadApplyKcDll() ).not() ) {
		throw exceptions::exception_DllNotFound( ::jmsf::CONSTANT_TEXT_STRING( "Database dll was not found" ) );
	}

	initializeDataBase( "c:\\MDM_data_base_temp\\" );

	if ( ::jmsf::Boolean( ::connectToDataBase( "127.0.0.1", "c:\\MDM_data_base\\1.ibs", "SYSDBA", "masterkey" ) ).not() ) {
		throw exceptions::exception_CantConnectToDataBase( ::jmsf::CONSTANT_TEXT_STRING( "Can't connect to database" ) );
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< es_StorageAppender > realization_es_StorageAppender::createClone() const throw() {
	return ::jmsf::Proxy< es_StorageAppender >::createUnique( new realization_es_StorageAppender( *this ) );
}

realization_es_StorageAppender::realization_es_StorageAppender( const realization_es_StorageAppender & ) throw() // other
{}

const realization_es_StorageAppender &realization_es_StorageAppender::operator =( const realization_es_StorageAppender &other ) throw() {
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
