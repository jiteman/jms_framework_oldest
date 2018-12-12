#ifndef __SSTL_SYNC_H_INCLUDED__
#define __SSTL_SYNC_H_INCLUDED__

#include "sstl_defs.h"

#include "impl/sstl_posix_sync.h"

NAMESPACE_SSTL

// scoped lock
template <class T>
class sstl_scoped_lock {
	
	T&	m_lock;
public:
	sstl_scoped_lock( T& lock ) : m_lock( lock ) {
		m_lock.acquire();
	}
	
	~sstl_scoped_lock() {
		m_lock.release();
	}
};

typedef sstl_posix_mutex    sstl_mutex;
typedef sstl_scoped_lock<sstl_mutex> sstl_mutex_lock;

END_NAMESPACE_SSTL

#endif//__SSTL_SYNC_H_INCLUDED__