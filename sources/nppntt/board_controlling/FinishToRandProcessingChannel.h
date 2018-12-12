#pragma once


#include "data_Finish.h"
#include "data_Rand.h"

#include "SynchronizedQueue.hpp"

#include "jmsf/osie/runup/MOVE_ContinuousRunnable.h"

#include "jmsf/WeakPointer.hpp"


namespace jmsf {
	template< class > class UniquePointer;
}


namespace nppntt {
namespace board_controlling {


class FinishToRandProcessingChannel : public ::jmsf::osie::runup::MOVE_ContinuousRunnable {

public:
	// virtuals
	void run() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend class ::jmsf::UniquePointer< FinishToRandProcessingChannel >;
	// virtual
	~FinishToRandProcessingChannel() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ::jmsf::UniquePointer< FinishToRandProcessingChannel > create( ::jmsf::WeakPointer< SynchronizedQueue< data_Finish > > finishQueue, ::jmsf::WeakPointer< SynchronizedQueue< data_Rand > > randQueue ) throw();

private:
	FinishToRandProcessingChannel( ::jmsf::WeakPointer< SynchronizedQueue< data_Finish > > finishQueue, ::jmsf::WeakPointer< SynchronizedQueue< data_Rand > > randQueue ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	::jmsf::UniquePointer< FinishToRandProcessingChannel > createClone() const throw();

private:
	FinishToRandProcessingChannel( const FinishToRandProcessingChannel &other ) throw();
	const FinishToRandProcessingChannel &operator =( const FinishToRandProcessingChannel &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::WeakPointer< SynchronizedQueue< data_Finish > > _finishQueue;
	::jmsf::WeakPointer< SynchronizedQueue< data_Rand > > _randQueue;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
