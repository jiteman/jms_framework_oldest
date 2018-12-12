#pragma once


#include "jmsf/patterning/Object.h"

#include "jmsf/texting/TextString.hxx"
#include "jmsf/pointing/Proxy.hxx"
#include "jmsf/pointing/ConstantProxy.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {


class JMSF_DLL_INTERFACE PopUpMessage :
	public virtual patterning::Object
{

public:
	virtual void showOk( const pointing::ConstantProxy< texting::TextString > &message ) const throw() = 0;
	virtual const typing::Boolean showOkCancel( const pointing::ConstantProxy< texting::TextString > &message ) const throw() = 0;

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
	virtual pointing::Proxy< PopUpMessage > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace osie
} // namespace jmsf
