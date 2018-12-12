#pragma once

#include "../factory_ExternalSoftware.h"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace realizations {


class realization_factory_ExternalSoftware :
	public factory_ExternalSoftware
{

public:
	// virtuals factory_ExternalSoftware
	::jmsf::Proxy< es_FileAppender > createFileAppender(
		const ::jmsf::ConstantProxy< ::jmsf::TextString > &pathToFolderWithFiles,
		::jmsf::Proxy< ::jmsf::mtf::Thread > thisThread ) const throw();

	::jmsf::Proxy< es_Decipher > createDecipher() const throw();
	::jmsf::Proxy< es_FileDeleter > createFileDeleter() const throw();
	::jmsf::Proxy< es_VoiceFileAndKeyPairMatchChecker > createVoiceFileAndKeyPairMatchChecker( ::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) const throw();
	::jmsf::Proxy< es_ServiceFileAndKeyPairMatchChecker > createServiceFileAndKeyPairMatchChecker( ::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) const throw();
	::jmsf::Proxy< es_StorageAppender > createStorageAppender() const throw();
	::jmsf::Proxy< es_StatisticsUpdater > createStatisticsUpdater( const ::jmsf::ConstantProxy< es_Decipher > &decipher ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_ExternalSoftware() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class factory_ExternalSoftware;
	realization_factory_ExternalSoftware() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_ExternalSoftware( const realization_factory_ExternalSoftware &other ) throw();
	const realization_factory_ExternalSoftware &operator =( const realization_factory_ExternalSoftware &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
