#include "FileSystemControl.h"


#include "jmsf/patterning/mixing/mixin_null_Object.h"
#include "jmsf/patterning/mixing/mixin_exception_Object.h"
#include "jmsf/patterning/Singleton.inl"

#include "jmsf/pointing/Proxy.inl"

#include "jmsf/validating/Should.h"
//#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace osie {


class null_FileSystemControl :
	public FileSystemControl,
	public patterning::mixing::mixin_null_Object,
	public patterning::Singleton< null_FileSystemControl >
{

public:
	// virtuals FileSystemControl
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_FileSystemControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend patterning::Singleton< null_FileSystemControl >;
	static null_FileSystemControl *createInstance() throw() {
		null_FileSystemControl *nullFileSystemControl = new null_FileSystemControl;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullFileSystemControl, MACROS_FILE_AND_LINE ) );
		return nullFileSystemControl;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_FileSystemControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< FileSystemControl > createClone() const throw() {
		return pointing::Proxy< FileSystemControl >::createUnique( this );
	}

private:
	null_FileSystemControl( const null_FileSystemControl & ) throw() {} // other
	
	const null_FileSystemControl &operator =( const null_FileSystemControl &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		validating::Should::neverViolateCopyingProhibition( "null_FileSystemControl::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_FileSystemControl :
	public FileSystemControl,
	public patterning::mixing::mixin_exception_Object,
	public patterning::Singleton< exception_FileSystemControl > {

public:
	// virtuals FileSystemControl
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_FileSystemControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend patterning::Singleton< exception_FileSystemControl >;
	static exception_FileSystemControl *createInstance() throw() {
		exception_FileSystemControl *exceptionFileSystemControl = new exception_FileSystemControl;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( exceptionFileSystemControl, MACROS_FILE_AND_LINE ) );
		return exceptionFileSystemControl;
	}

private:
	exception_FileSystemControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< FileSystemControl > createClone() const throw() {
		return pointing::Proxy< FileSystemControl >::createUnique( this );
	}

private:
	exception_FileSystemControl( const exception_FileSystemControl & ) throw() {} // other

	const exception_FileSystemControl &operator =( const exception_FileSystemControl &other ) throw( validating::Exception ) {
		if ( this == &other ) return *this;

		// copy
		validating::Should::neverViolateCopyingProhibition( "exception_FileSystemControl::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
FileSystemControl *FileSystemControl::getNull() throw() {
	return null_FileSystemControl::instance();
}

// static
FileSystemControl *FileSystemControl::getException() throw() {
	return exception_FileSystemControl::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace osie
} // namespace jmsf
