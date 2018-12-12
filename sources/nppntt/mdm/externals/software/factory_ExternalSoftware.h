#pragma once

#include "jmsf/Singleton.hpp"

#include "es_FileAppender.hxx"
#include "es_Decipher.hxx"
#include "es_FileDeleter.hxx"
#include "es_VoiceFileAndKeyPairMatchChecker.hxx"
#include "es_ServiceFileAndKeyPairMatchChecker.hxx"
#include "es_StorageAppender.hxx"
#include "es_StatisticsUpdater.hxx"

#include "jmsf/mtf/Thread.h"
#include "jmsf/osie/Mutex.hxx"
#include "jmsf/TextString.hxx"
#include "jmsf/PointersAndProxies.hxx"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {


class factory_ExternalSoftware :
	public ::jmsf::Singleton< factory_ExternalSoftware >
{

public:
	virtual ::jmsf::Proxy< es_FileAppender > createFileAppender(
		const ::jmsf::ConstantProxy< ::jmsf::TextString > &pathToFolderWithFiles,
		::jmsf::Proxy< ::jmsf::mtf::Thread > thisThread ) const throw() = 0;

	virtual ::jmsf::Proxy< es_Decipher > createDecipher() const throw() = 0;
	virtual ::jmsf::Proxy< es_FileDeleter > createFileDeleter() const throw() = 0;
	virtual ::jmsf::Proxy< es_VoiceFileAndKeyPairMatchChecker > createVoiceFileAndKeyPairMatchChecker( ::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) const throw() = 0;
	virtual ::jmsf::Proxy< es_ServiceFileAndKeyPairMatchChecker > createServiceFileAndKeyPairMatchChecker( ::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) const throw() = 0;
	virtual ::jmsf::Proxy< es_StorageAppender > createStorageAppender() const throw() = 0;
	virtual ::jmsf::Proxy< es_StatisticsUpdater > createStatisticsUpdater( const ::jmsf::ConstantProxy< es_Decipher > &decipher ) const throw() = 0;
		
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_ExternalSoftware() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< factory_ExternalSoftware >;
	static factory_ExternalSoftware *createInstance() throw();

protected:
	factory_ExternalSoftware() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_ExternalSoftware( const factory_ExternalSoftware &other ) throw();
	const factory_ExternalSoftware &operator =( const factory_ExternalSoftware &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
