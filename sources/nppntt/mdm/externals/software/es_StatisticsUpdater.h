#pragma once

#include "jmsf/Object.h"

#include "../data/statistics/ed_Summary.hxx"
#include "../data/ed_VoiceFile.hxx"
#include "../data/ed_ServiceFile.hxx"
#include "jmsf/Pair.hxx"
#include "jmsf/Proxies.hxx"
#include "jmsf/Pointers.hxx"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {


class es_StatisticsUpdater :
	public virtual ::jmsf::Object
{

public:
	virtual const ::jmsf::ConstantProxy< data::statistics::ed_Summary > &updateAndGetSummary() throw() = 0;
	virtual void updateAppendedFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw() = 0;
	virtual void updateAppendedFiles( const ::jmsf::ConstantProxy< data::ed_ServiceFile > &serviceFile ) throw() = 0;
	virtual void updateAppendedToDecipherVoiceFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw() = 0;
	virtual void updateDecipheringVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw() = 0;
	virtual void updateDecipheredVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw() = 0;
	virtual void updateNotDecipheredVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw() = 0;

	virtual void updateResultVoiceFileAndServiceFilePair(
		const ::jmsf::ConstantProxy< ::jmsf::Pair< ::jmsf::ConstantProxy< data::ed_VoiceFile >, ::jmsf::ConstantProxy< data::ed_ServiceFile > > > &voiceFileAndServiceFilePair ) throw() = 0;

	virtual void updateResultVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw() = 0;
	virtual void updateResultServiceFile( const ::jmsf::ConstantProxy< data::ed_ServiceFile > &serviceFile ) throw() = 0;
	virtual void updateDeletedFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw() = 0;
	virtual void updateDeletedFiles( const ::jmsf::ConstantProxy< data::ed_ServiceFile > &serviceFile ) throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static es_StatisticsUpdater *getNull() throw();
	static es_StatisticsUpdater *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< es_StatisticsUpdater > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
