#pragma once

#include "jmsf/Object.h"

#include "jmsf/Proxies.hxx"

#include "../jmsf.h"


namespace jmsf {
namespace osie {


class JMSF_DLL_INTERFACE Event :
	public virtual ::jmsf::Object
{

public:
	virtual void set() throw() = 0;
	virtual Boolean isSet() const throw() = 0;
	virtual Boolean isNotSet() const throw() = 0;
	virtual void reset() throw() = 0;
	virtual void wait() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Event *getNull() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< Event > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
