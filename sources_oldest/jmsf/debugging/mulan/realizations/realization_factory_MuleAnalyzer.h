#pragma once

#include "../factory_MuleAnalyzer.h"

namespace jmsf {
namespace debugging {
namespace mulan {
namespace realizations {

class realization_factory_MuleAnalyzer :
	public factory_MuleAnalyzer
{

public:
	// virtuals factory_MuleAnalyzer
	Proxy< MuleAnalyzer > createMuleAnalyzer() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_MuleAnalyzer() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend factory_MuleAnalyzer;
	realization_factory_MuleAnalyzer() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_MuleAnalyzer( const realization_factory_MuleAnalyzer &other ) throw();
	const realization_factory_MuleAnalyzer &operator =( const realization_factory_MuleAnalyzer &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace realizations
} // namespace mulan
} // namespace debugging
} // namespace jmsf
