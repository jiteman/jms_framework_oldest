#include "es_FileAppender.h"
#include "../others/abstractFileDescriptor.h"
#include "jmsf/mtf/mixins/mixin_null_Runnable.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/osie/Event.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/PointersAndProxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace externals {
namespace software {

class null_es_FileAppender :
	public es_FileAppender,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_es_FileAppender >
{

public:
	// virtuals es_FileAppender
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > &takeVoiceFileDataQueue() throw() {
		return _fileDescriptorDataQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > &takeServiceFileDataQueue() throw() {
		return _fileDescriptorDataQueueRtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_es_FileAppender() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_es_FileAppender >;
	static null_es_FileAppender *createInstance() throw() {
		return new null_es_FileAppender;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_es_FileAppender() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_FileAppender > createClone() const throw() {
		return ::jmsf::Proxy< es_FileAppender >::createUnique( this );
	}

private:
	null_es_FileAppender( const null_es_FileAppender & ) throw() {} // other
	
	const null_es_FileAppender &operator =( const null_es_FileAppender &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_es_FileAppender::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > _fileDescriptorDataQueueRtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_es_FileAppender :
	public es_FileAppender,
	public ::jmsf::mtf::mixins::mixin_null_Runnable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_es_FileAppender > {

public:
	// virtuals es_FileAppender
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > &takeVoiceFileDataQueue() throw() {
		return _fileDescriptorDataQueueRtr;
	}

	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > &takeServiceFileDataQueue() throw() {
		return _fileDescriptorDataQueueRtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_es_FileAppender() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_es_FileAppender >;
	static exception_es_FileAppender *createInstance() throw() {
		return new exception_es_FileAppender;
	}

private:
	exception_es_FileAppender() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_FileAppender > createClone() const throw() {
		return ::jmsf::Proxy< es_FileAppender >::createUnique( this );
	}

private:
	exception_es_FileAppender( const exception_es_FileAppender & ) throw() {} // other

	const exception_es_FileAppender &operator =( const exception_es_FileAppender &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_es_FileAppender::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
		::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > _fileDescriptorDataQueueRtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
es_FileAppender *es_FileAppender::getNull() throw() {
	return null_es_FileAppender::instance();
}

// static
es_FileAppender *es_FileAppender::getException() throw() {
	return exception_es_FileAppender::instance();
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
