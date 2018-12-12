#pragma once

#include "../factory_DebuggingObject.h"

namespace jmsf {
namespace debugging {
namespace realizations {

class realization_factory_DebuggingObject :
	public factory_DebuggingObject
{

public:
	// virtuals factory_Debugging
	Proxy< Log > createLog( const ConstantProxy< TextString > &pathToLogFile ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_DebuggingObject() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend factory_DebuggingObject;
	realization_factory_DebuggingObject() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_DebuggingObject( const realization_factory_DebuggingObject &other ) throw();
	const realization_factory_DebuggingObject &operator =( const realization_factory_DebuggingObject &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace realizations
} // namespace debugging
} // namespace jmsf
