#pragma once

#include "../ed_DeletedFiles.h"

#include "jmsf/mtf/mixin_nulls/mixin_null_Synchronizable.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


#include "jmsf/Pointers.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace nulls {


class null_ed_DeletedFiles :
	public ed_DeletedFiles,
	public ::jmsf::mtf::mixin_nulls::mixin_null_Synchronizable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_ed_DeletedFiles >
{

public:
	// virtuals ed_DeletedFiles
	::jmsf::Pointer< DeleteFilesStatisticsData > getOneselfData() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ed_DeletedFiles() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_ed_DeletedFiles >;
	static null_ed_DeletedFiles *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ed_DeletedFiles() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_DeletedFiles > createClone() const throw();

private:
	null_ed_DeletedFiles( const null_ed_DeletedFiles &other ) throw();
	const null_ed_DeletedFiles &operator =( const null_ed_DeletedFiles &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< DeleteFilesStatisticsData > _deletedFilesData;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
}
