#pragma once

#include "../ed_VoiceFile.h"
#include "jmsf/mixin_nulls/mixin_null_Object.h"
#include "jmsf/mtf/mtf_Singleton.hpp"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace nulls {


class null_ed_VoiceFile :
	public ed_VoiceFile,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::mtf::mtf_Singleton< null_ed_VoiceFile >
{

public:
	// virtuals ed_VoiceFile
	::jmsf::Pointer< FileDescriptorData > getOneselfData() throw();
	::jmsf::Pointer< AppliedData > getOneselfAppliedData() throw();
	const ::jmsf::ConstantPointer< FileDescriptorData > getData() const throw();
	const ::jmsf::ConstantPointer< AppliedData > getAppliedData() const throw();
	::jmsf::Boolean isServiceFileSuitable( const ::jmsf::ConstantProxy< ed_ServiceFile > &serviceFile ) const throw();
	const ::jmsf::ConstantProxy< ed_Key > getLastAppliedKey() const throw();
	void updateLastAppliedKey( const ::jmsf::ConstantProxy< ed_Key > &key ) throw();
	void updateAppliedData( ::jmsf::Pointer< AppliedData > appliedData ) throw();
	::jmsf::Boolean isDeletedFromDecipher() const throw();
	void markAsDeletedFromDecipher() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ed_VoiceFile() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::mtf::mtf_Singleton< null_ed_VoiceFile >;
	static null_ed_VoiceFile *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ed_VoiceFile() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_VoiceFile > createClone() const throw();

private:
	null_ed_VoiceFile( const null_ed_VoiceFile &other ) throw();
	const null_ed_VoiceFile &operator =( const null_ed_VoiceFile &other ) throw();

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
