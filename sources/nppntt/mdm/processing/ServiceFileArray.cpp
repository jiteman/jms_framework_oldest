#include "ServiceFileArray.h"
#include "../externals/data/ed_ServiceFile.h"
#include "jmsf/mtf/mixins/mixin_null_Lockable.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Container.hpp"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace processing {

class null_ServiceFileArray :
	public ServiceFileArray,
	public ::jmsf::mtf::mixins::mixin_null_Lockable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ServiceFileArray >
{

public:
	// virtuals ServiceFileArray
	void append( const ::jmsf::Proxy< externals::data::ed_ServiceFile > & ) throw( ::jmsf::Exception ) {} // serviceFile

	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeAccessToServiceFiles() throw( ::jmsf::Exception ) {
		return _serviceFileContainerRtr;
	}

	void clearExpired() throw( ::jmsf::Exception ) {}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ServiceFileArray() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ServiceFileArray >;
	static null_ServiceFileArray *createInstance() throw() {
		return new null_ServiceFileArray;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ServiceFileArray() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ServiceFileArray > createClone() const throw() {
		return ::jmsf::Proxy< ServiceFileArray >::createUnique( this );
	}

private:
	null_ServiceFileArray( const null_ServiceFileArray & ) throw() {} // other
	
	const null_ServiceFileArray &operator =( const null_ServiceFileArray &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ServiceFileArray::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _serviceFileContainerRtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_ServiceFileArray :
	public ServiceFileArray,
	public ::jmsf::mtf::mixins::mixin_null_Lockable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ServiceFileArray > {

public:
	// virtuals ServiceFileArray
	void append( const ::jmsf::Proxy< externals::data::ed_ServiceFile > & ) throw( ::jmsf::Exception ) {} // serviceFile

	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeAccessToServiceFiles() throw( ::jmsf::Exception ) {
		return _serviceFileContainerRtr;
	}

	void clearExpired() throw( ::jmsf::Exception ) {}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ServiceFileArray() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ServiceFileArray >;
	static exception_ServiceFileArray *createInstance() throw() {
		return new exception_ServiceFileArray;
	}

private:
	exception_ServiceFileArray() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ServiceFileArray > createClone() const throw() {
		return ::jmsf::Proxy< ServiceFileArray >::createUnique( this );
	}

private:
	exception_ServiceFileArray( const exception_ServiceFileArray & ) throw() {} // other

	const exception_ServiceFileArray &operator =( const exception_ServiceFileArray &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ServiceFileArray::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _serviceFileContainerRtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
ServiceFileArray *ServiceFileArray::getNull() throw() {
	return null_ServiceFileArray::instance();
}

// static
ServiceFileArray *ServiceFileArray::getException() throw() {
	return exception_ServiceFileArray::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace processing
} // namespace mdm
} // namespace nppntt
