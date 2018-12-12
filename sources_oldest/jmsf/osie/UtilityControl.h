#pragma once

#include "jmsf/Object.h"

#include "Stopwatch.hxx"
#include "PopUpMessage.hxx"
#include "jmsf/TextString.hxx"
#include "jmsf/Proxies.hxx"

#include "../jmsf.h"

namespace jmsf {
namespace osie {

class JMSF_DLL_INTERFACE UtilityControl :
	public virtual Object
{

public:
	virtual Proxy< Stopwatch > createStopwatch() const throw() = 0;
	virtual Proxy< PopUpMessage > createPopUpMessage() const throw() = 0;
	virtual Proxy< PopUpMessage > createPopUpMessage( const ConstantProxy< TextString > &caption ) const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static UtilityControl *getNull() throw();
	static UtilityControl *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual Proxy< UtilityControl > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace osie
} // namespace jmsf
