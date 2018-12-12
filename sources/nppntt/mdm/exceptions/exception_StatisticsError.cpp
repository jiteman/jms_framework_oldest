#include "exception_StatisticsError.h"
#include "jmsf/TextStream.h"


namespace nppntt {
namespace mdm {
namespace exceptions {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
exception_StatisticsError::~exception_StatisticsError() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_StatisticsError::exception_StatisticsError( const ::jmsf::ConstantProxy< ::jmsf::TextString > &reason ) throw()
    : mixin_Exception( reason )
{}

exception_StatisticsError::exception_StatisticsError( const ::jmsf::Proxy< ::jmsf::TextStream > &reason ) throw()
    : mixin_Exception( reason )
{}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
exception_StatisticsError::exception_StatisticsError( const exception_StatisticsError &other ) throw()
    : mixin_Exception( other )
{}

const exception_StatisticsError &exception_StatisticsError::operator =( const exception_StatisticsError &other ) throw() {
    if ( this == &other ) return *this;

    mixin_Exception::operator =( other );

    return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
