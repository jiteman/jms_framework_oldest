#pragma once


#include "anti_warning.h"

#include "../nppntt_dll_header/nppntt_dll.h"


#if defined( NPPNTT_BOARD_CONTROLLER_DLL_INTERFACE_INTERNAL )
	#define NPPNTT_BOARD_CONTROLLER_DLL_INTERFACE NPPNTT_DLL_EXPORT
#else
	#define NPPNTT_BOARD_CONTROLLER_DLL_INTERFACE NPPNTT_DLL_IMPORT
#endif
