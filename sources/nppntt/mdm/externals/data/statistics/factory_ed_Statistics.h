#pragma once

#include "jmsf/Singleton.hpp"


#include "ed_Summary.hxx"
#include "ed_AppendedFiles.hxx"
#include "ed_DecipheringFiles.hxx"
#include "ed_StoredFiles.hxx"
#include "ed_DeletedFiles.hxx"

#include "jmsf/Proxies.hxx"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {


class factory_ed_Statistics :
	public ::jmsf::Singleton< factory_ed_Statistics >
{

public:
	virtual ::jmsf::Proxy< ed_Summary > createSummary() const throw() = 0;
	virtual ::jmsf::Proxy< ed_AppendedFiles > createAppendedFiles() const throw() = 0;
	virtual ::jmsf::Proxy< ed_DecipheringFiles > createDecipheringFiles() const throw() = 0;
	virtual ::jmsf::Proxy< ed_StoredFiles > createStoredFiles() const throw() = 0;
	virtual ::jmsf::Proxy< ed_DeletedFiles > createDeletedFiles() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_ed_Statistics() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< factory_ed_Statistics >;
	static factory_ed_Statistics *createInstance() throw();

protected:
	factory_ed_Statistics() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_ed_Statistics( const factory_ed_Statistics &other ) throw();
	const factory_ed_Statistics &operator =( const factory_ed_Statistics &other ) throw();

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
