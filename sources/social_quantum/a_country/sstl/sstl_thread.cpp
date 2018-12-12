#include "sstl_thread.h"

// !!!
#include "sstl_profiler.h"
//#include <sys/time.h>

// external entry
namespace  sstl {
    void sstl_dump_profile_entry( const std::string& str ) {
        std::cerr << str << std::endl;
    }

    void get_current_time_mks( time_mks& mks ) {
//        struct timeval t;
//        gettimeofday( &t, 0 );

//        mks = (sstl::time_mks)t.tv_sec * (sstl::time_mks)1000000 + (sstl::time_mks)t.tv_usec;
    }

}
