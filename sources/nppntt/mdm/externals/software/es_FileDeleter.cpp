#include "es_FileDeleter.h"
#include "../others/abstractFileDescriptor.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/PointersAndProxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace externals {
namespace software {

class null_es_FileDeleter :
	public es_FileDeleter,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_es_FileDeleter >
{

public:
	// virtuals es_FileDeleter
	void deleteFile(
			::jmsf::Pointer< FileDescriptorData > ,
			::jmsf::Pointer< AppliedData >   ) const throw() // fileData, appliedData
	{}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_es_FileDeleter() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_es_FileDeleter >;
	static null_es_FileDeleter *createInstance() throw() {
		return new null_es_FileDeleter;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_es_FileDeleter() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_FileDeleter > createClone() const throw() {
		return ::jmsf::Proxy< es_FileDeleter >::createUnique( this );
	}

private:
	null_es_FileDeleter( const null_es_FileDeleter & ) throw() {} // other
	
	const null_es_FileDeleter &operator =( const null_es_FileDeleter &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_es_FileDeleter::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_es_FileDeleter :
	public es_FileDeleter,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_es_FileDeleter > {

public:
	// virtuals es_FileDeleter
	void deleteFile(
			::jmsf::Pointer< FileDescriptorData > ,
			::jmsf::Pointer< AppliedData >   ) const throw() // fileData, appliedData
	{}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_es_FileDeleter() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_es_FileDeleter >;
	static exception_es_FileDeleter *createInstance() throw() {
		return new exception_es_FileDeleter;
	}

private:
	exception_es_FileDeleter() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_FileDeleter > createClone() const throw() {
		return ::jmsf::Proxy< es_FileDeleter >::createUnique( this );
	}

private:
	exception_es_FileDeleter( const exception_es_FileDeleter & ) throw() {} // other

	const exception_es_FileDeleter &operator =( const exception_es_FileDeleter &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_es_FileDeleter::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
es_FileDeleter *es_FileDeleter::getNull() throw() {
	return null_es_FileDeleter::instance();
}

// static
es_FileDeleter *es_FileDeleter::getException() throw() {
	return exception_es_FileDeleter::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace software
} // namespace externals
} // namespace mdm
} // namespace nppntt
