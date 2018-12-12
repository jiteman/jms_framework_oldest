#include "DeletedServiceFileStatisticsProcess.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace statistics {

class null_DeletedServiceFileStatisticsProcess :
	public DeletedServiceFileStatisticsProcess,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_DeletedServiceFileStatisticsProcess >
{

public:
	// virtuals DeletedServiceFileStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_DeletedServiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_DeletedServiceFileStatisticsProcess >;
	static null_DeletedServiceFileStatisticsProcess *createInstance() throw() {
		return new null_DeletedServiceFileStatisticsProcess;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_DeletedServiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< DeletedServiceFileStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< DeletedServiceFileStatisticsProcess >::createUnique( this );
	}

private:
	null_DeletedServiceFileStatisticsProcess( const null_DeletedServiceFileStatisticsProcess & ) throw() {} // other
	
	const null_DeletedServiceFileStatisticsProcess &operator =( const null_DeletedServiceFileStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_DeletedServiceFileStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_DeletedServiceFileStatisticsProcess :
	public DeletedServiceFileStatisticsProcess,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_DeletedServiceFileStatisticsProcess > {

public:
	// virtuals DeletedServiceFileStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_DeletedServiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_DeletedServiceFileStatisticsProcess >;
	static exception_DeletedServiceFileStatisticsProcess *createInstance() throw() {
		return new exception_DeletedServiceFileStatisticsProcess;
	}

private:
	exception_DeletedServiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< DeletedServiceFileStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< DeletedServiceFileStatisticsProcess >::createUnique( this );
	}

private:
	exception_DeletedServiceFileStatisticsProcess( const exception_DeletedServiceFileStatisticsProcess & ) throw() {} // other

	const exception_DeletedServiceFileStatisticsProcess &operator =( const exception_DeletedServiceFileStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_DeletedServiceFileStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
DeletedServiceFileStatisticsProcess *DeletedServiceFileStatisticsProcess::getNull() throw() {
	return null_DeletedServiceFileStatisticsProcess::instance();
}

// static
DeletedServiceFileStatisticsProcess *DeletedServiceFileStatisticsProcess::getException() throw() {
	return exception_DeletedServiceFileStatisticsProcess::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace statistics
} // namespace mdm
} // namespace nppntt
