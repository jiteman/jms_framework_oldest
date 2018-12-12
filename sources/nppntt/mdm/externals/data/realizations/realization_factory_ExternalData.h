#pragma once

#include "../factory_ExternalData.h"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace realizations {


class realization_factory_ExternalData :
		public factory_ExternalData
{

public:
	// virtuals factory_ExternalData
	::jmsf::Proxy< ed_FileFilter > createFileFilter(
		::jmsf::Pointer< FilterData > fileFilterData ) const throw();

	::jmsf::Proxy< ed_VoiceFile > createVoiceFile(
		::jmsf::Pointer< FileDescriptorData > voiceFileData ) const throw();

	::jmsf::Proxy< ed_ServiceFile > createServiceFile(
		::jmsf::Pointer< FileDescriptorData > serviceFileData ) const throw();

	::jmsf::Proxy< ed_Key > createKey(
		::jmsf::natural_size identifier,
		::jmsf::Pointer< KeyData > keyData ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_ExternalData() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class factory_ExternalData;
	realization_factory_ExternalData() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_ExternalData( const realization_factory_ExternalData &other ) throw();
	const realization_factory_ExternalData &operator =( const realization_factory_ExternalData &other ) throw();

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
