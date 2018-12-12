#include "realization_es_FileAppender.h"
#include "../../data/ed_VoiceFile.h"
#include "../../data/ed_ServiceFile.h"
#include "jmsf/mtf/Thread.h"
#include "jmsf/osie/Event.h"
#include "jmsf/TextString.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace realizations {


::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > &realization_es_FileAppender::takeVoiceFileDataQueue() throw() {
	return _voiceFileDataQueue;
}

::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > &realization_es_FileAppender::takeServiceFileDataQueue() throw() {
	return _serviceFileDataQueue;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_es_FileAppender::~realization_es_FileAppender() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_es_FileAppender::realization_es_FileAppender(
	const ::jmsf::ConstantProxy< ::jmsf::TextString > &pathToFolderWithFiles,
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > voiceFileDataQueue,
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > serviceFileDataQueue,
	::jmsf::Proxy< ::jmsf::mtf::Thread > thisThread ) throw()
	:
		FileAppender(
			pathToFolderWithFiles,
			voiceFileDataQueue.getWeak(),
			serviceFileDataQueue.getWeak(),
			thisThread )
// 		_voiceFileDataQueue( voiceFileDataQueue ),
// 		_serviceFileDataQueue( serviceFileDataQueue )
{
	_voiceFileDataQueue = voiceFileDataQueue;
	_serviceFileDataQueue = serviceFileDataQueue;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< es_FileAppender > realization_es_FileAppender::createClone() const throw() {
	return ::jmsf::Proxy< es_FileAppender >::createUnique( new realization_es_FileAppender( *this ) );
}

realization_es_FileAppender::realization_es_FileAppender( const realization_es_FileAppender & ) throw() // other
	:
		FileAppender(
			::jmsf::CONSTANT_TEXT_STRING( "" ),
			::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > >(),
			::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > >(),
			::jmsf::Proxy< ::jmsf::mtf::Thread >() )
{}

const realization_es_FileAppender &realization_es_FileAppender::operator =( const realization_es_FileAppender &other ) throw() {
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
