#include "SingleTestRunner.h"
#include "../results/TestResultCollector.h"
#include "../results/TestResult.h"
#include "../user_interfaces/UiOutput.h"
#include "../exception_Cule.h"
#include "../Test_stop_watch.h"
#include "../TestFailure.h"

#include "jmsf/patterning/Singleton.inl"

#include "jmsf/pointing/Pointer.inl"
#include "jmsf/pointing/Constant_pointer.inl"
#include "jmsf/memorying/temporary_Allocator.h"

#include "jmsf/memorying/Constructor.inl"

////#include "jmsf/factory_TextObject.h"
////#include "jmsf/Proxies.hpp"
////#include "jmsf/stdal/stdal_stl.h"
////#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace cule {
namespace execution {


SingleTestRunner::~SingleTestRunner() {
}

SingleTestRunner::SingleTestRunner( const pointing::Pointer< results::TestResultCollector > &testResult, const pointing::Pointer< Test > &test )
	:
		_test( test ),
		_testResultCollector( testResult )
{}

void SingleTestRunner::runTest() {
	_testResultCollector->oneMoreTestRunning();
	Test_stop_watch::instance()->startLocal();

	try {
		_test->run();
	} catch ( exception_Cule e ) {
		_testResultCollector->addFailure( createTestFailure( e ) );
	} catch ( std::exception e ) {
		memorying::temporary_Allocator temporary_allocator;
		memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );

		exception_Cule culeException( AS_C_string( the_temporary_allocator, e.what() ), validating::File_and_line() );
		_testResultCollector->addError( createTestFailure( culeException ) );
	} catch ( ... ) {
		exception_Cule culeException( AS_string_literal( exception_Cule::UNKNOWN_EXCEPTION_REASON ), validating::File_and_line() );
		_testResultCollector->addError( createTestFailure( culeException ) );
	}	
}

const pointing::Constant_pointer< TestFailure > SingleTestRunner::createTestFailure( const exception_Cule &culeException ) {
	memorying::temporary_Allocator temporary_allocator;
	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );

	return pointing::Constant_pointer< TestFailure >::create_unique(
		memorying::Constructor< TestFailure, TestFailure >::construct(
			the_temporary_allocator,
			_test->get_filename(),
			_test->get_name(),
			_test->get_line_number(),
			culeException.get_description(),
			culeException.get_line_number() ) );
}


} // namespace execution
} // namespace cule
} // namespace jmsf
