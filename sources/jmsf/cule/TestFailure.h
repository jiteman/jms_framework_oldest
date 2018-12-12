#pragma once


////#include "jmsf/TextString.h"
////#include "jmsf/Proxies.hpp"

#include "jmsf/typing/Ansii_string.h"
#include "jmsf/typing/Naturals.hpp"


namespace jmsf {
namespace cule {


class TestFailure {

	const typing::Ansii_string _fileName;
	const typing::Ansii_string _testName;	
	const typing::Natural _testLineNumber;
	const typing::Natural _assertionLineNumber;
	const typing::Ansii_string _reason;

public:
	virtual ~TestFailure();

	TestFailure(
		const typing::Ansii_string &fileName,
		const typing::Ansii_string &testName,
		typing::Natural testLineNumber,
		const typing::Ansii_string &reason,
		typing::Natural assertionLineNumber );

	const typing::Ansii_string &getName() const;
	const typing::Ansii_string &getFilename() const;
	typing::Natural getLineNumber() const;
	const typing::Ansii_string &getReason() const;
	typing::Natural getAssertionLineNumber() const;

private:
	const TestFailure &operator=( const TestFailure & ) { return *this; }

};


} // namespace
}
