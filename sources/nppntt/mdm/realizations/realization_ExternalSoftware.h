#pragma once

#include "../ExternalSoftware.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"
#include "jmsf/Pointers.hpp"

#include "realization_factory_MaskDmObjects.hxx"

namespace nppntt {
namespace mdm {
namespace realizations {

class realization_ExternalSoftware :
	public ExternalSoftware,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals ExternalSoftware
	::jmsf::Proxy< externals::software::es_Decipher > &takeDecipher() throw();
	::jmsf::Proxy< externals::software::es_StatisticsUpdater > &takeStatisticsUpdater() throw();
	const ::jmsf::ConstantProxy< externals::software::es_StatisticsUpdater > &getStatisticsUpdater() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ExternalSoftware() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_MaskDmObjects;
	realization_ExternalSoftware(
		::jmsf::Proxy< externals::software::es_Decipher > decipher,
		::jmsf::Proxy< externals::software::es_StatisticsUpdater > statisticsUpdater ) throw( jmsf::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ExternalSoftware > createClone() const throw();

private:
	realization_ExternalSoftware( const realization_ExternalSoftware &other ) throw();
	const realization_ExternalSoftware &operator =( const realization_ExternalSoftware &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< externals::software::es_Decipher > _decipher;
	::jmsf::Proxy< externals::software::es_StatisticsUpdater > _statisticsUpdater;
	::jmsf::ConstantProxy< externals::software::es_StatisticsUpdater > _constantStatisticsUpdater;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
}
