#include "FileSystemControl.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace osie {

class null_FileSystemControl :
	public FileSystemControl,
	public mixins::mixin_null_Object,
	public Singleton< null_FileSystemControl >
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
private: friend Singleton< null_FileSystemControl >;
	static null_FileSystemControl *createInstance() throw() {
		null_FileSystemControl *nullFileSystemControl = new null_FileSystemControl;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullFileSystemControl, MACROS_FILE_AND_LINE ) );
		return nullFileSystemControl;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_FileSystemControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< FileSystemControl > createClone() const throw() {
		return Proxy< FileSystemControl >::createUnique( this );
	}

private:
	null_FileSystemControl( const null_FileSystemControl & ) throw() {} // other
	
	const null_FileSystemControl &operator =( const null_FileSystemControl &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "null_FileSystemControl::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_FileSystemControl :
	public FileSystemControl,
	public mixins::mixin_exception_Object,
	public Singleton< exception_FileSystemControl > {

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
private: friend Singleton< exception_FileSystemControl >;
	static exception_FileSystemControl *createInstance() throw() {
		exception_FileSystemControl *exceptionFileSystemControl = new exception_FileSystemControl;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( exceptionFileSystemControl, MACROS_FILE_AND_LINE ) );
		return exceptionFileSystemControl;
	}

private:
	exception_FileSystemControl() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< FileSystemControl > createClone() const throw() {
		return Proxy< FileSystemControl >::createUnique( this );
	}

private:
	exception_FileSystemControl( const exception_FileSystemControl & ) throw() {} // other

	const exception_FileSystemControl &operator =( const exception_FileSystemControl &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "exception_FileSystemControl::operator =()" );
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
