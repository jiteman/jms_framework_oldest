#pragma once

#include "jmsf/warning_suppressor.h"
#include "jmsf_dll_convention.h"

#if defined( JMSF_MULE_ANALYZER_DLL_INTERFACE_INTERNAL )
	#define JMSF_MULE_ANALYZER_DLL_INTERFACE JMSF_DLL_EXPORT_CONVENTION
#else
	#define JMSF_MULE_ANALYZER_DLL_INTERFACE JMSF_DLL_IMPORT_CONVENTION
#endif
