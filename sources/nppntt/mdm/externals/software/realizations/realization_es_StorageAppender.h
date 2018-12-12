#pragma once

#include "../es_StorageAppender.h"
#include "jmsf/mixins/mixin_Object.h"

#include "realization_factory_ExternalSoftware.hxx"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace realizations {


class realization_es_StorageAppender :
	public es_StorageAppender,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals es_StorageAppender
	void store( const ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::ConstantProxy< data::ed_VoiceFile >, ::jmsf::Proxy< data::ed_ServiceFile > > > &voiceFileAndServiceFilePair ) throw();
	void store( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw();
	void store( const ::jmsf::Proxy< data::ed_ServiceFile > &serviceFile ) throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_es_StorageAppender() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ExternalSoftware;
	realization_es_StorageAppender() throw( ::jmsf::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_StorageAppender > createClone() const throw();

private:
	realization_es_StorageAppender( const realization_es_StorageAppender &other ) throw();
	const realization_es_StorageAppender &operator =( const realization_es_StorageAppender &other ) throw();

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
