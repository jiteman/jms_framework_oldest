#include "null_NewFileAppenders.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace nulls {




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_NewFileAppenders::~null_NewFileAppenders() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_NewFileAppenders *null_NewFileAppenders::createInstance() throw() {
	return new null_NewFileAppenders;
}

null_NewFileAppenders::null_NewFileAppenders() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< NewFileAppenders > null_NewFileAppenders::createClone() const throw() {
	return ::jmsf::Proxy< NewFileAppenders >::createUnique( this );
}

null_NewFileAppenders::null_NewFileAppenders( const null_NewFileAppenders & ) throw() // other
{}

const null_NewFileAppenders &null_NewFileAppenders::operator =( const null_NewFileAppenders &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
}
