#pragma once

#include "../ed_Key.h"
#include "jmsf/mixin_nulls/mixin_null_Object.h"
#include "jmsf/mtf/mtf_Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace nulls {


class null_ed_Key :
	public ed_Key,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::mtf::mtf_Singleton< null_ed_Key >
{

public:
	// virtuals ed_Key
	::jmsf::Pointer< KeyData > getOneselfData() throw();
	const ::jmsf::ConstantPointer< KeyData > getData() const throw();
	::jmsf::Boolean isFileSuitable( const ::jmsf::ConstantProxy< ed_VoiceFile > &voiceFile ) const throw();
	::jmsf::Boolean isFileSuitable( const ::jmsf::ConstantProxy< ed_ServiceFile > &serviceFile ) const throw();
	::jmsf::natural_size getIdentifier() const throw();
	::jmsf::Boolean isEqual( const ::jmsf::ConstantProxy< ed_Key > &key ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ed_Key() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::mtf::mtf_Singleton< null_ed_Key >;
	static null_ed_Key *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ed_Key() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_Key > createClone() const throw();

private:
	null_ed_Key( const null_ed_Key &other ) throw();
	const null_ed_Key &operator =( const null_ed_Key &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< KeyData > _keyData;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
