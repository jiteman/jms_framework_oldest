#include "es_VoiceFileAndKeyPairMatchChecker.h"
#include "../data/ed_Key.h"
#include "../data/ed_VoiceFile.h"
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

class null_es_VoiceFileAndKeyPairMatchChecker :
	public es_VoiceFileAndKeyPairMatchChecker,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_es_VoiceFileAndKeyPairMatchChecker >
{

public:
	// virtuals es_VoiceFileAndKeyPairMatchChecker
	void setPair( const ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< data::ed_VoiceFile >, ::jmsf::ConstantProxy< data::ed_Key > > > & ) throw() // voiceFileAndKeyPair
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
	~null_es_VoiceFileAndKeyPairMatchChecker() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_es_VoiceFileAndKeyPairMatchChecker >;
	static null_es_VoiceFileAndKeyPairMatchChecker *createInstance() throw() {
		return new null_es_VoiceFileAndKeyPairMatchChecker;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_es_VoiceFileAndKeyPairMatchChecker() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_VoiceFileAndKeyPairMatchChecker > createClone() const throw() {
		return ::jmsf::Proxy< es_VoiceFileAndKeyPairMatchChecker >::createUnique( this );
	}

private:
	null_es_VoiceFileAndKeyPairMatchChecker( const null_es_VoiceFileAndKeyPairMatchChecker & ) throw() {} // other
	
	const null_es_VoiceFileAndKeyPairMatchChecker &operator =( const null_es_VoiceFileAndKeyPairMatchChecker &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_es_VoiceFileAndKeyPairMatchChecker::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::ConstantProxy< data::ed_Key > _keyCrtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_es_VoiceFileAndKeyPairMatchChecker :
	public es_VoiceFileAndKeyPairMatchChecker,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_es_VoiceFileAndKeyPairMatchChecker > {

public:
	// virtuals es_VoiceFileAndKeyPairMatchChecker
	void setPair( const ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< data::ed_VoiceFile >, ::jmsf::ConstantProxy< data::ed_Key > > > & ) throw() // voiceFileAndKeyPair
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
	~exception_es_VoiceFileAndKeyPairMatchChecker() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_es_VoiceFileAndKeyPairMatchChecker >;
	static exception_es_VoiceFileAndKeyPairMatchChecker *createInstance() throw() {
		return new exception_es_VoiceFileAndKeyPairMatchChecker;
	}

private:
	exception_es_VoiceFileAndKeyPairMatchChecker() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_VoiceFileAndKeyPairMatchChecker > createClone() const throw() {
		return ::jmsf::Proxy< es_VoiceFileAndKeyPairMatchChecker >::createUnique( this );
	}

private:
	exception_es_VoiceFileAndKeyPairMatchChecker( const exception_es_VoiceFileAndKeyPairMatchChecker & ) throw() {} // other

	const exception_es_VoiceFileAndKeyPairMatchChecker &operator =( const exception_es_VoiceFileAndKeyPairMatchChecker &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_es_VoiceFileAndKeyPairMatchChecker::operator =()" );
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
es_VoiceFileAndKeyPairMatchChecker *es_VoiceFileAndKeyPairMatchChecker::getNull() throw() {
	return null_es_VoiceFileAndKeyPairMatchChecker::instance();
}

// static
es_VoiceFileAndKeyPairMatchChecker *es_VoiceFileAndKeyPairMatchChecker::getException() throw() {
	return exception_es_VoiceFileAndKeyPairMatchChecker::instance();
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
