#pragma once

#include "../MuleAnalyzer.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "jmsf/Exception.hxx"
#include "jmsf/Container.hxx"
#include "jmsf/Pointers.hxx"
#include "MulanObjectCreationInformation.hxx"
#include "MulanObjectDeletionInformation.hxx"
#include "MulanArrayCreationInformation.hxx"
#include "MulanArrayDeletionInformation.hxx"
#include "realization_factory_MuleAnalyzer.hxx"

namespace jmsf {
namespace debugging {
namespace mulan {
namespace realizations {

class realization_MuleAnalyzer :
	public MuleAnalyzer,
	public mixins::mixin_Object
{

public:
	// virtuals MuleAnalyzer
	Boolean readCollectedData() throw();
	void performAnalysis() throw();
	void showResults() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_MuleAnalyzer() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_MuleAnalyzer;
	realization_MuleAnalyzer(
		const Proxy< Container< Pointer< MulanObjectCreationInformation > > > &objectCreationContainer,
		const Proxy< Container< Pointer< MulanObjectDeletionInformation > > > &objectDeletionContainer,
		const Proxy< Container< Pointer< MulanArrayCreationInformation > > > &arrayCreationContainer,
		const Proxy< Container< Pointer< MulanArrayDeletionInformation > > > &arrayDeletionContainer ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< MuleAnalyzer > createClone() const throw();

private:
	realization_MuleAnalyzer( const realization_MuleAnalyzer &other ) throw();
	const realization_MuleAnalyzer &operator =( const realization_MuleAnalyzer &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Proxy< Container< Pointer< MulanObjectCreationInformation > > > _objectCreationContainer;
	Proxy< Container< Pointer< MulanObjectDeletionInformation > > > _objectDeletionContainer;
	Proxy< Container< Pointer< MulanArrayCreationInformation > > > _arrayCreationContainer;
	Proxy< Container< Pointer< MulanArrayDeletionInformation > > > _arrayDeletionContainer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace realizations
} // namespace mulan
} // namespace debugging
} // namespace jmsf