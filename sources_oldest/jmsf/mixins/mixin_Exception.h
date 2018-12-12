#pragma once

#include "jmsf/Exception.h"
#include "jmsf/Proxies.hpp"
#include "jmsf/TextString.h"
#include "jmsf/TextStream.hxx"
#include "jmsf/jmsf.h"


namespace jmsf {
namespace mixins {


class JMSF_DLL_INTERFACE mixin_Exception :
	public Exception
{

public:
	// virtuals
	const ConstantProxy< TextString > &getName() const throw();
	const ConstantProxy< TextString > &getFilename() const throw();
	const types::Natural getLineNumber() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~mixin_Exception() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_Exception( const ConstantProxy< TextString > &name, const ConstantProxy< TextString > filename, types::Natural lineNumber ) throw();
	mixin_Exception( const Proxy< TextStream > &name, const ConstantProxy< TextString > filename, types::Natural lineNumber ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_Exception( const mixin_Exception &other ) throw();

protected:
	const mixin_Exception &operator =( const mixin_Exception &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const ConstantProxy< TextString > _name;
	const ConstantProxy< TextString > _filename;
	const types::Natural _lineNumber;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
