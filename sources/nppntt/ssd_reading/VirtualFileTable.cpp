#include "VirtualFileTable.h"

#include "exceptions/exception_SsdReading.h"

#include "jmsf/factory_TextObject.h"

#include "jmsf/stdal/stdal_stl.h"


namespace nppntt {
namespace ssd_reading {


const VirtualFileTableElement &VirtualFileTable::getElement( const ::jmsf::natural_size numberOfFile ) const throw( ::jmsf::Exception ) {
	const VirtualFileTableElement *fileListElement = nullptr;

	try {
		fileListElement = &_elements.at( numberOfFile );
	} catch ( const std::out_of_range &catched ) {
		::jmsf::Proxy< ::jmsf::TextStream > textStream = ::jmsf::factory_TextObject::instance()->createTextStream();
		textStream->put( ::jmsf::CONSTANT_TEXT_STRING( "FileTable::getElement() - out of range exception by number of file [ " ) );
		textStream->putNatural( numberOfFile );
		textStream->put( ::jmsf::CONSTANT_TEXT_STRING( " ]: " ) );
		textStream->put( ::jmsf::TEXT_STRING( catched.what() ) );
		throw exceptions::exception_SsdReading( textStream );
	} catch ( const std::exception &catched ) {
		::jmsf::Proxy< ::jmsf::TextStream > textStream = ::jmsf::factory_TextObject::instance()->createTextStream();
		textStream->put( ::jmsf::CONSTANT_TEXT_STRING( "FileTable::getElement() - out of range exception by number of file [ " ) );
		textStream->putNatural( numberOfFile );
		textStream->put( ::jmsf::CONSTANT_TEXT_STRING( " ]: " ) );
		textStream->put( ::jmsf::TEXT_STRING( catched.what() ) );
		throw exceptions::exception_SsdReading( textStream );
	}

	return *fileListElement;
}

::jmsf::natural_size VirtualFileTable::getQuantity() const throw() {
	return _elements.size();
}


// static
::jmsf::Pointer< VirtualFileTable > VirtualFileTable::create( const std::string &listFilename ) throw( ::jmsf::Exception ) {
	std::ifstream fileListFile( listFilename );

	if ( ::jmsf::Boolean( fileListFile.is_open() ).not() ) {
		::jmsf::Proxy< ::jmsf::TextStream > textStream = ::jmsf::factory_TextObject::instance()->createTextStream();
		textStream->put( ::jmsf::CONSTANT_TEXT_STRING( "FileTable::create() - can't open file configuration file at: " ) )->put( ::jmsf::TEXT_STRING( listFilename.c_str() ) );
		throw exceptions::exception_SsdReading( textStream );
	}

	return ::jmsf::Pointer< VirtualFileTable >::createUnique( new VirtualFileTable( fileListFile ) );
}

VirtualFileTable::~VirtualFileTable() throw()
{}

VirtualFileTable::VirtualFileTable( std::ifstream &virtualFileTableFile ) throw() {
	::jmsf::natural_big sizeOfCluster = 0;
	virtualFileTableFile >> sizeOfCluster;
	::jmsf::natural_size quantityOfVirtualFiles = 0;	
	virtualFileTableFile >> quantityOfVirtualFiles;
	_elements.reserve( MAX_AMOUNT_OF_VIRTUAL_FILES );
	_elements.resize( quantityOfVirtualFiles );
	::jmsf::natural_big positionStepSize = 0;
	virtualFileTableFile >> positionStepSize;

	for ( ::jmsf::natural_size virtualFileCounter = 0; virtualFileCounter < quantityOfVirtualFiles; virtualFileCounter++ ) {
		::jmsf::natural_size indexOfDrive = 0;
		virtualFileTableFile >> indexOfDrive;
		std::string pathToFile;
		virtualFileTableFile >> pathToFile;
		::jmsf::natural_size numberOfPositionStep = 0;
		virtualFileTableFile >> numberOfPositionStep;
		_elements.at( virtualFileCounter ) = VirtualFileTableElement( sizeOfCluster, pathToFile, indexOfDrive, positionStepSize * numberOfPositionStep );
	}
}

// const std::vector< FileListElement > &FileTable::getElements() const throw() {
// 	return _list;
// }

VirtualFileTable::VirtualFileTable( const VirtualFileTable & ) throw() // other
{}

const VirtualFileTable &VirtualFileTable::operator =( const VirtualFileTable &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}


} // namespace
}
