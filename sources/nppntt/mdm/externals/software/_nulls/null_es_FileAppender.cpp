#include "null_es_FileAppender.h"
#include "../../others/abstractFileDescriptor.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace nulls {


::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, FileDescriptorData > > null_es_FileAppender::getOneselfVoiceFileDataQueue() throw() {
	return _fileDataQueue.getWeak();
}

::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, FileDescriptorData > > null_es_FileAppender::getOneselfServiceFileDataQueue() throw() {
	return _fileDataQueue.getWeak();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_es_FileAppender::~null_es_FileAppender() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_es_FileAppender *null_es_FileAppender::createInstance() throw() {
	return new null_es_FileAppender;
}

null_es_FileAppender::null_es_FileAppender() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< es_FileAppender > null_es_FileAppender::createClone() const throw() {
	return ::jmsf::Proxy< es_FileAppender >::createUnique( this );
}

null_es_FileAppender::null_es_FileAppender( const null_es_FileAppender & ) throw() // other
{}

const null_es_FileAppender &null_es_FileAppender::operator =( const null_es_FileAppender &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
}
}
