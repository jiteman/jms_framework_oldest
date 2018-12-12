#pragma once

#include "jmsf/Object.h"

#include "jmsf/osie/File.hxx"
#include "jmsf/Proxies.hxx"

#include "../jmsf.h"

namespace jmsf {
namespace osie {

class JMSF_DLL_INTERFACE FileSystemControl :
	public virtual Object
{

public:
// 	virtual Proxy< File > createBufferedFileForInput() = 0;
// 	virtual Proxy< File > createBufferedFileForOutput() = 0;
// 	virtual Proxy< File > createBufferedFileForInputAndOutput() = 0;
// 
// 	virtual Proxy< File > createNonbufferedFileForInput() = 0;
// 	virtual Proxy< File > createNonbufferedFileForOutput() = 0;
// 	virtual Proxy< File > createNonbufferedFileForInputAndOutput() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static FileSystemControl *getNull() throw();
	static FileSystemControl *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual Proxy< FileSystemControl > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace osie
} // namespace jmsf
