#include "SystemTime.h"

#include "jmsf/typing/Naturals.inl"

#include <ctime>


namespace jmsf {
namespace cule {
namespace to_libs {
namespace system {


// static
const typing::Natural SystemTime::MILLISECONDS_IN_SECOND = typing::Natural::create( 1000 );


SystemTime::~SystemTime()
{}

SystemTime::SystemTime()
{}

typing::Natural SystemTime::getCurrentTimeInMilliseconds() const {
	const typing::Natural clocksInThousand = typing::Natural::create( ::clock() ) * MILLISECONDS_IN_SECOND;
	return clocksInThousand / typing::Natural::create( CLOCKS_PER_SEC ); 
}


} // namespace
}
}
}
