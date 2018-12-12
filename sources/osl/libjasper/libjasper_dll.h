#pragma once


#include "jmsf_dll_convention.h"


#if defined( OSL_LIBJASPER_DLL_INTERFACE_INTERNAL )
	#define OSL_LIBJASPER_DLL_INTERFACE JMSF_DLL_EXPORT_CONVENTION
#else
	#define OSL_LIBJASPER_DLL_INTERFACE JMSF_DLL_IMPORT_CONVENTION
#endif


#if !defined( JAS_WIN_MSVC_BUILD )
	#define JAS_WIN_MSVC_BUILD
#endif

#if !defined( WIN32 )
	#define WIN32
#endif
