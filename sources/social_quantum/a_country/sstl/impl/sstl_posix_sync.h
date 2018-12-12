#pragma once

//#include <pthread.h>
#include <cassert>
#include "../sstl_defs.h"

NAMESPACE_SSTL

////////////////////////////////////////////////////////////////////////////////
class sstl_posix_mutex {

public:
	sstl_posix_mutex() {
		assert( false );
//        pthread_mutex_init( &m_lock, NULL );
	}
	
	~sstl_posix_mutex() {
		assert( false );
//		pthread_mutex_destroy( &m_lock );
	}
	
	void acquire() {
		assert( false );
//		pthread_mutex_lock( &m_lock );
    }
	
    void release() {
		assert( false );
//        pthread_mutex_unlock( &m_lock );
	}

private:
//	pthread_mutex_t	m_lock;
};

/*
 comment cos pthread_rwlock_t is not supported on android
////////////////////////////////////////////////////////////////////////////////
class sstl_posix_rw_mutex {
	
	pthread_rwlock_t	m_rw_lock;
public:
	sstl_posix_rw_mutex() {
        pthread_rwlock_init( &m_rw_lock, NULL );
	}
	
	~sstl_posix_rw_mutex() {
        pthread_rwlock_destroy( &m_rw_lock );
	}
    
	void acquire( const rw_acquire type ) {
		if ( type == acquire_read ) {
			pthread_rwlock_rdlock( &m_rw_lock );
		} else {
			pthread_rwlock_wrlock( &m_rw_lock );
		}
    }
	
    void release() {
        pthread_rwlock_unlock( &m_rw_lock );
    }	
};
*/
END_NAMESPACE_SSTL
