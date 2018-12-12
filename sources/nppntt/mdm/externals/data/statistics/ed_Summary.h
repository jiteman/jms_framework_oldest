#pragma once

#include "jmsf/Object.h"

#include "../../others/DataTypes.hxx"
#include "jmsf/Proxies.hxx"
#include "jmsf/Pointers.hxx"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {

class ed_Summary :
	public virtual ::jmsf::Object
{

public:
	virtual ::jmsf::Pointer< GlobalStatisticsData > &takeData() throw( ::jmsf::Exception ) = 0;
	virtual const ::jmsf::ConstantPointer< GlobalStatisticsData > &getData() const throw( ::jmsf::Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ed_Summary *getNull() throw();
	static ed_Summary *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< ed_Summary > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace statistics
} // namespace data
} // namespace externals
} // namespace mdm
} // namespace nppntt
