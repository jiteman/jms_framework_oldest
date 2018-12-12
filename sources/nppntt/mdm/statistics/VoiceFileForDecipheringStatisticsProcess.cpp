#include "VoiceFileForDecipheringStatisticsProcess.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace statistics {

class null_VoiceFileForDecipheringStatisticsProcess :
	public VoiceFileForDecipheringStatisticsProcess,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_VoiceFileForDecipheringStatisticsProcess >
{

public:
	// virtuals VoiceFileForDecipheringStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_VoiceFileForDecipheringStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_VoiceFileForDecipheringStatisticsProcess >;
	static null_VoiceFileForDecipheringStatisticsProcess *createInstance() throw() {
		return new null_VoiceFileForDecipheringStatisticsProcess;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_VoiceFileForDecipheringStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< VoiceFileForDecipheringStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< VoiceFileForDecipheringStatisticsProcess >::createUnique( this );
	}

private:
	null_VoiceFileForDecipheringStatisticsProcess( const null_VoiceFileForDecipheringStatisticsProcess & ) throw() {} // other
	
	const null_VoiceFileForDecipheringStatisticsProcess &operator =( const null_VoiceFileForDecipheringStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_VoiceFileForDecipheringStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_VoiceFileForDecipheringStatisticsProcess :
	public VoiceFileForDecipheringStatisticsProcess,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_VoiceFileForDecipheringStatisticsProcess > {

public:
	// virtuals VoiceFileForDecipheringStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_VoiceFileForDecipheringStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_VoiceFileForDecipheringStatisticsProcess >;
	static exception_VoiceFileForDecipheringStatisticsProcess *createInstance() throw() {
		return new exception_VoiceFileForDecipheringStatisticsProcess;
	}

private:
	exception_VoiceFileForDecipheringStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< VoiceFileForDecipheringStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< VoiceFileForDecipheringStatisticsProcess >::createUnique( this );
	}

private:
	exception_VoiceFileForDecipheringStatisticsProcess( const exception_VoiceFileForDecipheringStatisticsProcess & ) throw() {} // other

	const exception_VoiceFileForDecipheringStatisticsProcess &operator =( const exception_VoiceFileForDecipheringStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_VoiceFileForDecipheringStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
VoiceFileForDecipheringStatisticsProcess *VoiceFileForDecipheringStatisticsProcess::getNull() throw() {
	return null_VoiceFileForDecipheringStatisticsProcess::instance();
}

// static
VoiceFileForDecipheringStatisticsProcess *VoiceFileForDecipheringStatisticsProcess::getException() throw() {
	return exception_VoiceFileForDecipheringStatisticsProcess::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace statistics
} // namespace mdm
} // namespace nppntt
