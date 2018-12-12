#include "MulArrayCreationInformation.h"

namespace jmsf {
namespace debugging {

MulArrayCreationInformation::~MulArrayCreationInformation() throw()
{}

MulArrayCreationInformation::MulArrayCreationInformation(
	const natural_size addressOfObject,
	const char_type *const nameOfClass,
	const natural_size sizeOfObject,
	const natural_size quantityOfObjects,
	const char_type *const pathToFile,
	const natural_size numberOfLine ) throw()
	:
		_addressOfObject( addressOfObject ),
		_nameOfClass( nameOfClass ),
		_sizeOfObject( sizeOfObject ),
		_quantityOfObjects( quantityOfObjects ),
		_pathToFile( pathToFile ),
		_numberOfLine( numberOfLine )
{}

natural_size MulArrayCreationInformation::getAddressOfObject() const throw() {
	return _addressOfObject;
}

const char_type *const MulArrayCreationInformation::getNameOfClass() const throw() {
	return _nameOfClass;
}

natural_size MulArrayCreationInformation::getSizeOfObject() const throw() {
	return _sizeOfObject;
}

natural_size MulArrayCreationInformation::getQuantityOfObjects() const throw() {
	return _quantityOfObjects;
}

const char_type *const MulArrayCreationInformation::getPathToFile() const throw() {
	return _pathToFile;
}

natural_size MulArrayCreationInformation::getNumberOfLine() const throw() {
	return _numberOfLine;
}

MulArrayCreationInformation::MulArrayCreationInformation( const MulArrayCreationInformation &other ) throw() // other
	:
		_addressOfObject( other._addressOfObject ),
		_nameOfClass( other._nameOfClass ),
		_sizeOfObject( other._sizeOfObject ),
		_quantityOfObjects( other._quantityOfObjects ),
		_pathToFile( other._pathToFile ),
		_numberOfLine( other._numberOfLine )
{}

const MulArrayCreationInformation &MulArrayCreationInformation::operator =( const MulArrayCreationInformation &other ) throw() {
	if ( this != &other ) return *this;

	return *this;	
}


} // namespace debugging
} // namespace jmsf