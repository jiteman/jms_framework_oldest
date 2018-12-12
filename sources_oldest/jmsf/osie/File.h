#pragma once

#include "jmsf/Object.h"

#include "jmsf/Proxies.hxx"

#include "../jmsf.h"

namespace jmsf {
namespace osie {

class JMSF_DLL_INTERFACE File :
	public virtual Object
{

public:
//	virtual 

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static File *getNull() throw();
	static File *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual Proxy< File > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace osie
} // namespace jmsf
