#include "ed_VoiceFile.h"
#include "../others/abstractFileDescriptor.h"
#include "ed_Key.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/PointersAndProxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {

class null_ed_VoiceFile :
	public ed_VoiceFile,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ed_VoiceFile >
{

public:
	// virtuals ed_VoiceFile
	::jmsf::Pointer< FileDescriptorData > &takeData() throw() {
		return _fileDescriptorDataReferenceToReturn;
	}

	::jmsf::Pointer< AppliedData > &takeAppliedData() throw() {
		return _appliedDataReferenceToReturn;
	}

	const ::jmsf::ConstantPointer< FileDescriptorData > &getData() const throw() {
		return _fileDescriptorDataConstantReferenceToReturn;
	}

	const ::jmsf::ConstantPointer< AppliedData > &getAppliedData() const throw() {
		return _appliedDataConstantReferenceToReturn;
	}

	const ::jmsf::Boolean isServiceFileSuitable( const ::jmsf::ConstantProxy< ed_ServiceFile > & ) const throw() { // serviceFile
		return ::jmsf::False;
	}

	const ::jmsf::ConstantProxy< ed_Key > &getLastAppliedKey() const throw() {
		return _keyReferenceToReturn;
	}

	void updateLastAppliedKey( const ::jmsf::ConstantProxy< ed_Key > & ) throw() {} // key
	void updateAppliedData( const ::jmsf::Pointer< AppliedData > & ) throw() {} // appliedData

	const ::jmsf::Boolean isDeletedFromDecipher() const throw() {
		return ::jmsf::False;
	}

	void markAsDeletedFromDecipher() throw() {}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ed_VoiceFile() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ed_VoiceFile >;
	static null_ed_VoiceFile *createInstance() throw() {
		return new null_ed_VoiceFile;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ed_VoiceFile() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_VoiceFile > createClone() const throw() {
		return ::jmsf::Proxy< ed_VoiceFile >::createUnique( this );
	}

private:
	null_ed_VoiceFile( const null_ed_VoiceFile & ) throw() {} // other
	
	const null_ed_VoiceFile &operator =( const null_ed_VoiceFile &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ed_VoiceFile::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< FileDescriptorData > _fileDescriptorDataReferenceToReturn;
	::jmsf::ConstantPointer< FileDescriptorData > _fileDescriptorDataConstantReferenceToReturn;
	::jmsf::Pointer< AppliedData > _appliedDataReferenceToReturn;
	::jmsf::ConstantPointer< AppliedData > _appliedDataConstantReferenceToReturn;
	::jmsf::ConstantProxy< ed_Key > _keyReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_ed_VoiceFile :
	public ed_VoiceFile,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ed_VoiceFile > {

public:
	// virtuals ed_VoiceFile
	::jmsf::Pointer< FileDescriptorData > &takeData() throw() {
		return _fileDescriptorDataReferenceToReturn;
	}

	::jmsf::Pointer< AppliedData > &takeAppliedData() throw() {
		return _appliedDataReferenceToReturn;
	}

	const ::jmsf::ConstantPointer< FileDescriptorData > &getData() const throw() {
		return _fileDescriptorDataConstantReferenceToReturn;
	}

	const ::jmsf::ConstantPointer< AppliedData > &getAppliedData() const throw() {
		return _appliedDataConstantReferenceToReturn;
	}

	const ::jmsf::Boolean isServiceFileSuitable( const ::jmsf::ConstantProxy< ed_ServiceFile > & ) const throw() { // serviceFile
		return ::jmsf::False;
	}

	const ::jmsf::ConstantProxy< ed_Key > &getLastAppliedKey() const throw() {
		return _keyReferenceToReturn;
	}

	void updateLastAppliedKey( const ::jmsf::ConstantProxy< ed_Key > & ) throw() {} // key
	void updateAppliedData( const ::jmsf::Pointer< AppliedData > & ) throw() {} // appliedData

	const ::jmsf::Boolean isDeletedFromDecipher() const throw() {
		return ::jmsf::False;
	}

	void markAsDeletedFromDecipher() throw() {}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ed_VoiceFile() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ed_VoiceFile >;
	static exception_ed_VoiceFile *createInstance() throw() {
		return new exception_ed_VoiceFile;
	}

private:
	exception_ed_VoiceFile() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_VoiceFile > createClone() const throw() {
		return ::jmsf::Proxy< ed_VoiceFile >::createUnique( this );
	}

private:
	exception_ed_VoiceFile( const exception_ed_VoiceFile & ) throw() {} // other

	const exception_ed_VoiceFile &operator =( const exception_ed_VoiceFile &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ed_VoiceFile::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< FileDescriptorData > _fileDescriptorDataReferenceToReturn;
	::jmsf::ConstantPointer< FileDescriptorData > _fileDescriptorDataConstantReferenceToReturn;
	::jmsf::Pointer< AppliedData > _appliedDataReferenceToReturn;
	::jmsf::ConstantPointer< AppliedData > _appliedDataConstantReferenceToReturn;
	::jmsf::ConstantProxy< ed_Key > _keyReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
ed_VoiceFile *ed_VoiceFile::getNull() throw() {
	return null_ed_VoiceFile::instance();
}

// static
ed_VoiceFile *ed_VoiceFile::getException() throw() {
	return exception_ed_VoiceFile::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace data
} // namespace externals
} // namespace mdm
} // namespace nppntt
