#pragma once

#include "../es_StatisticsUpdater.h"
#include "jmsf/mixin_nulls/mixin_null_Object.h"
#include "jmsf/Singleton.hpp"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace nulls {


class null_es_StatisticsUpdater :
	public es_StatisticsUpdater,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_es_StatisticsUpdater >
{

public:
	// virtuals es_StatisticsUpdater
	const ::jmsf::ConstantProxy< data::statistics::ed_Summary > updateAndGetOneselfSummary() throw();
	void updateAppendedFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw();
	void updateAppendedFiles( const ::jmsf::ConstantProxy< data::ed_ServiceFile > &serviceFile ) throw();
	void updateAppendedToDecipherVoiceFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw();
	void updateDecipheringVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw();
	void updateDecipheredVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw();
	void updateNotDecipheredVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw();
	void updateResultVoiceFileAndServiceFilePair( const ::jmsf::ConstantPointer< ::jmsf::Pair< ::jmsf::ConstantProxy, data::ed_VoiceFile, data::ed_ServiceFile > > &voiceFileAndServiceFilePair ) throw();
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
	~null_es_StatisticsUpdater() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_es_StatisticsUpdater >;
	static null_es_StatisticsUpdater *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_es_StatisticsUpdater() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_StatisticsUpdater > createClone() const throw();

private:
	null_es_StatisticsUpdater( const null_es_StatisticsUpdater &other ) throw();
	const null_es_StatisticsUpdater &operator =( const null_es_StatisticsUpdater &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< data::statistics::ed_Summary > _summary;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
