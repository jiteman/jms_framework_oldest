#include "es_ServiceFileAndKeyPairMatchChecker.h"
#include "../data/ed_Key.h"
#include "../data/ed_ServiceFile.h"
#include "jmsf/mtf/mixins/mixin_null_Runnable.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Pair.hpp"
#include "jmsf/Singleton.hpp"
#include "jmsf/PointersAndProxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace externals {
namespace software {

class null_es_ServiceFileAndKeyPairMatchChecker :
	public es_ServiceFileAndKeyPairMatchChecker,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_es_ServiceFileAndKeyPairMatchChecker >
{

public:
	// virtuals es_ServiceFileAndKeyPairMatchChecker
	void setPair( const ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< data::ed_ServiceFile >, ::jmsf::ConstantProxy< data::ed_Key > > > & ) throw() // serviceFileAndKeyPair
	{}

	const ::jmsf::Boolean isPairMatched() const throw() {
		return ::jmsf::False;
	}

	const ::jmsf::ConstantProxy< data::ed_Key > &getTheKey() const throw() {
		return _keyCrtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_es_ServiceFileAndKeyPairMatchChecker() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_es_ServiceFileAndKeyPairMatchChecker >;
	static null_es_ServiceFileAndKeyPairMatchChecker *createInstance() throw() {
		return new null_es_ServiceFileAndKeyPairMatchChecker;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_es_ServiceFileAndKeyPairMatchChecker() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_ServiceFileAndKeyPairMatchChecker > createClone() const throw() {
		return ::jmsf::Proxy< es_ServiceFileAndKeyPairMatchChecker >::createUnique( this );
	}

private:
	null_es_ServiceFileAndKeyPairMatchChecker( const null_es_ServiceFileAndKeyPairMatchChecker & ) throw() {} // other
	
	const null_es_ServiceFileAndKeyPairMatchChecker &operator =( const null_es_ServiceFileAndKeyPairMatchChecker &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_es_ServiceFileAndKeyPairMatchChecker::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::ConstantProxy< data::ed_Key > _keyCrtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_es_ServiceFileAndKeyPairMatchChecker :
	public es_ServiceFileAndKeyPairMatchChecker,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_es_ServiceFileAndKeyPairMatchChecker > {

public:
	// virtuals es_ServiceFileAndKeyPairMatchChecker
	void setPair( const ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< data::ed_ServiceFile >, ::jmsf::ConstantProxy< data::ed_Key > > > & ) throw() // serviceFileAndKeyPair
	{}

	const ::jmsf::Boolean isPairMatched() const throw() {
		return ::jmsf::False;
	}

	const ::jmsf::ConstantProxy< data::ed_Key > &getTheKey() const throw() {
		return _keyCrtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_es_ServiceFileAndKeyPairMatchChecker() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_es_ServiceFileAndKeyPairMatchChecker >;
	static exception_es_ServiceFileAndKeyPairMatchChecker *createInstance() throw() {
		return new exception_es_ServiceFileAndKeyPairMatchChecker;
	}

private:
	exception_es_ServiceFileAndKeyPairMatchChecker() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_ServiceFileAndKeyPairMatchChecker > createClone() const throw() {
		return ::jmsf::Proxy< es_ServiceFileAndKeyPairMatchChecker >::createUnique( this );
	}

private:
	exception_es_ServiceFileAndKeyPairMatchChecker( const exception_es_ServiceFileAndKeyPairMatchChecker & ) throw() {} // other

	const exception_es_ServiceFileAndKeyPairMatchChecker &operator =( const exception_es_ServiceFileAndKeyPairMatchChecker &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_es_ServiceFileAndKeyPairMatchChecker::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::ConstantProxy< data::ed_Key > _keyCrtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
es_ServiceFileAndKeyPairMatchChecker *es_ServiceFileAndKeyPairMatchChecker::getNull() throw() {
	return null_es_ServiceFileAndKeyPairMatchChecker::instance();
}

// static
es_ServiceFileAndKeyPairMatchChecker *es_ServiceFileAndKeyPairMatchChecker::getException() throw() {
	return exception_es_ServiceFileAndKeyPairMatchChecker::instance();
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
