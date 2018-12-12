#pragma once

#include "../KeyArray.h"
#include "jmsf/mtf/mixin_nulls/mixin_null_Synchronizable.h"
#include "jmsf/mixin_nulls/mixin_null_Object.h"
#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {


class null_KeyArray :
	public KeyArray,
	public ::jmsf::mtf::mixin_nulls::mixin_null_Synchronizable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_KeyArray >
{

public:
	// virtuals KeyArray
	const ::jmsf::ConstantProxy< externals::data::ed_Key > getTheKeyIfAlredyExists(
		const ::jmsf::ConstantProxy< externals::data::ed_Key > &newKey ) const throw( ::jmsf::Exception );
	void append( const ::jmsf::ConstantProxy< externals::data::ed_Key > &key ) throw( ::jmsf::Exception );
	const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy, externals::data::ed_Key > > getLastAmountOfKeys( ::jmsf::natural_size quantity ) const throw( ::jmsf::Exception );
	::jmsf::Pointer< ::jmsf::osie::runup::Event > getIsNewKeyAvailableEvent() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_KeyArray() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_KeyArray >;
	static null_KeyArray *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_KeyArray() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< KeyArray > createClone() const throw();

private:
	null_KeyArray( const null_KeyArray &other ) throw();
	const null_KeyArray &operator =( const null_KeyArray &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	mutable ::jmsf::Pointer< ::jmsf::osie::runup::Event > _isNewKeyAvailableEvent;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
