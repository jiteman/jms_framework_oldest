#pragma once

#include "../NewServiceFileDispatcher.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "../../externals/data/ed_FileFilter.hxx"
#include "../../externals/data/ed_ServiceFile.hxx"
#include "../ServiceFileArray.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"

#include "realization_factory_ProcessingProcesses.hxx"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

class realization_NewServiceFileDispatcher :
	public NewServiceFileDispatcher,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals NewServiceFileDispatcher
	
	//~virtuals

	// virtuals MOVE_Runnable
	void run() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_NewServiceFileDispatcher() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ProcessingProcesses;
	realization_NewServiceFileDispatcher(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &sourceServiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileForDeletionQueue,
		const ::jmsf::Proxy< ServiceFileArray > &serviceFileArray,
		const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< NewServiceFileDispatcher > createClone() const throw();

private:
	realization_NewServiceFileDispatcher( const realization_NewServiceFileDispatcher &other ) throw();
	const realization_NewServiceFileDispatcher &operator =( const realization_NewServiceFileDispatcher &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _sourceServiceFileQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _destinationServiceFileForDeletionQueue;
	::jmsf::Proxy< ServiceFileArray > _serviceFileArray;
	const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > _fileFilter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
