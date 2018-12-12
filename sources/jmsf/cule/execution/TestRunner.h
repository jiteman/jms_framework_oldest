#pragma once


#include "jmsf/pointing/Pointer.hpp"

#include "jmsf/pointing/Constant_pointer.hxx"


namespace jmsf {
namespace cule {

	class Test;

	namespace user_interfaces {
		class UiOutput;
	}

	namespace results {
		class TestResult;
	}

namespace execution {	


class TestRunner {

public:
	virtual ~TestRunner();
	TestRunner( const pointing::Pointer< user_interfaces::UiOutput > &uiOutput );

	void run();

private:
	void print( const pointing::Constant_pointer< results::TestResult > &testResult );

	TestRunner( const TestRunner & ) {}
	const TestRunner &operator=( const TestRunner & ) { return *this; }

private:
	pointing::Pointer< user_interfaces::UiOutput > _uiOutput;

};


} // namespace
}
}
