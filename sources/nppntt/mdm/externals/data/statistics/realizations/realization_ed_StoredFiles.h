#pragma once

#include "../ed_StoredFiles.h"
#include "jmsf/mtf/mixins/mixin_Lockable.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Pointers.hpp"

#include "realization_factory_ed_Statistics.hxx"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace realizations {

class realization_ed_StoredFiles :
	public ed_StoredFiles,
	public ::jmsf::mtf::mixins::mixin_Lockable,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals ed_StoredFiles
	::jmsf::Pointer< DataBaseStatisticsData > &takeData() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ed_StoredFiles() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ed_Statistics;
	realization_ed_StoredFiles( ::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_StoredFiles > createClone() const throw();

private:
	realization_ed_StoredFiles( const realization_ed_StoredFiles &other ) throw();
	const realization_ed_StoredFiles &operator =( const realization_ed_StoredFiles &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< DataBaseStatisticsData > _storedFilesData;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
}
