#include "ProcessingQueues.h"
#include "externals/data/ed_VoiceFile.h"
#include "externals/data/ed_ServiceFile.h"
#include "externals/data/ed_Key.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Pair.hpp"
#include "jmsf/PointersAndProxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {

class null_ProcessingQueues :
	public ProcessingQueues,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ProcessingQueues >
{

public:
	// virtuals ProcessingQueues
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeNewVoiceFileQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeVoiceFileForDecipheringQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeVoiceFileForPreliminarySearchForAMatchWithKeyQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeVoiceFileForRecurrentSearchForAMatchWithKeyQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &takeNewVoiceFileAndKeyPairForImmediateMatchVerificationQueue() throw() {
		return _voiceFileAndKeyPairQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &takeMatchedVoiceFileAndKeyPairQueue() throw() {
		return _voiceFileAndKeyPairQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeNewServiceFileQueue() throw() {
		return _serviceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::ConstantProxy< externals::data::ed_Key > > > &takeNewKeyQueue() throw() {
		return _keyQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > &takeDecipheredVoiceFileAndServiceFilePairForAppendingToStorageQueue() throw() {
		return _voiceFileAndServiceFilePairQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeDecipheredVoiceFileForAppendingToStorageQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeDecipheredServiceFileForAppendingToStorageQueue() throw() {
		return _serviceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeVoiceFileForDeletingQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeServiceFileForLastChanceMatchFindQueue() throw() {
		return _serviceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeServiceFileForDeletingQueue() throw() {
		return _serviceFileQueueRtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ProcessingQueues() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ProcessingQueues >;
	static null_ProcessingQueues *createInstance() throw() {
		return new null_ProcessingQueues;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ProcessingQueues() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ProcessingQueues > createClone() const throw() {
		return ::jmsf::Proxy< ProcessingQueues >::createUnique( this );
	}

private:
	null_ProcessingQueues( const null_ProcessingQueues & ) throw() {} // other
	
	const null_ProcessingQueues &operator =( const null_ProcessingQueues &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ProcessingQueues::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _voiceFileQueueRtr;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _serviceFileQueueRtr;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::ConstantProxy< externals::data::ed_Key > > > _keyQueueRtr;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > _voiceFileAndKeyPairQueueRtr;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > _voiceFileAndServiceFilePairQueueRtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_ProcessingQueues :
	public ProcessingQueues,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ProcessingQueues > {

public:
	// virtuals ProcessingQueues
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeNewVoiceFileQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeVoiceFileForDecipheringQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeVoiceFileForPreliminarySearchForAMatchWithKeyQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeVoiceFileForRecurrentSearchForAMatchWithKeyQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &takeNewVoiceFileAndKeyPairForImmediateMatchVerificationQueue() throw() {
		return _voiceFileAndKeyPairQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &takeMatchedVoiceFileAndKeyPairQueue() throw() {
		return _voiceFileAndKeyPairQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeNewServiceFileQueue() throw() {
		return _serviceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::ConstantProxy< externals::data::ed_Key > > > &takeNewKeyQueue() throw() {
		return _keyQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > &takeDecipheredVoiceFileAndServiceFilePairForAppendingToStorageQueue() throw() {
		return _voiceFileAndServiceFilePairQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeDecipheredVoiceFileForAppendingToStorageQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeDecipheredServiceFileForAppendingToStorageQueue() throw() {
		return _serviceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeVoiceFileForDeletingQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeServiceFileForLastChanceMatchFindQueue() throw() {
		return _serviceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeServiceFileForDeletingQueue() throw() {
		return _serviceFileQueueRtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ProcessingQueues() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ProcessingQueues >;
	static exception_ProcessingQueues *createInstance() throw() {
		return new exception_ProcessingQueues;
	}

private:
	exception_ProcessingQueues() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ProcessingQueues > createClone() const throw() {
		return ::jmsf::Proxy< ProcessingQueues >::createUnique( this );
	}

private:
	exception_ProcessingQueues( const exception_ProcessingQueues & ) throw() {} // other

	const exception_ProcessingQueues &operator =( const exception_ProcessingQueues &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ProcessingQueues::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _voiceFileQueueRtr;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _serviceFileQueueRtr;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::ConstantProxy< externals::data::ed_Key > > > _keyQueueRtr;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > _voiceFileAndKeyPairQueueRtr;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > _voiceFileAndServiceFilePairQueueRtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
ProcessingQueues *ProcessingQueues::getNull() throw() {
	return null_ProcessingQueues::instance();
}

// static
ProcessingQueues *ProcessingQueues::getException() throw() {
	return exception_ProcessingQueues::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace mdm
} // namespace nppntt
