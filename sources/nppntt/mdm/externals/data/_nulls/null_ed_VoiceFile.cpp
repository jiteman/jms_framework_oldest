#include "null_ed_VoiceFile.h"
#include "../../others/abstractFileDescriptor.h"
#include "../ed_Key.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace nulls {


::jmsf::Pointer< FileDescriptorData > null_ed_VoiceFile::getOneselfData() throw() {
	return ::jmsf::Pointer< FileDescriptorData >();
}

::jmsf::Pointer< AppliedData > null_ed_VoiceFile::getOneselfAppliedData() throw() {
	return ::jmsf::Pointer< AppliedData >();
}

const ::jmsf::ConstantPointer< FileDescriptorData > null_ed_VoiceFile::getData() const throw() {
	return ::jmsf::ConstantPointer< FileDescriptorData >();
}

const ::jmsf::ConstantPointer< AppliedData > null_ed_VoiceFile::getAppliedData() const throw() {
	return ::jmsf::ConstantPointer< AppliedData >();
}

::jmsf::Boolean null_ed_VoiceFile::isServiceFileSuitable( const ::jmsf::ConstantProxy< ed_ServiceFile > & ) const throw() { // serviceFile
	return ::jmsf::False;
}

const ::jmsf::ConstantProxy< ed_Key > null_ed_VoiceFile::getLastAppliedKey() const throw() {
	return ::jmsf::ConstantProxy< ed_Key >();
}

void null_ed_VoiceFile::updateLastAppliedKey( const ::jmsf::ConstantProxy< ed_Key > & ) throw()
{}

void null_ed_VoiceFile::updateAppliedData( ::jmsf::Pointer< AppliedData >  ) throw()
{}

::jmsf::Boolean null_ed_VoiceFile::isDeletedFromDecipher() const throw() {
	return ::jmsf::False;
}

void null_ed_VoiceFile::markAsDeletedFromDecipher() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_ed_VoiceFile::~null_ed_VoiceFile() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_ed_VoiceFile *null_ed_VoiceFile::createInstance() throw() {
	return new null_ed_VoiceFile;
}

null_ed_VoiceFile::null_ed_VoiceFile() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_VoiceFile > null_ed_VoiceFile::createClone() const throw() {
	return ::jmsf::Proxy< ed_VoiceFile >::createUnique( this );
}

null_ed_VoiceFile::null_ed_VoiceFile( const null_ed_VoiceFile & ) throw() // other
{}

const null_ed_VoiceFile &null_ed_VoiceFile::operator =( const null_ed_VoiceFile &other ) throw() {
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
