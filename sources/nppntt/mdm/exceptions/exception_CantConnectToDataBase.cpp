#include "exception_CantConnectToDataBase.h"

#include "jmsf/TextStream.h"


namespace nppntt {
namespace mdm {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_CantConnectToDataBase::~exception_CantConnectToDataBase() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_CantConnectToDataBase::exception_CantConnectToDataBase( const ::jmsf::ConstantProxy< ::jmsf::TextString > &reason ) throw()
	: mixin_Exception( reason )
{}

exception_CantConnectToDataBase::exception_CantConnectToDataBase( const ::jmsf::Proxy< ::jmsf::TextStream > &reason ) throw()
	: mixin_Exception( reason )
{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_CantConnectToDataBase::exception_CantConnectToDataBase( const exception_CantConnectToDataBase &other ) throw()
	: mixin_Exception( other )
{}

const exception_CantConnectToDataBase &exception_CantConnectToDataBase::operator =( const exception_CantConnectToDataBase &other ) throw() {
	if ( this == &other ) return *this;

	mixin_Exception::operator =( other );

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
