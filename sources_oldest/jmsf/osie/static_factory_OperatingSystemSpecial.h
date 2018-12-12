#pragma once

#include "Mutex.hxx"
#include "Stopwatch.hxx"
#include "jmsf/Automatic.hxx"

#include "../jmsf.h"

namespace jmsf {
namespace osie {

class JMSF_DLL_INTERFACE static_factory_OperatingSystemSpecial {

public:
	static Automatic< Stopwatch > createAutomaticStopwatch() throw();
	static Automatic< Mutex > createAutomaticMutex() throw();
	static Mutex *takeOperatingSystemMutex() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static void initialize() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	~static_factory_OperatingSystemSpecial() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static_factory_OperatingSystemSpecial() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static_factory_OperatingSystemSpecial( const static_factory_OperatingSystemSpecial &other ) throw();
	const static_factory_OperatingSystemSpecial &operator =( const static_factory_OperatingSystemSpecial &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static Automatic< Mutex > _static_operatingSystemMutex;

};


} // namespace osie
} // namespace jmsf
