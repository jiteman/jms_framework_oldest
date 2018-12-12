#pragma once

#include "jmsf/mixins/mixin_Exception.h"


namespace nppntt {
namespace mdm {
namespace exceptions {


class exception_StatisticsError : public ::jmsf::mixins::mixin_Exception {

public:
    // virtuals	
    //~virtuals

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

    // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
    // virtual
    ~exception_StatisticsError() throw();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
    exception_StatisticsError( const ::jmsf::ConstantProxy< ::jmsf::TextString > &reason ) throw();
    exception_StatisticsError( const ::jmsf::Proxy< ::jmsf::TextStream > &reason ) throw();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
    exception_StatisticsError( const exception_StatisticsError &other ) throw();
    const exception_StatisticsError &operator =( const exception_StatisticsError &other ) throw();

    // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
    //	static const ::jmsf::char_type *MESSAGE_HEADER = "Dll not found: ";

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
