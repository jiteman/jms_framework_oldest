#pragma once


#include "data_Rand.h"
#include "data_Register.h"

#include "SynchronizedQueue.hpp"

#include "jmsf/osie/runup/MOVE_ContinuousRunnable.h"

#include "jmsf/WeakPointer.hpp"


namespace nppntt {
namespace board_controlling {		


class RandToRegisterProcessingChannel : public ::jmsf::osie::runup::MOVE_ContinuousRunnable {

public:
	// virtuals
	void run() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend class ::jmsf::UniquePointer< RandToRegisterProcessingChannel >;
	// virtual
	~RandToRegisterProcessingChannel() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ::jmsf::UniquePointer< RandToRegisterProcessingChannel > create( ::jmsf::WeakPointer< SynchronizedQueue< data_Rand > > randQueue, ::jmsf::WeakPointer< SynchronizedQueue< data_Register > > registerQueue ) throw();

private:
	RandToRegisterProcessingChannel( ::jmsf::WeakPointer< SynchronizedQueue< data_Rand > > randQueue, ::jmsf::WeakPointer< SynchronizedQueue< data_Register > > registerQueue ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	::jmsf::UniquePointer< RandToRegisterProcessingChannel > createClone() const throw();

private:
	RandToRegisterProcessingChannel( const RandToRegisterProcessingChannel &other ) throw();
	const RandToRegisterProcessingChannel &operator =( const RandToRegisterProcessingChannel &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:	
	::jmsf::WeakPointer< SynchronizedQueue< data_Rand > > _randQueue;
	::jmsf::WeakPointer< SynchronizedQueue< data_Register > > _registerQueue;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
