#pragma once

#include "../ProcessingProcesses.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "realization_factory_MaskDmObjects.hxx"

namespace nppntt {
namespace mdm {
namespace realizations {

class realization_ProcessingProcesses :
	public ProcessingProcesses,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals ProcessingProcesses
	::jmsf::Proxy< processing::NewVoiceFileDispatcher > &takeNewVoiceFileDispatcher() throw();
	::jmsf::Proxy< processing::VoiceFileDecipher > &takeVoiceFileDecipher() throw();
	::jmsf::Proxy< processing::ImmediateVoiceFileAndKeyPairVerifier > &takeImmediateVoiceFileAndKeyPairVerifier() throw();
	::jmsf::Proxy< processing::PreliminaryVoiceFileAndKeyMatchFinder > &takePreliminaryVoiceFileAndKeyMatchFinder() throw();
	::jmsf::Proxy< processing::RecurrentVoiceFileAndKeyMatchFinder > &takeRecurrentVoiceFileAndKeyMatchFinder() throw();
	::jmsf::Proxy< processing::VoiceFileDeleter > &takeVoiceFileDeleter() throw();

	::jmsf::Proxy< processing::NewServiceFileDispatcher > &takeNewServiceFileDispatcher() throw();
	::jmsf::Proxy< processing::LastChanceServiceFileMatchFinder > &takeLastChanceServiceFileMatchFinder() throw();
	::jmsf::Proxy< processing::ServiceFileDeleter > &takeServiceFileDeleter() throw();

	::jmsf::Proxy< processing::ServiceFileAndKeyMatchFinder > &takeServiceFileAndKeyMatchFinder() throw();
	::jmsf::Proxy< processing::ResultToStorageAppender > &takeResultToStorageAppender() throw();

	::jmsf::Proxy< processing::NewKeyDispatcher > &takeNewKeyDispatcher() throw();
	::jmsf::Proxy< processing::KeyArray > &takeKeyArray() throw();
	::jmsf::Proxy< processing::ServiceFileArray > &takeServiceFileArray() throw();

	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &takeThreadContainer() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ProcessingProcesses() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_MaskDmObjects;
	realization_ProcessingProcesses(
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
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &threadContainer ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ProcessingProcesses > createClone() const throw();

private:
	realization_ProcessingProcesses( const realization_ProcessingProcesses &other ) throw();
	const realization_ProcessingProcesses &operator =( const realization_ProcessingProcesses &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< processing::NewVoiceFileDispatcher > _newVoiceFileDispatcher;
	::jmsf::Proxy< processing::VoiceFileDecipher > _voiceFileDecipher;
	::jmsf::Proxy< processing::ImmediateVoiceFileAndKeyPairVerifier > _immediateVoiceFileAndKeyPairVerifier;
	::jmsf::Proxy< processing::PreliminaryVoiceFileAndKeyMatchFinder > _preliminaryVoiceFileAndKeyMatchFinder;
	::jmsf::Proxy< processing::RecurrentVoiceFileAndKeyMatchFinder > _recurrentVoiceFileAndKeyMatchFinder;
	::jmsf::Proxy< processing::VoiceFileDeleter > _voiceFileDeleter;

	::jmsf::Proxy< processing::NewServiceFileDispatcher > _newServiceFileDispatcher;
	::jmsf::Proxy< processing::LastChanceServiceFileMatchFinder > _lastChanceServiceFileMatchFinder;
	::jmsf::Proxy< processing::ServiceFileDeleter > _serviceFileDeleter;

	::jmsf::Proxy< processing::ServiceFileAndKeyMatchFinder > _serviceFileAndKeyMatchFinder;
	::jmsf::Proxy< processing::ResultToStorageAppender > _resultToStorageAppender;

	::jmsf::Proxy< processing::NewKeyDispatcher > _newKeyDispatcher;
	::jmsf::Proxy< processing::KeyArray > _keyArray;
	::jmsf::Proxy< processing::ServiceFileArray > _serviceFileArray;

	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > _threadContainer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
