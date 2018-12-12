#pragma once

#include "../es_FileAppender.h"
#include "../../others/FileAppender.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/TextString.hxx"

#include "realization_factory_ExternalSoftware.hxx"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace realizations {


class realization_es_FileAppender :
	public es_FileAppender,
	public others::FileAppender,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals FileAppender
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > &takeVoiceFileDataQueue() throw();
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > &takeServiceFileDataQueue() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_es_FileAppender() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ExternalSoftware;
	realization_es_FileAppender(
		const ::jmsf::ConstantProxy< ::jmsf::TextString > &pathToFolderWithFiles,
		::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > voiceFileDataQueue,
		::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > serviceFileDataQueue,
		::jmsf::Proxy< ::jmsf::mtf::Thread > thisThread ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_FileAppender > createClone() const throw();

private:
	realization_es_FileAppender( const realization_es_FileAppender &other ) throw();
	const realization_es_FileAppender &operator =( const realization_es_FileAppender &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > _voiceFileDataQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > _serviceFileDataQueue;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
