#pragma once

#include "jmsf/types.h"
#include "jmsf/jmsf.h"

namespace jmsf {
namespace debugging {

class JMSF_DLL_INTERFACE MulArrayDeletionInformation {

public:
	~MulArrayDeletionInformation() throw();

	MulArrayDeletionInformation(
		natural_size addressOfObject,
		const char_type *nameOfClass,
		natural_size sizeOfObject,
		natural_size quantityOfObjects,
		const char_type *pathToFile,
		natural_size numberOfLine ) throw();

	natural_size getAddressOfObject() const throw();
	const char_type *const getNameOfClass() const throw();
	natural_size getSizeOfObject() const throw();
	natural_size getQuantityOfObjects() const throw();
	const char_type *const getPathToFile() const throw();
	natural_size getNumberOfLine() const throw();

public:
	MulArrayDeletionInformation( const MulArrayDeletionInformation &other ) throw();

private:
	const MulArrayDeletionInformation &operator =( const MulArrayDeletionInformation &other ) throw();

private:
	 const natural_size _addressOfObject;
	 const char_type *const _nameOfClass;
	 const natural_size _sizeOfObject;
	 const natural_size _quantityOfObjects;
	 const char_type *const _pathToFile;
	 const natural_size _numberOfLine;

};

} // namespace debugging
} // namespace jmsf
