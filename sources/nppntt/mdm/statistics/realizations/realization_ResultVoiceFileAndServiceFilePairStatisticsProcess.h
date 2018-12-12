#pragma once

#include "../ResultVoiceFileAndServiceFilePairStatisticsProcess.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "../../externals/data/ed_VoiceFile.hxx"
#include "../../externals/data/ed_ServiceFile.hxx"
#include "../../externals/software/es_StatisticsUpdater.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"
#include "jmsf/Pair.hxx"

#include "realization_factory_StatisticsProcesses.hxx"

namespace nppntt {
namespace mdm {
namespace statistics {
namespace realizations {

class realization_ResultVoiceFileAndServiceFilePairStatisticsProcess :
	public ResultVoiceFileAndServiceFilePairStatisticsProcess,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals ResultVoiceFileAndServiceFilePairStatisticsProcess
	
	//~virtuals

	// virtuals MOVE_Runnable
	void run() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ResultVoiceFileAndServiceFilePairStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_StatisticsProcesses;
	realization_ResultVoiceFileAndServiceFilePairStatisticsProcess(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > &sourceVoiceFileAndServiceFilePairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > &destinationVoiceFileAndServiceFilePairQueue,
		const ::jmsf::Proxy< externals::software::es_StatisticsUpdater > &statisticsUpdater ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ResultVoiceFileAndServiceFilePairStatisticsProcess > createClone() const throw();

private:
	realization_ResultVoiceFileAndServiceFilePairStatisticsProcess( const realization_ResultVoiceFileAndServiceFilePairStatisticsProcess &other ) throw();
	const realization_ResultVoiceFileAndServiceFilePairStatisticsProcess &operator =( const realization_ResultVoiceFileAndServiceFilePairStatisticsProcess &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > _sourceVoiceFileAndServiceFilePairQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > _destinationVoiceFileAndServiceFilePairQueue;
	::jmsf::Proxy< externals::software::es_StatisticsUpdater > _statisticsUpdater;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
