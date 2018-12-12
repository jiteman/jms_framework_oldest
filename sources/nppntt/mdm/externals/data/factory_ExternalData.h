#pragma once

#include "jmsf/Singleton.hpp"

#include "../others/DataTypes.hxx"
#include "ed_FileFilter.hxx"
#include "ed_Voicefile.hxx"
#include "ed_ServiceFile.hxx"
#include "ed_Key.hxx"

#include "jmsf/PointersAndProxies.hxx"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {


class factory_ExternalData :
	public ::jmsf::Singleton< factory_ExternalData >
{

public:
	virtual ::jmsf::Proxy< ed_FileFilter > createFileFilter(
		::jmsf::Pointer< FilterData > fileFilterData ) const throw() = 0;

	virtual ::jmsf::Proxy< ed_VoiceFile > createVoiceFile(		
		::jmsf::Pointer< FileDescriptorData > voiceFileData ) const throw() = 0;

	virtual ::jmsf::Proxy< ed_ServiceFile > createServiceFile(
		::jmsf::Pointer< FileDescriptorData > serviceFileData ) const throw() = 0;

	virtual ::jmsf::Proxy< ed_Key > createKey(
		::jmsf::natural_size identifier,
		::jmsf::Pointer< KeyData > keyData ) const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_ExternalData() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< factory_ExternalData >;
	static factory_ExternalData *createInstance() throw();

protected:
	factory_ExternalData() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_ExternalData( const factory_ExternalData &other ) throw();
	const factory_ExternalData &operator =( const factory_ExternalData &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
