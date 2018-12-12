#pragma once

#include "jmsf/Object.h"

#include "mulan.h"

#include "jmsf/Proxies.hxx"
#include "jmsf/Boolean.hxx"

namespace jmsf {
namespace debugging {
namespace mulan {

class JMSF_MULE_ANALYZER_DLL_INTERFACE MuleAnalyzer :
	public virtual Object
{

public:
	virtual Boolean readCollectedData() throw() = 0;
	virtual void performAnalysis() throw() = 0;
	virtual void showResults() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static MuleAnalyzer *getNull() throw();
	static MuleAnalyzer *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual Proxy< MuleAnalyzer > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace mulan
} // namespace debugging
} // namespace jmsf