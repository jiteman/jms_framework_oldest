#pragma once

#include "../factory_MaskDmObjects.h"


namespace nppntt {
namespace mdm {
namespace realizations {


class realization_factory_MaskDmObjects :
	public factory_MaskDmObjects
{

public:
	// virtuals factory_MaskDmObjects
	::jmsf::Proxy< FileFilters > createFileFilters() const throw();
	::jmsf::Proxy< StatisticsQueues > createStatisticsQueues() const throw();
	::jmsf::Proxy< ProcessingQueues > createProcessingQueues() const throw();
	::jmsf::Proxy< ExternalSoftware > createExternalSoftware() const throw( ::jmsf::Exception );

	::jmsf::Proxy< StatisticsProcesses > createStatisticProcesses(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware ) const throw();

	::jmsf::Proxy< ProcessingProcesses > createProcessingProcesses(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< FileFilters > &fileFilters ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_MaskDmObjects() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class factory_MaskDmObjects;
	realization_factory_MaskDmObjects() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_MaskDmObjects( const realization_factory_MaskDmObjects &other ) throw();
	const realization_factory_MaskDmObjects &operator =( const realization_factory_MaskDmObjects &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
