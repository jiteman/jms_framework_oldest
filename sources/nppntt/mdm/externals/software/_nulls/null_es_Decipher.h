#pragma once

#include "../es_Decipher.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace nulls {


class null_es_Decipher :
	public es_Decipher,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_es_Decipher >
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
	~null_es_Decipher() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_es_Decipher >;
	static null_es_Decipher *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_es_Decipher() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_Decipher > createClone() const throw();

private:
	null_es_Decipher( const null_es_Decipher &other ) throw();
	const null_es_Decipher &operator =( const null_es_Decipher &other ) throw();

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
