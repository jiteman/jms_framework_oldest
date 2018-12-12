#include "StatisticsQueues.h"
#include "externals/data/ed_VoiceFile.h"
#include "externals/data/ed_ServiceFile.h"
#include "externals/data/ed_Key.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Pair.hpp"
#include "jmsf/Singleton.hpp"
#include "jmsf/PointersAndProxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {

class null_StatisticsQueues :
	public StatisticsQueues,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_StatisticsQueues >
{

public:
	// virtuals StatisticsQueues
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeNewVoiceFileStatisticsQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeNewServiceFileStatisticsQueue() throw() {
		return _serviceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeVoiceFileForDecipheringStatisticsQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &takeDecipheredVoiceFileAndKeyPairStatisticsQueue() throw() {
		return _voiceFileAndKeyPairQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeNotDecipheredVoiceFileStatisticsQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > &takeResultVoiceFileAndServiceFilePairStatisticsQueue() throw() {
		return _voiceFielAndServiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeResultVoiceFileStatisticsQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeResultServiceFileStatisticsQueue() throw() {
		return _serviceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeDeletedVoiceFileStatisticsQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeDeletedServiceFileStatisticsQueue() throw() {
		return _serviceFileQueueRtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_StatisticsQueues() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_StatisticsQueues >;
	static null_StatisticsQueues *createInstance() throw() {
		return new null_StatisticsQueues;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_StatisticsQueues() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< StatisticsQueues > createClone() const throw() {
		return ::jmsf::Proxy< StatisticsQueues >::createUnique( this );
	}

private:
	null_StatisticsQueues( const null_StatisticsQueues & ) throw() {} // other
	
	const null_StatisticsQueues &operator =( const null_StatisticsQueues &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_StatisticsQueues::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _voiceFileQueueRtr;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _serviceFileQueueRtr;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > _voiceFileAndKeyPairQueueRtr;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > _voiceFielAndServiceFileQueueRtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_StatisticsQueues :
	public StatisticsQueues,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_StatisticsQueues > {

public:
	// virtuals StatisticsQueues
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeNewVoiceFileStatisticsQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeNewServiceFileStatisticsQueue() throw() {
		return _serviceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeVoiceFileForDecipheringStatisticsQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &takeDecipheredVoiceFileAndKeyPairStatisticsQueue() throw() {
		return _voiceFileAndKeyPairQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeNotDecipheredVoiceFileStatisticsQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > &takeResultVoiceFileAndServiceFilePairStatisticsQueue() throw() {
		return _voiceFielAndServiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeResultVoiceFileStatisticsQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeResultServiceFileStatisticsQueue() throw() {
		return _serviceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &takeDeletedVoiceFileStatisticsQueue() throw() {
		return _voiceFileQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeDeletedServiceFileStatisticsQueue() throw() {
		return _serviceFileQueueRtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_StatisticsQueues() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_StatisticsQueues >;
	static exception_StatisticsQueues *createInstance() throw() {
		return new exception_StatisticsQueues;
	}

private:
	exception_StatisticsQueues() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< StatisticsQueues > createClone() const throw() {
		return ::jmsf::Proxy< StatisticsQueues >::createUnique( this );
	}

private:
	exception_StatisticsQueues( const exception_StatisticsQueues & ) throw() {} // other

	const exception_StatisticsQueues &operator =( const exception_StatisticsQueues &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_StatisticsQueues::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _voiceFileQueueRtr;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _serviceFileQueueRtr;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > _voiceFileAndKeyPairQueueRtr;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > _voiceFielAndServiceFileQueueRtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
StatisticsQueues *StatisticsQueues::getNull() throw() {
	return null_StatisticsQueues::instance();
}

// static
StatisticsQueues *StatisticsQueues::getException() throw() {
	return exception_StatisticsQueues::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace mdm
} // namespace nppntt
