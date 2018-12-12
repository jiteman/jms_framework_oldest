#pragma once

#include "jmsf/mixins/mixin_Exception.h"

#include "jmsf/types.h"

#include "../../jmsf.h"

namespace jmsf {
namespace osie {
namespace exceptions {


class JMSF_DLL_INTERFACE exception_FileException :
	public mixins::mixin_Exception
{

	static const char_type *const UNKNOWN_FILE_EXCEPTION;

public:
	// virtual
	~exception_FileException() throw();
	exception_FileException() throw();
	exception_FileException( const ConstantProxy< TextString > &message ) throw();
	exception_FileException( const Proxy< TextStream > &message ) throw();

private:
// 	FileException( const FileException & ) throw() {}
// 	const FileException &operator =( const FileException & ) throw() { return *this; }

};


} // namespace
}
}
