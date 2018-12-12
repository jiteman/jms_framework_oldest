#pragma once

#include "../es_FileDeleter.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace nulls {


class null_es_FileDeleter :
	public es_FileDeleter,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_es_FileDeleter >
{

public:
	// virtuals es_FileDeleter
	void deleteFile(
		::jmsf::Pointer< FileDescriptorData > fileData,
		::jmsf::Pointer< AppliedData > appliedData  ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_es_FileDeleter() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_es_FileDeleter >;
	static null_es_FileDeleter *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_es_FileDeleter() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_FileDeleter > createClone() const throw();

private:
	null_es_FileDeleter( const null_es_FileDeleter &other ) throw();
	const null_es_FileDeleter &operator =( const null_es_FileDeleter &other ) throw();

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
