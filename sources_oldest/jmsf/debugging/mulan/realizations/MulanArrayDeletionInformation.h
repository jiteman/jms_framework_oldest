#pragma once

#include "jmsf/types.h"
#include "jmsf/stdal/stdal_stl.h"

namespace jmsf {
namespace debugging {
namespace mulan {
namespace realizations {

class MulanArrayDeletionInformation {

public:
	~MulanArrayDeletionInformation() throw();

	MulanArrayDeletionInformation(
		natural_size addressOfObject,
		const std::string &nameOfClass,
		natural_size sizeOfObject,
		natural_size quantityOfObjects,
		const std::string &pathToFile,
		natural_size numberOfLine ) throw();

	natural_size getAddressOfObject() const throw();
	const std::string &getNameOfClass() const throw();
	natural_size getSizeOfObject() const throw();
	natural_size getQuantityOfObjects() const throw();
	const std::string &getPathToFile() const throw();
	natural_size getNumberOfLine() const throw();

public:
	MulanArrayDeletionInformation() throw();
	MulanArrayDeletionInformation( const MulanArrayDeletionInformation &other ) throw();

private:
	const MulanArrayDeletionInformation &operator =( const MulanArrayDeletionInformation &other ) throw();

private:
	 natural_size _addressOfObject;
	 std::string _nameOfClass;
	 natural_size _sizeOfObject;
	 natural_size _quantityOfObjects;
	 std::string _pathToFile;
	 natural_size _numberOfLine;

};

} // namespace realizations
} // namespace mulan
} // namespace debugging
} // namespace jmsf
