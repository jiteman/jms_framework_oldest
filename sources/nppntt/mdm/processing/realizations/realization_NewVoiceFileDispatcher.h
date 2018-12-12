#pragma once

#include "../NewVoiceFileDispatcher.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/PointersAndProxies.hpp"

#include "../../externals/data/ed_VoiceFile.hxx"
#include "../../externals/data/ed_FileFilter.hxx"
#include "jmsf/debugging/Log.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"

#include "realization_factory_ProcessingProcesses.hxx"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

class realization_NewVoiceFileDispatcher :
	public NewVoiceFileDispatcher,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals Runnable
	void run() throw( ::jmsf::Exception );
	//~virtuals

	// virtuals NewVoiceFileDispatcher	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_NewVoiceFileDispatcher() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ProcessingProcesses;
	realization_NewVoiceFileDispatcher(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &sourceVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileForDecipheringQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &realVoiceFileForDecipheringQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileForPreliminarySearchForAMatchWithKeyQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileForDeletingQueue,
		const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< NewVoiceFileDispatcher > createClone() const throw();

private:
	realization_NewVoiceFileDispatcher( const realization_NewVoiceFileDispatcher &other ) throw();
	const realization_NewVoiceFileDispatcher &operator =( const realization_NewVoiceFileDispatcher &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _sourceVoiceFileQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _destinationVoiceFileForDecipheringQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _realVoiceFileForDecipheringQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _destinationVoiceFileForPreliminarySearchForAMatchWithKeyQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _destinationVoiceFileForDeletingQueue;
	
	const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > _fileFilter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const ::jmsf::natural_size DECIPHER_QUEUE_THRESHOLD = 10;

private: // debugging
	::jmsf::Proxy< ::jmsf::debugging::Log > _logFile;
	
};


} // namespace
}
}
}
