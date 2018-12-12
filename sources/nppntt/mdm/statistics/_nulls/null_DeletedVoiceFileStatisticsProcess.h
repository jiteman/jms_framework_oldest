#pragma once

#include "../DeletedVoiceFileStatisticsProcess.h"
#include "jmsf/osie/runup/mixin_nulls/mixin_null_Runnable.h"
#include "jmsf/mixin_nulls/mixin_null_Object.h"
#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {


class null_DeletedVoiceFileStatisticsProcess :
	public DeletedVoiceFileStatisticsProcess,
	public ::jmsf::osie::runup::mixin_nulls::mixin_null_Runnable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_DeletedVoiceFileStatisticsProcess >
{

public:
	// virtuals DeletedVoiceFileStatisticsQueue
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_DeletedVoiceFileStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_DeletedVoiceFileStatisticsProcess >;
	static null_DeletedVoiceFileStatisticsProcess *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_DeletedVoiceFileStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< DeletedVoiceFileStatisticsProcess > createClone() const throw();

private:
	null_DeletedVoiceFileStatisticsProcess( const null_DeletedVoiceFileStatisticsProcess &other ) throw();
	const null_DeletedVoiceFileStatisticsProcess &operator =( const null_DeletedVoiceFileStatisticsProcess &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
