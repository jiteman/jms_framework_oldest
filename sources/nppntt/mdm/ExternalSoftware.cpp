#include "ExternalSoftware.h"
#include "externals/software/es_Decipher.h"
#include "externals/software/es_StatisticsUpdater.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {

class null_ExternalSoftware :
	public ExternalSoftware,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ExternalSoftware >
{

public:
	// virtuals ExternalSoftware
	::jmsf::Proxy< externals::software::es_Decipher > &takeDecipher() throw() {
		return _decipherReferenceToReturn;
	}

	::jmsf::Proxy< externals::software::es_StatisticsUpdater > &takeStatisticsUpdater() throw() {
		return _statisticsUpdaterReferenceToReturn;
	}

	const ::jmsf::ConstantProxy< externals::software::es_StatisticsUpdater > &getStatisticsUpdater() const throw() {
		return _statisticsUpdaterConstantReferenceToReturn;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ExternalSoftware() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ExternalSoftware >;
	static null_ExternalSoftware *createInstance() throw() {
		return new null_ExternalSoftware;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ExternalSoftware() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ExternalSoftware > createClone() const throw() {
		return ::jmsf::Proxy< ExternalSoftware >::createUnique( this );
	}

private:
	null_ExternalSoftware( const null_ExternalSoftware & ) throw() {} // other
	
	const null_ExternalSoftware &operator =( const null_ExternalSoftware &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ExternalSoftware::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< externals::software::es_Decipher > _decipherReferenceToReturn;
	::jmsf::Proxy< externals::software::es_StatisticsUpdater > _statisticsUpdaterReferenceToReturn;
	::jmsf::ConstantProxy< externals::software::es_StatisticsUpdater > _statisticsUpdaterConstantReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_ExternalSoftware :
	public ExternalSoftware,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ExternalSoftware > {

public:
	// virtuals ExternalSoftware
	::jmsf::Proxy< externals::software::es_Decipher > &takeDecipher() throw() {
		return _decipherReferenceToReturn;
	}

	::jmsf::Proxy< externals::software::es_StatisticsUpdater > &takeStatisticsUpdater() throw() {
		return _statisticsUpdaterReferenceToReturn;
	}

	const ::jmsf::ConstantProxy< externals::software::es_StatisticsUpdater > &getStatisticsUpdater() const throw() {
		return _statisticsUpdaterConstantReferenceToReturn;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ExternalSoftware() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ExternalSoftware >;
	static exception_ExternalSoftware *createInstance() throw() {
		return new exception_ExternalSoftware;
	}

private:
	exception_ExternalSoftware() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ExternalSoftware > createClone() const throw() {
		return ::jmsf::Proxy< ExternalSoftware >::createUnique( this );
	}

private:
	exception_ExternalSoftware( const exception_ExternalSoftware & ) throw() {} // other

	const exception_ExternalSoftware &operator =( const exception_ExternalSoftware &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ExternalSoftware::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< externals::software::es_Decipher > _decipherReferenceToReturn;
	::jmsf::Proxy< externals::software::es_StatisticsUpdater > _statisticsUpdaterReferenceToReturn;
	::jmsf::ConstantProxy< externals::software::es_StatisticsUpdater > _statisticsUpdaterConstantReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
ExternalSoftware *ExternalSoftware::getNull() throw() {
	return null_ExternalSoftware::instance();
}

// static
ExternalSoftware *ExternalSoftware::getException() throw() {
	return exception_ExternalSoftware::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace mdm
} // namespace nppntt
