#pragma once

#include "jmsf/Object.h"

#include "../others/DataTypes.hxx"
#include "ed_VoiceFile.hxx"
#include "ed_ServiceFile.hxx"
#include "jmsf/Proxies.hxx"
#include "jmsf/Pointers.hxx"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {

class ed_Key :
	public virtual ::jmsf::Object
{

public:
	virtual ::jmsf::Pointer< KeyData > &takeData() throw() = 0;
	virtual const ::jmsf::ConstantPointer< KeyData > &getData() const throw() = 0;
	virtual const ::jmsf::Boolean isFileSuitable( const ::jmsf::ConstantProxy< ed_VoiceFile > &voiceFile ) const throw() = 0;
	virtual const ::jmsf::Boolean isFileSuitable( const ::jmsf::ConstantProxy< ed_ServiceFile > &serviceFile ) const throw() = 0;
	virtual ::jmsf::natural_size getIdentifier() const throw() = 0;
	virtual const ::jmsf::Boolean isEqual( const ::jmsf::ConstantProxy< ed_Key > &key ) const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ed_Key *getNull() throw();
	static ed_Key *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< ed_Key > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace data
} // namespace externals
} // namespace mdm
} // namespace nppntt
