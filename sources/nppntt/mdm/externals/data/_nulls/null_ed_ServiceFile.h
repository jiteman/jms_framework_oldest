#pragma once

#include "../ed_ServiceFile.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/mtf/mtf_Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace nulls {


class null_ed_ServiceFile :
	public ed_ServiceFile,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::mtf::mtf_Singleton< null_ed_ServiceFile >
{

public:
	// virtuals ed_ServiceFile
	::jmsf::Pointer< FileDescriptorData > getOneselfData() throw();
	::jmsf::Pointer< AppliedData > getOneselfAppliedData() throw();
	const ::jmsf::ConstantPointer< FileDescriptorData > getData() const throw();
	const ::jmsf::ConstantPointer< AppliedData > getAppliedData() const throw();
	void updateAppliedData( ::jmsf::Pointer< AppliedData > appliedData ) throw();
	::jmsf::Boolean isSuccessfullyProcessed() const throw();
	::jmsf::Boolean isNotSuccessfullyProcessed() const throw();
	void markAsSuccessfullyProcessed() throw();
	void updateKey( const ::jmsf::ConstantProxy< ed_Key > &key ) throw();
	const ::jmsf::ConstantProxy< ed_Key > getKey() const throw();
	::jmsf::Boolean isEarly( const ::jmsf::ConstantProxy< ed_ServiceFile > &other ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ed_ServiceFile() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::mtf::mtf_Singleton< null_ed_ServiceFile >;
	static null_ed_ServiceFile *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ed_ServiceFile() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_ServiceFile > createClone() const throw();

private:
	null_ed_ServiceFile( const null_ed_ServiceFile &other ) throw();
	const null_ed_ServiceFile &operator =( const null_ed_ServiceFile &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
