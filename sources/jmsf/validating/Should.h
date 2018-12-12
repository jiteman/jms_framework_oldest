#pragma once

//#include "typing.h"

#include "jmsf/typing/Boolean.hxx"

#include "jmsf/typing/Ansii_string.hxx"

#include "File_and_line.hxx"
#include "jmsf/memorying/Allocator.hxx"
#include "jmsf/memorying/Womp.hpp"

#include "jmsf/typing/internals/internal_types.h"

#include "jmsf/jmsf.h"

#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace validating {


class JMSF_DLL_INTERFACE Should {

public:
	static void always_be( typing::Boolean expression, const File_and_line &fileAndLine );
	static void never_be( typing::Boolean expression, const File_and_line &fileAndLine );

	static void always_be_null( const void *pointer, const File_and_line &fileAndLine );
	static void never_be_null( const void *pointer, const File_and_line &fileAndLine );

	template< class A_type >
	static void always_be_null_object( const A_type *pointer, const File_and_line &fileAndLine );

	template< class A_type >
	static void never_be_null_object( const A_type *pointer, const File_and_line &fileAndLine );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	static void _never_reach_here( const typing::internals::platform_character_type *reason, const File_and_line &fileAndLine );
	static void never_violate_copy_prohibition( const typing::internals::platform_character_type *place, const File_and_line &fileAndLine );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	static void set_allocators(
		const memorying::Womp< memorying::Allocator > &temporary_character_array_allocator,
		const memorying::Womp< memorying::Allocator > &character_array_allocator,
		const memorying::Womp< memorying::Allocator > &consolidated_character_array_allocator,
		const memorying::Womp< memorying::Allocator > &list_node_allocator ) noexept;

// 		const memorying::Womp< memorying::Allocator > &textStreamAllocator,
// 		const memorying::Womp< memorying::Allocator > &textStringAllocator,
// 		const memorying::Womp< memorying::Allocator > &textArrayAllocator ) noexept;

// 	static memorying::Womp< memorying::Allocator > take_text_stream_allocator() noexept;
// 	static memorying::Womp< memorying::Allocator > take_text_string_allocator() noexept;
// 	static memorying::Womp< memorying::Allocator > take_text_array_allocator() noexept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	~Should() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Should() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Should( const Should &other ) noexept;
	const Should &operator =( const Should &other ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	static memorying::Womp< memorying::Allocator > TEMPORARY_CHARACTER_ARRAY_ALLOCATOR;
	static memorying::Womp< memorying::Allocator > CHARACTER_ARRAY_ALLOCATOR;
	static memorying::Womp< memorying::Allocator > CONSOLIDATED_CHARACTER_ARRAY_ALLOCATOR;
	static memorying::Womp< memorying::Allocator > LIST_NODE_ALLOCATOR;
// 	static memorying::Womp< memorying::Allocator > TEXT_STREAM_ALLOCATOR;
// 	static memorying::Womp< memorying::Allocator > TEXT_STRING_ALLOCATOR;
// 	static memorying::Womp< memorying::Allocator > TEXT_ARRAY_ALLOCATOR;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace validating
} // namespace jmsf


#include "File_and_line.h"


namespace jmsf {
namespace validating {


template< class A_type >
void Should::always_be_null_object( const A_type *pointer, const File_and_line &fileAndLine ) {
	if ( pointer == nullptr ) {
		throw realizations::exception_Should( CONSTANT_TEXT_STRING( "Should::always_be_null_object( nullptr )" ), fileAndLine );
	}

	if ( pointer->isNull().not() ) {
		throw realizations::exception_Should( CONSTANT_TEXT_STRING( "Should::always_be_null_object( not NullObject )" ), fileAndLine );
	}
}

template< class A_type >
void Should::never_be_null_object( const A_type *pointer, const File_and_line &fileAndLine ) {
	if ( pointer == nullptr ) {
		throw realizations::exception_Should( CONSTANT_TEXT_STRING( "Should::never_be_null_object( nullptr )" ), fileAndLine );
	}

	if ( pointer->isNull() ) {
		throw realizations::exception_Should( CONSTANT_TEXT_STRING( "Should::never_be_null_object( NullObject )" ), fileAndLine );
	}
}


} // namespace validating
} // namespace jmsf
