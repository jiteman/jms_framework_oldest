#pragma once

#include "../ed_Key.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Pointers.hpp"

#include "realization_factory_ExternalData.hxx"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace realizations {

class realization_ed_Key :
	public ed_Key,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals ed_Key
	::jmsf::Pointer< KeyData > &takeData() throw();
	const ::jmsf::ConstantPointer< KeyData > &getData() const throw();
	const ::jmsf::Boolean isFileSuitable( const ::jmsf::ConstantProxy< ed_VoiceFile > &voiceFile ) const throw();
	const ::jmsf::Boolean isFileSuitable( const ::jmsf::ConstantProxy< ed_ServiceFile > &serviceFile ) const throw();
	::jmsf::natural_size getIdentifier() const throw();
	const ::jmsf::Boolean isEqual( const ::jmsf::ConstantProxy< ed_Key > &key ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ed_Key() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ExternalData;
	realization_ed_Key(
		::jmsf::natural_size identifier,
		const ::jmsf::Pointer< KeyData > &keyData ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_Key > createClone() const throw();

private:
	realization_ed_Key( const realization_ed_Key &other ) throw();
	const realization_ed_Key &operator =( const realization_ed_Key &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< KeyData > _keyData;
	::jmsf::ConstantPointer< KeyData > _constantKeyData;
	const ::jmsf::natural_size _identifier;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
