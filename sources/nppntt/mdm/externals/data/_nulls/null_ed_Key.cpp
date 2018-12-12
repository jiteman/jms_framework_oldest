#include "null_ed_Key.h"
#include "../../others/abstractKey.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace nulls {


::jmsf::Pointer< KeyData > null_ed_Key::getOneselfData() throw() {
	return _keyData.getWeak();
}

const ::jmsf::ConstantPointer< KeyData > null_ed_Key::getData() const throw() {
	return _keyData.getWeakConstant();
}

::jmsf::Boolean null_ed_Key::isFileSuitable( const ::jmsf::ConstantProxy< ed_VoiceFile > & ) const throw() { // voiceFile
	return ::jmsf::False;
}

::jmsf::Boolean null_ed_Key::isFileSuitable( const ::jmsf::ConstantProxy< ed_ServiceFile > & ) const throw() { // serviceFile
	return ::jmsf::False;
}

::jmsf::natural_size null_ed_Key::getIdentifier() const throw() {
	return 0;
}

::jmsf::Boolean null_ed_Key::isEqual( const ::jmsf::ConstantProxy< ed_Key > & ) const throw() { // key
	return ::jmsf::False;
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ed_Key::~null_ed_Key() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ed_Key *null_ed_Key::createInstance() throw() {
	return new null_ed_Key;
}

null_ed_Key::null_ed_Key() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_Key > null_ed_Key::createClone() const throw() {
	return ::jmsf::Proxy< ed_Key >::createUnique( this );
}

null_ed_Key::null_ed_Key( const null_ed_Key & ) throw() // other
{}

const null_ed_Key &null_ed_Key::operator =( const null_ed_Key &other ) throw() {
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
