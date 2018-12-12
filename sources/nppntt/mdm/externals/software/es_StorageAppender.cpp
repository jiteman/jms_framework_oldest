#include "es_StorageAppender.h"
#include "../data/ed_VoiceFile.h"
#include "../data/ed_ServiceFile.h"
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

class null_es_StorageAppender :
	public es_StorageAppender,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_es_StorageAppender >
{

public:
	// virtuals es_StorageAppender
	void store( const ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::ConstantProxy< data::ed_VoiceFile >, ::jmsf::Proxy< data::ed_ServiceFile > > > & ) throw() // voiceFileAndServiceFilePair
	{}

	void store( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
	{}

	void store( const ::jmsf::Proxy< data::ed_ServiceFile > & ) throw() // serviceFile
	{}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_es_StorageAppender() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_es_StorageAppender >;
	static null_es_StorageAppender *createInstance() throw() {
		return new null_es_StorageAppender;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_es_StorageAppender() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_StorageAppender > createClone() const throw() {
		return ::jmsf::Proxy< es_StorageAppender >::createUnique( this );
	}

private:
	null_es_StorageAppender( const null_es_StorageAppender & ) throw() {} // other
	
	const null_es_StorageAppender &operator =( const null_es_StorageAppender &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_es_StorageAppender::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_es_StorageAppender :
	public es_StorageAppender,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_es_StorageAppender > {

public:
	// virtuals es_StorageAppender
	void store( const ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::ConstantProxy< data::ed_VoiceFile >, ::jmsf::Proxy< data::ed_ServiceFile > > > & ) throw() // voiceFileAndServiceFilePair
	{}

	void store( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
	{}

	void store( const ::jmsf::Proxy< data::ed_ServiceFile > & ) throw() // serviceFile
	{}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_es_StorageAppender() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_es_StorageAppender >;
	static exception_es_StorageAppender *createInstance() throw() {
		return new exception_es_StorageAppender;
	}

private:
	exception_es_StorageAppender() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_StorageAppender > createClone() const throw() {
		return ::jmsf::Proxy< es_StorageAppender >::createUnique( this );
	}

private:
	exception_es_StorageAppender( const exception_es_StorageAppender & ) throw() {} // other

	const exception_es_StorageAppender &operator =( const exception_es_StorageAppender &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_es_StorageAppender::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
es_StorageAppender *es_StorageAppender::getNull() throw() {
	return null_es_StorageAppender::instance();
}

// static
es_StorageAppender *es_StorageAppender::getException() throw() {
	return exception_es_StorageAppender::instance();
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
