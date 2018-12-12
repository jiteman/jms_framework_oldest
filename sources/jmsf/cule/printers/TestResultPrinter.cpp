#include "TestResultPrinter.h"
#include "../results/TestResult.h"
#include "../user_interfaces/UiOutput.h"
#include "../TestFailure.h"
#include "TestFailurePrinter.h"

#include "jmsf/pointing/Pointer.inl"
#include "jmsf/pointing/Constant_pointer.inl"

#include "jmsf/typing/Ansii_string.h"
#include "jmsf/typing/Boolean.h"

#include "jmsf/memorying/Constructor.inl"
#include "jmsf/memorying/temporary_Allocator.h"

////#include "jmsf/factory_TextObject.h"
////#include "jmsf/TextString.h"
////#include "jmsf/PointersAndProxies.hpp"
////#include "jmsf/Boolean.h"
////#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace cule {
namespace printers {


const typing::internals::platform_character_type *TestResultPrinter::UNKNOWN_ERROR_NAME = "unknown error";
const typing::internals::platform_character_type *TestResultPrinter::ERROR_NAME = "error";
const typing::internals::platform_character_type *TestResultPrinter::FAILURE_NAME = "failure";


TestResultPrinter::~TestResultPrinter()
{}

TestResultPrinter::TestResultPrinter( const pointing::Pointer< user_interfaces::UiOutput > &uiOutput, const pointing::Constant_pointer< results::TestResult > &testResult )
	:
		_uiOutput( uiOutput ),
		_testResult( testResult )
{}

void TestResultPrinter::print() {
	const typing::Boolean there_is_no_error =
		typing::Boolean::create( _testResult->getUnknownErrorContainer().empty() ) &&
		typing::Boolean::create( _testResult->getErrorContainer().empty() ) &&
		typing::Boolean::create( _testResult->getFailureContainer().empty() );

	if ( there_is_no_error ) {
		_uiOutput->printNoErrors();
	} else {
		printTestFailures( _testResult->getUnknownErrorContainer(), AS_string_literal( UNKNOWN_ERROR_NAME ) );
		printTestFailures( _testResult->getErrorContainer(), AS_string_literal( ERROR_NAME ) );
		printTestFailures( _testResult->getFailureContainer(), AS_string_literal( FAILURE_NAME ) );
	}

	const typing::Natural numberOfRunnedTests = _testResult->getNumberOfRunnedTests();
	const typing::Natural totalTestingDuration = _testResult->getTotalTestingDuration();
	_uiOutput->printTotalTestingDuration( numberOfRunnedTests, totalTestingDuration );
}

void TestResultPrinter::printTestFailures( const std::vector< const pointing::Constant_pointer< TestFailure > > &vector , const typing::Ansii_string &name ) {
	if ( !vector.empty() ) {
		typing::Natural number = typing::Natural_one;

		_uiOutput->printBlankLine();
		_uiOutput->printBlankLine();

		memorying::temporary_Allocator temporary_allocator;
		memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );

		pointing::Pointer< TestFailurePrinter > test_failure_printer =
			pointing::Pointer< TestFailurePrinter >::create_unique(
				memorying::Constructor< TestFailurePrinter, TestFailurePrinter >::construct( the_temporary_allocator, _uiOutput ) );

////		TestFailurePrinter *testFailurePrinterPointer = new TestFailurePrinter( _uiOutput );
////		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( testFailurePrinterPointer, MACROS_FILE_AND_LINE ) );
////		Pointer< TestFailurePrinter > testFailurePrinter = Pointer< TestFailurePrinter >::createUnique( testFailurePrinterPointer );

		for ( std::vector< const pointing::Constant_pointer< TestFailure > >::const_iterator cit = vector.begin(); cit != vector.end(); ++cit ) {
			test_failure_printer->print( number, *cit );
			number += typing::Natural_one;
		}

		_uiOutput->printTestFailureCaption( typing::Natural::create( vector.size() ), name );
	}
}


} // namespace
}
}
