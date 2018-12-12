#pragma once

#include "../ServiceFileDeleter.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "../../externals/software/es_FileDeleter.hxx"
#include "../../externals/data/ed_ServiceFile.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"

#include "realization_factory_ProcessingProcesses.hxx"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

class realization_ServiceFileDeleter :
	public ServiceFileDeleter,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals ServiceFileDeleter
	
	//~virtuals

	// virtuals MOVE_Runnable
	void run() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ServiceFileDeleter() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ProcessingProcesses;
	realization_ServiceFileDeleter(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &sourceServiceFileQueue,
		const ::jmsf::Proxy< externals::software::es_FileDeleter > &fileDeleter ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ServiceFileDeleter > createClone() const throw();

private:
	realization_ServiceFileDeleter( const realization_ServiceFileDeleter &other ) throw();
	const realization_ServiceFileDeleter &operator =( const realization_ServiceFileDeleter &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _sourceServiceFileQueue;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	::jmsf::Proxy< externals::software::es_FileDeleter > _fileDeleter;

};


} // namespace
}
}
}
