#include "realization_ed_Key.h"
#include "../../others/abstractKey.h"
#include "../ed_VoiceFile.h"
#include "../ed_ServiceFile.h"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace realizations {

::jmsf::Pointer< KeyData > &realization_ed_Key::takeData() throw() {
	return _keyData;
}

const ::jmsf::ConstantPointer< KeyData > &realization_ed_Key::getData() const throw() {
	return _constantKeyData;
}

const ::jmsf::Boolean realization_ed_Key::isFileSuitable( const ::jmsf::ConstantProxy< ed_VoiceFile > &voiceFile ) const throw() {
	return ::isSuitableFileDescriptorToKey( voiceFile->getData().get(), _keyData.get() );
}

const ::jmsf::Boolean realization_ed_Key::isFileSuitable( const ::jmsf::ConstantProxy< ed_ServiceFile > &serviceFile ) const throw() {
	return ::isSuitableFileDescriptorToKey( serviceFile->getData().get(), _keyData.get() );
}

::jmsf::natural_size realization_ed_Key::getIdentifier() const throw() {
	return _identifier;
}

const ::jmsf::Boolean realization_ed_Key::isEqual( const ::jmsf::ConstantProxy< ed_Key > &key ) const throw() {
	return ::areKeysEqual( _keyData.get(), key->getData().get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ed_Key::~realization_ed_Key() throw() {
//	::deleteKey( _keyData.get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ed_Key::realization_ed_Key(
	const ::jmsf::natural_size identifier,
	const ::jmsf::Pointer< KeyData > &keyData ) throw()
	:
		_identifier( identifier ),
		_keyData( keyData )
{
	_constantKeyData = _keyData.getWeakConstant();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_Key > realization_ed_Key::createClone() const throw() {
	return ::jmsf::Proxy< ed_Key >::createUnique( new realization_ed_Key( *this ) );
}

realization_ed_Key::realization_ed_Key( const realization_ed_Key & ) throw() // other
	:
		_identifier( 0 )
{}

const realization_ed_Key &realization_ed_Key::operator =( const realization_ed_Key &other ) throw() {
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
}
