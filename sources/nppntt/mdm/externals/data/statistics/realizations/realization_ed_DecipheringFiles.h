#pragma once

#include "../ed_DecipheringFiles.h"
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

class realization_ed_DecipheringFiles :
	public ed_DecipheringFiles,
	public ::jmsf::mtf::mixins::mixin_Lockable,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals ed_DecipheringFiles
	::jmsf::Pointer< DecipherStatisticsData > &takeData() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ed_DecipheringFiles() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ed_Statistics;
	realization_ed_DecipheringFiles(
		::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_DecipheringFiles > createClone() const throw();

private:
	realization_ed_DecipheringFiles( const realization_ed_DecipheringFiles &other ) throw();
	const realization_ed_DecipheringFiles &operator =( const realization_ed_DecipheringFiles &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< DecipherStatisticsData > _decipheringFilesData;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
}
}
}
}
