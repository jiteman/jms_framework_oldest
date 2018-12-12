#pragma once

#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <functional>
#include "../sqc/sqc_defs.h"


#define SQC_NODOWNLOAD

#if defined _DEBUG
#define sqc_assert(_Expression)     assert(_Expression)
#else
#define sqc_assert(_Expression)     ((void)0)
#endif

//
// common sstl includes
//
#include "../sstl/sstl_defs.h"
#include "../sstl/sstl_profiler.h"
#include "../sstl/sstl_sync.h"
#include "../sstl/sstl_thread.h"
#include "../sstl/sstl_format.h"
#include "../sstl/sstl_ini.h"

//
// common milk includes
//
#include "../milk/milk_defs.h"
#include "../milk/milk_widget.h"
#include "../milk/milk_controls.h"
#include "../milk/milk_scroll_area.h"
#include "../milk/milk_spinboard.h"

//
// common surf includes
//
#include "../surf/surf_defs.h"
#include "../surf/surf_gl.h"
#include "../surf/surf_9way_image.h"


#define NAMESPACE_SQC_FRAMEWORK    namespace sqc { namespace framework {
#define END_NAMESPACE_SQC_FRAMEWORK   } }

#define NAMESPACE_SQC_PROCESSOR namespace sqc { namespace processor {
#define END_NAMESPACE_SQC_PROCESSOR }}


NAMESPACE_SQC_FRAMEWORK

enum sqc_call_type {
	call_async,
    call_sync,
};

inline sqc_string
print_sqc_call_type( const sqc_call_type type ) {
	if ( call_async == type )	return "async";
    if ( call_sync == type )	return "sync";
    sqc_assert( false );
    return "usync";
}

END_NAMESPACE_SQC_FRAMEWORK

// define notification provider and event id
#define declare_notification_provider_id( x ) \
static const sqc_string x ( #x );

#define declare_notification_event_id( x ) \
static const sqc_string x ( #x );


// layouts
#include "layouts/sqc_layout_defs.h"

#undef sqc_log
#undef sqc_endl
#undef sqc_verbose
#undef sqc_info
#undef sqc_warning
#undef sqc_error
#undef sqc_fatal

extern int g_log_level;

enum sqc_log_level {
    log_level_fatal = 0,
    log_level_error,
    log_level_warning,
    log_level_info,
    log_level_verbose,
};

class sqc_log_entry {
public:
    sqc_log_entry() {
        std::cout << "SQC     |";
    }
    
    ~sqc_log_entry() {
        std::cout << std::endl;
    }
    
    std::ostream &get_stream() {
        return std::cout;
    }
};

#define sqc_log( level )   if( level <= g_log_level ) sqc_log_entry().get_stream()
#define sqc_endl()         ""
#define sqc_verbose()      sqc_log( ::log_level_verbose ) << "VERBOSE |"
#define sqc_info()         sqc_log( ::log_level_info )    << "INFO    |"
#define sqc_warning()      sqc_log( ::log_level_warning ) << "WARNING |"
#define sqc_error()        sqc_log( ::log_level_error )   << "ERROR   |"
#define sqc_fatal()        sqc_log( ::log_level_fatal )   << "FATAL   |"
