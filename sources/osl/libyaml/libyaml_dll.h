#pragma once

#include "jmsf_dll_convention.h"

#if defined( OSL_LIBYAML_DLL_INTERFACE_INTERNAL )
	#define YAML_DECLARE_EXPORT
	#define OSL_LIBYAML_DLL_INTERFACE JMSF_DLL_EXPORT_CONVENTION
#else
	#define OSL_LIBYAML_DLL_INTERFACE JMSF_DLL_IMPORT_CONVENTION
#endif
