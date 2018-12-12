#pragma once


#if !defined( JMSF_APIENTRY_CONVENTION )
	#define JMSF_APIENTRY_CONVENTION	__stdcall
#endif


#if !defined( JMSF_DLL_EXPORT_CONVENTION )
	#define JMSF_DLL_EXPORT_CONVENTION	_declspec( dllexport )
#endif


#if !defined( JMSF_DLL_IMPORT_CONVENTION )
	#define JMSF_DLL_IMPORT_CONVENTION	_declspec( dllimport )
#endif
