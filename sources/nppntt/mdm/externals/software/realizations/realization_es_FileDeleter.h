#pragma once

#include "../es_FileDeleter.h"
#include "jmsf/mixins/mixin_Object.h"

#include "realization_factory_ExternalSoftware.hxx"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace realizations {


class realization_es_FileDeleter :
	public es_FileDeleter,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals es_FileDeleter
	void deleteFile(
		::jmsf::Pointer< FileDescriptorData > fileData,
		::jmsf::Pointer< AppliedData > appliedData ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_es_FileDeleter() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ExternalSoftware;
	realization_es_FileDeleter() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_FileDeleter > createClone() const throw();

private:
	realization_es_FileDeleter( const realization_es_FileDeleter &other ) throw();
	const realization_es_FileDeleter &operator =( const realization_es_FileDeleter &other ) throw();

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
