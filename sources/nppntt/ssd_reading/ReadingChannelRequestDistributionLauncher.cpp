#include "ReadingChannelRequestDistributionLauncher.h"


#include "DriveChannel.h"


namespace nppntt {
namespace ssd_reading {


void ReadingChannelRequestDistributionLauncher::run() throw( ::jmsf::osie::runup::MOVE_RunnableException, ::jmsf::Exception ) {
	_driveChannel->distributeAddedData();
}


// static
::jmsf::Pointer< ReadingChannelRequestDistributionLauncher > ReadingChannelRequestDistributionLauncher::create( const ::jmsf::Pointer< DriveChannel > &driveChannel ) throw() {
	return ::jmsf::Pointer< ReadingChannelRequestDistributionLauncher >::createUnique( new ReadingChannelRequestDistributionLauncher( driveChannel ) );
}


ReadingChannelRequestDistributionLauncher::~ReadingChannelRequestDistributionLauncher() throw()
{}

ReadingChannelRequestDistributionLauncher::ReadingChannelRequestDistributionLauncher( const ::jmsf::Pointer< DriveChannel > &driveChannel ) throw()
	: _driveChannel( driveChannel )
{}

ReadingChannelRequestDistributionLauncher::ReadingChannelRequestDistributionLauncher( const ReadingChannelRequestDistributionLauncher & ) throw() // other
	: _driveChannel( ::jmsf::Pointer< DriveChannel >::createWeak() )
{}

const ReadingChannelRequestDistributionLauncher &ReadingChannelRequestDistributionLauncher::operator =( const ReadingChannelRequestDistributionLauncher &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}


} // namespace
}
