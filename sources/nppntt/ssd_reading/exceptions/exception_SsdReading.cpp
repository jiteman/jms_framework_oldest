#include "exception_SsdReading.h"
#include "jmsf/TextStream.h"

namespace nppntt {
namespace ssd_reading {
namespace exceptions {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_SsdReading::~exception_SsdReading() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_SsdReading::exception_SsdReading( const ::jmsf::ConstantProxy< ::jmsf::TextString > &reason ) throw()
	: mixin_Exception( reason )
{}

exception_SsdReading::exception_SsdReading( const ::jmsf::Proxy< ::jmsf::TextStream > &reason ) throw()
	: mixin_Exception( reason )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_SsdReading::exception_SsdReading( const exception_SsdReading &other ) throw()
	: mixin_Exception( other )
{}

const exception_SsdReading &exception_SsdReading::operator =( const exception_SsdReading &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
