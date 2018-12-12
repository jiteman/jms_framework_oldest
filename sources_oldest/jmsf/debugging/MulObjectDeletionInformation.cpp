#include "MulObjectDeletionInformation.h"

namespace jmsf {
namespace debugging {

MulObjectDeletionInformation::~MulObjectDeletionInformation() throw()
{}

MulObjectDeletionInformation::MulObjectDeletionInformation(
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

natural_size MulObjectDeletionInformation::getAddressOfObject() const throw() {
	return _addressOfObject;
}

const char_type *const MulObjectDeletionInformation::getNameOfClass() const throw() {
	return _nameOfClass;
}

natural_size MulObjectDeletionInformation::getSizeOfObject() const throw() {
	return _sizeOfObject;
}

const char_type *const MulObjectDeletionInformation::getPathToFile() const throw() {
	return _pathToFile;
}

natural_size MulObjectDeletionInformation::getNumberOfLine() const throw() {
	return _numberOfLine;
}

MulObjectDeletionInformation::MulObjectDeletionInformation( const MulObjectDeletionInformation &other ) throw() // other
	:
		_addressOfObject( other._addressOfObject ),
		_nameOfClass( other._nameOfClass ),
		_sizeOfObject( other._sizeOfObject ),
		_pathToFile( other._pathToFile ),
		_numberOfLine( other._numberOfLine )
{}

const MulObjectDeletionInformation &MulObjectDeletionInformation::operator =( const MulObjectDeletionInformation &other ) throw() {
	if ( this != &other ) return *this;

	return *this;	
}


} // namespace debugging
} // namespace jmsf