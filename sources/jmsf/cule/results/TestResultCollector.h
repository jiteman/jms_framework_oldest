#pragma once

#include "../user_interfaces/UiOutput.hxx"
#include "../TestFailure.hxx"
#include "TestResult.hxx"

////#include "jmsf/Pointers.hpp"

#include "jmsf/pointing/Pointer.hpp"
#include "jmsf/pointing/Constant_pointer.hpp"


namespace jmsf {
namespace cule {
namespace results {


class TestResultCollector {

public:
	virtual ~TestResultCollector();
	TestResultCollector( const pointing::Pointer< user_interfaces::UiOutput > &uiOutput, const pointing::Pointer< TestResult > &testResult );

	void testingStarted();
	void testingFinished();

	void oneMoreTestRunning();

	void addFailure( const pointing::Constant_pointer< TestFailure > &testFailure );
	void addError( const pointing::Constant_pointer< TestFailure > &testFailure );
	void addUnknownError( const pointing::Constant_pointer< TestFailure > &testFailure );

	const pointing::Constant_pointer< TestResult > &getCollectedTestResult();

private:
	TestResultCollector( const TestResultCollector & ) {} 
	const TestResultCollector &operator=( const TestResultCollector & ) { return *this; }

private:
	pointing::Pointer< TestResult > _testResult;
	const pointing::Constant_pointer< TestResult > _constantTestResult;
	pointing::Pointer< user_interfaces::UiOutput > _uiOutput;

};


} // namespace
}
}
