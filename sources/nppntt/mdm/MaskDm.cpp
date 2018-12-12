#include "MaskDm.h"
#include "externals/data/statistics/ed_Summary.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {

class null_MaskDm :
	public MaskDm,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_MaskDm >
{

public:
	// virtuals MaskDm
	::jmsf::Boolean wasInitializedCorrectly() const throw() {
		return ::jmsf::False;
	}

	void continueDecipchering() throw() {}
	void stopDecipchering() throw() {}

	void changeFileAppenderFolders( const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< ::jmsf::TextString > > > & ) throw() {} // pathToFolderWithFilesContainer

	void updateFileFilter( const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > & ) throw() {} // fileFilter
	void setDecipheringTimeLimit( const ::jmsf::ConstantPointer< _decipherTimeLimit > & ) throw() {} // timeLimitData

	const ::jmsf::ConstantProxy< externals::data::statistics::ed_Summary > &getStatistics() throw() {
		return _summaryReferenceToReturn;
	}

	void clearExpiredServiceFiles() throw() {}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_MaskDm() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_MaskDm >;
	static null_MaskDm *createInstance() throw() {
		return new null_MaskDm;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_MaskDm() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< MaskDm > createClone() const throw() {
		return ::jmsf::Proxy< MaskDm >::createUnique( this );
	}

private:
	null_MaskDm( const null_MaskDm & ) throw() {} // other
	
	const null_MaskDm &operator =( const null_MaskDm &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_MaskDm::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::ConstantProxy< externals::data::statistics::ed_Summary > _summaryReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_MaskDm :
	public MaskDm,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_MaskDm > {

public:
	// virtuals MaskDm
	::jmsf::Boolean wasInitializedCorrectly() const throw() {
		return ::jmsf::False;
	}

	void continueDecipchering() throw() {}
	void stopDecipchering() throw() {}

	void changeFileAppenderFolders( const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< ::jmsf::TextString > > > & ) throw() {} // pathToFolderWithFilesContainer

	void updateFileFilter( const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > & ) throw() {} // fileFilter
	void setDecipheringTimeLimit( const ::jmsf::ConstantPointer< _decipherTimeLimit > & ) throw() {} // timeLimitData

	const ::jmsf::ConstantProxy< externals::data::statistics::ed_Summary > &getStatistics() throw() {
		return _summaryReferenceToReturn;
	}

	void clearExpiredServiceFiles() throw() {}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_MaskDm() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_MaskDm >;
	static exception_MaskDm *createInstance() throw() {
		return new exception_MaskDm;
	}

private:
	exception_MaskDm() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< MaskDm > createClone() const throw() {
		return ::jmsf::Proxy< MaskDm >::createUnique( this );
	}

private:
	exception_MaskDm( const exception_MaskDm & ) throw() {} // other

	const exception_MaskDm &operator =( const exception_MaskDm &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_MaskDm::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::ConstantProxy< externals::data::statistics::ed_Summary > _summaryReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
MaskDm *MaskDm::getNull() throw() {
	return null_MaskDm::instance();
}

// static
MaskDm *MaskDm::getException() throw() {
	return exception_MaskDm::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace mdm
} // namespace nppntt
