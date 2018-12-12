#pragma once


#include "jmsf/types/Asd.h"
#include "jmsf/types/Natural.h"
#include "jmsf/debugging/FileAndLine.h"
#include "jmsf/Proxies.hpp"


#include "jmsf/jmsf.h"


//#include "jmsf/Proxies.hpp"

//#include "jmsf/TextString.h"


namespace jmsf {
namespace debugging {


class JMSF_DLL_INTERFACE MulObjectCreationInformation {

public:
	~MulObjectCreationInformation() throw();

	MulObjectCreationInformation(
		types::Asd addressOfObject,
		const ConstantProxy< TextString > &nameOfClass,
		types::Natural sizeOfObject,
		const debugging::FileAndLine &fileAndLine ) throw();

	const types::Asd &getAddressOfObject() const throw();
	const ConstantProxy< TextString > &getNameOfClass() const throw();
	types::Natural getSizeOfObject() const throw();
	const debugging::FileAndLine &getFileAndLine() const throw();

public:
	MulObjectCreationInformation( const MulObjectCreationInformation &other ) throw();

private:
	const MulObjectCreationInformation &operator =( const MulObjectCreationInformation &other ) throw();

private:
	 const types::Asd _addressOfObject;
	 const ConstantProxy< TextString > _nameOfClass;
	 const types::Natural _sizeOfObject;
	 const debugging::FileAndLine _fileAndLine;

};


} // namespace debugging
} // namespace jmsf
