#pragma once

#include "../NewServiceFileStatisticsProcess.h"
#include "jmsf/osie/runup/mixin_nulls/mixin_null_Runnable.h"
#include "jmsf/mixin_nulls/mixin_null_Object.h"
#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace statistics {
namespace nulls {


class null_NewServiceFileStatisticsProcess :
	public NewServiceFileStatisticsProcess,
	public ::jmsf::osie::runup::mixin_nulls::mixin_null_Runnable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_NewServiceFileStatisticsProcess >
{

public:
	// virtuals NewServiceFileStatisticsProcess
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_NewServiceFileStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_NewServiceFileStatisticsProcess >;
	static null_NewServiceFileStatisticsProcess *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_NewServiceFileStatisticsProcess() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< NewServiceFileStatisticsProcess > createClone() const throw();

private:
	null_NewServiceFileStatisticsProcess( const null_NewServiceFileStatisticsProcess &other ) throw();
	const null_NewServiceFileStatisticsProcess &operator =( const null_NewServiceFileStatisticsProcess &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
