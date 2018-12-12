#pragma once

#include "../ServiceFileAndKeyMatchFinder.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "../../externals/software/es_ServiceFileAndKeyPairMatchChecker.hxx"
#include "../../externals/data/ed_FileFilter.hxx"
#include "../../externals/data/ed_VoiceFile.hxx"
#include "../../externals/data/ed_ServiceFile.hxx"
#include "../../externals/data/ed_Key.hxx"
#include "../ServiceFileArray.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"
#include "jmsf/Pair.hxx"
#include "jmsf/Pointers.hxx"

#include "jmsf/debugging/Log.hxx"

#include "realization_factory_ProcessingProcesses.hxx"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

class realization_ServiceFileAndKeyMatchFinder :
	public ServiceFileAndKeyMatchFinder,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals ServiceFileAndKeyMatchFinder
	
	//~virtuals

	// virtuals MOVE_Runnable
	void run() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ServiceFileAndKeyMatchFinder() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ProcessingProcesses;
	realization_ServiceFileAndKeyMatchFinder(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &sourceVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > &destinationVoiceFileAndServiceFilePairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileForDeletingQueue,
		const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter,
		const ::jmsf::Proxy< ServiceFileArray > &serviceFileArray,
		const ::jmsf::Proxy< externals::software::es_ServiceFileAndKeyPairMatchChecker > &serviceFileAndKeyPairMatchChecker ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ServiceFileAndKeyMatchFinder > createClone() const throw();

private:
	realization_ServiceFileAndKeyMatchFinder( const realization_ServiceFileAndKeyMatchFinder &other ) throw();
	const realization_ServiceFileAndKeyMatchFinder &operator =( const realization_ServiceFileAndKeyMatchFinder &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > _sourceVoiceFileAndKeyPairQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > _destinationVoiceFileAndServiceFilePairQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _destinationVoiceFileQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _destinationServiceFileQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _destinationServiceFileForDeletingQueue;
	const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > _fileFilter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	::jmsf::Proxy< ServiceFileArray > _serviceFileArray;
	::jmsf::Proxy< externals::software::es_ServiceFileAndKeyPairMatchChecker > _serviceFileAndKeyPairMatchChecker;

private:
	::jmsf::Proxy< ::jmsf::debugging::Log > _logFile;
};

} // namespace
}
}
}
