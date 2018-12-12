#pragma once

#include "../PreliminaryVoiceFileAndKeyMatchFinder.h"

#include "jmsf/osie/runup/mixin_nulls/mixin_null_Runnable.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {


class null_PreliminaryVoiceFileAndKeyMatchFinder :
	public PreliminaryVoiceFileAndKeyMatchFinder,
	public ::jmsf::osie::runup::mixin_nulls::mixin_null_Runnable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_PreliminaryVoiceFileAndKeyMatchFinder >
{

public:
	// virtuals PreliminaryVoiceFileAndKeyMatchFinder
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_PreliminaryVoiceFileAndKeyMatchFinder() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_PreliminaryVoiceFileAndKeyMatchFinder >;
	static null_PreliminaryVoiceFileAndKeyMatchFinder *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_PreliminaryVoiceFileAndKeyMatchFinder() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< PreliminaryVoiceFileAndKeyMatchFinder > createClone() const throw();

private:
	null_PreliminaryVoiceFileAndKeyMatchFinder( const null_PreliminaryVoiceFileAndKeyMatchFinder &other ) throw();
	const null_PreliminaryVoiceFileAndKeyMatchFinder &operator =( const null_PreliminaryVoiceFileAndKeyMatchFinder &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
