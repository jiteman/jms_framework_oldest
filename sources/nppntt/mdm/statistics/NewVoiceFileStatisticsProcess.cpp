#include "NewVoiceFileStatisticsProcess.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace statistics {

class null_NewVoiceFileStatisticsProcess :
	public NewVoiceFileStatisticsProcess,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_NewVoiceFileStatisticsProcess >
{

public:
	// virtuals NewVoiceFileStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_NewVoiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_NewVoiceFileStatisticsProcess >;
	static null_NewVoiceFileStatisticsProcess *createInstance() throw() {
		return new null_NewVoiceFileStatisticsProcess;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_NewVoiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< NewVoiceFileStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< NewVoiceFileStatisticsProcess >::createUnique( this );
	}

private:
	null_NewVoiceFileStatisticsProcess( const null_NewVoiceFileStatisticsProcess & ) throw() {} // other
	
	const null_NewVoiceFileStatisticsProcess &operator =( const null_NewVoiceFileStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_NewVoiceFileStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_NewVoiceFileStatisticsProcess :
	public NewVoiceFileStatisticsProcess,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_NewVoiceFileStatisticsProcess > {

public:
	// virtuals NewVoiceFileStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_NewVoiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_NewVoiceFileStatisticsProcess >;
	static exception_NewVoiceFileStatisticsProcess *createInstance() throw() {
		return new exception_NewVoiceFileStatisticsProcess;
	}

private:
	exception_NewVoiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< NewVoiceFileStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< NewVoiceFileStatisticsProcess >::createUnique( this );
	}

private:
	exception_NewVoiceFileStatisticsProcess( const exception_NewVoiceFileStatisticsProcess & ) throw() {} // other

	const exception_NewVoiceFileStatisticsProcess &operator =( const exception_NewVoiceFileStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_NewVoiceFileStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
NewVoiceFileStatisticsProcess *NewVoiceFileStatisticsProcess::getNull() throw() {
	return null_NewVoiceFileStatisticsProcess::instance();
}

// static
NewVoiceFileStatisticsProcess *NewVoiceFileStatisticsProcess::getException() throw() {
	return exception_NewVoiceFileStatisticsProcess::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace statistics
} // namespace mdm
} // namespace nppntt
