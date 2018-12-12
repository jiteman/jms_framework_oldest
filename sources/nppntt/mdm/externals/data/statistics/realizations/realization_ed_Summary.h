#pragma once

#include "../ed_Summary.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Pointers.hpp"

#include "realization_factory_ed_Statistics.hxx"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace realizations {

class realization_ed_Summary :
	public ed_Summary,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals ed_Summary
	::jmsf::Pointer< GlobalStatisticsData > &takeData() throw( ::jmsf::Exception );
	const ::jmsf::ConstantPointer< GlobalStatisticsData > &getData() const throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ed_Summary() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ed_Statistics;
	realization_ed_Summary() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_Summary > createClone() const throw();

private:
	realization_ed_Summary( const realization_ed_Summary &other ) throw();
	const realization_ed_Summary &operator =( const realization_ed_Summary &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< GlobalStatisticsData > _summaryFilesData;
	::jmsf::ConstantPointer< GlobalStatisticsData > _constantSummaryFilesData;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
}
