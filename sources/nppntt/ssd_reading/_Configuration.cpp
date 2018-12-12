#include "Configuration.h"
#include "exceptions/exception_SsdReading.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/TextStream.h"
#include "jmsf/stdal/stdal_stl.h"


namespace nppntt {
namespace ssd_reading {


// static
std::string Configuration::PATH_TO_CONFIGURATION_FILES = "";
// static
const std::string Configuration::CONFIGURATION_FILENAME = "configuration.ini";

// static
const std::string Configuration::ABSOLUTE_VALUE = "absolute";

// static
const std::string Configuration::RELATIVE_VALUE = "relative";


::jmsf::natural_size Configuration::getQuantityOfReadingChannels() const throw() {
	return _quantityOfReadingChannels;
}

const DriveTable &Configuration::getDriveTable() const throw() {
	return *_driveTable;
}

const VirtualFileTable &Configuration::getVirtualFileTable() const throw() {
	return *_virtualFileTable;
}

// RequestDataFileReader &Configuration::getRequestDataFileReader() throw() {
// 	return *_requestDataFileReader;
// }


// static
const std::string Configuration::readPath( std::ifstream &file ) throw( ::jmsf::Exception ) {
	std::string typeOfPath;
	file >> typeOfPath;
	std::string path;
	file >> path;

	if ( typeOfPath == ABSOLUTE_VALUE ) {
		return path;
	} else if ( typeOfPath == RELATIVE_VALUE ) {
		return PATH_TO_CONFIGURATION_FILES + path;
	} else {
		::jmsf::Proxy< ::jmsf::TextStream > textStream = ::jmsf::factory_TextObject::instance()->createTextStream();
		textStream->put( ::jmsf::CONSTANT_TEXT_STRING( "Configuration::readPath() - unknown type of path: " ) )->put( ::jmsf::TEXT_STRING( typeOfPath.c_str() ) );
		throw exceptions::exception_SsdReading( textStream );
	}
}

// static	
::jmsf::Pointer< Configuration > Configuration::_instance = ::jmsf::Pointer< Configuration >::createEmpty();

// static
::jmsf::Proxy< ::jmsf::osie::Mutex > Configuration::_synchronizer = ::jmsf::osie::runup::Mutex::create();

// static
Configuration *Configuration::instance() throw( ::jmsf::Exception ) {
	Configuration *currentInstance = _instance.get();

	if ( currentInstance == nullptr ) {
		_synchronizer->lock();
		currentInstance = _instance.get();

		if ( currentInstance == nullptr ) {		
			currentInstance = new Configuration( PATH_TO_CONFIGURATION_FILES + CONFIGURATION_FILENAME );

			_instance = ::jmsf::Pointer< Configuration >::createUnique( currentInstance );
		}

		_synchronizer->unlock();
	}

	return currentInstance;
}


Configuration::~Configuration() throw()
{}

Configuration::Configuration( const std::string &pathToConfigurationFile ) throw( ::jmsf::Exception )
	:
		_driveTable( ::jmsf::Pointer< DriveTable >::createUnique() ),
		_virtualFileTable( ::jmsf::Pointer< VirtualFileTable >::createUnique() )
{
	std::ifstream configurationFile( pathToConfigurationFile );

	if ( ::jmsf::Boolean( configurationFile.is_open() ).not() ) {
		::jmsf::Proxy< ::jmsf::TextStream > textStream = ::jmsf::factory_TextObject::instance()->createTextStream();
		textStream->put( ::jmsf::CONSTANT_TEXT_STRING( "Configuration::Configuration() - can't open configuration file at: " ) )->put( ::jmsf::TEXT_STRING( pathToConfigurationFile.c_str() ) );
		throw exceptions::exception_SsdReading( textStream );
	}

	_quantityOfReadingChannels = 0;
	configurationFile >> _quantityOfReadingChannels;

//	_requestDataFileReader = RequestDataFileReader::create( readPath( configurationFile ) );
	_driveTable = DriveTable::create( readPath( configurationFile ) );
	_virtualFileTable = VirtualFileTable::create( readPath( configurationFile ) );
}

Configuration::Configuration( const Configuration & ) throw() // other
	:
		_driveTable( ::jmsf::Pointer< DriveTable >::createUnique() ),
		_virtualFileTable( ::jmsf::Pointer< VirtualFileTable >::createUnique() )
{}

const Configuration &Configuration::operator =( const Configuration &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}


} // namespace
}