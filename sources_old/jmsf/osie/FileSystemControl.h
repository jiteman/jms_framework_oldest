#pragma once


#include "jmsf/patterning/Object.h"

#include "jmsf/osie/File.hxx"
#include "jmsf/pointing/Proxy.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {


class JMSF_DLL_INTERFACE FileSystemControl :
	public virtual patterning::Object
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
	virtual pointing::Proxy< FileSystemControl > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace osie
} // namespace jmsf
