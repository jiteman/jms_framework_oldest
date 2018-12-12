#pragma once


////#include "jmsf/types.h"
#include "jmsf/typing/Naturals.hpp"


namespace jmsf {
namespace cule {
namespace to_libs {
namespace system {


class SystemTime {

	static const typing::Natural MILLISECONDS_IN_SECOND; // = 1000;

public:
	virtual ~SystemTime();
	SystemTime();

	typing::Natural getCurrentTimeInMilliseconds() const;

private:
	SystemTime( const SystemTime & ) {}
	const SystemTime &operator=( const SystemTime & ) { return *this; }

};


} // namespace
}
}
}
