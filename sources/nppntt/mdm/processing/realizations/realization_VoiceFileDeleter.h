#pragma once

#include "../VoiceFileDeleter.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "../../externals/software/es_FileDeleter.hxx"
#include "../../externals/data/ed_VoiceFile.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"

#include "realization_factory_ProcessingProcesses.hxx"


namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

class realization_VoiceFileDeleter :
	public VoiceFileDeleter,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals VoiceFileDeleter
	
	//~virtuals

	// virtuals MOVE_Runnable
	void run() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_VoiceFileDeleter() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ProcessingProcesses;
	realization_VoiceFileDeleter(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &sourceVoiceFileQueue,
		const ::jmsf::Proxy< externals::software::es_FileDeleter > &fileDeleter ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< VoiceFileDeleter > createClone() const throw();

private:
	realization_VoiceFileDeleter( const realization_VoiceFileDeleter &other ) throw();
	const realization_VoiceFileDeleter &operator =( const realization_VoiceFileDeleter &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _sourceVoiceFileQueue;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	::jmsf::Proxy< externals::software::es_FileDeleter > _fileDeleter;

};


} // namespace
}
}
}
