#pragma once

#include "../es_FileAppender.h"

#include "jmsf/osie/runup/mixin_nulls/mixin_null_Runnable.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace nulls {


class null_es_FileAppender :
	public es_FileAppender,
	public ::jmsf::osie::runup::mixin_nulls::mixin_null_Runnable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_es_FileAppender >
{

public:
	// virtuals FileAppender
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, FileDescriptorData > > getOneselfVoiceFileDataQueue() throw();
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, FileDescriptorData > > getOneselfServiceFileDataQueue() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_es_FileAppender() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_es_FileAppender >;
	static null_es_FileAppender *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_es_FileAppender() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_FileAppender > createClone() const throw();

private:
	null_es_FileAppender( const null_es_FileAppender &other ) throw();
	const null_es_FileAppender &operator =( const null_es_FileAppender &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer, FileDescriptorData > > _fileDataQueue;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
