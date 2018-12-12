#pragma once

#include "../VoiceFileDecipher.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "../../externals/software/es_Decipher.hxx"
#include "../../externals/data/ed_FileFilter.hxx"
#include "../../externals/data/ed_VoiceFile.hxx"
#include "../../externals/data/ed_Key.hxx"
#include "../../processing/KeyArray.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"
#include "jmsf/Pair.hxx"
#include "jmsf/Pointers.hxx"

#include "realization_factory_ProcessingProcesses.hxx"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

class realization_VoiceFileDecipher :
	public VoiceFileDecipher,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals VoiceFileDecipher
	
	//~virtuals

	// virtuals MOVE_Runnable
	void run() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_VoiceFileDecipher() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ProcessingProcesses;
	realization_VoiceFileDecipher(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &sourceVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &destinationDecipheredVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::ConstantProxy< externals::data::ed_Key > > > &destinationKeyQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationNotDecipheredVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileForDeletingQueue,
		const ::jmsf::Proxy< processing::KeyArray > &keyArray,
		const ::jmsf::Proxy< externals::software::es_Decipher > &decipher,
		const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< VoiceFileDecipher > createClone() const throw();

private:
	realization_VoiceFileDecipher( const realization_VoiceFileDecipher &other ) throw();
	const realization_VoiceFileDecipher &operator =( const realization_VoiceFileDecipher &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _sourceVoiceFileQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile>, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > _destinationDecipheredVoiceFileAndKeyPairQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::ConstantProxy< externals::data::ed_Key > > > _destinationKeyQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _destinationNotDecipheredVoiceFileAndKeyPairQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _destinationVoiceFileForDeletingQueue;

	::jmsf::Proxy< processing::KeyArray > _keyArray;
	::jmsf::Proxy< externals::software::es_Decipher > _decipher;
	const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > _fileFilter;
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
