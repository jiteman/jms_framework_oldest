#include "PrefixToFinishProcessingChannel.h"


#include "jmsf/UniquePointer.hpp"


namespace nppntt {
namespace board_controlling {


void PrefixToFinishProcessingChannel::run() throw( ::jmsf::Exception ) {
	
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
PrefixToFinishProcessingChannel::~PrefixToFinishProcessingChannel() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
::jmsf::UniquePointer< PrefixToFinishProcessingChannel > PrefixToFinishProcessingChannel::create( const ::jmsf::WeakPointer< SynchronizedQueue< data_Prefix > > prefixQueue, const ::jmsf::WeakPointer< SynchronizedQueue< data_Finish > > finishQueue ) throw() {
	return ::jmsf::UniquePointer< PrefixToFinishProcessingChannel >( new PrefixToFinishProcessingChannel( prefixQueue, finishQueue ) );
}

PrefixToFinishProcessingChannel::PrefixToFinishProcessingChannel( const ::jmsf::WeakPointer< SynchronizedQueue< data_Prefix > > prefixQueue, const ::jmsf::WeakPointer< SynchronizedQueue< data_Finish > > finishQueue ) throw()
	: _prefixQueue( prefixQueue ), _finishQueue( finishQueue )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
PrefixToFinishProcessingChannel::PrefixToFinishProcessingChannel( const PrefixToFinishProcessingChannel & ) throw() // other
{}

const PrefixToFinishProcessingChannel &PrefixToFinishProcessingChannel::operator =( const PrefixToFinishProcessingChannel &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
