#pragma once

#include "../ed_VoiceFile.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Pointers.hpp"
#include "jmsf/Proxies.hpp"

#include "realization_factory_ExternalData.hxx"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace realizations {

class realization_ed_VoiceFile :
	public ed_VoiceFile,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals ed_VoiceFile
	::jmsf::Pointer< FileDescriptorData > &takeData() throw();
	::jmsf::Pointer< AppliedData > &takeAppliedData() throw();
	const ::jmsf::ConstantPointer< FileDescriptorData > &getData() const throw();
	const ::jmsf::ConstantPointer< AppliedData > &getAppliedData() const throw();
	const ::jmsf::Boolean isServiceFileSuitable( const ::jmsf::ConstantProxy< ed_ServiceFile > &serviceFile ) const throw();
	const ::jmsf::ConstantProxy< ed_Key > &getLastAppliedKey() const throw();
	void updateLastAppliedKey( const ::jmsf::ConstantProxy< ed_Key > &key ) throw();
	void updateAppliedData( const ::jmsf::Pointer< AppliedData > &appliedData ) throw();
	const ::jmsf::Boolean isDeletedFromDecipher() const throw();
	void markAsDeletedFromDecipher() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ed_VoiceFile() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ExternalData;
	realization_ed_VoiceFile(
		::jmsf::Pointer< FileDescriptorData > voiceFileData ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_VoiceFile > createClone() const throw();

private:
	realization_ed_VoiceFile( const realization_ed_VoiceFile &other ) throw( ::jmsf::Exception );
	const realization_ed_VoiceFile &operator =( const realization_ed_VoiceFile &other ) throw( ::jmsf::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< FileDescriptorData > _voiceFileData;
	::jmsf::ConstantPointer< FileDescriptorData > _constantVoiceFileData;
	::jmsf::Pointer< AppliedData > _voiceFileAppliedData;
	::jmsf::ConstantPointer< AppliedData > _constantVoiceFileAppliedData;
	::jmsf::ConstantProxy< ed_Key > _lastAppliedKey;
	::jmsf::Boolean _isDeletedFromDecipher;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
}
}
}
