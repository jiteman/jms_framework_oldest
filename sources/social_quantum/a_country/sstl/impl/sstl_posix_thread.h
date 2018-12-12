#pragma once

//#include <pthread.h>
#include <cassert>
#include "../sstl_defs.h"

NAMESPACE_SSTL

typedef std::tr1::function<void ()>   sstl_thread_proc;

class sstl_posix_thread {

public:    
    sstl_posix_thread( sstl_thread_proc proc ) 
        : thread_proc( proc )
    {
		assert( false );
//        pthread_create( &thread, 0, start_thread_thunk, this );
    }
    
    ~sstl_posix_thread() {
        join();
    }
    
    void join() {
		assert( false );
//        pthread_join( thread, 0 );
    }
private:
    static void *start_thread_thunk( void *arg ) {
        sstl_posix_thread   *pthis = (sstl_posix_thread*)arg;
        pthis->thread_proc();
        return 0;
    }
//    pthread_t           thread;
    sstl_thread_proc    thread_proc;
};


END_NAMESPACE_SSTL
