#pragma once

#include "jmsf/typing/Ansii_string.h"
#include "jmsf/typing/Naturals.hxx"
#include "jmsf/typing/Boolean.hxx"
#include "jmsf/validating/File_and_line.hxx"
//#include "jmsf/TextStream.h"

#include "cule.h"


namespace jmsf {
namespace cule {


	namespace free {
		JMSF_CULE_DLL_INTERFACE void ThrowCuleException( const typing::Ansii_string &message, const validating::File_and_line &file_and_line );
	}

class JMSF_CULE_DLL_INTERFACE Assert {

public:
	static void real_notImplementedYet( const typing::Ansii_string &message, const validating::File_and_line &file_and_line );
	static void real_testNotImplementedYet( const typing::Ansii_string &message, const validating::File_and_line &file_and_line );

	static void real_shouldBe( typing::Boolean actual, const validating::File_and_line &file_and_line );
	static void real_shouldNotBe( typing::Boolean actual, const validating::File_and_line &file_and_line );

	static void real_stringsShouldBeEqual( const typing::Ansii_string &expected, const typing::Ansii_string &actual, const validating::File_and_line &file_and_line );
	static void real_stringsShouldNotBeEqual( const typing::Ansii_string &expected, const typing::Ansii_string &actual, const validating::File_and_line &file_and_line );

//	static void real_shouldNotTakeLongerThan( typing::Natural expectedDuration, const validating::File_and_line &file_and_line );

	template< class An_object_type >
	static void real_overloadedShouldBeEqual( const An_object_type &expected, const An_object_type &actual, const validating::File_and_line &file_and_line );

	template< class An_object_type_one, class An_object_type_two >
	static void real_objectsShouldBeEqual( const An_object_type_one &expected, const An_object_type_two &actual, const validating::File_and_line &file_and_line );

	template< class An_object_type_one, class An_object_type_two >
	static void real_objectsShouldBeIdentical( const An_object_type_one &expected, const An_object_type_two &actual, const validating::File_and_line &file_and_line );

	template< class An_object_type >
	static void real_integerValuesShouldBeEqual( const An_object_type expected, const An_object_type actual, const validating::File_and_line &file_and_line );

	template< class An_object_type >
	static void real_naturalValuesShouldBeEqual( const An_object_type expected, const An_object_type actual, const validating::File_and_line &file_and_line );

	template< class An_object_type >
	static void real_overloadedShouldNotBeEqual( const An_object_type &expected, const An_object_type &actual, const validating::File_and_line &file_and_line );

	template< class An_object_type_one, class An_object_type_two >
	static void real_objectsShouldNotBeEqual( const An_object_type_one &expected, const An_object_type_two &actual, const validating::File_and_line &file_and_line );

	template< class An_object_type_one, class An_object_type_two >
	static void real_objectsShouldNotBeIdentical( const An_object_type_one &expected, const An_object_type_two &actual, const validating::File_and_line &file_and_line );

	template< class An_object_type >
	static void real_integerValuesShouldNotBeEqual( const An_object_type expected, const An_object_type actual, const validating::File_and_line &file_and_line );

	template< class An_object_type >
	static void real_naturalValuesShouldNotBeEqual( const An_object_type expected, const An_object_type actual, const validating::File_and_line &file_and_line );

	template< class A_real_type >
	static void real_valuesShouldBeCloseEqual( A_real_type expected, A_real_type actual, A_real_type accuracy, const validating::File_and_line &file_and_line );

	template< class A_real_type >
	static void real_valuesShouldNotBeCloseEqual( A_real_type expected, A_real_type actual, A_real_type accuracy, const validating::File_and_line &file_and_line );

	template< class An_object_type >
	static void real_pointerShouldBeNull( const An_object_type *actual, const validating::File_and_line &file_and_line );

	template< class An_object_type >
	static void real_pointerShouldNotBeNull( const An_object_type *actual, const validating::File_and_line &file_and_line );

// 	template< class An_object_type >
// 	static void real_pointerShouldBeNullObject( const An_object_type *actual, long lineNumber );
// 
// 	template< class An_object_type >
// 	static void real_pointerShouldNotBeNullObject( const An_object_type *actual, long lineNumber );

	template< class An_object_type >
	static void real_objectsShouldBeTheSame( const An_object_type &expected, const An_object_type &actual, const validating::File_and_line &file_and_line );

	template< class An_object_type >
	static void real_objectsShouldNotBeTheSame( const An_object_type &expected, const An_object_type &actual, const validating::File_and_line &file_and_line );

	template< class An_object_type >
	static void real_pointersShouldBeTheSame( const An_object_type *expected, const An_object_type *actual, const validating::File_and_line &file_and_line );

	template< class An_object_type >
	static void real_pointersShouldNotBeTheSame( const An_object_type *expected, const An_object_type *actual, const validating::File_and_line &file_and_line );

	template< class An_object_type_first, class An_object_type_second >
	static void real_proxiesShouldBeTheSame( const An_object_type_first &expected, const An_object_type_second &actual, const validating::File_and_line &file_and_line );

	template< class An_object_type_first, class An_object_type_second >
	static void real_proxiesShouldNotBeTheSame( const An_object_type_first &expected, const An_object_type_second &actual, const validating::File_and_line &file_and_line );

};


template< class An_object_type >
void Assert::real_overloadedShouldBeEqual( const An_object_type &expected, const An_object_type &actual, const validating::File_and_line &file_and_line ) {
	if ( expected != actual ) {
		to_remove::ToStringConverter converter;
		std::_tstringstream messageStream;
		messageStream << L"expected == to: ";
		messageStream << converter.toString( expected );
		messageStream << L", but was: ";
		messageStream << converter.toString( actual );
		free::ThrowCuleException( messageStream.str(), lineNumber );
	}
}

template< class An_object_type_one, class An_object_type_two >
void Assert::real_objectsShouldBeEqual( const An_object_type_one &expected, const An_object_type_two &actual, const validating::File_and_line &file_and_line ) {
	if ( expected->isNotEqualTo( actual ) ) {
		to_remove::ToStringConverter converter;
		std::_tstringstream messageStream;
		messageStream << L"expected equal to: ";
		messageStream << converter.toString( expected );
		messageStream << L", but was: ";
		messageStream << converter.toString( actual );
		free::ThrowCuleException( messageStream.str(), lineNumber );
	}
}

template< class An_object_type_one, class An_object_type_two >
void Assert::real_objectsShouldBeIdentical( const An_object_type_one &expected, const An_object_type_two &actual, const validating::File_and_line &file_and_line ) {
	if ( expected->isNotIdenticalTo( actual ) ) {
		to_remove::ToStringConverter converter;
		std::_tstringstream messageStream;
		messageStream << L"expected identical to: ";
		messageStream << converter.toString( expected );
		messageStream << L", but was: ";
		messageStream << converter.toString( actual );
		free::ThrowCuleException( messageStream.str(), lineNumber );
	}
}

template< class An_object_type >
void Assert::real_integerValuesShouldBeEqual( const An_object_type expected, const An_object_type actual, const validating::File_and_line &file_and_line ) {
	if ( expected != actual ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "expected equal to: " ) )->putInteger( expected );
		textStream->put( CONSTANT_TEXT_STRING( ", but was: " ) )->putInteger( actual );
		free::ThrowCuleException( textStream.getNonlinkedConstant(), lineNumber );
	}
}

template< class An_object_type >
void Assert::real_naturalValuesShouldBeEqual( const An_object_type expected, const An_object_type actual, const validating::File_and_line &file_and_line ) {
	if ( expected != actual ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "expected equal to: " ) )->putNatural( expected );
		textStream->put( CONSTANT_TEXT_STRING( ", but was: " ) )->putNatural( actual );
		free::ThrowCuleException( textStream.getNonlinkedConstant(), lineNumber );
	}
}

template< class An_object_type >
static void real_overloadedShouldNotBeEqual(  const An_object_type &expected, const An_object_type &actual, const validating::File_and_line &file_and_line ) {
	if ( expected == actual ) {
		to_remove::ToStringConverter converter;
		std::_tstringstream messageStream;
		messageStream << L"expected != to: ";
		messageStream << converter.toString( expected );
		messageStream << L", but was: ";
		messageStream << converter.toString( actual );
		free::ThrowCuleException( messageStream.str(), lineNumber );
	}
}

template< class An_object_type_one, class An_object_type_two >
void Assert::real_objectsShouldNotBeEqual( const An_object_type_one &expected, const An_object_type_two &actual, const validating::File_and_line &file_and_line ) {
	if ( expected->isEqualTo( actual ) ) {
		to_remove::ToStringConverter converter;
		std::_tstringstream messageStream;
		messageStream << L"expected not equal to: ";
		messageStream << converter.toString( expected );
		messageStream << L", but was: ";
		messageStream << converter.toString( actual );
		free::ThrowCuleException( messageStream.str(), lineNumber );
	}
}

template< class An_object_type_one, class An_object_type_two >
void Assert::real_objectsShouldNotBeIdentical( const An_object_type_one &expected, const An_object_type_two &actual, const validating::File_and_line &file_and_line ) {
	if ( expected->isIdenticalTo( actual ) ) {
		to_remove::ToStringConverter converter;
		std::_tstringstream messageStream;
		messageStream << L"expected object not identical to: ";
		messageStream << converter.toString( expected );
		messageStream << L", but got: ";
		messageStream << converter.toString( actual );
		free::ThrowCuleException( messageStream.str(), lineNumber );
	}
}

template< class An_object_type >
void Assert::real_integerValuesShouldNotBeEqual( const An_object_type expected, const An_object_type actual, const validating::File_and_line &file_and_line ) {
	if ( expected == actual ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "expected value not equal to: " ) )->putInteger( expected );
		textStream->put( CONSTANT_TEXT_STRING( ", but have gotten value: " ) )->putInteger( actual );
		free::ThrowCuleException( textStream.getWeakConstant(), lineNumber );
	}
}

template< class An_object_type >
void Assert::real_naturalValuesShouldNotBeEqual( const An_object_type expected, const An_object_type actual, const validating::File_and_line &file_and_line ) {
	if ( expected == actual ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "expected value not equal to: " ) )->putNatural( expected );
		textStream->put( CONSTANT_TEXT_STRING( ", but have gotten value: " ) )->putNatural( actual );
		free::ThrowCuleException( textStream.getWeakConstant(), lineNumber );
	}
}

template< class A_real_type >
void Assert::real_valuesShouldBeCloseEqual( const A_real_type expected, const A_real_type actual, const A_real_type accuracy, const validating::File_and_line &file_and_line ) {
	if ( expected - actual > accuracy || actual - expected > accuracy ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "expected: " ) )->putReal( expected );
		textStream->put( CONSTANT_TEXT_STRING( " with accuracy: " ) )->putReal( accuracy );
		textStream->put( CONSTANT_TEXT_STRING( ", but was: " ) )->putReal( actual );
		free::ThrowCuleException( textStream.getNonlinkedConstant(), lineNumber );
	}
}

template< class A_real_type >
void Assert::real_valuesShouldNotBeCloseEqual( const A_real_type expected, const A_real_type actual, const A_real_type accuracy, const validating::File_and_line &file_and_line ) {
	if ( !( expected - actual > accuracy || actual - expected > accuracy ) ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "expected: != " ) )->putReal( expected );
		textStream->put( CONSTANT_TEXT_STRING( " with accuracy: " ) )->putReal( accuracy );
		textStream->put( CONSTANT_TEXT_STRING( ", but was: " ) )->putReal( actual );
		free::ThrowCuleException( textStream.getNonlinkedConstant(), lineNumber );
	}
}

template< class An_object_type >
void Assert::real_pointerShouldBeNull( const An_object_type *actual, const validating::File_and_line &file_and_line ) {
	if ( actual != static_cast< An_object_type * >( 0 ) ) {
		to_remove::ToStringConverter converter;
		std::_tstringstream messageStream;
		messageStream << L"expected null pointer, but got pointer addressing: ";
		const long pointer = reinterpret_cast< long >( actual );
		messageStream << converter.toString( pointer );
		free::ThrowCuleException( messageStream.str(), lineNumber );
	}
}

template< class An_object_type >
void Assert::real_pointerShouldNotBeNull( const An_object_type *actual, const validating::File_and_line &file_and_line ) {
	if ( actual == static_cast< An_object_type * >( 0 ) ) {
		const typing::Ansii_string message = CONSTANT_TEXT_STRING( "expected not null pointer, but have gotten null pointer" );
		free::ThrowCuleException( message, lineNumber );
	}
}

template< class An_object_type >
void Assert::real_objectsShouldBeTheSame( const An_object_type &expected, const An_object_type &actual, const validating::File_and_line &file_and_line ) {
	if ( &expected != &actual ) {
		to_remove::ToStringConverter converter;
		std::_tstringstream messageStream;
		messageStream << L"expected the same object with address: ";

		{
			const long expectedPointer = reinterpret_cast< long >( &expected );
			messageStream << converter.toString( expectedPointer );
		}

		messageStream << L", but got object with address: ";

		{
			const long actualPointer = reinterpret_cast< long >( &actual );
			messageStream << converter.toString( actualPointer );
		}

		free::ThrowCuleException( messageStream.str(), lineNumber );
	}
}

template< class An_object_type >
void Assert::real_objectsShouldNotBeTheSame( const An_object_type &expected, const An_object_type &actual, const validating::File_and_line &file_and_line ) {
	if ( &expected == &actual ) {
		const std::wstring message = L"expected not the same object, but got the same object";
		free::ThrowCuleException( message, lineNumber );
	}
}

template< class An_object_type >
void Assert::real_pointersShouldBeTheSame( const An_object_type *expected, const An_object_type *actual, const validating::File_and_line &file_and_line ) {
	if ( expected != actual ) {
		to_remove::ToStringConverter converter;
		std::_tstringstream messageStream;
		messageStream << L"expected the same pointer as: ";

		{
			const long expectedPointer = reinterpret_cast< long >( expected );
			messageStream << converter.toString( expectedPointer );
		}

		messageStream << L", but got the pointer: ";

		{
			const long actualPointer = reinterpret_cast< long >( actual );
			messageStream << converter.toString( actualPointer );
		}

		free::ThrowCuleException( messageStream.str(), lineNumber );
	}
}

template< class An_object_type >
void Assert::real_pointersShouldNotBeTheSame( const An_object_type *expected, const An_object_type *actual, const validating::File_and_line &file_and_line ) {
	if ( &expected == &actual ) {
		const std::wstring message = L"expected not the same pointer, but got the same pointer";
		free::ThrowCuleException( message, lineNumber );
	}
}

template< class An_object_type_first, class An_object_type_second >
void Assert::real_proxiesShouldBeTheSame( const An_object_type_first &expected, const An_object_type_second &actual, const validating::File_and_line &file_and_line ) {
	if ( expected.isNotTheSameAs( actual ) ) {
		const std::_tstring message = _t( "expected the same proxy, but got not the same proxy" );

		to_remove::ToStringConverter converter;
		std::_tstringstream messageStream;
		messageStream << L"expected the same pointer as: ";

		{
			const long expectedPointer = reinterpret_cast< long >( &( *expected ) );
			messageStream << converter.toString( expectedPointer );
		}

		messageStream << L", but got the pointer: ";

		{
			const long actualPointer = reinterpret_cast< long >( &( *actual ) );
			messageStream << converter.toString( actualPointer );
		}

		free::ThrowCuleException( message, lineNumber );
	}
}

template< class An_object_type_first, class An_object_type_second >
void Assert::real_proxiesShouldNotBeTheSame( const An_object_type_first &expected, const An_object_type_second &actual, const validating::File_and_line &file_and_line ) {
	if ( expected.isTheSameAs( actual ) ) {
		const std::_tstring message = _t( "expected not the same proxy, but got the same proxy" );
		free::ThrowCuleException( message, lineNumber );
	}
}


} // namespace
}


// #if defined( _UNICODE )
// 	#define WIDEN2( _x ) L ## _x
// 	#define WIDEN( _x ) WIDEN2( _x )
// 	#define __WFILE__ WIDEN( __FILE__ )
// 	#define line_file __WFILE__, __LINE__
// #else
//	#define line_file __FILE__, __LINE__
//#endif


//----------------------------------------------------------------------------------------------------------------------
#define notImplementedYet( value )\
	jmsf::cule::Assert::real_notImplementedYet( ( value ), FILE_AND_LINE )

//----------------------------------------------------------------------------------------------------------------------
#define testNotImplementedYet( value )\
	jmsf::cule::Assert::real_testNotImplementedYet( ( value ), FILE_AND_LINE )


//----------------------------------------------------------------------------------------------------------------------
#define shouldBe( value )\
	jmsf::cule::Assert::real_shouldBe( ( value ), FILE_AND_LINE )
//----------------------------------------------------------------------------------------------------------------------
#define shouldNotBe( value )\
	jmsf::cule::Assert::real_shouldNotBe( ( value ), FILE_AND_LINE )


//----------------------------------------------------------------------------------------------------------------------
#define stringsShouldBeEqual( expected, actual )\
	jmsf::cule::Assert::real_stringsShouldBeEqual( ( expected ), ( actual ), FILE_AND_LINE )
//----------------------------------------------------------------------------------------------------------------------
#define stringsShouldNotBeEqual( expected, actual )\
	jmsf::cule::Assert::real_stringsShouldNotBeEqual( ( expected ), ( actual ), FILE_AND_LINE )


//----------------------------------------------------------------------------------------------------------------------
#define shouldBeEqual( expected, actual )\
	jmsf::cule::Assert::real_overloadedShouldBeEqual( ( expected ), ( actual ), FILE_AND_LINE )
//----------------------------------------------------------------------------------------------------------------------
#define shouldNotBeEqual( expected, actual )\
	jmsf::cule::Assert::real_overloadedShouldNotBeEqual( ( expected ), ( actual ), FILE_AND_LINE )


//----------------------------------------------------------------------------------------------------------------------
#define objectsShouldBeEqual( expected, actual )\
	jmsf::cule::Assert::real_objectsShouldBeEqual( ( expected ), ( actual ), FILE_AND_LINE )
//----------------------------------------------------------------------------------------------------------------------
#define objectsShouldNotBeEqual( expected, actual )\
	jmsf::cule::Assert::real_objectsShouldNotBeEqual( ( expected ), ( actual ), FILE_AND_LINE )

//----------------------------------------------------------------------------------------------------------------------
#define objectsShouldBeIdentical( expected, actual )\
	jmsf::cule::Assert::real_objectsShouldBeIdentical( ( expected ), ( actual ), FILE_AND_LINE )
//----------------------------------------------------------------------------------------------------------------------
#define objectsShouldNotBeIdentical( expected, actual )\
	jmsf::cule::Assert::real_objectsShouldNotBeIdentical( ( expected ), ( actual ), FILE_AND_LINE )


//----------------------------------------------------------------------------------------------------------------------
#define integerValuesShouldBeEqual( expected, actual )\
	jmsf::cule::Assert::real_integerValuesShouldBeEqual( ( expected ), ( actual ), FILE_AND_LINE )
//----------------------------------------------------------------------------------------------------------------------
#define integerValuesShouldNotBeEqual( expected, actual )\
	jmsf::cule::Assert::real_integerValuesShouldNotBeEqual( ( expected ), ( actual ), FILE_AND_LINE )

//----------------------------------------------------------------------------------------------------------------------
#define naturalValuesShouldBeEqual( expected, actual )\
	jmsf::cule::Assert::real_typing::NaturalValuesShouldBeEqual( ( expected ), ( actual ), FILE_AND_LINE )
//----------------------------------------------------------------------------------------------------------------------
#define naturalValuesShouldNotBeEqual( expected, actual )\
	jmsf::cule::Assert::real_typing::NaturalValuesNotShouldBeEqual( ( expected ), ( actual ), FILE_AND_LINE )

//----------------------------------------------------------------------------------------------------------------------
#define valuesShouldBeCloseEqual( expected, actual, accuracy )\
	jmsf::cule::Assert::real_valuesShouldBeCloseEqual( ( expected ), ( actual ), ( accuracy ), FILE_AND_LINE )
//----------------------------------------------------------------------------------------------------------------------
#define valuesShouldNoBeCloseEqual( expected, actual, accuracy )\
	jmsf::cule::Assert::real_valuesShouldNotBeCloseEqual( ( expected ), ( actual ), ( accuracy ), FILE_AND_LINE )


//----------------------------------------------------------------------------------------------------------------------
#define pointerShouldBeNull( value )\
	jmsf::cule::Assert::real_pointerShouldBeNull( ( value ), FILE_AND_LINE )
//----------------------------------------------------------------------------------------------------------------------
#define pointerShouldNotBeNull( value )\
	jmsf::cule::Assert::real_pointerShouldNotBeNull( ( value ), FILE_AND_LINE )


//----------------------------------------------------------------------------------------------------------------------
#define objectsShouldBeTheSame( expected, actual )\
	jmsf::cule::Assert::real_objectsShouldBeTheSame( ( expected ), ( actual ), FILE_AND_LINE )
//----------------------------------------------------------------------------------------------------------------------
#define objectsShouldNotBeTheSame( expected, actual )\
	jmsf::cule::Assert::real_objectsShouldNotBeTheSame( ( expected ), ( actual ), FILE_AND_LINE )


//----------------------------------------------------------------------------------------------------------------------
#define pointersShouldBeTheSame( expected, actual )\
	jmsf::cule::Assert::real_pointersShouldBeTheSame( ( expected ), ( actual ), FILE_AND_LINE )
//----------------------------------------------------------------------------------------------------------------------
#define pointersShouldNotBeTheSame( expected, actual )\
	jmsf::cule::Assert::real_pointersShouldNotBeTheSame( ( expected ), ( actual ), FILE_AND_LINE )


//----------------------------------------------------------------------------------------------------------------------
#define proxiesShouldBeTheSame( expected, actual )\
	jmsf::cule::Assert::real_proxiesShouldBeTheSame( ( expected ), ( actual ), FILE_AND_LINE )
//----------------------------------------------------------------------------------------------------------------------
#define proxiesShouldNotBeTheSame( expected, actual )\
	jmsf::cule::Assert::real_proxiesShouldNotBeTheSame( ( expected ), ( actual ), FILE_AND_LINE )


//----------------------------------------------------------------------------------------------------------------------
#define shouldNotTakeLongerThan( expected )\
	jmsf::cule::Assert::real_shouldNotTakeLongerThan( ( expected ), FILE_AND_LINE )
