#include "DriveChannel.h"


#include "jmsf/osie/runup/exceptions/exception_RunnableException.h"

#include "Configuration.h"

#include "jmsf/osie/runup/Log.h"

#include "jmsf/factory_TextObject.h"


namespace nppntt {
namespace ssd_reading {


::jmsf::natural_size DriveChannel::getIndexOfDrive() const throw() {
	return _numberOfDriveChannel;
}

::jmsf::natural_size DriveChannel::getQuantityOfAddedData() const throw() {
	return _requests.size();
}

void DriveChannel::addSingleRequest( const SingleRequestData &request ) throw() {
	_requests.push_back( request );
}

void DriveChannel::distributeAddedData() throw() {
	_requests.sort();

	const ::jmsf::natural_size computedQuantityOfRequestsPerChannel = _requests.size() / _readingChannels->getRunnables().size();
	const ::jmsf::natural_size quantityOfRequestsPerSubchannel = computedQuantityOfRequestsPerChannel == 0 ? 1 : computedQuantityOfRequestsPerChannel;

	::std::vector< ::jmsf::Pointer< ReadingChannel > >::iterator readingChannelIterator = _readingChannels->getRunnables().begin();
	const ::std::vector< ::jmsf::Pointer< ReadingChannel > >::const_iterator &readingChannelEnd = _readingChannels->getRunnables().end();
	::jmsf::natural_big requestPerChannelCounter = 0;
	SingleRequestData previousRequestData;

	for ( ::std::list< SingleRequestData >::const_iterator requestDataIterator = _requests.begin(); requestDataIterator != _requests.end(); ++requestDataIterator ) {
		( *readingChannelIterator )->addSingleRequestData( *requestDataIterator );
		requestPerChannelCounter += 1;

		if ( requestPerChannelCounter >= quantityOfRequestsPerSubchannel ) {
			if ( requestDataIterator->getIndexOfFile() != previousRequestData.getIndexOfFile() ) {
				if ( ( readingChannelIterator + 1 ) != readingChannelEnd ) {
					++readingChannelIterator;
				}

				requestPerChannelCounter = 0;
			}
		}

		previousRequestData = *requestDataIterator;
	}
}

void DriveChannel::writeToLog( ::jmsf::osie::runup::Log &log ) const throw() {
	for ( std::list< SingleRequestData >::const_iterator requestDataIterator = _requests.begin(); requestDataIterator != _requests.end(); ++requestDataIterator ) {
		log.put( "Drive: " );
		log.putValue( requestDataIterator->getActuaIndexOfDrive() );
		log.put( " File: " );
		log.putValue( requestDataIterator->getIndexOfFile() );
		log.put( " Position: " );
		log.putValue( requestDataIterator->getDataPosition() );
		log.putEndOfLine();
	}
}

void DriveChannel::clear() throw() {
	_requests.clear();
	clearExceptionInformation();

	std::vector< ::jmsf::Pointer< ReadingChannel > > &readingChannelArray = _readingChannels->getRunnables();

	for ( std::vector< ::jmsf::Pointer< ReadingChannel > >::iterator readingChannelIterator = readingChannelArray.begin(); readingChannelIterator != readingChannelArray.end(); ++readingChannelIterator ) {
		( *readingChannelIterator )->clear();
	}
}

const std::vector< ::jmsf::Pointer< ReadingChannel > > &DriveChannel::getReadingChannels() const throw() {
	return _readingChannels->getRunnables();
}

void DriveChannel::run() throw( ::jmsf::Exception ) {
	_readingChannels->continueRunning();
	_readingChannels->waitTillRunningIsStopped();

	{
		::jmsf::natural_size errorQuantity = 0;

		std::vector< ::jmsf::Pointer< ReadingChannel > > &readingChannelArray = _readingChannels->getRunnables();

		for ( std::vector< ::jmsf::Pointer< ReadingChannel > >::const_iterator readingChannelIterator = readingChannelArray.begin(); readingChannelIterator != readingChannelArray.end(); ++readingChannelIterator ) {
			const ReadingChannel &readingChannel = **readingChannelIterator;

			if ( readingChannel.wasExceptionOccured() ) {
				if ( readingChannel.wasExceptionOccured() ) {
					errorQuantity += 1;
				}
			}
		}

		if ( errorQuantity != 0 ) {
			::jmsf::Proxy< ::jmsf::TextStream > textStream = ::jmsf::factory_TextObject::instance()->createTextStream();
			textStream->put( ::jmsf::CONSTANT_TEXT_STRING( "DriveReadingChannel::run() - error was occured during reading subchannel(s) running" ) );
			throw ::jmsf::osie::runup::exceptions::exception_RunnableException( textStream );
		}
	}	
}


// static
::jmsf::Pointer< DriveChannel > DriveChannel::create( const ::jmsf::natural_size numberOfDriveChannel, const ::jmsf::Pointer< ResultDataGroupCollection > &resultDataGroupCollection ) throw() {
	return ::jmsf::Pointer< DriveChannel >::createUnique( new DriveChannel( numberOfDriveChannel, resultDataGroupCollection ) );
}


DriveChannel::~DriveChannel() throw() {
	_readingChannels->finalizeRunning();
	_readingChannels->waitTillFinalizingIsCompleted();
}

DriveChannel::DriveChannel( const ::jmsf::natural_size numberOfDriveChannel, const ::jmsf::Pointer< ResultDataGroupCollection > &resultDataGroupCollection ) throw()
	: _readingChannels( ::jmsf::osie::runup::RunnableArray< ReadingChannel >::create() )
{
	_numberOfDriveChannel = numberOfDriveChannel;
//	_requests.reserve( MAX_AMOUNT_OF_REQUESTS );

	const ::jmsf::natural_size quantityOfReadingChannels = Configuration::instance()->getQuantityOfReadingChannels();

	for ( ::jmsf::natural_size readingChannelCounter = 0; readingChannelCounter < quantityOfReadingChannels; readingChannelCounter += 1 ) {
		_readingChannels->addRunnable( ReadingChannel::create( readingChannelCounter, resultDataGroupCollection ) );
	}

	_readingChannels->launch();
}

DriveChannel::DriveChannel( const DriveChannel & ) throw() // other
	: _readingChannels( ::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray< ReadingChannel > >::createNone() )
{}

const DriveChannel &DriveChannel::operator =( const DriveChannel &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}


} // namespace
}
