#include "TestResult.h"
#include "../TestFailure.h"

#include "jmsf/pointing/Constant_pointer.inl"
#include "jmsf/typing/Naturals.inl"

////#include "jmsf/Pointers.hpp"


namespace jmsf {
namespace cule {
namespace results {


TestResult::~TestResult()
{}

TestResult::TestResult() {
	_numberOfRunnedTests = typing::Natural_nill;
}

void TestResult::addTest() {
	_numberOfRunnedTests += typing::Natural_one;
}

void TestResult::addFailure( const pointing::Constant_pointer< TestFailure > &testFailure ) {
	_failures.push_back( testFailure );
}

void TestResult::addError( const pointing::Constant_pointer< TestFailure > &testFailure ) {
	_errors.push_back( testFailure );
}

void TestResult::addUnknownError( const pointing::Constant_pointer< TestFailure > &testFailure ) {
	_unknownErrors.push_back( testFailure );
}

void TestResult::setTotalTestingDuration( const typing::Natural totalTestingDuration ) {
	_totalTestingDuration = totalTestingDuration;
}

const std::vector< const pointing::Constant_pointer< TestFailure > > &TestResult::getFailureContainer() const {
	return _failures;
}

const std::vector< const pointing::Constant_pointer< TestFailure > > &TestResult::getErrorContainer() const {
	return _errors;
}

const std::vector< const pointing::Constant_pointer< TestFailure > > &TestResult::getUnknownErrorContainer() const {
	return _unknownErrors;
}

typing::Natural TestResult::getTotalTestingDuration() const {
	return _totalTestingDuration;
}

typing::Natural TestResult::getNumberOfRunnedTests() const {
	return _numberOfRunnedTests;
}


} // namespace
}
}
