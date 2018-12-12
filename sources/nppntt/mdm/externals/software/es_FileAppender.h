#pragma once

#include "jmsf/mtf/Runnable.h"

#include "jmsf/Object.h"

#include "../others/DataTypes.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"
#include "jmsf/PointersAndProxies.hxx"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {


class es_FileAppender :
	public virtual ::jmsf::mtf::Runnable,
	public virtual ::jmsf::Object
{

public:
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > &takeVoiceFileDataQueue() throw() = 0;
	virtual ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Pointer< FileDescriptorData > > > &takeServiceFileDataQueue() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static es_FileAppender *getNull() throw();
	static es_FileAppender *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< es_FileAppender > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
