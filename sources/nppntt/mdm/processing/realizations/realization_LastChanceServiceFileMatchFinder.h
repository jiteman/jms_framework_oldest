#pragma once

#include "../LastChanceServiceFileMatchFinder.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "../../externals/data/ed_ServiceFile.hxx"
#include "../../externals/software/es_ServiceFileAndKeyPairMatchChecker.hxx"
#include "../KeyArray.hxx"
#include "jmsf/mtf/SynchronizedQueue.hxx"
#include "jmsf/Container.hxx"

#include "realization_factory_ProcessingProcesses.hxx"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

class realization_LastChanceServiceFileMatchFinder :
	public LastChanceServiceFileMatchFinder,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals LastChanceServiceFileMatchFinder
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals Runnable
	void run() throw( ::jmsf::Exception );
	//~virtuals
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_LastChanceServiceFileMatchFinder() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ProcessingProcesses;
	realization_LastChanceServiceFileMatchFinder(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &sourceServiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileWithMatchFoundQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileForDeletingQueue,
		const ::jmsf::Proxy< KeyArray > &keyArray,
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::software::es_ServiceFileAndKeyPairMatchChecker > > > &serviceFileAndKeyPairMatchCheckerArray ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< LastChanceServiceFileMatchFinder > createClone() const throw();

private:
	realization_LastChanceServiceFileMatchFinder( const realization_LastChanceServiceFileMatchFinder &other ) throw();
	const realization_LastChanceServiceFileMatchFinder &operator =( const realization_LastChanceServiceFileMatchFinder &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _sourceServiceFileQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _destinationServiceFileWithMatchFoundQueue;
	::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > _destinationServiceFileForDeletingQueue;
	::jmsf::Proxy< KeyArray > _keyArray;
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::software::es_ServiceFileAndKeyPairMatchChecker > > > _serviceFileAndKeyPairMatchCheckerArray;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const ::jmsf::natural_size AMOUNT_OF_LAST_KEYS_TO_APPLY = 1000;

};

} // namespace
}
}
}
