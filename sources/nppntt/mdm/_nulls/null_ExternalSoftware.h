#pragma once

#include "../ExternalSoftware.h"
#include "jmsf/mixin_nulls/mixin_null_Object.h"
#include "jmsf/Singleton.hpp"

#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace nulls {


class null_ExternalSoftware :
	public ExternalSoftware,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_ExternalSoftware >
{

public:
	// virtuals ExternalSoftware
	::jmsf::Proxy< externals::software::es_FileAppender > getOneselfFileAppender() throw();
	::jmsf::Proxy< externals::software::es_Decipher > getOneselfDecipher() throw();
	::jmsf::Proxy< externals::software::es_StatisticsUpdater > getOneselfStatisticsUpdater() throw();
	const ::jmsf::ConstantProxy< externals::software::es_StatisticsUpdater > getStatisticsUpdater() const throw();
	::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray > getOneselfProcessArray() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ExternalSoftware() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_ExternalSoftware >;
	static null_ExternalSoftware *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ExternalSoftware() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ExternalSoftware > createClone() const throw();

private:
	null_ExternalSoftware( const null_ExternalSoftware &other ) throw();
	const null_ExternalSoftware &operator =( const null_ExternalSoftware &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< externals::software::es_FileAppender > _fileAppender;
	::jmsf::Proxy< externals::software::es_Decipher > _decipher;
	::jmsf::Proxy< externals::software::es_StatisticsUpdater > _statisticsUpdater;
	::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray > _processArray;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
