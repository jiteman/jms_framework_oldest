#include "ed_DecipheringFiles.h"
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

class null_ed_DecipheringFiles :
	public ed_DecipheringFiles,
	public ::jmsf::mtf::mixins::mixin_null_Lockable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ed_DecipheringFiles >
{

public:
	// virtuals ed_DecipheringFiles
	::jmsf::Pointer< DecipherStatisticsData > &takeData() throw( ::jmsf::Exception ) {
		return _decipherStatisticsDataReferenceToReturn;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ed_DecipheringFiles() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ed_DecipheringFiles >;
	static null_ed_DecipheringFiles *createInstance() throw() {
		return new null_ed_DecipheringFiles;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ed_DecipheringFiles() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_DecipheringFiles > createClone() const throw() {
		return ::jmsf::Proxy< ed_DecipheringFiles >::createUnique( this );
	}

private:
	null_ed_DecipheringFiles( const null_ed_DecipheringFiles & ) throw() {} // other
	
	const null_ed_DecipheringFiles &operator =( const null_ed_DecipheringFiles &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ed_DecipheringFiles::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< DecipherStatisticsData > _decipherStatisticsDataReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_ed_DecipheringFiles :
	public ed_DecipheringFiles,
	public ::jmsf::mtf::mixins::mixin_null_Lockable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ed_DecipheringFiles > {

public:
	// virtuals ed_DecipheringFiles
	::jmsf::Pointer< DecipherStatisticsData > &takeData() throw( ::jmsf::Exception ) {
		return _decipherStatisticsDataReferenceToReturn;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ed_DecipheringFiles() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ed_DecipheringFiles >;
	static exception_ed_DecipheringFiles *createInstance() throw() {
		return new exception_ed_DecipheringFiles;
	}

private:
	exception_ed_DecipheringFiles() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_DecipheringFiles > createClone() const throw() {
		return ::jmsf::Proxy< ed_DecipheringFiles >::createUnique( this );
	}

private:
	exception_ed_DecipheringFiles( const exception_ed_DecipheringFiles & ) throw() {} // other

	const exception_ed_DecipheringFiles &operator =( const exception_ed_DecipheringFiles &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ed_DecipheringFiles::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< DecipherStatisticsData > _decipherStatisticsDataReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
ed_DecipheringFiles *ed_DecipheringFiles::getNull() throw() {
	return null_ed_DecipheringFiles::instance();
}

// static
ed_DecipheringFiles *ed_DecipheringFiles::getException() throw() {
	return exception_ed_DecipheringFiles::instance();
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
