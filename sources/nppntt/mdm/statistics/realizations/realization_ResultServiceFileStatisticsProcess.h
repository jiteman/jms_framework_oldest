#pragma once

#include "../ResultServiceFileStatisticsProcess.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "../../externals/data/ed_ServiceFile.hxx"
#include "../../externals/software/es_StorageAppender.hxx"
#include "../../externals/software/es_StatisticsUpdater.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"

#include "realization_factory_StatisticsProcesses.hxx"

namespace nppntt {
namespace mdm {
namespace statistics {
namespace realizations {

class realization_ResultServiceFileStatisticsProcess :
	public ResultServiceFileStatisticsProcess,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals ResultServiceFileStatisticsProcess
	
	//~virtuals

	// virtuals
	void run() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ResultServiceFileStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_StatisticsProcesses;
	realization_ResultServiceFileStatisticsProcess(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &sourceServiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileQueue,
		const ::jmsf::Proxy< externals::software::es_StatisticsUpdater > &statisticsUpdater ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ResultServiceFileStatisticsProcess > createClone() const throw();

private:
	realization_ResultServiceFileStatisticsProcess( const realization_ResultServiceFileStatisticsProcess &other ) throw();
	const realization_ResultServiceFileStatisticsProcess &operator =( const realization_ResultServiceFileStatisticsProcess &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _sourceServiceFileQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _destinationServiceFileQueue;
	::jmsf::Proxy< externals::software::es_StatisticsUpdater > _statisticsUpdater;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
