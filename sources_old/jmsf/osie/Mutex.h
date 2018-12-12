#pragma once


#include "jmsf/patterning/Object.h"

#include "jmsf/pointing/Proxy.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {


class JMSF_DLL_INTERFACE Mutex :
	public virtual ::jmsf::patterning::Object
{

public:
	virtual void lock() throw() = 0;
	virtual void unlock() throw() = 0;
	virtual typing::Boolean tryToLock() throw() = 0;
	virtual typing::Boolean isLocked() const throw() = 0;

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
	virtual ::jmsf::pointing::Proxy< Mutex > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
