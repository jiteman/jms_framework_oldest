#pragma once

#include "jmsf/types.h"
#include "jmsf/stdal/stdal_stl.h"

#include "jmsf/osie/Mutex.hxx"
#include "jmsf/Automatic.hxx"
#include "jmsf/Boolean.hxx"
#include "MulArrayDeletionInformation.hxx"

#include "jmsf/jmsf.h"

namespace jmsf {
namespace debugging {

class JMSF_DLL_INTERFACE static_ArrayDeletionLogger {

public:
	static void registerDeletion( const MulArrayDeletionInformation &mulArrayDeletionInformation ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~static_ArrayDeletionLogger() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static_ArrayDeletionLogger() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static_ArrayDeletionLogger( const static_ArrayDeletionLogger &other ) throw();
	const static_ArrayDeletionLogger &operator =( const static_ArrayDeletionLogger &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	static void initialize() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static std::ofstream _logFile;
	static Automatic< osie::Mutex > _arrayDeletionLoggerMutex;
	static natural_size _arrayDeletionCounter;
	static Boolean _isInitialized;

};

} // namespace debugging
} // namespace jmsf