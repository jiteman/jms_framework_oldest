#pragma once

#include "Object.h"

#include "jmsf/types/internals/internal_types.h"

#include "jmsf.h"

#include "Proxies.hxx"
#include "jmsf/types/Boolean.hxx"


namespace jmsf {


class JMSF_DLL_INTERFACE TextString :
	public virtual Object
{

public:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual const types::internals::platform_char *getCtext() const throw() = 0;
	virtual types::Boolean isEqual( const ConstantProxy< TextString > &other ) const throw() = 0;	

public:
	static TextString *getNull() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual const ConstantProxy< TextString > TextString::createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace
