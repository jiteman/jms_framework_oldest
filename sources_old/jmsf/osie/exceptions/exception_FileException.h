#pragma once


#include "jmsf/validating/mixing/mixin_Exception.h"

#include "jmsf/typing/internals/internal_types.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {
namespace exceptions {


class JMSF_DLL_INTERFACE exception_FileException :
	public validating::mixing::mixin_Exception
{

	static const typing::internals::platform_char *const UNKNOWN_FILE_EXCEPTION;

public:
	// virtual
	~exception_FileException() throw();
	exception_FileException( const validating::FileAndLine &fileAndLine ) throw();
	exception_FileException( const pointing::ConstantProxy< texting::TextString > &message, const validating::FileAndLine &fileAndLine ) throw();
	exception_FileException( const pointing::Proxy< texting::TextStream > &message, const validating::FileAndLine &fileAndLine ) throw();

private:
// 	FileException( const FileException & ) throw() {}
// 	const FileException &operator =( const FileException & ) throw() { return *this; }

};


} // namespace
}
}
