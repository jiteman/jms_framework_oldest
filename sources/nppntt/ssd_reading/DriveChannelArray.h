#pragma once


#include "DriveChannel.h"
#include "DriveChannelRequestDistributor.h"
#include "ReadingChannelRequestDistributionLauncher.h"
#include "RequestClearer.h"
#include "ResultDataGroupCollection.h"
#include "SingleRequestData.h"

#include "jmsf/osie/runup/RunnableArray.hpp"

#include "jmsf/Pointer.hpp"

#include "jmsf/stdal/stdal_dll.h"


namespace nppntt {
namespace ssd_reading {


class DriveChannelArray {

public:
	static ::jmsf::Pointer< DriveChannelArray > create() throw();

private:
	::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray< DriveChannel > > _driveChannels;
	::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray< DriveChannelRequestDistributor > > _driveChannelRequestDistributors;
	::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray< ReadingChannelRequestDistributionLauncher > > _readingChannelRequestDistributionLaunchers;
	::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray< RequestClearer > > _requestClearers;

	::jmsf::Pointer< ResultDataGroupCollection > _resultDataGroupCollection;
	::jmsf::Boolean _wasResultDataCleared;
	::jmsf::Boolean _isReadingInProgress;

	std::vector< SingleRequestData > _requestData;
	
private:
	friend class ::jmsf::Pointer< DriveChannelArray >;
	~DriveChannelArray() throw();

private:	
	DriveChannelArray() throw();

public:
	void addAndDistibuteRequestData( ::jmsf::natural_big quantityOfRequests, const ::jmsf::natural_big *sourceRequestDataBuffer, const ::jmsf::natural_big *sourceAlphaValuesBuffer, const ::jmsf::natural_big *sourceXorValuesBuffer ) throw();
	void readDataAndPutItToTheBuffer( ::jmsf::natural_big sizeOfDestinationBuffer, ::jmsf::natural_big *destinationBuffer ) throw();	

private:
	DriveChannelArray( const DriveChannelArray &other ) throw();
	const DriveChannelArray &operator =( const DriveChannelArray &other ) throw();

};


} // namespace
}
