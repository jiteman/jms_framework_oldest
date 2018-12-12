#include "TestFailurePrinter.h"

#include "../user_interfaces/UiOutput.h"
#include "../TestFailure.h"

#include "jmsf/pointing/Pointer.inl"
#include "jmsf/pointing/Constant_pointer.inl"
#include "jmsf/typing/Naturals.inl"

#include "jmsf/validating/Should.h"


namespace jmsf {
namespace cule {
namespace printers {


TestFailurePrinter::~TestFailurePrinter() {
}

TestFailurePrinter::TestFailurePrinter( const pointing::Pointer< user_interfaces::UiOutput > &uiOutput )
	:
		_uiOutput( uiOutput )
{}

void TestFailurePrinter::print( const typing::Natural number, const pointing::Constant_pointer< TestFailure > &testFailure ) {
	validating::Should::never_be( testFailure.is_empty(), FILE_AND_LINE );
	_uiOutput->printTestFailure( number, testFailure->getFilename(), testFailure->getAssertionLineNumber(), testFailure->getReason() );
}


} // namespace
}
}
