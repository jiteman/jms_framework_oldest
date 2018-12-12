#include "es_Decipher.h"
#include "../data/ed_VoiceFile.h"
#include "../data/ed_Key.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace externals {
namespace software {

class null_es_Decipher :
	public es_Decipher,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_es_Decipher >
{

public:
	// virtuals es_Decipher
	::jmsf::Proxy< externals::data::ed_Key > tryToDecipher( ::jmsf::Proxy< externals::data::ed_VoiceFile >  ) throw() { // voiceFile
		return ::jmsf::Proxy< externals::data::ed_Key >();
	}

	::jmsf::integer getCurrentlyDecipheringVoiceFileProgress() const throw() {
		return ::jmsf::integer( 0 );
	}

	void setStatisticsUpdater( const ::jmsf::Proxy< es_StatisticsUpdater > & ) throw() // statisticsUpdater
	{}

	void setTimeLimit( const ::jmsf::ConstantPointer< _decipherTimeLimit > & ) const throw() // timeLimitData
	{}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_es_Decipher() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_es_Decipher >;
	static null_es_Decipher *createInstance() throw() {
		return new null_es_Decipher;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_es_Decipher() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_Decipher > createClone() const throw() {
		return ::jmsf::Proxy< es_Decipher >::createUnique( this );
	}

private:
	null_es_Decipher( const null_es_Decipher & ) throw() {} // other
	
	const null_es_Decipher &operator =( const null_es_Decipher &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_es_Decipher::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_es_Decipher :
	public es_Decipher,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_es_Decipher > {

public:
	// virtuals es_Decipher
	::jmsf::Proxy< externals::data::ed_Key > tryToDecipher( ::jmsf::Proxy< externals::data::ed_VoiceFile >  ) throw() { // voiceFile
		return ::jmsf::Proxy< externals::data::ed_Key >();
	}

	::jmsf::integer getCurrentlyDecipheringVoiceFileProgress() const throw() {
		return ::jmsf::integer( 0 );
	}

	void setStatisticsUpdater( const ::jmsf::Proxy< es_StatisticsUpdater > & ) throw() // statisticsUpdater
	{}

	void setTimeLimit( const ::jmsf::ConstantPointer< _decipherTimeLimit > & ) const throw() // timeLimitData
	{}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_es_Decipher() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_es_Decipher >;
	static exception_es_Decipher *createInstance() throw() {
		return new exception_es_Decipher;
	}

private:
	exception_es_Decipher() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_Decipher > createClone() const throw() {
		return ::jmsf::Proxy< es_Decipher >::createUnique( this );
	}

private:
	exception_es_Decipher( const exception_es_Decipher & ) throw() {} // other

	const exception_es_Decipher &operator =( const exception_es_Decipher &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_es_Decipher::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
es_Decipher *es_Decipher::getNull() throw() {
	return null_es_Decipher::instance();
}

// static
es_Decipher *es_Decipher::getException() throw() {
	return exception_es_Decipher::instance();
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
