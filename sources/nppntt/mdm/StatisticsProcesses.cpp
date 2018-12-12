#include "StatisticsProcesses.h"
#include "statistics/NewVoiceFileStatisticsProcess.h"
#include "statistics/NewServiceFileStatisticsProcess.h"
#include "statistics/VoiceFileForDecipheringStatisticsProcess.h"
#include "statistics/DecipheredVoiceFileAndKeyPairStatisticsProcess.h"
#include "statistics/NotDecipheredVoiceFileStatisticsProcess.h"
#include "statistics/ResultVoiceFileAndServiceFilePairStatisticsProcess.h"
#include "statistics/ResultVoiceFileStatisticsProcess.h"
#include "statistics/ResultServiceFileStatisticsProcess.h"
#include "statistics/DeletedVoiceFileStatisticsProcess.h"
#include "statistics/DeletedServiceFileStatisticsProcess.h"
#include "jmsf/mtf/Thread.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Container.hpp"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {

class null_StatisticsProcesses :
	public StatisticsProcesses,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_StatisticsProcesses >
{

public:
	// virtuals StatisticsProcesses
	::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess > &takeNewVoiceFileStatisticsProcess() throw() {
		return _newVoiceFileStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess > &takeNewServiceFileStatisticsProcess() throw() {
		return _newServiceFileStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess > &takeVoiceFileForDecipheringStatisticsProcess() throw() {
		return _voiceFileForDecipheringStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess > &takeDecipheredVoiceFileAndKeyPairStatisticsProcess() throw() {
		return _decipheredVoiceFileAndKeyPairStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess > &takeNotDecipheredVoiceFileStatisticsProcess() throw() {
		return _notDecipheredVoiceFileStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess > &takeResultVoiceFileAndServiceFilePairStatisticsProcess() throw() {
		return _resultVoiceFileAndServiceFilePairStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess > &takeResultVoiceFileStatisticsProcess() throw() {
		return _resultVoiceFileStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess > &takeResultServiceFileStatisticsProcess() throw() {
		return _retusltServiceFileStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess > &takeDeletedVoiceFileStatisticsProcess() throw() {
		return _deletedVoiceFileStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess > &takeDeletedServiceFileStatisticsProcess() throw() {
		return _deletedServiceFileStatisticsProcessRtr;
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
	~null_StatisticsProcesses() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_StatisticsProcesses >;
	static null_StatisticsProcesses *createInstance() throw() {
		return new null_StatisticsProcesses;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_StatisticsProcesses() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< StatisticsProcesses > createClone() const throw() {
		return ::jmsf::Proxy< StatisticsProcesses >::createUnique( this );
	}

private:
	null_StatisticsProcesses( const null_StatisticsProcesses & ) throw() {} // other
	
	const null_StatisticsProcesses &operator =( const null_StatisticsProcesses &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_StatisticsProcesses::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess > _newVoiceFileStatisticsProcessRtr;
	::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess > _newServiceFileStatisticsProcessRtr;
	::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess > _voiceFileForDecipheringStatisticsProcessRtr;
	::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess > _decipheredVoiceFileAndKeyPairStatisticsProcessRtr;
	::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess > _notDecipheredVoiceFileStatisticsProcessRtr;
	::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess > _resultVoiceFileAndServiceFilePairStatisticsProcessRtr;
	::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess > _resultVoiceFileStatisticsProcessRtr;
	::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess > _retusltServiceFileStatisticsProcessRtr;
	::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess > _deletedVoiceFileStatisticsProcessRtr;
	::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess > _deletedServiceFileStatisticsProcessRtr;
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > _threadContainerRtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_StatisticsProcesses :
	public StatisticsProcesses,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_StatisticsProcesses > {

public:
	// virtuals StatisticsProcesses
	::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess > &takeNewVoiceFileStatisticsProcess() throw() {
		return _newVoiceFileStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess > &takeNewServiceFileStatisticsProcess() throw() {
		return _newServiceFileStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess > &takeVoiceFileForDecipheringStatisticsProcess() throw() {
		return _voiceFileForDecipheringStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess > &takeDecipheredVoiceFileAndKeyPairStatisticsProcess() throw() {
		return _decipheredVoiceFileAndKeyPairStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess > &takeNotDecipheredVoiceFileStatisticsProcess() throw() {
		return _notDecipheredVoiceFileStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess > &takeResultVoiceFileAndServiceFilePairStatisticsProcess() throw() {
		return _resultVoiceFileAndServiceFilePairStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess > &takeResultVoiceFileStatisticsProcess() throw() {
		return _resultVoiceFileStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess > &takeResultServiceFileStatisticsProcess() throw() {
		return _retusltServiceFileStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess > &takeDeletedVoiceFileStatisticsProcess() throw() {
		return _deletedVoiceFileStatisticsProcessRtr;
	}

	::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess > &takeDeletedServiceFileStatisticsProcess() throw() {
		return _deletedServiceFileStatisticsProcessRtr;
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
	~exception_StatisticsProcesses() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_StatisticsProcesses >;
	static exception_StatisticsProcesses *createInstance() throw() {
		return new exception_StatisticsProcesses;
	}

private:
	exception_StatisticsProcesses() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< StatisticsProcesses > createClone() const throw() {
		return ::jmsf::Proxy< StatisticsProcesses >::createUnique( this );
	}

private:
	exception_StatisticsProcesses( const exception_StatisticsProcesses & ) throw() {} // other

	const exception_StatisticsProcesses &operator =( const exception_StatisticsProcesses &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_StatisticsProcesses::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< statistics::NewVoiceFileStatisticsProcess > _newVoiceFileStatisticsProcessRtr;
	::jmsf::Proxy< statistics::NewServiceFileStatisticsProcess > _newServiceFileStatisticsProcessRtr;
	::jmsf::Proxy< statistics::VoiceFileForDecipheringStatisticsProcess > _voiceFileForDecipheringStatisticsProcessRtr;
	::jmsf::Proxy< statistics::DecipheredVoiceFileAndKeyPairStatisticsProcess > _decipheredVoiceFileAndKeyPairStatisticsProcessRtr;
	::jmsf::Proxy< statistics::NotDecipheredVoiceFileStatisticsProcess > _notDecipheredVoiceFileStatisticsProcessRtr;
	::jmsf::Proxy< statistics::ResultVoiceFileAndServiceFilePairStatisticsProcess > _resultVoiceFileAndServiceFilePairStatisticsProcessRtr;
	::jmsf::Proxy< statistics::ResultVoiceFileStatisticsProcess > _resultVoiceFileStatisticsProcessRtr;
	::jmsf::Proxy< statistics::ResultServiceFileStatisticsProcess > _retusltServiceFileStatisticsProcessRtr;
	::jmsf::Proxy< statistics::DeletedVoiceFileStatisticsProcess > _deletedVoiceFileStatisticsProcessRtr;
	::jmsf::Proxy< statistics::DeletedServiceFileStatisticsProcess > _deletedServiceFileStatisticsProcessRtr;
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< ::jmsf::mtf::Thread > > > _threadContainerRtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
StatisticsProcesses *StatisticsProcesses::getNull() throw() {
	return null_StatisticsProcesses::instance();
}

// static
StatisticsProcesses *StatisticsProcesses::getException() throw() {
	return exception_StatisticsProcesses::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace mdm
} // namespace nppntt
