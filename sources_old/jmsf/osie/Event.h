#pragma once


#include "jmsf/patterning/Object.h"

#include "jmsf/pointing/Proxy.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {


class JMSF_DLL_INTERFACE Event :
	public virtual ::jmsf::patterning::Object
{

public:
	virtual void set() throw() = 0;
	virtual typing::Boolean isSet() const throw() = 0;
	virtual typing::Boolean isNotSet() const throw() = 0;
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
	virtual ::jmsf::pointing::Proxy< Event > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
