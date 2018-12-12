#pragma once

#include "jmsf/Object.h"

#include "jmsf/Proxies.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {


class JMSF_DLL_INTERFACE Mutex :
	public virtual ::jmsf::Object
{

public:
	virtual void lock() throw() = 0;
	virtual void unlock() throw() = 0;
	virtual types::Boolean tryToLock() throw() = 0;
	virtual types::Boolean isLocked() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Mutex *getNull() throw();
	static Mutex *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual ::jmsf::Proxy< Mutex > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
