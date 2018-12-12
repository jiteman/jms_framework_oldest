#pragma once

#include "jmsf/Object.h"

#include "../data/ed_VoiceFile.hxx"
#include "../data/ed_ServiceFile.hxx"
#include "jmsf/Pair.hxx"
#include "jmsf/Pointers.hxx"
#include "jmsf/Proxies.hxx"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {


class es_StorageAppender :
	public virtual ::jmsf::Object
{

public:
	virtual void store( const ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::ConstantProxy< data::ed_VoiceFile >, ::jmsf::Proxy< data::ed_ServiceFile > > > &voiceFileAndServiceFilePair ) throw() = 0;
	virtual void store( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw() = 0;
	virtual void store( const ::jmsf::Proxy< data::ed_ServiceFile > &serviceFile ) throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static es_StorageAppender *getNull() throw();
	static es_StorageAppender *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< es_StorageAppender > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
