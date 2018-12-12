#pragma once


////#include "jmsf/types.h"

#include "../TestFailure.hxx"
////#include "jmsf/Pointers.hxx"

#include "jmsf/pointing/Constant_pointer.hxx"
#include "jmsf/typing/Naturals.hpp"

#include "jmsf/stdal/stdal_stl.h"


namespace jmsf {
namespace cule {
namespace results {


class TestResult {

public:
	virtual ~TestResult();
	TestResult();

	void addTest();
	void addFailure( const pointing::Constant_pointer< TestFailure > &testFailure );
	void addError( const pointing::Constant_pointer< TestFailure > &testFailure );
	void addUnknownError( const pointing::Constant_pointer< TestFailure > &testFailure );
	void setTotalTestingDuration( typing::Natural totalTestingDuration );

	const std::vector< const pointing::Constant_pointer< TestFailure > > &getFailureContainer() const;
	const std::vector< const pointing::Constant_pointer< TestFailure > > &getErrorContainer() const;
	const std::vector< const pointing::Constant_pointer< TestFailure > > &getUnknownErrorContainer() const;
	typing::Natural getTotalTestingDuration() const;
	typing::Natural getNumberOfRunnedTests() const;

private:
	TestResult( const TestResult & ) {}
	const TestResult &operator=( const TestResult & ) { return *this; }

private:
	std::vector< const pointing::Constant_pointer< TestFailure > > _failures;
	std::vector< const pointing::Constant_pointer< TestFailure > > _errors;
	std::vector< const pointing::Constant_pointer< TestFailure > > _unknownErrors;	

	typing::Natural _numberOfRunnedTests;
	typing::Natural _totalTestingDuration;
};


} // namespace
}
}
