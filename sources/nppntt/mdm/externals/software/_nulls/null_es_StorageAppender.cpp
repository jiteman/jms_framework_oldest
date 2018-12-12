#include "null_es_StorageAppender.h"
#include "../../data/ed_ServiceFile.h"
#include "../../data/ed_VoiceFile.h"
#include "jmsf/Pairs.hpp"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace nulls {


void null_es_StorageAppender::store( ::jmsf::Pointer< ::jmsf::Pair< ::jmsf::Proxy, data::ed_VoiceFile, data::ed_ServiceFile > >  ) throw() // voiceFileAndServiceFilePair
{}

void null_es_StorageAppender::store( ::jmsf::Proxy< data::ed_VoiceFile >  ) throw() // voiceFile
{}

void null_es_StorageAppender::store( ::jmsf::Proxy< data::ed_ServiceFile >  ) throw() // serviceFile
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_es_StorageAppender::~null_es_StorageAppender() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_es_StorageAppender *null_es_StorageAppender::createInstance() throw() {
	return new null_es_StorageAppender;
}

null_es_StorageAppender::null_es_StorageAppender() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< es_StorageAppender > null_es_StorageAppender::createClone() const throw() {
	return ::jmsf::Proxy< es_StorageAppender >::createUnique( this );
}

null_es_StorageAppender::null_es_StorageAppender( const null_es_StorageAppender & ) throw() // other
{}

const null_es_StorageAppender &null_es_StorageAppender::operator =( const null_es_StorageAppender &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
}
}
