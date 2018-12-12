#pragma once


#include "jmsf/patterning/Object.h"

//#include "jmsf/Proxies.hxx"

#include "jmsf/pointing/Proxy.hxx"
#include "jmsf/memorying/Womp.hxx"


namespace jmsf {
namespace testing {


class testing_Proxie :
	public virtual ::jmsf::patterning::Object
{

public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static memorying::Womp< testing_Proxie > &get_null_object() throw();
	static memorying::Womp< testing_Proxie > &get_exception_object() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
//	virtual ::jmsf::pointing::Proxy< testing_Proxie > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace testing
} // namespace jmsf
