#pragma once

#include "../ed_DecipheringFiles.h"

#include "jmsf/mtf/mixin_nulls/mixin_null_Synchronizable.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace nulls {


class null_ed_DecipheringFiles :
	public ed_DecipheringFiles,
	public ::jmsf::mtf::mixin_nulls::mixin_null_Synchronizable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_ed_DecipheringFiles >
{

public:
	// virtuals ed_DecipheringFiles
	::jmsf::Pointer< DecipherStatisticsData > getOneselfData() throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ed_DecipheringFiles() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_ed_DecipheringFiles >;
	static null_ed_DecipheringFiles *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ed_DecipheringFiles() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_DecipheringFiles > createClone() const throw();

private:
	null_ed_DecipheringFiles( const null_ed_DecipheringFiles &other ) throw();
	const null_ed_DecipheringFiles &operator =( const null_ed_DecipheringFiles &other ) throw();

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
