#pragma once

#include "../RecurrentVoiceFileAndKeyMatchFinder.h"

#include "jmsf/osie/runup/mixin_nulls/mixin_null_Runnable.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {


class null_RecurrentVoiceFileAndKeyMatchFinder :
	public RecurrentVoiceFileAndKeyMatchFinder,
	public ::jmsf::osie::runup::mixin_nulls::mixin_null_Runnable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_RecurrentVoiceFileAndKeyMatchFinder >
{

public:
	// virtuals RecurrentVoiceFileAndKeyMatchFinder
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_RecurrentVoiceFileAndKeyMatchFinder() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_RecurrentVoiceFileAndKeyMatchFinder >;
	static null_RecurrentVoiceFileAndKeyMatchFinder *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_RecurrentVoiceFileAndKeyMatchFinder() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< RecurrentVoiceFileAndKeyMatchFinder > createClone() const throw();

private:
	null_RecurrentVoiceFileAndKeyMatchFinder( const null_RecurrentVoiceFileAndKeyMatchFinder &other ) throw();
	const null_RecurrentVoiceFileAndKeyMatchFinder &operator =( const null_RecurrentVoiceFileAndKeyMatchFinder &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
