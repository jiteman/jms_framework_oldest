#pragma once

#include "jmsf/Object.h"

#include "jmsf/TextString.hxx"
#include "jmsf/Proxies.hxx"
#include "jmsf/Real.hxx"

#include "../jmsf.h"

namespace jmsf {
namespace debugging {

class JMSF_DLL_INTERFACE Log :
	public virtual Object
{

public:
	virtual void putWithEol( const ConstantProxy< TextString > &message ) throw() = 0;
	virtual Proxy< Log > put( const ConstantProxy< TextString > &message ) throw() = 0;
	virtual void putEol() throw() = 0;

	virtual Proxy< Log > putInteger( integer_big value ) throw() = 0;
	virtual Proxy< Log > putNatural( natural_big value ) throw() = 0;
	virtual Proxy< Log > putReal( const Real &value ) throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Log *getNull() throw();
	static Log *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual Proxy< Log > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace debugging
} // namespace jmsf
