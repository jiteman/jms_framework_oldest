#pragma once

////#include "jmsf/TextString.hxx"
////#include "jmsf/Proxies.hxx"

////#include "jmsf/types.h"

#include "jmsf/typing/Ansii_string.hxx"
#include "jmsf/typing/internals/internal_types.h"

#include "jmsf/typing/Naturals.hxx"


namespace jmsf {
namespace cule {
namespace user_interfaces {


class UiOutput {

	static const typing::internals::platform_character_type *TEST_START_INDICATOR;
	static const typing::internals::platform_character_type *FAILURE_INDICATOR;
	static const typing::internals::platform_character_type *ERROR_INDICATOR;
	static const typing::internals::platform_character_type *UNKNOWN_ERROR_INDICATOR;
	static const typing::internals::platform_character_type *BLANK_LINE;

public:
	virtual ~UiOutput() = 0 {};

	void indicateTestingStarted();

	void indicateTestStart();
	void indicateFailure();
	void indicateError();
	void indicateUnknownError();

	void printBlankLine();
	void printTestFailureCaption( typing::Natural quantity, const typing::Ansii_string &name );	
	void printTestFailure( typing::Natural number, const typing::Ansii_string &fileName, typing::Natural lineNumber, const typing::Ansii_string &message );
	void printNoErrors(); 
	void printTotalTestingDuration( typing::Natural number, typing::Natural duration );

protected:
	virtual void print( const typing::Ansii_string &string ) = 0;

};


} // namespace
}
}
