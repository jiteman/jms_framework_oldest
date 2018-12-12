#include "FinishToRandProcessingChannel.h"


#include "jmsf/UniquePointer.hpp"


namespace nppntt {
namespace board_controlling {


void FinishToRandProcessingChannel::run() throw( ::jmsf::Exception ) {
	
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
FinishToRandProcessingChannel::~FinishToRandProcessingChannel() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
::jmsf::UniquePointer< FinishToRandProcessingChannel > FinishToRandProcessingChannel::create( const ::jmsf::WeakPointer< SynchronizedQueue< data_Finish > > finishQueue, const ::jmsf::WeakPointer< SynchronizedQueue< data_Rand > > randQueue ) throw() {
	return ::jmsf::UniquePointer< FinishToRandProcessingChannel >( new FinishToRandProcessingChannel( finishQueue, randQueue ) );
}

FinishToRandProcessingChannel::FinishToRandProcessingChannel( const ::jmsf::WeakPointer< SynchronizedQueue< data_Finish > > finishQueue, const ::jmsf::WeakPointer< SynchronizedQueue< data_Rand > > randQueue ) throw()
	: _finishQueue( finishQueue ), _randQueue( randQueue )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
FinishToRandProcessingChannel::FinishToRandProcessingChannel( const FinishToRandProcessingChannel & ) throw() // other
{}

const FinishToRandProcessingChannel &FinishToRandProcessingChannel::operator =( const FinishToRandProcessingChannel &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
