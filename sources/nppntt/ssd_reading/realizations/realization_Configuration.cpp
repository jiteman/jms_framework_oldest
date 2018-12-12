#include "realization_Configuration.h"
#include "jmsf/Should.h"

namespace nppntt {
namespace ssd_reading {
namespace realizations {

::jmsf::natural_size realization_Configuration::getQuantityOfReadingChannels() const throw() {
	return _quantityOfReadingChannels;
}

const DriveTable &realization_Configuration::getDriveTable() const throw() {
	return *_driveTable;;
}

const VirtualFileTable &realization_Configuration::getVirtualFileTable() const throw() {
	return *_virtualFileTable;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_Configuration::~realization_Configuration() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Configuration::realization_Configuration() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_Configuration::realization_Configuration( const realization_Configuration & ) throw() // other
{}

const realization_Configuration &realization_Configuration::operator =( const realization_Configuration &other ) throw( ::jmsf::Exception ) {
	if ( this == &other ) return *this;

	// copy
	::jmsf::Should::neverViolateCopyingProhibition( "realization_Configuration::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
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

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
std::string Configuration::PATH_TO_CONFIGURATION_FILES = "";
// static
const std::string Configuration::CONFIGURATION_FILENAME = "configuration.ini";

// static
const std::string Configuration::ABSOLUTE_VALUE = "absolute";

// static
const std::string Configuration::RELATIVE_VALUE = "relative";

} // namespace realizations
} // namespace ssd_reading
} // namespace nppntt
