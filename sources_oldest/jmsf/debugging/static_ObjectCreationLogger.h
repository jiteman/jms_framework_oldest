#pragma once

#include "jmsf/types.h"
#include "jmsf/stdal/stdal_stl.h"
#include "jmsf/FileLineMacros.h"

#include "jmsf/osie/Mutex.hxx"
#include "jmsf/Automatic.hxx"
#include "jmsf/Boolean.hxx"
#include "MulObjectCreationInformation.hxx"

#include "jmsf/jmsf.h"

namespace jmsf {
namespace debugging {

class JMSF_DLL_INTERFACE static_ObjectCreationLogger {

public:
	static void registerCreation( const MulObjectCreationInformation &objectCreationInformation ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	~static_ObjectCreationLogger() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static_ObjectCreationLogger() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static_ObjectCreationLogger( const static_ObjectCreationLogger &other ) throw();
	const static_ObjectCreationLogger &operator =( const static_ObjectCreationLogger &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	static void initialize() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static std::ofstream _logFile;
	static Automatic< osie::Mutex > _objectCreationLoggerMutex;
	static natural_size _objectCreationCounter;
	static Boolean _isInitialized;

};


} // namespace debugging
} // namespace jmsf