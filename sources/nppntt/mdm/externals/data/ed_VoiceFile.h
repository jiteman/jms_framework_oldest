#pragma once

#include "jmsf/Object.h"

#include "../others/DataTypes.hxx"
#include "ed_ServiceFile.hxx"
#include "ed_Key.hxx"
#include "jmsf/Proxies.hxx"
#include "jmsf/Pointers.hxx"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {

class ed_VoiceFile :
	public virtual ::jmsf::Object
{

public:
	virtual ::jmsf::Pointer< FileDescriptorData > &takeData() throw() = 0;
	virtual ::jmsf::Pointer< AppliedData > &takeAppliedData() throw() = 0;
	virtual const ::jmsf::ConstantPointer< FileDescriptorData > &getData() const throw() = 0;
	virtual const ::jmsf::ConstantPointer< AppliedData > &getAppliedData() const throw() = 0;
	virtual const ::jmsf::Boolean isServiceFileSuitable( const ::jmsf::ConstantProxy< ed_ServiceFile > &serviceFile ) const throw() = 0;
	virtual const ::jmsf::ConstantProxy< ed_Key > &getLastAppliedKey() const throw() = 0;
	virtual void updateLastAppliedKey( const ::jmsf::ConstantProxy< ed_Key > &key ) throw() = 0;
	virtual void updateAppliedData( const ::jmsf::Pointer< AppliedData > &appliedData ) throw() = 0;
	virtual const ::jmsf::Boolean isDeletedFromDecipher() const throw() = 0;
	virtual void markAsDeletedFromDecipher() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ed_VoiceFile *getNull() throw();
	static ed_VoiceFile *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< ed_VoiceFile > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace data
} // namespace externals
} // namespace mdm
} // namespace nppntt
