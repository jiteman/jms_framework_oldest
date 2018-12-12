#include "UiOutput.h"

// #include "jmsf/factory_TextObject.h"
// #include "jmsf/TextStream.h"
// #include "jmsf/TextString.h"
// #include "jmsf/Proxies.hpp"
// #include "jmsf/Real.h"

#include "jmsf/typing/Ansii_string_stream.h"
#include "jmsf/typing/Ansii_string_stream.inl"
#include "jmsf/typing/Ansii_string.h"
#include "jmsf/typing/Naturals.inl"
#include "jmsf/typing/Reals.inl"

#include "jmsf/memorying/temporary_Allocator.h"

#include "jmsf/stdal/stdal_stl.h"


namespace jmsf {
namespace cule {
namespace user_interfaces {


const typing::internals::platform_character_type *UiOutput::TEST_START_INDICATOR = ".";
const typing::internals::platform_character_type *UiOutput::FAILURE_INDICATOR = "F\n";
const typing::internals::platform_character_type *UiOutput::ERROR_INDICATOR = "E\n";
const typing::internals::platform_character_type *UiOutput::UNKNOWN_ERROR_INDICATOR = "U\n";
const typing::internals::platform_character_type *UiOutput::BLANK_LINE = "\n";


void UiOutput::indicateTestingStarted() {	
	print( AS_string_literal( "\nCpp Unit Lite Enchanced - [Cule] started\n" ) );
}

void UiOutput::indicateTestStart() {
	print( AS_string_literal( TEST_START_INDICATOR ) );
}

void UiOutput::indicateFailure() {
	print( AS_string_literal( FAILURE_INDICATOR ) );
}

void UiOutput::indicateError() {
	print( AS_string_literal( ERROR_INDICATOR ) );
}

void UiOutput::indicateUnknownError() {
	print( AS_string_literal( UNKNOWN_ERROR_INDICATOR ) );
}

void UiOutput::printBlankLine() {
	print( AS_string_literal( BLANK_LINE ) );
}

void UiOutput::printTestFailureCaption( const typing::Natural quantity, const typing::Ansii_string &name ) {
	memorying::temporary_Allocator temporary_allocator;
	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );
	typing::Ansii_string_stream ansii_stream = typing::Ansii_string_stream::create( the_temporary_allocator, the_temporary_allocator );

////	Proxy< TextStream > stream = factory_TextObject::instance()->createTextStream();

	ansii_stream.put_string( AS_string_literal( "\nThere " ) );
	ansii_stream.put_string( AS_string_literal( quantity > typing::Natural_one ? "were " : "was " ) );
	ansii_stream.put_natural( quantity );
	ansii_stream.put_string( AS_string_literal( " " ) );
	ansii_stream.put_string( name );
	
	if ( quantity > typing::Natural_one ) {
		ansii_stream.put_string( AS_string_literal( "s" ) );
	}

	ansii_stream.put_string( AS_string_literal( ":\n\n" ) );
	
////	stream->put( CONSTANT_TEXT_STRING( "\nThere " ) )->put( CONSTANT_TEXT_STRING( quantity > 1 ? "were " : "was " ) )->putInteger( quantity );
////	stream->put( CONSTANT_TEXT_STRING( " " ) )->put( name )->put( CONSTANT_TEXT_STRING( ( quantity > 1 ? "s" : "" ) ) );
////	stream->put( CONSTANT_TEXT_STRING( ":\n\n" ) );
	print( ansii_stream.create_consolidated_ansii_string( the_temporary_allocator ) );

////	print( stream->createTextString() );
}

void UiOutput::printTestFailure( const typing::Natural number, const typing::Ansii_string &fileName, const typing::Natural lineNumber, const typing::Ansii_string &message ) {
	memorying::temporary_Allocator temporary_allocator;
	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );
	typing::Ansii_string_stream ansii_stream = typing::Ansii_string_stream::create( the_temporary_allocator, the_temporary_allocator );

	ansii_stream.put_natural( number );
	ansii_stream.put_string( AS_string_literal( "> " ) );
	ansii_stream.put_string( fileName );
	ansii_stream.put_string( AS_string_literal( "( " ) );
	ansii_stream.put_natural( lineNumber );
	ansii_stream.put_string( AS_string_literal( " ) : " ) );
	ansii_stream.put_string( message );
	ansii_stream.put_string( AS_string_literal( "\n" ) );

////	Proxy< TextStream > stream = factory_TextObject::instance()->createTextStream();
	//stringStream << number << L") " << fileName << L"[ " << lineNumber << L" ] : " << message << L"\n";
////	stream->putInteger( number )->put( CONSTANT_TEXT_STRING( "> " ) )->put( fileName )->put( CONSTANT_TEXT_STRING( "( " ) )->putInteger( lineNumber )->put( CONSTANT_TEXT_STRING( " ) : " ) )->put( message )->put( CONSTANT_TEXT_STRING( "\n" ) );

	print( ansii_stream.create_consolidated_ansii_string( the_temporary_allocator ) );
////	print( stream->createTextString() );
}

void UiOutput::printNoErrors() {
	print( AS_string_literal( "\nThere were no test failures.\n" ) );
}

void UiOutput::printTotalTestingDuration( const typing::Natural number, const typing::Natural duration ) {	
	const typing::Short_real one_second = typing::Short_real::create( 1000.0f );
	const typing::Short_real real_duration = typing::Short_real::create( duration.get_value() );
	const typing::Boolean duration_is_longer_than_second = real_duration > one_second;

	const typing::Short_real duration_to_print = duration_is_longer_than_second ? real_duration / one_second : real_duration;

	memorying::temporary_Allocator temporary_allocator;
	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );
	typing::Ansii_string_stream ansii_stream = typing::Ansii_string_stream::create( the_temporary_allocator, the_temporary_allocator );

	ansii_stream.put_string( AS_string_literal( "Runned: " ) );
	ansii_stream.put_natural( number );
	ansii_stream.put_string( AS_string_literal( " test" ) );

	if ( number > typing::Natural_one ) {
		ansii_stream.put_string( AS_string_literal( "s" ) );
	}

	ansii_stream.put_string( AS_string_literal( ", execution time: " ) );
	ansii_stream.put_real( duration_to_print );
	ansii_stream.put_string( AS_string_literal( duration_is_longer_than_second ? " seconds" : " milliseconds" ) );
	ansii_stream.put_string( AS_string_literal( "\n\n" ) );

////	Proxy< TextStream > stream = factory_TextObject::instance()->createTextStream();
////	stream->put( CONSTANT_TEXT_STRING( "Runned: " ) )->putInteger( number );
////	stream->put( CONSTANT_TEXT_STRING( number > 1 ? " tests" : " test" ) )->put( CONSTANT_TEXT_STRING( ", execution time: " ) );
////	stream->putReal( preciseDuration )->put( CONSTANT_TEXT_STRING( duration > 1000 ? " seconds" : " milliseconds" ) )->put( CONSTANT_TEXT_STRING( "\n\n" ) );
//	stream << std::setprecision( 3 ) << preciseDuration << ( duration > 1000 ? L" seconds" : L" milliseconds" ) << L"\n\n";

	print( ansii_stream.create_consolidated_ansii_string( the_temporary_allocator ) );

////	print( stream->createTextString() );
}


} // namespace
}
}
