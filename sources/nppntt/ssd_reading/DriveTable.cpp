#include "DriveTable.h"

#include "exceptions/exception_SsdReading.h"

#include "jmsf/factory_TextObject.h"

#include "jmsf/stdal/stdal_stl.h"

namespace nppntt {
namespace ssd_reading {

const std::vector< const ::jmsf::natural_size > &DriveTable::getDriveIndices() const throw() {
	return _driveIndices;
}


// static
::jmsf::Pointer< DriveTable > DriveTable::create( const std::string &pathToFileConfigurationFile ) throw() {
	return ::jmsf::Pointer< DriveTable >::createUnique( new DriveTable( pathToFileConfigurationFile ) );
}

DriveTable::~DriveTable() throw()
{}

DriveTable::DriveTable( const std::string &pathToFileConfigurationFile ) throw( ::jmsf::Exception ) {
	_driveIndices.reserve( MAX_QUANTITY_OF_DRIVES );
	std::ifstream fileConfigurationFile( pathToFileConfigurationFile );

	if ( ::jmsf::Boolean( fileConfigurationFile.is_open() ).not() ) {
		::jmsf::Proxy< ::jmsf::TextStream > textStream = ::jmsf::factory_TextObject::instance()->createTextStream();
		textStream->put( ::jmsf::CONSTANT_TEXT_STRING( "DriveTable::DriveTable() - can't open drive configuration file at: " ) )->put( ::jmsf::TEXT_STRING( pathToFileConfigurationFile.c_str() ) );
		throw exceptions::exception_SsdReading( textStream );		
	}

	::jmsf::natural_size quantityOfDrives = 0;
	fileConfigurationFile >> quantityOfDrives;
	_sizeOfCluster = 0;
	fileConfigurationFile >> _sizeOfCluster;

	for ( ::jmsf::natural_size driveCounter = 0; driveCounter < quantityOfDrives; driveCounter += 1 ) {
		::jmsf::natural_size indexOfDrive = 0;
		fileConfigurationFile >> indexOfDrive;
		_driveIndices.push_back( indexOfDrive );
	}
}

DriveTable::DriveTable( const DriveTable & ) // other
{}

const DriveTable &DriveTable::operator =( const DriveTable &other ) {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

} // namespace
}
