#pragma once


#include "UiOutput.h"

#include "jmsf/typing/Ansii_string.hxx"


namespace jmsf {
namespace cule {
namespace user_interfaces {


class TextOutputUi : public UiOutput {

public:
	// virtual
	~TextOutputUi();
	TextOutputUi();

protected:
	// virtuals
	void print( const typing::Ansii_string &string );
	//~virtuals

private:
	TextOutputUi( const TextOutputUi & ) {}
	const TextOutputUi &operator=( const TextOutputUi & ) { return *this; }

};


} // namespace
}
}
