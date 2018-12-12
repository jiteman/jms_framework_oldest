#include "ed_AppendedFiles.h"
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

class null_ed_AppendedFiles :
	public ed_AppendedFiles,
	public ::jmsf::mtf::mixins::mixin_null_Lockable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ed_AppendedFiles >
{

public:
	// virtuals ed_AppendedFiles
	::jmsf::Pointer< FileAppenderStatisticsData > &takeData() throw( ::jmsf::Exception ) {
		return _fileAppenderStatisticsDataReferenceToReturn;
	}

	const ::jmsf::ConstantPointer< FileAppenderStatisticsData > &getData() const throw( ::jmsf::Exception ) {
		return _fileAppenderStatisticsDataConstantReferenceToReturn;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ed_AppendedFiles() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ed_AppendedFiles >;
	static null_ed_AppendedFiles *createInstance() throw() {
		return new null_ed_AppendedFiles;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ed_AppendedFiles() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_AppendedFiles > createClone() const throw() {
		return ::jmsf::Proxy< ed_AppendedFiles >::createUnique( this );
	}

private:
	null_ed_AppendedFiles( const null_ed_AppendedFiles & ) throw() {} // other
	
	const null_ed_AppendedFiles &operator =( const null_ed_AppendedFiles &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ed_AppendedFiles::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< FileAppenderStatisticsData > _fileAppenderStatisticsDataReferenceToReturn;
	::jmsf::ConstantPointer< FileAppenderStatisticsData > _fileAppenderStatisticsDataConstantReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_ed_AppendedFiles :
	public ed_AppendedFiles,
	public ::jmsf::mtf::mixins::mixin_null_Lockable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ed_AppendedFiles > {

public:
	// virtuals ed_AppendedFiles
	::jmsf::Pointer< FileAppenderStatisticsData > &takeData() throw( ::jmsf::Exception ) {
		return _fileAppenderStatisticsDataReferenceToReturn;
	}

	const ::jmsf::ConstantPointer< FileAppenderStatisticsData > &getData() const throw( ::jmsf::Exception ) {
		return _fileAppenderStatisticsDataConstantReferenceToReturn;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ed_AppendedFiles() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ed_AppendedFiles >;
	static exception_ed_AppendedFiles *createInstance() throw() {
		return new exception_ed_AppendedFiles;
	}

private:
	exception_ed_AppendedFiles() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_AppendedFiles > createClone() const throw() {
		return ::jmsf::Proxy< ed_AppendedFiles >::createUnique( this );
	}

private:
	exception_ed_AppendedFiles( const exception_ed_AppendedFiles & ) throw() {} // other

	const exception_ed_AppendedFiles &operator =( const exception_ed_AppendedFiles &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ed_AppendedFiles::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< FileAppenderStatisticsData > _fileAppenderStatisticsDataReferenceToReturn;
	::jmsf::ConstantPointer< FileAppenderStatisticsData > _fileAppenderStatisticsDataConstantReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
ed_AppendedFiles *ed_AppendedFiles::getNull() throw() {
	return null_ed_AppendedFiles::instance();
}

// static
ed_AppendedFiles *ed_AppendedFiles::getException() throw() {
	return exception_ed_AppendedFiles::instance();
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
