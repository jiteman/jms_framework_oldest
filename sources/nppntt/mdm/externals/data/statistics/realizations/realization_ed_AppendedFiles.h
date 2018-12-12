#pragma once

#include "../ed_AppendedFiles.h"
#include "jmsf/mtf/mixins/mixin_Lockable.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Pointers.hpp"

#include "realization_factory_ed_Statistics.h"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace realizations {


class realization_ed_AppendedFiles :
	public ed_AppendedFiles,
	public ::jmsf::mtf::mixins::mixin_Lockable,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals ed_AppendedFiles
	::jmsf::Pointer< FileAppenderStatisticsData > &takeData() throw( ::jmsf::Exception );
	const ::jmsf::ConstantPointer< FileAppenderStatisticsData > &getData() const throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ed_AppendedFiles() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ed_Statistics;
	realization_ed_AppendedFiles(
		::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_AppendedFiles > createClone() const throw();

private:
	realization_ed_AppendedFiles( const realization_ed_AppendedFiles &other ) throw();
	const realization_ed_AppendedFiles &operator =( const realization_ed_AppendedFiles &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< FileAppenderStatisticsData > _appendedFilesData;
	::jmsf::ConstantPointer< FileAppenderStatisticsData > _constantAppendedFilesData;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
}
