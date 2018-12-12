#pragma once

#include "../es_Decipher.h"
#include "jmsf/mixins/mixin_Object.h"
#include "realization_factory_ExternalSoftware.hxx"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace realizations {


class realization_es_Decipher :
	public es_Decipher,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals es_Decipher
	::jmsf::Proxy< externals::data::ed_Key > tryToDecipher( ::jmsf::Proxy< externals::data::ed_VoiceFile > voiceFile ) throw();
	::jmsf::integer getCurrentlyDecipheringVoiceFileProgress() const throw();
	void setStatisticsUpdater( const ::jmsf::Proxy< es_StatisticsUpdater > &statisticsUpdater ) throw();
	void setTimeLimit( const ::jmsf::ConstantPointer< _decipherTimeLimit > &timeLimitData ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_es_Decipher() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ExternalSoftware;
	realization_es_Decipher() throw( ::jmsf::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_Decipher > createClone() const throw();

private:
	realization_es_Decipher( const realization_es_Decipher &other ) throw();
	const realization_es_Decipher &operator =( const realization_es_Decipher &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::natural_size _keyCounter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	::jmsf::Proxy< es_StatisticsUpdater > _statisticsUpdater;

};


} // namespace
}
}
}
}
