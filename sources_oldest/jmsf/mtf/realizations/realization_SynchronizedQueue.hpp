#pragma once

#include "../SynchronizedQueue.hpp"
#include "jmsf/mtf/mixins/mixin_Lockable.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/osie/Stopwatch.h"
#include "jmsf/Exception.hxx"
#include "jmsf/Container.hxx"
#include "jmsf/Pair.hxx"
#include "realization_factory_GenericMultithreading.hxx"

namespace jmsf {
namespace mtf {
namespace realizations {

template< class A_type >
class realization_SynchronizedQueue :
	public SynchronizedQueue< A_type >,
	public ::jmsf::mtf::mixins::mixin_Lockable,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals SynchronizedQueue< A_type >
	void appendBack( const A_type &object ) throw( Exception );
	void appendFront( const A_type &object ) throw( Exception );
	A_type withdrawFirst() throw( Exception );
	A_type withdrawLast() throw( Exception );
	integer_big getFirstTime() const throw( Exception );
	integer_big getLastTime() const throw( Exception );
	void empty() throw( Exception );
	const Boolean isEmpty() const throw( Exception );
	const Boolean isNotEmpty() const throw( Exception );
	natural_size getQuantityOfObjects() const throw( Exception );
	Proxy< osie::Event > &takeIsObjectAvailableEvent() throw();
	const ConstantProxy< osie::Event > &getIsObjectAvailableEvent() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_SynchronizedQueue() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_GenericMultithreading< A_type >;
	realization_SynchronizedQueue(
		Proxy< osie::Mutex > mutex,
		Proxy< Container< Proxy< Pair< A_type, const integer_big > > > > container,
		Proxy< osie::Event > isObjectAvailableEvent,
		Proxy< osie::Stopwatch > stopwatch ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< SynchronizedQueue< A_type > > createClone() const throw();

private:
	realization_SynchronizedQueue( const realization_SynchronizedQueue &other ) throw();
	const realization_SynchronizedQueue &operator =( const realization_SynchronizedQueue &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	void updateIsObjectAvailableEvent() throw();

private:
	Proxy< Container< Proxy< Pair< A_type, const integer_big > > > > _container;
	Proxy< osie::Event > _isObjectAvailableEvent;
	ConstantProxy< osie::Event > _constantIsObjectAvailableEvent;
	Proxy< osie::Stopwatch > _stopwatch;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Boolean _isObjectAvailabilitySet;

};

} // namespace realizations
} // namespace mtf
} // namespace jmsf


#include "jmsf/factory_Pair.hpp"
#include "jmsf/Pair.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace mtf {
namespace realizations {

template< class A_type >
void realization_SynchronizedQueue< A_type >::appendBack( const A_type &object ) throw( Exception ) {
	Should::alwaysBe( getMutex()->isLocked() );
	_container->appendBack( factory_Pair< A_type, const integer_big >::instance()->createPair( object, _stopwatch->getCounts() ) );
	updateIsObjectAvailableEvent();
}

template< class A_type >
void realization_SynchronizedQueue< A_type >::appendFront( const A_type &object ) throw( Exception ) {
	Should::alwaysBe( getMutex()->isLocked() );
	_container->appendFront( factory_Pair< A_type, const integer_big >::instance()->createPair( object, _stopwatch->getCounts() ) );
	updateIsObjectAvailableEvent();
}

template< class A_type >
A_type realization_SynchronizedQueue< A_type >::withdrawFirst() throw( Exception ) {
	Should::alwaysBe( getMutex()->isLocked() );
	Proxy< Pair< A_type, const integer_big > > object = _container->withdrawFirstContainie();
	updateIsObjectAvailableEvent();
	return object->takeFirst();
}

template< class A_type >
A_type realization_SynchronizedQueue< A_type >::withdrawLast() throw( Exception ) {
	Should::alwaysBe( getMutex()->isLocked() );
	Proxy< Pair< A_type, const integer_big > > object = _container->withdrawLastContainie();
	updateIsObjectAvailableEvent();
	return object->takeFirst();
}

template< class A_type >
integer_big realization_SynchronizedQueue< A_type >::getFirstTime() const throw( Exception ) {
	Should::alwaysBe( getMutex()->isLocked() );
	return _container->getFirstContainie()->getSecond();
}

template< class A_type >
integer_big realization_SynchronizedQueue< A_type >::getLastTime() const throw( Exception ) {
	Should::alwaysBe( getMutex()->isLocked() );
	return _container->getLastContainie()->getSecond();
}

template< class A_type >
void realization_SynchronizedQueue< A_type >::empty() throw( Exception ) {
	Should::alwaysBe( getMutex()->isLocked() );
	_container->clear();
	updateIsObjectAvailableEvent();
}

template< class A_type >
const Boolean realization_SynchronizedQueue< A_type >::isEmpty() const throw( Exception ) {
	Should::alwaysBe( getMutex()->isLocked() );
	return _container->isEmpty();
}

template< class A_type >
const Boolean realization_SynchronizedQueue< A_type >::isNotEmpty() const throw( Exception ) {
	Should::alwaysBe( getMutex()->isLocked() );
	return _container->isNotEmpty();
}

template< class A_type >
natural_size realization_SynchronizedQueue< A_type >::getQuantityOfObjects() const throw( Exception ) {
	Should::alwaysBe( getMutex()->isLocked() );
	return _container->getQuantityOfElements();
}

template< class A_type >
Proxy< osie::Event > &realization_SynchronizedQueue< A_type >::takeIsObjectAvailableEvent() throw() {
	return _isObjectAvailableEvent;
}

template< class A_type >
const ConstantProxy< osie::Event > &realization_SynchronizedQueue< A_type >::getIsObjectAvailableEvent() const throw() {
	return _constantIsObjectAvailableEvent;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_SynchronizedQueue< A_type >::~realization_SynchronizedQueue() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_SynchronizedQueue< A_type >::realization_SynchronizedQueue(
		Proxy< osie::Mutex > mutex,
		Proxy< Container< Proxy< Pair< A_type, const integer_big > > > > container,
		Proxy< osie::Event > isObjectAvailableEvent,
		Proxy< osie::Stopwatch > stopwatch ) throw()
	:
		mixin_Lockable( mutex ),
		_container( container ),
		_isObjectAvailableEvent( isObjectAvailableEvent ),
		_stopwatch( stopwatch )
{
	_constantIsObjectAvailableEvent = _isObjectAvailableEvent.getWeakConstant();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Proxy< SynchronizedQueue< A_type > > realization_SynchronizedQueue< A_type >::createClone() const throw() {
	SynchronizedQueue< A_type > *synchronizedQueue = new realization_SynchronizedQueue( *this );
	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectOrientedCreation( synchronizedQueue, MACROS_FILE_AND_LINE ) );
	return Proxy< SynchronizedQueue< A_type > >::createUnique( synchronizedQueue );
}

template< class A_type >
realization_SynchronizedQueue< A_type >::realization_SynchronizedQueue( const realization_SynchronizedQueue< A_type > & ) throw() // other
	:
		mixin_Lockable( ::jmsf::Proxy< ::jmsf::osie::Mutex >::createEmpty() )
{}

template< class A_type >
const realization_SynchronizedQueue< A_type > &realization_SynchronizedQueue< A_type >::operator =( const realization_SynchronizedQueue< A_type > &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	Should::neverViolateCopyingProhibition( "realization_SynchronizedQueue::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
template< class A_type >
void realization_SynchronizedQueue< A_type >::updateIsObjectAvailableEvent() throw() {
	if ( _container->isEmpty() ) {
		if ( _isObjectAvailabilitySet ) {
			_isObjectAvailableEvent->reset();
			_isObjectAvailabilitySet = False;
		}
	} else {
		if ( _isObjectAvailabilitySet.not() ) {
			_isObjectAvailableEvent->set();
			_isObjectAvailabilitySet = True;
		}
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace realizations
} // namespace mtf
} // namespace jmsf
