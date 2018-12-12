#pragma once

#include "jmsf/Object.h"

#include "jmsf/TextString.hxx"
#include "jmsf/Proxies.hxx"

#include "../jmsf.h"

namespace jmsf {
namespace osie {

class JMSF_DLL_INTERFACE PopUpMessage :
	public virtual Object
{

public:
	virtual void showOk( const ConstantProxy< TextString > &message ) const throw() = 0;
	virtual const Boolean showOkCancel( const ConstantProxy< TextString > &message ) const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static PopUpMessage *getNull() throw();
	static PopUpMessage *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual Proxy< PopUpMessage > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace osie
} // namespace jmsf
