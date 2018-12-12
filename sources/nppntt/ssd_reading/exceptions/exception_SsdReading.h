#pragma once

#include "jmsf/mixins/mixin_Exception.h"

namespace nppntt {
namespace ssd_reading {
namespace exceptions {

class exception_SsdReading :
	public ::jmsf::mixins::mixin_Exception
{

public:
	// virtuals	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~exception_SsdReading() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	exception_SsdReading( const ::jmsf::ConstantProxy< ::jmsf::TextString > &reason ) throw();
	exception_SsdReading( const ::jmsf::Proxy< ::jmsf::TextStream > &reason ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	exception_SsdReading( const exception_SsdReading &other ) throw();
	const exception_SsdReading &operator =( const exception_SsdReading &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
}
