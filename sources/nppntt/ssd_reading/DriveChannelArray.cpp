#include "DriveChannelArray.h"


#include "Configuration.h"

#include "jmsf/osie/runup/Thread.h"


namespace nppntt {
namespace ssd_reading {


// static
::jmsf::Pointer< DriveChannelArray > DriveChannelArray::create() throw() {
	return ::jmsf::Pointer< DriveChannelArray >::createUnique( new DriveChannelArray );
}


DriveChannelArray::~DriveChannelArray() throw() {
	_driveChannels->finalizeRunning();
	_driveChannelRequestDistributors->finalizeRunning();
	_readingChannelRequestDistributionLaunchers->finalizeRunning();
	_requestClearers->finalizeRunning();

	_driveChannels->waitTillFinalizingIsCompleted();
	_driveChannelRequestDistributors->waitTillFinalizingIsCompleted();
	_readingChannelRequestDistributionLaunchers->waitTillFinalizingIsCompleted();
	_requestClearers->waitTillFinalizingIsCompleted();
}

DriveChannelArray::DriveChannelArray() throw()
	:
	_driveChannels( ::jmsf::osie::runup::RunnableArray< DriveChannel >::create() ),
	_driveChannelRequestDistributors( ::jmsf::osie::runup::RunnableArray< DriveChannelRequestDistributor >::create() ),
	_readingChannelRequestDistributionLaunchers( ::jmsf::osie::runup::RunnableArray< ReadingChannelRequestDistributionLauncher >::create() ),
	_requestClearers( ::jmsf::osie::runup::RunnableArray< RequestClearer >::create() ),
	_resultDataGroupCollection( ResultDataGroupCollection::create() )
{
	_wasResultDataCleared = true;
	_isReadingInProgress = false;

	const std::vector< const ::jmsf::natural_size > &driveIndices = Configuration::instance()->getDriveTable().getDriveIndices();

	for ( std::vector< const ::jmsf::natural_size >::const_iterator driveIndexIterator = driveIndices.begin(); driveIndexIterator != driveIndices.end(); ++driveIndexIterator ) {
		::jmsf::Pointer< DriveChannel > driveChannel = DriveChannel::create( *driveIndexIterator, _resultDataGroupCollection );
		_driveChannelRequestDistributors->addRunnable( DriveChannelRequestDistributor::create( driveChannel ) );
		_readingChannelRequestDistributionLaunchers->addRunnable( ReadingChannelRequestDistributionLauncher::create( driveChannel ) );
		_requestClearers->addRunnable( RequestClearer::create( driveChannel ) );
		_driveChannels->addRunnable( driveChannel );
	}

	_driveChannelRequestDistributors->launch();
	_readingChannelRequestDistributionLaunchers->launch();
	_driveChannels->launch();
	_requestClearers->launch();
}

void DriveChannelArray::addAndDistibuteRequestData( const ::jmsf::natural_big quantityOfRequests, const ::jmsf::natural_big *const sourceRequestDataBuffer, const ::jmsf::natural_big *const sourceAlphaValuesBuffer, const ::jmsf::natural_big *const sourceXorValuesBuffer ) throw() {
	_resultDataGroupCollection->resizeIfNeeded( static_cast< ::jmsf::natural_size >( quantityOfRequests ) );

	// create data buffer
	{
		const ::jmsf::natural_big *requestData = sourceRequestDataBuffer;		
		const ::jmsf::natural_big *alphaValues = sourceAlphaValuesBuffer;
		const ::jmsf::natural_big *xorValues = sourceXorValuesBuffer;

		for ( ::jmsf::natural_big requestDataCounter = 0; requestDataCounter < quantityOfRequests; requestDataCounter += 1 ) {
			if ( *requestData != 0 ) {
				_requestData.push_back( SingleRequestData( static_cast< ::jmsf::natural_size >( requestDataCounter ), *requestData, *alphaValues, *xorValues ) );
			}

			requestData += 1;
			alphaValues += 1;
			xorValues += 1;
		}
	}

	// distribute data to drive channel
	{
		DriveChannelRequestDistributor::setRequestDataSeries( _requestData );
		_driveChannelRequestDistributors->continueRunning();
		_driveChannelRequestDistributors->waitTillRunningIsStopped();
		_requestData.clear();
	}

	// distribute data to reading channels
	{
		_readingChannelRequestDistributionLaunchers->continueRunning();
		_readingChannelRequestDistributionLaunchers->waitTillRunningIsStopped();
	}
}

void DriveChannelArray::readDataAndPutItToTheBuffer( const ::jmsf::natural_big sizeOfDestinationBuffer, ::jmsf::natural_big *const destinationBuffer ) throw() {
	// read
	{
		_isReadingInProgress = true;
		_driveChannels->continueRunning();
		_driveChannels->waitTillRunningIsStopped();
	}

	// start clearing of request data
	{
		_requestClearers->continueRunning();
	}

	// put
	{
		::jmsf::natural_big *readedDataPointer = destinationBuffer;
		::jmsf::natural_big readedDataCounter = 0;
		::jmsf::Boolean isSizeLimitReached = ::jmsf::False;

		for ( std::vector< ResultDataGroup >::const_iterator resultDataGroupIterator = _resultDataGroupCollection->getResultDataGroups().begin(); resultDataGroupIterator != _resultDataGroupCollection->getResultDataGroups().end(); ++resultDataGroupIterator ) {
			for ( std::vector< ::jmsf::natural_big >::const_iterator resultDataIterator = resultDataGroupIterator->getResultData().begin(); resultDataIterator != resultDataGroupIterator->getResultData().end(); ++resultDataIterator ) {
				*readedDataPointer++ = *resultDataIterator;

				if ( ++readedDataCounter >= sizeOfDestinationBuffer ) {
					isSizeLimitReached = ::jmsf::True;
					break;
				}
			}

			if ( isSizeLimitReached ) break;
		}

		if ( isSizeLimitReached.not() ) {
			if ( readedDataCounter < sizeOfDestinationBuffer ) {
				*readedDataPointer = 0;
			}
		}

		_resultDataGroupCollection->clear();
	}

	// wait for request data clearing completion
	{
		_requestClearers->waitTillRunningIsStopped();
	}

	_isReadingInProgress = false;

}

DriveChannelArray::DriveChannelArray( const DriveChannelArray & ) throw() // other
	:
		_driveChannels( ::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray< DriveChannel > >::createNone() ),
		_driveChannelRequestDistributors( ::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray< DriveChannelRequestDistributor > >::createNone() ),
		_readingChannelRequestDistributionLaunchers( ::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray< ReadingChannelRequestDistributionLauncher > >::createNone() ),
		_requestClearers( ::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray< RequestClearer > >::createNone() ),
		_resultDataGroupCollection( ::jmsf::Pointer< ResultDataGroupCollection >::createNone() )
{}

const DriveChannelArray &DriveChannelArray::operator =( const DriveChannelArray &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}


} // namespace
}
