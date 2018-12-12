#pragma once

#include "../VoiceFileForDecipheringStatisticsProcess.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "../../externals/data/ed_VoiceFile.hxx"
#include "../../externals/software/es_StatisticsUpdater.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"

#include "realization_factory_StatisticsProcesses.hxx"

namespace nppntt {
namespace mdm {
namespace statistics {
namespace realizations {

class realization_VoiceFileForDecipheringStatisticsProcess :
	public VoiceFileForDecipheringStatisticsProcess,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals VoiceFileForDecipheringStatisticsProcess
	
	//~virtuals

	// virtual MOVE_Runnable
	void run() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_VoiceFileForDecipheringStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_StatisticsProcesses;
	realization_VoiceFileForDecipheringStatisticsProcess(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &sourceVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileQueue,
		const ::jmsf::Proxy< externals::software::es_StatisticsUpdater > &statisticsUpdater ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< VoiceFileForDecipheringStatisticsProcess > createClone() const throw();

private:
	realization_VoiceFileForDecipheringStatisticsProcess( const realization_VoiceFileForDecipheringStatisticsProcess &other ) throw();
	const realization_VoiceFileForDecipheringStatisticsProcess &operator =( const realization_VoiceFileForDecipheringStatisticsProcess &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _sourceVoiceFileQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _destinationVoiceFileQueue;
	::jmsf::Proxy< externals::software::es_StatisticsUpdater > _statisticsUpdater;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
}
}
