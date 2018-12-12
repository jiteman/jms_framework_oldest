#pragma once

////#include "jmsf/Pointers.hpp"
////#include "jmsf/types.h"

#include "jmsf/pointing/Pointer.hpp"
#include "jmsf/pointing/Constant_pointer.hpp"

#include "jmsf/typing/Ansii_string.hxx"

#include "../user_interfaces/UiOutput.hxx"
#include "../results/TestResult.hxx"
#include "../TestFailure.hxx"

#include "jmsf/typing/internals/internal_types.h"

#include "jmsf/stdal/stdal_stl.h"
////#include "jmsf/TextString.hxx"
////#include "jmsf/PointersAndProxies.hxx"


namespace jmsf {
namespace cule {
namespace printers {


class TestResultPrinter {

public:
	virtual ~TestResultPrinter();
	TestResultPrinter( const pointing::Pointer< user_interfaces::UiOutput > &UiOutput, const pointing::Constant_pointer< results::TestResult > &testResult );

	void print();

private:
	void printTestFailures( const std::vector< const pointing::Constant_pointer< TestFailure > > &vector, const typing::Ansii_string &name );
	//TestResultPrinter( const TestResultPrinter &ohter ) {}
	const TestResultPrinter &operator=( const TestResultPrinter & ) { return *this; }

private:
	pointing::Pointer< user_interfaces::UiOutput > _uiOutput;
	const pointing::Constant_pointer< results::TestResult > _testResult;

private:
	static const typing::internals::platform_character_type *UNKNOWN_ERROR_NAME;
	static const typing::internals::platform_character_type *ERROR_NAME;
	static const typing::internals::platform_character_type *FAILURE_NAME;

};


} // namespace
}
}
