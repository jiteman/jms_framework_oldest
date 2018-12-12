#pragma once

#include "jmsf/Object.h"

#include "externals/software/es_Decipher.hxx"
#include "externals/software/es_StatisticsUpdater.hxx"
#include "jmsf/Proxies.hxx"

namespace nppntt {
namespace mdm {

class ExternalSoftware :
	public virtual ::jmsf::Object
{

public:
	virtual ::jmsf::Proxy< externals::software::es_Decipher > &takeDecipher() throw() = 0;
	virtual ::jmsf::Proxy< externals::software::es_StatisticsUpdater > &takeStatisticsUpdater() throw() = 0;
	virtual const ::jmsf::ConstantProxy< externals::software::es_StatisticsUpdater > &getStatisticsUpdater() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ExternalSoftware *getNull() throw();
	static ExternalSoftware *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< ExternalSoftware > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace mdm
} // namespace nppntt
