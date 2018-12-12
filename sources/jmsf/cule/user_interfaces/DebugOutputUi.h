#pragma once


#include "UiOutput.h"

#include "jmsf/typing/Ansii_string.hxx"


namespace jmsf {
namespace cule {
namespace user_interfaces {


class DebugOutputUi :
	public UiOutput
{

public:
	// virtual
	~DebugOutputUi();
	DebugOutputUi();

protected:
	// virtuals
	void print( const typing::Ansii_string &string );
	//~virtuals

private:
	DebugOutputUi( const DebugOutputUi & ) {}
	const DebugOutputUi &operator =( const DebugOutputUi & ) { return *this; }

};


} // namespace
}
}
