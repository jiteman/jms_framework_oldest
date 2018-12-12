#include "Native_C_string.h"


#include "jmsf/structing/containing/Buffer.hin"

#include "jmsf/pointing/Constant_pointer.hin"

#include "jmsf/validating/Should.h"
#include "jmsf/validating/logging_macroses.h"


namespace jmsf {
namespace texting {


pointing::Constant_pointer< Native_C_string > create_AT_from_string_literal( const typeing::internals::platform_character *characters ) {
	JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( characters == nullptr, "Ansii_string::create_from_constant_literal( characters )" );
	jmsf_Should_never_be_null_native_pointer( characters );

	return
		pointing::Constant_pointer< Native_C_string >::crea

	return Ansii_string (
		memorying::Womp< memorying::Allocator >(),
		memorying::Wamp< internals::platform_character >::create(
			memorying::Memory_pointer::create_from_pointer( characters ),
			count_quantity_of_characters( characters ) ) );
}

pointing::Constant_pointer< texting::Native_C_string > create_AT_from_C_string(
	const memorying::Womp< memorying::Allocator > &character_array_allocator,
	const typeing::internals::platform_character *characters )
{
}

typeing::Ansii_string AS_string_literal( const typeing::internals::platform_character *characters ) noexcept {
	return typeing::Ansii_string::create_from_constant_literal( characters );
}

typeing::Ansii_string AS_C_string( const memorying::Womp< memorying::Allocator > &character_array_allocator, const typeing::internals::platform_character *characters ) noexcept {
	return typeing::Ansii_string::create_from_c_language_string( character_array_allocator, characters );
}


} // namespace texting
} // namespace jmsf
