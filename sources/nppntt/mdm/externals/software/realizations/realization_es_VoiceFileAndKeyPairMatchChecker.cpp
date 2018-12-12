#include "realization_es_VoiceFileAndKeyPairMatchChecker.h"
#include "../../others/abstractApplyKey.h"
#include "../../data/ed_VoiceFile.h"
#include "../../data/ed_Key.h"
#include "jmsf/osie/Mutex.h"
#include "jmsf/Pair.hpp"
#include "jmsf/PointersAndProxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace realizations {


void realization_es_VoiceFileAndKeyPairMatchChecker::run() throw( ::jmsf::Exception ) {
	if ( _voiceFileAndKeyPair->getSecond().isEmpty() ) {
		_isPairMatched = ::jmsf::False;
		return;
	}

	::jmsf::Pointer< AppliedData > voiceFileAppliedData = ::jmsf::Pointer< AppliedData >::createWeakFor(
		::CheckTCH( _voiceFileAndKeyPair->getFirst()->getData().get(), _voiceFileAndKeyPair->getSecond()->getData().get() ) );

	_isPairMatched = voiceFileAppliedData.isNotEmpty();

	// EugeneSh: REFACTOR - remove duplication
	if ( _isPairMatched ) {
		if ( _voiceFileAndKeyPair->getFirst()->getAppliedData().isEmpty() ) {
			_voiceFileMutex->lock();
		
			if ( _voiceFileAndKeyPair->getFirst()->getAppliedData().isEmpty() ) {
				_voiceFileAndKeyPair->takeFirst()->updateAppliedData( voiceFileAppliedData );
			} else {
				::deleteAppliedData( voiceFileAppliedData.get() );
				_isPairMatched = ::jmsf::False;
			}

			_voiceFileMutex->unlock();
		} else {
			::deleteAppliedData( voiceFileAppliedData.get() );
			_isPairMatched = ::jmsf::False;
		}
	}
}

void realization_es_VoiceFileAndKeyPairMatchChecker::setPair( const ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< data::ed_VoiceFile >, ::jmsf::ConstantProxy< data::ed_Key > > > &voiceFileAndKeyPair ) throw() {
	_voiceFileAndKeyPair = voiceFileAndKeyPair;
	_isPairMatched = ::jmsf::False;
}

const ::jmsf::Boolean realization_es_VoiceFileAndKeyPairMatchChecker::isPairMatched() const throw() {
	return _isPairMatched;
}

const ::jmsf::ConstantProxy< data::ed_Key > &realization_es_VoiceFileAndKeyPairMatchChecker::getTheKey() const throw() {
	return _voiceFileAndKeyPair->getSecond();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_es_VoiceFileAndKeyPairMatchChecker::~realization_es_VoiceFileAndKeyPairMatchChecker() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_es_VoiceFileAndKeyPairMatchChecker::realization_es_VoiceFileAndKeyPairMatchChecker(
	::jmsf::Proxy< ::jmsf::osie::Mutex > mutex  ) throw()
	:
		_voiceFileMutex( mutex )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< es_VoiceFileAndKeyPairMatchChecker > realization_es_VoiceFileAndKeyPairMatchChecker::createClone() const throw() {
	return ::jmsf::Proxy< es_VoiceFileAndKeyPairMatchChecker >::createUnique( new realization_es_VoiceFileAndKeyPairMatchChecker( *this ) );
}

realization_es_VoiceFileAndKeyPairMatchChecker::realization_es_VoiceFileAndKeyPairMatchChecker( const realization_es_VoiceFileAndKeyPairMatchChecker & ) throw() // other
{}

const realization_es_VoiceFileAndKeyPairMatchChecker &realization_es_VoiceFileAndKeyPairMatchChecker::operator =( const realization_es_VoiceFileAndKeyPairMatchChecker &other ) throw() {
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
}
