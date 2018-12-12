#include "TestResultCollector.h"
#include "../user_interfaces/UiOutput.h"
#include "../Test_stop_watch.h"
#include "../TestFailure.h"
#include "TestResult.h"

#include "jmsf/patterning/Singleton.inl"

#include "jmsf/pointing/Pointer.inl"


namespace jmsf {
namespace cule {
namespace results {


TestResultCollector::~TestResultCollector()
{}

TestResultCollector::TestResultCollector( const pointing::Pointer< user_interfaces::UiOutput > &uiOutput, const pointing::Pointer< TestResult > &testResult )
	:
		_uiOutput( uiOutput ),
		_constantTestResult( testResult.get_nonlinked_constant() )		
{
	_testResult = testResult;
}

void TestResultCollector::testingStarted() {
	_uiOutput->indicateTestingStarted();
	Test_stop_watch::instance()->startGlobal();	
}

void TestResultCollector::testingFinished() {
	_testResult->setTotalTestingDuration( Test_stop_watch::instance()->getGlobalDuration() );
}

void TestResultCollector::oneMoreTestRunning() {
	_testResult->addTest();
	_uiOutput->indicateTestStart();
}

void TestResultCollector::addFailure( const pointing::Constant_pointer< TestFailure > &testFailure ) {
	_testResult->addFailure( testFailure );
	_uiOutput->indicateFailure();
}

void TestResultCollector::addError( const pointing::Constant_pointer< TestFailure > &testFailure ) {
	_testResult->addError( testFailure );
	_uiOutput->indicateError();
}

void TestResultCollector::addUnknownError( const pointing::Constant_pointer< TestFailure > &testFailure ) {
	_testResult->addUnknownError( testFailure );
	_uiOutput->indicateUnknownError();
}

const pointing::Constant_pointer< TestResult > &TestResultCollector::getCollectedTestResult() {
	return _constantTestResult;
}


} // namespace
}
}
