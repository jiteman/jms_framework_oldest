#include "Should.h"


#include "jmsf/memorying/Womp.inl"

 #include "jmsf/memorying/Allocator.h"
// 
#include "excepting/exception_Should.h"
// #include "jmsf/typing/Ansii_string.h"
#include "jmsf/typing/Ansii_string_stream.h"



namespace jmsf {
namespace validating {


void Should::always_be( const typing::Boolean expression, const File_and_line &fileAndLine ) {
	if ( expression.not() ) {
		throw realizations::exception_Should( typing::Ansii_string::create_from_constant_literal( "Should::always_be( false )" ), fileAndLine );
	}
}

void Should::never_be( const typing::Boolean expression, const File_and_line &fileAndLine ) {
	if ( expression ) {
		throw realizations::exception_Should( typing::Ansii_string::create_from_constant_literal( "Should::never_be( true )" ), fileAndLine );
	}
}

void Should::always_be_null( const void *const pointer, const File_and_line &fileAndLine ) {
	if ( pointer != nullptr ) {
		throw realizations::exception_Should( typing::Ansii_string::create_from_constant_literal( "Should::always_be_null( not nullptr )" ), fileAndLine );
	}
}

void Should::never_be_null( const void *const pointer, const File_and_line &fileAndLine ) {
	if ( pointer == nullptr ) {
		throw realizations::exception_Should( typing::Ansii_string::create_from_constant_literal( "Should::never_be_null( nullptr )" ), fileAndLine );
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void Should::_never_reach_here( const typing::internals::platform_character_type *reason, const File_and_line &fileAndLine ) {
	typing::Ansii_string_stream ansii_string_stream = typing::Ansii_string_stream::create( CHARACTER_ARRAY_ALLOCATOR, LIST_NODE_ALLOCATOR );
	ansii_string_stream.put_string( typing::Ansii_string::create_from_constant_literal( "Should::neverReachHere() - " ) );
	ansii_string_stream.put_string( typing::Ansii_string::create_from_constant_literal( reason ) );
	throw realizations::exception_Should( ansii_string_stream.create_consolidated_ansii_string( CONSOLIDATED_CHARACTER_ARRAY_ALLOCATOR ), fileAndLine );

// 	pointing::Proxy< texting::TextStream > textStream = texting::factory_TextObject::instance()->createTextStream( *TEXT_STREAM_ALLOCATOR );
// 	textStream->put( CONSTANT_TEXT_STRING( *TEXT_STRING_ALLOCATOR, "Should::neverReachHere() - " ) );
// 	textStream->put( CONSTANT_TEXT_STRING( *TEXT_STRING_ALLOCATOR, reason ) );
// 	throw realizations::exception_Should( textStream->createTextString( *TEXT_STRING_ALLOCATOR ), fileAndLine );
}

void Should::never_violate_copy_prohibition( const typing::internals::platform_character_type *place, const File_and_line &fileAndLine ) {
	typing::Ansii_string_stream ansii_string_stream = typing::Ansii_string_stream::create( CHARACTER_ARRAY_ALLOCATOR, LIST_NODE_ALLOCATOR );
	ansii_string_stream.put_string( typing::Ansii_string::create_from_constant_literal( "Should::never_violate_copy_prohibition() - " ) );
	ansii_string_stream.put_string( typing::Ansii_string::create_from_constant_literal( place ) );
	throw realizations::exception_Should( ansii_string_stream.create_consolidated_ansii_string( CONSOLIDATED_CHARACTER_ARRAY_ALLOCATOR ), fileAndLine );

// 	pointing::Proxy< texting::TextStream > textStream = texting::factory_TextObject::instance()->createTextStream( *TEXT_STREAM_ALLOCATOR );
// 	textStream->put( CONSTANT_TEXT_STRING( *TEXT_STRING_ALLOCATOR, "Should::never_violate_copy_prohibition() - " ) );
// 	textStream->put( CONSTANT_TEXT_STRING( *TEXT_STRING_ALLOCATOR, place ) );
// 	throw realizations::exception_Should( textStream->createTextString( *TEXT_STRING_ALLOCATOR ), fileAndLine );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
void Should::set_allocators(
		const memorying::Womp< memorying::Allocator > &temporary_character_array_allocator,
		const memorying::Womp< memorying::Allocator > &character_array_allocator,
		const memorying::Womp< memorying::Allocator > &consolidated_character_array_allocator,
		const memorying::Womp< memorying::Allocator > &list_node_allocator ) noexept
{
	TEMPORARY_CHARACTER_ARRAY_ALLOCATOR	= temporary_character_array_allocator;
	CHARACTER_ARRAY_ALLOCATOR = character_array_allocator;
	CONSOLIDATED_CHARACTER_ARRAY_ALLOCATOR = consolidated_character_array_allocator;
	LIST_NODE_ALLOCATOR = list_node_allocator;
}

// void Should::set_allocator(
// 		const memorying::Womp< memorying::Allocator > &textStreamAllocator,
// 		const memorying::Womp< memorying::Allocator > &textStringAllocator,
// 		const memorying::Womp< memorying::Allocator > &textArrayAllocator ) noexept
// {
// 	TEXT_STREAM_ALLOCATOR = textStreamAllocator;
// 	TEXT_STRING_ALLOCATOR = textStringAllocator;
// 	TEXT_ARRAY_ALLOCATOR = textArrayAllocator;
// }

// memorying::Womp< memorying::Allocator > Should::take_text_stream_allocator() noexept {
// 	return *TEXT_STREAM_ALLOCATOR;
// }
// 
// memorying::Womp< memorying::Allocator > Should::take_text_string_allocator() noexept {
// 	return *TEXT_STRING_ALLOCATOR;
// }
// 
// memorying::Womp< memorying::Allocator > Should::take_text_array_allocator() noexept {
// 	return *TEXT_ARRAY_ALLOCATOR;
// }

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Should::~Should() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Should::Should() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Should::Should( const Should & ) noexept // other
{}

const Should &Should::operator =( const Should &other ) noexept {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// statics
memorying::Womp< memorying::Allocator > Should::TEMPORARY_CHARACTER_ARRAY_ALLOCATOR;
memorying::Womp< memorying::Allocator > Should::CHARACTER_ARRAY_ALLOCATOR;
memorying::Womp< memorying::Allocator > Should::CONSOLIDATED_CHARACTER_ARRAY_ALLOCATOR;
memorying::Womp< memorying::Allocator > Should::LIST_NODE_ALLOCATOR;
//~statics

// memorying::Allocator *Should::TEXT_STREAM_ALLOCATOR = nullptr;
// memorying::Allocator *Should::TEXT_STRING_ALLOCATOR = nullptr;
// memorying::Allocator *Should::TEXT_ARRAY_ALLOCATOR = nullptr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace validating
} // namespace jmsf
