#include "DebugOutputUi.h"

////#include "jmsf/TextString.h"
////#include "jmsf/Proxies.hpp"

#include "jmsf/memorying/Destructor.inl"
#include "jmsf/memorying/temporary_Allocator.h"

#include "jmsf/typing/Ansii_string.h"

#include "temporary_windows_include.h"


namespace jmsf {
namespace cule {
namespace user_interfaces {


DebugOutputUi::~DebugOutputUi() {
}

DebugOutputUi::DebugOutputUi() {
}

void DebugOutputUi::print( const typing::Ansii_string &string ) {
	memorying::temporary_Allocator temporary_allocator;
	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );

	memorying::Amp< typing::internals::platform_character_type > c_string = string.get_as_C_string( the_temporary_allocator );

	::OutputDebugStringA( c_string.get() );

	memorying::Destructor< typing::internals::platform_character_type >::destruct( c_string );
}


} // namespace
}
}
