#pragma once


#include "jmsf_dll_convention.h"


//#define GLEW_MX

#if defined( OSL_GLEW_DLL_INTERFACE_INTERNAL )
	#define GLEW_BUILD
	#define JMSF_DLL_INTERFACE JMSF_DLL_EXPORT_CONVENTION
#else
	#define JMSF_DLL_INTERFACE JMSF_DLL_IMPORT_CONVENTION
#endif
