#include "realization_ed_ServiceFile.h"
#include "../../others/abstractFileDescriptor.h"
#include "../ed_Key.h"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace realizations {

::jmsf::Pointer< FileDescriptorData > &realization_ed_ServiceFile::takeData() throw() {
	return _serviceFileData;
}

::jmsf::Pointer< AppliedData > &realization_ed_ServiceFile::takeAppliedData() throw() {
	return _serviceFileAppliedData;
}

const ::jmsf::ConstantPointer< FileDescriptorData > &realization_ed_ServiceFile::getData() const throw() {
	return _constantServiceFileData;
}

const ::jmsf::ConstantPointer< AppliedData > &realization_ed_ServiceFile::getAppliedData() const throw() {
	return _constantServiceFileAppliedData;
}

void realization_ed_ServiceFile::updateAppliedData( const ::jmsf::Pointer< AppliedData > &appliedData ) throw() {
	_serviceFileAppliedData = appliedData;
	_constantServiceFileAppliedData = _serviceFileAppliedData.getWeakConstant();
}

const ::jmsf::Boolean realization_ed_ServiceFile::isSuccessfullyProcessed() const throw() {
	return _wasSuccefullyProcessed;
}

const ::jmsf::Boolean realization_ed_ServiceFile::isNotSuccessfullyProcessed() const throw() {
	return _wasSuccefullyProcessed.not();
}

void realization_ed_ServiceFile::markAsSuccessfullyProcessed() throw() {
	_wasSuccefullyProcessed = ::jmsf::True;
}

void realization_ed_ServiceFile::updateKey( const ::jmsf::ConstantProxy< ed_Key > &key ) throw() {
	_key = key;
}

const ::jmsf::ConstantProxy< ed_Key > &realization_ed_ServiceFile::getKey() const throw() {
	return _key;
}

const ::jmsf::Boolean realization_ed_ServiceFile::isEarly( const ::jmsf::ConstantProxy< ed_ServiceFile > &other ) const throw() {
	return ::compareFileDescriptorTime( _serviceFileData.getWeakConstant().get(), other->getData().get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ed_ServiceFile::~realization_ed_ServiceFile() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ed_ServiceFile::realization_ed_ServiceFile(
	::jmsf::Pointer< FileDescriptorData > serviceFileData ) throw()
	:
		_serviceFileData( serviceFileData )
{
	_constantServiceFileData = _serviceFileData.getWeakConstant();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_ServiceFile > realization_ed_ServiceFile::createClone() const throw() {
	return ::jmsf::Proxy< ed_ServiceFile >::createUnique( new realization_ed_ServiceFile( *this ) );
}

realization_ed_ServiceFile::realization_ed_ServiceFile( const realization_ed_ServiceFile & ) throw( ::jmsf::Exception ) { // other
	::jmsf::Should::neverViolateCopyingProhibition( "realization_ed_ServiceFile::realization_ed_ServiceFile()" );
}

const realization_ed_ServiceFile &realization_ed_ServiceFile::operator =( const realization_ed_ServiceFile &other ) throw( ::jmsf::Exception ) {
	if ( this == &other ) return *this;

	::jmsf::Should::neverViolateCopyingProhibition( "realization_ed_ServiceFile::opreator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
}
}
