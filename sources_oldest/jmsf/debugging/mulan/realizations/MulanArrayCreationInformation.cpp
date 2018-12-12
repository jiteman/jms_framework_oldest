#include "MulanArrayCreationInformation.h"

namespace jmsf {
namespace debugging {
namespace mulan {
namespace realizations {

MulanArrayCreationInformation::~MulanArrayCreationInformation() throw()
{}

MulanArrayCreationInformation::MulanArrayCreationInformation(
	const natural_size addressOfObject,
	const std::string &nameOfClass,
	const natural_size sizeOfObject,
	const natural_size quantityOfObjects,
	const std::string &pathToFile,
	const natural_size numberOfLine ) throw()
	:
		_addressOfObject( addressOfObject ),
		_nameOfClass( nameOfClass ),
		_sizeOfObject( sizeOfObject ),
		_quantityOfObjects( quantityOfObjects ),
		_pathToFile( pathToFile ),
		_numberOfLine( numberOfLine )
{}

natural_size MulanArrayCreationInformation::getAddressOfObject() const throw() {
	return _addressOfObject;
}

const std::string &MulanArrayCreationInformation::getNameOfClass() const throw() {
	return _nameOfClass;
}

natural_size MulanArrayCreationInformation::getSizeOfObject() const throw() {
	return _sizeOfObject;
}

natural_size MulanArrayCreationInformation::getQuantityOfObjects() const throw() {
	return _quantityOfObjects;
}

const std::string &MulanArrayCreationInformation::getPathToFile() const throw() {
	return _pathToFile;
}

natural_size MulanArrayCreationInformation::getNumberOfLine() const throw() {
	return _numberOfLine;
}

MulanArrayCreationInformation::MulanArrayCreationInformation() throw()
	:
		_addressOfObject( 0 ),
		_sizeOfObject( 0 ),
		_quantityOfObjects( 0 ),
		_numberOfLine( 0 )
{}

MulanArrayCreationInformation::MulanArrayCreationInformation( const MulanArrayCreationInformation &other ) throw() // other
	:
		_addressOfObject( other._addressOfObject ),
		_nameOfClass( other._nameOfClass ),
		_sizeOfObject( other._sizeOfObject ),
		_quantityOfObjects( other._quantityOfObjects ),
		_pathToFile( other._pathToFile ),
		_numberOfLine( other._numberOfLine )
{}

const MulanArrayCreationInformation &MulanArrayCreationInformation::operator =( const MulanArrayCreationInformation &other ) throw() {
	if ( this != &other ) return *this;

	_addressOfObject = other._addressOfObject;
	_nameOfClass = other._nameOfClass;
	_sizeOfObject = other._sizeOfObject;
	_quantityOfObjects = other._quantityOfObjects;
	_pathToFile = other._pathToFile;
	_numberOfLine = other._numberOfLine;
	return *this;	
}

} // namespace realizations
} // namespace mulan
} // namespace debugging
} // namespace jmsf