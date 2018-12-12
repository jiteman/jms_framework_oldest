#pragma once

#include "jmsf_dll_convention.h"

#if defined( OSL_FTGL_DLL_INTERFACE_INTERNAL )
	#define FTGL_LIBRARY
	#define OSL_FTGL_DLL_INTERFACE JMSF_DLL_EXPORT_CONVENTION
#else
	#define OSL_FTGL_DLL_INTERFACE JMSF_DLL_IMPORT_CONVENTION
#endif
