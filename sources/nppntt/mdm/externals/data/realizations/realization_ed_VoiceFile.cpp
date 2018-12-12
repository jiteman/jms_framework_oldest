#include "realization_ed_VoiceFile.h"
#include "../../others/abstractCheckMatchVoiceSms.h"
#include "../../others/abstractFileDescriptor.h"
#include "../ed_ServiceFile.h"
#include "../ed_Key.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace realizations {


::jmsf::Pointer< FileDescriptorData > &realization_ed_VoiceFile::takeData() throw() {
	return _voiceFileData;
}

::jmsf::Pointer< AppliedData > &realization_ed_VoiceFile::takeAppliedData() throw() {
	return _voiceFileAppliedData;
}

const ::jmsf::ConstantPointer< FileDescriptorData > &realization_ed_VoiceFile::getData() const throw() {
	return _constantVoiceFileData;
}

const ::jmsf::ConstantPointer< AppliedData > &realization_ed_VoiceFile::getAppliedData() const throw() {
	return _constantVoiceFileAppliedData;
}

const ::jmsf::Boolean realization_ed_VoiceFile::isServiceFileSuitable( const ::jmsf::ConstantProxy< ed_ServiceFile > &serviceFile ) const throw() {
	return ::isServiceFileWithinTimeRangeOfVoiceFile( *_voiceFileData.getWeakConstant(), *serviceFile->getData() );
}

const ::jmsf::ConstantProxy< ed_Key > &realization_ed_VoiceFile::getLastAppliedKey() const throw() {
	return _lastAppliedKey;
}

void realization_ed_VoiceFile::updateLastAppliedKey( const ::jmsf::ConstantProxy< ed_Key > &key ) throw() {
	_lastAppliedKey = key;
}

void realization_ed_VoiceFile::updateAppliedData( const ::jmsf::Pointer< AppliedData > &appliedData ) throw() {
	_voiceFileAppliedData = appliedData;
	_constantVoiceFileAppliedData = _voiceFileAppliedData.getWeakConstant();
}

const ::jmsf::Boolean realization_ed_VoiceFile::isDeletedFromDecipher() const throw() {
	return _isDeletedFromDecipher;
}

void realization_ed_VoiceFile::markAsDeletedFromDecipher() throw() {
	_isDeletedFromDecipher = ::jmsf::True;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ed_VoiceFile::~realization_ed_VoiceFile() throw() {
	// must be done: call FileDescriptorData deleter
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ed_VoiceFile::realization_ed_VoiceFile(
	::jmsf::Pointer< FileDescriptorData > voiceFileData ) throw()
	:
		_voiceFileData( voiceFileData )
{
	_constantVoiceFileData = _voiceFileData.getWeakConstant();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_VoiceFile > realization_ed_VoiceFile::createClone() const throw() {
	return ::jmsf::Proxy< ed_VoiceFile >::createUnique( new realization_ed_VoiceFile( *this ) );
}

realization_ed_VoiceFile::realization_ed_VoiceFile( const realization_ed_VoiceFile & ) throw( ::jmsf::Exception ) { // other
	::jmsf::Should::neverViolateCopyingProhibition( "realization_ed_VoiceFile::realization_ed_VoiceFile()" );
}

const realization_ed_VoiceFile &realization_ed_VoiceFile::operator =( const realization_ed_VoiceFile &other ) throw( ::jmsf::Exception ) {
	if ( this == &other ) return *this;

	::jmsf::Should::neverViolateCopyingProhibition( "realization_ed_VoiceFile::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
}
}
