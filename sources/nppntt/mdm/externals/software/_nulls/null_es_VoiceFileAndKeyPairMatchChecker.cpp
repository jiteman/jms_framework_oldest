#include "null_es_VoiceFileAndKeyPairMatchChecker.h"
#include "../../data/ed_Key.h"
#include "../../data/ed_VoiceFile.h"
#include "jmsf/Pairs.hpp"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace nulls {


void null_es_VoiceFileAndKeyPairMatchChecker::setPair( ::jmsf::Pointer< ::jmsf::VariousPair< ::jmsf::Proxy, data::ed_VoiceFile, ::jmsf::ConstantProxy, data::ed_Key > > ) throw() // voiceFileAndKeyPair
{}

const ::jmsf::Boolean null_es_VoiceFileAndKeyPairMatchChecker::isPairMatched() const throw() {
	return ::jmsf::False;
}

const ::jmsf::ConstantProxy< data::ed_Key > null_es_VoiceFileAndKeyPairMatchChecker::getTheKey() const throw() {
	return ::jmsf::ConstantProxy< data::ed_Key >();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_es_VoiceFileAndKeyPairMatchChecker::~null_es_VoiceFileAndKeyPairMatchChecker() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_es_VoiceFileAndKeyPairMatchChecker *null_es_VoiceFileAndKeyPairMatchChecker::createInstance() throw() {
	return new null_es_VoiceFileAndKeyPairMatchChecker;
}

null_es_VoiceFileAndKeyPairMatchChecker::null_es_VoiceFileAndKeyPairMatchChecker() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< es_VoiceFileAndKeyPairMatchChecker > null_es_VoiceFileAndKeyPairMatchChecker::createClone() const throw() {
	return ::jmsf::Proxy< es_VoiceFileAndKeyPairMatchChecker >::createUnique( this );
}

null_es_VoiceFileAndKeyPairMatchChecker::null_es_VoiceFileAndKeyPairMatchChecker( const null_es_VoiceFileAndKeyPairMatchChecker & ) throw() // other
{}

const null_es_VoiceFileAndKeyPairMatchChecker &null_es_VoiceFileAndKeyPairMatchChecker::operator =( const null_es_VoiceFileAndKeyPairMatchChecker &other ) throw() {
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
