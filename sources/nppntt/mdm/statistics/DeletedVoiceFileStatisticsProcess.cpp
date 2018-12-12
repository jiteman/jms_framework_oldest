#include "DeletedVoiceFileStatisticsProcess.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace statistics {

class null_DeletedVoiceFileStatisticsProcess :
	public DeletedVoiceFileStatisticsProcess,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_DeletedVoiceFileStatisticsProcess >
{

public:
	// virtuals DeletedVoiceFileStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_DeletedVoiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_DeletedVoiceFileStatisticsProcess >;
	static null_DeletedVoiceFileStatisticsProcess *createInstance() throw() {
		return new null_DeletedVoiceFileStatisticsProcess;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_DeletedVoiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< DeletedVoiceFileStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< DeletedVoiceFileStatisticsProcess >::createUnique( this );
	}

private:
	null_DeletedVoiceFileStatisticsProcess( const null_DeletedVoiceFileStatisticsProcess & ) throw() {} // other
	
	const null_DeletedVoiceFileStatisticsProcess &operator =( const null_DeletedVoiceFileStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_DeletedVoiceFileStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_DeletedVoiceFileStatisticsProcess :
	public DeletedVoiceFileStatisticsProcess,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_DeletedVoiceFileStatisticsProcess > {

public:
	// virtuals DeletedVoiceFileStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_DeletedVoiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_DeletedVoiceFileStatisticsProcess >;
	static exception_DeletedVoiceFileStatisticsProcess *createInstance() throw() {
		return new exception_DeletedVoiceFileStatisticsProcess;
	}

private:
	exception_DeletedVoiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< DeletedVoiceFileStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< DeletedVoiceFileStatisticsProcess >::createUnique( this );
	}

private:
	exception_DeletedVoiceFileStatisticsProcess( const exception_DeletedVoiceFileStatisticsProcess & ) throw() {} // other

	const exception_DeletedVoiceFileStatisticsProcess &operator =( const exception_DeletedVoiceFileStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_DeletedVoiceFileStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
DeletedVoiceFileStatisticsProcess *DeletedVoiceFileStatisticsProcess::getNull() throw() {
	return null_DeletedVoiceFileStatisticsProcess::instance();
}

// static
DeletedVoiceFileStatisticsProcess *DeletedVoiceFileStatisticsProcess::getException() throw() {
	return exception_DeletedVoiceFileStatisticsProcess::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace statistics
} // namespace mdm
} // namespace nppntt
