#include "ResultServiceFileStatisticsProcess.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace statistics {

class null_ResultServiceFileStatisticsProcess :
	public ResultServiceFileStatisticsProcess,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ResultServiceFileStatisticsProcess >
{

public:
	// virtuals ResultServiceFileStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ResultServiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ResultServiceFileStatisticsProcess >;
	static null_ResultServiceFileStatisticsProcess *createInstance() throw() {
		return new null_ResultServiceFileStatisticsProcess;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ResultServiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ResultServiceFileStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< ResultServiceFileStatisticsProcess >::createUnique( this );
	}

private:
	null_ResultServiceFileStatisticsProcess( const null_ResultServiceFileStatisticsProcess & ) throw() {} // other
	
	const null_ResultServiceFileStatisticsProcess &operator =( const null_ResultServiceFileStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ResultServiceFileStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_ResultServiceFileStatisticsProcess :
	public ResultServiceFileStatisticsProcess,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ResultServiceFileStatisticsProcess > {

public:
	// virtuals ResultServiceFileStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ResultServiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ResultServiceFileStatisticsProcess >;
	static exception_ResultServiceFileStatisticsProcess *createInstance() throw() {
		return new exception_ResultServiceFileStatisticsProcess;
	}

private:
	exception_ResultServiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ResultServiceFileStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< ResultServiceFileStatisticsProcess >::createUnique( this );
	}

private:
	exception_ResultServiceFileStatisticsProcess( const exception_ResultServiceFileStatisticsProcess & ) throw() {} // other

	const exception_ResultServiceFileStatisticsProcess &operator =( const exception_ResultServiceFileStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ResultServiceFileStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
ResultServiceFileStatisticsProcess *ResultServiceFileStatisticsProcess::getNull() throw() {
	return null_ResultServiceFileStatisticsProcess::instance();
}

// static
ResultServiceFileStatisticsProcess *ResultServiceFileStatisticsProcess::getException() throw() {
	return exception_ResultServiceFileStatisticsProcess::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace statistics
} // namespace mdm
} // namespace nppntt
