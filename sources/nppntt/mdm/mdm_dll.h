#pragma once

#include "jmsf_dll_convention.h"


#if defined( NPPNTT_MDM_DLL_INTERFACE_INTERNAL )
	#define NPPNTT_MDM_DLL_INTERFACE JMSF_DLL_EXPORT_CONVENTION
#else
	#define NPPNTT_MDM_DLL_INTERFACE JMSF_DLL_IMPORT_CONVENTION
#endif
