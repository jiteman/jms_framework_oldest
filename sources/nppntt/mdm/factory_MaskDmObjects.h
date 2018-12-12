#pragma once

#include "jmsf/Singleton.hpp"

#include "FileFilters.hxx"
#include "StatisticsQueues.hxx"
#include "ProcessingQueues.hxx"
#include "StatisticsProcesses.hxx"
#include "ProcessingProcesses.hxx"
#include "ExternalSoftware.hxx"

#include "jmsf/Proxies.hxx"


namespace nppntt {
namespace mdm {


class factory_MaskDmObjects :
	public ::jmsf::Singleton< factory_MaskDmObjects >
{

public:		
	virtual ::jmsf::Proxy< FileFilters > createFileFilters() const throw() = 0;
	virtual ::jmsf::Proxy< StatisticsQueues > createStatisticsQueues() const throw() = 0;
	virtual ::jmsf::Proxy< ProcessingQueues > createProcessingQueues() const throw() = 0;
	virtual ::jmsf::Proxy< ExternalSoftware > createExternalSoftware() const throw( ::jmsf::Exception ) = 0;

	virtual ::jmsf::Proxy< StatisticsProcesses > createStatisticProcesses(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware ) const throw() = 0;

	virtual ::jmsf::Proxy< ProcessingProcesses > createProcessingProcesses(
		const ::jmsf::Proxy< StatisticsQueues > &statisticsQueues,
		const ::jmsf::Proxy< ProcessingQueues > &processingQueues,
		const ::jmsf::Proxy< ExternalSoftware > &externalSoftware,
		const ::jmsf::Proxy< FileFilters > &fileFilters ) const throw() = 0;
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_MaskDmObjects() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< factory_MaskDmObjects >;
	static factory_MaskDmObjects *createInstance() throw();

protected:
	factory_MaskDmObjects() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_MaskDmObjects( const factory_MaskDmObjects &other ) throw();
	const factory_MaskDmObjects &operator =( const factory_MaskDmObjects &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
