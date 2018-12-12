#include "MulArrayDeletionInformation.h"

namespace jmsf {
namespace debugging {

MulArrayDeletionInformation::~MulArrayDeletionInformation() throw()
{}

MulArrayDeletionInformation::MulArrayDeletionInformation(
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

natural_size MulArrayDeletionInformation::getAddressOfObject() const throw() {
	return _addressOfObject;
}

const char_type *const MulArrayDeletionInformation::getNameOfClass() const throw() {
	return _nameOfClass;
}

natural_size MulArrayDeletionInformation::getSizeOfObject() const throw() {
	return _sizeOfObject;
}

natural_size MulArrayDeletionInformation::getQuantityOfObjects() const throw() {
	return _quantityOfObjects;
}

const char_type *const MulArrayDeletionInformation::getPathToFile() const throw() {
	return _pathToFile;
}

natural_size MulArrayDeletionInformation::getNumberOfLine() const throw() {
	return _numberOfLine;
}

MulArrayDeletionInformation::MulArrayDeletionInformation( const MulArrayDeletionInformation &other ) throw() // other
	:
		_addressOfObject( other._addressOfObject ),
		_nameOfClass( other._nameOfClass ),
		_sizeOfObject( other._sizeOfObject ),
		_quantityOfObjects( other._quantityOfObjects ),
		_pathToFile( other._pathToFile ),
		_numberOfLine( other._numberOfLine )
{}

const MulArrayDeletionInformation &MulArrayDeletionInformation::operator =( const MulArrayDeletionInformation &other ) throw() {
	if ( this != &other ) return *this;

	return *this;	
}


} // namespace debugging
} // namespace jmsf