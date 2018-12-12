#pragma once

#include "../factory_ed_Statistics.h"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace realizations {


class realization_factory_ed_Statistics :
	public factory_ed_Statistics
{

public:
	// virtuals factory_ed_Statistics
	::jmsf::Proxy< ed_Summary > createSummary() const throw();
	::jmsf::Proxy< ed_AppendedFiles > createAppendedFiles() const throw();
	::jmsf::Proxy< ed_DecipheringFiles > createDecipheringFiles() const throw();
	::jmsf::Proxy< ed_StoredFiles > createStoredFiles() const throw();
	::jmsf::Proxy< ed_DeletedFiles > createDeletedFiles() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_ed_Statistics() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class factory_ed_Statistics;
	realization_factory_ed_Statistics() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_ed_Statistics( const realization_factory_ed_Statistics &other ) throw();
	const realization_factory_ed_Statistics &operator =( const realization_factory_ed_Statistics &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
}
