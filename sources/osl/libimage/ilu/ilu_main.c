//-----------------------------------------------------------------------------
//
// ImageLib Utility Sources
// Copyright (C) 2000-2002 by Denton Woods
// Last modified: 05/20/2001 <--Y2K Compliant! =]
//
// Filename: src-ILU/src/ilu_main.c
//
// Description: Startup functions
//
//-----------------------------------------------------------------------------


#include "ilu_internal.h"
#include "ilu_states.h"


void ILAPIENTRY iluInit()
{
	// Used mostly for rotations
	//IL_PI = 4 * atan(1);		// precomputed value of pi
	//IL_DEGCONV = IL_PI / 180;	// division is slow on some computers

	iluSetLanguage(ILU_ENGLISH);
	return;
}

ILuint ILAPIENTRY iluLoadImage(ILconst_string FileName)
{
	ILuint Id;
	ilGenImages(1, &Id);
	if (Id == 0)
		return 0;
	if (!ilLoadImage(FileName)) {
		ilDeleteImages(1, &Id);
		return 0;
	}
	return Id;
}
