#pragma once

#include "jmsf/mtf/Lockable.h"
#include "jmsf/Object.h"

#include "../../others/DataTypes.hxx"
#include "jmsf/Proxies.hxx"
#include "jmsf/Pointers.hxx"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {

class ed_AppendedFiles :
	public virtual ::jmsf::mtf::Lockable,
	public virtual ::jmsf::Object
{

public:
	virtual ::jmsf::Pointer< FileAppenderStatisticsData > &takeData() throw( ::jmsf::Exception ) = 0;
	virtual const ::jmsf::ConstantPointer< FileAppenderStatisticsData > &getData() const throw( ::jmsf::Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ed_AppendedFiles *getNull() throw();
	static ed_AppendedFiles *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< ed_AppendedFiles > createClone() const throw() = 0;

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
