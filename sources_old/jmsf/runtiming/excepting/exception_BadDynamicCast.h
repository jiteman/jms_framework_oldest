#pragma once


#include "jmsf/validating/mixing/mixin_Exception.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace runtiming {
namespace exceptions {


class JMSF_DLL_INTERFACE exception_BadDynamicCast :
	public validating::mixins::mixin_Exception
{

public:
	// virtuals	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~exception_BadDynamicCast() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_BadDynamicCast( const pointing::ConstantProxy< texting::TextString > &reason, const validating::FileAndLine &fileAndLine ) throw();
	exception_BadDynamicCast( const pointing::Proxy< texting::TextStream > &reason, const validating::FileAndLine &fileAndLine ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_BadDynamicCast( const exception_BadDynamicCast &other ) throw();
	const exception_BadDynamicCast &operator =( const exception_BadDynamicCast &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace exceptions
} // namespace runtiming
} // namespace jmsf
