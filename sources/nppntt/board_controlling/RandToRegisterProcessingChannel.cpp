#include "RandToRegisterProcessingChannel.h"


namespace nppntt {
namespace board_controlling {


void RandToRegisterProcessingChannel::run() throw( ::jmsf::Exception ) {
	
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
RandToRegisterProcessingChannel::~RandToRegisterProcessingChannel() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
::jmsf::UniquePointer< RandToRegisterProcessingChannel > RandToRegisterProcessingChannel::create( const ::jmsf::WeakPointer< SynchronizedQueue< data_Rand > > randQueue, const ::jmsf::WeakPointer< SynchronizedQueue< data_Register > > registerQueue ) throw() {
	return ::jmsf::UniquePointer< RandToRegisterProcessingChannel >( new RandToRegisterProcessingChannel( randQueue, registerQueue ) );
}

RandToRegisterProcessingChannel::RandToRegisterProcessingChannel( const ::jmsf::WeakPointer< SynchronizedQueue< data_Rand > > randQueue, const ::jmsf::WeakPointer< SynchronizedQueue< data_Register > > registerQueue ) throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
RandToRegisterProcessingChannel::RandToRegisterProcessingChannel( const RandToRegisterProcessingChannel & ) throw() // other
{}

const RandToRegisterProcessingChannel &RandToRegisterProcessingChannel::operator =( const RandToRegisterProcessingChannel &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
