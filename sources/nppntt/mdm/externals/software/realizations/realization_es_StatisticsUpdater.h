#pragma once

#include "../es_StatisticsUpdater.h"
#include "jmsf/mixins/mixin_Object.h"

#include "../../data/statistics/ed_AppendedFiles.hxx"
#include "../../data/statistics/ed_DecipheringFiles.hxx"
#include "../../data/statistics/ed_StoredFiles.hxx"
#include "../../data/statistics/ed_DeletedFiles.hxx"
#include "../es_Decipher.hxx"
#include "jmsf/Proxies.hpp"

#include "realization_factory_ExternalSoftware.hxx"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace realizations {


class realization_es_StatisticsUpdater :
	public es_StatisticsUpdater,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals es_StatisticsUpdater
	const ::jmsf::ConstantProxy< data::statistics::ed_Summary > &updateAndGetSummary() throw();
	void updateAppendedFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw();
	void updateAppendedFiles( const ::jmsf::ConstantProxy< data::ed_ServiceFile > &serviceFile ) throw();
	void updateAppendedToDecipherVoiceFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw();
	void updateDecipheringVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw();
	void updateDecipheredVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw();
	void updateNotDecipheredVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw();

	void updateResultVoiceFileAndServiceFilePair(
		const ::jmsf::ConstantProxy< ::jmsf::Pair< ::jmsf::ConstantProxy< data::ed_VoiceFile >, ::jmsf::ConstantProxy< data::ed_ServiceFile > > > &voiceFileAndServiceFilePair ) throw();

	void updateResultVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw();
	void updateResultServiceFile( const ::jmsf::ConstantProxy< data::ed_ServiceFile > &serviceFile ) throw();
	void updateDeletedFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw();
	void updateDeletedFiles( const ::jmsf::ConstantProxy< data::ed_ServiceFile > &serviceFile ) throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_es_StatisticsUpdater() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ExternalSoftware;
	realization_es_StatisticsUpdater(
		::jmsf::Proxy< data::statistics::ed_Summary > summary,
		::jmsf::Proxy< data::statistics::ed_AppendedFiles > appendingFiles,
		::jmsf::Proxy< data::statistics::ed_DecipheringFiles > decipheringFiles,
		::jmsf::Proxy< data::statistics::ed_StoredFiles > storageFiles,
		::jmsf::Proxy< data::statistics::ed_DeletedFiles > deletedFiles,
		const ::jmsf::ConstantProxy< es_Decipher > &decipher ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_StatisticsUpdater > createClone() const throw();

private:
	realization_es_StatisticsUpdater( const realization_es_StatisticsUpdater &other ) throw();
	const realization_es_StatisticsUpdater &operator =( const realization_es_StatisticsUpdater &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< data::statistics::ed_Summary > _summary;
	::jmsf::ConstantProxy< data::statistics::ed_Summary > _constantSummary;
	::jmsf::Proxy< data::statistics::ed_AppendedFiles > _appendingFiles;
	::jmsf::Proxy< data::statistics::ed_DecipheringFiles > _decipheringFiles;
	::jmsf::Proxy< data::statistics::ed_StoredFiles > _storageFiles;
	::jmsf::Proxy< data::statistics::ed_DeletedFiles > _deletedFiles;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	const ::jmsf::ConstantProxy< es_Decipher > _decipher;

};


} // namespace
}
}
}
}
