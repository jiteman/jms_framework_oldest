#pragma once


#include "../jmsf_dll_header/jmsf_dll.h"


#if defined( JMSF_OSIE_MS_WINDOWS_DLL_INTERFACE_INTERNAL )
	#define JMSF_OSIE_MS_WINDOWS_DLL_INTERFACE JMSF_DLL_EXPORT
#else
	#define JMSF_OSIE_MS_WINDOWS_DLL_INTERFACE JMSF_DLL_IMPORT
#endif
