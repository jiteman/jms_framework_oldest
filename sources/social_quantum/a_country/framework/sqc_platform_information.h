/*
 *  sqc_platform_information.h
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/15/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SQC_PLATFORM_INFORMATION_H_INCLUDED
#define SQC_PLATFORM_INFORMATION_H_INCLUDED

#include <sqc/sqc_defs.h>

/// there for include hell
namespace sqc { namespace framework {

	struct sqc_platform_information {
		const char* platform_name;
		const char* device_model;
		sqc_dword	total_memory;
		sqc_dword	free_memory;
		sqc_dword	used_memory;
		sqc_dword	video_memory;
	};
	
} }


#endif /*SQC_PLATFORM_INFORMATION_H_INCLUDED*/
