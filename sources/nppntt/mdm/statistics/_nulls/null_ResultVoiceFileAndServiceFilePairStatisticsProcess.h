#pragma once

#include "../ResultVoiceFileAndServiceFilePairStatisticsProcess.h"

#include "jmsf/osie/runup/mixin_nulls/mixin_null_Runnable.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {


class null_ResultVoiceFileAndServiceFilePairStatisticsProcess :
	public ResultVoiceFileAndServiceFilePairStatisticsProcess,
	public ::jmsf::osie::runup::mixin_nulls::mixin_null_Runnable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_ResultVoiceFileAndServiceFilePairStatisticsProcess >
{

public:
	// virtuals ResultVoiceFileAndServiceFilePairStatisticsProcess
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ResultVoiceFileAndServiceFilePairStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_ResultVoiceFileAndServiceFilePairStatisticsProcess >;
	static null_ResultVoiceFileAndServiceFilePairStatisticsProcess *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ResultVoiceFileAndServiceFilePairStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ResultVoiceFileAndServiceFilePairStatisticsProcess > createClone() const throw();

private:
	null_ResultVoiceFileAndServiceFilePairStatisticsProcess( const null_ResultVoiceFileAndServiceFilePairStatisticsProcess &other ) throw();
	const null_ResultVoiceFileAndServiceFilePairStatisticsProcess &operator =( const null_ResultVoiceFileAndServiceFilePairStatisticsProcess &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
