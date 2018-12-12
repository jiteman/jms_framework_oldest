#pragma once

#include "Should.hxx"


#include "excepting/exception_Should.h"

#include "File_and_line.hxx"
#include "jmsf/pointing/Proxy.hxx"
#include "jmsf/pointing/Constant_proxy.hxx"
#include "jmsf/pointing/Pointer.hxx"
#include "jmsf/pointing/Constant_pointer.hxx"
#include "jmsf/memorying/Awamp.hxx"
#include "jmsf/memorying/Wamp.hxx"
#include "jmsf/memorying/Amp.hxx"
#include "jmsf/memorying/Owomp.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Omp.hxx"
#include "jmsf/typeing/Boolean.hxx"
#include "jmsf/typeing/Ansii_string.hxx"
#include "jmsf/memorying/Allocator.hxx"

#include "jmsf/typeing/internals/internal_types.h"

#include "jmsf/jmsf.h"

#include "jmsf/encodebuba/common_standard_support.h"


namespace jmsf {
namespace validating {


class JMSF_SHARED_INTERFACE Should {

public:
	static void always_be( typeing::Boolean expression_result, const File_and_line &file_and_line );
	static void never_be( typeing::Boolean expression_result, const File_and_line &file_and_line );

	static void always_be_null_native_pointer( const void *native_pointer, const File_and_line &file_and_line );
	static void never_be_null_native_pointer( const void *native_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_null( const memorying::Omp< A_type > &object_memory_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_null( const memorying::Omp< A_type > &object_memory_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_null( const memorying::Womp< A_type > &weak_object_memory_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_null( const memorying::Womp< A_type > &weak_object_memory_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_null( const memorying::Owomp< A_type > &object_weak_object_memory_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_null( const memorying::Owomp< A_type > &object_weak_object_memory_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_null( const memorying::Amp< A_type > &array_memory_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_null( const memorying::Amp< A_type > &array_memory_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_null( const memorying::Wamp< A_type > &weak_array_memory_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_null( const memorying::Wamp< A_type > &weak_array_memory_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_null( const memorying::Awamp< A_type > &array_weak_array_memory_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_null( const memorying::Awamp< A_type > &array_weak_array_memory_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_null( const pointing::Pointer< A_type > &a_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_null( const pointing::Pointer< A_type > &a_pointer, const File_and_line &file_and_line );

	template< class A_type >
	static void always_be_null( const pointing::Constant_pointer< A_type > &a_constant_pointer, const File_and_line &file_and_line );
	template< class A_type >
	static void never_be_null( const pointing::Constant_pointer< A_type > &a_constant_pointer, const File_and_line &file_and_line );

//	// SenSEI: todonext - next two method should sound like "always/never be null" with parameters Proxy and Constant_proxy +
//	// method "never be null pointer" with parameters Proxy and Constant_proxy
//	template< class A_type >
//	static void always_be_null( const pointing::Proxy< A_type > &a_proxy, const File_and_line &file_and_line );
//	template< class A_type >
//	static void never_be_null( const pointing::Proxy< A_type > &a_proxy, const File_and_line &file_and_line );

//	template< class A_type >
//	static void always_be_null( const pointing::Constant_proxy< A_type > &a_constant_proxy, const File_and_line &file_and_line );
//	template< class A_type >
//	static void never_be_null( const pointing::Constant_proxy< A_type > &a_constant_proxy, const File_and_line &file_and_line );

//	template< class A_type >
//	static void never_be_null_pointer( const pointing::Proxy< A_type > &a_proxy, const File_and_line &file_and_line );
//	template< class A_type >
//	static void never_be_null_pointer( const pointing::Constant_proxy< A_type > &a_constant_proxy, const File_and_line &file_and_line );

//	template< class A_type >
//	static void always_be_null_object( const A_type *pointer, const File_and_line &file_and_line );
//	template< class A_type >
//	static void never_be_null_object( const A_type *pointer, const File_and_line &file_and_line );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	static void never_reach_here( const typeing::internals::platform_character *reason, const File_and_line &file_and_line );
	static void never_reach_here_empty( const File_and_line &file_and_line );
	static void never_violate_copy_prohibition( const typeing::internals::platform_character *place, const File_and_line &file_and_line );
	static void never_violate_copy_prohibition_empty( const File_and_line &file_and_line );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	static void set_allocators(
//		const memorying::Womp< memorying::Allocator > &temporary_character_array_allocator,
//		const memorying::Womp< memorying::Allocator > &character_array_allocator,
//		const memorying::Womp< memorying::Allocator > &consolidated_character_array_allocator,
//		const memorying::Womp< memorying::Allocator > &list_node_allocator ) noexcept;

// 		const memorying::Womp< memorying::Allocator > &textStreamAllocator,
// 		const memorying::Womp< memorying::Allocator > &textStringAllocator,
// 		const memorying::Womp< memorying::Allocator > &textArrayAllocator ) noexcept;

// 	static memorying::Womp< memorying::Allocator > take_text_stream_allocator() noexcept;
// 	static memorying::Womp< memorying::Allocator > take_text_string_allocator() noexcept;
// 	static memorying::Womp< memorying::Allocator > take_text_array_allocator() noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	~Should() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Should() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Should( const Should &other ) noexcept;
	const Should &operator =( const Should &other ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
//	static memorying::Womp< memorying::Allocator > TEMPORARY_CHARACTER_ARRAY_ALLOCATOR;
//	static memorying::Womp< memorying::Allocator > CHARACTER_ARRAY_ALLOCATOR;
//	static memorying::Womp< memorying::Allocator > CONSOLIDATED_CHARACTER_ARRAY_ALLOCATOR;
//	static memorying::Womp< memorying::Allocator > LIST_NODE_ALLOCATOR;
// 	static memorying::Womp< memorying::Allocator > TEXT_STREAM_ALLOCATOR;
// 	static memorying::Womp< memorying::Allocator > TEXT_STRING_ALLOCATOR;
// 	static memorying::Womp< memorying::Allocator > TEXT_ARRAY_ALLOCATOR;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace validating
} // namespace jmsf


#include "File_and_line.h"
#include "logging_flags.h"


// SenSEI: todonext - transfer all call to Sould to macroses
#if defined( JMSF_VALIDATING_SHOULD_IS_UNCONDITIONAL )

	#define jmsf_Should_always_be( boolean_expression ) \
		::jmsf::validating::Should::always_be( ( boolean_expression ), JMSF_FILE_AND_LINE )

	#define jmsf_Should_never_be( boolean_expression ) \
		::jmsf::validating::Should::never_be( ( boolean_expression ), JMSF_FILE_AND_LINE )

	#define jmsf_Should_always_be_null_native_pointer( native_pointer ) \
		::jmsf::validating::Should::always_be_null_native_pointer( ( native_pointer ), JMSF_FILE_AND_LINE )

	#define jmsf_Should_never_be_null_native_pointer( native_pointer ) \
		::jmsf::validating::Should::never_be_null_native_pointer( ( native_pointer ), JMSF_FILE_AND_LINE )

	#define jmsf_Should_always_be_null( some_jmsf_pointer ) \
		::jmsf::validating::Should::always_be_null( ( some_jmsf_pointer ), JMSF_FILE_AND_LINE )

	#define jmsf_Should_never_be_null( some_jmsf_pointer ) \
		::jmsf::validating::Should::never_be_null( ( some_jmsf_pointer ), JMSF_FILE_AND_LINE )

#else // #if defined( JMSF_VALIDATING_SHOULD_IS_UNCONDITIONAL )

	#define jmsf_Should_always_be( boolean_expression ) \
		if ( ( boolean_expression ) ) { ::jmsf::validating::Should::always_be( ( boolean_expression ), JMSF_FILE_AND_LINE ); }

	#define jmsf_Should_never_be( boolean_expression ) \
		if ( ( boolean_expression ) ) { ::jmsf::validating::Should::never_be( ( boolean_expression ), JMSF_FILE_AND_LINE ); }

	#define jmsf_Should_always_be_null_native_pointer( native_pointer ) \
		if ( ( native_pointer ) != nullptr ) { ::jmsf::validating::Should::always_be_null_native_pointer( ( native_pointer ), JMSF_FILE_AND_LINE ); }

	#define jmsf_Should_never_be_null_native_pointer( native_pointer ) \
		if ( ( native_pointer ) == nullptr ) { ::jmsf::validating::Should::never_be_null_native_pointer( ( native_pointer ), JMSF_FILE_AND_LINE ); }

	#define jmsf_Should_always_be_null( some_jmsf_pointer ) \
		if ( ( some_jmsf_pointer ).is_not_empty() ) { ::jmsf::validating::Should::always_be_null( ( some_jmsf_pointer ), JMSF_FILE_AND_LINE ); }

	#define jmsf_Should_never_be_null( some_jmsf_pointer ) \
		if ( ( some_jmsf_pointer ).is_empty() ) { ::jmsf::validating::Should::never_be_null( ( some_jmsf_pointer ), JMSF_FILE_AND_LINE ); }

#endif // #if defined( JMSF_VALIDATING_SHOULD_IS_UNCONDITIONAL )


#define jmsf_Should_never_reach_here( a_reason ) \
	::jmsf::validating::Should::never_reach_here( ( a_reason ), JMSF_FILE_AND_LINE )

#define jmsf_Should_never_reach_here_empty() \
	::jmsf::validating::Should::never_reach_here_empty( JMSF_FILE_AND_LINE )

#define jmsf_Should_never_violate_copy_prohibition( a_place ) \
	::jmsf::validating::Should::never_violate_copy_prohibition( ( a_place ), JMSF_FILE_AND_LINE )

#define jmsf_Should_never_violate_copy_prohibition_empty() \
	::jmsf::validating::Should::never_violate_copy_prohibition_empty( JMSF_FILE_AND_LINE )
