#pragma once

#include "../es_StorageAppender.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace nulls {


class null_es_StorageAppender :
	public es_StorageAppender,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_es_StorageAppender >
{

public:
	// virtuals es_StorageAppender
	void store( ::jmsf::Pointer< ::jmsf::Pair< ::jmsf::Proxy, data::ed_VoiceFile, data::ed_ServiceFile > > voiceFileAndServiceFilePair ) throw();
	void store( ::jmsf::Proxy< data::ed_VoiceFile > voiceFile ) throw();
	void store( ::jmsf::Proxy< data::ed_ServiceFile > serviceFile ) throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_es_StorageAppender() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_es_StorageAppender >;
	static null_es_StorageAppender *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_es_StorageAppender() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_StorageAppender > createClone() const throw();

private:
	null_es_StorageAppender( const null_es_StorageAppender &other ) throw();
	const null_es_StorageAppender &operator =( const null_es_StorageAppender &other ) throw();

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
