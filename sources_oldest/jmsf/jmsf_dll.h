#pragma once

//#include "warning_suppressor.h"
#include "jmsf_dll_convention.h"

#if defined( JMSF_DLL_INTERFACE_INTERNAL )
	#define JMSF_DLL_INTERFACE JMSF_DLL_EXPORT_CONVENTION
#else
	#define JMSF_DLL_INTERFACE JMSF_DLL_IMPORT_CONVENTION
#endif
