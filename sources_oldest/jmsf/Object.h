#pragma once


#include "jmsf/Exception.hxx"
#include "jmsf/types/Boolean.hxx"

#include "jmsf.h"


namespace jmsf {


class JMSF_DLL_INTERFACE Object {

public:	
	virtual const types::Boolean isNull() const throw() = 0;
	virtual const types::Boolean isException() const throw() = 0;	

	virtual void throwIfException() const throw( Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const types::Boolean isReal() const throw();
	void _deleteThisIfReal() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	virtual ~Object() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace
