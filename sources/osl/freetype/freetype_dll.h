#pragma once

#include "jmsf_dll_convention.h"

#if defined( OSL_FREETYPE_DLL_INTERFACE_INTERNAL )
//	#define FT2_BUILD_LIBRARY
	#define OSL_FREETYPE_DLL_INTERFACE JMSF_DLL_EXPORT_CONVENTION
#else
	#define OSL_FREETYPE_DLL_INTERFACE JMSF_DLL_IMPORT_CONVENTION
#endif
