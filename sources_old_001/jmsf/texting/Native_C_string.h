#pragma once

#include "Native_C_string.hxx"


#include "jmsf/structing/containing/Buffer.hpp"

#include "jmsf/pointing/Constant_pointer.hxx"


namespace jmsf {
namespace texting {


pointing::Constant_pointer< texting::Native_C_string > create_AT_from_string_literal( const typeing::internals::platform_character *characters );

pointing::Constant_pointer< texting::Native_C_string > create_AT_from_C_string(
	const memorying::Womp< memorying::Allocator > &character_array_allocator,
	const typeing::internals::platform_character *characters );


} // namespace texting
} // namespace jmsf
