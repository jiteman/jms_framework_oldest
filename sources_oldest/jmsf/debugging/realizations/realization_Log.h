#pragma once

#include "../Log.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Exception.hxx"
#include "realization_factory_DebuggingObject.hxx"

#include "jmsf/stdal/stdal_stl.h"

namespace jmsf {
namespace debugging {
namespace realizations {

class realization_Log :
	public Log,
	public mixins::mixin_Object
{

public:
	// virtuals Log
	void putWithEol( const ConstantProxy< TextString > &message ) throw();
	Proxy< Log > put( const ConstantProxy< TextString > &message ) throw();
	void putEol() throw();

	Proxy< Log > putInteger( integer_big value ) throw();
	Proxy< Log > putNatural( natural_big value ) throw();
	Proxy< Log > putReal( const Real &value ) throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_Log() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_DebuggingObject;
	realization_Log( const ConstantProxy< TextString > &pathToLogFile ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Log > createClone() const throw();

private:
	realization_Log( const realization_Log &other ) throw();
	const realization_Log &operator =( const realization_Log &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	std::ofstream _logFile;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace realizations
} // namespace debugging
} // namespace jmsf
