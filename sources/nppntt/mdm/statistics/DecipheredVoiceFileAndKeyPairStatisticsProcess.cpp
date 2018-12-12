#include "DecipheredVoiceFileAndKeyPairStatisticsProcess.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace statistics {

class null_DecipheredVoiceFileAndKeyPairStatisticsProcess :
	public DecipheredVoiceFileAndKeyPairStatisticsProcess,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_DecipheredVoiceFileAndKeyPairStatisticsProcess >
{

public:
	// virtuals DecipheredVoiceFileAndKeyPairStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_DecipheredVoiceFileAndKeyPairStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_DecipheredVoiceFileAndKeyPairStatisticsProcess >;
	static null_DecipheredVoiceFileAndKeyPairStatisticsProcess *createInstance() throw() {
		return new null_DecipheredVoiceFileAndKeyPairStatisticsProcess;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_DecipheredVoiceFileAndKeyPairStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< DecipheredVoiceFileAndKeyPairStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< DecipheredVoiceFileAndKeyPairStatisticsProcess >::createUnique( this );
	}

private:
	null_DecipheredVoiceFileAndKeyPairStatisticsProcess( const null_DecipheredVoiceFileAndKeyPairStatisticsProcess & ) throw() {} // other
	
	const null_DecipheredVoiceFileAndKeyPairStatisticsProcess &operator =( const null_DecipheredVoiceFileAndKeyPairStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_DecipheredVoiceFileAndKeyPairStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_DecipheredVoiceFileAndKeyPairStatisticsProcess :
	public DecipheredVoiceFileAndKeyPairStatisticsProcess,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_DecipheredVoiceFileAndKeyPairStatisticsProcess > {

public:
	// virtuals DecipheredVoiceFileAndKeyPairStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_DecipheredVoiceFileAndKeyPairStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_DecipheredVoiceFileAndKeyPairStatisticsProcess >;
	static exception_DecipheredVoiceFileAndKeyPairStatisticsProcess *createInstance() throw() {
		return new exception_DecipheredVoiceFileAndKeyPairStatisticsProcess;
	}

private:
	exception_DecipheredVoiceFileAndKeyPairStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< DecipheredVoiceFileAndKeyPairStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< DecipheredVoiceFileAndKeyPairStatisticsProcess >::createUnique( this );
	}

private:
	exception_DecipheredVoiceFileAndKeyPairStatisticsProcess( const exception_DecipheredVoiceFileAndKeyPairStatisticsProcess & ) throw() {} // other

	const exception_DecipheredVoiceFileAndKeyPairStatisticsProcess &operator =( const exception_DecipheredVoiceFileAndKeyPairStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_DecipheredVoiceFileAndKeyPairStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
DecipheredVoiceFileAndKeyPairStatisticsProcess *DecipheredVoiceFileAndKeyPairStatisticsProcess::getNull() throw() {
	return null_DecipheredVoiceFileAndKeyPairStatisticsProcess::instance();
}

// static
DecipheredVoiceFileAndKeyPairStatisticsProcess *DecipheredVoiceFileAndKeyPairStatisticsProcess::getException() throw() {
	return exception_DecipheredVoiceFileAndKeyPairStatisticsProcess::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace statistics
} // namespace mdm
} // namespace nppntt
