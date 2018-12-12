#ifndef __SSTL_PROFILER_H_INCLUDED__
#define __SSTL_PROFILER_H_INCLUDED__

#include <time.h>
#include "sstl_defs.h"


NAMESPACE_SSTL

// external entry
extern void sstl_dump_profile_entry( const std::string& str );
extern void get_current_time_mks( time_mks& mks );

class profile_entry {
public:
	profile_entry( const char* entry_name, time_mks max_diff, bool log_enter_leave ) 
        : m_next_entry( 0 )
        , m_max_diff( max_diff )
        , m_log_enter_leave( log_enter_leave ) {
            
		m_entry = entry_name;
        get_current_time_mks( m_start_time );
        
        if ( m_log_enter_leave ) {
            std::string str( "PROFILER ENTER "  );
            str += entry_name;
            str += " ->";
            sstl_dump_profile_entry( str );
        }
        
        /*android_profile_entry*& entry = get_head();
        if ( entry ) {
            entry->next_entry = entry;
        }
        entry = this;*/
	}
	~profile_entry() {
        time_mks end_time = 0;
        get_current_time_mks( end_time );
        
        time_mks diff = end_time - m_start_time;
        
        if ( diff > m_max_diff ) {
            dump_time( diff );
        }
        
        if ( m_log_enter_leave ) {
            std::string str( "PROFILER LEAVE "  );
            str += m_entry;
            str += " <-";
            sstl_dump_profile_entry( str );
        }
	}
    
protected:
    static profile_entry*& get_head() {
        static profile_entry* entry;
        return entry;
    }
    
	void dump_time( const time_mks& t ) {
        std::stringstream out;
		out
            << "PROFILER " << m_entry << " take "
            << t / 1000 << " ms";
        
        sstl_dump_profile_entry( out.str() );
    }
    
    time_mks		m_max_diff;
    bool            m_log_enter_leave;
	time_mks		m_start_time;
	std::string 	m_entry;
    profile_entry*  m_next_entry;
};

static const time_mks	time_interval_realtime = 1 * 1000;
static const time_mks	time_interval_critical = 5 * 1000;
static const time_mks	time_interval_normal = 50 * 1000;

#define PROFILE_ENTRY( x ) sstl::profile_entry _profiler_( x, sstl::time_interval_normal, false );
#define PROFILE_ENTRY_ENTER_LEAVE( x ) sstl::profile_entry _profiler_( x, sstl::time_interval_normal, true );

#define PROFILE_ENTRY_REALTIME( x ) sstl::profile_entry _profiler_( x, sstl::time_interval_realtime, false );
#define PROFILE_ENTRY_CRITICAL( x ) sstl::profile_entry _profiler_( x, sstl::time_interval_critical, false );
#define PROFILE_ENTRY_INTERVAL( x, i ) sstl::profile_entry _profiler_( x, i, false );


END_NAMESPACE_SSTL


#endif//__SSTL_PROFILER_H_INCLUDED__