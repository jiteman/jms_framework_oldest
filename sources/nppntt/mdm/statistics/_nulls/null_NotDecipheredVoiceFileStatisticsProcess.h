#pragma once

#include "../NotDecipheredVoiceFileStatisticsProcess.h"

#include "jmsf/osie/runup/mixin_nulls/mixin_null_Runnable.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {


class null_NotDecipheredVoiceFileStatisticsProcess :
	public NotDecipheredVoiceFileStatisticsProcess,
	public ::jmsf::osie::runup::mixin_nulls::mixin_null_Runnable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_NotDecipheredVoiceFileStatisticsProcess >
{

public:
	// virtuals NotDecipheredVoiceFileStatisticsProcess
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_NotDecipheredVoiceFileStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_NotDecipheredVoiceFileStatisticsProcess >;
	static null_NotDecipheredVoiceFileStatisticsProcess *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_NotDecipheredVoiceFileStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< NotDecipheredVoiceFileStatisticsProcess > createClone() const throw();

private:
	null_NotDecipheredVoiceFileStatisticsProcess( const null_NotDecipheredVoiceFileStatisticsProcess &other ) throw();
	const null_NotDecipheredVoiceFileStatisticsProcess &operator =( const null_NotDecipheredVoiceFileStatisticsProcess &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
