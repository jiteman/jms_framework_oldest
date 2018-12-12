#include "MemoryLoggingSwitch.h"

namespace jmsf {
namespace debugging {

// static
Boolean MemoryLoggingSwitch::_isOn = False;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
void MemoryLoggingSwitch::turnOn() throw() {
	_isOn = True;
}

// static
void MemoryLoggingSwitch::turnOff() throw() {
	_isOn = False;
}

// static
Boolean MemoryLoggingSwitch::isOn() throw() {
	return _isOn;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
MemoryLoggingSwitch::~MemoryLoggingSwitch() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
MemoryLoggingSwitch::MemoryLoggingSwitch() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
MemoryLoggingSwitch::MemoryLoggingSwitch( const MemoryLoggingSwitch & ) throw() // other
{}

const MemoryLoggingSwitch &MemoryLoggingSwitch::operator =( const MemoryLoggingSwitch &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace debugging
} // namespace jmsf
