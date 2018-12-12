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

class ed_DecipheringFiles :
	public virtual ::jmsf::mtf::Lockable,
	public virtual ::jmsf::Object
{

public:
	virtual ::jmsf::Pointer< DecipherStatisticsData > &takeData() throw( ::jmsf::Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ed_DecipheringFiles *getNull() throw();
	static ed_DecipheringFiles *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< ed_DecipheringFiles > createClone() const throw() = 0;

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
