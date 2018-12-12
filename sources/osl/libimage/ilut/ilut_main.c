//-----------------------------------------------------------------------------
//
// ImageLib Utility Toolkit Sources
// Copyright (C) 2000-2002 by Denton Woods
// Last modified: 05/28/2001 <--Y2K Compliant! =]
//
// Filename: src-ILUT/src/ilut_main.c
//
// Description: Startup functions
//
//-----------------------------------------------------------------------------


#include "ilut_internal.h"


void ILAPIENTRY ilutInit()
{
	ilutDefaultStates();  // Set states to their defaults
	// Can cause crashes if DevIL is not initialized yet

#ifdef ILUT_USE_OPENGL
	ilutGLInit();  // default renderer is OpenGL
#endif

#ifdef ILUT_USE_DIRECTX8
	ilutD3D8Init();
#endif

#ifdef ILUT_USE_DIRECTX9
	ilutD3D9Init();
#endif

	return;
}
