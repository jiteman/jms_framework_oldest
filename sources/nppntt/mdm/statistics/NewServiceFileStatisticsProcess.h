#pragma once

#include "jmsf/Object.h"

#include "jmsf/Proxies.hxx"

namespace nppntt {
namespace mdm {
namespace statistics {

class NewServiceFileStatisticsProcess :
	public virtual ::jmsf::Object
{

public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static NewServiceFileStatisticsProcess *getNull() throw();
	static NewServiceFileStatisticsProcess *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< NewServiceFileStatisticsProcess > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace statistics
} // namespace mdm
} // namespace nppntt
