#include "TestFailure.h"


#include "jmsf/typing/Naturals.inl"


namespace jmsf {
namespace cule {


TestFailure::~TestFailure() {
}

TestFailure::TestFailure(
	const typing::Ansii_string &fileName,
	const typing::Ansii_string &testName,
	const typing::Natural testLineNumber,
	const typing::Ansii_string &reason,
	const typing::Natural assertionLineNumber )
	:
		_fileName( fileName ),
		_testName( testName ),
		_testLineNumber( testLineNumber ),
		_reason( reason ),
		_assertionLineNumber( assertionLineNumber )
{}

const typing::Ansii_string &TestFailure::getName() const {
	return _testName;
}

const typing::Ansii_string &TestFailure::getFilename() const {
	return _fileName;
}

typing::Natural TestFailure::getLineNumber() const {
	return _testLineNumber;
}

const typing::Ansii_string &TestFailure::getReason() const {
	return _reason;
}

typing::Natural TestFailure::getAssertionLineNumber() const {
	return _assertionLineNumber;
}


} // namespace
}
