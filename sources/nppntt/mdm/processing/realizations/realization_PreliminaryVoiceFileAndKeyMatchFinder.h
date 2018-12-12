#pragma once

#include "../PreliminaryVoiceFileAndKeyMatchFinder.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "../../externals/data/ed_FileFilter.hxx"
#include "../../externals/data/ed_VoiceFile.hxx"
#include "../../externals/data/ed_Key.hxx"
#include "../KeyArray.h"
#include "../../externals/software/es_VoiceFileAndKeyPairMatchChecker.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"
#include "jmsf/Pair.hxx"
#include "jmsf/Pointers.hxx"

#include "realization_factory_ProcessingProcesses.hxx"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

class realization_PreliminaryVoiceFileAndKeyMatchFinder :
	public PreliminaryVoiceFileAndKeyMatchFinder,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals PreliminaryVoiceFileAndKeyMatchFinder
	
	//~virtuals

	// virtuals MOVE_Runnable
	void run() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_PreliminaryVoiceFileAndKeyMatchFinder() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ProcessingProcesses;
	realization_PreliminaryVoiceFileAndKeyMatchFinder(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &sourceVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &destinationMatchedVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileWithNoMatchFoundQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileForDeletingQueue,
		const ::jmsf::Proxy< KeyArray > &keyArray,
		const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter,
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > > > &voiceFileAndKeyPairMatchCheckerArray ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< PreliminaryVoiceFileAndKeyMatchFinder > createClone() const throw();

private:
	realization_PreliminaryVoiceFileAndKeyMatchFinder( const realization_PreliminaryVoiceFileAndKeyMatchFinder &other ) throw();
	const realization_PreliminaryVoiceFileAndKeyMatchFinder &operator =( const realization_PreliminaryVoiceFileAndKeyMatchFinder &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _sourceVoiceFileQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > >_destinationMatchedVoiceFileAndKeyPairQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _destinationVoiceFileWithNoMatchFoundQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _destinationVoiceFileForDeletingQueue;
	::jmsf::Proxy< KeyArray > _keyArray;
	const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > _fileFilter;

private:
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > > > _voiceFileAndKeyPairMatchCheckerArray;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const ::jmsf::natural_size AMOUNT_OF_LAST_KEYS_TO_APPLY = 1000;

};


} // namespace
}
}
}
