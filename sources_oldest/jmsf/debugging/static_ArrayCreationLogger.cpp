#include "static_ArrayCreationLogger.h"
#include "jmsf/osie/static_factory_OperatingSystemSpecial.h"
#include "jmsf/osie/Mutex.h"
#include "jmsf/Automatic.hpp"
#include "jmsf/Boolean.h"
#include "MulArrayCreationInformation.h"
#include "MemoryLoggingSwitch.h"

namespace jmsf {
namespace debugging {

// static
void static_ArrayCreationLogger::registerCreation( const MulArrayCreationInformation &mulArrayCreationInformation ) throw() {
	if ( MemoryLoggingSwitch::isOn().not() ) return;

	if ( _isInitialized.not() ) {
		initialize();
	}

	_logFile << mulArrayCreationInformation.getAddressOfObject() << "\t";
	_logFile << mulArrayCreationInformation.getNameOfClass() << "\t";
	_logFile << std::setbase( 10 ) << mulArrayCreationInformation.getSizeOfObject() << "\t";
	_logFile << mulArrayCreationInformation.getQuantityOfObjects() << "\t";
	_logFile << mulArrayCreationInformation.getPathToFile() << "\t";
	_logFile << mulArrayCreationInformation.getNumberOfLine() << std::endl;

	_arrayCreationCounter += 1;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
static_ArrayCreationLogger::~static_ArrayCreationLogger() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static_ArrayCreationLogger::static_ArrayCreationLogger() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static_ArrayCreationLogger::static_ArrayCreationLogger( const static_ArrayCreationLogger & ) throw() // other
{}

const static_ArrayCreationLogger &static_ArrayCreationLogger::operator =( const static_ArrayCreationLogger &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// static
void static_ArrayCreationLogger::initialize() throw() {
	if ( _isInitialized.not() ) {
		osie::static_factory_OperatingSystemSpecial::takeOperatingSystemMutex()->lock();

		if ( _isInitialized.not() ) {
			_arrayCreationLoggerMutex = osie::static_factory_OperatingSystemSpecial::createAutomaticMutex();
			_logFile.open( "ArrayCreationLog.txt", std::ios_base::out );
			_logFile << "Address\t";
			_logFile << "Type\t";
			_logFile << "Size of type\t";
			_logFile << "Quantity of elements\t";
			_logFile << "Path to file\t";
			_logFile << "Number of line" << std::endl;
		}

		_isInitialized = True;
		osie::static_factory_OperatingSystemSpecial::takeOperatingSystemMutex()->unlock();
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// static
std::ofstream static_ArrayCreationLogger::_logFile;

// static
Automatic< osie::Mutex > static_ArrayCreationLogger::_arrayCreationLoggerMutex;

// static
natural_size static_ArrayCreationLogger::_arrayCreationCounter = 0;

// static
Boolean static_ArrayCreationLogger::_isInitialized;

} // namespace debugging
} // namespace jmsf
