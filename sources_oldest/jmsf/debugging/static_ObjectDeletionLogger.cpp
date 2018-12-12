#include "static_ObjectDeletionLogger.h"
#include "mulObjectDeletionInformation.h"
#include "jmsf/debugging/MemoryLoggingSwitch.h"
#include "jmsf/osie/static_factory_OperatingSystemSpecial.h"
#include "jmsf/osie/Mutex.h"
#include "jmsf/Automatic.hpp"
#include "jmsf/Boolean.h"


namespace jmsf {
namespace debugging {

// static
void static_ObjectDeletionLogger::registerDeletion( const MulObjectDeletionInformation &mulObjectDeletionInformation ) throw() {
	if ( MemoryLoggingSwitch::isOn().not() ) return;

	if ( _isInitialized.not() ) {
		initialize();
	}

	_logFile << mulObjectDeletionInformation.getAddressOfObject() << "\t";
	_logFile << mulObjectDeletionInformation.getNameOfClass() << "\t";
	_logFile << std::setbase( 10 ) << mulObjectDeletionInformation.getSizeOfObject() << "\t";
	_logFile << mulObjectDeletionInformation.getPathToFile() << "\t";
	_logFile << mulObjectDeletionInformation.getNumberOfLine() << std::endl;

	_objectDeletionCounter += 1;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
static_ObjectDeletionLogger::~static_ObjectDeletionLogger() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static_ObjectDeletionLogger::static_ObjectDeletionLogger() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static_ObjectDeletionLogger::static_ObjectDeletionLogger( const static_ObjectDeletionLogger & ) throw() // other
{}

const static_ObjectDeletionLogger &static_ObjectDeletionLogger::operator =( const static_ObjectDeletionLogger &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// static
void static_ObjectDeletionLogger::initialize() throw() {
	if ( _isInitialized.not() ) {
		osie::static_factory_OperatingSystemSpecial::takeOperatingSystemMutex()->lock();

		if ( _isInitialized.not() ) {
			_objectDeletionLoggerMutex = osie::static_factory_OperatingSystemSpecial::createAutomaticMutex();
			_logFile.open( "ObjectDeletionLog.txt", std::ios_base::out );
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
std::ofstream static_ObjectDeletionLogger::_logFile;

// static
Automatic< osie::Mutex > static_ObjectDeletionLogger::_objectDeletionLoggerMutex;

// static
natural_size static_ObjectDeletionLogger::_objectDeletionCounter = 0;

// static
Boolean static_ObjectDeletionLogger::_isInitialized;

} // namespace debugging
} // namespace jmsf
