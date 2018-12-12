#include "PrefixToRegisterConveyor.h"


#include "jmsf/UniquePointer.hpp"


namespace nppntt {
namespace board_controlling {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
PrefixToRegisterConveyor::~PrefixToRegisterConveyor() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
::jmsf::UniquePointer< PrefixToRegisterConveyor > PrefixToRegisterConveyor::create() throw() {
	return ::jmsf::UniquePointer< PrefixToRegisterConveyor >( new PrefixToRegisterConveyor );
}

PrefixToRegisterConveyor::PrefixToRegisterConveyor() throw()
	:
		_prefixQueue( SynchronizedQueue< data_Prefix >::create( ::jmsf::osie::runup::Mutex::create() ) ),
		_finishQueue( SynchronizedQueue< data_Finish >::create( ::jmsf::osie::runup::Mutex::create() ) ),
		_randQueue( SynchronizedQueue< data_Rand >::create( ::jmsf::osie::runup::Mutex::create() ) ),
		_registerQueue( SynchronizedQueue< data_Register >::create( ::jmsf::osie::runup::Mutex::create() ) )
{
	_prefixToFinishProcessingChannel = PrefixToFinishProcessingChannel::create( _prefixQueue, _finishQueue );
	_finishToRandProcessingChannel = FinishToRandProcessingChannel::create( _finishQueue, _randQueue );
	_randToRegisterProcessingChannel = RandToRegisterProcessingChannel::create( _randQueue, _registerQueue );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::UniquePointer< PrefixToRegisterConveyor > PrefixToRegisterConveyor::createClone() const throw() {
	return ::jmsf::UniquePointer< PrefixToRegisterConveyor >( new PrefixToRegisterConveyor( *this ) );
}

PrefixToRegisterConveyor::PrefixToRegisterConveyor( const PrefixToRegisterConveyor & ) throw() // other
{}

const PrefixToRegisterConveyor &PrefixToRegisterConveyor::operator =( const PrefixToRegisterConveyor &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
