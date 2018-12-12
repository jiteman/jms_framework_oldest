#pragma once

#include "jmsf/types.h"
#include "jmsf/stdal/stdal_stl.h"

#include "jmsf/osie/Mutex.hxx"
#include "jmsf/Automatic.hxx"
#include "jmsf/Boolean.hxx"
#include "MulArrayCreationInformation.hxx"

#include "jmsf/jmsf.h"

namespace jmsf {
namespace debugging {

class JMSF_DLL_INTERFACE static_ArrayCreationLogger {

public:
	static void registerCreation( const MulArrayCreationInformation &mulArrayCreationInformation ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	~static_ArrayCreationLogger() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static_ArrayCreationLogger() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static_ArrayCreationLogger( const static_ArrayCreationLogger &other ) throw();
	const static_ArrayCreationLogger &operator =( const static_ArrayCreationLogger &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	static void initialize() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static std::ofstream _logFile;
	static Automatic< osie::Mutex > _arrayCreationLoggerMutex;
	static natural_size _arrayCreationCounter;
	static Boolean _isInitialized;

};


} // namespace debugging
} // namespace jmsf