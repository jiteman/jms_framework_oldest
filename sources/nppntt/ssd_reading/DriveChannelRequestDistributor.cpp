#include "DriveChannelRequestDistributor.h"


#include "DriveChannel.h"
#include "Configuration.h"


namespace nppntt {
namespace ssd_reading {


const std::vector< SingleRequestData > *DriveChannelRequestDistributor::_requestDataSeries = nullptr;


// static
void DriveChannelRequestDistributor::setRequestDataSeries( const std::vector< SingleRequestData > &requestDataSeries ) throw() {
	_requestDataSeries = &requestDataSeries;
}


void DriveChannelRequestDistributor::run() throw( ::jmsf::osie::runup::MOVE_RunnableException, ::jmsf::Exception ) {
	const ::jmsf::natural_size quantityOfFiles = Configuration::instance()->getVirtualFileTable().getQuantity();
	const ::jmsf::natural_size numberOfDriveChannel = _driveChannel->getIndexOfDrive();

	for ( std::vector< SingleRequestData >::const_iterator requestDataIterator = _requestDataSeries->begin(); requestDataIterator != _requestDataSeries->end(); ++requestDataIterator ) {
		if ( ::jmsf::Boolean( requestDataIterator->getActuaIndexOfDrive() == numberOfDriveChannel ).and( requestDataIterator->getIndexOfFile() < quantityOfFiles ) ) {
			_driveChannel->addSingleRequest( *requestDataIterator );
		}
	}	
}


// static
::jmsf::Pointer< DriveChannelRequestDistributor > DriveChannelRequestDistributor::create(  const ::jmsf::Pointer< DriveChannel > &driveChannel ) throw() {
	return ::jmsf::Pointer< DriveChannelRequestDistributor >::createUnique( new DriveChannelRequestDistributor( driveChannel ) );
}


DriveChannelRequestDistributor::~DriveChannelRequestDistributor() throw()
{}

DriveChannelRequestDistributor::DriveChannelRequestDistributor( const ::jmsf::Pointer< DriveChannel > &driveChannel ) throw()
	: _driveChannel( driveChannel )
{}

DriveChannelRequestDistributor::DriveChannelRequestDistributor( const DriveChannelRequestDistributor & ) throw() // other
	: _driveChannel( ::jmsf::Pointer< DriveChannel >::createWeak() )
{}

const DriveChannelRequestDistributor &DriveChannelRequestDistributor::operator =( const DriveChannelRequestDistributor &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}


} // namespace
}
