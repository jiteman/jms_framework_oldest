#include "realization_KeyArray.h"
#include "../../externals/data/ed_Key.h"
//#include "jmsf/osie/runup/Mutex.h"
#include "jmsf/osie/Event.h"
#include "jmsf/factory_Container.hpp"
#include "jmsf/Container.hpp"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

const ::jmsf::ConstantProxy< externals::data::ed_Key > &realization_KeyArray::tryToAppendKeyAndGetNewOrExistingKey(
	const ::jmsf::ConstantProxy< externals::data::ed_Key > &newKey ) throw( ::jmsf::Exception )
{
	::jmsf::Should::alwaysBe( getMutex()->isLocked() );
//	::jmsf::ConstantProxy< externals::data::ed_Key > key;

	for (
		::jmsf::Proxy< ::jmsf::ConstantIterator< ::jmsf::ConstantProxy< externals::data::ed_Key > > > keyIterator = _keyContainer->createConstantForwardIterator();
		keyIterator->isNotDone();
		keyIterator->advance() )
	{
		if ( keyIterator->getContainie()->isEqual( newKey ) ) {
			return keyIterator->getContainie();
		}
	}

	_keyContainer->appendBack( newKey );
	_isNewKeyAvailableEvent->set();
	return _keyContainer->getLastContainie();
}

const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< externals::data::ed_Key > > > realization_KeyArray::getLastAmountOfKeys( const ::jmsf::natural_size quantity ) const throw( ::jmsf::Exception ) {
	::jmsf::Should::alwaysBe( getMutex()->isLocked() );

	if ( _keyContainer.getWeakConstant()->isEmpty() ) {
		return ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< externals::data::ed_Key > > >();
	}

	::jmsf::Proxy< ::jmsf::Container< ::jmsf::ConstantProxy< externals::data::ed_Key > > > lastAmountOfKeysContainer =
		::jmsf::factory_Container< ::jmsf::ConstantProxy< externals::data::ed_Key > >::instance()->createArray();

	const ::jmsf::natural_size quantityOfKeys = _keyContainer.getWeakConstant()->getQuantityOfElements();
	const ::jmsf::natural_size quantityOfKeysToReturn = quantity == 0 ? quantityOfKeys : quantity;
	
	const ::jmsf::natural_size bottomKeyIndex =
		quantityOfKeys < quantityOfKeysToReturn ?
			0 :
			quantityOfKeys - quantityOfKeysToReturn;

	for ( ::jmsf::natural_size keyCounter = bottomKeyIndex; keyCounter < quantityOfKeys; keyCounter += 1 ) {
		lastAmountOfKeysContainer->appendBack( _keyContainer->getContainie( keyCounter ) );
	}

	return lastAmountOfKeysContainer.takeConstant();
}

::jmsf::Proxy< ::jmsf::osie::Event > &realization_KeyArray::takeIsNewKeyAvailableEvent() throw() {
	return _isNewKeyAvailableEvent;
}

const ::jmsf::ConstantProxy< ::jmsf::osie::Event > &realization_KeyArray::getIsNewKeyAvailableEvent() const throw() {
	return _isNewKeyAvailableConstantEvent;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_KeyArray::~realization_KeyArray() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_KeyArray::realization_KeyArray(
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::ConstantProxy< externals::data::ed_Key > > > &keyContainer,
		const ::jmsf::Proxy< ::jmsf::osie::Event > &event,
		const ::jmsf::Proxy< ::jmsf::osie::Mutex > &mutex ) throw()
	:
		mixin_Lockable( mutex ),
		_keyContainer( keyContainer ),
		_isNewKeyAvailableEvent( event )
{
	_isNewKeyAvailableConstantEvent = _isNewKeyAvailableEvent.getWeakConstant();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< KeyArray > realization_KeyArray::createClone() const throw() {
	return ::jmsf::Proxy< KeyArray >::createUnique( new realization_KeyArray( *this ) );
}

realization_KeyArray::realization_KeyArray( const realization_KeyArray & ) throw() // other
	:
		mixin_Lockable( ::jmsf::Proxy< ::jmsf::osie::Mutex >() )
{}

const realization_KeyArray &realization_KeyArray::operator =( const realization_KeyArray &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
}
