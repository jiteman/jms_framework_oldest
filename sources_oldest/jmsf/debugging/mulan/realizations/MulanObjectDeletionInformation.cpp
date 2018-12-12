#include "MulanObjectDeletionInformation.h"

namespace jmsf {
namespace debugging {
namespace mulan {
namespace realizations {

MulanObjectDeletionInformation::~MulanObjectDeletionInformation() throw()
{}

MulanObjectDeletionInformation::MulanObjectDeletionInformation(
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

natural_size MulanObjectDeletionInformation::getAddressOfObject() const throw() {
	return _addressOfObject;
}

const std::string &MulanObjectDeletionInformation::getNameOfClass() const throw() {
	return _nameOfClass;
}

natural_size MulanObjectDeletionInformation::getSizeOfObject() const throw() {
	return _sizeOfObject;
}

const std::string &MulanObjectDeletionInformation::getPathToFile() const throw() {
	return _pathToFile;
}

natural_size MulanObjectDeletionInformation::getNumberOfLine() const throw() {
	return _numberOfLine;
}

MulanObjectDeletionInformation::MulanObjectDeletionInformation() throw()
	:
		_addressOfObject( 0 ),
		_sizeOfObject( 0 ),
		_numberOfLine( 0 )
{}

MulanObjectDeletionInformation::MulanObjectDeletionInformation( const MulanObjectDeletionInformation &other ) throw() // other
	:
		_addressOfObject( other._addressOfObject ),
		_nameOfClass( other._nameOfClass ),
		_sizeOfObject( other._sizeOfObject ),
		_pathToFile( other._pathToFile ),
		_numberOfLine( other._numberOfLine )
{}

const MulanObjectDeletionInformation &MulanObjectDeletionInformation::operator =( const MulanObjectDeletionInformation &other ) throw() {
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