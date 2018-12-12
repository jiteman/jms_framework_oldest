#pragma once

#include "jmsf/Object.h"

#include "../others/DataTypes.hxx"
#include "../data/ed_VoiceFile.hxx"
#include "../data/ed_Key.hxx"
#include "es_StatisticsUpdater.hxx"
#include "jmsf/Proxies.hxx"
#include "jmsf/Pointers.hxx"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {


class es_Decipher :
	public virtual ::jmsf::Object
{

public:
	virtual ::jmsf::Proxy< externals::data::ed_Key > tryToDecipher( ::jmsf::Proxy< externals::data::ed_VoiceFile > voiceFile ) throw() = 0;
	virtual ::jmsf::integer getCurrentlyDecipheringVoiceFileProgress() const throw() = 0;

	virtual void setStatisticsUpdater( const ::jmsf::Proxy< es_StatisticsUpdater > &statisticsUpdater ) throw() = 0;
	virtual void setTimeLimit( const ::jmsf::ConstantPointer< _decipherTimeLimit > &timeLimitData ) const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static es_Decipher *getNull() throw();
	static es_Decipher *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< es_Decipher > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
