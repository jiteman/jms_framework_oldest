#pragma once


#include "jmsf_dll_convention.h"


#if defined( OSL_AUDIERE_DLL_INTERFACE_INTERNAL )
	#define AUDIERE_EXPORTS
	#define OSL_AUDIERE_DLL_INTERFACE JMSF_DLL_EXPORT_CONVENTION
#else
	#define OSL_AUDIERE_DLL_INTERFACE JMSF_DLL_IMPORT_CONVENTION
#endif


#define NO_FLAC
#define NO_DUMB
#define NO_MP3
#undef NO_OGG
#define NO_SPEEX
