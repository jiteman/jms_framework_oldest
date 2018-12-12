#pragma once

#include "jmsf/Singleton.hpp"

#include "Log.hxx"
#include "jmsf/TextString.hxx"
#include "jmsf/Pointers.hxx"

#include "../jmsf.h"

namespace jmsf {
namespace debugging {

class JMSF_DLL_INTERFACE factory_DebuggingObject :
	public Singleton< factory_DebuggingObject >
{

public:
	virtual Proxy< Log > createLog( const ConstantProxy< TextString > &pathToLogFile ) const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: friend DeleterForPointer< factory_DebuggingObject >;
	~factory_DebuggingObject() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< factory_DebuggingObject >;
	static factory_DebuggingObject *createInstance() throw();

protected:
	factory_DebuggingObject() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	factory_DebuggingObject( const factory_DebuggingObject &other ) throw();
	const factory_DebuggingObject &operator =( const factory_DebuggingObject &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace debugging
} // namespace jmsf
