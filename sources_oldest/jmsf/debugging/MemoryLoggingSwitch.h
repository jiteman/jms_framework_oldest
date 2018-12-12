#pragma once

#include "jmsf/Boolean.h"
#include "jmsf/jmsf.h"

namespace jmsf {
namespace debugging {

class JMSF_DLL_INTERFACE MemoryLoggingSwitch {

public:
	static Boolean _isOn;

public:
	static void turnOn() throw();
	static void turnOff() throw();
	static Boolean isOn() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	~MemoryLoggingSwitch() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	MemoryLoggingSwitch() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	MemoryLoggingSwitch( const MemoryLoggingSwitch &other ) throw();
	const MemoryLoggingSwitch &operator =( const MemoryLoggingSwitch &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};



} // namespace debugging
} // namespace jmsf