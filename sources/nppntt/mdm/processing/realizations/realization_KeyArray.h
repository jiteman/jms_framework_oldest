#pragma once

#include "../KeyArray.h"
#include "jmsf/mtf/mixins/mixin_Lockable.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "realization_factory_ProcessingProcesses.hxx"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

class realization_KeyArray :
	public KeyArray,
	public ::jmsf::mtf::mixins::mixin_Lockable,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals KeyArray
	const ::jmsf::ConstantProxy< externals::data::ed_Key > &tryToAppendKeyAndGetNewOrExistingKey( const ::jmsf::ConstantProxy< externals::data::ed_Key > &newKey ) throw( ::jmsf::Exception );
	const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< externals::data::ed_Key > > > getLastAmountOfKeys( ::jmsf::natural_size quantity ) const throw( ::jmsf::Exception );
	::jmsf::Proxy< ::jmsf::osie::Event > &takeIsNewKeyAvailableEvent() throw();
	const ::jmsf::ConstantProxy< ::jmsf::osie::Event > &getIsNewKeyAvailableEvent() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_KeyArray() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ProcessingProcesses;
	realization_KeyArray(
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::ConstantProxy< externals::data::ed_Key > > > &keyContainer,
		const ::jmsf::Proxy< ::jmsf::osie::Event > &event,
		const ::jmsf::Proxy< ::jmsf::osie::Mutex > &mutex ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< KeyArray > createClone() const throw();

private:
	realization_KeyArray( const realization_KeyArray &other ) throw();
	const realization_KeyArray &operator =( const realization_KeyArray &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::ConstantProxy< externals::data::ed_Key > > > _keyContainer;
	::jmsf::Proxy< ::jmsf::osie::Event > _isNewKeyAvailableEvent;
	::jmsf::ConstantProxy< ::jmsf::osie::Event > _isNewKeyAvailableConstantEvent;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
