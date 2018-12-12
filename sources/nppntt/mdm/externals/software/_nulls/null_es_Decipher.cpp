#include "null_es_Decipher.h"
#include "../../data/ed_Key.h"
#include "../../data/ed_VoiceFile.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace nulls {


::jmsf::Proxy< externals::data::ed_Key > null_es_Decipher::tryToDecipher( ::jmsf::Proxy< externals::data::ed_VoiceFile > ) throw() { // voiceFile
	return ::jmsf::Proxy< externals::data::ed_Key >();
}

::jmsf::integer null_es_Decipher::getCurrentlyDecipheringVoiceFileProgress() const throw() {
	return ::jmsf::integer( 0 );
}

void null_es_Decipher::setStatisticsUpdater( const ::jmsf::Proxy< es_StatisticsUpdater > & ) throw() // statisticsUpdater
{}

void null_es_Decipher::setTimeLimit( const ::jmsf::ConstantPointer< _decipherTimeLimit > & ) const throw() // timeLimitData
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_es_Decipher::~null_es_Decipher() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_es_Decipher *null_es_Decipher::createInstance() throw() {
	return new null_es_Decipher;
}

null_es_Decipher::null_es_Decipher() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< es_Decipher > null_es_Decipher::createClone() const throw() {
	return ::jmsf::Proxy< es_Decipher >::createUnique( this );
}

null_es_Decipher::null_es_Decipher( const null_es_Decipher & ) throw() // other
{}

const null_es_Decipher &null_es_Decipher::operator =( const null_es_Decipher &other ) throw() {
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
