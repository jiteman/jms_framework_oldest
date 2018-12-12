#include "MulObjectCreationInformation.h"

namespace jmsf {
namespace debugging {

MulObjectCreationInformation::~MulObjectCreationInformation() throw()
{}

MulObjectCreationInformation::MulObjectCreationInformation(
	const natural_size addressOfObject,
	const char_type *const nameOfClass,
	const natural_size sizeOfObject,
	const char_type *const pathToFile,
	const natural_size numberOfLine ) throw()
	:
		_addressOfObject( addressOfObject ),
		_nameOfClass( nameOfClass ),
		_sizeOfObject( sizeOfObject ),
		_pathToFile( pathToFile ),
		_numberOfLine( numberOfLine )
{}

natural_size MulObjectCreationInformation::getAddressOfObject() const throw() {
	return _addressOfObject;
}

const char_type *const MulObjectCreationInformation::getNameOfClass() const throw() {
	return _nameOfClass;
}

natural_size MulObjectCreationInformation::getSizeOfObject() const throw() {
	return _sizeOfObject;
}

const char_type *const MulObjectCreationInformation::getPathToFile() const throw() {
	return _pathToFile;
}

natural_size MulObjectCreationInformation::getNumberOfLine() const throw() {
	return _numberOfLine;
}

MulObjectCreationInformation::MulObjectCreationInformation( const MulObjectCreationInformation &other ) throw() // other
	:
		_addressOfObject( other._addressOfObject ),
		_nameOfClass( other._nameOfClass ),
		_sizeOfObject( other._sizeOfObject ),
		_pathToFile( other._pathToFile ),
		_numberOfLine( other._numberOfLine )
{}

const MulObjectCreationInformation &MulObjectCreationInformation::operator =( const MulObjectCreationInformation &other ) throw() {
	if ( this != &other ) return *this;

	return *this;	
}


} // namespace debugging
} // namespace jmsf