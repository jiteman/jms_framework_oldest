#include "null_KeyArray.h"
#include "../../externals/data/ed_Key.h"
#include "jmsf/osie/runup/Event.h"
#include "jmsf/Container.hpp"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {

const ::jmsf::ConstantProxy< externals::data::ed_Key > null_KeyArray::getTheKeyIfAlredyExists(
	const ::jmsf::ConstantProxy< externals::data::ed_Key > & ) const throw( ::jmsf::Exception )
{
	return ::jmsf::ConstantProxy< externals::data::ed_Key >();
}

void null_KeyArray::append( const ::jmsf::ConstantProxy< externals::data::ed_Key > &  ) throw( ::jmsf::Exception ) // key
{}

const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy, externals::data::ed_Key > > null_KeyArray::getLastAmountOfKeys( const ::jmsf::natural_size  ) const throw( ::jmsf::Exception ) { // quantity
	return ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy, externals::data::ed_Key > >::createNone();
}

::jmsf::Pointer< ::jmsf::osie::runup::Event > null_KeyArray::getIsNewKeyAvailableEvent() const throw() {
	return _isNewKeyAvailableEvent.getWeak();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_KeyArray::~null_KeyArray() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_KeyArray *null_KeyArray::createInstance() throw() {
	return new null_KeyArray;
}

null_KeyArray::null_KeyArray() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< KeyArray > null_KeyArray::createClone() const throw() {
	return ::jmsf::Proxy< KeyArray >::createUnique( this );
}

null_KeyArray::null_KeyArray( const null_KeyArray & ) throw() // other
{}

const null_KeyArray &null_KeyArray::operator =( const null_KeyArray &other ) throw() {
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
