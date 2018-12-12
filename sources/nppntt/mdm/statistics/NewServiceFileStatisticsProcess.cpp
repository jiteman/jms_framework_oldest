#include "NewServiceFileStatisticsProcess.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace statistics {

class null_NewServiceFileStatisticsProcess :
	public NewServiceFileStatisticsProcess,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_NewServiceFileStatisticsProcess >
{

public:
	// virtuals NewServiceFileStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_NewServiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_NewServiceFileStatisticsProcess >;
	static null_NewServiceFileStatisticsProcess *createInstance() throw() {
		return new null_NewServiceFileStatisticsProcess;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_NewServiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< NewServiceFileStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< NewServiceFileStatisticsProcess >::createUnique( this );
	}

private:
	null_NewServiceFileStatisticsProcess( const null_NewServiceFileStatisticsProcess & ) throw() {} // other
	
	const null_NewServiceFileStatisticsProcess &operator =( const null_NewServiceFileStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_NewServiceFileStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_NewServiceFileStatisticsProcess :
	public NewServiceFileStatisticsProcess,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_NewServiceFileStatisticsProcess > {

public:
	// virtuals NewServiceFileStatisticsProcess
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_NewServiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_NewServiceFileStatisticsProcess >;
	static exception_NewServiceFileStatisticsProcess *createInstance() throw() {
		return new exception_NewServiceFileStatisticsProcess;
	}

private:
	exception_NewServiceFileStatisticsProcess() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< NewServiceFileStatisticsProcess > createClone() const throw() {
		return ::jmsf::Proxy< NewServiceFileStatisticsProcess >::createUnique( this );
	}

private:
	exception_NewServiceFileStatisticsProcess( const exception_NewServiceFileStatisticsProcess & ) throw() {} // other

	const exception_NewServiceFileStatisticsProcess &operator =( const exception_NewServiceFileStatisticsProcess &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_NewServiceFileStatisticsProcess::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
NewServiceFileStatisticsProcess *NewServiceFileStatisticsProcess::getNull() throw() {
	return null_NewServiceFileStatisticsProcess::instance();
}

// static
NewServiceFileStatisticsProcess *NewServiceFileStatisticsProcess::getException() throw() {
	return exception_NewServiceFileStatisticsProcess::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace statistics
} // namespace mdm
} // namespace nppntt
