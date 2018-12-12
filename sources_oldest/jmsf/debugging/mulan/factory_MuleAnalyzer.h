#pragma once

#include "jmsf/Singleton.hpp"

#include "mulan.h"

#include "jmsf/DeleterForPointer.hxx"
#include "MuleAnalyzer.hxx"

namespace jmsf {
namespace debugging {
namespace mulan {

class JMSF_MULE_ANALYZER_DLL_INTERFACE factory_MuleAnalyzer :
	public Singleton< factory_MuleAnalyzer >
{

public:
	virtual Proxy< MuleAnalyzer > createMuleAnalyzer() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: friend DeleterForPointer< factory_MuleAnalyzer >;
	~factory_MuleAnalyzer() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< factory_MuleAnalyzer >;
	static factory_MuleAnalyzer *createInstance() throw();

protected:
	factory_MuleAnalyzer() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	factory_MuleAnalyzer( const factory_MuleAnalyzer &other ) throw();
	const factory_MuleAnalyzer &operator =( const factory_MuleAnalyzer &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace mulan
} // namespace debugging
} // namespace jmsf
