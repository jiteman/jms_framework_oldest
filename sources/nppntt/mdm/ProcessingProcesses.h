#pragma once

#include "jmsf/Object.h"

#include "processing/NewVoiceFileDispatcher.hxx"
#include "processing/VoiceFileDecipher.hxx"
#include "processing/ImmediateVoiceFileAndKeyPairVerifier.hxx"
#include "processing/PreliminaryVoiceFileAndKeyMatchFinder.hxx"
#include "processing/RecurrentVoiceFileAndKeyMatchFinder.hxx"
#include "processing/VoiceFileDeleter.hxx"
#include "processing/NewServiceFileDispatcher.hxx"
#include "processing/LastChanceServiceFileMatchFinder.hxx"
#include "processing/ServiceFileDeleter.hxx"
#include "processing/ServiceFileAndKeyMatchFinder.hxx"
#include "processing/ResultToStorageAppender.hxx"
#include "processing/NewKeyDispatcher.hxx"
#include "processing/KeyArray.hxx"
#include "processing/ServiceFileArray.hxx"

#include "jmsf/mtf/Thread.hxx"
#include "jmsf/Container.hxx"
#include "jmsf/PointersAndProxies.hxx"

namespace nppntt {
namespace mdm {

class ProcessingProcesses :
	public virtual ::jmsf::Object
{

public:
	virtual ::jmsf::Proxy< processing::NewVoiceFileDispatcher > &takeNewVoiceFileDispatcher() throw() = 0;
	virtual ::jmsf::Proxy< processing::VoiceFileDecipher > &takeVoiceFileDecipher() throw() = 0;
	virtual ::jmsf::Proxy< processing::ImmediateVoiceFileAndKeyPairVerifier > &takeImmediateVoiceFileAndKeyPairVerifier() throw() = 0;
	virtual ::jmsf::Proxy< processing::PreliminaryVoiceFileAndKeyMatchFinder > &takePreliminaryVoiceFileAndKeyMatchFinder() throw() = 0;
	virtual ::jmsf::Proxy< processing::RecurrentVoiceFileAndKeyMatchFinder > &takeRecurrentVoiceFileAndKeyMatchFinder() throw() = 0;
	virtual ::jmsf::Proxy< processing::VoiceFileDeleter > &takeVoiceFileDeleter() throw() = 0;

	virtual ::jmsf::Proxy< processing::NewServiceFileDispatcher > &takeNewServiceFileDispatcher() throw() = 0;
	virtual ::jmsf::Proxy< processing::LastChanceServiceFileMatchFinder > &takeLastChanceServiceFileMatchFinder() throw() = 0;
	virtual ::jmsf::Proxy< processing::ServiceFileDeleter > &takeServiceFileDeleter() throw() = 0;

	virtual ::jmsf::Proxy< processing::ServiceFileAndKeyMatchFinder > &takeServiceFileAndKeyMatchFinder() throw() = 0;
	virtual ::jmsf::Proxy< processing::ResultToStorageAppender > &takeResultToStorageAppender() throw() = 0;

	virtual ::jmsf::Proxy< processing::NewKeyDispatcher > &takeNewKeyDispatcher() throw() = 0;
	virtual ::jmsf::Proxy< processing::KeyArray > &takeKeyArray() throw() = 0;
	virtual ::jmsf::Proxy< processing::ServiceFileArray > &takeServiceFileArray() throw() = 0;

	virtual ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &takeThreadContainer() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ProcessingProcesses *getNull() throw();
	static ProcessingProcesses *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< ProcessingProcesses > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace mdm
} // namespace nppntt
