#pragma once


#include "../types.h"
#include "../Boolean.h"

#include "../Exception.hxx"

#include "../jmsf.h"


namespace jmsf {
namespace base_pointing {


class JMSF_DLL_INTERFACE ReferenceCounters {

public:
	~ReferenceCounters() throw( Exception ); // it is bad, but this exception means a failure, not an error.
	ReferenceCounters() throw();	

	Boolean isStrongNull() const throw();
	Boolean isWeakNull() const throw();
	Boolean areNull() const throw();

	natural_size getConnectivity() const throw();

	void increaseStrong() throw();
	void decreaseStrong() throw();
	void increaseWeak() throw();
	void decreaseWeak() throw();

private:
	natural_size _strong;
	natural_size _weak;

};


} // namespace base_pointing
} // namespace jmsf
