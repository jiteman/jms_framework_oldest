#include "ed_ServiceFile.h"
#include "ed_Key.h"
#include "../others/abstractFileDescriptor.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/PointersAndProxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {

class null_ed_ServiceFile :
	public ed_ServiceFile,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ed_ServiceFile >
{

public:
	// virtuals ed_ServiceFile
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

	void updateAppliedData( const ::jmsf::Pointer< AppliedData > & ) throw() {} // appliedData

	const ::jmsf::Boolean isSuccessfullyProcessed() const throw() {
		return ::jmsf::False;
	}

	const ::jmsf::Boolean isNotSuccessfullyProcessed() const throw() {
		return ::jmsf::True;
	}

	void markAsSuccessfullyProcessed() throw() {}

	void updateKey( const ::jmsf::ConstantProxy< ed_Key > & ) throw() {} // key

	const ::jmsf::ConstantProxy< ed_Key > &getKey() const throw() {
		return _keyReferenceToReturn;
	}

	const ::jmsf::Boolean isEarly( const ::jmsf::ConstantProxy< ed_ServiceFile > & ) const throw() { // other
		return ::jmsf::False;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ed_ServiceFile() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ed_ServiceFile >;
	static null_ed_ServiceFile *createInstance() throw() {
		return new null_ed_ServiceFile;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ed_ServiceFile() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_ServiceFile > createClone() const throw() {
		return ::jmsf::Proxy< ed_ServiceFile >::createUnique( this );
	}

private:
	null_ed_ServiceFile( const null_ed_ServiceFile & ) throw() {} // other
	
	const null_ed_ServiceFile &operator =( const null_ed_ServiceFile &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ed_ServiceFile::operator =()" );
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


class exception_ed_ServiceFile :
	public ed_ServiceFile,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ed_ServiceFile > {

public:
	// virtuals ed_ServiceFile
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

	void updateAppliedData( const ::jmsf::Pointer< AppliedData > & ) throw() {} // appliedData

	const ::jmsf::Boolean isSuccessfullyProcessed() const throw() {
		return ::jmsf::False;
	}

	const ::jmsf::Boolean isNotSuccessfullyProcessed() const throw() {
		return ::jmsf::True;
	}

	void markAsSuccessfullyProcessed() throw() {}

	void updateKey( const ::jmsf::ConstantProxy< ed_Key > & ) throw() {} // key

	const ::jmsf::ConstantProxy< ed_Key > &getKey() const throw() {
		return _keyReferenceToReturn;
	}

	const ::jmsf::Boolean isEarly( const ::jmsf::ConstantProxy< ed_ServiceFile > & ) const throw() { // other
		return ::jmsf::False;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ed_ServiceFile() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ed_ServiceFile >;
	static exception_ed_ServiceFile *createInstance() throw() {
		return new exception_ed_ServiceFile;
	}

private:
	exception_ed_ServiceFile() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_ServiceFile > createClone() const throw() {
		return ::jmsf::Proxy< ed_ServiceFile >::createUnique( this );
	}

private:
	exception_ed_ServiceFile( const exception_ed_ServiceFile & ) throw() {} // other

	const exception_ed_ServiceFile &operator =( const exception_ed_ServiceFile &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ed_ServiceFile::operator =()" );
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
ed_ServiceFile *ed_ServiceFile::getNull() throw() {
	return null_ed_ServiceFile::instance();
}

// static
ed_ServiceFile *ed_ServiceFile::getException() throw() {
	return exception_ed_ServiceFile::instance();
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
