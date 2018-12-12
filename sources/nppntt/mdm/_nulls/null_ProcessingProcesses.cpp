#include "null_ProcessingProcesses.h"

#include "../processing/NewVoiceFileDispatcher.h"
#include "../processing/VoiceFileDecipher.h"
#include "../processing/ImmediateVoiceFileAndKeyPairVerifier.h"
#include "../processing/PreliminaryVoiceFileAndKeyMatchFinder.h"
#include "../processing/RecurrentVoiceFileAndKeyMatchFinder.h"
#include "../processing/VoiceFileDeleter.h"
#include "../processing/NewServiceFileDispatcher.h"
#include "../processing/ServiceFileDeleter.h"
#include "../processing/LastChanceServiceFileMatchFinder.h"
#include "../processing/ServiceFileAndKeyMatchFinder.h"
#include "../processing/ResultToStorageAppender.h"
#include "../processing/NewKeyDispatcher.h"
#include "../processing/KeyArray.h"
#include "../processing/ServiceFileArray.h"

#include "jmsf/osie/runup/RunnableArray.h"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace nulls {


::jmsf::Proxy< processing::NewVoiceFileDispatcher > null_ProcessingProcesses::getOneselfNewVoiceFileDispatcher() throw() {
	return ::jmsf::Proxy< processing::NewVoiceFileDispatcher >();
}

::jmsf::Proxy< processing::VoiceFileDecipher > null_ProcessingProcesses::getOneselfVoiceFileDecipher() throw() {
	return ::jmsf::Proxy< processing::VoiceFileDecipher >();
}

::jmsf::Proxy< processing::ImmediateVoiceFileAndKeyPairVerifier > null_ProcessingProcesses::getOneselfImmediateVoiceFileAndKeyPairVerifier() throw() {
	return ::jmsf::Proxy< processing::ImmediateVoiceFileAndKeyPairVerifier >();
}

::jmsf::Proxy< processing::PreliminaryVoiceFileAndKeyMatchFinder > null_ProcessingProcesses::getOneselfPreliminaryVoiceFileAndKeyMatchFinder() throw() {
	return ::jmsf::Proxy< processing::PreliminaryVoiceFileAndKeyMatchFinder >();
}

::jmsf::Proxy< processing::RecurrentVoiceFileAndKeyMatchFinder > null_ProcessingProcesses::getOneselfRecurrentVoiceFileAndKeyMatchFinder() throw() {
	return ::jmsf::Proxy< processing::RecurrentVoiceFileAndKeyMatchFinder >();
}

::jmsf::Proxy< processing::VoiceFileDeleter > null_ProcessingProcesses::getOneselfVoiceFileDeleter() throw() {
	return ::jmsf::Proxy< processing::VoiceFileDeleter >();
}

::jmsf::Proxy< processing::LastChanceServiceFileMatchFinder > null_ProcessingProcesses::getOneselfLastChanceServiceFileMatchFinder() throw() {
	return ::jmsf::Proxy< processing::LastChanceServiceFileMatchFinder >();
}

::jmsf::Proxy< processing::NewServiceFileDispatcher > null_ProcessingProcesses::getOneselfNewServiceFileDispatcher() throw() {
	return ::jmsf::Proxy< processing::NewServiceFileDispatcher >();
}

::jmsf::Proxy< processing::ServiceFileDeleter > null_ProcessingProcesses::getOneselfServiceFileDeleter() throw() {
	return ::jmsf::Proxy< processing::ServiceFileDeleter >();
}

::jmsf::Proxy< processing::ServiceFileAndKeyMatchFinder > null_ProcessingProcesses::getOneselfServiceFileAndKeyMatchFinder() throw() {
	return ::jmsf::Proxy< processing::ServiceFileAndKeyMatchFinder >();
}

::jmsf::Proxy< processing::ResultToStorageAppender > null_ProcessingProcesses::getOneselfResultToStorageAppender() throw() {
	return ::jmsf::Proxy< processing::ResultToStorageAppender >();
}

::jmsf::Proxy< processing::NewKeyDispatcher > null_ProcessingProcesses::getOneselfNewKeyDispatcher() throw() {
	return ::jmsf::Proxy< processing::NewKeyDispatcher >();
}

::jmsf::Proxy< processing::KeyArray > null_ProcessingProcesses::getOneselfKeyArray() throw() {
	return ::jmsf::Proxy< processing::KeyArray >();
}

::jmsf::Proxy< processing::ServiceFileArray > null_ProcessingProcesses::getOneselfServiceFileArray() throw() {
	return ::jmsf::Proxy< processing::ServiceFileArray >();
}

::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray > null_ProcessingProcesses::getOneselfProcessArray() throw() {
	return ::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray >();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ProcessingProcesses::~null_ProcessingProcesses() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ProcessingProcesses *null_ProcessingProcesses::createInstance() throw() {
	return new null_ProcessingProcesses;
}

null_ProcessingProcesses::null_ProcessingProcesses() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ProcessingProcesses > null_ProcessingProcesses::createClone() const throw() {
	return ::jmsf::Proxy< ProcessingProcesses >::createUnique( this );
}

null_ProcessingProcesses::null_ProcessingProcesses( const null_ProcessingProcesses & ) throw() // other
{}

const null_ProcessingProcesses &null_ProcessingProcesses::operator =( const null_ProcessingProcesses &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
