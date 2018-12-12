#include "TestRunner.h"
#include "../results/TestResultCollector.h"
#include "../results/TestResult.h"
#include "../user_interfaces/UiOutput.h"
#include "../TestRegistry.h"
#include "../TestFailure.h"
#include "SingleTestRunner.h"
#include "../printers/TestResultPrinter.h"

#include "jmsf/pointing/Pointer.inl"
#include "jmsf/pointing/Constant_pointer.inl"

#include "jmsf/memorying/Constructor.inl"
#include "jmsf/memorying/temporary_Allocator.h"

#include "jmsf/stdal/stdal_stl.h"
////#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace cule {
namespace execution {

TestRunner::~TestRunner()
{}

TestRunner::TestRunner( const pointing::Pointer< user_interfaces::UiOutput > &uiOutput )
	:
		_uiOutput( uiOutput )
{}

void TestRunner::run() {
	memorying::temporary_Allocator temporary_allocator;
	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );

	pointing::Pointer< results::TestResult > test_result =
		pointing::Pointer< results::TestResult >::create_unique(
			memorying::Constructor< results::TestResult, results::TestResult >::construct( the_temporary_allocator ) );

////	results::TestResult *testResult = new results::TestResult;
////	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( testResult, MACROS_FILE_AND_LINE ) );

	pointing::Pointer< results::TestResultCollector > test_result_collector =
		pointing::Pointer< results::TestResultCollector >::create_unique(
			memorying::Constructor< results::TestResultCollector, results::TestResultCollector >::construct( the_temporary_allocator, _uiOutput.get_nonlinked(), test_result ) );

////	results::TestResultCollector testResultCollector( _uiOutput.get_nonlinked(), test_result );
	const std::vector< pointing::Pointer< Test > > &registeredTests = Test::get_test_registry().getRegisteredTests();
	test_result_collector->testingStarted();

	for ( std::vector< pointing::Pointer< Test > >::const_iterator testIterator = registeredTests.begin(); testIterator != registeredTests.end(); ++testIterator ) {
		SingleTestRunner singleTestRunner( test_result_collector.get_nonlinked(), ( *testIterator ).get_nonlinked() );
		singleTestRunner.runTest();
	}

	test_result_collector->testingFinished();
	print( test_result_collector->getCollectedTestResult() );	
}

void TestRunner::print( const pointing::Constant_pointer< results::TestResult > &testResult ) {
	memorying::temporary_Allocator temporary_allocator;
	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );

	pointing::Pointer< printers::TestResultPrinter > test_result_printer =
		pointing::Pointer< printers::TestResultPrinter >::create_unique(
			memorying::Constructor< printers::TestResultPrinter, printers::TestResultPrinter >::construct( the_temporary_allocator, _uiOutput.get_nonlinked(), testResult ) );

////	printers::TestResultPrinter *testResultPrinterPointer = new printers::TestResultPrinter( _uiOutput.getNonlinked(), testResult );
////	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( testResultPrinterPointer, MACROS_FILE_AND_LINE ) );
	test_result_printer->print();
}

} // namespace
}
}
