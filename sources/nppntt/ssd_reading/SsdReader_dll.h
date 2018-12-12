#pragma once


#include "jmsf_dll_convention.h"


#if defined( NPPNTT_SSD_READER_DLL_INTERNAL )
	#define NPPNTT_SSD_READER_DLL_INTERFACE	JMSF_DLL_EXPORT_CONVENTION
#else
	#define NPPNTT_SSD_READER_DLL_INTERFACE	JMSF_DLL_IMPORT_CONVENTION
#endif
