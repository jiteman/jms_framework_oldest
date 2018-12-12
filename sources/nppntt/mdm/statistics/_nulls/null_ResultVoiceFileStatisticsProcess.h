#pragma once

#include "../ResultVoiceFileStatisticsProcess.h"

#include "jmsf/osie/runup/mixin_nulls/mixin_null_Runnable.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {


class null_ResultVoiceFileStatisticsProcess :
	public ResultVoiceFileStatisticsProcess,
	public ::jmsf::osie::runup::mixin_nulls::mixin_null_Runnable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_ResultVoiceFileStatisticsProcess >
{

public:
	// virtuals ResultVoiceFileStatisticsProcess
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ResultVoiceFileStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_ResultVoiceFileStatisticsProcess >;
	static null_ResultVoiceFileStatisticsProcess *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ResultVoiceFileStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ResultVoiceFileStatisticsProcess > createClone() const throw();

private:
	null_ResultVoiceFileStatisticsProcess( const null_ResultVoiceFileStatisticsProcess &other ) throw();
	const null_ResultVoiceFileStatisticsProcess &operator =( const null_ResultVoiceFileStatisticsProcess &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
