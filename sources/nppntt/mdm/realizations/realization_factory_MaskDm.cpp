#include "realization_factory_MaskDm.h"

#include "../factory_MaskDmObjects.h"
#include "../FileFilters.h"
#include "../StatisticsQueues.h"
#include "../ProcessingQueues.h"
#include "../StatisticsProcesses.h"
#include "../ProcessingProcesses.h"
#include "../ExternalSoftware.h"

#include "realization_MaskDm.h"

#include "jmsf/assisting/flyweight_factory_Functor.hpp"
#include "jmsf/assists/Functors.hpp"
#include "jmsf/mtf/Thread.h"
#include "jmsf/Container.hpp"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace realizations {

::jmsf::Proxy< MaskDm > realization_factory_MaskDm::createMaskDm() const throw() {
	const ::jmsf::Proxy< FileFilters > fileFilters = factory_MaskDmObjects::instance()->createFileFilters();
	const ::jmsf::Proxy< StatisticsQueues > statisticsQueues = factory_MaskDmObjects::instance()->createStatisticsQueues();
	const ::jmsf::Proxy< ProcessingQueues > processingQueues = factory_MaskDmObjects::instance()->createProcessingQueues();
	const ::jmsf::Proxy< ExternalSoftware > externalSoftware = factory_MaskDmObjects::instance()->createExternalSoftware();

	const ::jmsf::Proxy< StatisticsProcesses > statisticsProcesses =
		factory_MaskDmObjects::instance()->createStatisticProcesses(
			statisticsQueues.getWeak(),
			processingQueues.getWeak(),
			externalSoftware.getWeak() );

	const ::jmsf::Proxy< ProcessingProcesses > processingProcesses =
		factory_MaskDmObjects::instance()->createProcessingProcesses(
			statisticsQueues.getWeak(),
			processingQueues.getWeak(),
			externalSoftware.getWeak(),
			fileFilters.getWeak() );

	return ::jmsf::Proxy< MaskDm >::createUnique(
		new realization_MaskDm(
			fileFilters,
			statisticsQueues,
			processingQueues,
			statisticsProcesses,
			processingProcesses,
			externalSoftware,
			::jmsf::assisting::flyweight_factory_Functor< ::jmsf::Proxy< ::jmsf::mtf::Thread > >::instance()->createFunctor( &::jmsf::mtf::Thread::launch ),
			::jmsf::assisting::flyweight_factory_Functor< ::jmsf::Proxy< ::jmsf::mtf::Thread > >::instance()->createFunctor( &::jmsf::mtf::Thread::resume ),
			::jmsf::assisting::flyweight_factory_Functor< ::jmsf::Proxy< ::jmsf::mtf::Thread > >::instance()->createFunctor( &::jmsf::mtf::Thread::suspend ),
			::jmsf::assisting::flyweight_factory_Functor< ::jmsf::Proxy< ::jmsf::mtf::Thread > >::instance()->createConstantFunctor( &::jmsf::mtf::Thread::waitTillIsSuspended ),
			::jmsf::assisting::flyweight_factory_Functor< ::jmsf::Proxy< ::jmsf::mtf::Thread > >::instance()->createConstantFunctor( &::jmsf::mtf::Thread::waitTillTerminatingIsCompleted ) ) );

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_factory_MaskDm::~realization_factory_MaskDm() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_MaskDm::realization_factory_MaskDm() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_MaskDm::realization_factory_MaskDm( const realization_factory_MaskDm & ) throw() // other
{}

const realization_factory_MaskDm &realization_factory_MaskDm::operator =( const realization_factory_MaskDm &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
