#include "File.h"


#include "jmsf/patterning/mixing/mixin_null_Object.h"
#include "jmsf/patterning/mixing/mixin_exception_Object.h"
#include "jmsf/patterning/Singleton.inl"

#include "jmsf/pointing/Proxy.inl"
#include "jmsf/validating/Should.h"
//#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace osie {


class null_File :
	public File,
	public patterning::mixing::mixin_null_Object,
	public patterning::Singleton< null_File >
{

public:
	// virtuals File
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_File() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend patterning::Singleton< null_File >;
	static null_File *createInstance() throw() {
		null_File *nullFile = new null_File;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullFile, MACROS_FILE_AND_LINE ) );
		return nullFile;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_File() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< File > createClone() const throw() {
		return pointing::Proxy< File >::createUnique( this );
	}

private:
	null_File( const null_File & ) throw() {} // other
	
	const null_File &operator =( const null_File &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		validating::Should::neverViolateCopyingProhibition( "null_File::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_File :
	public File,
	public patterning::mixing::mixin_exception_Object,
	public patterning::Singleton< exception_File > {

public:
	// virtuals File
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_File() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend patterning::Singleton< exception_File >;
	static exception_File *createInstance() throw() {
		exception_File *exceptionFile = new exception_File;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( exceptionFile, MACROS_FILE_AND_LINE ) );
		return exceptionFile;
	}

private:
	exception_File() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< File > createClone() const throw() {
		return pointing::Proxy< File >::createUnique( this );
	}

private:
	exception_File( const exception_File & ) throw() {} // other

	const exception_File &operator =( const exception_File &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		validating::Should::neverViolateCopyingProhibition( "exception_File::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
File *File::getNull() throw() {
	return null_File::instance();
}

// static
File *File::getException() throw() {
	return exception_File::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace osie
} // namespace jmsf
