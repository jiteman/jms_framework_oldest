#pragma once


#include "jmsf/patterning/Object.h"

#include "Stopwatch.hxx"
#include "PopUpMessage.hxx"
#include "jmsf/texting/TextString.hxx"
#include "jmsf/pointing/Proxy.hxx"
#include "jmsf/pointing/ConstantProxy.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {


class JMSF_DLL_INTERFACE UtilityControl :
	public virtual patterning::Object
{

public:
	virtual pointing::Proxy< Stopwatch > createStopwatch() const throw() = 0;
	virtual pointing::Proxy< PopUpMessage > createPopUpMessage() const throw() = 0;
	virtual pointing::Proxy< PopUpMessage > createPopUpMessage( const pointing::ConstantProxy< texting::TextString > &caption ) const throw() = 0;

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
	virtual pointing::Proxy< UtilityControl > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace osie
} // namespace jmsf
