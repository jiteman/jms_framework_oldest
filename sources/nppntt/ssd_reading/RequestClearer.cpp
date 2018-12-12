#include "RequestClearer.h"


#include "DriveChannel.h"


namespace nppntt {
namespace ssd_reading {


void RequestClearer::run() throw( ::jmsf::osie::runup::MOVE_RunnableException, ::jmsf::Exception ) {
	_driveChannel->clear();
}


// static
::jmsf::Pointer< RequestClearer > RequestClearer::create( const ::jmsf::Pointer< DriveChannel > &driveChannel ) throw() {
	return ::jmsf::Pointer< RequestClearer >::createUnique( new RequestClearer( driveChannel ) );
}


RequestClearer::~RequestClearer() throw()
{}

RequestClearer::RequestClearer( const ::jmsf::Pointer< DriveChannel > &driveChannel ) throw()
	: _driveChannel( driveChannel )
{}

RequestClearer::RequestClearer( const RequestClearer & ) throw() // other
	: _driveChannel( ::jmsf::Pointer< DriveChannel >::createWeak() )
{}

const RequestClearer &RequestClearer::operator =( const RequestClearer &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}


} // namespace
}
