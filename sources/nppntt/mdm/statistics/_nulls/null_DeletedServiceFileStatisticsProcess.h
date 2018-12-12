#pragma once

#include "../DeletedServiceFileStatisticsProcess.h"
#include "jmsf/osie/runup/mixin_nulls/mixin_null_Runnable.h"
#include "jmsf/mixin_nulls/mixin_null_Object.h"
#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {


class null_DeletedServiceFileStatisticsProcess :
	public DeletedServiceFileStatisticsProcess,
	public ::jmsf::osie::runup::mixin_nulls::mixin_null_Runnable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_DeletedServiceFileStatisticsProcess >
{

public:
	// virtuals DeletedServiceFileStatisticsQueue
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_DeletedServiceFileStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_DeletedServiceFileStatisticsProcess >;
	static null_DeletedServiceFileStatisticsProcess *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_DeletedServiceFileStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< DeletedServiceFileStatisticsProcess > createClone() const throw();

private:
	null_DeletedServiceFileStatisticsProcess( const null_DeletedServiceFileStatisticsProcess &other ) throw();
	const null_DeletedServiceFileStatisticsProcess &operator =( const null_DeletedServiceFileStatisticsProcess &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
