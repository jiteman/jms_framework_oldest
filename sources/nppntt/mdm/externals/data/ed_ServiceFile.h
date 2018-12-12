#pragma once

#include "jmsf/Object.h"

#include "../others/DataTypes.hxx"
#include "ed_Key.hxx"
#include "jmsf/Proxies.hxx"
#include "jmsf/Pointers.hxx"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {

class ed_ServiceFile :
	public virtual ::jmsf::Object
{

public:
	virtual ::jmsf::Pointer< FileDescriptorData > &takeData() throw() = 0;
	virtual ::jmsf::Pointer< AppliedData > &takeAppliedData() throw() = 0;
	virtual const ::jmsf::ConstantPointer< FileDescriptorData > &getData() const throw() = 0;
	virtual const ::jmsf::ConstantPointer< AppliedData > &getAppliedData() const throw() = 0;
	virtual void updateAppliedData( const ::jmsf::Pointer< AppliedData > &appliedData ) throw() = 0;
	virtual const ::jmsf::Boolean isSuccessfullyProcessed() const throw() = 0;
	virtual const ::jmsf::Boolean isNotSuccessfullyProcessed() const throw() = 0;
	virtual void markAsSuccessfullyProcessed() throw() = 0;
	virtual void updateKey( const ::jmsf::ConstantProxy< ed_Key > &key ) throw() = 0;
	virtual const ::jmsf::ConstantProxy< ed_Key > &getKey() const throw() = 0;

	virtual const ::jmsf::Boolean isEarly( const ::jmsf::ConstantProxy< ed_ServiceFile > &other ) const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ed_ServiceFile *getNull() throw();
	static ed_ServiceFile *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< ed_ServiceFile > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace data
} // namespace externals
} // namespace mdm
} // namespace nppntt
