#pragma once


#include "jmsf_dll_convention.h"


#if defined( OSL_LIBIMAGE_DLL_INTERFACE_INTERNAL )
	#define OSL_LIBIMAGE_DLL_INTERFACE JMSF_DLL_EXPORT_CONVENTION
#else
	#define OSL_LIBIMAGE_DLL_INTERFACE JMSF_DLL_IMPORT_CONVENTION
#endif
