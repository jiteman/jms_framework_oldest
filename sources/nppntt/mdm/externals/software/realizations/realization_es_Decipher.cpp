#include "realization_es_Decipher.h"
#include "../../../exceptions/exception_DllNotFound.h"
#include "../../../exceptions/exception_CantStartDecipheringHardware.h"
#include "../../others/abstractDecipher.h"
#include "../../data/factory_ExternalData.h"
#include "../../data/ed_VoiceFile.h"
#include "../../data/ed_Key.h"
#include "../es_StatisticsUpdater.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/Proxies.hpp"
#include "jmsf/Pointers.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace realizations {


::jmsf::Proxy< externals::data::ed_Key > realization_es_Decipher::tryToDecipher( ::jmsf::Proxy< externals::data::ed_VoiceFile > voiceFile ) throw() {
	_statisticsUpdater->updateDecipheringVoiceFile( voiceFile.getWeakConstant() );

	::jmsf::Proxy< externals::data::ed_Key > newKey =
		externals::data::factory_ExternalData::instance()->createKey(
			_keyCounter + 1,
			::jmsf::Pointer< KeyData >::createUnique( ::createKey() ) );

	const ::jmsf::Boolean isVoiceFileDeciphered =
		::decipherThisFile(
			voiceFile->takeData().get(),
			newKey->takeData().get() );

	if ( isVoiceFileDeciphered ) {
		_keyCounter += 1;
	}

	return isVoiceFileDeciphered ? newKey : ::jmsf::Proxy< externals::data::ed_Key >();
}

::jmsf::integer realization_es_Decipher::getCurrentlyDecipheringVoiceFileProgress() const throw() {
	return ::decipherGetCurrentVoiceFileProgress();
}

void realization_es_Decipher::setStatisticsUpdater( const ::jmsf::Proxy< es_StatisticsUpdater > &statisticsUpdater ) throw() {
	_statisticsUpdater = statisticsUpdater;
}

void realization_es_Decipher::setTimeLimit( const ::jmsf::ConstantPointer< _decipherTimeLimit > &timeLimitData ) const throw() {
	::decipherSetTimeLimit( *timeLimitData );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_es_Decipher::~realization_es_Decipher() throw() {
	::decipherRelease();
	::unloadDecipherDll();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_es_Decipher::realization_es_Decipher() throw( ::jmsf::Exception ) {
	_keyCounter = 0;

	if ( ::jmsf::Boolean( ::loadDecipherDll() ).not() ) {
		throw exceptions::exception_DllNotFound( ::jmsf::CONSTANT_TEXT_STRING( "Decipher dll was not found" ) );
	}

	if ( ::jmsf::Boolean( ::decipherInitialize() ).not() ) {
		throw exceptions::exception_CantStartDecipheringHardware( ::jmsf::CONSTANT_TEXT_STRING( "Can't start deciphering hardware" ) );
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< es_Decipher > realization_es_Decipher::createClone() const throw() {
	return ::jmsf::Proxy< es_Decipher >::createUnique( new realization_es_Decipher( *this ) );
}

realization_es_Decipher::realization_es_Decipher( const realization_es_Decipher & ) throw() // other
{}

const realization_es_Decipher &realization_es_Decipher::operator =( const realization_es_Decipher &other ) throw() {
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
