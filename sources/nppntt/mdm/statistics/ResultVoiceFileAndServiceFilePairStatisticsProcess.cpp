#include "ResultVoiceFileAndServiceFilePairStatisticsProcess.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace statistics {

class null_ResultVoiceFileAndServiceFilePairStatisticsProcess :
	public ResultVoiceFileAndServiceFilePairStatisticsProcess,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ResultVoiceFileAndServiceFilePairStatisticsProcess >
{

public:
	// virtuals ResultVoiceFileAndServiceFilePairStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ResultVoiceFileAndServiceFilePairStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ResultVoiceFileAndServiceFilePairStatisticsProcess >;
	static null_ResultVoiceFileAndServiceFilePairStatisticsProcess *createInstance() throw() {
		return new null_ResultVoiceFileAndServiceFilePairStatisticsProcess;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ResultVoiceFileAndServiceFilePairStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ResultVoiceFileAndServiceFilePairStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< ResultVoiceFileAndServiceFilePairStatisticsProcess >::createUnique( this );
	}

private:
	null_ResultVoiceFileAndServiceFilePairStatisticsProcess( const null_ResultVoiceFileAndServiceFilePairStatisticsProcess & ) throw() {} // other
	
	const null_ResultVoiceFileAndServiceFilePairStatisticsProcess &operator =( const null_ResultVoiceFileAndServiceFilePairStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ResultVoiceFileAndServiceFilePairStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_ResultVoiceFileAndServiceFilePairStatisticsProcess :
	public ResultVoiceFileAndServiceFilePairStatisticsProcess,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ResultVoiceFileAndServiceFilePairStatisticsProcess > {

public:
	// virtuals ResultVoiceFileAndServiceFilePairStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ResultVoiceFileAndServiceFilePairStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ResultVoiceFileAndServiceFilePairStatisticsProcess >;
	static exception_ResultVoiceFileAndServiceFilePairStatisticsProcess *createInstance() throw() {
		return new exception_ResultVoiceFileAndServiceFilePairStatisticsProcess;
	}

private:
	exception_ResultVoiceFileAndServiceFilePairStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ResultVoiceFileAndServiceFilePairStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< ResultVoiceFileAndServiceFilePairStatisticsProcess >::createUnique( this );
	}

private:
	exception_ResultVoiceFileAndServiceFilePairStatisticsProcess( const exception_ResultVoiceFileAndServiceFilePairStatisticsProcess & ) throw() {} // other

	const exception_ResultVoiceFileAndServiceFilePairStatisticsProcess &operator =( const exception_ResultVoiceFileAndServiceFilePairStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ResultVoiceFileAndServiceFilePairStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
ResultVoiceFileAndServiceFilePairStatisticsProcess *ResultVoiceFileAndServiceFilePairStatisticsProcess::getNull() throw() {
	return null_ResultVoiceFileAndServiceFilePairStatisticsProcess::instance();
}

// static
ResultVoiceFileAndServiceFilePairStatisticsProcess *ResultVoiceFileAndServiceFilePairStatisticsProcess::getException() throw() {
	return exception_ResultVoiceFileAndServiceFilePairStatisticsProcess::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace statistics
} // namespace mdm
} // namespace nppntt
