#pragma once

#include "Object.h"


#include "TextString.hxx"
#include "Proxies.hxx"
#include "Real.hxx"

#include "jmsf.h"


namespace jmsf {


class JMSF_DLL_INTERFACE TextStream : public virtual Object {

public:
	virtual Proxy< TextStream > put( const ConstantProxy< TextString > &textString ) throw() = 0;
	virtual Proxy< TextStream > putInteger( integer_big value ) throw() = 0;
	virtual Proxy< TextStream > putNatural( natural_big value ) throw() = 0;
	virtual Proxy< TextStream > putReal( const Real &value ) throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual const ConstantProxy< TextString > createTextString() const throw() = 0;
	virtual Proxy< TextStream > setDecimalBase() throw() = 0;
	virtual Proxy< TextStream > setHexadecimalBase() throw() = 0;
	virtual Proxy< TextStream > setWidth( natural_size width ) throw() = 0;
	virtual Proxy< TextStream > setFill( const ConstantProxy< TextString > &fill ) throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static TextStream *getNull() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual Proxy< TextStream > TextStream::createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
