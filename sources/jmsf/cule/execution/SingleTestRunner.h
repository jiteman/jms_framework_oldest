#pragma once


#include "../Test.h"

#include "jmsf/pointing/Pointer.hpp"

#include "jmsf/pointing/Constant_pointer.hxx"
////#include "jmsf/Pointer.hpp"



namespace jmsf {
namespace cule {

	class Test;
	class exception_Cule;
	class TestFailure;

	namespace results {
		class TestResultCollector;
	}	

namespace execution {	


class SingleTestRunner {

	pointing::Pointer< results::TestResultCollector > _testResultCollector;
	pointing::Pointer< Test > _test;

public:
	virtual ~SingleTestRunner();
	SingleTestRunner( const pointing::Pointer< results::TestResultCollector > &testResult, const pointing::Pointer< Test > &test );

	void runTest();

private:
	const pointing::Constant_pointer< TestFailure > createTestFailure( const exception_Cule &culeException );

	SingleTestRunner( const SingleTestRunner & ) {}
	const SingleTestRunner &operator=( const SingleTestRunner & ) { return *this; }

};


} // namespace
}
}
