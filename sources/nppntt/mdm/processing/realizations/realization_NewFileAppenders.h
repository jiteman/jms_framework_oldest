#pragma once

#include "../NewFileAppenders.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/PointersAndProxies.hpp"

#include "../../externals/data/ed_VoiceFile.hxx"
#include "../../externals/data/ed_ServiceFile.hxx"
#include "../../externals/software/es_FileAppender.hxx"

#include "jmsf/mtf/SynchronizedQueue.hxx"
#include "jmsf/Container.hxx"


#include "realization_factory_ProcessingProcesses.hxx"


namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {


class realization_NewFileAppenders :
	public NewFileAppenders,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals Runnable
	void run() throw( ::jmsf::Exception );
	//~virtuals

	// virtuals NewFileAppenders
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_NewFileAppenders() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ProcessingProcesses;
	realization_NewFileAppenders(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::software::es_FileAppender > > > &fileAppenderContainer ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< NewFileAppenders > createClone() const throw();

private:
	realization_NewFileAppenders( const realization_NewFileAppenders &other ) throw();
	const realization_NewFileAppenders &operator =( const realization_NewFileAppenders &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > _destinationVoiceFileQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _destinationServiceFileQueue;
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::software::es_FileAppender > > > _fileAppenderContainer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
