#pragma once


#include "data_Prefix.h"
#include "data_Finish.h"

#include "SynchronizedQueue.hpp"

#include "jmsf/osie/runup/MOVE_ContinuousRunnable.h"

#include "jmsf/WeakPointer.hpp"


namespace jmsf {
	template< class > class UniquePointer;
}


namespace nppntt {
namespace board_controlling {


class PrefixToFinishProcessingChannel : public ::jmsf::osie::runup::MOVE_ContinuousRunnable {

public:
	// virtuals
	void run() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend class ::jmsf::UniquePointer< PrefixToFinishProcessingChannel >;
	// virtual
	~PrefixToFinishProcessingChannel() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ::jmsf::UniquePointer< PrefixToFinishProcessingChannel > create( ::jmsf::WeakPointer< SynchronizedQueue< data_Prefix > > prefixQueue, ::jmsf::WeakPointer< SynchronizedQueue< data_Finish > > finishQueue ) throw();

private:
	PrefixToFinishProcessingChannel( ::jmsf::WeakPointer< SynchronizedQueue< data_Prefix > > prefixQueue, ::jmsf::WeakPointer< SynchronizedQueue< data_Finish > > finishQueue ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	::jmsf::UniquePointer< PrefixToFinishProcessingChannel > createClone() const throw();

private:
	PrefixToFinishProcessingChannel( const PrefixToFinishProcessingChannel &other ) throw();
	const PrefixToFinishProcessingChannel &operator =( const PrefixToFinishProcessingChannel &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::WeakPointer< SynchronizedQueue< data_Prefix > > _prefixQueue;
	::jmsf::WeakPointer< SynchronizedQueue< data_Finish > > _finishQueue;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
