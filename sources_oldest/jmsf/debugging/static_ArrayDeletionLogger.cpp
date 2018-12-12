#include "static_ArrayDeletionLogger.h"
#include "MulArrayDeletionInformation.h"
#include "jmsf/debugging/MemoryLoggingSwitch.h"
#include "jmsf/osie/static_factory_OperatingSystemSpecial.h"
#include "jmsf/osie/Mutex.h"
#include "jmsf/Automatic.hpp"
#include "jmsf/Boolean.h"

namespace jmsf {
namespace debugging {

// static
void static_ArrayDeletionLogger::registerDeletion( const MulArrayDeletionInformation &mulArrayDeletionInformation ) throw() {
	if ( MemoryLoggingSwitch::isOn().not() ) return;

	if ( _isInitialized.not() ) {
		initialize();
	}

	_logFile << mulArrayDeletionInformation.getAddressOfObject() << "\t";
	_logFile << mulArrayDeletionInformation.getNameOfClass() << "\t";
	_logFile << std::setbase( 10 ) << mulArrayDeletionInformation.getSizeOfObject() << "\t";
	_logFile << mulArrayDeletionInformation.getQuantityOfObjects() << "\t";
	_logFile << mulArrayDeletionInformation.getPathToFile() << "\t";
	_logFile << mulArrayDeletionInformation.getNumberOfLine() << std::endl;

	_arrayDeletionCounter += 1;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
static_ArrayDeletionLogger::~static_ArrayDeletionLogger() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static_ArrayDeletionLogger::static_ArrayDeletionLogger() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static_ArrayDeletionLogger::static_ArrayDeletionLogger( const static_ArrayDeletionLogger & ) throw() // other
{}

const static_ArrayDeletionLogger &static_ArrayDeletionLogger::operator =( const static_ArrayDeletionLogger &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// static
void static_ArrayDeletionLogger::initialize() throw() {
	if ( _isInitialized.not() ) {
		osie::static_factory_OperatingSystemSpecial::takeOperatingSystemMutex()->lock();

		if ( _isInitialized.not() ) {
			_arrayDeletionLoggerMutex = osie::static_factory_OperatingSystemSpecial::createAutomaticMutex();
			_logFile.open( "ArrayDeletionLog.txt", std::ios_base::out );
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
std::ofstream static_ArrayDeletionLogger::_logFile;

// static
Automatic< osie::Mutex > static_ArrayDeletionLogger::_arrayDeletionLoggerMutex;

// static
natural_size static_ArrayDeletionLogger::_arrayDeletionCounter = 0;

// static
Boolean static_ArrayDeletionLogger::_isInitialized;

} // namespace debugging
} // namespace jmsf
