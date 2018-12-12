#pragma once

////#include "jmsf/types.h"
////#include "jmsf/Pointers.hpp"

#include "jmsf/pointing/Pointer.hpp"
#include "jmsf/typing/Naturals.hxx"

#include "jmsf/pointing/Constant_pointer.hxx"


namespace jmsf {
namespace cule {

	class TestFailure;

	namespace user_interfaces {
		class UiOutput;
	}

namespace printers {


class TestFailurePrinter {

public:
	virtual ~TestFailurePrinter();
	TestFailurePrinter( const pointing::Pointer< user_interfaces::UiOutput > &uiOutput );

	void print( typing::Natural number, const pointing::Constant_pointer< TestFailure > &testFailure );

private:
	TestFailurePrinter( const TestFailurePrinter & ) {}
	const TestFailurePrinter &operator=( const TestFailurePrinter & ) { return *this; }

private:
	pointing::Pointer< user_interfaces::UiOutput > _uiOutput;	
};


} // namespace
}
}
