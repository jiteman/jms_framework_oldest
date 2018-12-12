#include "realization_es_ServiceFileAndKeyPairMatchChecker.h"
#include "../../../exceptions/exception_DllNotFound.h"
#include "../../others/abstractApplyKey.h"
#include "../../data/ed_ServiceFile.h"
#include "../../data/ed_Key.h"
#include "jmsf/osie/Mutex.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/Pair.hpp"
#include "jmsf/Pointers.hpp"

namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace realizations {
	
void realization_es_ServiceFileAndKeyPairMatchChecker::setPair( const ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< data::ed_ServiceFile >, ::jmsf::ConstantProxy< data::ed_Key > > > &serviceFileAndKeyPair ) throw() {
	_serviceFileAndKeyPair = serviceFileAndKeyPair;
	_isPairMatched = ::jmsf::False;
}

const ::jmsf::Boolean realization_es_ServiceFileAndKeyPairMatchChecker::isPairMatched() const throw() {
	return _isPairMatched;
}

const ::jmsf::ConstantProxy< data::ed_Key > &realization_es_ServiceFileAndKeyPairMatchChecker::getTheKey() const throw() {
	return _serviceFileAndKeyPair->getSecond();
}

void realization_es_ServiceFileAndKeyPairMatchChecker::run() throw( ::jmsf::Exception ) {
	if ( _serviceFileAndKeyPair->getSecond().isEmpty() ) {
		_isPairMatched = ::jmsf::False;
		return;
	}

	::jmsf::Pointer< AppliedData > serviceFileAppliedData = ::jmsf::Pointer< AppliedData >::createWeakFor( 
		::CheckSDCCH(
			_serviceFileAndKeyPair->takeFirst()->takeData().get(),
			_serviceFileAndKeyPair->getSecond()->getData().get() ) );

	_isPairMatched = serviceFileAppliedData.isNotEmpty();

	// EugeneSh: REFACTOR - remove duplication
	if ( _isPairMatched ) {
		if ( _serviceFileAndKeyPair->getFirst()->getAppliedData().isEmpty() ) {
			_serviceFileAndKeyPairMatchCheckerMutex->lock();
		
			if ( _serviceFileAndKeyPair->getFirst()->getAppliedData().isEmpty() ) {
				_serviceFileAndKeyPair->takeFirst()->updateAppliedData( serviceFileAppliedData );
			} else {
				::deleteAppliedData( serviceFileAppliedData.get() );
				_isPairMatched = ::jmsf::False;
			}

			_serviceFileAndKeyPairMatchCheckerMutex->unlock();
		} else {
			::deleteAppliedData( serviceFileAppliedData.get() );
			_isPairMatched = ::jmsf::False;
		}
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_es_ServiceFileAndKeyPairMatchChecker::~realization_es_ServiceFileAndKeyPairMatchChecker() throw() {
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_es_ServiceFileAndKeyPairMatchChecker::realization_es_ServiceFileAndKeyPairMatchChecker(
	::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) throw( jmsf::Exception )
	:
		_serviceFileAndKeyPairMatchCheckerMutex( mutex )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< es_ServiceFileAndKeyPairMatchChecker > realization_es_ServiceFileAndKeyPairMatchChecker::createClone() const throw() {
	return ::jmsf::Proxy< es_ServiceFileAndKeyPairMatchChecker >::createUnique( new realization_es_ServiceFileAndKeyPairMatchChecker( *this ) );
}

realization_es_ServiceFileAndKeyPairMatchChecker::realization_es_ServiceFileAndKeyPairMatchChecker( const realization_es_ServiceFileAndKeyPairMatchChecker & ) throw() // other
{}

const realization_es_ServiceFileAndKeyPairMatchChecker &realization_es_ServiceFileAndKeyPairMatchChecker::operator =( const realization_es_ServiceFileAndKeyPairMatchChecker &other ) throw() {
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
