#include "ed_StoredFiles.h"
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

class null_ed_StoredFiles :
	public ed_StoredFiles,
	public ::jmsf::mtf::mixins::mixin_null_Lockable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ed_StoredFiles >
{

public:
	// virtuals ed_StoredFiles
	::jmsf::Pointer< DataBaseStatisticsData > &takeData() throw( ::jmsf::Exception ) {
		return _databaseStatisticsData;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ed_StoredFiles() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ed_StoredFiles >;
	static null_ed_StoredFiles *createInstance() throw() {
		return new null_ed_StoredFiles;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ed_StoredFiles() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_StoredFiles > createClone() const throw() {
		return ::jmsf::Proxy< ed_StoredFiles >::createUnique( this );
	}

private:
	null_ed_StoredFiles( const null_ed_StoredFiles & ) throw() {} // other
	
	const null_ed_StoredFiles &operator =( const null_ed_StoredFiles &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ed_StoredFiles::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< DataBaseStatisticsData > _databaseStatisticsData;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_ed_StoredFiles :
	public ed_StoredFiles,
	public ::jmsf::mtf::mixins::mixin_null_Lockable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ed_StoredFiles > {

public:
	// virtuals ed_StoredFiles
	::jmsf::Pointer< DataBaseStatisticsData > &takeData() throw( ::jmsf::Exception ) {
		return _databaseStatisticsData;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ed_StoredFiles() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ed_StoredFiles >;
	static exception_ed_StoredFiles *createInstance() throw() {
		return new exception_ed_StoredFiles;
	}

private:
	exception_ed_StoredFiles() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_StoredFiles > createClone() const throw() {
		return ::jmsf::Proxy< ed_StoredFiles >::createUnique( this );
	}

private:
	exception_ed_StoredFiles( const exception_ed_StoredFiles & ) throw() {} // other

	const exception_ed_StoredFiles &operator =( const exception_ed_StoredFiles &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ed_StoredFiles::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< DataBaseStatisticsData > _databaseStatisticsData;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
ed_StoredFiles *ed_StoredFiles::getNull() throw() {
	return null_ed_StoredFiles::instance();
}

// static
ed_StoredFiles *ed_StoredFiles::getException() throw() {
	return exception_ed_StoredFiles::instance();
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
