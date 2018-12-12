#pragma once

//#include "warning_suppressor.h"
#include "jmsf_dll_convention.h"

#if defined( OSL_SOIL_DLL_INTERFACE_INTERNAL )
	#define OSL_SOIL_DLL_INTERFACE JMSF_DLL_EXPORT_CONVENTION
#else
	#define OSL_SOIL_DLL_INTERFACE JMSF_DLL_IMPORT_CONVENTION
#endif
