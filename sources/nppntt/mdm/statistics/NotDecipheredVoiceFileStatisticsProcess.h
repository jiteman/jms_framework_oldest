#pragma once

#include "jmsf/Object.h"

#include "jmsf/Proxies.hxx"

namespace nppntt {
namespace mdm {
namespace statistics {

class NotDecipheredVoiceFileStatisticsProcess :
	public virtual ::jmsf::Object
{

public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static NotDecipheredVoiceFileStatisticsProcess *getNull() throw();
	static NotDecipheredVoiceFileStatisticsProcess *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< NotDecipheredVoiceFileStatisticsProcess > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace statistics
} // namespace mdm
} // namespace nppntt
