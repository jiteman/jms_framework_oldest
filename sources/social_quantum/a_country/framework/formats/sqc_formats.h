#pragma once

#include "../sqc_framework_defs.h"
#include "../../sstl/sstl_format.h"

NAMESPACE_SQC_FRAMEWORK

//
// sqc_formats implementation
//
class sqc_formats {
public:
	sqc_formats();
	virtual ~sqc_formats();

    // format as 1 000
    sqc_string format_digit_grouping( sqc_ddword size ) const;
    // format as 1K, 1M, etc
    sqc_string format_digit_compact( sqc_ddword size ) const;
    
    // format as percent
    sqc_string format_percent( int percent ) const;
    // format quantity
    sqc_string format_quantity( int count, int total ) const;
	
	// format time
	sqc_string format_time( int seconds );

    // format time
	sqc_string format_time_colon( int seconds );

	// time format mask ( HHh MMm SSs )
	sqc_string get_time_mask() const;
};

END_NAMESPACE_SQC_FRAMEWORK
