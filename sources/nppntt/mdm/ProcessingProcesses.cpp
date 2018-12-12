#include "ProcessingProcesses.h"
#include "processing/NewVoiceFileDispatcher.h"
#include "processing/VoiceFileDecipher.h"
#include "processing/ImmediateVoiceFileAndKeyPairVerifier.h"
#include "processing/PreliminaryVoiceFileAndKeyMatchFinder.h"
#include "processing/RecurrentVoiceFileAndKeyMatchFinder.h"
#include "processing/VoiceFileDeleter.h"
#include "processing/NewServiceFileDispatcher.h"
#include "processing/LastChanceServiceFileMatchFinder.h"
#include "processing/ServiceFileDeleter.h"
#include "processing/ServiceFileAndKeyMatchFinder.h"
#include "processing/ResultToStorageAppender.h"
#include "processing/NewKeyDispatcher.h"
#include "processing/KeyArray.h"
#include "processing/ServiceFileArray.h"
#include "jmsf/mtf/Thread.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Container.hpp"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {

class null_ProcessingProcesses :
	public ProcessingProcesses,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ProcessingProcesses >
{

public:
	// virtuals ProcessingProcesses
	::jmsf::Proxy< processing::NewVoiceFileDispatcher > &takeNewVoiceFileDispatcher() throw() {
		return _newVoiceFileDispatcherRtr;
	}

	::jmsf::Proxy< processing::VoiceFileDecipher > &takeVoiceFileDecipher() throw() {
		return _voiceFileDecipherRtr;
	}

	::jmsf::Proxy< processing::ImmediateVoiceFileAndKeyPairVerifier > &takeImmediateVoiceFileAndKeyPairVerifier() throw() {
		return _immediateVoiceFileAndKeyPairVerifierRtr;
	}

	::jmsf::Proxy< processing::PreliminaryVoiceFileAndKeyMatchFinder > &takePreliminaryVoiceFileAndKeyMatchFinder() throw() {
		return _preliminaryVoiceFileAndKeyMatchFinderRtr;
	}

	::jmsf::Proxy< processing::RecurrentVoiceFileAndKeyMatchFinder > &takeRecurrentVoiceFileAndKeyMatchFinder() throw() {
		return _recurrentVoiceFileAndKeyMatchFinderRtr;
	}

	::jmsf::Proxy< processing::VoiceFileDeleter > &takeVoiceFileDeleter() throw() {
		return _voiceFileDeleterRtr;
	}

	::jmsf::Proxy< processing::NewServiceFileDispatcher > &takeNewServiceFileDispatcher() throw() {
		return _newServiceFileDispatcherRtr;
	}

	::jmsf::Proxy< processing::LastChanceServiceFileMatchFinder > &takeLastChanceServiceFileMatchFinder() throw() {
		return _lastChanceServiceFileMatchFinderRtr;
	}

	::jmsf::Proxy< processing::ServiceFileDeleter > &takeServiceFileDeleter() throw() {
		return _serviceFileDeleterRtr;
	}

	::jmsf::Proxy< processing::ServiceFileAndKeyMatchFinder > &takeServiceFileAndKeyMatchFinder() throw() {
		return _serviceFileAndKeyMatchFinderRtr;
	}

	::jmsf::Proxy< processing::ResultToStorageAppender > &takeResultToStorageAppender() throw() {
		return _resultToStorageAppenderRtr;
	}

	::jmsf::Proxy< processing::NewKeyDispatcher > &takeNewKeyDispatcher() throw() {
		return _newKeyDispatcherRtr;
	}

	::jmsf::Proxy< processing::KeyArray > &takeKeyArray() throw() {
		return _keyArrayRtr;
	}

	::jmsf::Proxy< processing::ServiceFileArray > &takeServiceFileArray() throw() {
		return _serviceFileArrayRtr;
	}

	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &takeThreadContainer() throw() {
		return _threadContainerRtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ProcessingProcesses() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ProcessingProcesses >;
	static null_ProcessingProcesses *createInstance() throw() {
		return new null_ProcessingProcesses;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ProcessingProcesses() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ProcessingProcesses > createClone() const throw() {
		return ::jmsf::Proxy< ProcessingProcesses >::createUnique( this );
	}

private:
	null_ProcessingProcesses( const null_ProcessingProcesses & ) throw() {} // other
	
	const null_ProcessingProcesses &operator =( const null_ProcessingProcesses &other ) throw( jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ProcessingProcesses::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< processing::NewVoiceFileDispatcher > _newVoiceFileDispatcherRtr;
	::jmsf::Proxy< processing::VoiceFileDecipher > _voiceFileDecipherRtr;
	::jmsf::Proxy< processing::ImmediateVoiceFileAndKeyPairVerifier > _immediateVoiceFileAndKeyPairVerifierRtr;
	::jmsf::Proxy< processing::PreliminaryVoiceFileAndKeyMatchFinder > _preliminaryVoiceFileAndKeyMatchFinderRtr;
	::jmsf::Proxy< processing::RecurrentVoiceFileAndKeyMatchFinder > _recurrentVoiceFileAndKeyMatchFinderRtr;
	::jmsf::Proxy< processing::VoiceFileDeleter > _voiceFileDeleterRtr;
	::jmsf::Proxy< processing::NewServiceFileDispatcher > _newServiceFileDispatcherRtr;
	::jmsf::Proxy< processing::LastChanceServiceFileMatchFinder > _lastChanceServiceFileMatchFinderRtr;
	::jmsf::Proxy< processing::ServiceFileDeleter > _serviceFileDeleterRtr;
	::jmsf::Proxy< processing::ServiceFileAndKeyMatchFinder > _serviceFileAndKeyMatchFinderRtr;
	::jmsf::Proxy< processing::ResultToStorageAppender > _resultToStorageAppenderRtr;
	::jmsf::Proxy< processing::NewKeyDispatcher > _newKeyDispatcherRtr;
	::jmsf::Proxy< processing::KeyArray > _keyArrayRtr;
	::jmsf::Proxy< processing::ServiceFileArray > _serviceFileArrayRtr;
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > _threadContainerRtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_ProcessingProcesses :
	public ProcessingProcesses,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ProcessingProcesses > {

public:
	// virtuals ProcessingProcesses
	::jmsf::Proxy< processing::NewVoiceFileDispatcher > &takeNewVoiceFileDispatcher() throw() {
		return _newVoiceFileDispatcherRtr;
	}

	::jmsf::Proxy< processing::VoiceFileDecipher > &takeVoiceFileDecipher() throw() {
		return _voiceFileDecipherRtr;
	}

	::jmsf::Proxy< processing::ImmediateVoiceFileAndKeyPairVerifier > &takeImmediateVoiceFileAndKeyPairVerifier() throw() {
		return _immediateVoiceFileAndKeyPairVerifierRtr;
	}

	::jmsf::Proxy< processing::PreliminaryVoiceFileAndKeyMatchFinder > &takePreliminaryVoiceFileAndKeyMatchFinder() throw() {
		return _preliminaryVoiceFileAndKeyMatchFinderRtr;
	}

	::jmsf::Proxy< processing::RecurrentVoiceFileAndKeyMatchFinder > &takeRecurrentVoiceFileAndKeyMatchFinder() throw() {
		return _recurrentVoiceFileAndKeyMatchFinderRtr;
	}

	::jmsf::Proxy< processing::VoiceFileDeleter > &takeVoiceFileDeleter() throw() {
		return _voiceFileDeleterRtr;
	}

	::jmsf::Proxy< processing::NewServiceFileDispatcher > &takeNewServiceFileDispatcher() throw() {
		return _newServiceFileDispatcherRtr;
	}

	::jmsf::Proxy< processing::LastChanceServiceFileMatchFinder > &takeLastChanceServiceFileMatchFinder() throw() {
		return _lastChanceServiceFileMatchFinderRtr;
	}

	::jmsf::Proxy< processing::ServiceFileDeleter > &takeServiceFileDeleter() throw() {
		return _serviceFileDeleterRtr;
	}

	::jmsf::Proxy< processing::ServiceFileAndKeyMatchFinder > &takeServiceFileAndKeyMatchFinder() throw() {
		return _serviceFileAndKeyMatchFinderRtr;
	}

	::jmsf::Proxy< processing::ResultToStorageAppender > &takeResultToStorageAppender() throw() {
		return _resultToStorageAppenderRtr;
	}

	::jmsf::Proxy< processing::NewKeyDispatcher > &takeNewKeyDispatcher() throw() {
		return _newKeyDispatcherRtr;
	}

	::jmsf::Proxy< processing::KeyArray > &takeKeyArray() throw() {
		return _keyArrayRtr;
	}

	::jmsf::Proxy< processing::ServiceFileArray > &takeServiceFileArray() throw() {
		return _serviceFileArrayRtr;
	}

	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > &takeThreadContainer() throw() {
		return _threadContainerRtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ProcessingProcesses() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ProcessingProcesses >;
	static exception_ProcessingProcesses *createInstance() throw() {
		return new exception_ProcessingProcesses;
	}

private:
	exception_ProcessingProcesses() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ProcessingProcesses > createClone() const throw() {
		return ::jmsf::Proxy< ProcessingProcesses >::createUnique( this );
	}

private:
	exception_ProcessingProcesses( const exception_ProcessingProcesses & ) throw() {} // other

	const exception_ProcessingProcesses &operator =( const exception_ProcessingProcesses &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ProcessingProcesses::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< processing::NewVoiceFileDispatcher > _newVoiceFileDispatcherRtr;
	::jmsf::Proxy< processing::VoiceFileDecipher > _voiceFileDecipherRtr;
	::jmsf::Proxy< processing::ImmediateVoiceFileAndKeyPairVerifier > _immediateVoiceFileAndKeyPairVerifierRtr;
	::jmsf::Proxy< processing::PreliminaryVoiceFileAndKeyMatchFinder > _preliminaryVoiceFileAndKeyMatchFinderRtr;
	::jmsf::Proxy< processing::RecurrentVoiceFileAndKeyMatchFinder > _recurrentVoiceFileAndKeyMatchFinderRtr;
	::jmsf::Proxy< processing::VoiceFileDeleter > _voiceFileDeleterRtr;
	::jmsf::Proxy< processing::NewServiceFileDispatcher > _newServiceFileDispatcherRtr;
	::jmsf::Proxy< processing::LastChanceServiceFileMatchFinder > _lastChanceServiceFileMatchFinderRtr;
	::jmsf::Proxy< processing::ServiceFileDeleter > _serviceFileDeleterRtr;
	::jmsf::Proxy< processing::ServiceFileAndKeyMatchFinder > _serviceFileAndKeyMatchFinderRtr;
	::jmsf::Proxy< processing::ResultToStorageAppender > _resultToStorageAppenderRtr;
	::jmsf::Proxy< processing::NewKeyDispatcher > _newKeyDispatcherRtr;
	::jmsf::Proxy< processing::KeyArray > _keyArrayRtr;
	::jmsf::Proxy< processing::ServiceFileArray > _serviceFileArrayRtr;
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > _threadContainerRtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
ProcessingProcesses *ProcessingProcesses::getNull() throw() {
	return null_ProcessingProcesses::instance();
}

// static
ProcessingProcesses *ProcessingProcesses::getException() throw() {
	return exception_ProcessingProcesses::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace mdm
} // namespace nppntt
