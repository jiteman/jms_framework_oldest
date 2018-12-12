#pragma once

#include "../ed_ServiceFile.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Pointers.hpp"
#include "jmsf/Proxies.hpp"

#include "realization_factory_ExternalData.hxx"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace realizations {

class realization_ed_ServiceFile :
	public ed_ServiceFile,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals ed_ServiceFile
	::jmsf::Pointer< FileDescriptorData > &takeData() throw();
	::jmsf::Pointer< AppliedData > &takeAppliedData() throw();
	const ::jmsf::ConstantPointer< FileDescriptorData > &getData() const throw();
	const ::jmsf::ConstantPointer< AppliedData > &getAppliedData() const throw();
	void updateAppliedData( const ::jmsf::Pointer< AppliedData > &appliedData ) throw();
	const ::jmsf::Boolean isSuccessfullyProcessed() const throw();
	const ::jmsf::Boolean isNotSuccessfullyProcessed() const throw();
	void markAsSuccessfullyProcessed() throw();
	void updateKey( const ::jmsf::ConstantProxy< ed_Key > &key ) throw();
	const ::jmsf::ConstantProxy< ed_Key > &getKey() const throw();
	const ::jmsf::Boolean isEarly( const ::jmsf::ConstantProxy< ed_ServiceFile > &other ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ed_ServiceFile() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ExternalData;
	realization_ed_ServiceFile(
		::jmsf::Pointer< FileDescriptorData > serviceFileData ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_ServiceFile > createClone() const throw();

private:
	realization_ed_ServiceFile( const realization_ed_ServiceFile &other ) throw( ::jmsf::Exception );
	const realization_ed_ServiceFile &operator =( const realization_ed_ServiceFile &other ) throw( ::jmsf::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< FileDescriptorData > _serviceFileData;
	::jmsf::ConstantPointer< FileDescriptorData > _constantServiceFileData;
	::jmsf::Pointer< AppliedData > _serviceFileAppliedData;
	::jmsf::ConstantPointer< AppliedData > _constantServiceFileAppliedData;
	::jmsf::Boolean _wasSuccefullyProcessed;
	::jmsf::ConstantProxy< ed_Key > _key;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
}
}
}
