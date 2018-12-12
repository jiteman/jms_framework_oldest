#pragma once

#include "../factory_GenericMultithreading.hpp"

namespace jmsf {
namespace mtf {
namespace realizations {

template< class A_type >
class realization_factory_GenericMultithreading :
	public factory_GenericMultithreading< A_type >
{

public:
	// virtuals factory_GenericMultithreading< A_type >
	Proxy< SynchronizedQueue< A_type > > createSynchronizedQueue() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_GenericMultithreading() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend factory_GenericMultithreading< A_type >;
	realization_factory_GenericMultithreading() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_GenericMultithreading( const realization_factory_GenericMultithreading &other ) throw();
	const realization_factory_GenericMultithreading &operator =( const realization_factory_GenericMultithreading &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace realizations
} // namespace mtf
} // namespace jmsf


#include "realization_SynchronizedQueue.hpp"
#include "jmsf/osie/factory_OperatingSystem.h"
#include "jmsf/osie/MultithreadingControl.h"
#include "jmsf/osie/UtilityControl.h"
#include "jmsf/factory_Container.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace mtf {
namespace realizations {

template< class A_type >
Proxy< SynchronizedQueue< A_type > > realization_factory_GenericMultithreading< A_type >::createSynchronizedQueue() const throw() {
	SynchronizedQueue< A_type > *synchronizedQueue =
		new realization_SynchronizedQueue< A_type >(
			osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createMutex(),
			factory_Container< Proxy< Pair< A_type, const integer_big > > >::instance()->createList(),
			osie::factory_OperatingSystem::instance()->getMultithreadingControl()->createEvent(),
			osie::factory_OperatingSystem::instance()->getUtilityControl()->createStopwatch() );

	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( synchronizedQueue, MACROS_FILE_AND_LINE ) );
	return Proxy< SynchronizedQueue< A_type > >::createUnique( synchronizedQueue );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_factory_GenericMultithreading< A_type >::~realization_factory_GenericMultithreading() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_factory_GenericMultithreading< A_type >::realization_factory_GenericMultithreading() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_factory_GenericMultithreading< A_type >::realization_factory_GenericMultithreading( const realization_factory_GenericMultithreading< A_type > & ) throw() // other
{}

template< class A_type >
const realization_factory_GenericMultithreading< A_type > &realization_factory_GenericMultithreading< A_type >::operator =( const realization_factory_GenericMultithreading< A_type > &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	// copy
	Should::neverViolateCopyingProhibition( "realization_factory_GenericMultithreading< A_type >::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace realizations
} // namespace mtf
} // namespace jmsf
