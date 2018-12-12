#pragma once

#include "../ProcessingProcesses.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


#include "jmsf/Proxies.hpp"
#include "jmsf/Pointers.hpp"


namespace nppntt {
namespace mdm {
namespace nulls {


class null_ProcessingProcesses :
	public ProcessingProcesses,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_ProcessingProcesses >
{

public:
	// virtuals ProcessingProcesses
	::jmsf::Proxy< processing::NewVoiceFileDispatcher > getOneselfNewVoiceFileDispatcher() throw();
	::jmsf::Proxy< processing::VoiceFileDecipher > getOneselfVoiceFileDecipher() throw();
	::jmsf::Proxy< processing::ImmediateVoiceFileAndKeyPairVerifier > getOneselfImmediateVoiceFileAndKeyPairVerifier() throw();
	::jmsf::Proxy< processing::PreliminaryVoiceFileAndKeyMatchFinder > getOneselfPreliminaryVoiceFileAndKeyMatchFinder() throw();
	::jmsf::Proxy< processing::RecurrentVoiceFileAndKeyMatchFinder > getOneselfRecurrentVoiceFileAndKeyMatchFinder() throw();
	::jmsf::Proxy< processing::VoiceFileDeleter > getOneselfVoiceFileDeleter() throw();

	::jmsf::Proxy< processing::NewServiceFileDispatcher > getOneselfNewServiceFileDispatcher() throw();
	::jmsf::Proxy< processing::LastChanceServiceFileMatchFinder > getOneselfLastChanceServiceFileMatchFinder() throw();
	::jmsf::Proxy< processing::ServiceFileDeleter > getOneselfServiceFileDeleter() throw();

	::jmsf::Proxy< processing::ServiceFileAndKeyMatchFinder > getOneselfServiceFileAndKeyMatchFinder() throw();
	::jmsf::Proxy< processing::ResultToStorageAppender > getOneselfResultToStorageAppender() throw();

	::jmsf::Proxy< processing::NewKeyDispatcher > getOneselfNewKeyDispatcher() throw();
	::jmsf::Proxy< processing::KeyArray > getOneselfKeyArray() throw();
	::jmsf::Proxy< processing::ServiceFileArray > getOneselfServiceFileArray() throw();

	::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray > getOneselfProcessArray() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ProcessingProcesses() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_ProcessingProcesses >;
	static null_ProcessingProcesses *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ProcessingProcesses() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ProcessingProcesses > createClone() const throw();

private:
	null_ProcessingProcesses( const null_ProcessingProcesses &other ) throw();
	const null_ProcessingProcesses &operator =( const null_ProcessingProcesses &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
