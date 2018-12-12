/*
 *  sqc_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef __SQC_COMMAND_QUEUE_H_INCLUDED__
#define __SQC_COMMAND_QUEUE_H_INCLUDED__

#include "framework/sqc_framework_defs.h"

NAMESPACE_SQC_FRAMEWORK

//
// sqc_command_queue implementation
//
class sqc_command_queue {
public:
	sqc_command_queue() {
	}
	virtual ~sqc_command_queue() {
	}
};
	
END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_COMMAND_QUEUE_H_INCLUDED__
