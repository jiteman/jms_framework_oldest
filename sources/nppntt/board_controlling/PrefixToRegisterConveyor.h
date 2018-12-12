#pragma once


#include "PrefixToFinishProcessingChannel.h"
#include "FinishToRandProcessingChannel.h"
#include "RandToRegisterProcessingChannel.h"

#include "data_Prefix.h"
#include "data_Finish.h"
#include "data_Rand.h"
#include "data_Register.h"

#include "SynchronizedQueue.hpp"

#include "jmsf/UniquePointer.hpp"


namespace nppntt {
namespace board_controlling {


class PrefixToRegisterConveyor {

public:
	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend class ::jmsf::UniquePointer< PrefixToRegisterConveyor >;
	~PrefixToRegisterConveyor() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ::jmsf::UniquePointer< PrefixToRegisterConveyor > create( ::jmsf::) throw();

private:
	PrefixToRegisterConveyor() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	::jmsf::UniquePointer< PrefixToRegisterConveyor > createClone() const throw();

private:
	PrefixToRegisterConveyor( const PrefixToRegisterConveyor &other ) throw();
	const PrefixToRegisterConveyor &operator =( const PrefixToRegisterConveyor &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::UniquePointer< PrefixToFinishProcessingChannel > _prefixToFinishProcessingChannel;
	::jmsf::UniquePointer< FinishToRandProcessingChannel > _finishToRandProcessingChannel;
	::jmsf::UniquePointer< RandToRegisterProcessingChannel > _randToRegisterProcessingChannel;

	::jmsf::UniquePointer< SynchronizedQueue< data_Prefix > > _prefixQueue;
	::jmsf::UniquePointer< SynchronizedQueue< data_Finish > > _finishQueue;
	::jmsf::UniquePointer< SynchronizedQueue< data_Rand > > _randQueue;
	::jmsf::UniquePointer< SynchronizedQueue< data_Register > > _registerQueue;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
