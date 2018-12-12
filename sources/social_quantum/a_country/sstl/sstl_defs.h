#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <functional>

//
//
//
#define NAMESPACE_SSTL namespace sstl {
#define END_NAMESPACE_SSTL }


#if defined _DEBUG
#define sstl_assert(_Expression)     assert(_Expression)
#else
#define sstl_assert(_Expression)     ((void)0)
#endif

NAMESPACE_SSTL

enum rw_acquire {
	acquire_read,
	acquire_write
};

typedef long long time_mks;

void get_current_time_mks( time_mks& mks );

END_NAMESPACE_SSTL
