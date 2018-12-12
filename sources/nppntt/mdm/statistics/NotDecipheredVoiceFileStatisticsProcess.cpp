#include "NotDecipheredVoiceFileStatisticsProcess.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace statistics {

class null_NotDecipheredVoiceFileStatisticsProcess :
	public NotDecipheredVoiceFileStatisticsProcess,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_NotDecipheredVoiceFileStatisticsProcess >
{

public:
	// virtuals NotDecipheredVoiceFileStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_NotDecipheredVoiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_NotDecipheredVoiceFileStatisticsProcess >;
	static null_NotDecipheredVoiceFileStatisticsProcess *createInstance() throw() {
		return new null_NotDecipheredVoiceFileStatisticsProcess;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_NotDecipheredVoiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< NotDecipheredVoiceFileStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< NotDecipheredVoiceFileStatisticsProcess >::createUnique( this );
	}

private:
	null_NotDecipheredVoiceFileStatisticsProcess( const null_NotDecipheredVoiceFileStatisticsProcess & ) throw() {} // other
	
	const null_NotDecipheredVoiceFileStatisticsProcess &operator =( const null_NotDecipheredVoiceFileStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_NotDecipheredVoiceFileStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_NotDecipheredVoiceFileStatisticsProcess :
	public NotDecipheredVoiceFileStatisticsProcess,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_NotDecipheredVoiceFileStatisticsProcess > {

public:
	// virtuals NotDecipheredVoiceFileStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_NotDecipheredVoiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_NotDecipheredVoiceFileStatisticsProcess >;
	static exception_NotDecipheredVoiceFileStatisticsProcess *createInstance() throw() {
		return new exception_NotDecipheredVoiceFileStatisticsProcess;
	}

private:
	exception_NotDecipheredVoiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< NotDecipheredVoiceFileStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< NotDecipheredVoiceFileStatisticsProcess >::createUnique( this );
	}

private:
	exception_NotDecipheredVoiceFileStatisticsProcess( const exception_NotDecipheredVoiceFileStatisticsProcess & ) throw() {} // other

	const exception_NotDecipheredVoiceFileStatisticsProcess &operator =( const exception_NotDecipheredVoiceFileStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_NotDecipheredVoiceFileStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
NotDecipheredVoiceFileStatisticsProcess *NotDecipheredVoiceFileStatisticsProcess::getNull() throw() {
	return null_NotDecipheredVoiceFileStatisticsProcess::instance();
}

// static
NotDecipheredVoiceFileStatisticsProcess *NotDecipheredVoiceFileStatisticsProcess::getException() throw() {
	return exception_NotDecipheredVoiceFileStatisticsProcess::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace statistics
} // namespace mdm
} // namespace nppntt
