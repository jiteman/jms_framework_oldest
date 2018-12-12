#include "ResultVoiceFileStatisticsProcess.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace statistics {

class null_ResultVoiceFileStatisticsProcess :
	public ResultVoiceFileStatisticsProcess,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ResultVoiceFileStatisticsProcess >
{

public:
	// virtuals ResultVoiceFileStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ResultVoiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ResultVoiceFileStatisticsProcess >;
	static null_ResultVoiceFileStatisticsProcess *createInstance() throw() {
		return new null_ResultVoiceFileStatisticsProcess;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ResultVoiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ResultVoiceFileStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< ResultVoiceFileStatisticsProcess >::createUnique( this );
	}

private:
	null_ResultVoiceFileStatisticsProcess( const null_ResultVoiceFileStatisticsProcess & ) throw() {} // other
	
	const null_ResultVoiceFileStatisticsProcess &operator =( const null_ResultVoiceFileStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ResultVoiceFileStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_ResultVoiceFileStatisticsProcess :
	public ResultVoiceFileStatisticsProcess,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ResultVoiceFileStatisticsProcess > {

public:
	// virtuals ResultVoiceFileStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ResultVoiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ResultVoiceFileStatisticsProcess >;
	static exception_ResultVoiceFileStatisticsProcess *createInstance() throw() {
		return new exception_ResultVoiceFileStatisticsProcess;
	}

private:
	exception_ResultVoiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ResultVoiceFileStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< ResultVoiceFileStatisticsProcess >::createUnique( this );
	}

private:
	exception_ResultVoiceFileStatisticsProcess( const exception_ResultVoiceFileStatisticsProcess & ) throw() {} // other

	const exception_ResultVoiceFileStatisticsProcess &operator =( const exception_ResultVoiceFileStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ResultVoiceFileStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
ResultVoiceFileStatisticsProcess *ResultVoiceFileStatisticsProcess::getNull() throw() {
	return null_ResultVoiceFileStatisticsProcess::instance();
}

// static
ResultVoiceFileStatisticsProcess *ResultVoiceFileStatisticsProcess::getException() throw() {
	return exception_ResultVoiceFileStatisticsProcess::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace statistics
} // namespace mdm
} // namespace nppntt
