#pragma once

#include "jmsf/types.h"
#include "jmsf/stdal/stdal_stl.h"

#include "jmsf/osie/Mutex.hxx"
#include "jmsf/Automatic.hxx"
#include "jmsf/Boolean.hxx"
#include "MulObjectDeletionInformation.hxx"

#include "jmsf/jmsf.h"

namespace jmsf {
namespace debugging {

class JMSF_DLL_INTERFACE static_ObjectDeletionLogger {

public:
//	static void registerDeletion( const MemoryLoggerInformation &memoryLoggerInformation ) throw();
	static void registerDeletion( const MulObjectDeletionInformation &mulObjectDeletionInformation ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~static_ObjectDeletionLogger() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static_ObjectDeletionLogger() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static_ObjectDeletionLogger( const static_ObjectDeletionLogger &other ) throw();
	const static_ObjectDeletionLogger &operator =( const static_ObjectDeletionLogger &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	static void initialize() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static std::ofstream _logFile;
	static Automatic< osie::Mutex > _objectDeletionLoggerMutex;
	static natural_size _objectDeletionCounter;
	static Boolean _isInitialized;

};

} // namespace debugging
} // namespace jmsf