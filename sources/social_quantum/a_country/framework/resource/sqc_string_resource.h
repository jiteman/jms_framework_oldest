#pragma once

#include "../sqc_framework_defs.h"

NAMESPACE_SQC_FRAMEWORK

//
// sqc_string_resources interface
//
class sqc_string_resources {
public:
	virtual sqc_string load( const sqc_string& resource_id, 
							const sqc_string& def_value ) = 0;
};
	
//
// sqc_string_resources_dummy implementation
//
class sqc_string_resources_dummy : public sqc_string_resources {
public:
	sqc_string_resources_dummy() {
	}
	virtual ~sqc_string_resources_dummy() {
	}
	
	virtual sqc_string load( const sqc_string& resource_id,
							const sqc_string& def_value ) {
		return def_value;
	}
};
	
END_NAMESPACE_SQC_FRAMEWORK
