#include "testing_Proxie.h"
#include "jmsf/patterning/mixing/mixin_null_Object.h"
#include "jmsf/patterning/mixing/mixin_exception_Object.h"
#include "jmsf/patterning/Singleton.hpp"

#include "jmsf/pointing/Proxy.inl"
#include "jmsf/memorying/Womp.inl"
#include "jmsf/validating/Should.h"

////#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace testing {


class null_testing_Proxie :
	public testing_Proxie,
	public patterning::mixing::mixin_null_Object,
	public patterning::Singleton< testing_Proxie >
{

public:
	// virtuals testing_Proxie
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_testing_Proxie() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: //friend Singleton< null_testing_Proxie >;
	static null_testing_Proxie *create_singleton_instance() throw() {
		null_testing_Proxie *nullTestingProxie = new null_testing_Proxie;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullTestingProxie, MACROS_FILE_AND_LINE ) );
		return nullTestingProxie;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_testing_Proxie() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
// 	patterning::Proxy< testing_Proxie > createClone() const throw() {
// 		return Proxy< testing_Proxie >::createUnique( this );
// 	}

private:
	null_testing_Proxie( const null_testing_Proxie & ) throw() {} // other
	
	const null_testing_Proxie &operator =( const null_testing_Proxie &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		validating::Should::never_violate_copy_prohibition( "null_testing_Proxie::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_testing_Proxie :
	public testing_Proxie,
	public patterning::mixing::mixin_exception_Object,
	public patterning::Singleton< testing_Proxie > {

public:
	// virtuals testing_Proxie
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_testing_Proxie() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< exception_testing_Proxie >;
	static exception_testing_Proxie *create_singleton_instance() throw() {
		exception_testing_Proxie *exceptionTestingProxie = new exception_testing_Proxie;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( exceptionTestingProxie, MACROS_FILE_AND_LINE ) );
		return exceptionTestingProxie;
	}

private:
	exception_testing_Proxie() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
// 	Proxy< testing_Proxie > createClone() const throw() {
// 		return Proxy< testing_Proxie >::createUnique( this );
// 	}

private:
	exception_testing_Proxie( const exception_testing_Proxie & ) throw() {} // other

	const exception_testing_Proxie &operator =( const exception_testing_Proxie &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		validating::Should::never_violate_copy_prohibition( "exception_testing_Proxie::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
memorying::Womp< testing_Proxie > &testing_Proxie::get_null_object() throw() {
	return null_testing_Proxie::instance();
}

// static
memorying::Womp< testing_Proxie > &testing_Proxie::get_exception_object() throw() {
	return exception_testing_Proxie::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace testing
} // namespace jmsf
