#include "static_ObjectCreationLogger.h"
#include "MulObjectCreationInformation.h"
#include "jmsf/debugging/MemoryLoggingSwitch.h"
#include "jmsf/osie/static_factory_OperatingSystemSpecial.h"
#include "jmsf/osie/Mutex.h"
#include "jmsf/Automatic.hpp"
#include "jmsf/Boolean.h"

namespace jmsf {
namespace debugging {

// static
void static_ObjectCreationLogger::registerCreation( const MulObjectCreationInformation &objectCreationInformation ) throw() {
	if ( MemoryLoggingSwitch::isOn().not() ) return;

	if ( _isInitialized.not() ) {
		initialize();
	}

	_logFile << objectCreationInformation.getAddressOfObject() << "\t";
	_logFile << objectCreationInformation.getNameOfClass() << "\t";
	_logFile << std::setbase( 10 ) << objectCreationInformation.getSizeOfObject() << "\t";
	_logFile << objectCreationInformation.getPathToFile() << "\t";
	_logFile << objectCreationInformation.getNumberOfLine() << std::endl;

	_objectCreationCounter += 1;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
static_ObjectCreationLogger::~static_ObjectCreationLogger() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static_ObjectCreationLogger::static_ObjectCreationLogger() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static_ObjectCreationLogger::static_ObjectCreationLogger( const static_ObjectCreationLogger & ) throw() // other
{}

const static_ObjectCreationLogger &static_ObjectCreationLogger::operator =( const static_ObjectCreationLogger &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// static
void static_ObjectCreationLogger::initialize() throw() {
	if ( _isInitialized.not() ) {
		osie::static_factory_OperatingSystemSpecial::takeOperatingSystemMutex()->lock();

		if ( _isInitialized.not() ) {
			_objectCreationLoggerMutex = osie::static_factory_OperatingSystemSpecial::createAutomaticMutex();
			_logFile.open( "ObjectCreationLog.txt", std::ios_base::out );
			_logFile << "Address\t";
			_logFile << "Type\t";
			_logFile << "Size of type\t";
			_logFile << "Path to file\t";
			_logFile << "Number of line" << std::endl;
		}

		_isInitialized = True;
		osie::static_factory_OperatingSystemSpecial::takeOperatingSystemMutex()->unlock();
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// static
std::ofstream static_ObjectCreationLogger::_logFile;

// static
Automatic< osie::Mutex > static_ObjectCreationLogger::_objectCreationLoggerMutex;

// static
natural_size static_ObjectCreationLogger::_objectCreationCounter = 0;

// static
Boolean static_ObjectCreationLogger::_isInitialized;

} // namespace debugging
} // namespace jmsf
