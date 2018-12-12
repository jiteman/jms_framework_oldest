#include "Should.h"


#include "jmsf/jmsf_Allocators.h"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Allocator.h"

#include "excepting/exception_Should.h"
#include "jmsf/typeing/Ansii_string_stream.h"
//

#include "logging_macroses.h"


namespace jmsf {
namespace validating {


void Should::always_be( const typeing::Boolean expression_result, const File_and_line &file_and_line ) {
	if ( expression_result.inversion() ) {
		JMSF_LOG_ERROR_OUTPUT( "Should::always_be" );
		throw excepting::exception_Should( AS_string_literal( "Should::always_be( false )" ), file_and_line );
	}
}

void Should::never_be( const typeing::Boolean expression_result, const File_and_line &file_and_line ) {
	if ( expression_result ) {
		JMSF_LOG_ERROR_OUTPUT( "Should::never_be" );
		throw excepting::exception_Should( AS_string_literal( "Should::never_be( true )" ), file_and_line );
	}
}

void Should::always_be_null_native_pointer( const void *const native_pointer, const File_and_line &file_and_line ) {
	if ( native_pointer != nullptr ) {
		JMSF_LOG_ERROR_OUTPUT( "Should::always_be_null_native_pointer" );
		throw excepting::exception_Should( AS_string_literal( "Should::always_be_null_native_pointer( not nullptr )" ), file_and_line );
	}
}

void Should::never_be_null_native_pointer( const void *const native_pointer, const File_and_line &file_and_line ) {
	if ( native_pointer == nullptr ) {
		JMSF_LOG_ERROR_OUTPUT( "Should::never_be_null_native_pointer" );
		throw excepting::exception_Should( AS_string_literal( "Should::never_be_null_native_pointer( nullptr )" ), file_and_line );
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void Should::never_reach_here( const typeing::internals::platform_character *reason, const File_and_line &file_and_line ) {
	JMSF_LOG_ERROR_OUTPUT( "Should::never_reach_here()" );
	typeing::Ansii_string_stream ansii_string_stream =
		typeing::Ansii_string_stream::create(
			jmsf_Allocators::instance()->get_character_array_allocator(),
			jmsf_Allocators::instance()->get_list_node_allocator() );

	ansii_string_stream.put_string( AS_string_literal( "Should::neverReachHere() - " ) );
	ansii_string_stream.put_string( AS_string_literal( reason ) );

	JMSF_LOG_INFORMING_OUTPUT( "Should::never_reach_here( reason, file_and_line )" );

	throw
		excepting::exception_Should(
			ansii_string_stream.create_consolidated_ansii_string_(
				jmsf_Allocators::instance()->get_character_array_allocator() ),
			file_and_line );
}

// static
void Should::never_reach_here_empty( const File_and_line &file_and_line ) {
	JMSF_LOG_ERROR_OUTPUT( "Should::never_reach_here_empty()" );
	throw excepting::exception_Should( AS_string_literal( "Should::never_reach_here_empty()" ), file_and_line );
}

void Should::never_violate_copy_prohibition( const typeing::internals::platform_character *place, const File_and_line &file_and_line ) {
	JMSF_LOG_ERROR_OUTPUT( "Should::never_violate_copy_prohibition()" );
	typeing::Ansii_string_stream ansii_string_stream =
		typeing::Ansii_string_stream::create(
			jmsf_Allocators::instance()->get_character_array_allocator(),
			jmsf_Allocators::instance()->get_list_node_allocator() );

	ansii_string_stream.put_string( AS_string_literal( "Should::never_violate_copy_prohibition() - " ) );
	ansii_string_stream.put_string( AS_string_literal( place ) );

	JMSF_LOG_INFORMING_OUTPUT( "Should::never_violate_copy_prohibition( place, file_and_line )" );
	throw
		excepting::exception_Should(
			ansii_string_stream.create_consolidated_ansii_string_(
				jmsf_Allocators::instance()->get_character_array_allocator() ),
			file_and_line );
}

void Should::never_violate_copy_prohibition_empty( const File_and_line &file_and_line ) {
	JMSF_LOG_ERROR_OUTPUT( "Should::never_violate_copy_prohibition_empty()" );
	throw excepting::exception_Should( AS_string_literal( "Should::never_violate_copy_prohibition_empty()" ), file_and_line );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
//void Should::set_allocators( // SenSEI: todonext - police allocator initialization and using
//		const memorying::Womp< memorying::Allocator > &temporary_character_array_allocator,
//		const memorying::Womp< memorying::Allocator > &character_array_allocator,
//		const memorying::Womp< memorying::Allocator > &consolidated_character_array_allocator,
//		const memorying::Womp< memorying::Allocator > &list_node_allocator ) noexcept
//{
//	TEMPORARY_CHARACTER_ARRAY_ALLOCATOR	= temporary_character_array_allocator;
//	CHARACTER_ARRAY_ALLOCATOR = character_array_allocator;
//	CONSOLIDATED_CHARACTER_ARRAY_ALLOCATOR = consolidated_character_array_allocator;
//	LIST_NODE_ALLOCATOR = list_node_allocator;
//}

// void Should::set_allocator(
// 		const memorying::Womp< memorying::Allocator > &textStreamAllocator,
// 		const memorying::Womp< memorying::Allocator > &textStringAllocator,
// 		const memorying::Womp< memorying::Allocator > &textArrayAllocator ) noexcept
// {
// 	TEXT_STREAM_ALLOCATOR = textStreamAllocator;
// 	TEXT_STRING_ALLOCATOR = textStringAllocator;
// 	TEXT_ARRAY_ALLOCATOR = textArrayAllocator;
// }

// memorying::Womp< memorying::Allocator > Should::take_text_stream_allocator() noexcept {
// 	return *TEXT_STREAM_ALLOCATOR;
// }
//
// memorying::Womp< memorying::Allocator > Should::take_text_string_allocator() noexcept {
// 	return *TEXT_STRING_ALLOCATOR;
// }
//
// memorying::Womp< memorying::Allocator > Should::take_text_array_allocator() noexcept {
// 	return *TEXT_ARRAY_ALLOCATOR;
// }

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Should::~Should() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Should::Should() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Should::Should( const Should & ) noexcept // other
{}

const Should &Should::operator =( const Should &other ) noexcept {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace validating
} // namespace jmsf


// SenSEI: todonext - test this code in main (exceptions: construction and destruction)
//class Exceptional {

//public:
//	Exceptional() {
//		cout << "Exceptional constructor" << endl;
//		throw 1;
//	}

//	~Exceptional() {
//		cout << "Exceptional destructor" << endl;
//	}
//};


//class Unexceptional {

//public:
//	Unexceptional() {
//		cout << "Unexceptional constructor" << endl;
//	}

//	~Unexceptional() {
//		cout << "Unexceptional destructor" << endl;
//	}
//};


//class InitTest {

//public:
//	InitTest() {
//		cout << "Init test constructor" << endl;
//	}

//private:
//	Unexceptional _unexceptional;
//	Exceptional _exceptional;
//};


//int main() {
//	try {
//		InitTest init;
//	} catch( int i ) {
//			cout << "Exception construction init" << endl;
//	}
//}
