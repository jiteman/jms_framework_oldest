#include "Assert.h"


#include "jmsf/typing/Ansii_string_stream.inl"
#include "jmsf/typing/Ansii_string.h"
#include "jmsf/memorying/temporary_Allocator.h"
#include "jmsf/memorying/Womp.inl"
#include "exception_Cule.h"


//#include <cmath>


namespace jmsf {
namespace cule {

namespace free {
	void ThrowCuleException( const typing::Ansii_string &message, const validating::File_and_line &file_and_line );
} // namespace free


void Assert::real_notImplementedYet( const typing::Ansii_string &message, const validating::File_and_line &file_and_line ) {
	memorying::temporary_Allocator temporary_allocator;
	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );
	typing::Ansii_string_stream ansii_stream = typing::Ansii_string_stream::create( the_temporary_allocator, the_temporary_allocator );

	ansii_stream.put_string( AS_string_literal( "warning: " ) );
	ansii_stream.put_string( message );
	ansii_stream.put_string( AS_string_literal( " is not implemented yet" ) );

	free::ThrowCuleException( ansii_stream.create_consolidated_ansii_string( the_temporary_allocator ), file_and_line );
}

void Assert::real_testNotImplementedYet( const typing::Ansii_string &message, const validating::File_and_line &file_and_line ) {
	memorying::temporary_Allocator temporary_allocator;
	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );
	typing::Ansii_string_stream ansii_stream = typing::Ansii_string_stream::create( the_temporary_allocator, the_temporary_allocator );

	ansii_stream.put_string( AS_string_literal( "warning: " ) );
	ansii_stream.put_string( message );
	ansii_stream.put_string( AS_string_literal( " behaviour is not implemented yet" ) );

	free::ThrowCuleException( ansii_stream.create_consolidated_ansii_string( the_temporary_allocator ), file_and_line );
}

void Assert::real_shouldBe( const typing::Boolean actual, const validating::File_and_line &file_and_line ) {
	if ( !actual ) {
		free::ThrowCuleException( AS_string_literal( "expected: true, but was: false" ), file_and_line );
	}
}

void Assert::real_shouldNotBe( const typing::Boolean actual, const validating::File_and_line &file_and_line ) {
	if ( actual ) {
		free::ThrowCuleException( AS_string_literal( "expected: false, but was: true" ), file_and_line );
	}
}

void Assert::real_stringsShouldBeEqual( const typing::Ansii_string &expected, const typing::Ansii_string &actual, const validating::File_and_line &file_and_line ) {
	if ( expected.is_not_equal( actual ) ) {
		memorying::temporary_Allocator temporary_allocator;
		memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );
		typing::Ansii_string_stream ansii_stream = typing::Ansii_string_stream::create( the_temporary_allocator, the_temporary_allocator );

		ansii_stream.put_string( AS_string_literal( "expected: " ) );
		ansii_stream.put_string( expected );
		ansii_stream.put_string( AS_string_literal( ", but was: " ) );
		ansii_stream.put_string( actual );

		free::ThrowCuleException( ansii_stream.create_consolidated_ansii_string( the_temporary_allocator ), file_and_line );
	}
}

void real_stringsShouldNotBeEqual( const typing::Ansii_string &expected, const typing::Ansii_string &actual, const validating::File_and_line &file_and_line ) {
	if ( expected.is_equal( actual ) ) {
		memorying::temporary_Allocator temporary_allocator;
		memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );
		typing::Ansii_string_stream ansii_stream = typing::Ansii_string_stream::create( the_temporary_allocator, the_temporary_allocator );

		ansii_stream.put_string( AS_string_literal( "expected: != " ) );
		ansii_stream.put_string( expected );
		ansii_stream.put_string( AS_string_literal( ", but was: " ) );
		ansii_stream.put_string( actual );

		free::ThrowCuleException( ansii_stream.create_consolidated_ansii_string( the_temporary_allocator ), file_and_line );

	}
}

// void Assert::real_shouldNotTakeLongerThan( const natural expectedDuration, const validating::File_and_line &file_and_line ) {
// 	const natural duration = TestStopWatch::instance()->getLocalDuration();
// 
// 	if ( duration >= expectedDuration ) {
// 		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
// 		textStream->put( CONSTANT_TEXT_STRING( "expected duration less than: " ) )->putNatural( expectedDuration )->put( CONSTANT_TEXT_STRING( " ms" ) );
// 		textStream->put( CONSTANT_TEXT_STRING( ", but was: " ) )->putNatural( duration )->put( CONSTANT_TEXT_STRING( " ms" ) );
// 		free::ThrowCuleException( textStream.getNonlinkedConstant(), lineNumber );
// 	}
// }

namespace free {

void ThrowCuleException( const typing::Ansii_string &message, const validating::File_and_line &file_and_line ) {
	throw exception_Cule( message, file_and_line );
}

} // namespace free

} // namespace cule
} // namespace jmsf
