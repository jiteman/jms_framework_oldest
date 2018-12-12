#include "realization_ImmediateVoiceFileAndKeyPairVerifier.h"
#include "../../externals/software/es_VoiceFileAndKeyPairMatchChecker.h"
#include "../../externals/data/ed_VoiceFile.h"
#include "../../externals/data/ed_Key.h"
#include "jmsf/osie/Event.h"
#include "jmsf/osie/EventArray.h"
#include "jmsf/mtf/Thread.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/Pair.hpp"
#include "jmsf/Pointers.hpp"
#include "jmsf/Casts.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {


void realization_ImmediateVoiceFileAndKeyPairVerifier::run() throw( ::jmsf::Exception ) {
	_sourceVoiceFileAndKeyPairQueue->takeMutex()->lock();

	if ( _sourceVoiceFileAndKeyPairQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceVoiceFileAndKeyPairQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > voiceFileAndKeyPair =
		_sourceVoiceFileAndKeyPairQueue->withdrawFirst();
	
	_sourceVoiceFileAndKeyPairQueue->takeMutex()->unlock();
	_voiceFileAndKeyPairMatchChecker->setPair( voiceFileAndKeyPair.getWeak() );

// 	continueRunningOfNestedRunnables();
// 	waitTillRunningOfNestedRunnablesIsStopped();

	if ( _voiceFileAndKeyPairMatchChecker->isPairMatched() ) {
		_destinationMatchedVoiceFileAndKeyPairQueue->takeMutex()->lock();
		_destinationMatchedVoiceFileAndKeyPairQueue->appendBack( voiceFileAndKeyPair );
		_destinationMatchedVoiceFileAndKeyPairQueue->takeMutex()->unlock();
	} else {
		_destinationVoiceFileWithNoMatchFoundQueue->takeMutex()->lock();
		_destinationVoiceFileWithNoMatchFoundQueue->appendBack( voiceFileAndKeyPair->takeFirst() );
		_destinationVoiceFileWithNoMatchFoundQueue->takeMutex()->unlock();
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ImmediateVoiceFileAndKeyPairVerifier::~realization_ImmediateVoiceFileAndKeyPairVerifier() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ImmediateVoiceFileAndKeyPairVerifier::realization_ImmediateVoiceFileAndKeyPairVerifier(
	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &sourceVoiceFileAndKeyPairQueue,
	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &destinationMatchedVoiceFileAndKeyPairQueue,
	const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileWithNoMatchFoundQueue,
	const ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > &voiceFileAndKeyPairMatchChecker ) throw()
	:
		_sourceVoiceFileAndKeyPairQueue( sourceVoiceFileAndKeyPairQueue ),
		_destinationMatchedVoiceFileAndKeyPairQueue( destinationMatchedVoiceFileAndKeyPairQueue ),
		_destinationVoiceFileWithNoMatchFoundQueue( destinationVoiceFileWithNoMatchFoundQueue ),
		_voiceFileAndKeyPairMatchChecker( voiceFileAndKeyPairMatchChecker )
{
// 	appendNestedRunnable( ::jmsf::adjacentCast< ::jmsf::osie::runup::Runnable >( _voiceFileAndKeyPairMatchChecker.getWeak() ) );
// 	appendWaitableEvent( _sourceVoiceFileAndKeyPairQueue->getOneselfIsObjectAvailableEvent() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ImmediateVoiceFileAndKeyPairVerifier > realization_ImmediateVoiceFileAndKeyPairVerifier::createClone() const throw() {
	return ::jmsf::Proxy< ImmediateVoiceFileAndKeyPairVerifier >::createUnique( new realization_ImmediateVoiceFileAndKeyPairVerifier( *this ) );
}

realization_ImmediateVoiceFileAndKeyPairVerifier::realization_ImmediateVoiceFileAndKeyPairVerifier( const realization_ImmediateVoiceFileAndKeyPairVerifier & ) throw() // other
{}

const realization_ImmediateVoiceFileAndKeyPairVerifier &realization_ImmediateVoiceFileAndKeyPairVerifier::operator =( const realization_ImmediateVoiceFileAndKeyPairVerifier &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
}
