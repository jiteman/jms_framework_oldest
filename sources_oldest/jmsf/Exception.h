#pragma once

#include "TextString.hxx"
#include "Proxies.hxx"
#include "types/Natural.hxx"

//#include "warning_suppressor.h"
#include "jmsf.h"


namespace jmsf {


class JMSF_DLL_INTERFACE Exception {

public:
	virtual const ConstantProxy< TextString > &getName() const throw() = 0;
	virtual const ConstantProxy< TextString > &getReason() const throw() = 0;
	virtual const ConstantProxy< TextString > &getFilename() const throw() = 0;
	virtual const types::Natural getLineNumber() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	virtual ~Exception() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace
