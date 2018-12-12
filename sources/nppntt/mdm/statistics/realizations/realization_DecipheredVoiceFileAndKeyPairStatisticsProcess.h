#pragma once

#include "../DecipheredVoiceFileAndKeyPairStatisticsProcess.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "../../externals/data/ed_VoiceFile.hxx"
#include "../../externals/data/ed_Key.hxx"
#include "../../externals/software/es_StatisticsUpdater.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"
#include "jmsf/Pair.hxx"

#include "realization_factory_StatisticsProcesses.hxx"

namespace nppntt {
namespace mdm {
namespace statistics {
namespace realizations {

class realization_DecipheredVoiceFileAndKeyPairStatisticsProcess :
	public DecipheredVoiceFileAndKeyPairStatisticsProcess,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals DecipheredVoiceFileAndKeyPairStatisticsProcess
	
	//~virtuals

	// virtuals MOVE_Runnable
	void run() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_DecipheredVoiceFileAndKeyPairStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_StatisticsProcesses;
	realization_DecipheredVoiceFileAndKeyPairStatisticsProcess(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &sourceVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &destinationVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< externals::software::es_StatisticsUpdater > &statisticsUpdater ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< DecipheredVoiceFileAndKeyPairStatisticsProcess > createClone() const throw();

private:
	realization_DecipheredVoiceFileAndKeyPairStatisticsProcess( const realization_DecipheredVoiceFileAndKeyPairStatisticsProcess &other ) throw();
	const realization_DecipheredVoiceFileAndKeyPairStatisticsProcess &operator =( const realization_DecipheredVoiceFileAndKeyPairStatisticsProcess &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > >_sourceVoiceFileAndKeyPairQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > _destinationVoiceFileAndKeyPairQueue;
	::jmsf::Proxy< externals::software::es_StatisticsUpdater > _statisticsUpdater;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
}
}
