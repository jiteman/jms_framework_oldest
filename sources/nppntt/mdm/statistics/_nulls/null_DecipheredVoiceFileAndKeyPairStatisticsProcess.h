#pragma once

#include "../DecipheredVoiceFileAndKeyPairStatisticsProcess.h"

#include "jmsf/osie/runup/mixin_nulls/mixin_null_Runnable.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {


class null_DecipheredVoiceFileAndKeyPairStatisticsProcess :
	public DecipheredVoiceFileAndKeyPairStatisticsProcess,
	public ::jmsf::osie::runup::mixin_nulls::mixin_null_Runnable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_DecipheredVoiceFileAndKeyPairStatisticsProcess >
{

public:
	// virtuals DecipheredVoiceFileAndKeyPairStatisticsProcess
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_DecipheredVoiceFileAndKeyPairStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_DecipheredVoiceFileAndKeyPairStatisticsProcess >;
	static null_DecipheredVoiceFileAndKeyPairStatisticsProcess *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_DecipheredVoiceFileAndKeyPairStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< DecipheredVoiceFileAndKeyPairStatisticsProcess > createClone() const throw();

private:
	null_DecipheredVoiceFileAndKeyPairStatisticsProcess( const null_DecipheredVoiceFileAndKeyPairStatisticsProcess &other ) throw();
	const null_DecipheredVoiceFileAndKeyPairStatisticsProcess &operator =( const null_DecipheredVoiceFileAndKeyPairStatisticsProcess &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
