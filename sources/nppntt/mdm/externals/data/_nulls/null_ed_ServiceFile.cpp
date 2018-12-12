#include "null_ed_ServiceFile.h"
#include "../../others/abstractFileDescriptor.h"
#include "../ed_Key.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace nulls {


::jmsf::Pointer< FileDescriptorData > null_ed_ServiceFile::getOneselfData() throw() {
	return ::jmsf::Pointer< FileDescriptorData >();
}

::jmsf::Pointer< AppliedData > null_ed_ServiceFile::getOneselfAppliedData() throw() {
	return ::jmsf::Pointer< AppliedData >();
}

const ::jmsf::ConstantPointer< FileDescriptorData > null_ed_ServiceFile::getData() const throw() {
	return ::jmsf::ConstantPointer< FileDescriptorData >();
}

const ::jmsf::ConstantPointer< AppliedData > null_ed_ServiceFile::getAppliedData() const throw() {
	return ::jmsf::ConstantPointer< AppliedData >();
}

void null_ed_ServiceFile::updateAppliedData( ::jmsf::Pointer< AppliedData >  ) throw()
{}

::jmsf::Boolean null_ed_ServiceFile::isSuccessfullyProcessed() const throw() {
	return ::jmsf::False;
}

::jmsf::Boolean null_ed_ServiceFile::isNotSuccessfullyProcessed() const throw() {
	return ::jmsf::True;
}

void null_ed_ServiceFile::markAsSuccessfullyProcessed() throw()
{}

void null_ed_ServiceFile::updateKey( const ::jmsf::ConstantProxy< ed_Key > & ) throw() // key
{}

const ::jmsf::ConstantProxy< ed_Key > null_ed_ServiceFile::getKey() const throw() {
	return ::jmsf::ConstantProxy< ed_Key >();
}

::jmsf::Boolean null_ed_ServiceFile::isEarly( const ::jmsf::ConstantProxy< ed_ServiceFile > & ) const throw() { // other
	return ::jmsf::False;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ed_ServiceFile::~null_ed_ServiceFile() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ed_ServiceFile *null_ed_ServiceFile::createInstance() throw() {
	return new null_ed_ServiceFile;
}

null_ed_ServiceFile::null_ed_ServiceFile() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_ServiceFile > null_ed_ServiceFile::createClone() const throw() {
	return ::jmsf::Proxy< ed_ServiceFile >::createUnique( this );
}

null_ed_ServiceFile::null_ed_ServiceFile( const null_ed_ServiceFile & ) throw() // other
{}

const null_ed_ServiceFile &null_ed_ServiceFile::operator =( const null_ed_ServiceFile &other ) throw() {
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
}
