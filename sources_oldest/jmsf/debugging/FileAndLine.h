#pragma once


#include "jmsf/TextString.hxx"
#include "jmsf/types/Natural.h"

#include "jmsf/Proxies.hpp"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace debugging {


class JMSF_DLL_INTERFACE FileAndLine {

public:
	const ConstantProxy< TextString > &getFilename() const throw();
	const types::Natural getLineNumber() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~FileAndLine() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	FileAndLine( const ConstantProxy< TextString > &filename, types::Natural lineNumber ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	FileAndLine( const FileAndLine &other ) throw();
	const FileAndLine &operator =( const FileAndLine &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const ConstantProxy< TextString > _filename;
	const types::Natural _lineNubmer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace debugging
} // namespace jmsf
