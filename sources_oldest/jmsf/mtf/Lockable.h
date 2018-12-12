#pragma once

#include "jmsf/osie/Mutex.hxx"
#include "jmsf/Proxies.hxx"

#include "../jmsf.h"

namespace jmsf {
namespace mtf {

class JMSF_DLL_INTERFACE Lockable {

public:
	virtual Proxy< osie::Mutex > &takeMutex() const throw() = 0;
	virtual const ConstantProxy< osie::Mutex > &getMutex() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	virtual ~Lockable() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace mtf
} // namespace jmsf
