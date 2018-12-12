#include "null_es_StatisticsUpdater.h"
#include "../../data/statistics/ed_Summary.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace nulls {


const ::jmsf::ConstantProxy< data::statistics::ed_Summary > null_es_StatisticsUpdater::updateAndGetOneselfSummary() throw() {
	return _summary;
}

void null_es_StatisticsUpdater::updateAppendedFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
{}

void null_es_StatisticsUpdater::updateAppendedFiles( const ::jmsf::ConstantProxy< data::ed_ServiceFile > & ) throw() // serviceFiles
{}

void null_es_StatisticsUpdater::updateAppendedToDecipherVoiceFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
{}

void null_es_StatisticsUpdater::updateDecipheringVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
{}

void null_es_StatisticsUpdater::updateDecipheredVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
{}

void null_es_StatisticsUpdater::updateNotDecipheredVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
{}

void null_es_StatisticsUpdater::updateResultVoiceFileAndServiceFilePair(
	const ::jmsf::ConstantPointer< ::jmsf::Pair< ::jmsf::ConstantProxy, data::ed_VoiceFile, data::ed_ServiceFile > > & ) throw() // voiceFileAndServiceFilePair
{}

void null_es_StatisticsUpdater::updateResultVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
{}

void null_es_StatisticsUpdater::updateResultServiceFile( const ::jmsf::ConstantProxy< data::ed_ServiceFile > & ) throw() // serviceFile
{}

void null_es_StatisticsUpdater::updateDeletedFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
{}

void null_es_StatisticsUpdater::updateDeletedFiles( const ::jmsf::ConstantProxy< data::ed_ServiceFile > & ) throw() // serviceFile
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_es_StatisticsUpdater::~null_es_StatisticsUpdater() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_es_StatisticsUpdater *null_es_StatisticsUpdater::createInstance() throw() {
	return new null_es_StatisticsUpdater;
}

null_es_StatisticsUpdater::null_es_StatisticsUpdater() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< es_StatisticsUpdater > null_es_StatisticsUpdater::createClone() const throw() {
	return ::jmsf::Proxy< es_StatisticsUpdater >::createUnique( this );
}

null_es_StatisticsUpdater::null_es_StatisticsUpdater( const null_es_StatisticsUpdater & ) throw() // other
{}

const null_es_StatisticsUpdater &null_es_StatisticsUpdater::operator =( const null_es_StatisticsUpdater &other ) throw() {
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
