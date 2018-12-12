#include "ed_DeletedFiles.h"
#include "../../others/abstractStatistics.h"
#include "jmsf/mtf/mixins/mixin_null_Lockable.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/PointersAndProxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {

class null_ed_DeletedFiles :
	public ed_DeletedFiles,
	public ::jmsf::mtf::mixins::mixin_null_Lockable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ed_DeletedFiles >
{

public:
	// virtuals ed_DeletedFiles
	::jmsf::Pointer< DeleteFilesStatisticsData > &takeData() throw( ::jmsf::Exception ) {
		return _deleteFilesStatisticsDataReferenceToReturn;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ed_DeletedFiles() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ed_DeletedFiles >;
	static null_ed_DeletedFiles *createInstance() throw() {
		return new null_ed_DeletedFiles;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ed_DeletedFiles() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_DeletedFiles > createClone() const throw() {
		return ::jmsf::Proxy< ed_DeletedFiles >::createUnique( this );
	}

private:
	null_ed_DeletedFiles( const null_ed_DeletedFiles & ) throw() {} // other
	
	const null_ed_DeletedFiles &operator =( const null_ed_DeletedFiles &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ed_DeletedFiles::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< DeleteFilesStatisticsData > _deleteFilesStatisticsDataReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_ed_DeletedFiles :
	public ed_DeletedFiles,
	public ::jmsf::mtf::mixins::mixin_null_Lockable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ed_DeletedFiles > {

public:
	// virtuals ed_DeletedFiles
	::jmsf::Pointer< DeleteFilesStatisticsData > &takeData() throw( ::jmsf::Exception ) {
		return _deleteFilesStatisticsDataReferenceToReturn;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ed_DeletedFiles() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ed_DeletedFiles >;
	static exception_ed_DeletedFiles *createInstance() throw() {
		return new exception_ed_DeletedFiles;
	}

private:
	exception_ed_DeletedFiles() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_DeletedFiles > createClone() const throw() {
		return ::jmsf::Proxy< ed_DeletedFiles >::createUnique( this );
	}

private:
	exception_ed_DeletedFiles( const exception_ed_DeletedFiles & ) throw() {} // other

	const exception_ed_DeletedFiles &operator =( const exception_ed_DeletedFiles &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ed_DeletedFiles::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< DeleteFilesStatisticsData > _deleteFilesStatisticsDataReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
ed_DeletedFiles *ed_DeletedFiles::getNull() throw() {
	return null_ed_DeletedFiles::instance();
}

// static
ed_DeletedFiles *ed_DeletedFiles::getException() throw() {
	return exception_ed_DeletedFiles::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace statistics
} // namespace data
} // namespace externals
} // namespace mdm
} // namespace nppntt
