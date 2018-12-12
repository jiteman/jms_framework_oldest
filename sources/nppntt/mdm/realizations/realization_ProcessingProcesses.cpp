#include "realization_ProcessingProcesses.h"
#include "../processing/NewVoiceFileDispatcher.h"
#include "../processing/VoiceFileDecipher.h"
#include "../processing/ImmediateVoiceFileAndKeyPairVerifier.h"
#include "../processing/PreliminaryVoiceFileAndKeyMatchFinder.h"
#include "../processing/RecurrentVoiceFileAndKeyMatchFinder.h"
#include "../processing/VoiceFileDeleter.h"
#include "../processing/NewServiceFileDispatcher.h"
#include "../processing/LastChanceServiceFileMatchFinder.h"
#include "../processing/ServiceFileDeleter.h"
#include "../processing/ServiceFileAndKeyMatchFinder.h"
#include "../processing/ResultToStorageAppender.h"
#include "../processing/NewKeyDispatcher.h"
#include "../processing/KeyArray.h"
#include "../processing/ServiceFileArray.h"
#include "jmsf/mtf/Thread.h"
#include "jmsf/Container.hpp"

namespace nppntt {
namespace mdm {
namespace realizations {
	
::jmsf::Proxy< processing::NewVoiceFileDispatcher > &realization_ProcessingProcesses::takeNewVoiceFileDispatcher() throw() {
	return _newVoiceFileDispatcher;
}

::jmsf::Proxy< processing::VoiceFileDecipher > &realization_ProcessingProcesses::takeVoiceFileDecipher() throw() {
	return _voiceFileDecipher;
}

::jmsf::Proxy< processing::ImmediateVoiceFileAndKeyPairVerifier > &realization_ProcessingProcesses::takeImmediateVoiceFileAndKeyPairVerifier() throw() {
	return _immediateVoiceFileAndKeyPairVerifier;
}

::jmsf::Proxy< processing::PreliminaryVoiceFileAndKeyMatchFinder > &realization_ProcessingProcesses::takePreliminaryVoiceFileAndKeyMatchFinder() throw() {
	return _preliminaryVoiceFileAndKeyMatchFinder;
}

::jmsf::Proxy< processing::RecurrentVoiceFileAndKeyMatchFinder > &realization_ProcessingProcesses::takeRecurrentVoiceFileAndKeyMatchFinder() throw() {
	return _recurrentVoiceFileAndKeyMatchFinder;
}

::jmsf::Proxy< processing::VoiceFileDeleter > &realization_ProcessingProcesses::takeVoiceFileDeleter() throw() {
	return _voiceFileDeleter;
}

::jmsf::Proxy< processing::NewServiceFileDispatcher > &realization_ProcessingProcesses::takeNewServiceFileDispatcher() throw() {
	return _newServiceFileDispatcher;
}

::jmsf::Proxy< processing::LastChanceServiceFileMatchFinder > &realization_ProcessingProcesses::takeLastChanceServiceFileMatchFinder() throw() {
	return _lastChanceServiceFileMatchFinder;
}

::jmsf::Proxy< processing::ServiceFileDeleter > &realization_ProcessingProcesses::takeServiceFileDeleter() throw() {
	return _serviceFileDeleter;
}

::jmsf::Proxy< processing::ServiceFileAndKeyMatchFinder > &realization_ProcessingProcesses::takeServiceFileAndKeyMatchFinder() throw() {
	return _serviceFileAndKeyMatchFinder;
}

::jmsf::Proxy< processing::ResultToStorageAppender > &realization_ProcessingProcesses::takeResultToStorageAppender() throw() {
	return _resultToStorageAppender;
}

::jmsf::Proxy< processing::NewKeyDispatcher > &realization_ProcessingProcesses::takeNewKeyDispatcher() throw() {
	return _newKeyDispatcher;
}

::jmsf::Proxy< processing::KeyArray > &realization_ProcessingProcesses::takeKeyArray() throw() {
	return _keyArray;
}

::jmsf::Proxy< processing::ServiceFileArray > &realization_ProcessingProcesses::takeServiceFileArray() throw() {
	return _serviceFileArray;
}

::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &realization_ProcessingProcesses::takeThreadContainer() throw() {
	return _threadContainer;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ProcessingProcesses::~realization_ProcessingProcesses() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ProcessingProcesses::realization_ProcessingProcesses(
		const ::jmsf::Proxy< processing::NewVoiceFileDispatcher > &newVoiceFileDispatcher,
		const ::jmsf::Proxy< processing::VoiceFileDecipher > &voiceFileDecipher,
		const ::jmsf::Proxy< processing::ImmediateVoiceFileAndKeyPairVerifier > &immediateVoiceFileAndKeyPairVerifier,
		const ::jmsf::Proxy< processing::PreliminaryVoiceFileAndKeyMatchFinder > &preliminaryVoiceFileAndKeyMatchFinder,
		const ::jmsf::Proxy< processing::RecurrentVoiceFileAndKeyMatchFinder > &recurrentVoiceFileAndKeyMatchFinder,
		const ::jmsf::Proxy< processing::VoiceFileDeleter > &voiceFileDeleter,
		const ::jmsf::Proxy< processing::NewServiceFileDispatcher > &newServiceFileDispatcher,
		const ::jmsf::Proxy< processing::LastChanceServiceFileMatchFinder > &lastChanceServiceFileMatchFinder,
		const ::jmsf::Proxy< processing::ServiceFileDeleter > &serviceFileDeleter,
		const ::jmsf::Proxy< processing::ServiceFileAndKeyMatchFinder > &serviceFileAndKeyMatchFinder,
		const ::jmsf::Proxy< processing::ResultToStorageAppender > &resultToStorageAppender,
		const ::jmsf::Proxy< processing::NewKeyDispatcher > &newKeyDispatcher,
		const ::jmsf::Proxy< processing::KeyArray > &keyArray,
		const ::jmsf::Proxy< processing::ServiceFileArray > &serviceFileArray,
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &threadContainer ) throw()
	:
		_newVoiceFileDispatcher( newVoiceFileDispatcher ),
		_voiceFileDecipher( voiceFileDecipher ),
		_immediateVoiceFileAndKeyPairVerifier( immediateVoiceFileAndKeyPairVerifier ),

		_preliminaryVoiceFileAndKeyMatchFinder( preliminaryVoiceFileAndKeyMatchFinder ),
		_recurrentVoiceFileAndKeyMatchFinder( recurrentVoiceFileAndKeyMatchFinder ),
		_voiceFileDeleter( voiceFileDeleter ),

		_newServiceFileDispatcher( newServiceFileDispatcher ),
		_lastChanceServiceFileMatchFinder( lastChanceServiceFileMatchFinder ),
		_serviceFileDeleter( serviceFileDeleter ),

		_serviceFileAndKeyMatchFinder( serviceFileAndKeyMatchFinder ),
		_resultToStorageAppender( resultToStorageAppender ),

		_newKeyDispatcher( newKeyDispatcher ),
		_keyArray( keyArray ),
		_serviceFileArray( serviceFileArray ),

		_threadContainer( threadContainer )
{
// 	_processArray->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _newVoiceFileDispatcher.get() ) );
// 	_processArray->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _voiceFileDecipher.get() ) );
// 	_processArray->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _immediateVoiceFileAndKeyPairVerifier.get() ) );
// 	_processArray->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _preliminaryVoiceFileAndKeyMatchFinder.get() ) );
// 	_processArray->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _recurrentVoiceFileAndKeyMatchFinder.get() ) );
// 	_processArray->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _voiceFileDeleter.get() ) );
// 	_processArray->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _newServiceFileDispatcher.get() ) );
// 	_processArray->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _lastChanceServiceFileMatchFinder.get() ) );	
// 	_processArray->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _serviceFileDeleter.get() ) );
// 	_processArray->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _serviceFileAndKeyMatchFinder.get() ) );
// 	_processArray->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _resultToStorageAppender.get() ) );
// 	_processArray->appendRunnable( ::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor( _newKeyDispatcher.get() ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ProcessingProcesses > realization_ProcessingProcesses::createClone() const throw() {
	return ::jmsf::Proxy< ProcessingProcesses >::createUnique( new realization_ProcessingProcesses( *this ) );
}

realization_ProcessingProcesses::realization_ProcessingProcesses( const realization_ProcessingProcesses & ) throw() // other
{}

const realization_ProcessingProcesses &realization_ProcessingProcesses::operator =( const realization_ProcessingProcesses &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
