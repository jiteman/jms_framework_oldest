#pragma once

#include "../ServiceFileArray.h"
#include "jmsf/mtf/mixins/mixin_Lockable.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "../../externals/data/ed_FileFilter.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"

#include "realization_factory_ProcessingProcesses.hxx"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

class realization_ServiceFileArray :
	public ServiceFileArray,
	public ::jmsf::mtf::mixins::mixin_Lockable,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals ServiceFileArray
	void append( const ::jmsf::Proxy< externals::data::ed_ServiceFile > &serviceFile ) throw( ::jmsf::Exception );
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &takeAccessToServiceFiles() throw( ::jmsf::Exception );
	void clearExpired() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ServiceFileArray() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ProcessingProcesses;
	realization_ServiceFileArray(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileForDeletingQueue,
		const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter,
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &serviceFiles,
		const ::jmsf::Proxy< ::jmsf::osie::Mutex > &mutex ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ServiceFileArray > createClone() const throw();

private:
	realization_ServiceFileArray( const realization_ServiceFileArray &other ) throw();
	const realization_ServiceFileArray &operator =( const realization_ServiceFileArray &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _destinationServiceFileForDeletingQueue;
	const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > _fileFilter;
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _serviceFileContainer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
