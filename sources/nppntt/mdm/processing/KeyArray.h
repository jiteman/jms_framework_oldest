#pragma once

#include "jmsf/mtf/Lockable.h"
#include "jmsf/Object.h"

#include "../externals/data/ed_Key.hxx"

#include "jmsf/osie/Event.hxx"
#include "jmsf/Container.hxx"
#include "jmsf/Proxies.hxx"

namespace nppntt {
namespace mdm {
namespace processing {

class KeyArray :
	public virtual ::jmsf::mtf::Lockable,
	public virtual ::jmsf::Object
{

public:
	virtual const ::jmsf::ConstantProxy< externals::data::ed_Key > &tryToAppendKeyAndGetNewOrExistingKey( const ::jmsf::ConstantProxy< externals::data::ed_Key > &newKey ) throw( ::jmsf::Exception ) = 0;
	virtual const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< externals::data::ed_Key > > > getLastAmountOfKeys( ::jmsf::natural_size quantity = 0 ) const throw( ::jmsf::Exception ) = 0;
	virtual ::jmsf::Proxy< ::jmsf::osie::Event > &takeIsNewKeyAvailableEvent() throw() = 0;
	virtual const ::jmsf::ConstantProxy< ::jmsf::osie::Event > &getIsNewKeyAvailableEvent() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static KeyArray *getNull() throw();
	static KeyArray *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< KeyArray > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace processing
} // namespace mdm
} // namespace nppntt
