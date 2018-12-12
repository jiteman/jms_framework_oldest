#pragma once


#include "jmsf_dll_convention.h"


#if defined( OSL_LIBMNG_DLL_INTERFACE_INTERNAL )
//	#define OSL_LIBMNG_DLL_INTERFACE JMSF_DLL_EXPORT_CONVENTION
	#define MNG_BUILD_DLL
#else	
//	#define OSL_LIBMNG_DLL_INTERFACE JMSF_DLL_IMPORT_CONVENTION
	#define MNG_USE_DLL
#endif
