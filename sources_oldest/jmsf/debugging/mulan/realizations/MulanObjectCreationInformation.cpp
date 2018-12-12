#include "MulanObjectCreationInformation.h"

namespace jmsf {
namespace debugging {
namespace mulan {
namespace realizations {

MulanObjectCreationInformation::~MulanObjectCreationInformation() throw()
{}

MulanObjectCreationInformation::MulanObjectCreationInformation(
	const natural_size addressOfObject,
	const std::string &nameOfClass,
	const natural_size sizeOfObject,
	const std::string &pathToFile,
	const natural_size numberOfLine ) throw()
	:
		_addressOfObject( addressOfObject ),
		_nameOfClass( nameOfClass ),
		_sizeOfObject( sizeOfObject ),
		_pathToFile( pathToFile ),
		_numberOfLine( numberOfLine )
{}

natural_size MulanObjectCreationInformation::getAddressOfObject() const throw() {
	return _addressOfObject;
}

const std::string &MulanObjectCreationInformation::getNameOfClass() const throw() {
	return _nameOfClass;
}

natural_size MulanObjectCreationInformation::getSizeOfObject() const throw() {
	return _sizeOfObject;
}

const std::string &MulanObjectCreationInformation::getPathToFile() const throw() {
	return _pathToFile;
}

natural_size MulanObjectCreationInformation::getNumberOfLine() const throw() {
	return _numberOfLine;
}

MulanObjectCreationInformation::MulanObjectCreationInformation() throw()
	:
		_addressOfObject( 0 ),
		_sizeOfObject( 0 ),
		_numberOfLine( 0 )
{}

MulanObjectCreationInformation::MulanObjectCreationInformation( const MulanObjectCreationInformation &other ) throw() // other
	:
		_addressOfObject( other._addressOfObject ),
		_nameOfClass( other._nameOfClass ),
		_sizeOfObject( other._sizeOfObject ),
		_pathToFile( other._pathToFile ),
		_numberOfLine( other._numberOfLine )
{}

const MulanObjectCreationInformation &MulanObjectCreationInformation::operator =( const MulanObjectCreationInformation &other ) throw() {
	if ( this != &other ) return *this;

	_addressOfObject = other._addressOfObject;
	_nameOfClass = other._nameOfClass;
	_sizeOfObject = other._sizeOfObject;
	_pathToFile = other._pathToFile;
	_numberOfLine = other._numberOfLine;
	return *this;	
}

} // namespace realizations
} // namespace mulan
} // namespace debugging
} // namespace jmsf