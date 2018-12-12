#pragma once

#include "jmsf/types.h"
#include "jmsf/stdal/stdal_stl.h"

namespace jmsf {
namespace debugging {
namespace mulan {
namespace realizations {

class MulanObjectCreationInformation {

public:
	~MulanObjectCreationInformation() throw();

	MulanObjectCreationInformation() throw();

	MulanObjectCreationInformation(
		natural_size addressOfObject,
		const std::string &nameOfClass,
		natural_size sizeOfObject,
		const std::string &pathToFile,
		natural_size numberOfLine ) throw();

	natural_size getAddressOfObject() const throw();
	const std::string &getNameOfClass() const throw();
	natural_size getSizeOfObject() const throw();
	const std::string &getPathToFile() const throw();
	natural_size getNumberOfLine() const throw();

public:	
	MulanObjectCreationInformation( const MulanObjectCreationInformation &other ) throw();

private:
	const MulanObjectCreationInformation &operator =( const MulanObjectCreationInformation &other ) throw();

private:
	 natural_size _addressOfObject;
	 std::string _nameOfClass;
	 natural_size _sizeOfObject;
	 std::string _pathToFile;
	 natural_size _numberOfLine;

};

} // namespace realizations
} // namespace mulan
} // namespace debugging
} // namespace jmsf
